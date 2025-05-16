# <a name="VAM-PDU-Descriptions"></a>ASN.1 module VAM-PDU-Descriptions
OID: _{itu-t(0) identified-organization(4) etsi(0) itsDomain(5) wg1(1) 103300 vam(1) major-version-3(3) minor-version-1(1)}_

## Imports:
* **[ETSI-ITS-CDD](ETSI-ITS-CDD.md)** *{itu-t (0) identified-organization (4) etsi (0) itsDomain (5) wg1 (1) 102894 cdd (2) major-version-3 (3) minor-version-1 (1) } WITH SUCCESSORS*<br/>
## Data Elements:
### <a name="VAM"></a>VAM

* _header_ of type [**ItsPduHeaderVam**](#ItsPduHeaderVam) <br>
* _vam_ of type [**VruAwareness**](#VruAwareness) <br>
```asn1
VAM ::= SEQUENCE {
        header ItsPduHeaderVam,
        vam    VruAwareness
    }
```

### <a name="ItsPduHeaderVam"></a>ItsPduHeaderVam
The ITS PDU header for the VAM.

 This DF includes DEs for the VAM _protocolVersion_, the VAM message type identifier _messageID_ 
 and the station identifier _stationID_ of the originating ITS-S.

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Communication information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V2.2.1_
```asn1
ItsPduHeaderVam ::= ItsPduHeader(WITH COMPONENTS {..., protocolVersion(3), messageId(vam)})
```

### <a name="VruAwareness"></a>VruAwareness
VAM payload.

 It includes the time stamp of the VAM and the VAM different containers

* _generationDeltaTime_ of type [**GenerationDeltaTime**](ETSI-ITS-CDD.md#GenerationDeltaTime) <br>
* _vamParameters_ of type [**VamParameters**](#VamParameters) <br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Communication information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V2.2.1_
```asn1
VruAwareness ::= SEQUENCE {
        generationDeltaTime  GenerationDeltaTime,
        vamParameters        VamParameters 
    }
```

### <a name="VamParameters"></a>VamParameters
The VAM payload includes the [**BasicContainer**](ETSI-ITS-CDD.md#BasicContainer) and [**VruHighFrequencyContainer**](#VruHighFrequencyContainer). 
 The VAM payload may also include additional containers: [**VruLowFrequencyContainer**](#VruLowFrequencyContainer),
 [**VruClusterInformationContainer**](#VruClusterInformationContainer), [**VruClusterOperationContainer**](#VruClusterOperationContainer) and [**VruMotionPredictionContainer**](#VruMotionPredictionContainer).
 The selection of the additional containers depends on the dissemination criteria, 
 e.g. _vruCluster_ or _MotionDynamicPrediction_ availability.

* _basicContainer_ of type [**BasicContainer**](ETSI-ITS-CDD.md#BasicContainer) <br>
* _vruHighFrequencyContainer_ of type [**VruHighFrequencyContainer**](#VruHighFrequencyContainer) <br>
* _vruLowFrequencyContainer_ of type [**VruLowFrequencyContainer**](#VruLowFrequencyContainer)  OPTIONAL<br>
* _vruClusterInformationContainer_ of type [**VruClusterInformationContainer**](#VruClusterInformationContainer)  OPTIONAL<br>
* _vruClusterOperationContainer_ of type [**VruClusterOperationContainer**](#VruClusterOperationContainer)  OPTIONAL<br>
* _vruMotionPredictionContainer_ of type [**VruMotionPredictionContainer**](#VruMotionPredictionContainer)  OPTIONAL<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Communication information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V2.2.1_
```asn1
VamParameters ::= SEQUENCE {
        basicContainer                 BasicContainer,
        vruHighFrequencyContainer      VruHighFrequencyContainer, 
        vruLowFrequencyContainer       VruLowFrequencyContainer OPTIONAL,
        vruClusterInformationContainer VruClusterInformationContainer OPTIONAL,
        vruClusterOperationContainer   VruClusterOperationContainer OPTIONAL,
        vruMotionPredictionContainer   VruMotionPredictionContainer OPTIONAL,
        ...
    }
```

### <a name="VruHighFrequencyContainer"></a>VruHighFrequencyContainer
The VRU HF container of the VAM contains potentially fast-changing status information of the VRU ITS-S.
 It includes the following components (setting indications are specified in clause 7.3.3 of TS 103 300-3):

* _heading_ of type [**Wgs84Angle**](ETSI-ITS-CDD.md#Wgs84Angle) <br>
  heading and heading confidence of the originating VRU with regards to the true north. 

* _speed_ of type [**Speed**](ETSI-ITS-CDD.md#Speed) <br>
  speed in moving direction and speed confidence of the originating VRU.   

* _longitudinalAcceleration_ of type [**LongitudinalAcceleration**](ETSI-ITS-CDD.md#LongitudinalAcceleration) <br>
  longitudinal acceleration of the originating VRU. 

* _curvature_ of type [**Curvature**](ETSI-ITS-CDD.md#Curvature)  OPTIONAL<br>
  related to the actual trajectory of the originating VRU vehicle.
            _(recommended for VRU Profile 2)_

* _curvatureCalculationMode_ of type [**CurvatureCalculationMode**](ETSI-ITS-CDD.md#CurvatureCalculationMode)  OPTIONAL<br>
  indicates whether vehicle yaw-rate is used in the calculation of
          the curvature of the VRU vehicle ITS-S that originates the VAM. _(recommended for VRU Profile 2)_

* _yawRate_ of type [**YawRate**](ETSI-ITS-CDD.md#YawRate)  OPTIONAL<br>
  yaw rate of originating VRU vehicle. _(recommended for VRU Profile 2)_

* _lateralAcceleration_ of type [**LateralAcceleration**](ETSI-ITS-CDD.md#LateralAcceleration)  OPTIONAL<br>
  originating VRU lateral acceleration in the street plane.
          This field shall be present if the data is available at the originating ITS-S. _(recommended for VRU Profile 2)_ 

* _verticalAcceleration_ of type [**VerticalAcceleration**](ETSI-ITS-CDD.md#VerticalAcceleration)  OPTIONAL<br>
  vertical acceleration of the originating VRU.
          This field shall be present if the data is available at the originating ITS-S.

* _vruLanePosition_ of type [**GeneralizedLanePosition**](ETSI-ITS-CDD.md#GeneralizedLanePosition)  OPTIONAL<br>
  lane position of the referencePosition of a VRU, which is either a VRU-specific non-traffic lane  
          or a standard traffic lane. This field shall be present if the data is available at the originating ITS-S.

* _environment_ of type [**VruEnvironment**](ETSI-ITS-CDD.md#VruEnvironment)  OPTIONAL<br>
  provides contextual awareness of the VRU among other road users.
          This field shall be present only if the data is available at the originating ITS-S.

* _movementControl_ of type [**VruMovementControl**](ETSI-ITS-CDD.md#VruMovementControl)  OPTIONAL<br>
  indicates the mechanism used by the VRU to control the  longitudinal movement of the VRU vehicle.
          This field shall be present only if the data is available at the originating ITS-S. _(recommended for VRU Profile 2)_

* _orientation_ of type [**Wgs84Angle**](ETSI-ITS-CDD.md#Wgs84Angle)  OPTIONAL<br>
  complements the dimensions of the VRU vehicle by defining the angle of the VRU vehicle longitudinal
          axis with regards to the WGS84 north. _(recommended for VRU Profile 2)_

* _rollAngle_ of type [**CartesianAngle**](ETSI-ITS-CDD.md#CartesianAngle)  OPTIONAL<br>
  provides the angle and angle accuracy between the ground plane and the current orientation of a vehicle's
          y-axis with respect to the ground plane about the x-axis according to the ISO 8855. 
          This field shall be present only if the data is available at the originating ITS-S. _(recommended for VRU Profile 2)_

* _deviceUsage_ of type [**VruDeviceUsage**](ETSI-ITS-CDD.md#VruDeviceUsage)  OPTIONAL<br>
  provides indications from the personal device about the potential 
          activity of the VRU. This field shall be present only if the data is available at the originating ITS-S.
          _(recommended for VRU Profile 1)_


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** VRU information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V2.2.1_
```asn1
VruHighFrequencyContainer ::= SEQUENCE {
        heading                  Wgs84Angle,  
        speed                    Speed, 
        longitudinalAcceleration LongitudinalAcceleration, 
        curvature                Curvature OPTIONAL, 
        curvatureCalculationMode CurvatureCalculationMode OPTIONAL, 
        yawRate                  YawRate OPTIONAL, 
        lateralAcceleration      LateralAcceleration OPTIONAL, 
        verticalAcceleration     VerticalAcceleration OPTIONAL, 
        vruLanePosition          GeneralizedLanePosition OPTIONAL, 
        environment              VruEnvironment OPTIONAL,
        movementControl          VruMovementControl OPTIONAL,
        orientation              Wgs84Angle OPTIONAL, 
        rollAngle                CartesianAngle OPTIONAL,  
        deviceUsage              VruDeviceUsage OPTIONAL,
        ...
    }
```

### <a name="VruLowFrequencyContainer"></a>VruLowFrequencyContainer
The VRU LF container of the VAM contains potentially slow-changing information of the VRU ITS-S.
 It is mandatory with higher periodicity as specified in clause 6.2 or when VRU cluster operation container is present.
 It includes the following components (setting indications are specified in clause 7.3.4 of TS 103 300-3):

* _profileAndSubprofile_ of type [**VruProfileAndSubprofile**](ETSI-ITS-CDD.md#VruProfileAndSubprofile) <br>
  profile of the ITS-S that originates the VAM, including sub-profile information. 

* _sizeClass_ of type [**VruSizeClass**](ETSI-ITS-CDD.md#VruSizeClass)  OPTIONAL<br>
  information about the size of the VRU. 

* _exteriorLights_ of type [**VruExteriorLights**](ETSI-ITS-CDD.md#VruExteriorLights)  OPTIONAL<br>
  status of the most important exterior lights switches of the VRU ITS-S that originates the VAM. 
          _(conditional mandatory as specified in clause 7.3.4 of TS 103 300-3)_ 


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** VRU information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V2.2.1_
```asn1
VruLowFrequencyContainer ::= SEQUENCE {
        profileAndSubprofile     VruProfileAndSubprofile,
        sizeClass                VruSizeClass OPTIONAL,        
		exteriorLights           VruExteriorLights OPTIONAL,
       ...
    }
```

### <a name="VruClusterInformationContainer"></a>VruClusterInformationContainer
The VRU Cluster Information container of the VAM provides the information/parameters relevant to the VRU cluster.
 It is mandatory if the VAM is transmitted by VRU cluster leader.
 It includes the following components (setting indications are specified in clause 7.3.5 of TS 103 300-3):

* _vruClusterInformation_ of type [**VruClusterInformation**](ETSI-ITS-CDD.md#VruClusterInformation)  (WITH COMPONENTS{..., clusterId, clusterBoundingBoxShape PRESENT})<br>
  set of parammeters releated to the VRU cluster. 
          When transmitted by a VRU ITS-S, the clusterId and clusterBoundingBoxShape fields inside this DF shall be present.
          The clusterBoundingBoxShape is positioned with respect to the position sent in the BasicContainer.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** VRU information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V2.2.1_
```asn1
VruClusterInformationContainer::= SEQUENCE{ 
        vruClusterInformation    VruClusterInformation (WITH COMPONENTS{..., clusterId, clusterBoundingBoxShape PRESENT}), 
        ...
    }
```

### <a name="VruClusterOperationContainer"></a>VruClusterOperationContainer
The VRU Cluster Operation container of the VAM provides information relevant to change of cluster state and composition.
 It is mandatory if the VAM is transmitted by a VRU joining, leaving or breaking up a cluster.
 It includes the following components (setting indications are specified in clause 7.3.5 of TS 103 300-3). 
 At least one of the fields below shall be present if the container is present in the VAM:

* _clusterJoinInfo_ of type [**ClusterJoinInfo**](ETSI-ITS-CDD.md#ClusterJoinInfo)  OPTIONAL<br>
  indicates the intent of an individual VAM transmitter to join a cluster. 

* _clusterLeaveInfo_ of type [**ClusterLeaveInfo**](ETSI-ITS-CDD.md#ClusterLeaveInfo)  OPTIONAL<br>
  indicates that an individual VAM transmitter has recently left the VRU cluster. 

* _clusterBreakupInfo_ of type [**ClusterBreakupInfo**](ETSI-ITS-CDD.md#ClusterBreakupInfo)  OPTIONAL<br>
  indicates the intent of a cluster VAM transmitter to stop sending cluster VAMs. 

* _clusterIdChangeTimeInfo_ of type [**DeltaTimeQuarterSecond**](ETSI-ITS-CDD.md#DeltaTimeQuarterSecond)  OPTIONAL<br>
  indicates the intent of a cluster VAM transmitter to change cluster ID. 


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** VRU information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V2.2.1_
```asn1
VruClusterOperationContainer ::= SEQUENCE {
        clusterJoinInfo         ClusterJoinInfo OPTIONAL,
        clusterLeaveInfo        ClusterLeaveInfo OPTIONAL,
        clusterBreakupInfo      ClusterBreakupInfo OPTIONAL,
        clusterIdChangeTimeInfo DeltaTimeQuarterSecond OPTIONAL,
        ...
    }
```

### <a name="VruMotionPredictionContainer"></a>VruMotionPredictionContainer
The VRU Motion Prediction container of the VAM carries the past and future motion state information of the VRU.
 It includes the following components (setting indications are specified in clause 7.3.6 of TS 103 300-3). 
 At least one of the fields below shall be present if the container is present in the VAM:

* _pathHistory_ of type [**PathHistory**](ETSI-ITS-CDD.md#PathHistory)  OPTIONAL<br>
  represents the VRU's recent movement over some past time and/or distance. 
          It consists of a list of path points. 

* _pathPrediction_ of type [**PathPredicted**](ETSI-ITS-CDD.md#PathPredicted)  OPTIONAL<br>
  provides the set of predicted locations of the ITS-S, confidence values 
          and the corresponding future time instants. 

* _safeDistance_ of type [**SequenceOfSafeDistanceIndication**](ETSI-ITS-CDD.md#SequenceOfSafeDistanceIndication)  OPTIONAL<br>
  provides indication of safe distance between an ego-VRU and up to 8 other ITS-S 
          or entity on the road to indicate whether the ego-VRU is at a safe distance (that is less likely to 
          physically collide) from another ITS-S or entity on the road. 

* _trajectoryInterceptionIndication_ of type [**SequenceOfTrajectoryInterceptionIndication**](ETSI-ITS-CDD.md#SequenceOfTrajectoryInterceptionIndication)  OPTIONAL<br>
  provides the indication for possible trajectory interception 
          with up to 8 VRUs or other objects on the road.. 

* _accelerationChangeIndication_ of type [**AccelerationChangeIndication**](ETSI-ITS-CDD.md#AccelerationChangeIndication)  OPTIONAL<br>
  provides an acceleration change indication of the VRU. 
          When present this DF indicates an anticipated change in the VRU speed for period of actionDeltaTime.

* _headingChangeIndication_ of type [**HeadingChangeIndication**](ETSI-ITS-CDD.md#HeadingChangeIndication)  OPTIONAL<br>
  provides additional data elements associated to heading change indicators 
          such as a change of travel direction (left or right). 
          The direction change action is performed for a period of actionDeltaTime. 

* _stabilityChangeIndication_ of type [**StabilityChangeIndication**](ETSI-ITS-CDD.md#StabilityChangeIndication)  OPTIONAL<br>
  provides an estimation of the VRU stability. 


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** GeoReference information VRU information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V2.2.1_
```asn1
VruMotionPredictionContainer ::= SEQUENCE {
        pathHistory                      PathHistory OPTIONAL,
        pathPrediction                   PathPredicted OPTIONAL,  
        safeDistance                     SequenceOfSafeDistanceIndication OPTIONAL,
        trajectoryInterceptionIndication SequenceOfTrajectoryInterceptionIndication OPTIONAL,
        accelerationChangeIndication     AccelerationChangeIndication OPTIONAL,
        headingChangeIndication          HeadingChangeIndication OPTIONAL,
        stabilityChangeIndication        StabilityChangeIndication OPTIONAL,
        ...
    }
```



