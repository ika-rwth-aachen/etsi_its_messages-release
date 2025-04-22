# <a name="CAM-PDU-Descriptions"></a>ASN.1 module CAM-PDU-Descriptions
OID: _{itu-t (0) identified-organization (4) etsi (0) itsDomain (5) wg1 (1) camPduRelease2 (103900) major-version-2 (2) minor-version-1 (1)}_

## Imports:
* **[ETSI-ITS-CDD](ETSI-ITS-CDD.md)** *{itu-t (0) identified-organization (4) etsi (0) itsDomain (5) wg1 (1) 102894 cdd (2) major-version-4 (4) minor-version-1 (1)} WITH SUCCESSORS*<br/>
## Data Elements:
### <a name="CAM"></a>CAM
This type represents the CAM PDU.

 It shall include the following componenets:

* _header_ of type [**ItsPduHeader**](ETSI-ITS-CDD.md#ItsPduHeader)  (WITH COMPONENTS {... , protocolVersion (2), messageId(cam)})<br>
  the header of the CAM PDU.

* _cam_ of type [**CamPayload**](#CamPayload) <br>
  the payload of the CAM PDU.

```asn1
CAM ::= SEQUENCE {
	header ItsPduHeader (WITH COMPONENTS {... , protocolVersion (2), messageId(cam)}),
	cam    CamPayload
}
```

### <a name="CamPayload"></a>CamPayload
This type represents the CAM payload. 

 It shall include the following components:

* _generationDeltaTime_ of type [**GenerationDeltaTime**](ETSI-ITS-CDD.md#GenerationDeltaTime) <br>
  Time corresponding to the time of the reference position in the CAM, considered as time of the CAM generation.

* _camParameters_ of type [**CamParameters**](#CamParameters) <br>
  The sequence of CAM mandatory and optional container.

```asn1
CamPayload ::= SEQUENCE {
	generationDeltaTime GenerationDeltaTime,
	camParameters       CamParameters
}
```

### <a name="CamParameters"></a>CamParameters

* _basicContainer_ of type [**BasicContainer**](ETSI-ITS-CDD.md#BasicContainer) <br>
  the mandatory basic container of the CAM.

* _highFrequencyContainer_ of type [**HighFrequencyContainer**](#HighFrequencyContainer) <br>
  the mandatory container represents the high frequency of the CAM.

* _lowFrequencyContainer_ of type [**LowFrequencyContainer**](#LowFrequencyContainer)  OPTIONAL<br>
  the optional conatainer represents the low frequency of the CAM.

* _specialVehicleContainer_ of type [**SpecialVehicleContainer**](#SpecialVehicleContainer)  OPTIONAL<br>
  The special container of the CAM shall be present as defined in clause 6.1.2. 
   The content of the container shall be set according to the value of the vehicleRole component as specified in Table 5. 

```asn1
CamParameters ::= SEQUENCE {
	basicContainer           BasicContainer,
	highFrequencyContainer   HighFrequencyContainer,
	lowFrequencyContainer    LowFrequencyContainer OPTIONAL,
	specialVehicleContainer  SpecialVehicleContainer OPTIONAL,
	...
}
```

### <a name="HighFrequencyContainer"></a>HighFrequencyContainer
This type represents the high frequency container.
 
 It shall include the following components:

* _basicVehicleContainerHighFrequency_ of type [**BasicVehicleContainerHighFrequency**](#BasicVehicleContainerHighFrequency) <br>
  The mandatory high frequency container of the CAM when the originating ITS-S is of the type vehicle ITS-S.

* _rsuContainerHighFrequency_ of type [**RSUContainerHighFrequency**](#RSUContainerHighFrequency) <br>
  The mandatory high frequency container of CAM when the type of the originating ITS-S is RSU ITS-S.

```asn1
HighFrequencyContainer ::= CHOICE {
	basicVehicleContainerHighFrequency BasicVehicleContainerHighFrequency,
	rsuContainerHighFrequency          RSUContainerHighFrequency,
	...
}
```

### <a name="LowFrequencyContainer"></a>LowFrequencyContainer
This type represents the low frequency container.
 
 It shall include the following components: 

 The low frequency container of the CAM when the originating ITS-S is of the type vehicle ITS-S. It shall be present as defined in clause 6.1.2.

* _basicVehicleContainerLowFrequency_ of type [**BasicVehicleContainerLowFrequency**](#BasicVehicleContainerLowFrequency)  (WITH COMPONENTS {..., pathHistory (SIZE (0..23))})<br>
```asn1
LowFrequencyContainer ::= CHOICE {
  basicVehicleContainerLowFrequency BasicVehicleContainerLowFrequency (WITH COMPONENTS {..., pathHistory (SIZE (0..23))}),
	...
}
```

### <a name="SpecialVehicleContainer"></a>SpecialVehicleContainer
This type represent the Special Vehicle Container.

 It shall include the following components:

* _publicTransportContainer_ of type [**PublicTransportContainer**](#PublicTransportContainer) <br>
  If the vehicleRole component is set to publicTransport(1) this container shall be present.

* _specialTransportContainer_ of type [**SpecialTransportContainer**](#SpecialTransportContainer) <br>
  If the vehicleRole component is set to specialTransport(2) this container shall be present.

* _dangerousGoodsContainer_ of type [**DangerousGoodsContainer**](#DangerousGoodsContainer) <br>
  If the vehicleRole component is set to dangerousGoods(3) this container shall be present.

* _roadWorksContainerBasic_ of type [**RoadWorksContainerBasic**](#RoadWorksContainerBasic) <br>
  If the vehicleRole component is set to roadWork(4) this container shall be present. 

* _rescueContainer_ of type [**RescueContainer**](#RescueContainer) <br>
  If the vehicleRole component is set to rescue(5) this container shall be present. 

* _emergencyContainer_ of type [**EmergencyContainer**](#EmergencyContainer) <br>
  If the vehicleRole component is set to emergency(6) this container shall be present.

* _safetyCarContainer_ of type [**SafetyCarContainer**](#SafetyCarContainer) <br>
  If the vehicleRole component is set to safetyCar(7) this container shall be present. 

```asn1
SpecialVehicleContainer ::= CHOICE {
	publicTransportContainer  PublicTransportContainer,
	specialTransportContainer SpecialTransportContainer,
	dangerousGoodsContainer   DangerousGoodsContainer,
	roadWorksContainerBasic   RoadWorksContainerBasic,
	rescueContainer           RescueContainer,
	emergencyContainer        EmergencyContainer,
	safetyCarContainer        SafetyCarContainer,
	...
}
```

### <a name="BasicVehicleContainerHighFrequency"></a>BasicVehicleContainerHighFrequency
This type contains detaild information of the Basic Vehicle Container High Frequency.

 It shall include the following components:

* _heading_ of type [**Heading**](ETSI-ITS-CDD.md#Heading) <br>
  It represent the heading and heading accuracy of the vehicle movement of the originating ITS-S with regards to the true north. 
   The heading accuracy provided in the heading Confidence value shall provide the accuracy of the measured vehicle heading with a confidence level 
   of 95 %. Otherwise, the value of the headingConfidence shall be set to unavailable.

* _speed_ of type [**Speed**](ETSI-ITS-CDD.md#Speed) <br>
  It represent driving speed and speed accuracy of the originating ITS-S. The speed accuracy provided in the speedConfidence shall 
   provide the accuracy of the speed value with a confidence level of 95 %. Otherwise, the speedConfidence shall be set to unavailable.

* _driveDirection_ of type [**DriveDirection**](ETSI-ITS-CDD.md#DriveDirection) <br>
  This component represent the vehicle drive direction (forward or backward) of the originating ITS-S.

* _vehicleLength_ of type [**VehicleLength**](ETSI-ITS-CDD.md#VehicleLength) <br>
  This component represent the vehicle length value and vehicle length confidence indication of the vehicle ITS-S that 
   originate the CAM. 

* _vehicleWidth_ of type [**VehicleWidth**](ETSI-ITS-CDD.md#VehicleWidth) <br>
  This component represents the Vehicle Width of the vehicle ITS-S that originates the CAM excluding side mirrors and possible
   similar extensions.

* _longitudinalAcceleration_ of type [**AccelerationComponent**](ETSI-ITS-CDD.md#AccelerationComponent) <br>
  It represent the vehicle Longitudinal Acceleration of the originating ITS-S in the centre of the mass of the 
   empty vehicle. It shall include the measured vehicle longitudinal acceleration and its accuracy value with the confidence level of 95 %. 
   Otherwise, the longitudinalAccelerationConfidence shall be set to unavailable. 

* _curvature_ of type [**Curvature**](ETSI-ITS-CDD.md#Curvature) <br>
  this component reppresent the actual trajectory of the vehicle. 

* _curvatureCalculationMode_ of type [**CurvatureCalculationMode**](ETSI-ITS-CDD.md#CurvatureCalculationMode) <br>
  It indicates whether vehicle yaw-rate is used in the calculation of the curvature of the vehicle ITS-S that
   originates the CAM.

* _yawRate_ of type [**YawRate**](ETSI-ITS-CDD.md#YawRate) <br>
  It denotes the vehicle rotation around the centre of mass of the empty vehicle. The leading sign denotes the direction of 
   rotation. The value is negative if the motion is clockwise when viewing from the top.
   yawRateConfidence denotes the accuracy for the 95 % confidence level for the measured yawRateValue. Otherwise, the value of yawRateConfidence
   shall be set to unavailable.

* _accelerationControl_ of type [**AccelerationControl**](ETSI-ITS-CDD.md#AccelerationControl)  OPTIONAL<br>
  an optional component which represents the current status of the vehcile mechnanisms controlling the longitudinal movement of the vehcile ITS-S
   (e.g. brake pedal,  gas pedal, etc. engaged) that originate the CAM.

* _lanePosition_ of type [**LanePosition**](ETSI-ITS-CDD.md#LanePosition)  OPTIONAL<br>
  an optional component which represents the lanePosition of the referencePosition of a vehicle. This component shall be present if the data is 
   available at the originating ITS-S.

* _steeringWheelAngle_ of type [**SteeringWheelAngle**](ETSI-ITS-CDD.md#SteeringWheelAngle)  OPTIONAL<br>
  an optional component which indicates the steering wheel angle and accuracy as measured at the vehicle ITS-S that originates the CAM.

* _lateralAcceleration_ of type [**AccelerationComponent**](ETSI-ITS-CDD.md#AccelerationComponent)  OPTIONAL<br>
  an optional component which represents the vehicle lateral acceleration of the originating ITS-S in the centre of the mass of the empty vehicle. 
   It shall include the measured vehicle lateral acceleration and its accuracy value with the confidence level of 95%.

* _verticalAcceleration_ of type [**AccelerationComponent**](ETSI-ITS-CDD.md#AccelerationComponent)  OPTIONAL<br>
  an optional component which indicates the originating ITS-S in the centre of the mass of the empty vehicle.

* _performanceClass_ of type [**PerformanceClass**](ETSI-ITS-CDD.md#PerformanceClass)  OPTIONAL<br>
  an optional component characterizes the maximum age of the CAM data elements with regard to the generation delta time.

* _cenDsrcTollingZone_ of type [**CenDsrcTollingZone**](ETSI-ITS-CDD.md#CenDsrcTollingZone)  OPTIONAL<br>
  an optional component which represents the information about the position of a CEN DSRC Tolling Station operating in the 5,8 GHz frequency band.

```asn1
BasicVehicleContainerHighFrequency ::= SEQUENCE {
	heading Heading,
	speed Speed,
	driveDirection DriveDirection,
	vehicleLength VehicleLength,
	vehicleWidth VehicleWidth,
	longitudinalAcceleration AccelerationComponent,
	curvature Curvature,
	curvatureCalculationMode CurvatureCalculationMode,
	yawRate YawRate,
	accelerationControl AccelerationControl OPTIONAL,
	lanePosition LanePosition OPTIONAL,
	steeringWheelAngle SteeringWheelAngle OPTIONAL,
	lateralAcceleration AccelerationComponent OPTIONAL,
	verticalAcceleration AccelerationComponent OPTIONAL,
	performanceClass PerformanceClass OPTIONAL,
	cenDsrcTollingZone CenDsrcTollingZone OPTIONAL
}
```

### <a name="BasicVehicleContainerLowFrequency"></a>BasicVehicleContainerLowFrequency
This type contains detaild information of the Basic Vehicle Container Low Frequency.

 It shall include the following components:

* _vehicleRole_ of type [**VehicleRole**](ETSI-ITS-CDD.md#VehicleRole) <br>
  represent the role of the vehicle ITS-S that originates the CAM. Only values 0 to 7 shall be used.

* _exteriorLights_ of type [**ExteriorLights**](ETSI-ITS-CDD.md#ExteriorLights) <br>
  represent the status of the most important exterior lights switches of the vehicle ITS-S that originates the CAM.

* _pathHistory_ of type [**Path**](ETSI-ITS-CDD.md#Path) <br>
  which represents the vehicle's recent movement over some past time and/or distance. It consists of a list of path points,
   each represented as DF PathPoint. The list of path points may consist of up to 23 elements. 

```asn1
BasicVehicleContainerLowFrequency  ::= SEQUENCE {
	vehicleRole VehicleRole,
	exteriorLights ExteriorLights,
	pathHistory Path
}
```

### <a name="PublicTransportContainer"></a>PublicTransportContainer
This type contains detaild information of the Public Transport Container.

 It shall include the following components:

* _embarkationStatus_ of type [**EmbarkationStatus**](ETSI-ITS-CDD.md#EmbarkationStatus) <br>
  It indicates whether the passenger embarkation is currently ongoing. 

* _ptActivation_ of type [**PtActivation**](ETSI-ITS-CDD.md#PtActivation)  OPTIONAL<br>
  an optional component used for controlling traffic lights, barriers, bollards, etc.

```asn1
PublicTransportContainer ::= SEQUENCE {
	embarkationStatus EmbarkationStatus,
	ptActivation PtActivation OPTIONAL
}
```

### <a name="SpecialTransportContainer"></a>SpecialTransportContainer
This type contains detaild information of the Special Transport Container.

 It shall include the following components:

* _specialTransportType_ of type [**SpecialTransportType**](ETSI-ITS-CDD.md#SpecialTransportType) <br>
  which indicates whether the originating ITS-S is mounted on a special transport vehicle with heavy or oversized load
   or both. It shall be present if the data is available in originating ITS-S.

* _lightBarSirenInUse_ of type [**LightBarSirenInUse**](ETSI-ITS-CDD.md#LightBarSirenInUse) <br>
  indicates whether light-bar or a siren is in use by the vehicle originating the CAM.

```asn1
SpecialTransportContainer ::= SEQUENCE {
	specialTransportType SpecialTransportType,
	lightBarSirenInUse LightBarSirenInUse
}
```

### <a name="DangerousGoodsContainer"></a>DangerousGoodsContainer
This type contains detaild information of the Dangerous Goods Container.

 It shall include the following components:

* _dangerousGoodsBasic_ of type [**DangerousGoodsBasic**](ETSI-ITS-CDD.md#DangerousGoodsBasic) <br>
  identifies the type of the dangerous goods transported by the vehicle that originates the CAM. It shall be present if
   the data is available in the originating ITS S.

```asn1
DangerousGoodsContainer ::= SEQUENCE {
  dangerousGoodsBasic DangerousGoodsBasic
 }
```

### <a name="RoadWorksContainerBasic"></a>RoadWorksContainerBasic
This type contains detaild information of the Road Works Container Basic.

 It shall include the following components:

* _roadworksSubCauseCode_ of type [**RoadworksSubCauseCode**](ETSI-ITS-CDD.md#RoadworksSubCauseCode)  OPTIONAL<br>
  The optional component, in case the originating ITS-S is mounted to a vehicle ITS-S participating to roadwork. It 
   provides information on the type of roadwork that it is currently undertaking. This component shall be present if the data is available in 
   originating ITS S.

* _lightBarSirenInUse_ of type [**LightBarSirenInUse**](ETSI-ITS-CDD.md#LightBarSirenInUse) <br>
  it indicates whether light-bar or a siren is in use by the vehicle originating the CAM.

* _closedLanes_ of type [**ClosedLanes**](ETSI-ITS-CDD.md#ClosedLanes)  OPTIONAL<br>
  an optional component which provides information about the opening/closure status of the lanes ahead. Lanes are counted from
   the outside boarder of the road. If a lane is closed to traffic, the corresponding bit shall be set to 1.

```asn1
RoadWorksContainerBasic ::= SEQUENCE {
  roadworksSubCauseCode RoadworksSubCauseCode OPTIONAL,
  lightBarSirenInUse LightBarSirenInUse,
  closedLanes ClosedLanes OPTIONAL
 }
```

### <a name="RescueContainer"></a>RescueContainer
This type contains detaild information of the Rescue Container.

 It shall include the following components:

* _lightBarSirenInUse_ of type [**LightBarSirenInUse**](ETSI-ITS-CDD.md#LightBarSirenInUse) <br>
  it indicates whether light-bar or a siren is in use by the vehicle originating the CAM.

```asn1
RescueContainer ::= SEQUENCE {
	lightBarSirenInUse LightBarSirenInUse
}
```

### <a name="EmergencyContainer"></a>EmergencyContainer
This type contains detaild information of the Emergency Container.

 It shall include the following components:

* _lightBarSirenInUse_ of type [**LightBarSirenInUse**](ETSI-ITS-CDD.md#LightBarSirenInUse) <br>
  it indicates whether light-bar or a siren is in use by the vehicle originating the CAM.

* _incidentIndication_ of type [**CauseCodeV2**](ETSI-ITS-CDD.md#CauseCodeV2)  OPTIONAL<br>
  the optional incident related to the roadworks to provide additional information of the roadworks zone.

* _emergencyPriority_ of type [**EmergencyPriority**](ETSI-ITS-CDD.md#EmergencyPriority)  OPTIONAL<br>
  the optional component represent right of way indicator of the vehicle ITS-S that originates the CAM PDU.

```asn1
EmergencyContainer ::= SEQUENCE {
	lightBarSirenInUse LightBarSirenInUse,
	incidentIndication CauseCodeV2 OPTIONAL,
	emergencyPriority EmergencyPriority OPTIONAL
}
```

### <a name="SafetyCarContainer"></a>SafetyCarContainer
This type contains detaild information of the Safety Car Container.

 It shall include the following components:

* _lightBarSirenInUse_ of type [**LightBarSirenInUse**](ETSI-ITS-CDD.md#LightBarSirenInUse) <br>
  it indicates whether light-bar or a siren is in use by the vehicle originating the CAM.

* _incidentIndication_ of type [**CauseCodeV2**](ETSI-ITS-CDD.md#CauseCodeV2)  OPTIONAL<br>
  the optional incident related to the roadworks to provide additional information of the roadworks zone.

* _trafficRule_ of type [**TrafficRule**](ETSI-ITS-CDD.md#TrafficRule)  OPTIONAL<br>
  an optional rule indicates whether vehicles are allowed to overtake a safety car that is originating this CAM.

* _speedLimit_ of type [**SpeedLimit**](ETSI-ITS-CDD.md#SpeedLimit)  OPTIONAL<br>
  an optional speed indicates whether a speed limit is applied to vehicles following the safety car. 

```asn1
SafetyCarContainer ::= SEQUENCE {
	lightBarSirenInUse LightBarSirenInUse,
	incidentIndication CauseCodeV2 OPTIONAL,
	trafficRule TrafficRule OPTIONAL,
	speedLimit SpeedLimit OPTIONAL
}
```

### <a name="RSUContainerHighFrequency"></a>RSUContainerHighFrequency
This type contains detaild information of the RSU Container High Frequency.

 It shall include the following components:

* _protectedCommunicationZonesRSU_ of type [**ProtectedCommunicationZonesRSU**](ETSI-ITS-CDD.md#ProtectedCommunicationZonesRSU)  OPTIONAL<br>
  an optional Information about position of a CEN DSRC Tolling Station operating in the 5,8 GHz frequency 
   band. If this information is provided by RSUs a receiving vehicle ITS-S is prepared to adopt mitigation techniques when being in the vicinity of
   CEN DSRC tolling stations. 

```asn1
RSUContainerHighFrequency ::= SEQUENCE {
	protectedCommunicationZonesRSU ProtectedCommunicationZonesRSU OPTIONAL,
	...
}
```



