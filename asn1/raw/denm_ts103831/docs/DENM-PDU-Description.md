# <a name="DENM-PDU-Description"></a>ASN.1 module DENM-PDU-Description
OID: _{itu-t (0) identified-organization (4) etsi (0) itsDomain (5) wg1 (1) denmPduRelease2 (103831) major-version-2 (2) minor-version-2 (2)}_

## Imports:
* **[ETSI-ITS-CDD](ETSI-ITS-CDD.md)** *{itu-t (0) identified-organization (4) etsi (0) itsDomain (5) wg1 (1) ts (102894) cdd (2) major-version-4 (4) minor-version-1 (1)} WITH SUCCESSORS*<br/>
## Data Elements:
### <a name="DENM"></a>DENM
This type represents the DENM PDU.

 It shall include the following components:

* _header_ of type [**ItsPduHeader**](ETSI-ITS-CDD.md#ItsPduHeader)  (WITH COMPONENTS {... , protocolVersion (2), messageId(denm)})<br>
  the header of the DENM PDU.

* _denm_ of type [**DenmPayload**](#DenmPayload) <br>
  the payload of the DENM PDU.

```asn1
DENM ::= SEQUENCE {
	header ItsPduHeader (WITH COMPONENTS {... , protocolVersion (2), messageId(denm)}),
	denm   DenmPayload
}
```

### <a name="DenmPayload"></a>DenmPayload
This type represents the DENM payload.

 It shall include the following components:

* _management_ of type [**ManagementContainer**](#ManagementContainer) <br>
  the Management Container.

* _situation_ of type [**SituationContainer**](#SituationContainer)  OPTIONAL<br>
  the optional Situation Container.

* _location_ of type [**LocationContainer**](#LocationContainer)  OPTIONAL<br>
  the optional Location Container.

* _alacarte_ of type [**AlacarteContainer**](#AlacarteContainer)  OPTIONAL<br>
  the optional ALaCarte Container .

```asn1
DenmPayload ::= SEQUENCE {
    management ManagementContainer,
    situation  SituationContainer OPTIONAL,
    location   LocationContainer OPTIONAL,
    alacarte   AlacarteContainer OPTIONAL
}
((WITH COMPONENTS {..., management (WITH COMPONENTS {..., termination ABSENT}), situation PRESENT, location PRESENT}) |
 (WITH COMPONENTS {..., management (WITH COMPONENTS {..., termination PRESENT}), situation ABSENT, location ABSENT, alacarte ABSENT}))
```

### <a name="ManagementContainer"></a>ManagementContainer
This type represents the Management Container.

 It shall include the following components:

* _actionId_ of type [**ActionId**](ETSI-ITS-CDD.md#ActionId) <br>
  the identifier of the DENM.

* _detectionTime_ of type [**TimestampIts**](ETSI-ITS-CDD.md#TimestampIts) <br>
  the time at which the event is detected.

* _referenceTime_ of type [**TimestampIts**](ETSI-ITS-CDD.md#TimestampIts) <br>
  the time at which a new DENM, an update DENM or a cancellation DENM is generated

* _termination_ of type [**Termination**](#Termination)  OPTIONAL<br>
  the optional termination type of the DENM.

* _eventPosition_ of type [**ReferencePosition**](ETSI-ITS-CDD.md#ReferencePosition) <br>
  the geographical position used in the definition of the awareness area / relevance zone, see clause 6.1.3.

* _awarenessDistance_ of type [**StandardLength3b**](ETSI-ITS-CDD.md#StandardLength3b)  OPTIONAL<br>
  the optional radius of the circular awareness area, with centre at the event position or at any of the 
   event history points as defined in clause 6.1.3.1.

* _trafficDirection_ of type [**TrafficDirection**](ETSI-ITS-CDD.md#TrafficDirection)  OPTIONAL<br>
  the optional traffic direction along which the receiving ITS-S may encounter the event, 
   as defined in clause 6.1.3.

* _validityDuration_ of type [**DeltaTimeSecond**](ETSI-ITS-CDD.md#DeltaTimeSecond)  DEFAULT defaultValidity<br>
  the validity duration of a DENM. This component represents a time offset in the unit of second since detectionTime.

* _transmissionInterval_ of type [**DeltaTimeMilliSecondPositive**](ETSI-ITS-CDD.md#DeltaTimeMilliSecondPositive)  OPTIONAL<br>
  the optional time interval for DENM transmission as defined by the originating ITS-S. 
   If the component is not present in DENM, a default value defaultValidity is assumed.

* _stationType_ of type [**StationType**](ETSI-ITS-CDD.md#StationType) <br>
  the station type information of the originating ITS-S.

```asn1
ManagementContainer ::= SEQUENCE {
    actionId                  ActionId,
    detectionTime             TimestampIts,
    referenceTime             TimestampIts,
    termination               Termination OPTIONAL,
    eventPosition             ReferencePosition,
    awarenessDistance         StandardLength3b OPTIONAL,
    trafficDirection          TrafficDirection OPTIONAL,
    validityDuration          DeltaTimeSecond DEFAULT defaultValidity, 
    transmissionInterval      DeltaTimeMilliSecondPositive OPTIONAL,
    stationType               StationType,
    ...
}
```

### <a name="SituationContainer"></a>SituationContainer
This type represents the situation container.

 It shall include the following components:

* _informationQuality_ of type [**InformationQuality**](ETSI-ITS-CDD.md#InformationQuality) <br>
  the quality level of the information provided by the ITS-S application of the originating ITS-S. 
   It indicates the probability of the detected event being truly existent at the event position.

* _eventType_ of type [**CauseCodeV2**](ETSI-ITS-CDD.md#CauseCodeV2) <br>
  the event type, including direct cause and sub cause.

* _linkedCause_ of type [**CauseCodeV2**](ETSI-ITS-CDD.md#CauseCodeV2)  OPTIONAL<br>
  the optional type of a linked event co-existing at the same time and the same place (same event zone), 
   including direct cause and sub cause of the linked event, for which no other DENM is sent out.

* _eventZone_ of type [**EventZone**](ETSI-ITS-CDD.md#EventZone)  OPTIONAL<br>
  an optional list of EventPoint, using the position indicated in the component eventPosition of the Management container 
   as the reference position for the first EventPoint.

* _linkedDenms_ of type [**ActionIdList**](ETSI-ITS-CDD.md#ActionIdList)  OPTIONAL<br>
  the optional list of DF ActionId, pointing to DENMs that are semantically connected because applying to consecutive 
   event zones at the same time.

* _eventEnd_ of type [**Position1d**](ETSI-ITS-CDD.md#Position1d)  OPTIONAL <br>
  the end position of the event along the road that is affected by the event w.r.t. the component eventPosition of the 
   Management container. This end position is represented by the length of the event along the road. 

```asn1
SituationContainer ::= SEQUENCE {
    informationQuality InformationQuality,
    eventType          CauseCodeV2,
    linkedCause        CauseCodeV2 OPTIONAL,
    eventZone          EventZone OPTIONAL,
    ...,
[[  linkedDenms        ActionIdList OPTIONAL,
    eventEnd           Position1d OPTIONAL ]]   
}
  ((WITH COMPONENTS {..., eventZone PRESENT, eventEnd ABSENT}) |
   (WITH COMPONENTS {..., eventZone ABSENT, eventEnd PRESENT}) |
   (WITH COMPONENTS {..., eventZone ABSENT, eventEnd ABSENT}))
```

### <a name="LocationContainer"></a>LocationContainer
This type represents the Location Container.

 It shall include the following components:

* _eventSpeed_ of type [**Speed**](ETSI-ITS-CDD.md#Speed)  OPTIONAL<br>
  optional speed of a detected dynamic event and the confidence of the speed information. 

* _eventPositionHeading_ of type [**Wgs84Angle**](ETSI-ITS-CDD.md#Wgs84Angle)  OPTIONAL<br>
  the optional heading of a dynamic event and the confidence of the heading information.

* _detectionZonesToEventPosition_ of type [**Traces**](ETSI-ITS-CDD.md#Traces) <br>
  the detection zone information approaching the event position, see clause 6.1.3.3.

* _roadType_ of type [**RoadType**](ETSI-ITS-CDD.md#RoadType)  OPTIONAL<br>
  the optional road type information at the event position. 

* _lanePositions_ of type [**GeneralizedLanePositions**](ETSI-ITS-CDD.md#GeneralizedLanePositions)  OPTIONAL<br>
  the optional lane(s) where the event is located, at the position indicated by the component eventPosition 
   of the Management container and for a given reference direction.

* _occupiedLanes_ of type [**OccupiedLanesWithConfidence**](ETSI-ITS-CDD.md#OccupiedLanesWithConfidence)  OPTIONAL<br>
  the optional lane(s) that are fully or partially occupied by the event, at the position indicated by the 
   component eventPosition of the Management container and for a given reference direction.

* _linkedIvims_ of type [**IvimReferences**](ETSI-ITS-CDD.md#IvimReferences)  OPTIONAL<br>
  the optional list of DF IvimReference, pointing to IVIMs that are semantically connected because providing information 
   applying to the road segment(s) covered by the components detectionZonesToEventPosition, detectionZonesToSpecifiedEventPoint and 
   the SituationContainer component eventZone.

* _linkedMapems_ of type [**MapReferences**](ETSI-ITS-CDD.md#MapReferences)  OPTIONAL<br>
* _detectionZonesToSpecifiedEventPoint_ of type [**TracesExtended**](ETSI-ITS-CDD.md#TracesExtended)  OPTIONAL<br>
  the optional detection zone information approaching towards a 
   specified event point, see clause 6.1.3.3. 

* _predictedPaths_ of type [**PathPredictedList**](ETSI-ITS-CDD.md#PathPredictedList)  OPTIONAL <br>
  the optional list of future paths or trajectories that the event may move along or zones that the event may occupy. 

* linkedMapem<br>
  the optional list of DF Mapreference, pointing to MAPEMs that are semantically connected because providing information 
   applying to the road segment(s) covered by the component detectionZonesToEventPosition, detectionZonesToSpecifiedEventPoint and 
   the SituationContainer component eventZone.

```asn1
LocationContainer ::= SEQUENCE {
    eventSpeed                            Speed OPTIONAL,
    eventPositionHeading                  Wgs84Angle OPTIONAL,
    detectionZonesToEventPosition         Traces,
    roadType                              RoadType OPTIONAL,
    ...,
[[	lanePositions                         GeneralizedLanePositions OPTIONAL,
    occupiedLanes                         OccupiedLanesWithConfidence OPTIONAL,
    linkedIvims                           IvimReferences OPTIONAL, 
    linkedMapems                          MapReferences OPTIONAL, 
    detectionZonesToSpecifiedEventPoint   TracesExtended OPTIONAL,
    predictedPaths	          	          PathPredictedList OPTIONAL ]]
}
```

### <a name="ImpactReductionContainer"></a>ImpactReductionContainer
This type contains detailed information about the vehicle in which the originating ITS-S is mounted, for mitigating the consequences 
 of a collision.

 It shall include the following components:

* _heightLonCarrLeft_ of type [**HeightLonCarr**](ETSI-ITS-CDD.md#HeightLonCarr) <br>
  the height of the left longitudinal carrier of the vehicle from base to top.

* _heightLonCarrRight_ of type [**HeightLonCarr**](ETSI-ITS-CDD.md#HeightLonCarr) <br>
  the height of the right longitudinal carrier of the vehicle from base to top.

* _posLonCarrLeft_ of type [**PosLonCarr**](ETSI-ITS-CDD.md#PosLonCarr) <br>
  the position of the left longitudinal carrier of vehicle.

* _posLonCarrRight_ of type [**PosLonCarr**](ETSI-ITS-CDD.md#PosLonCarr) <br>
  the position of the right longitudinal carrier of vehicle.

* _positionOfPillars_ of type [**PositionOfPillars**](ETSI-ITS-CDD.md#PositionOfPillars) <br>
  information about the vertical support of the vehicle in which the originating ITS-S is mounted. It shall be 
   included for passenger vehicles only.

* _posCentMass_ of type [**PosCentMass**](ETSI-ITS-CDD.md#PosCentMass) <br>
  the position of the centre of mass of the vehicle.

* _wheelBaseVehicle_ of type [**WheelBaseVehicle**](ETSI-ITS-CDD.md#WheelBaseVehicle) <br>
  the wheel base of the vehicle.

* _turningRadius_ of type [**TurningRadius**](ETSI-ITS-CDD.md#TurningRadius) <br>
  the turning radius of the vehicle.

* _posFrontAx_ of type [**PosFrontAx**](ETSI-ITS-CDD.md#PosFrontAx) <br>
  the position of the front axle of the vehicle.

* _positionOfOccupants_ of type [**PositionOfOccupants**](ETSI-ITS-CDD.md#PositionOfOccupants) <br>
  indicates whether an in-vehicle seat is occupied at the moment of generation of the message.

* _vehicleMass_ of type [**VehicleMass**](ETSI-ITS-CDD.md#VehicleMass) <br>
  the mass of the unloaded vehicle

* _requestResponseIndication_ of type [**RequestResponseIndication**](ETSI-ITS-CDD.md#RequestResponseIndication) <br>
  indicates whether the originating ITS-S transmitting the impactReduction component is requesting 
   the receiving ITS-S to provide also its impactReduction component.

```asn1
ImpactReductionContainer ::= SEQUENCE {
    heightLonCarrLeft         HeightLonCarr,
    heightLonCarrRight        HeightLonCarr,
    posLonCarrLeft            PosLonCarr,
    posLonCarrRight           PosLonCarr,
    positionOfPillars         PositionOfPillars,
    posCentMass               PosCentMass,
    wheelBaseVehicle          WheelBaseVehicle,
    turningRadius             TurningRadius,
    posFrontAx                PosFrontAx,
    positionOfOccupants       PositionOfOccupants,
    vehicleMass               VehicleMass,
    requestResponseIndication RequestResponseIndication
}
```

### <a name="PreCrashContainer"></a>PreCrashContainer
This type contains detailed information about an object with which a vehicle and/or the traffic is likely to collide.

 It shall include the following components:

* _perceivedPreCrashObject_ of type [**PerceivedObject**](ETSI-ITS-CDD.md#PerceivedObject) <br>
  information about a perceived object in the East, North, Up reference frame.

* _objectStationId_ of type [**StationId**](ETSI-ITS-CDD.md#StationId)  OPTIONAL<br>
  the optional station Id of the object for which the information is provided.

* _timeToCollision_ of type [**DeltaTimeMilliSecondPositive**](ETSI-ITS-CDD.md#DeltaTimeMilliSecondPositive)  OPTIONAL<br>
  the optional estimated time to collision of a vehicle with the object. 

* _impactSection_ of type [**ObjectFace**](ETSI-ITS-CDD.md#ObjectFace)  OPTIONAL<br>
  indication of the object's section where the impact will most likely occur. 
   When the target object is likely to be a vehicle, then this component should be present, otherwise it should not be provided.  

* _estimatedBrakingDistance_ of type [**StandardLength12b**](ETSI-ITS-CDD.md#StandardLength12b)  OPTIONAL<br>
  the optional estimated distance in which the vehicle would need to come to a complete hold, 
   if no obstruction was in the way. 

```asn1
PreCrashContainer ::= SEQUENCE { 
    perceivedPreCrashObject   PerceivedObject, 
    objectStationId           StationId OPTIONAL, 
    timeToCollision           DeltaTimeMilliSecondPositive OPTIONAL, 
    impactSection             ObjectFace OPTIONAL, 
    estimatedBrakingDistance  StandardLength12b OPTIONAL,
    ... 
}
```

### <a name="RoadConfigurationContainer"></a>RoadConfigurationContainer
This type contains detailed information about the configuration of road section(s) that are geographically related to the event.

 It shall include the following components:

* _roadConfigurationConfidence_ of type [**MetaInformation**](ETSI-ITS-CDD.md#MetaInformation) <br>
  information about the source of the road configuration and the confidence in the information.

* _roadConfigurationSectionList_ of type [**RoadConfigurationSectionList**](ETSI-ITS-CDD.md#RoadConfigurationSectionList) <br>
  a list of road configuration information per applicable road section. 

```asn1
RoadConfigurationContainer ::=  SEQUENCE {
    roadConfigurationConfidence     MetaInformation,
    roadConfigurationSectionList    RoadConfigurationSectionList,
    ...
}
```

### <a name="RoadWorksContainerExtended"></a>RoadWorksContainerExtended
This type contains detailed information of a roadwork zone and specific access conditions.

 It shall include the following components:

* _lightBarSirenInUse_ of type [**LightBarSirenInUse**](ETSI-ITS-CDD.md#LightBarSirenInUse)  OPTIONAL<br>
  optionally indicates whether a roadwork vehicle has switched on the light bar or siren. 
   It is used when the roadwork involves a specific roadwork vehicle

* _closedLanes_ of type [**ClosedLanes**](ETSI-ITS-CDD.md#ClosedLanes)  OPTIONAL<br>
  optionally indicates whether the roadwork has caused the closure of one or several driving lanes. 
   Optionally, it may indicate whether a hard shoulder lane is closed to traffic or can be used for specific usage (e.g. for stopping).

* _restriction_ of type [**RestrictedTypes**](ETSI-ITS-CDD.md#RestrictedTypes)  OPTIONAL<br>
  the optional type(s) of vehicles that are restricted to access the road work zone. 
   More than one vehicle types may be provided by this component if the restriction apply to multiple vehicle types. 

* _speedLimit_ of type [**SpeedLimit**](ETSI-ITS-CDD.md#SpeedLimit)  OPTIONAL<br>
  the optional speed limitation applied to the roadwork zone.

* _incidentIndication_ of type [**CauseCodeV2**](ETSI-ITS-CDD.md#CauseCodeV2)  OPTIONAL<br>
  the optional incident related to the roadworks to provide additional information of the roadworks zone.

* _recommendedPath_ of type [**ItineraryPath**](ETSI-ITS-CDD.md#ItineraryPath)  OPTIONAL<br>
  the optional recommended itinerary in order to contour the roadworks zone. If present, a recommended path 
   shall be a list of path points in the order from the starting point closest to the roadworks zone to the end point of the recommended path. 

* _startingPointSpeedLimit_ of type [**DeltaReferencePosition**](ETSI-ITS-CDD.md#DeltaReferencePosition)  OPTIONAL<br>
  the optional effective starting position of a speed limit being applied to the roadwork zone, 
   with respect to the component eventPosition on the Management Container.
   This component shall be present if the speed limit is applied at a certain distance prior to the roadwork zone starting position.

* _trafficFlowRule_ of type [**TrafficRule**](ETSI-ITS-CDD.md#TrafficRule)  OPTIONAL<br>
  optionally indicates the side of the road to which the traffic should flow around a roadwork.

* _referenceDenms_ of type [**ActionIdList**](ETSI-ITS-CDD.md#ActionIdList)  OPTIONAL<br>
  an optional sequence of actionIds for different DENMs that describe the same event. 
   If it is available, it indicates the actionIds of all other DENMs describing this event.

```asn1
RoadWorksContainerExtended ::= SEQUENCE {
    lightBarSirenInUse      LightBarSirenInUse OPTIONAL,
    closedLanes             ClosedLanes OPTIONAL,
    restriction             RestrictedTypes OPTIONAL,
    speedLimit              SpeedLimit OPTIONAL,
    incidentIndication      CauseCodeV2 OPTIONAL,
    recommendedPath         ItineraryPath OPTIONAL,
    startingPointSpeedLimit DeltaReferencePosition OPTIONAL,
    trafficFlowRule         TrafficRule OPTIONAL,
    referenceDenms          ActionIdList OPTIONAL
}
```

### <a name="StationaryVehicleContainer"></a>StationaryVehicleContainer
This type contains detailed information about a stationary vehicle.

 It shall include the following components:

* _stationarySince_ of type [**StationarySince**](ETSI-ITS-CDD.md#StationarySince)  OPTIONAL<br>
  the optional time duration of the stationary vehicle being stationary.

* _stationaryCause_ of type [**CauseCodeV2**](ETSI-ITS-CDD.md#CauseCodeV2)  OPTIONAL<br>
  optional additional information to describe causes of the stationary vehicle event such as human problem.

* _carryingDangerousGoods_ of type [**DangerousGoodsExtended**](ETSI-ITS-CDD.md#DangerousGoodsExtended)  OPTIONAL<br>
  optional information on the type of dangerous goods, the required emergency action and other information.

* _numberOfOccupants_ of type [**NumberOfOccupants**](ETSI-ITS-CDD.md#NumberOfOccupants)  OPTIONAL<br>
  the optional estimated number of occupants involved in the stationary vehicle event.

* _vehicleIdentification_ of type [**VehicleIdentification**](ETSI-ITS-CDD.md#VehicleIdentification)  OPTIONAL<br>
  the optional identification of the stationary vehicle.

* _energyStorageType_ of type [**EnergyStorageType**](ETSI-ITS-CDD.md#EnergyStorageType)  OPTIONAL<br>
  the optional vehicle energy storage type information of the stationary vehicle, such as electric, diesel, etc.

```asn1
StationaryVehicleContainer ::= SEQUENCE {
    stationarySince        StationarySince OPTIONAL, 
    stationaryCause        CauseCodeV2 OPTIONAL,
    carryingDangerousGoods DangerousGoodsExtended OPTIONAL,
    numberOfOccupants      NumberOfOccupants OPTIONAL,
    vehicleIdentification  VehicleIdentification OPTIONAL,
    energyStorageType      EnergyStorageType OPTIONAL
}
```

### <a name="AlacarteContainer"></a>AlacarteContainer
This type represents the A La Carte Container.

 It shall include the following components:

* _lanePosition_ of type [**LanePosition**](ETSI-ITS-CDD.md#LanePosition)  OPTIONAL<br>
  the optional lane position of the event.

* _impactReduction_ of type [**ImpactReductionContainer**](#ImpactReductionContainer)  OPTIONAL<br>
  optional vehicle data for collision mitigation.

* _externalTemperature_ of type [**Temperature**](ETSI-ITS-CDD.md#Temperature)  OPTIONAL<br>
  optional the ambient temperature at the event position.

* _roadWorks_ of type [**RoadWorksContainerExtended**](#RoadWorksContainerExtended)  OPTIONAL<br>
  optional information of the roadwork zone.

* _positioningSolution_ of type [**PositioningSolutionType**](ETSI-ITS-CDD.md#PositioningSolutionType)  OPTIONAL<br>
  optionally indicates the technical solution being used by the originating ITS-S to estimate the event position.

* _stationaryVehicle_ of type [**StationaryVehicleContainer**](#StationaryVehicleContainer)  OPTIONAL<br>
  optional information about a stationary vehicle.

* _roadConfiguration_ of type [**RoadConfigurationContainer**](#RoadConfigurationContainer)  OPTIONAL<br>
  optional information about the configuration of the road.

* _preCrash_ of type [**PreCrashContainer**](#PreCrashContainer)  OPTIONAL <br>
* precrash<br>
  the optional information about perceived objects that represent hazards and/or could be subject of collisions. 

```asn1
AlacarteContainer ::= SEQUENCE {
    lanePosition        LanePosition OPTIONAL,
    impactReduction     ImpactReductionContainer OPTIONAL,
    externalTemperature Temperature OPTIONAL,
    roadWorks           RoadWorksContainerExtended OPTIONAL,
    positioningSolution PositioningSolutionType OPTIONAL,
    stationaryVehicle   StationaryVehicleContainer OPTIONAL,
    ...,
[[  roadConfiguration 	RoadConfigurationContainer OPTIONAL,
    preCrash            PreCrashContainer OPTIONAL ]]
}
```

This type specifies the default value for DENM validity duration used for DENM protocol operation.

```asn1
defaultValidity INTEGER ::= 600
```

### <a name="Termination"></a>Termination
This indicates the termination type of generated DENM, i.e. if it is a cancellation DENM or a negation DENM
```asn1
Termination ::= ENUMERATED {isCancellation(0), isNegation (1)}
```



