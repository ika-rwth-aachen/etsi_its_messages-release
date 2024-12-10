# <a name="ETSI-ITS-CDD"></a>ASN.1 module ETSI-ITS-CDD
OID: _{itu-t (0) identified-organization (4) etsi (0) itsDomain (5) wg1 (1) 102894 cdd (2) major-version-3 (3) minor-version-1 (1)}_

## Data Elements:
### <a name="AccelerationChange"></a>AccelerationChange
This DE indicates a change of acceleration.

 The value shall be set to:
 - 0 - `accelerate` - if the magnitude of the horizontal velocity vector increases.
 - 1 - `decelerate` - if the magnitude of the horizontal velocity vector decreases.

* **accelerate** (0)<br>
* **decelerate** (1)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Kinematic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
AccelerationChange::= ENUMERATED { 
    accelerate (0), 
    decelerate (1) 
}
```

### <a name="AccelerationConfidence"></a>AccelerationConfidence
This DE indicates the acceleration confidence value which represents the estimated absolute accuracy of an acceleration value with a default confidence level of 95 %. 
 If required, the confidence level can be defined by the corresponding standards applying this DE.

 The value shall be set to:
 - `n` (`n > 0` and `n < 101`) if the confidence value is equal to or less than n x 0,1 m/s<sup>2</sup>, and greater than (n-1) x 0,1 m/s<sup>2</sup>,
 - `101` if the confidence value is out of range i.e. greater than 10 m/s<sup>2</sup>,
 - `102` if the confidence value is unavailable.

 The value 0 shall not be used.

* **outOfRange** (101)<br>
* **unavailable** (102)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _0,1 m/s<sup>2</sup>_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Kinematic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Description revised in V2.1.1_

>>>
NOTE:&emsp;If an acceleration value is received and its confidence value is set to `outOfRange(101)`, it means that the value is not valid and therefore cannot be trusted. Such value is not useful for the application.
>>>
```asn1
AccelerationConfidence ::= INTEGER {
    outOfRange                 (101), 
    unavailable                (102)
} (0..102)
```

### <a name="AccelerationControl"></a>AccelerationControl
This DE indicates the current controlling mechanism for longitudinal movement of the vehicle.
 The data may be provided via the in-vehicle network. It indicates whether a specific in-vehicle
 acceleration control system is engaged or not. Currently, this DE includes the information of the
 vehicle brake pedal, gas pedal, emergency brake system, collision warning system, adaptive cruise
 control system, cruise control system and speed limiter system.

 The corresponding bit shall be set to 1 under the following conditions:
 - 0 - `brakePedalEngaged`      - Driver is stepping on the brake pedal,
 - 1 - `gasPedalEngaged`        - Driver is stepping on the gas pedal,
 - 2 - `emergencyBrakeEngaged`  - emergency brake system is engaged,
 - 3 - `collisionWarningEngaged`- collision warning system is engaged,
 - 4 - `accEngaged`             - ACC is engaged,
 - 5 - `cruiseControlEngaged`   - cruise control is engaged,
 - 6 - `speedLimiterEngaged`    - speed limiter is engaged.

 Otherwise (for example when the corresponding system is not available due to non equipped system
 or information is unavailable), the corresponding bit shall be set to 0.

* **brakePedalEngaged** (0)<br>
* **gasPedalEngaged** (1)<br>
* **emergencyBrakeEngaged** (2)<br>
* **collisionWarningEngaged** (3)<br>
* **accEngaged** (4)<br>
* **cruiseControlEngaged** (5)<br>
* **speedLimiterEngaged** (6)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Vehicle information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V1.3.1_

>>>
NOTE:&emsp;The system engagement condition is OEM specific and therefore out of scope of the present document.
>>>
```asn1
AccelerationControl ::= BIT STRING {
    brakePedalEngaged       (0),
    gasPedalEngaged         (1),
    emergencyBrakeEngaged   (2),
    collisionWarningEngaged (3),
    accEngaged              (4),
    cruiseControlEngaged    (5),
    speedLimiterEngaged     (6)
} (SIZE(7))
```

### <a name="AccelerationMagnitudeValue"></a>AccelerationMagnitudeValue
This DE represents the magnitude of the acceleration vector in a defined coordinate system.

 The value shall be set to:
 - `0` to indicate no acceleration,
 - `n` (`n > 0` and `n < 160`) to indicate acceleration equal to or less than n x 0,1 m/s<sup>2</sup>, and greater than (n-1) x 0,1 m/s<sup>2</sup>,
 - `160` for acceleration values greater than 15,9 m/s<sup>2</sup>,
 - `161` when the data is unavailable.

* **positiveOutOfRange** (160)<br>
* **unavailable** (161)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _0,1 m/s<sup>2</sup>_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Kinematic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
AccelerationMagnitudeValue ::= INTEGER {
    positiveOutOfRange (160),
    unavailable        (161)  
} (0.. 161)
```

### <a name="AccelerationValue"></a>AccelerationValue
This DE represents the value of an acceleration component in a defined coordinate system.

 The value shall be set to:
 - `-160` for acceleration values equal to or less than -16 m/s<sup>2</sup>,
 - `n` (`n > -160` and `n ≤ 0`) to indicate negative acceleration equal to or less than n x 0,1 m/s<sup>2</sup>, and greater than (n-1) x 0,1 m/s<sup>2</sup>,
 - `n` (`n > 0` and `n < 160`) to indicate positive acceleration equal to or less than n x 0,1 m/s<sup>2</sup>, and greater than (n-1) x 0,1 m/s<sup>2</sup>,
 - `160` for acceleration values greater than 15,9 m/s<sup>2</sup>,
 - `161` when the data is unavailable.

* **negativeOutOfRange** (-160)<br>
* **positiveOutOfRange** (160)<br>
* **unavailable** (161)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _0,1 m/s<sup>2</sup>_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Kinematic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_

>>>
NOTE:&emsp;the formula for values > -160 and <160 results in rounding up to the next value. Zero acceleration is indicated using n=0.
>>>
```asn1
AccelerationValue ::= INTEGER {
    negativeOutOfRange (-160),
    positiveOutOfRange (160),
    unavailable        (161)  
} (-160 .. 161)
```

### <a name="AccessTechnologyClass"></a>AccessTechnologyClass
This DE indicates an access technology.

 The value shall be set to:
 - `0`: in case of any access technology class,
 - `1`: in case of ITS-G5 access technology class,
 - `2`: in case of LTE-V2X access technology class,
 - `3`: in case of NR-V2X access technology class.

* **any** (0)<br>
* **itsg5Class** (1)<br>
* **ltev2xClass** (2)<br>
* **nrv2xClass** (3)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Communication information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
AccessTechnologyClass ::= ENUMERATED {
   any         (0), 
   itsg5Class  (1), 
   ltev2xClass (2), 
   nrv2xClass  (3),
   ...
}
```

### <a name="AccidentSubCauseCode"></a>AccidentSubCauseCode
This DE represents the value of the sub cause code of the [**CauseCode**](#CauseCode) `accident`.

 The value shall be set to:
 - 0 - `unavailable`                        - in case the information on the sub cause of the accident is unavailable,
 - 1 - `multiVehicleAccident`               - in case more than two vehicles are involved in accident,
 - 2 - `heavyAccident`                      - in case the airbag of the vehicle involved in the accident is triggered, 
                                              the accident requires important rescue and/or recovery work,
 - 3 - `accidentInvolvingLorry`             - in case the accident involves a lorry,
 - 4 - `accidentInvolvingBus`               - in case the accident involves a bus,
 - 5 - `accidentInvolvingHazardousMaterials`- in case the accident involves hazardous material,
 - 6 - `accidentOnOppositeLane`             - in case the accident happens on opposite lanes,
 - 7 - `unsecuredAccident`                  - in case the accident is not secured,
 - 8 - `assistanceRequested`                - in case rescue and assistance are requested,
 - 9-255                                    - reserved for future usage.

* **unavailable** (0)<br>
* **multiVehicleAccident** (1)<br>
* **heavyAccident** (2)<br>
* **accidentInvolvingLorry** (3)<br>
* **accidentInvolvingBus** (4)<br>
* **accidentInvolvingHazardousMaterials** (5)<br>
* **accidentOnOppositeLane** (6)<br>
* **unsecuredAccident** (7)<br>
* **assistanceRequested** (8)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Traffic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V1.3.1_
```asn1
AccidentSubCauseCode ::= INTEGER {
    unavailable                         (0),
    multiVehicleAccident                (1),
    heavyAccident                       (2),
    accidentInvolvingLorry              (3),
    accidentInvolvingBus                (4),
    accidentInvolvingHazardousMaterials (5),
    accidentOnOppositeLane              (6),
    unsecuredAccident                   (7),
    assistanceRequested                 (8)
} (0..255)
```

### <a name="AdverseWeatherCondition-AdhesionSubCauseCode"></a>AdverseWeatherCondition-AdhesionSubCauseCode
This DE represents the value of the sub cause code of the [**CauseCode**](#CauseCode) `adverseWeatherCondition-Adhesion`. 
 
 The value shall be set to:
 - 0 - `unavailable`     - in case information on the cause of the low road adhesion is unavailable,
 - 1 - `heavyFrostOnRoad`- in case the low road adhesion is due to heavy frost on the road,
 - 2 - `fuelOnRoad`      - in case the low road adhesion is due to fuel on the road,
 - 3 - `mudOnRoad`       - in case the low road adhesion is due to mud on the road,
 - 4 - `snowOnRoad`      - in case the low road adhesion is due to snow on the road,
 - 5 - `iceOnRoad`       - in case the low road adhesion is due to ice on the road,
 - 6 - `blackIceOnRoad`  - in case the low road adhesion is due to black ice on the road,
 - 7 - `oilOnRoad`       - in case the low road adhesion is due to oil on the road,
 - 8 - `looseChippings`  - in case the low road adhesion is due to loose gravel or stone fragments detached from a road surface or from a hazard,
 - 9 - `instantBlackIce` - in case the low road adhesion is due to instant black ice on the road surface,
 - 10 - `roadsSalted`    - when the low road adhesion is due to salted road,
 - 11-255                - are reserved for future usage.

* **unavailable** (0)<br>
* **heavyFrostOnRoad** (1)<br>
* **fuelOnRoad** (2)<br>
* **mudOnRoad** (3)<br>
* **snowOnRoad** (4)<br>
* **iceOnRoad** (5)<br>
* **blackIceOnRoad** (6)<br>
* **oilOnRoad** (7)<br>
* **looseChippings** (8)<br>
* **instantBlackIce** (9)<br>
* **roadsSalted** (10)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Traffic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V1.3.1_
```asn1
AdverseWeatherCondition-AdhesionSubCauseCode ::= INTEGER {
    unavailable      (0),
    heavyFrostOnRoad (1),
    fuelOnRoad       (2),
    mudOnRoad        (3),
    snowOnRoad       (4),
    iceOnRoad        (5),
    blackIceOnRoad   (6),
    oilOnRoad        (7),
    looseChippings   (8),
    instantBlackIce  (9),
    roadsSalted      (10)
} (0..255)
```

### <a name="AdverseWeatherCondition-ExtremeWeatherConditionSubCauseCode"></a>AdverseWeatherCondition-ExtremeWeatherConditionSubCauseCode
This DE represents the value of the sub cause codes of the [**CauseCode**](#CauseCode) `adverseWeatherCondition-ExtremeWeatherCondition`.

 The value shall be set to:
 - 0 - `unavailable` - in case information on the type of extreme weather condition is unavailable,
 - 1 - `strongWinds` - in case the type of extreme weather condition is strong wind,
 - 2 - `damagingHail`- in case the type of extreme weather condition is damaging hail,
 - 3 - `hurricane`   - in case the type of extreme weather condition is hurricane,
 - 4 - `thunderstorm`- in case the type of extreme weather condition is thunderstorm,
 - 5 - `tornado`     - in case the type of extreme weather condition is tornado,
 - 6 - `blizzard`    - in case the type of extreme weather condition is blizzard.
 - 7-255             - are reserved for future usage.

* **unavailable** (0)<br>
* **strongWinds** (1)<br>
* **damagingHail** (2)<br>
* **hurricane** (3)<br>
* **thunderstorm** (4)<br>
* **tornado** (5)<br>
* **blizzard** (6)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Traffic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V1.3.1_
```asn1
AdverseWeatherCondition-ExtremeWeatherConditionSubCauseCode ::= INTEGER {
    unavailable  (0),
    strongWinds  (1),
    damagingHail (2),
    hurricane    (3),
    thunderstorm (4),
    tornado      (5),
    blizzard     (6)
} (0..255)
```

### <a name="AdverseWeatherCondition-PrecipitationSubCauseCode"></a>AdverseWeatherCondition-PrecipitationSubCauseCode
This DE represents the value of the sub cause codes of the [**CauseCode**](#CauseCode) `adverseWeatherCondition-Precipitation`. 

 The value shall be set to:
 - 0 - `unavailable`   - in case information on the type of precipitation is unavailable,
 - 1 - `heavyRain`     - in case the type of precipitation is heavy rain,
 - 2 - `heavySnowfall` - in case the type of precipitation is heavy snow fall,
 - 3 - `softHail`      - in case the type of precipitation is soft hail.
 - 4-255               - are reserved for future usage

* **unavailable** (0)<br>
* **heavyRain** (1)<br>
* **heavySnowfall** (2)<br>
* **softHail** (3)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Traffic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V1.3.1_
```asn1
AdverseWeatherCondition-PrecipitationSubCauseCode ::= INTEGER {
    unavailable   (0),
    heavyRain     (1),
    heavySnowfall (2),
    softHail      (3)
} (0..255)
```

### <a name="AdverseWeatherCondition-VisibilitySubCauseCode"></a>AdverseWeatherCondition-VisibilitySubCauseCode
This DE represents the value of the sub cause codes of the [**CauseCode**](#CauseCode) `adverseWeatherCondition-Visibility`.

 The value shall be set to:
 - 0 - `unavailable`    - in case information on the cause of low visibility is unavailable,
 - 1 - `fog`            - in case the cause of low visibility is fog,
 - 2 - `smoke`          - in case the cause of low visibility is smoke,
 - 3 - `heavySnowfall`  - in case the cause of low visibility is heavy snow fall,
 - 4 - `heavyRain`      - in case the cause of low visibility is heavy rain,
 - 5 - `heavyHail`      - in case the cause of low visibility is heavy hail,
 - 6 - `lowSunGlare`    - in case the cause of low visibility is sun glare,
 - 7 - `sandstorms`     - in case the cause of low visibility is sand storm,
 - 8 - `swarmsOfInsects`- in case the cause of low visibility is swarm of insects.
 - 9-255                - are reserved for future usage

* **unavailable** (0)<br>
* **fog** (1)<br>
* **smoke** (2)<br>
* **heavySnowfall** (3)<br>
* **heavyRain** (4)<br>
* **heavyHail** (5)<br>
* **lowSunGlare** (6)<br>
* **sandstorms** (7)<br>
* **swarmsOfInsects** (8)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Traffic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V1.3.1_
```asn1
AdverseWeatherCondition-VisibilitySubCauseCode ::= INTEGER {
    unavailable     (0),
    fog             (1),
    smoke           (2),
    heavySnowfall   (3),
    heavyRain       (4),
    heavyHail       (5),
    lowSunGlare     (6),
    sandstorms      (7),
    swarmsOfInsects (8)
} (0..255)
```

### <a name="AirHumidity"></a>AirHumidity
This DE represents the air humidity in tenths of percent.

 The value shall be set to:
 - `n` (`n > 0` and `n < 1001`) indicates that the applicable value is equal to or less than n x 0,1 percent and greater than (n-1) x 0,1 percent.
 - `1001` indicates that the air humidity is unavailable.

* **oneHundredPercent** (1000)<br>
* **unavailable** (1001)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _0,1 %_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Basic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _created in V2.1.1_
```asn1
AirHumidity ::= INTEGER {
	oneHundredPercent   (1000),
	unavailable         (1001)
} (1..1001)
```

### <a name="AltitudeConfidence"></a>AltitudeConfidence
This DE indicates the altitude confidence value which represents the estimated absolute accuracy of an altitude value of a geographical point with a default confidence level of 95 %.
 If required, the confidence level can be defined by the corresponding standards applying this DE.

 The value shall be set to: 
   - 0  - `alt-000-01`   - if the confidence value is equal to or less than 0,01 metre,
   - 1  - `alt-000-02`   - if the confidence value is equal to or less than 0,02 metre and greater than 0,01 metre,
   - 2  - `alt-000-05`   - if the confidence value is equal to or less than 0,05 metre and greater than 0,02 metre,            
   - 3  - `alt-000-10`   - if the confidence value is equal to or less than 0,1 metre and greater than 0,05 metre,            
   - 4  - `alt-000-20`   - if the confidence value is equal to or less than 0,2 metre and greater than 0,1 metre,            
   - 5  - `alt-000-50`   - if the confidence value is equal to or less than 0,5 metre and greater than 0,2 metre,             
   - 6  - `alt-001-00`   - if the confidence value is equal to or less than 1 metre and greater than 0,5 metre,             
   - 7  - `alt-002-00`   - if the confidence value is equal to or less than 2 metres and greater than 1 metre,             
   - 8  - `alt-005-00`   - if the confidence value is equal to or less than 5 metres and greater than 2 metres,              
   - 9  - `alt-010-00`   - if the confidence value is equal to or less than 10 metres and greater than 5 metres,             
   - 10 - `alt-020-00`   - if the confidence value is equal to or less than 20 metres and greater than 10 metres,            
   - 11 - `alt-050-00`   - if the confidence value is equal to or less than 50 metres and greater than 20 metres,            
   - 12 - `alt-100-00`   - if the confidence value is equal to or less than 100 metres and greater than 50 metres,           
   - 13 - `alt-200-00`   - if the confidence value is equal to or less than 200 metres and greater than 100 metres,           
   - 14 - `outOfRange`   - if the confidence value is out of range, i.e. greater than 200 metres,
   - 15 - `unavailable`  - if the confidence value is unavailable.

* **alt-000-01** (0)<br>
* **alt-000-02** (1)<br>
* **alt-000-05** (2)<br>
* **alt-000-10** (3)<br>
* **alt-000-20** (4)<br>
* **alt-000-50** (5)<br>
* **alt-001-00** (6)<br>
* **alt-002-00** (7)<br>
* **alt-005-00** (8)<br>
* **alt-010-00** (9)<br>
* **alt-020-00** (10)<br>
* **alt-050-00** (11)<br>
* **alt-100-00** (12)<br>
* **alt-200-00** (13)<br>
* **outOfRange** (14)<br>
* **unavailable** (15)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** GeoReference information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Description revised in V2.1.1_

>>>
NOTE:&emsp;If an altitude value is received and its confidence value is set to `outOfRange(14)`, it means that the  
 altitude value is not valid and therefore cannot be trusted. Such value is not useful for the application.
>>>
```asn1
AltitudeConfidence ::= ENUMERATED {
    alt-000-01  (0),
    alt-000-02  (1),
    alt-000-05  (2),
    alt-000-10  (3),
    alt-000-20  (4),
    alt-000-50  (5),
    alt-001-00  (6),
    alt-002-00  (7),
    alt-005-00  (8),
    alt-010-00  (9),
    alt-020-00  (10),
    alt-050-00  (11),
    alt-100-00  (12),
    alt-200-00  (13),
    outOfRange  (14),
    unavailable (15)
}
```

### <a name="AltitudeValue"></a>AltitudeValue
This DE represents the altitude value in a WGS84 coordinate system.
 The specific WGS84 coordinate system is specified by the corresponding standards applying this DE.

 The value shall be set to: 
 - `-100 000` if the altitude is equal to or less than -1 000 m,
 - `n` (`n > -100 000` and `n < 800 000`) if the altitude is equal to or less than n  x 0,01 metre and greater than (n-1) x 0,01 metre,
 - `800 000` if the altitude  greater than 7 999,99 m,
 - `800 001` if the information is not available.

* **negativeOutOfRange** (-100000)<br>
* **postiveOutOfRange** (800000)<br>
* **unavailable** (800001)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _0,01 metre_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** GeoReference information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Description revised in V2.1.1 (definition of 800 000 has slightly changed)_

>>>
NOTE:&emsp;the range of this DE does not use the full binary encoding range, but all reasonable values are covered. In order to cover all possible altitude ranges a larger encoding would be necessary.
>>>
```asn1
AltitudeValue ::= INTEGER {
    negativeOutOfRange (-100000),
    postiveOutOfRange  (800000),
    unavailable        (800001)
} (-100000..800001)
```

### <a name="AngleConfidence"></a>AngleConfidence
This DE indicates the angle confidence value which represents the estimated absolute accuracy of an angle value with a default confidence level of 95 %.
 If required, the confidence level can be defined by the corresponding standards applying this DE.

 The value shall be set to: 
 - `n` (`n > 0` and `n < 126`)  if the accuracy is equal to or less than n * 0,1 degrees and greater than (n-1) x * 0,1 degrees,
 - `126` if the  accuracy is out of range, i.e. greater than 12,5 degrees,
 - `127` if the accuracy information is not available.

* **outOfRange** (126)<br>
* **unavailable** (127)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _0,1 degrees_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Basic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
AngleConfidence ::= INTEGER {
    outOfRange  (126),
    unavailable (127)   
} (1..127)
```

### <a name="AngularSpeedConfidence"></a>AngularSpeedConfidence
This DE indicates the angular speed confidence value which represents the estimated absolute accuracy of an angular speed value with a default confidence level of 95 %.
 If required, the confidence level can be defined by the corresponding standards applying this DE.
 For correlation computation, maximum interval levels can be assumed.

 The value shall be set to:
 - 0 - `degSec-01`   - if the accuracy is equal to or less than 1 degree/second,
 - 1 - `degSec-02`   - if the accuracy is equal to or less than 2 degrees/second and greater than 1 degree/second,
 - 2 - `degSec-05`   - if the accuracy is equal to or less than 5 degrees/second and greater than 2 degrees/second,
 - 3 - `degSec-10`   - if the accuracy is equal to or less than 10 degrees/second and greater than 5 degrees/second,
 - 4 - `degSec-20`   - if the accuracy is equal to or less than 20 degrees/second and greater than 10 degrees/second,
 - 5 - `degSec-50`   - if the accuracy is equal to or less than 50 degrees/second and greater than 20 degrees/second,
 - 6 - `outOfRange`  - if the accuracy is out of range, i.e. greater than 50 degrees/second,
 - 7 - `unavailable` - if the accuracy information is unavailable.

* **degSec-01** (0)<br>
* **degSec-02** (1)<br>
* **degSec-05** (2)<br>
* **degSec-10** (3)<br>
* **degSec-20** (4)<br>
* **degSec-50** (5)<br>
* **outOfRange** (6)<br>
* **unavailable** (7)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Kinematic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
AngularSpeedConfidence ::= ENUMERATED {
    degSec-01   (0), 
    degSec-02   (1),  
    degSec-05   (2), 
    degSec-10   (3), 
    degSec-20   (4),  
    degSec-50   (5), 
    outOfRange  (6),   
    unavailable (7)   
}
```

### <a name="AngularAccelerationConfidence"></a>AngularAccelerationConfidence
This DE indicates the angular acceleration confidence value which represents the estimated accuracy of an angular acceleration value with a default confidence level of 95 %.
 If required, the confidence level can be defined by the corresponding standards applying this DE.
 For correlation computation, maximum interval levels shall be assumed.

 The value shall be set to:
 - 0 - `degSecSquared-01` - if the accuracy is equal to or less than 1 degree/second<sup>2</sup>,
 - 1 - `degSecSquared-02` - if the accuracy is equal to or less than 2 degrees/second<sup>2</sup> and greater than 1 degree/second<sup>2</sup>,
 - 2 - `degSecSquared-05` - if the accuracy is equal to or less than 5 degrees/second<sup>2</sup> and greater than 1 degree/second<sup>2</sup>,
 - 3 - `degSecSquared-10` - if the accuracy is equal to or less than 10 degrees/second<sup>2</sup> and greater than 5 degrees/second<sup>2</sup>,
 - 4 - `degSecSquared-20` - if the accuracy is equal to or less than 20 degrees/second<sup>2</sup> and greater than 10 degrees/second<sup>2</sup>,
 - 5 - `degSecSquared-50` - if the accuracy is equal to or less than 50 degrees/second<sup>2</sup> and greater than 20 degrees/second<sup>2</sup>,
 - 6 - `outOfRange`       - if the accuracy is out of range, i.e. greater than 50 degrees/second<sup>2</sup>,
 - 7 - `unavailable`      - if the accuracy information is unavailable.

* **degSecSquared-01** (0)<br>
* **degSecSquared-02** (1)<br>
* **degSecSquared-05** (2)<br>
* **degSecSquared-10** (3)<br>
* **degSecSquared-20** (4)<br>
* **degSecSquared-50** (5)<br>
* **outOfRange** (6)<br>
* **unavailable** (7)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Kinematic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
AngularAccelerationConfidence ::= ENUMERATED {
    degSecSquared-01 (0), 
    degSecSquared-02 (1), 
    degSecSquared-05 (2),  
    degSecSquared-10 (3), 
    degSecSquared-20 (4),  
    degSecSquared-50 (5),  
    outOfRange       (6),     
    unavailable      (7)   
}
```

### <a name="AxlesCount"></a>AxlesCount
This DE indicates the number of axles of a passing train.

 The value shall be set to:
 - `n` (`n > 2` and `n < 1001`) indicates that the train has n x axles,
 - `1001`indicates that the number of axles is out of range,
 - `1002` the information is unavailable.

* **outOfRange** (1001)<br>
* **unavailable** (1002)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _Number of axles_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Vehicle information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
AxlesCount ::= INTEGER{
    outOfRange   (1001),
    unavailable  (1002)
} (2..1002)
```

### <a name="BarometricPressure"></a>BarometricPressure
This DE represents the measured uncompensated atmospheric pressure.
 
 The value shall be set to:
 - `2999` indicates that the applicable value is less than 29990 Pa,
 - `n` (`n > 2999` and `n ≤ 12000`) indicates that the applicable value is equal to or less than n x 10 Pa and greater than (n-1) x 10 Pa, 
 - `12001` indicates that the values is greater than 120000 Pa,
 - `12002` indicates that the information is not available.

* **outOfRangelower** (2999)<br>
* **outOfRangeUpper** (12001)<br>
* **unavailable** (12002)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _10 Pascal_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Basic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
BarometricPressure ::= INTEGER{
	outOfRangelower        (2999),
	outOfRangeUpper        (12001),
	unavailable            (12002)
} (2999..12002)
```

### <a name="BogiesCount"></a>BogiesCount
This DE indicates the cardinal number of bogies of a train.

 The value shall be set to: 
 - `n` (`n > 1` and `n < 100`) indicates that the train has n x bogies,
 - `100`indicates that the number of bogies is out of range, 
 - `101` the information is unavailable.

* **outOfRange** (100)<br>
* **unavailable** (101)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _Number of bogies_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Vehicle information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
BogiesCount ::= INTEGER{
	outOfRange   (100),
	unavailable  (101)
} (2..101)
```

### <a name="CardinalNumber1B"></a>CardinalNumber1B
The DE represents a cardinal number that counts the size of a set.

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Basic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
CardinalNumber1B ::= INTEGER(0..255)
```

### <a name="CardinalNumber3b"></a>CardinalNumber3b
The DE represents a cardinal number that counts the size of a set.

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Basic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
CardinalNumber3b ::= INTEGER(1..8)
```

### <a name="CartesianAngleValue"></a>CartesianAngleValue
This DE represents an angle value described in a local Cartesian coordinate system, per default counted positive in
 a right-hand local coordinate system from the abscissa.

 The value shall be set to: 
 - `n` (`n ≥ 0` and `n < 3600`) if the angle is equal to or less than n x 0,1 degrees, and greater than (n-1) x 0,1 degrees,
 - `36001` if the accuracy information is not available.

 The value 3600 shall not be used.

* **valueNotUsed** (3600)<br>
* **unavailable** (3601)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _0,1 degrees_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Basic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
CartesianAngleValue ::= INTEGER {
    valueNotUsed (3600),
    unavailable  (3601)
} (0..3601)
```

### <a name="CartesianAngularAccelerationComponentValue"></a>CartesianAngularAccelerationComponentValue
This DE represents an angular acceleration value described in a local Cartesian coordinate system, per default counted positive in
 a right-hand local coordinate system from the abscissa.

 The value shall be set to: 
 - `-255` if the acceleration is equal to or less than -255 degrees/s<sup>2</sup>,
 - `n` (`n > -255` and `n < 255`) if the acceleration is equal to or less than n x 1 degree/s<sup>2</sup>,
      and greater than `(n-1)` x 0,01 degree/s<sup>2</sup>,
 - `255` if the acceleration is greater than 254 degrees/s<sup>2</sup>,
 - `256` if the information is unavailable.

* **negativeOutOfRange** (-255)<br>
* **positiveOutOfRange** (255)<br>
* **unavailable** (256)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _degree/s<sup>2</sup> (degrees per second squared)_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Kinematic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
CartesianAngularAccelerationComponentValue ::= INTEGER {
    negativeOutOfRange (-255),
    positiveOutOfRange (255),
    unavailable        (256)
} (-255..256)
```

### <a name="CartesianAngularVelocityComponentValue"></a>CartesianAngularVelocityComponentValue
This DE represents an angular velocity component described in a local Cartesian coordinate system, per default counted positive in
 a right-hand local coordinate system from the abscissa.

 The value shall be set to: 
 - `-255` if the velocity is equal to or less than -255 degrees/s,
 - `n` (`n > -255` and `n < 255`) if the velocity is equal to or less than n x 1 degree/s, and greater than (n-1) x 1 degree/s,
 - `255` if the velocity is greater than 254 degrees/s,
 - `256` if the information is unavailable.

* **negativeOutofRange** (-255)<br>
* **positiveOutOfRange** (255)<br>
* **unavailable** (256)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _degree/s_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Kinematic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
CartesianAngularVelocityComponentValue ::= INTEGER {
    negativeOutofRange (-255),
    positiveOutOfRange (255),
    unavailable	       (256)
} (-255..256)
```

### <a name="CauseCodeType"></a>CauseCodeType
The DE represents the value of the cause code of an event. 
 
 The value shall be set to:
 - 0                                                     - reserved for future use,
 - 1  - `trafficCondition`                               - in case the type of event is an abnormal traffic condition,
 - 2  - `accident`                                       - in case the type of event is a road accident,
 - 3  - `roadworks`                                      - in case the type of event is roadwork,
 - 4                                                     - reserved for future usage,
 - 5  - `impassability`                                  - in case the  type of event is unmanaged road blocking, referring to any
                                                           blocking of a road, partial or total, which has not been adequately
                                                           secured and signposted,
 - 6  - `adverseWeatherCondition-Adhesion`               - in case the  type of event is low adhesion,
 - 7  - `aquaplaning`                                    - danger of aquaplaning on the road,
 - 8                                                     - reserved for future usage,
 - 9  - `hazardousLocation-SurfaceCondition`             - in case the type of event is abnormal road surface condition,
 - 10 - `hazardousLocation-ObstacleOnTheRoad`            - in case the type of event is obstacle on the road,
 - 11 - `hazardousLocation-AnimalOnTheRoad`              - in case the type of event is animal on the road,
 - 12 - `humanPresenceOnTheRoad`                         - in case the type of event is human presence on the road,
 - 13                                                    - reserved for future usage,
 - 14 - `wrongWayDriving`                                - in case the type of the event is vehicle driving in wrong way,
 - 15 - `rescueAndRecoveryWorkInProgress`                - in case the type of event is rescue and recovery work for accident or for a road hazard in progress,
 - 16                                                    - reserved for future usage,
 - 17 - `adverseWeatherCondition-ExtremeWeatherCondition`- in case the type of event is extreme weather condition,
 - 18 - `adverseWeatherCondition-Visibility`             - in case the type of event is low visibility,
 - 19 - `adverseWeatherCondition-Precipitation`          - in case the type of event is precipitation,
 - 20 - `violence`                                       - in case the the type of event is human violence on or near the road,
 - 21-25                                                 - reserved for future usage,
 - 26 - `slowVehicle`                                    - in case the type of event is slow vehicle driving on the road,
 - 27 - `dangerousEndOfQueue`                            - in case the type of event is dangerous end of vehicle queue,
 - 28-90                                                 - are reserved for future usage,
 - 91 - `vehicleBreakdown`                               - in case the type of event is break down vehicle on the road,
 - 92 - `postCrash`                                      - in case the type of event is a detected crash,
 - 93 - `humanProblem`                                   - in case the type of event is human health problem in vehicles involved in traffic,
 - 94 - `stationaryVehicle`                              - in case the type of event is stationary vehicle,
 - 95 - `emergencyVehicleApproaching`                    - in case the type of event is approaching vehicle operating emergency mission,
 - 96 - `hazardousLocation-DangerousCurve`               - in case the type of event is dangerous curve,
 - 97 - `collisionRisk`                                  - in case the type of event is a collision risk,
 - 98 - `signalViolation`                                - in case the type of event is signal violation,
 - 99 - `dangerousSituation`                             - in case the type of event is dangerous situation in which autonomous safety system in vehicle 
                                                             is activated,
 - 100 - `railwayLevelCrossing`                          - in case the type of event is a railway level crossing. 
 - 101-255                                               - are reserved for future usage.

* **trafficCondition** (1)<br>
* **accident** (2)<br>
* **roadworks** (3)<br>
* **impassability** (5)<br>
* **adverseWeatherCondition-Adhesion** (6)<br>
* **aquaplaning** (7)<br>
* **hazardousLocation-SurfaceCondition** (9)<br>
* **hazardousLocation-ObstacleOnTheRoad** (10)<br>
* **hazardousLocation-AnimalOnTheRoad** (11)<br>
* **humanPresenceOnTheRoad** (12)<br>
* **wrongWayDriving** (14)<br>
* **rescueAndRecoveryWorkInProgress** (15)<br>
* **adverseWeatherCondition-ExtremeWeatherCondition** (17)<br>
* **adverseWeatherCondition-Visibility** (18)<br>
* **adverseWeatherCondition-Precipitation** (19)<br>
* **violence** (20)<br>
* **slowVehicle** (26)<br>
* **dangerousEndOfQueue** (27)<br>
* **vehicleBreakdown** (91)<br>
* **postCrash** (92)<br>
* **humanProblem** (93)<br>
* **stationaryVehicle** (94)<br>
* **emergencyVehicleApproaching** (95)<br>
* **hazardousLocation-DangerousCurve** (96)<br>
* **collisionRisk** (97)<br>
* **signalViolation** (98)<br>
* **dangerousSituation** (99)<br>
* **railwayLevelCrossing** (100)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Traffic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V1.3.1_
```asn1
CauseCodeType ::= INTEGER {
    trafficCondition                                (1),
    accident                                        (2),
    roadworks                                       (3),
    impassability                                   (5),
    adverseWeatherCondition-Adhesion                (6),
    aquaplaning                                     (7),
    hazardousLocation-SurfaceCondition              (9),
    hazardousLocation-ObstacleOnTheRoad             (10),
    hazardousLocation-AnimalOnTheRoad               (11),
    humanPresenceOnTheRoad                          (12),
    wrongWayDriving                                 (14),
    rescueAndRecoveryWorkInProgress                 (15),
    adverseWeatherCondition-ExtremeWeatherCondition (17),
    adverseWeatherCondition-Visibility              (18),
    adverseWeatherCondition-Precipitation           (19),
    violence                                        (20),
    slowVehicle                                     (26),
    dangerousEndOfQueue                             (27),
    vehicleBreakdown                                (91),
    postCrash                                       (92),
    humanProblem                                    (93),
    stationaryVehicle                               (94),
    emergencyVehicleApproaching                     (95),
    hazardousLocation-DangerousCurve                (96),
    collisionRisk                                   (97),
    signalViolation                                 (98),
    dangerousSituation                              (99),
    railwayLevelCrossing                            (100) 
} (0..255)
```

### <a name="CartesianCoordinateSmall"></a>CartesianCoordinateSmall
This DF represents the value of a cartesian coordinate with a range of -30,94 metres to +10,00 metres.

 The value shall be set to:
 - `3094` if the longitudinal offset is out of range, i.e. less than or equal to -30,94 metres,
 - `n` (`n > -3 094` and `n < 1 001`) if the longitudinal offset information is equal to or less than n x 0,01 metre and more than (n-1) x 0,01 metre,
 - `1001` if the longitudinal offset is out of range, i.e. greater than 10 metres.

* **negativeOutOfRange** (-3094)<br>
* **positiveOutOfRange** (1001)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _0,01 m_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Basic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
CartesianCoordinateSmall::= INTEGER {
    negativeOutOfRange (-3094),
    positiveOutOfRange (1001)
} (-3094..1001)
```

### <a name="CartesianCoordinate"></a>CartesianCoordinate
This DF represents the value of a cartesian coordinate with a range of -327,68 metres to +327,66 metres.

 The value shall be set to:
 - `-32 768` if the longitudinal offset is out of range, i.e. less than or equal to -327,68 metres,
 - `n` (`n > -32 768` and `n < 32 767`) if the longitudinal offset information is equal to or less than n x 0,01 metre and more than (n-1) x 0,01 metre,
 - `32 767` if the longitudinal offset is out of range, i.e. greater than + 327,66 metres.

* **negativeOutOfRange** (-32768)<br>
* **positiveOutOfRange** (32767)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _0,01 m_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Basic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
CartesianCoordinate::= INTEGER{
    negativeOutOfRange (-32768),
    positiveOutOfRange (32767)
} (-32768..32767)
```

### <a name="CartesianCoordinateLarge"></a>CartesianCoordinateLarge
This DF represents the value of a cartesian coordinate with a range of -1 310,72 metres to +1 310,70 metres.

 The value shall be set to:
 - `-131072` if the longitudinal offset is out of range, i.e. less than or equal to -1 310,72 metres,
 - `n` (`n > 131 072` and `n < 131 071`) if the longitudinal offset information is equal to or less than n x 0,01 metre and more than (n-1) x 0,01 metre,
 - `131 071` if the longitudinal offset is out of range, i.e. greater than + 1 310,70 metres.

* **negativeOutOfRange** (-131072)<br>
* **positiveOutOfRange** (131071)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _0,01 m_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Basic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
CartesianCoordinateLarge::= INTEGER{ 
    negativeOutOfRange (-131072),
    positiveOutOfRange (131071)
} (-131072..131071)
```

### <a name="CenDsrcTollingZoneID"></a>CenDsrcTollingZoneID
This DE represents the ID of a CEN DSRC tolling zone.

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Communication information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V1.3.1_

>>>
NOTE:&emsp;this DE is deprecated and shall not be used anymore.
>>>
```asn1
CenDsrcTollingZoneID::= ProtectedZoneId
```

### <a name="ClusterBreakupReason"></a>ClusterBreakupReason
This DE indicates the reason why a cluster leader intends to break up the cluster.
 
 The value shall be set to:
 - 0 - `notProvided`                          - if the information is not provided,
 - 1 - `clusteringPurposeCompleted`           - if the cluster purpose has been completed,
 - 2 - `leaderMovedOutOfClusterBoundingBox`   - if the leader moved out of the cluster's bounding box,
 - 3 - `joiningAnotherCluster`                - if the cluster leader is about to join another cluster,
 - 4 - `enteringLowRiskAreaBasedOnMaps`       - if the cluster is entering an area idenrified as low risk based on the use of maps,
 - 5 - `receptionOfCpmContainingCluster`      - if the leader received a Collective Perception Message containing information about the same cluster. 
 - 6 to 15                                    - are reserved for future use.

* **notProvided** (0)<br>
* **clusteringPurposeCompleted** (1)<br>
* **leaderMovedOutOfClusterBoundingBox** (2)<br>
* **joiningAnotherCluster** (3)<br>
* **enteringLowRiskAreaBasedOnMaps** (4)<br>
* **receptionOfCpmContainingCluster** (5)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Cluster information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
ClusterBreakupReason ::= ENUMERATED {
    notProvided                        (0),
    clusteringPurposeCompleted         (1),
    leaderMovedOutOfClusterBoundingBox (2),    
    joiningAnotherCluster              (3),
    enteringLowRiskAreaBasedOnMaps     (4),
    receptionOfCpmContainingCluster    (5),
    max(15)                                                                 
}
```

### <a name="ClusterLeaveReason"></a>ClusterLeaveReason
This DE indicates the reason why a cluster participant is leaving the cluster.
 
 The value shall be set to:
 - 0 - `notProvided `                 - if the information is not provided,
 - 1 - `clusterLeaderLost`            - if the cluster leader cannot be found anymore,   
 - 2 - `clusterDisbandedByLeader`     - if the cluster has been disbanded by the leader,
 - 3 - `outOfClusterBoundingBox`      - if the participants moved out of the cluster's bounding box,
 - 4 - `outOfClusterSpeedRange`       - if the cluster speed moved out of a defined range, 
 - 5 - `joiningAnotherCluster`        - if the participant is joining another cluster,
 - 6 - `cancelledJoin`                - if the participant is cancelling a joining procedure,
 - 7 - `failedJoin`                   - if the participant failed to join the cluster,
 - 8 - `safetyCondition`              - if a safety condition applies.
 - 9 to 15                            - are reserved for future use

* **notProvided** (0)<br>
* **clusterLeaderLost** (1)<br>
* **clusterDisbandedByLeader** (2)<br>
* **outOfClusterBoundingBox** (3)<br>
* **outOfClusterSpeedRange** (4)<br>
* **joiningAnotherCluster** (5)<br>
* **cancelledJoin** (6)<br>
* **failedJoin** (7)<br>
* **safetyCondition** (8)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Cluster information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
ClusterLeaveReason ::= ENUMERATED {
    notProvided                   (0), 
    clusterLeaderLost             (1),    
    clusterDisbandedByLeader      (2),    
    outOfClusterBoundingBox       (3),    
    outOfClusterSpeedRange        (4),
    joiningAnotherCluster         (5),
    cancelledJoin                 (6),
    failedJoin                    (7),
    safetyCondition               (8),
    max(15)            
}
```

### <a name="CollisionRiskSubCauseCode"></a>CollisionRiskSubCauseCode
This DE represents the sub cause codes of the [**CauseCode**](#CauseCode) `collisionRisk`.
 
 The value shall be set to:
 - 0 - `unavailable`              - in case information on the type of collision risk is unavailable,
 - 1 - `longitudinalCollisionRisk`- in case the type of detected collision risk is longitudinal collision risk, 
                                       e.g. forward collision or face to face collision,
 - 2 - `crossingCollisionRisk`    - in case the type of detected collision risk is crossing collision risk,
 - 3 - `lateralCollisionRisk`     - in case the type of detected collision risk is lateral collision risk,
 - 4 - `vulnerableRoadUser`       - in case the type of detected collision risk involves vulnerable road users
                                       e.g. pedestrians or bicycles.
 - 5-255                          - are reserved for future usage.

* **unavailable** (0)<br>
* **longitudinalCollisionRisk** (1)<br>
* **crossingCollisionRisk** (2)<br>
* **lateralCollisionRisk** (3)<br>
* **vulnerableRoadUser** (4)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Traffic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V1.3.1_
```asn1
CollisionRiskSubCauseCode ::= INTEGER {
    unavailable               (0), 
    longitudinalCollisionRisk (1), 
    crossingCollisionRisk     (2), 
    lateralCollisionRisk      (3), 
    vulnerableRoadUser        (4)
}(0..255)
```

### <a name="ConfidenceLevel"></a>ConfidenceLevel
This DE represents a confidence level in percentage.
 
 The value shall be set to:
 - `n` (`n > 0` and `n < 101`) : for the confidence level in %,
 - `101`                   : in case the confidence level is not available.

* **unavailable** (101)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _Percent_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Basic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
ConfidenceLevel ::= INTEGER {
    unavailable (101)  
} (1..101)
```

### <a name="CoordinateConfidence"></a>CoordinateConfidence
This DE indicates the coordinate confidence value which represents the estimated absolute accuracy of a position coordinate with a default confidence level of 95 %.
 If required, the confidence level can be defined by the corresponding standards applying this DE.

 The value shall be set to: 
 - `n` (`n > 0` and `n < 4095`) if the confidence value is is equal to or less than n x 0,01 metre, and greater than (n-1) x 0,01 metre,
 - `4095` if the confidence value is greater than 40,94 metres,
 - `4096` if the confidence value is not available.

* **outOfRange** (4095)<br>
* **unavailable** (4096)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _0,01 m_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Basic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
CoordinateConfidence ::= INTEGER {
    outOfRange            (4095),
    unavailable           (4096) 
} (1..4096)
```

### <a name="CorrelationCellValue"></a>CorrelationCellValue
This DE represents the Bravais-Pearson correlation value for each cell of a lower triangular correlation matrix.

 The value shall be set to: 
 - `-100` in case of full negative correlation,
 - `n` (`n > -100` and `n < 0`) if the correlation is negative and equal to n x 100,
 - `0` in case of no correlation,
 - `n` (`n > 0` and `n < 100`) if the correlation is positive and equal to n x 100,
 - `100` in case of full positive correlation,
 - `101` in case the correlation information is unavailable.

* **full-negative-correlation** (-100)<br>
* **no-correlation** (0)<br>
* **full-positive-correlation** (100)<br>
* **unavailable** (101)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _the value is scaled by 100_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Basic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
CorrelationCellValue ::= INTEGER {
    full-negative-correlation    (-100),     
    no-correlation               (0),       
    full-positive-correlation    (100),
    unavailable (101)  
} (-100..101)
```

### <a name="CurvatureCalculationMode"></a>CurvatureCalculationMode
The DE describes whether the yaw rate is used to calculate the curvature for a curvature value.
 
 The value shall be set to:
 - 0 - `yawRateUsed`    - if the yaw rate is used,
 - 1 - `yawRateNotUsed` - if the yaw rate is not used,
 - 2 - `unavailable`    - if the information of curvature calculation mode is unknown.

* **yawRateUsed** (0)<br>
* **yawRateNotUsed** (1)<br>
* **unavailable** (2)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Vehicle information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V1.3.1_
```asn1
CurvatureCalculationMode ::= ENUMERATED {
    yawRateUsed    (0), 
    yawRateNotUsed (1), 
    unavailable    (2), 
    ...
}
```

### <a name="CurvatureConfidence"></a>CurvatureConfidence
This DE indicates the acceleration confidence value which represents the estimated absolute accuracy range of a curvature value with a confidence level of 95 %.
 If required, the confidence level can be defined by the corresponding standards applying this DE.
 
 The value shall be set to:
 - 0 - `onePerMeter-0-00002` - if the confidence value is less than or equal to 0,00002 m-1,
 - 1 - `onePerMeter-0-0001`  - if the confidence value is less than or equal to 0,0001 m-1 and greater than 0,00002 m-1,
 - 2 - `onePerMeter-0-0005`  - if the confidence value is less than or equal to 0,0005 m-1 and greater than 0,0001 m-1,
 - 3 - `onePerMeter-0-002`   - if the confidence value is less than or equal to 0,002 m-1 and greater than 0,0005 m-1,
 - 4 - `nePerMeter-0-01`     - if the confidence value is less than or equal to 0,01 m-1 and greater than 0,002 m-1,
 - 5 - `nePerMeter-0-1`      - if the confidence value is less than or equal to 0,1 m-1  and greater than 0,01 m-1,
 - 6 - `outOfRange`          - if the confidence value is out of range, i.e. greater than 0,1 m-1,
 - 7 - `unavailable`         - if the confidence value is not available.

* **onePerMeter-0-00002** (0)<br>
* **onePerMeter-0-0001** (1)<br>
* **onePerMeter-0-0005** (2)<br>
* **onePerMeter-0-002** (3)<br>
* **onePerMeter-0-01** (4)<br>
* **onePerMeter-0-1** (5)<br>
* **outOfRange** (6)<br>
* **unavailable** (7)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Vehicle information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Description revised in V2.1.1_

>>>
NOTE:&emsp;If a curvature value is received and its confidence value is set to `outOfRange(6)`, it means that the curvature value is not valid 
 and therefore cannot be trusted. Such value is not useful for the application.
>>>
```asn1
CurvatureConfidence ::= ENUMERATED {
    onePerMeter-0-00002 (0),
    onePerMeter-0-0001  (1),
    onePerMeter-0-0005  (2),
    onePerMeter-0-002   (3),
    onePerMeter-0-01    (4),
    onePerMeter-0-1     (5),
    outOfRange          (6),
    unavailable         (7)
}
```

### <a name="CurvatureValue"></a>CurvatureValue
This DE describes vehicle turning curve with the following information:
 ```
     Value = 1 / Radius * 10000
 ```
 wherein radius is the vehicle turning curve radius in metres. 
 
 Positive values indicate a turning curve to the left hand side of the driver.
 It corresponds to the vehicle coordinate system as defined in ISO 8855 [[21]](#references).

 The value shall be set to:
 - `-1023` for  values smaller than -1023,
 - `n` (`n > -1023` and `n < 0`) for negative values equal to or less than `n`, and greater than `(n-1)`,
 - `0` when the vehicle is moving straight,
 - `n` (`n > 0` and `n < 1022`) for positive values equal to or less than `n`, and greater than `(n-1)`,
 - `1022`, for values  greater than 1021,
 - `1023`, if the information is not available.

* **outOfRangeNegative** (-1023)<br>
* **straight** (0)<br>
* **outOfRangePositive** (1022)<br>
* **unavailable** (1023)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _1 over 10 000 metres_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Vehicle information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _description revised in V2.1.1 (the definition of value 1022 has changed slightly)_

>>>
NOTE:&emsp;The present DE is limited to vehicle types as defined in ISO 8855 [[21]](#references).
>>>
```asn1
CurvatureValue ::= INTEGER {
    outOfRangeNegative (-1023),
    straight           (0),
    outOfRangePositive (1022), 
    unavailable        (1023)
} (-1023..1023)
```

### <a name="DangerousEndOfQueueSubCauseCode"></a>DangerousEndOfQueueSubCauseCode
This DE represents the value of the sub cause codes of the [**CauseCode**](#CauseCode) `dangerousEndOfQueue`. 
 
 The value shall be set to:
 - 0 - `unavailable`     - in case information on the type of dangerous queue is unavailable,
 - 1 - `suddenEndOfQueue`- in case a sudden end of queue is detected, e.g. due to accident or obstacle,
 - 2 - `queueOverHill`   - in case the dangerous end of queue is detected on the road hill,
 - 3 - `queueAroundBend` - in case the dangerous end of queue is detected around the road bend,
 - 4 - `queueInTunnel`   - in case queue is detected in tunnel,
 - 5-255                 - reserved for future usage.

* **unavailable** (0)<br>
* **suddenEndOfQueue** (1)<br>
* **queueOverHill** (2)<br>
* **queueAroundBend** (3)<br>
* **queueInTunnel** (4)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Traffic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V1.3.1_
```asn1
DangerousEndOfQueueSubCauseCode ::= INTEGER {
    unavailable      (0), 
    suddenEndOfQueue (1), 
    queueOverHill    (2), 
    queueAroundBend  (3), 
    queueInTunnel    (4)
} (0..255)
```

### <a name="DangerousGoodsBasic"></a>DangerousGoodsBasic
This DE indicates the type of the dangerous goods being carried by a heavy vehicle.
 The value is assigned according to `class` and `division` definitions of dangerous goods as specified in part II,
 chapter 2.1.1.1 of European Agreement concerning the International Carriage of Dangerous Goods by Road [[3]](#references).

* **explosives1** (0)<br>
* **explosives2** (1)<br>
* **explosives3** (2)<br>
* **explosives4** (3)<br>
* **explosives5** (4)<br>
* **explosives6** (5)<br>
* **flammableGases** (6)<br>
* **nonFlammableGases** (7)<br>
* **toxicGases** (8)<br>
* **flammableLiquids** (9)<br>
* **flammableSolids** (10)<br>
* **substancesLiableToSpontaneousCombustion** (11)<br>
* **substancesEmittingFlammableGasesUponContactWithWater** (12)<br>
* **oxidizingSubstances** (13)<br>
* **organicPeroxides** (14)<br>
* **toxicSubstances** (15)<br>
* **infectiousSubstances** (16)<br>
* **radioactiveMaterial** (17)<br>
* **corrosiveSubstances** (18)<br>
* **miscellaneousDangerousSubstances** (19)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Vehicle information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V1.3.1_
```asn1
DangerousGoodsBasic::= ENUMERATED {
    explosives1                                          (0),
    explosives2                                          (1),
    explosives3                                          (2),
    explosives4                                          (3),
    explosives5                                          (4),
    explosives6                                          (5),
    flammableGases                                       (6),
    nonFlammableGases                                    (7),
    toxicGases                                           (8),
    flammableLiquids                                     (9),
    flammableSolids                                      (10),
    substancesLiableToSpontaneousCombustion              (11),
    substancesEmittingFlammableGasesUponContactWithWater (12),
    oxidizingSubstances                                  (13),
    organicPeroxides                                     (14),
    toxicSubstances                                      (15),
    infectiousSubstances                                 (16),
    radioactiveMaterial                                  (17),
    corrosiveSubstances                                  (18),
    miscellaneousDangerousSubstances                     (19)
}
```

### <a name="DangerousSituationSubCauseCode"></a>DangerousSituationSubCauseCode
This DE represents the value of the sub cause codes of the [**CauseCode**](#CauseCode) `dangerousSituation` 
 
 The value shall be set to:
 - 0 - `unavailable`                      - in case information on the type of dangerous situation is unavailable,
 - 1 - `emergencyElectronicBrakeEngaged`  - in case emergency electronic brake is engaged,
 - 2 - `preCrashSystemEngaged`            - in case pre-crash system is engaged,
 - 3 - `espEngaged`                       - in case Electronic Stability Program (ESP) system is engaged,
 - 4 - `absEngaged`                       - in case Anti-lock Braking System (ABS) is engaged,
 - 5 - `aebEngaged`                       - in case Autonomous Emergency Braking (AEB) system is engaged,
 - 6 - `brakeWarningEngaged`              - in case brake warning is engaged,
 - 7 - `collisionRiskWarningEngaged`      - in case collision risk warning is engaged,
 - 8-255                                  - reserved for future usage.

* **unavailable** (0)<br>
* **emergencyElectronicBrakeEngaged** (1)<br>
* **preCrashSystemEngaged** (2)<br>
* **espEngaged** (3)<br>
* **absEngaged** (4)<br>
* **ebEngaged** (5)<br>
* **brakeWarningEngaged** (6)<br>
* **collisionRiskWarningEngaged** (7)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Traffic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V1.3.1_
```asn1
DangerousSituationSubCauseCode ::= INTEGER {
    unavailable                     (0), 
    emergencyElectronicBrakeEngaged (1), 
    preCrashSystemEngaged           (2), 
    espEngaged                      (3), 
    absEngaged                      (4), 
    ebEngaged                       (5), 
    brakeWarningEngaged             (6), 
    collisionRiskWarningEngaged     (7)
} (0..255)
```

### <a name="DeltaAltitude"></a>DeltaAltitude
This DE represents an offset altitude with regards to a defined altitude value.
 It may be used to describe a geographical point with regards to a specific reference geographical position.

 The value shall be set to:
 - `-12 700` for values equal to or lower than -127 metres,
 - `n` (`n > -12 700` and `n ≤ 0`) for altitude offset n x 0,01 metre below the reference position,
 - `0` for no altitudinal offset,
 - `n` (`n > 0` and `n < 12799`) for altitude offset n x 0,01 metre above the reference position,
 - `12 799` for values equal to or greater than 127,99 metres,
 - `12 800` when the information is unavailable.

* **negativeOutOfRange** (-12700)<br>
* **positiveOutOfRange** (12799)<br>
* **unavailable** (12800)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _0,01 metre_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** GeoReference information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _editorial update in V2.1.1_
```asn1
DeltaAltitude ::= INTEGER {
    negativeOutOfRange (-12700),
    positiveOutOfRange (12799),
    unavailable        (12800)
} (-12700..12800)
```

### <a name="DeltaLatitude"></a>DeltaLatitude
This DE represents an offset latitude with regards to a defined latitude value.
 It may be used to describe a geographical point with regards to a specific reference geographical position.

 The value shall be set to:
 - `n` (`n ≥ -131 071` and `n < 0`) for offset n x 10<sup>-7</sup> degree towards the south from the reference position,
 - `0` for no latitudinal offset,
 - `n` (`n > 0` and `n < 131 072`) for offset n x 10<sup>-7</sup> degree towards the north from the reference position,
 - `131 072` when the information is unavailable.

* **unavailable** (131072)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _10<sup>-7</sup> degree_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** GeoReference information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _editorial update in V2.1.1_
```asn1
DeltaLatitude ::= INTEGER {
    unavailable (131072)
} (-131071..131072)
```

### <a name="DeltaLongitude"></a>DeltaLongitude
This DE represents an offset longitude with regards to a defined longitude value.
 It may be used to describe a geographical point with regards to a specific reference geographical position.

 The value shall be set to:
 - `n` (`n ≥ -131 071` and `n < 0`) for offset n x 10<sup>-7</sup> degree towards the west from the reference position,
 - `0` for no longitudinal offset,
 - `n` (`n > 0` and `n < 131 072`) for offset n x 10<sup>-7</sup> degree towards the east from the reference position, 
 - `131 072` when the information is unavailable.

* **unavailable** (131072)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _10<sup>-7</sup> degree_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** GeoReference information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _editorial update in V2.1.1_
```asn1
DeltaLongitude ::= INTEGER {
    unavailable (131072)
} (-131071..131072)
```

### <a name="DeltaTimeMilliSecondPositive"></a>DeltaTimeMilliSecondPositive
This DE represents a difference in time with respect to a reference time.

 The value shall be set to:
 - `n` (`n > 0` and `n < 10001`) to indicate a time value equal to or less than n x 0,001 s, and greater than (n-1) x 0,001 s,

 Example: a time interval between two consecutive message transmissions.

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _0,001 s_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Basic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1 from the DE TransmissionInterval in [[2]](#references)_
```asn1
DeltaTimeMilliSecondPositive ::= INTEGER (1..10000)
```

### <a name="DeltaTimeMilliSecondSigned"></a>DeltaTimeMilliSecondSigned
This DE represents a signed difference in time with respect to a reference time.

 The value shall be set to:
 - `-2048` for time values equal to or less than -2,048 s,
 - `n` (`n > -2048` and `n < 2047`) to indicate a time value equal to or less than n x 0,001 s, and greater than (n-1) x 0,001 s,
 - `2047` for time values greater than 2,046 s

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _0,001 s_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Basic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
DeltaTimeMilliSecondSigned ::= INTEGER (-2048..2047)
```

### <a name="DeltaTimeQuarterSecond"></a>DeltaTimeQuarterSecond
This DE represents a difference in time with respect to a reference time.
 It can be interpreted as the first 8 bits of a GenerationDeltaTime. To convert it to a [**GenerationDeltaTime**](ETSI-ITS-CDD.md#GenerationDeltaTime), 
 multiply by 256 (i.e. append a `00` byte)

* **unavailable** (255)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _256 * 0,001 s_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Basic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
DeltaTimeQuarterSecond::= INTEGER {
    unavailable (255)  
} (1..255)
```

### <a name="DeltaTimeTenthOfSecond"></a>DeltaTimeTenthOfSecond
This DE represents a difference in time with respect to a reference time.

 The value shall be set to:
 - `0` for a difference in time of 0 seconds. 
 - `n` (`n > 0` and `n < 128`) to indicate a time value equal to or less than n x 0,1 s, and greater than (n-1) x 0,1 s,

* **unavailable** (127)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _0,1 s_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Basic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
DeltaTimeTenthOfSecond::= INTEGER {
    unavailable (127)  
} (0..127)
```

### <a name="DeltaTimeSecond"></a>DeltaTimeSecond
This DE represents a  difference in time with respect to a reference time.

 The value shall be set to:
 - `-0` for a difference in time of 0 seconds. 
 - `n` (`n > 0` and `n ≤ 86400`) to indicate a time value equal to or less than n x 1 s, and greater than (n-1) x 1 s,

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _1 s_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Basic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1 from ValidityDuration_
```asn1
DeltaTimeSecond ::= INTEGER  (0..86400)
```

### <a name="Direction"></a>Direction
This DE indicates a direction with respect to a defined reference direction.
 Example: a reference direction may be implicitly defined by the definition of a geographical zone.

 The value shall be set to:
 - 0 - `sameDirection`     - to indicate the same direction as the reference direction,
 - 1 - `oppositeDirection` - to indicate opposite direction as the reference direction,
 - 2 - `bothDirections`    - to indicate both directions, i.e. the same and the opposite direction,
 - 3 - `unavailable`       - to indicate that the information is unavailable.

* **sameDirection** (0)<br>
* **oppositeDirection** (1)<br>
* **bothDirections** (2)<br>
* **unavailable** (3)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** GeoReference information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
Direction::= INTEGER{
    sameDirection     (0),
    oppositeDirection (1),
    bothDirections    (2),
    unavailable       (3)
 } (0..3)
```

### <a name="DriveDirection"></a>DriveDirection
This DE indicates in which direction something is moving.

 The value shall be set to:
 - 0 - `forward`     - to indicate it is moving forward,
 - 1 - `backwards`   - to indicate it is moving backwards,
 - 2 - `unavailable` - to indicate that the information is unavailable.

* **forward** (0)<br>
* **backward** (1)<br>
* **unavailable** (2)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Kinematic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _editorial update in V2.1.1_
```asn1
DriveDirection ::= ENUMERATED {
    forward     (0), 
    backward    (1), 
    unavailable (2)
}
```

### <a name="DrivingLaneStatus"></a>DrivingLaneStatus
This DE indicates whether a driving lane is open to traffic.
 
 A lane is counted from inside border of the road excluding the hard shoulder. The size of the bit string shall
 correspond to the total number of the driving lanes in the carriageway.
 
 The numbering is matched to [**LanePosition**](ETSI-ITS-CDD.md#LanePosition).
 The bit `0` is used to indicate the innermost lane, bit `1` is used to indicate the second lane from inside border.
 
 If a lane is closed to traffic, the corresponding bit shall be set to `1`. Otherwise, it shall be set to `0`.

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Traffic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V1.3.1_

>>>
NOTE:&emsp;hard shoulder status is not provided by this DE but in [**HardShoulderStatus**](#HardShoulderStatus).
>>>
```asn1
DrivingLaneStatus ::= BIT STRING (SIZE (1..13))
```

### <a name="EmbarkationStatus"></a>EmbarkationStatus
This DE indicates whether a vehicle (e.g. public transport vehicle, truck) is under the embarkation process.
 If that is the case, the value is *TRUE*, otherwise *FALSE*.

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Vehicle information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _editorial update in V2.1.1_
```asn1
EmbarkationStatus ::= BOOLEAN
```

### <a name="EmergencyPriority"></a>EmergencyPriority
This DE indicates the right of priority requested or assumed by an operating emergency vehicle.
 The right-of-priority bit shall be set to `1` if the corresponding right is requested.
 
 The corresponding bit shall be set to 1 under the following conditions:
 - 0 - `requestForRightOfWay`                  - when the vehicle is requesting/assuming the right of way,
 - 1 - `requestForFreeCrossingAtATrafficLight` - when the vehicle is requesting/assuming the right to pass at a (red) traffic light.

* **requestForRightOfWay** (0)<br>
* **requestForFreeCrossingAtATrafficLight** (1)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Traffic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _description revised in V2.1.1_
```asn1
EmergencyPriority ::= BIT STRING {
    requestForRightOfWay                  (0), 
    requestForFreeCrossingAtATrafficLight (1)
} (SIZE(2))
```

### <a name="EmergencyVehicleApproachingSubCauseCode"></a>EmergencyVehicleApproachingSubCauseCode
This DE represents the value of the sub cause codes of the [**CauseCode**](#CauseCode) "emergencyVehicleApproaching". 
 
 The value shall be set to:
 - 0 - `unavailable`                   - in case further detailed information on the emergency vehicle approaching event 
                                         is unavailable,
 - 1 - `emergencyVehicleApproaching`   - in case an operating emergency vehicle is approaching,
 - 2 - `prioritizedVehicleApproaching` - in case a prioritized vehicle is approaching,
 - 3-255                               - reserved for future usage.

* **unavailable** (0)<br>
* **emergencyVehicleApproaching** (1)<br>
* **prioritizedVehicleApproaching** (2)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Traffic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V1.3.1_
```asn1
EmergencyVehicleApproachingSubCauseCode ::= INTEGER {
    unavailable                   (0), 
    emergencyVehicleApproaching   (1), 
    prioritizedVehicleApproaching (2)
} (0..255)
```

### <a name="EnergyStorageType"></a>EnergyStorageType
This DE indicated the type of energy being used and stored in vehicle.

 The corresponding bit shall be set to 1 under the following conditions:
 - 0 - `hydrogenStorage`       - when hydrogen is being used and stored in vehicle,
 - 1 - `electricEnergyStorage` - when electric energy is being used and stored in vehicle,
 - 2 - `liquidPropaneGas`      - when liquid Propane Gas (LPG) is being used and stored in vehicle,   
 - 3 - `compressedNaturalGas ` - when compressedNaturalGas (CNG) is being used and stored in vehicle,
 - 4 - `diesel`                - when diesel is being used and stored in vehicle,
 - 5 - `gasoline`              - when gasoline is being used and stored in vehicle,
 - 6 - `ammonia`               - when ammonia is being used and stored in vehicle.

 - Otherwise, the corresponding bit shall be set to `0`.

* **hydrogenStorage** (0)<br>
* **electricEnergyStorage** (1)<br>
* **liquidPropaneGas** (2)<br>
* **compressedNaturalGas** (3)<br>
* **diesel** (4)<br>
* **gasoline** (5)<br>
* **ammonia** (6)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Vehicle information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _editorial revision in V2.1.1_
```asn1
EnergyStorageType ::= BIT STRING {
    hydrogenStorage       (0), 
    electricEnergyStorage (1), 
    liquidPropaneGas      (2), 
    compressedNaturalGas  (3), 
    diesel                (4), 
    gasoline              (5), 
    ammonia               (6)
}(SIZE(7))
```

### <a name="EuVehicleCategoryL"></a>EuVehicleCategoryL
This DE represents one of the specific categories in the L category: L1, L2, L3, L4, L5, L6, or L7 according to UNECE/TRANS/WP.29/78/Rev.4 [[16]](#references).

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Vehicle information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V2.1.1_
```asn1
EuVehicleCategoryL ::= ENUMERATED { l1, l2, l3, l4, l5, l6, l7 }
```

### <a name="EuVehicleCategoryM"></a>EuVehicleCategoryM
This DE represents one of the specific categories in the M category: M1, M2, or M3 according to UNECE/TRANS/WP.29/78/Rev.4 [[16]](#references).

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Vehicle information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V2.1.1_
```asn1
EuVehicleCategoryM ::= ENUMERATED {m1, m2, m3}
```

### <a name="EuVehicleCategoryN"></a>EuVehicleCategoryN
This DE represents one of the specific categories in the N category: N1, N2, or N3 according to UNECE/TRANS/WP.29/78/Rev.4 [[16]](#references).

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Vehicle information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V2.1.1_
```asn1
EuVehicleCategoryN ::= ENUMERATED {n1, n2, n3}
```

### <a name="EuVehicleCategoryO"></a>EuVehicleCategoryO
This DE represents one of the specific categories in the O category: O1, O2, O3 or O4 according to UNECE/TRANS/WP.29/78/Rev.4 [[16]](#references).

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Vehicle information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V2.1.1_
```asn1
EuVehicleCategoryO ::= ENUMERATED {o1, o2, o3, o4}
```

### <a name="ExteriorLights"></a>ExteriorLights
This DE describes the status of the exterior light switches of a vehicle incl. VRU vehicles.

 The corresponding bit shall be set to 1 under the following conditions:
 - 0 - `lowBeamHeadlightsOn`    - when the low beam head light switch is on,
 - 1 - `highBeamHeadlightsOn`   - when the high beam head light switch is on,
 - 2 - `leftTurnSignalOn`       - when the left turnSignal switch is on,
 - 3 - `rightTurnSignalOn`      - when the right turn signal switch is on,
 - 4 - `daytimeRunningLightsOn` - when the daytime running light switch is on,
 - 5 - `reverseLightOn`         - when the reverse light switch is on,
 - 6 - `fogLightOn`             - when the tail fog light switch is on,
 - 7 - `parkingLightsOn`        - when the parking light switch is on.

 
 If a vehicle is not equipped with a certain light or if the light switch status information is not available,
 the corresponding bit shall be set to `0`.
 
 As the bit value indicates only the state of the switch, the turn signal and hazard signal bit values shall not
 alternate with the blinking interval.
 
 For hazard indicator, the `leftTurnSignalOn (2)` and `rightTurnSignalOn (3)` shall be both set to `1`.

* **lowBeamHeadlightsOn** (0)<br>
* **highBeamHeadlightsOn** (1)<br>
* **leftTurnSignalOn** (2)<br>
* **rightTurnSignalOn** (3)<br>
* **daytimeRunningLightsOn** (4)<br>
* **reverseLightOn** (5)<br>
* **fogLightOn** (6)<br>
* **parkingLightsOn** (7)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Vehicle information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Description revised in V2.1.1_

>>>
NOTE:&emsp;The value of each bit indicates the state of the switch, which commands the corresponding light.
 The bit corresponding to a specific light is set to `1`, when the corresponding switch is turned on,
 either manually by the driver or automatically by a vehicle system. The bit value does not indicate
 if the corresponding lamps are alight or not.
>>>
```asn1
ExteriorLights ::= BIT STRING {
    lowBeamHeadlightsOn      (0),
    highBeamHeadlightsOn     (1),
    leftTurnSignalOn         (2),
    rightTurnSignalOn        (3),
    daytimeRunningLightsOn   (4),
    reverseLightOn           (5),
    fogLightOn               (6),
    parkingLightsOn          (7)
} (SIZE(8))
```

### <a name="GenerationDeltaTime"></a>GenerationDeltaTime
This DE represents a timestamp based on TimestampIts modulo 65 536.
 This means that generationDeltaTime = TimestampIts mod 65 536.

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Basic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1 based on ETSI TS 103 900 [[1]](#references)_
```asn1
GenerationDeltaTime ::= INTEGER { oneMilliSec(1) } (0..65535)
```

### <a name="HardShoulderStatus"></a>HardShoulderStatus
This DE indicates the current status of a hard shoulder: whether it is available for special usage
 (e.g. for stopping or for driving) or closed for all vehicles.
 
 The value shall be set to:
 - 0 - `availableForStopping` - if the hard shoulder is available for stopping in e.g. emergency situations,
 - 1 - `closed`               - if the hard shoulder is closed and cannot be occupied in any case,
 - 2 - `availableForDriving`  - if the hard shoulder is available for regular driving.

* **availableForStopping** (0)<br>
* **closed** (1)<br>
* **availableForDriving** (2)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Traffic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Description revised in V2.1.1_
```asn1
HardShoulderStatus ::= ENUMERATED {
    availableForStopping (0), 
    closed               (1), 
    availableForDriving  (2)
}
```

### <a name="HazardousLocation-AnimalOnTheRoadSubCauseCode"></a>HazardousLocation-AnimalOnTheRoadSubCauseCode
This DE represents the value of the sub cause code of the [**CauseCode**](#CauseCode) `hazardousLocation-AnimalOnTheRoad`.
 
 The value shall be set to:
 - 0 - `unavailable`  - in case further detailed information on the animal on the road event is unavailable,
 - 1 - `wildAnimals`  - in case wild animals are detected on the road,
 - 2 - `herdOfAnimals`- in case herd of animals are detected on the road,
 - 3 - `smallAnimals` - in case small size animals are detected on the road,
 - 4 - `largeAnimals` - in case large size animals are detected on the road.
 - 5-255              - are reserved for future usage.

* **unavailable** (0)<br>
* **wildAnimals** (1)<br>
* **herdOfAnimals** (2)<br>
* **smallAnimals** (3)<br>
* **largeAnimals** (4)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Traffic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V1.3.1_
```asn1
HazardousLocation-AnimalOnTheRoadSubCauseCode ::= INTEGER {
    unavailable   (0), 
    wildAnimals   (1), 
    herdOfAnimals (2), 
    smallAnimals  (3), 
    largeAnimals  (4)
} (0..255)
```

### <a name="HazardousLocation-DangerousCurveSubCauseCode"></a>HazardousLocation-DangerousCurveSubCauseCode
This DE represents the sub cause code of the [**CauseCode**](#CauseCode)  `hazardousLocation-DangerousCurve`.
 
 The value shall be set to:
 - 0 - `unavailable`                                        - in case further detailed information on the dangerous curve is unavailable,
 - 1 - `dangerousLeftTurnCurve`                             - in case the dangerous curve is a left turn curve,
 - 2 - `dangerousRightTurnCurve`                            - in case the dangerous curve is a right turn curve,
 - 3 - `multipleCurvesStartingWithUnknownTurningDirection`  - in case of multiple curves for which the starting curve turning direction is not known,
 - 4 - `multipleCurvesStartingWithLeftTurn`                 - in case of multiple curves starting with a left turn curve,
 - 5 - `multipleCurvesStartingWithRightTurn`                - in case of multiple curves starting with a right turn curve.
 - 6-255                                                    - are reserved for future usage.
 
 The definition of whether a curve is dangerous may vary according to region and according to vehicle types/mass
 and vehicle speed driving on the curve. This definition is out of scope of the present document.

* **unavailable** (0)<br>
* **dangerousLeftTurnCurve** (1)<br>
* **dangerousRightTurnCurve** (2)<br>
* **multipleCurvesStartingWithUnknownTurningDirection** (3)<br>
* **multipleCurvesStartingWithLeftTurn** (4)<br>
* **multipleCurvesStartingWithRightTurn** (5)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Traffic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V1.3.1_
```asn1
HazardousLocation-DangerousCurveSubCauseCode ::= INTEGER {
    unavailable                                       (0), 
    dangerousLeftTurnCurve                            (1), 
    dangerousRightTurnCurve                           (2), 
    multipleCurvesStartingWithUnknownTurningDirection (3), 
    multipleCurvesStartingWithLeftTurn                (4), 
    multipleCurvesStartingWithRightTurn               (5)
} (0..255)
```

### <a name="HazardousLocation-ObstacleOnTheRoadSubCauseCode"></a>HazardousLocation-ObstacleOnTheRoadSubCauseCode
This DE represents the value of the sub cause code of the [**CauseCode**](#CauseCode) `hazardousLocation-ObstacleOnTheRoad`. 
 
 The value shall be set to:
 - 0 - `unavailable`    - in case further detailed information on the detected obstacle is unavailable,
 - 1 - `shedLoad`       - in case detected obstacle is large amount of obstacles (shedload),
 - 2 - `partsOfVehicles`- in case detected obstacles are parts of vehicles,
 - 3 - `partsOfTyres`   - in case the detected obstacles are parts of tyres,
 - 4 - `bigObjects`     - in case the detected obstacles are big objects,
 - 5 - `fallenTrees`    - in case the detected obstacles are fallen trees,
 - 6 - `hubCaps`        - in case the detected obstacles are hub caps,
 - 7 - `waitingVehicles`- in case the detected obstacles are waiting vehicles.
 - 8-255                - are reserved for future usage.

* **unavailable** (0)<br>
* **shedLoad** (1)<br>
* **partsOfVehicles** (2)<br>
* **partsOfTyres** (3)<br>
* **bigObjects** (4)<br>
* **fallenTrees** (5)<br>
* **hubCaps** (6)<br>
* **waitingVehicles** (7)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Traffic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V1.3.1_
```asn1
HazardousLocation-ObstacleOnTheRoadSubCauseCode ::= INTEGER {
    unavailable     (0), 
    shedLoad        (1), 
    partsOfVehicles (2), 
    partsOfTyres    (3), 
    bigObjects      (4), 
    fallenTrees     (5), 
    hubCaps         (6), 
    waitingVehicles (7)
} (0..255)
```

### <a name="HazardousLocation-SurfaceConditionSubCauseCode"></a>HazardousLocation-SurfaceConditionSubCauseCode
This DE represents the value of the sub cause code of the [**CauseCode**](#CauseCode) `hazardousLocation-SurfaceCondition`. 
 
The value shall be set to:
 - 0  - `unavailable`     - in case further detailed information on the road surface condition is unavailable,
 - 1  - `rockfalls`       - in case rock falls are detected on the road surface,
 - 2  - `earthquakeDamage`- in case the road surface is damaged by earthquake,
 - 3  - `sewerCollapse`   - in case of sewer collapse on the road surface,
 - 4  - `subsidence`      - in case road surface is damaged by subsidence,
 - 5  - `snowDrifts`      - in case road surface is damaged due to snow drift,
 - 6  - `stormDamage`     - in case road surface is damaged by strong storm,
 - 7  - `burstPipe`       - in case road surface is damaged due to pipe burst,
 - 8  - `volcanoEruption` - in case road surface is damaged due to volcano eruption,
 - 9  - `fallingIce`      - in case road surface damage is due to falling ice,
 - 10 - `fire`            - in case there is fire on or near to the road surface.
 - 11-255                 - are reserved for future usage.

* **unavailable** (0)<br>
* **rockfalls** (1)<br>
* **earthquakeDamage** (2)<br>
* **sewerCollapse** (3)<br>
* **subsidence** (4)<br>
* **snowDrifts** (5)<br>
* **stormDamage** (6)<br>
* **burstPipe** (7)<br>
* **volcanoEruption** (8)<br>
* **fallingIce** (9)<br>
* **fire** (10)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Traffic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V1.3.1_
```asn1
HazardousLocation-SurfaceConditionSubCauseCode ::= INTEGER {
    unavailable      (0), 
    rockfalls        (1), 
    earthquakeDamage (2), 
    sewerCollapse    (3), 
    subsidence       (4), 
    snowDrifts       (5), 
    stormDamage      (6), 
    burstPipe        (7), 
    volcanoEruption  (8), 
    fallingIce       (9), 
    fire             (10)
} (0..255)
```

### <a name="HeadingConfidence"></a>HeadingConfidence
This DE indicates the heading confidence value which represents the estimated absolute accuracy of a heading value with a confidence level of 95 %.
 
 The value shall be set to:
 - `n` (`n > 0` and `n < 126`) if the confidence value is equal to or less than n x 0,1 degree and more than (n-1) x 0,1 degree,
 - `126` if the confidence value is out of range, i.e. greater than 12,5 degrees,
 - `127` if the confidence value information is not available.

* **outOfRange** (126)<br>
* **unavailable** (127)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _0,1 degree_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** GeoReference information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Description revised in V2.1.1_

>>>
NOTE:&emsp;this DE is kept for backwards compatibility reasons only. It is recommended to use the [**Wgs84AngleConfidence**](#Wgs84AngleConfidence) instead.
>>>
```asn1
HeadingConfidence ::= INTEGER {
    outOfRange  (126), 
    unavailable (127)  
} (1..127)
```

### <a name="HeadingValue"></a>HeadingValue
This DE represents the orientation of the horizontal velocity vector with regards to the WGS84 north.
 When the information is not available, the DE shall be set to 3 601. The value 3600 shall not be used.


 Unit: 0,1 degree
 Categories: GeoReference information

* **wgs84North** (0)<br>
* **wgs84East** (900)<br>
* **wgs84South** (1800)<br>
* **wgs84West** (2700)<br>
* **doNotUse** (3600)<br>
* **unavailable** (3601)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Description revised in V2.1.1 (usage of value 3600 specified)_

>>>
NOTE:&emsp;this DE is kept for backwards compatibility reasons only. It is recommended to use the [**Wgs84AngleValue**](#Wgs84AngleValue) instead.
>>>
```asn1
HeadingValue ::= INTEGER { 
    wgs84North  (0),
    wgs84East   (900),
    wgs84South  (1800),
    wgs84West   (2700),
    doNotUse    (3600),
    unavailable (3601)
} (0..3601)
```

### <a name="HeightLonCarr"></a>HeightLonCarr
This DE represents the height of the left or right longitude carrier of vehicle from base to top (left or right carrier seen from vehicle
 rear to front). 

 The value shall be set to:
 - `n` (`n ≥ 1` and `n < 99`) if the height information is equal to or less than n x 0,01 metre and more than (n-1) x 0,01 metre,
 - `99` if the height is out of range, i.e. equal to or greater than 0,98 m,
 - `100` if the height information is not available.

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _0,01 metre_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Vehicle information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Description revised in V2.1.1 (the definition of 99 has changed slightly)_
```asn1
HeightLonCarr ::= INTEGER {
    outOfRange(99),
    unavailable(100)
} (1..100)
```

### <a name="HumanPresenceOnTheRoadSubCauseCode"></a>HumanPresenceOnTheRoadSubCauseCode
This DE represents the value of the sub cause code of the [**CauseCode**](#CauseCode) `humanPresenceOnTheRoad`.
 
 The value shall be set to:
 - 0 - `unavailable`          - in case further detailed information on human presence on the road is unavailable,
 - 1 - `childrenOnRoadway`    - in case children are detected on the road,
 - 2 - `cyclistOnRoadway`     - in case cyclist presence is detected on the road,
 - 3 - `motorcyclistOnRoadway`- in case motorcyclist presence is detected on the road.
 - 4-255                      - are reserved for future usage.

* **unavailable** (0)<br>
* **childrenOnRoadway** (1)<br>
* **cyclistOnRoadway** (2)<br>
* **motorcyclistOnRoadway** (3)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Traffic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _editorial revision in V2.1.1_
```asn1
HumanPresenceOnTheRoadSubCauseCode ::= INTEGER {
    unavailable           (0), 
    childrenOnRoadway     (1), 
    cyclistOnRoadway      (2), 
    motorcyclistOnRoadway (3)
} (0..255)
```

### <a name="HumanProblemSubCauseCode"></a>HumanProblemSubCauseCode
This DE represents the value of the sub cause codes of the [**CauseCode**](#CauseCode) "humanProblem".
 
 The value shall be set to:
 - 0 - `unavailable`    - in case further detailed information on human health problem is unavailable,
 - 1 - `glycemiaProblem`- in case human problem is due to glycaemia problem,
 - 2 - `heartProblem`   - in case human problem is due to heart problem.
 - 3-255                - reserved for future usage.

* **unavailable** (0)<br>
* **glycemiaProblem** (1)<br>
* **heartProblem** (2)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Traffic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V1.3.1_
```asn1
HumanProblemSubCauseCode ::= INTEGER {
    unavailable     (0), 
    glycemiaProblem (1), 
    heartProblem    (2)
} (0..255)
```

### <a name="Identifier1B"></a>Identifier1B
This DE is a general identifier.

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Basic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
Identifier1B ::= INTEGER (0..255)
```

### <a name="Identifier2B"></a>Identifier2B
This DE is a general identifier.

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Basic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
Identifier2B ::= INTEGER (0..65535)
```

### <a name="InformationQuality"></a>InformationQuality
This DE represents the quality level of provided information.
 
 The value shall be set to:
 - `0` if the information is unavailable,
 - `1` if the quality level is lowest,
 - `n` (`n > 1` and `n < 7`) if the quality level is n, 
 - `7` if the quality level is highest.

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Basic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Editorial update in V2.1.1_

>>>
NOTE:&emsp;Definition of quality level is out of scope of the present document.
>>>
```asn1
InformationQuality ::= INTEGER (0..7)
```

### <a name="InterferenceManagementZoneType"></a>InterferenceManagementZoneType
This DE defines the type of an interference management zone, so that an ITS-S can 
 assert the actions to do while passing by such zone (e.g. reduce the transmit power in case of a DSRC tolling station).
 It is an extension of the type [**ProtectedZoneType**](#ProtectedZoneType).

 The value shall be set to:
 - 0 - `permanentCenDsrcTolling` - as specified in ETSI TS 102 792 [[14]](#references),
 - 1 - `temporaryCenDsrcTolling` - as specified in ETSI TS 102 792 [[14]](#references),
 - 2 - `unavailable`             - default value. Set to 2 for backwards compatibility with DSRC tolling,
 - 3 - `urbanRail`               - as specified in ETSI TS 103 724 [[13]](#references), clause 7,
 - 4 - `satelliteStation`        - as specified in ETSI TS 103 724 [[13]](#references), clause 7,
 - 5 - `fixedLinks`              - as specified in ETSI TS 103 724 [[13]](#references), clause 7.

* **permanentCenDsrcTolling** (0)<br>
* **temporaryCenDsrcTolling** (1)<br>
* **unavailable** (2)<br>
* **urbanRail** (3)<br>
* **satelliteStation** (4)<br>
* **fixedLinks** (5)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Communication information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
InterferenceManagementZoneType ::= ENUMERATED {
    permanentCenDsrcTolling (0),
    temporaryCenDsrcTolling (1),
    unavailable             (2), 
    urbanRail               (3),      
    satelliteStation        (4),
    fixedLinks              (5), 
    ...
}
```

### <a name="Iso3833VehicleType"></a>Iso3833VehicleType
This DE represents the vehicle type according to ISO 3833 [[22]](#references).
 A "term No" refers to the number of the corresponding term and its definition in ISO 3833.

 The value shall be set to:
 - 0	- `passengerCar`              - term No 3.1.1
 - 1	- `saloon`                    - term No 3.1.1.1 (sedan)
 - 2	- `convertibleSaloon`         - term No 3.1.1.2
 - 3	- `pullmanSaloon`             - term No 3.1.1.3
 - 4	- `stationWagon`              - term No 3.1.1.4
 - 5	- `truckStationWagon`         - term No 3.1.1.4.1
 - 6	- `coupe`                     - term No 3.1.1.5 (coupe)
 - 7	- `convertible`               - term No 3.1.1.6 (open tourer, roadstar, spider)
 - 8	- `multipurposePassengerCar`  - term No 3.1.1.7
 - 9	- `forwardControlPassengerCar`- term No 3.1.1.8
 - 10	- `specialPassengerCar`       - term No 3.1.1.9
 - 11	- `bus`                       - term No 3.1.2
 - 12	- `minibus`                   - term No 3.1.2.1
 - 13	- `urbanBus`                  - term No 3.1.2.2
 - 14	- `interurbanCoach`           - term No 3.1.2.3
 - 15	- `longDistanceCoach`         - term No 3.1.2.4
 - 16	- `articulatedBus`            - term No 3.1.2.5
 - 17	- `trolleyBus	`             - term No 3.1.2.6
 - 18	- `specialBus`                - term No 3.1.2.7
 - 19	- `commercialVehicle`         - term No 3.1.3
 - 20	- `specialCommercialVehicle`  - term No 3.1.3.1
 - 21	- `specialVehicle`            - term No 3.1.4
 - 22	- `trailingTowingVehicle`     - term No 3.1.5 (draw-bar tractor)
 - 23	- `semiTrailerTowingVehicle`  - term No 3.1.6 (fifth wheel tractor)
 - 24	- `trailer`                   - term No 3.2.1
 - 25	- `busTrailer`                - term No 3.2.1.1
 - 26	- `generalPurposeTrailer`     - term No 3.2.1.2
 - 27	- `caravan`                   - term No 3.2.1.3
 - 28	- `specialTrailer`            - term No 3.2.1.4
 - 29	- `semiTrailer`               - term No 3.2.2
 - 30	- `busSemiTrailer`            - term No 3.2.2.1
 - 31	- `generalPurposeSemiTrailer` - term No 3.2.2.2
 - 32	- `specialSemiTrailer`        - term No 3.2.2.3
 - 33	- `roadTrain`                 - term No 3.3.1
 - 34	- `passengerRoadTrain`        - term No 3.3.2
 - 35	- `articulatedRoadTrain`      - term No 3.3.3
 - 36	- `doubleRoadTrain`           - term No 3.3.4
 - 37	- `compositeRoadTrain`        - term No 3.3.5
 - 38	- `specialRoadTrain`          - term No 3.3.6
 - 39	- `moped`                     - term No 3.4
 - 40	- `motorCycle`                - term No 3.5
 - 41-255                           - reserved for future use

* **passengerCar** (0)<br>
* **saloon** (1)<br>
* **convertibleSaloon** (2)<br>
* **pullmanSaloon** (3)<br>
* **stationWagon** (4)<br>
* **truckStationWagon** (5)<br>
* **coupe** (6)<br>
* **convertible** (7)<br>
* **multipurposePassengerCar** (8)<br>
* **forwardControlPassengerCar** (9)<br>
* **specialPassengerCar** (10)<br>
* **bus** (11)<br>
* **minibus** (12)<br>
* **urbanBus** (13)<br>
* **interurbanCoach** (14)<br>
* **longDistanceCoach** (15)<br>
* **articulatedBus** (16)<br>
* **trolleyBus** (17)<br>
* **specialBus** (18)<br>
* **commercialVehicle** (19)<br>
* **specialCommercialVehicle** (20)<br>
* **specialVehicle** (21)<br>
* **trailingTowingVehicle** (22)<br>
* **semiTrailerTowingVehicle** (23)<br>
* **trailer** (24)<br>
* **busTrailer** (25)<br>
* **generalPurposeTrailer** (26)<br>
* **caravan** (27)<br>
* **specialTrailer** (28)<br>
* **semiTrailer** (29)<br>
* **busSemiTrailer** (30)<br>
* **generalPurposeSemiTrailer** (31)<br>
* **specialSemiTrailer** (32)<br>
* **roadTrain** (33)<br>
* **passengerRoadTrain** (34)<br>
* **articulatedRoadTrain** (35)<br>
* **doubleRoadTrain** (36)<br>
* **compositeRoadTrain** (37)<br>
* **specialRoadTrain** (38)<br>
* **moped** (39)<br>
* **motorCycle** (40)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Vehicle information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
Iso3833VehicleType ::= INTEGER {
    passengerCar                 (0),
    saloon                       (1),	
    convertibleSaloon            (2),	
    pullmanSaloon                (3),	
    stationWagon                 (4),	
    truckStationWagon            (5),	
    coupe                        (6),
    convertible                  (7),	
    multipurposePassengerCar     (8),	
    forwardControlPassengerCar   (9),	
    specialPassengerCar	         (10),
    bus	                         (11),
    minibus                      (12),	
    urbanBus                     (13),	
    interurbanCoach              (14),	
    longDistanceCoach            (15),	
    articulatedBus               (16),	
    trolleyBus                   (17),
    specialBus                   (18),	
    commercialVehicle            (19),	
    specialCommercialVehicle     (20),
    specialVehicle               (21),	
    trailingTowingVehicle        (22),	
    semiTrailerTowingVehicle     (23),	
    trailer                      (24),	
    busTrailer                   (25),
    generalPurposeTrailer        (26),
    caravan                      (27),	
    specialTrailer               (28),	
    semiTrailer	                 (29),	
    busSemiTrailer               (30),	
    generalPurposeSemiTrailer    (31),
    specialSemiTrailer           (32),	
    roadTrain                    (33),	
    passengerRoadTrain           (34),	
    articulatedRoadTrain         (35),	
    doubleRoadTrain	             (36),
    compositeRoadTrain           (37),	
    specialRoadTrain             (38),	
    moped                        (39),	
    motorCycle                   (40)	
	} (0..255)
```

### <a name="LanePosition"></a>LanePosition
This DE indicates a transversal position on the carriageway at a specific longitudinal position, in resolution of lanes of the carriageway. 

 For right-hand traffic roads, the value shall be set to:
 - `-1` if the position is off, i.e. besides the road,
 - `0` if the position is on the inner hard shoulder, i.e. the hard should adjacent to the leftmost lane,
 - `n` (`n > 0` and `n < 14`), if the position is on the n-th driving lane counted from the leftmost lane to the rightmost lane of a specific traffic direction,
 - `14` if the position is on the outer hard shoulder, i.e. the hard should adjacent to rightmost lane (if present).

 For left-hand traffic roads, the value shall be set to:
 - `-1` if the position is off, i.e. besides the road,
 - `0` if the position is on the inner hard shoulder, i.e. the hard should adjacent to the rightmost lane,
 - `n` (`n > 0` and `n < 14`), if the position is on the n-th driving lane counted from the rightmost lane to the leftmost lane of a specific traffic direction,
 - `14` if the position is on the outer hard shoulder, i.e. the hard should adjacent to leftmost lane (if present).


 If the carriageway allows only traffic in one direction (e.g. in case of dual or multiple carriageway roads), the position is counted from the physical border of the carriageway. 
 If the carriageway allows traffic in both directions and there is no physical delimitation between traffic directions (e.g. on a single carrriageway road), 
 the position is counted from the legal (i.e. optical) separation between traffic directions (horizontal marking).

* **offTheRoad** (-1)<br>
* **innerHardShoulder** (0)<br>
* **outerHardShoulder** (14)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Road topology information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Description revised in V2.1.1_

>>>
NOTE:&emsp;in practice this means that the position is counted from "inside" to "outside" no matter which traffic practice is used.
>>>
```asn1
LanePosition ::= INTEGER {
    offTheRoad           (-1), 
    innerHardShoulder    (0), 
    outerHardShoulder    (14) 
} (-1..14)
```

### <a name="LaneType"></a>LaneType
This DE represents the type of a lane. 
 
 The value shall be set to:
 - 0	- `traffic`            - Lane dedicated to the movement of vehicles,
 - 1	- `through`            - Lane dedicated to the movement of vehicles travelling ahead and not turning,
 - 2	- `reversible`         - Lane where the direction of traffic can be changed to match the peak flow,
 - 3	- `acceleration`	   - Lane that allows vehicles entering a road to accelerate to the speed of through traffic before merging with it,
 - 4	- `deceleration`       - Lane that allows vehicles exiting a road to decelerate before leaving it,
 - 5	- `leftHandTurning`    - Lane reserved for slowing down and making a left turn, so as not to disrupt traffic,
 - 6	- `rightHandTurning`   - Lane reserved for slowing down and making a right turn so as not to disrupt traffic,
 - 7	- `dedicatedVehicle`   - Lane dedicated to movement of motor vehicles with specific characteristics, such as heavy goods vehicles, etc., 
 - 8	- `bus`                - Lane dedicated to movement of buses providing public transport,
 - 9	- `taxi`               - Lane dedicated to movement of taxis,
 - 10	- `hov`                - Carpooling lane or high occupancy vehicle lane,
 - 11	- `hot`                - High occupancy vehicle lanes that is allowed to be used without meeting the occupancy criteria by paying a toll,
 - 12	- `pedestrian`         - Lanes dedicated to pedestrians such as pedestrian sidewalk paths,
 - 13	- `cycleLane`	       - Lane dedicated to exclusive or preferred use by bicycles,
 - 14	- `median`             - Lane not dedicated to movement of vehicles but representing a median / central reservation  such as the central median, 
                                 separating the two directional carriageways of the highway,
 - 15	- `striping`	       - Lane not dedicated to movement of vehicles but covered with roadway markings,
 - 16	- `trackedVehicle`     - Lane dedicated to movement of trains, trams and trolleys,
 - 17	- `parking`            - Lanes dedicated to vehicles parking, stopping and loading lanes,
 - 18	- `emergency`          - Lane dedicated to vehicles in breakdown or to emergency vehicles also called hard shoulder,
 - 19	- `verge`              - Lane representing the verge, i.e. a narrow strip of grass or plants and sometimes also trees located between 
                                 the road surface edge and the boundary of a road,
 - 20	`minimumRiskManoeuvre` - Lane dedicated to automated vehicles making a minimum risk manoeuvre.
 - values 21 to 30             reserved for future use.

* **traffic** (0)<br>
* **through** (1)<br>
* **reversible** (2)<br>
* **acceleration** (3)<br>
* **deceleration** (4)<br>
* **leftHandTurning** (5)<br>
* **rightHandTurning** (6)<br>
* **dedicatedVehicle** (7)<br>
* **bus** (8)<br>
* **taxi** (9)<br>
* **hov** (10)<br>
* **hot** (11)<br>
* **pedestrian** (12)<br>
* **cycleLane** (13)<br>
* **median** (14)<br>
* **striping** (15)<br>
* **trackedVehicle** (16)<br>
* **parking** (17)<br>
* **emergency** (18)<br>
* **verge** (19)<br>
* **minimumRiskManoeuvre** (20)<br>
* **unknown** (31)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Road topology information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
LaneType::= INTEGER{
	traffic              (0),
	through	             (1),
	reversible           (2),
	acceleration         (3),
	deceleration         (4),
	leftHandTurning      (5),
	rightHandTurning     (6),
	dedicatedVehicle     (7),
	bus                  (8),
	taxi                 (9),
	hov                  (10),
	hot                  (11),
	pedestrian           (12),
	cycleLane            (13),
	median               (14),   
	striping             (15),
	trackedVehicle       (16),
	parking	             (17),
	emergency            (18),
	verge                (19),
	minimumRiskManoeuvre (20),
	unknown              (31)
}(0..31)
```

### <a name="LaneWidth"></a>LaneWidth
This DE represents the width of a lane measured at a defined position.

 The value shall be set to:
 - `n` (`n > 0` and `n < 1022`) if the lane width information is equal to or less than n x 0,01 metre and more than (n-1) x 0,01 metre,
 - `1022` if the lane width is out of range, i.e. greater than 10,21 m,
 - `1023` if the lane width information is not available.

 The value 0 shall not be used.

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _0,01 metre_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Road topology information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
LaneWidth::= INTEGER (0..1023)
```

### <a name="Latitude"></a>Latitude
This DE represents the absolute geographical latitude in a WGS84 coordinate system, providing a range of 90 degrees in north or
 in south hemisphere.
 The specific WGS84 coordinate system is specified by the corresponding standards applying this DE.

 The value shall be set to:
 - `n` (`n ≥ -900 000 000` and `n < 0`) x 10<sup>-7</sup> degree, i.e. negative values for latitudes south of the Equator,
 - `0` is used for the latitude of the equator,
 - `n` (`n > 0` and `n < 900 000 001`) x 10<sup>-7</sup> degree, i.e. positive values for latitudes north of the Equator,
 - `900 000 001` when the information is unavailable.

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _10<sup>-7</sup> degree_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** GeoReference information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Editorial update in V2.1.1_
```asn1
Latitude ::= INTEGER {
    unavailable(900000001)
} (-900000000..900000001)
```

### <a name="LateralAccelerationValue"></a>LateralAccelerationValue
This DE represents the vehicle acceleration at lateral direction in the centre of the mass of the empty vehicle.
 It corresponds to the vehicle coordinate system as specified in ISO 8855 [[21]](#references).

 The value shall be set to:
 - `-160` for acceleration values equal to or less than -16 m/s<sup>2</sup>,
 - `n` (`n > -160` and `n ≤ 0`) to indicate that the vehicle is accelerating towards the right side with regards to the vehicle orientation 
                            with acceleration equal to or less than n x 0,1 m/s<sup>2</sup> and greater than (n-1) x 0,1 m/s<sup>2</sup>,
 - `n` (`n > 0` and `n < 160`) to indicate that the vehicle is accelerating towards the left hand side with regards to the vehicle orientation 
						     with acceleration equal to or less than n x 0,1 m/s<sup>2</sup> and greater than (n-1) x 0,1 m/s<sup>2</sup>,
 - `160` for acceleration values greater than 15,9 m/s<sup>2</sup>,
 - `161` when the data is unavailable.

* **negativeOutOfRange** (-160)<br>
* **positiveOutOfRange** (160)<br>
* **unavailable** (161)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _0,1 m/s<sup>2</sup>_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Vehicle information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Description updated in V2.1.1 (the meaning of 160 has changed slightly)._

>>>
NOTE:&emsp;this DF is kept for backwards compatibility reasons only. It is recommended to use [**AccelerationValue**](#AccelerationValue) instead.
>>>
```asn1
LateralAccelerationValue ::= INTEGER {
    negativeOutOfRange (-160),
    positiveOutOfRange (160),
    unavailable        (161)  
} (-160 .. 161)
```

### <a name="LightBarSirenInUse"></a>LightBarSirenInUse
This DE indicates the status of light bar and any sort of audible alarm system besides the horn.
 This includes various common sirens as well as backup up beepers and other slow speed manoeuvring alerts.

 The corresponding bit shall be set to 1 under the following conditions:
 - 0 - `lightBarActivated`      - when the light bar is activated,
 - 1 - `sirenActivated`         - when the siren is activated.

 Otherwise, it shall be set to 0.

* **lightBarActivated** (0)<br>
* **sirenActivated** (1)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Vehicle information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Editorial update in V2.1.1_
```asn1
LightBarSirenInUse ::= BIT STRING {
    lightBarActivated (0),
    sirenActivated    (1)
} (SIZE(2))
```

### <a name="Longitude"></a>Longitude
This DE represents the absolute geographical longitude in a WGS84 coordinate system, providing a range of 180 degrees
 to the east or to the west of the prime meridian.
 The specific WGS84 coordinate system is specified by the corresponding standards applying this DE.

 The value shall be set to:
 - `n` (`n > -1 800 000 000` and `n < 0`) x 10<sup>-7</sup> degree, i.e. negative values for longitudes to the west,
 - `0` to indicate the prime meridian,
 - `n` (`n > 0` and `n < 1 800 000 001`) x 10<sup>-7</sup> degree, i.e. positive values for longitudes to the east,
 - `1 800 000 001` when the information is unavailable.

 The value -1 800 000 000 shall not be used.

* **valueNotUsed** (-1800000000)<br>
* **unavailable** (1800000001)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _10<sup>-7</sup> degree_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** GeoReference information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Description revised in V2.1.1_
```asn1
Longitude ::= INTEGER {
    valueNotUsed (-1800000000),
    unavailable  (1800000001)
} (-1800000000..1800000001)
```

### <a name="LongitudinalAccelerationValue"></a>LongitudinalAccelerationValue
This DE represents the vehicle acceleration at longitudinal direction in the centre of the mass of the empty vehicle.
 The value shall be provided in the vehicle coordinate system as defined in ISO 8855 [[21]](#references), clause 2.11.

 The value shall be set to:
 - `-160` for acceleration values equal to or less than -16 m/s<sup>2</sup>,
 - `n` (`n > -160` and `n ≤ 0`) to indicate that the vehicle is braking with acceleration equal to or less than n x 0,1 m/s<sup>2</sup>, and greater than (n-1) x 0,1 m/s<sup>2</sup>
 - `n` (`n > 0` and `n < 160`) to indicate that the vehicle is accelerating with acceleration equal to or less than n x 0,1 m/s<sup>2</sup>, and greater than (n-1) x 0,1 m/s<sup>2</sup>,
 - `160` for acceleration values greater than 15,9 m/s<sup>2</sup>,
 - `161` when the data is unavailable. 
 
 This acceleration is along the tangent plane of the road surface and does not include gravity components.

* **negativeOutOfRange** (-160)<br>
* **positiveOutOfRange** (160)<br>
* **unavailable** (161)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _0,1 m/s<sup>2</sup>_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Vehicle information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _description revised in V2.1.1 (the meaning of 160 has changed slightly). T_

>>>
NOTE:&emsp;The empty load vehicle is defined in ISO 1176 [[8]](#references), clause 4.6.
>>>
```asn1
LongitudinalAccelerationValue::= INTEGER {
    negativeOutOfRange (-160),
    positiveOutOfRange (160),
    unavailable        (161)  
} (-160 .. 161)
```

### <a name="LongitudinalLanePositionValue"></a>LongitudinalLanePositionValue
This DE represents the longitudinal offset of a map-matched position along a matched lane, beginning from the lane's starting point.
 
 The value shall be set to:
 - `n` (`n ≥ 0` and `n < 32766`) if the longitudinal offset information is equal to or less than n x 0,1 metre and more than (n-1) x 0,1 metre,
 - `32 766` if the longitudinal offset is out of range, i.e. greater than 3276,5 m,
 - `32 767` if the longitudinal offset information is not available.

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _0,1 metre_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** GeoReference information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
LongitudinalLanePositionValue ::= INTEGER {
    outOfRange(32766),
    unavailable(32767)
}(0..32767)
```

### <a name="LongitudinalLanePositionConfidence"></a>LongitudinalLanePositionConfidence
This DE indicates the longitudinal lane position confidence value which represents the estimated accuracy of longitudinal lane position measurement with a default confidence level of 95 %.
 If required, the confidence level can be defined by the corresponding standards applying this DE.

 The value shall be set to:
 - `n` (`n > 0` and `n < 1 022`) if the  confidence value is equal to or less than n x 0,1 m, and more than (n-1) x 0,1 m,
 - `1 022` if the confidence value is out of range i.e. greater than 102,1 m,
 - `1 023` if the confidence value is unavailable.

* **outOfRange** (1022)<br>
* **unavailable** (1023)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _0,1 metre_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** GeoReference information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
LongitudinalLanePositionConfidence ::= INTEGER {
    outOfRange  (1022),
    unavailable (1023)  
} (0..1023)
```

### <a name="MatrixIncludedComponents"></a>MatrixIncludedComponents
This DE indicates the components of an [**PerceivedObject**](#PerceivedObject) that are included in the [**LowerTriangularPositiveSemidefiniteMatrix**](#LowerTriangularPositiveSemidefiniteMatrix).

 The corresponding bit shall be set to 1 if the component is included:
 - 0 - `xCoordinate`                   - when the component xCoordinate of the component [**CartesianPosition3dWithConfidence**](#CartesianPosition3dWithConfidence) is included,
 - 1 - `yCoordinate`                   - when the component yCoordinate of the component [**CartesianPosition3dWithConfidence**](#CartesianPosition3dWithConfidence) is included,   
 - 2 - `zCoordinate`                   - when the component zCoordinate of the component [**CartesianPosition3dWithConfidence**](#CartesianPosition3dWithConfidence) is included, 
 - 3 - `xVelocityOrVelocityMagnitude`  - when the component xVelocity of the component [**VelocityCartesian**](#VelocityCartesian) or the component VelocityMagnitude of the component [**VelocityPolarWithZ**](#VelocityPolarWithZ) is included,   
 - 4 - `yVelocityOrVelocityDirection`  - when the component yVelocity of the component [**VelocityCartesian**](#VelocityCartesian) or the component VelocityDirection of the component [**VelocityPolarWithZ**](#VelocityPolarWithZ) is included,   
 - 5 - `zVelocity`                     - when the component zVelocity of the component [**VelocityCartesian**](#VelocityCartesian) or of the component [**VelocityPolarWithZ**](#VelocityPolarWithZ) is included,
 - 6 - `xAccelOrAccelMagnitude`        - when the component xAcceleration of the component [**AccelerationCartesian**](#AccelerationCartesian) or the component AccelerationMagnitude of the component [**AccelerationPolarWithZ**](#AccelerationPolarWithZ) is included,  
 - 7 - `yAccelOrAccelDirection`        - when the component yAcceleration of the component [**AccelerationCartesian**](#AccelerationCartesian) or the component AccelerationDirection of the component [**AccelerationPolarWithZ**](#AccelerationPolarWithZ) is included,   
 - 8 - `zAcceleration`                 - when the component zAcceleration of the component [**AccelerationCartesian**](#AccelerationCartesian) or of the component [**AccelerationPolarWithZ**](#AccelerationPolarWithZ) is included,
 - 9 - `zAngle`                        - when the component zAngle is included,
 - 10 - `yAngle`                       - when the component yAngle is included,   
 - 11 - `xAngle`                       - when the component xAngle is included,   
 - 12 - `zAngularVelocity`             - when the component zAngularVelocity is included.   

 Otherwise, it shall be set to 0.

* **xPosition** (0)<br>
* **yPosition** (1)<br>
* **zPosition** (2)<br>
* **xVelocityOrVelocityMagnitude** (3)<br>
* **yVelocityOrVelocityDirection** (4)<br>
* **zSpeed** (5)<br>
* **xAccelOrAccelMagnitude** (6)<br>
* **yAccelOrAccelDirection** (7)<br>
* **zAcceleration** (8)<br>
* **zAngle** (9)<br>
* **yAngle** (10)<br>
* **xAngle** (11)<br>
* **zAngularVelocity** (12)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Sensing information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
MatrixIncludedComponents::= BIT STRING{
    xPosition                    (0),
    yPosition                    (1),
    zPosition                    (2),
    xVelocityOrVelocityMagnitude (3),
    yVelocityOrVelocityDirection (4),
    zSpeed                       (5),
    xAccelOrAccelMagnitude       (6),
    yAccelOrAccelDirection       (7),
    zAcceleration                (8),
    zAngle                       (9),  
    yAngle                      (10), 
    xAngle                      (11), 
    zAngularVelocity              (12)
} (SIZE(13,...))
```

### <a name="MessageId"></a>MessageId
This DE represents the type of facility layer message.

  The value shall be set to:
	- 1  - `denm`              - for Decentralized Environmental Notification Message (DENM) as specified in ETSI EN 302 637-3 [[2]](#references),
  - 2  - `cam`               - for Cooperative Awareness Message (CAM) as specified in ETSI EN 302 637-2 [[1]](#references),
  - 3  - `poi`               - for Point of Interest message as specified in ETSI TS 101 556-1 [[9]](#references),
  - 4  - `spatem`            - for Signal Phase And Timing Extended Message (SPATEM) as specified in ETSI TS 103 301 [[15]](#references),
  - 5  - `mapem`             - for MAP Extended Message (MAPEM) as specified in ETSI TS 103 301 [[15]](#references),
  - 6  - `ivim`              - for in Vehicle Information Message (IVIM) as specified in ETSI TS 103 301 [[15]](#references),
  - 7  - `ev-rsr`            - for Electric vehicle recharging spot reservation message, as defined in ETSI TS 101 556-3 [[11]](#references),
  - 8  - `tistpgtransaction` - for messages for Tyre Information System (TIS) and Tyre Pressure Gauge (TPG) interoperability, as specified in ETSI TS 101 556-2 [[10]](#references),
  - 9  - `srem`              - for Signal Request Extended Message as specified in ETSI TS 103 301 [[15]](#references),
  - 10 - `ssem`              - for Signal request Status Extended Message as specified in ETSI TS 103 301 [[15]](#references),
  - 11 - `evcsn`             - for Electrical Vehicle Charging Spot Notification message as specified in ETSI TS 101 556-1 [[9]](#references),
  - 12 - `saem`              - for Services Announcement Extended Message as specified in ETSI EN 302 890-1 [[17]](#references),
  - 13 - `rtcmem`            - for Radio Technical Commission for Maritime Services Extended Message (RTCMEM) as specified in ETSI TS 103 301 [[15]](#references),
  - 14 - `cpm`               - reserved for Collective Perception Message (CPM), 
  - 15 - `imzm`              - for Interference Management Zone Message (IMZM) as specified in ETSI TS 103 724 [[13]](#references),
  - 16 - `vam`               - for Vulnerable Road User Awareness Message as specified in ETSI TS 130 300-3 [[12]](#references), 
  - 17 - `dsm`               - reserved for Diagnosis, logging and Status Message,
  - 18 - `pcim`              - reserved for Parking Control Infrastructure Message,
  - 19 - `pcvm`              - reserved for Parking Control Vehicle Message,
  - 20 - `mcm`               - reserved for Manoeuvre Coordination Message,
  - 21 - `pam`               - reserved for Parking Availability Message,
  - 22-255                   - reserved for future usage.

* **denm** (1)<br>
* **cam** (2)<br>
* **poi** (3)<br>
* **spatem** (4)<br>
* **mapem** (5)<br>
* **ivim** (6)<br>
* **ev-rsr** (7)<br>
* **tistpgtransaction** (8)<br>
* **srem** (9)<br>
* **ssem** (10)<br>
* **evcsn** (11)<br>
* **saem** (12)<br>
* **rtcmem** (13)<br>
* **cpm** (14)<br>
* **imzm** (15)<br>
* **vam** (16)<br>
* **dsm** (17)<br>
* **pcim** (18)<br>
* **pcvm** (19)<br>
* **mcm** (20)<br>
* **pam** (21)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Communication information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1 from [**ItsPduHeader**](ETSI-ITS-CDD.md#ItsPduHeader)._
```asn1
MessageId::= INTEGER { 
    denm              (1),  
    cam               (2), 
    poi               (3), 
    spatem            (4), 
    mapem             (5), 
    ivim              (6), 
    ev-rsr            (7), 
    tistpgtransaction (8), 
    srem              (9), 
    ssem              (10), 
    evcsn             (11), 
    saem              (12), 
    rtcmem            (13), 
    cpm               (14),
    imzm              (15),
    vam               (16),
    dsm               (17), 
    pcim              (18),
    pcvm              (19),
    mcm               (20),
    pam               (21)
} (0..255)
```

### <a name="NumberOfOccupants"></a>NumberOfOccupants
This DE represents the number of occupants in a vehicle.

 The value shall be set to:
 - `n` (`n ≥ 0` and `n < 126`) for the number n of occupants,
 - `126` for values equal to or higher than 125,
 - `127` if information is not available.

* **outOfRange** (126)<br>
* **unavailable** (127)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _1 person_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Vehicle information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Editorial update in V2.1.1_
```asn1
NumberOfOccupants ::= INTEGER {
    outOfRange  (126),
    unavailable (127)
} (0 .. 127)
```

### <a name="ObjectPerceptionQuality"></a>ObjectPerceptionQuality
This DE represents a single-value indication about the overall information quality of a perceived object.
 
 The value shall be set to:  
 - `0`                        : if there is no confidence in detected object, e.g. for "ghost"-objects or if confidence could not be computed,
 - `n` (`n > 0` and `n < 15`) : for the applicable confidence value,
 - `15`                       : if there is full confidence in the detected Object.

* **noConfidence** (0)<br>
* **fullConfidence** (15)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _n/a_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Sensing information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
ObjectPerceptionQuality ::= INTEGER {
    noConfidence        (0), 
    fullConfidence      (15) 
} (0..15)
```

### <a name="ObjectDimensionValue"></a>ObjectDimensionValue
This DE represents a single dimension of an object.

 The value shall be set to:
 - `n` (`n > 0` and `n < 255`) if the  accuracy is equal to or less than n x 0,1 m, and more than (n-1) x 0,1 m,
 - `255` if the accuracy is out of range i.e. greater than 25,4 m,
 - `256` if the data is unavailable.

* **outOfRange** (255)<br>
* **unavailable** (256)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _0,1 m_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Basic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
ObjectDimensionValue ::= INTEGER { 
    outOfRange              (255),
    unavailable             (256)
}(1..256)
```

### <a name="ObjectDimensionConfidence"></a>ObjectDimensionConfidence
This DE indicates the object dimension confidence value which represents the estimated absolute accuracy of an object dimension value with a default confidence level of 95 %.
 If required, the confidence level can be defined by the corresponding standards applying this DE.

 The value shall be set to:
 - `n` (`n > 0` and `n < 31`) if the confidence value is equal to or less than n x 0,1 metre, and more than (n-1) x 0,1 metre,
 - `31` if the confidence value is out of range i.e. greater than 3,0 m,
 - `32` if the confidence value is unavailable.

* **outOfRange** (31)<br>
* **unavailable** (32)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _0,1 m_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Sensing information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
ObjectDimensionConfidence ::= INTEGER { 
    outOfRange              (31),
    unavailable             (32)
} (1..32)
```

### <a name="ObjectFace"></a>ObjectFace
This DE indicates the face or part of a face of a solid object.

 The object is modelled  as a rectangular prism that has a length that is greater than its width, with the faces of the object being defined as:
 - front: the face defined by the prism's width and height, and which is the first face in direction of longitudinal movement of the object,
 - back: the face defined by the prism's width and height, and which is the last face in direction of longitudinal movement of the object,
 - side: the faces defined by the prism's length and height with "left" and "right" defined by looking at the front face and "front" and "back" defined w.r.t to the front and back faces. 

 Note: It is permissible to derive the required object dimensions and orientation from models to provide a best guess.

* **front** (0)<br>
* **sideLeftFront** (1)<br>
* **sideLeftBack** (2)<br>
* **sideRightFront** (3)<br>
* **sideRightBack** (4)<br>
* **back** (5)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Basic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V2.1.1_
```asn1
ObjectFace ::= ENUMERATED {
    front          (0), 
    sideLeftFront  (1), 
    sideLeftBack   (2), 
    sideRightFront (3), 
    sideRightBack  (4),
    back           (5)   
}
```

### <a name="OpeningDaysHours"></a>OpeningDaysHours
This DE represents a time period to describe the opening days and hours of a Point of Interest.
 (for example local commerce).

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Basic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V1.3.1_
```asn1
OpeningDaysHours ::= UTF8String
```

### <a name="OrdinalNumber1B"></a>OrdinalNumber1B
The DE represents an ordinal number that indicates the position of an element in a set.

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Basic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
OrdinalNumber1B ::= INTEGER(0..255)
```

### <a name="OrdinalNumber3b"></a>OrdinalNumber3b
The DE represents an ordinal number that indicates the position of an element in a set.

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Basic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
OrdinalNumber3b ::= INTEGER(1..8)
```

### <a name="OtherSubClass"></a>OtherSubClass
This DE indicates the subclass of a detected object for [**ObjectClass**](#ObjectClass) "otherSubclass".

 The value shall be set to:
 - `0` - unknown          - if the subclass is unknown.
 - `1` - singleObject     - if the object is a single object.
 - `2` - multipleObjects  - if the object is a group of multiple objects.
 - `3` - bulkMaterial     - if the object is a bulk material.

* **unknown** (0)<br>
* **singleObject** (1)<br>
* **multipleObjects** (2)<br>
* **bulkMaterial** (3)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Sensing information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
OtherSubClass ::= INTEGER {
    unknown         (0),
    singleObject    (1),
    multipleObjects (2),
    bulkMaterial    (3)
} (0..255)
```

### <a name="PathDeltaTime"></a>PathDeltaTime
This DE represents the recorded or estimated travel time between a position and a predefined reference position.

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _0,01 second_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** GeoReference information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V1.3.1_
```asn1
PathDeltaTime ::= INTEGER (1..65535, ...)
```

### <a name="PerformanceClass"></a>PerformanceClass
This DE denotes the ability of an ITS-S to provide up-to-date information.
 A performance class value is used to describe age of data. The exact values are out of scope of the present document.
 
  The value shall be set to:
 - `0` if  the performance class is unknown,
 - `1` for performance class A as defined in ETSI TS 101 539-1 [[5]](#references),
 - `2` for performance class B as defined in ETSI TS 101 539-1 [[5]](#references),
 -  3-7 reserved for future use.

* **unavailable** (0)<br>
* **performanceClassA** (1)<br>
* **performanceClassB** (2)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Vehicle information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Editorial update in V2.1.1_
```asn1
PerformanceClass ::= INTEGER {
    unavailable       (0), 
    performanceClassA (1), 
    performanceClassB (2)
} (0..7)
```

### <a name="PhoneNumber"></a>PhoneNumber
This DE represents a telephone number

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Basic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V1.3.1_
```asn1
PhoneNumber ::= NumericString (SIZE(1..16))
```

### <a name="PosCentMass"></a>PosCentMass
This DE indicates the perpendicular distance from the centre of mass of an empty load vehicle to the front line of
 the vehicle bounding box of the empty load vehicle.

 The value shall be set to:
 - `n` (`n > 0` and `n < 62`) for any aplicable value n between 0,1 metre and 6,2 metres, 
 - `62` for values equal to or higher than 6.1 metres,
 - `63`  if the information is unavailable.

* **tenCentimetres** (1)<br>
* **outOfRange** (62)<br>
* **unavailable** (63)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _0,1 metre_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Vehicle information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _description revised in V2.1.1 (the meaning of 62 has changed slightly)_

>>>
NOTE:&emsp;The empty load vehicle is defined in ISO 1176 [[8]](#references), clause 4.6.
>>>
```asn1
PosCentMass ::= INTEGER {
    tenCentimetres (1), 
    outOfRange     (62),
    unavailable    (63)
} (1..63)
```

### <a name="PositioningSolutionType"></a>PositioningSolutionType
This DE indicates the positioning technology being used to estimate a geographical position.

 The value shall be set to:
 - 0 `noPositioningSolution`  - no positioning solution used,
 - 1 `sGNSS`                  - Global Navigation Satellite System used,
 - 2 `dGNSS`                  - Differential GNSS used,
 - 3 `sGNSSplusDR`            - GNSS and dead reckoning used,
 - 4 `dGNSSplusDR`            - Differential GNSS and dead reckoning used,
 - 5 `dR`                     - dead reckoning used.

* **noPositioningSolution** (0)<br>
* **sGNSS** (1)<br>
* **dGNSS** (2)<br>
* **sGNSSplusDR** (3)<br>
* **dGNSSplusDR** (4)<br>
* **dR** (5)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** GeoReference information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V1.3.1_
```asn1
PositioningSolutionType ::= ENUMERATED {
    noPositioningSolution (0), 
    sGNSS                 (1), 
    dGNSS                 (2), 
    sGNSSplusDR           (3), 
    dGNSSplusDR           (4), 
    dR                    (5), 
    ...
}
```

### <a name="PositionOfOccupants"></a>PositionOfOccupants
This DE indicates whether a passenger seat is occupied or whether the occupation status is detectable or not.
 
 The number of row in vehicle seats layout is counted in rows from the driver row backwards from front to the rear
 of the vehicle.
 The left side seat of a row refers to the left hand side seen from vehicle rear to front.
 Additionally, a bit is reserved for each seat row, to indicate if the seat occupation of a row is detectable or not,
 i.e. `row1NotDetectable (3)`, `row2NotDetectable(8)`, `row3NotDetectable(13)` and `row4NotDetectable(18)`.
 Finally, a bit is reserved for each row seat to indicate if the seat row is present or not in the vehicle,
 i.e. `row1NotPresent (4)`, `row2NotPresent (9)`, `row3NotPresent(14)`, `row4NotPresent(19)`.
 
 When a seat is detected to be occupied, the corresponding seat occupation bit shall be set to `1`.
 For example, when the row 1 left seat is occupied, `row1LeftOccupied(0)` bit shall be set to `1`.
 When a seat is detected to be not occupied, the corresponding seat occupation bit shall be set to `0`.
 Otherwise, the value of seat occupation bit shall be set according to the following conditions:
 - If the seat occupation of a seat row is not detectable, the corresponding bit shall be set to `1`.
   When any seat row not detectable bit is set to `1`, all corresponding seat occupation bits of the same row
   shall be set to `1`.
 - If the seat row is not present, the corresponding not present bit of the same row shall be set to `1`.
   When any of the seat row not present bit is set to `1`, the corresponding not detectable bit for that row
   shall be set to `1`, and all the corresponding seat occupation bits in that row shall be set to `0`.

* **row1LeftOccupied** (0)<br>
* **row1RightOccupied** (1)<br>
* **row1MidOccupied** (2)<br>
* **row1NotDetectable** (3)<br>
* **row1NotPresent** (4)<br>
* **row2LeftOccupied** (5)<br>
* **row2RightOccupied** (6)<br>
* **row2MidOccupied** (7)<br>
* **row2NotDetectable** (8)<br>
* **row2NotPresent** (9)<br>
* **row3LeftOccupied** (10)<br>
* **row3RightOccupied** (11)<br>
* **row3MidOccupied** (12)<br>
* **row3NotDetectable** (13)<br>
* **row3NotPresent** (14)<br>
* **row4LeftOccupied** (15)<br>
* **row4RightOccupied** (16)<br>
* **row4MidOccupied** (17)<br>
* **row4NotDetectable** (18)<br>
* **row4NotPresent** (19)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Vehicle information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V1.3.1_
```asn1
PositionOfOccupants ::= BIT STRING {
    row1LeftOccupied  (0),
    row1RightOccupied (1),
    row1MidOccupied   (2),
    row1NotDetectable (3),
    row1NotPresent    (4),
    row2LeftOccupied  (5),
    row2RightOccupied (6),
    row2MidOccupied   (7),
    row2NotDetectable (8),
    row2NotPresent    (9),
    row3LeftOccupied  (10),
    row3RightOccupied (11),
    row3MidOccupied   (12),
    row3NotDetectable (13),
    row3NotPresent    (14),
    row4LeftOccupied  (15),
    row4RightOccupied (16),
    row4MidOccupied   (17),
    row4NotDetectable (18),
    row4NotPresent    (19)
} (SIZE(20))
```

### <a name="PosFrontAx"></a>PosFrontAx
This DE indicates the perpendicular distance between the vehicle front line of the bounding box and the front wheel axle in 0,1 metre.

 The value shall be set to:
 - `n` (`n > 0` and `n < 19`) for any aplicable value between 0,1 metre and 1,9 metres,
 - `19` for values equal to or higher than 1.8 metres,
 - `20` if the information is unavailable.

* **outOfRange** (19)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _0,1 metre_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Vehicle information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _description revised in V2.1.1 (the meaning of 19 has changed slightly)_
```asn1
PosFrontAx ::= INTEGER {
    outOfRange (19), 
    unavailable(20)
} (1..20)
```

### <a name="PosLonCarr"></a>PosLonCarr
This DE represents the distance from the centre of vehicle front bumper to the right or left longitudinal carrier of vehicle.
 The left/right carrier refers to the left/right as seen from a passenger sitting in the vehicle.

 The value shall be set to:
 - `n` (`n > 0` and `n < 126`) for any aplicable value between 0,01 metre and 1,26 metres, 
 - `126` for values equal to or higher than 1.25 metres,
 - `127` if the information is unavailable.

* **outOfRange** (126)<br>
* **unavailable** (127)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _0,01 metre_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Vehicle information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _description revised in V2.1.1 (the meaning of 126 has changed slightly)_
```asn1
PosLonCarr ::= INTEGER {
    outOfRange  (126),
    unavailable (127)
} (1..127)
```

### <a name="PosPillar"></a>PosPillar
This DE represents the perpendicular inter-distance of neighbouring pillar axis of vehicle starting from the
 middle point of the front line of the vehicle bounding box.

 The value shall be set to:
 - `n` (`n > 0` and `n < 29`) for any aplicable value between 0,1 metre and 2,9 metres, 
 - `29` for values equal to or greater than 2.8 metres,
 - `30` if the information is unavailable.

* **outOfRange** (29)<br>
* **unavailable** (30)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _0,1 metre_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Vehicle information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _description revised in V2.1.1 (the meaning of 29 has changed slightly)_
```asn1
PosPillar ::= INTEGER {
    outOfRange  (29),
    unavailable (30)
} (1..30)
```

### <a name="PostCrashSubCauseCode"></a>PostCrashSubCauseCode
This DE represents the value of the sub cause codes of the [**CauseCode**](#CauseCode) `postCrash` .
 
 The value shall be set to:
 - 0 `unavailable`                                               - in case further detailed information on post crash event is unavailable,
 - 1 `accidentWithoutECallTriggered`                             - in case no eCall has been triggered for an accident,
 - 2 `accidentWithECallManuallyTriggered`                        - in case eCall has been manually triggered and transmitted to eCall back end,
 - 3 `accidentWithECallAutomaticallyTriggered`                   - in case eCall has been automatically triggered and transmitted to eCall back end,
 - 4 `accidentWithECallTriggeredWithoutAccessToCellularNetwork`  - in case eCall has been triggered but cellular network is not accessible from triggering vehicle.
 - 5-255                                                         - are reserved for future usage.

* **unavailable** (0)<br>
* **accidentWithoutECallTriggered** (1)<br>
* **accidentWithECallManuallyTriggered** (2)<br>
* **accidentWithECallAutomaticallyTriggered** (3)<br>
* **accidentWithECallTriggeredWithoutAccessToCellularNetwork** (4)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Traffic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V1.3.1_
```asn1
PostCrashSubCauseCode ::= INTEGER {
    unavailable                                              (0), 
    accidentWithoutECallTriggered                            (1), 
    accidentWithECallManuallyTriggered                       (2), 
    accidentWithECallAutomaticallyTriggered                  (3), 
    accidentWithECallTriggeredWithoutAccessToCellularNetwork (4)
} (0..255)
```

### <a name="PrecipitationIntensity"></a>PrecipitationIntensity
This DE represent the total amount of rain falling during one hour. It is measured in mm per hour at an area of 1 square metre.  
 
 The following values are specified:
 - `n` (`n > 0` and `n < 2000`) if the amount of rain falling is equal to or less than n x 0,1 mm/h and greater than (n-1) x 0,1 mm/h,
 - `2000` if the amount of rain falling is greater than 199.9 mm/h, 
 - `2001` if the information is not available.

* **outOfRange** (2000)<br>
* **unavailable** (2001)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _0,1 mm/h_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Basic Information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _created in V2.1.1_
```asn1
PrecipitationIntensity ::= INTEGER {
	outOfRange								(2000), 
	unavailable								(2001) 
} (1..2001)
```

### <a name="ProtectedZoneId"></a>ProtectedZoneId
This DE represents the indentifier of a protected communication zone.

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Infrastructure information Communication information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Revision in V2.1.1 (changed name from ProtectedZoneID to ProtectedZoneId)_
```asn1
ProtectedZoneId ::= INTEGER (0.. 134217727)
```

### <a name="ProtectedZoneRadius"></a>ProtectedZoneRadius
This DE represents the radius of a protected communication zone.

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _metre_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Infrastructure information Communication information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V1.3.1_
```asn1
ProtectedZoneRadius ::= INTEGER (1..255,...)
```

### <a name="ProtectedZoneType"></a>ProtectedZoneType
This DE indicates the type of a protected communication zone, so that an ITS-S is aware of the actions to do
 while passing by such zone (e.g. reduce the transmit power in case of a DSRC tolling station).
 
 The protected zone type is defined in ETSI TS 102 792 [[14]](#references).

* **permanentCenDsrcTolling** (0)<br>
* **temporaryCenDsrcTolling** (1)<br>
    
       ...,

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Communication information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V1.3.1_
```asn1
ProtectedZoneType::= ENUMERATED {
    permanentCenDsrcTolling (0), 
    ..., 
    temporaryCenDsrcTolling (1) 
}
```

### <a name="PtActivationData"></a>PtActivationData
This DE is used for various tasks in the public transportation environment, especially for controlling traffic
 signal systems to prioritize and speed up public transportation in urban area (e.g. intersection "_bottlenecks_").
 The traffic lights may be controlled by an approaching bus or tram automatically. This permits "_In Time_" activation
 of the green phase, will enable the individual traffic to clear a potential traffic jam in advance. Thereby the
 approaching bus or tram may pass an intersection with activated green light without slowing down the speed due to
 traffic congestion. Other usage of the DE is the provision of information like the public transport line number
 or the schedule delay of a public transport vehicle.

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Vehicle information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V1.3.1_
```asn1
PtActivationData ::= OCTET STRING (SIZE(1..20))
```

### <a name="PtActivationType"></a>PtActivationType
This DE indicates a certain coding type of the PtActivationData data.

 The folowing value are specified:
 - 0 `undefinedCodingType`  : undefined coding type,
 - 1 `r09-16CodingType`     : coding of PtActivationData conform to VDV recommendation 420 [[7]](#references),
 - 2 `vdv-50149CodingType`  : coding of PtActivationData based on VDV recommendation 420 [[7]](#references).
 - 3 - 255                  : reserved for alternative and future use.

* **undefinedCodingType** (0)<br>
* **r09-16CodingType** (1)<br>
* **vdv-50149CodingType** (2)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Vehicle information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V1.3.1_
```asn1
PtActivationType ::= INTEGER {
    undefinedCodingType (0), 
    r09-16CodingType    (1), 
    vdv-50149CodingType (2)
} (0..255)
```

### <a name="RailwayLevelCrossingSubCauseCode"></a>RailwayLevelCrossingSubCauseCode
This DE represents the value of the sub cause codes of the [**CauseCode**](#CauseCode) `railwayLevelCrossing` .
 
 The value shall be set to:
 - 0 `unavailable`                   - in case no further detailed information on the railway level crossing status is available,
 - 1 `doNotCrossAbnormalSituation`   - in case when something wrong is detected by equation or sensors of the railway level crossing, 
                                         including level crossing is closed for too long (e.g. more than 10 minutes long ; default value),
 - 2 `closed`                        - in case the crossing is closed (barriers down),
 - 3 `unguarded`                     - in case the level crossing is unguarded (i.e a Saint Andrew cross level crossing without detection of train),
 - 4 `nominal`                       - in case the barriers are up and lights are off.
 - 5-255: reserved for future usage.

* **unavailable** (0)<br>
* **doNotCrossAbnormalSituation** (1)<br>
* **closed** (2)<br>
* **unguarded** (3)<br>
* **nominal** (4)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Traffic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V1.3.1_
```asn1
RailwayLevelCrossingSubCauseCode ::= INTEGER {
    unavailable                 (0), 
    doNotCrossAbnormalSituation (1), 
    closed                      (2), 
    unguarded                   (3), 
    nominal                     (4)
} (0..255)
```

### <a name="RelevanceDistance"></a>RelevanceDistance
This DE describes a distance of relevance for information indicated in a message.

 The value shall be set to:
 - 0 `lessThan50m`   - for distances below 50 m,
 - 1 `lessThan100m`  - for distances below 100 m, 
 - 2 `lessThan200m`  - for distances below 200 m, 
 - 3 `lessThan500m`  - for distances below 300 m, 
 - 4 `lessThan1000m` - for distances below 1 000 m, 
 - 5 `lessThan5km`   - for distances below 5 000 m, 
 - 6 `lessThan10km`  - for distances below 10 000 m, 
 - 7 `over10km`      - for distances over 10 000 m.

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** GeoReference information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Editorial update in V2.1.1_

>>>
NOTE:&emsp;this DE is kept for backwards compatibility reasons only. It is recommended to use the [**StandardLength3b**](#StandardLength3b) instead.
>>>
```asn1
RelevanceDistance ::= ENUMERATED {
    lessThan50m(0), 
    lessThan100m(1), 
    lessThan200m(2), 
    lessThan500m(3), 
    lessThan1000m(4), 
    lessThan5km(5), 
    lessThan10km(6), 
    over10km(7)
}
```

### <a name="RelevanceTrafficDirection"></a>RelevanceTrafficDirection
This DE indicates a traffic direction that is relevant to information indicated in a message.
 
 The value shall be set to:
 - 0 `allTrafficDirections` - for all traffic directions, 
 - 1 `upstreamTraffic`      - for upstream traffic, 
 - 2 `downstreamTraffic`    - for downstream traffic, 
 - 3 `oppositeTraffic`      - for traffic in the opposite direction. 

 The terms `upstream`, `downstream` and `oppositeTraffic` are relative to the event position.

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** GeoReference information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Editorial update in V2.1.1_

>>>
NOTE:&emsp;this DE is kept for backwards compatibility reasons only. It is recommended to use the [**TrafficDirection**](#TrafficDirection) instead.
>>>
```asn1
RelevanceTrafficDirection ::= ENUMERATED {
    allTrafficDirections(0), 
    upstreamTraffic(1), 
    downstreamTraffic(2), 
    oppositeTraffic(3)
}
```

### <a name="RequestResponseIndication"></a>RequestResponseIndication
This DE indicates whether an ITS message is transmitted as request from ITS-S or a response transmitted from
 ITS-S after receiving request from other ITS-Ss.

 The value shall be set to:
 - 0 `request`  - for a request message, 
 - 1 `response` - for a response message.

* **request** (0)<br>
* **response** (1)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Communication information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Editorial update in V2.1.1_
```asn1
RequestResponseIndication ::= ENUMERATED {
    request  (0), 
    response (1)
}
```

### <a name="RescueAndRecoveryWorkInProgressSubCauseCode"></a>RescueAndRecoveryWorkInProgressSubCauseCode
This DE represents the value of the sub cause codes of the [**CauseCode**](#CauseCode) `rescueAndRecoveryWorkInProgress` 
 
 The value shall be set to:
 - 0 `unavailable`             - in case further detailed information on rescue and recovery work is unavailable,
 - 1 `emergencyVehicles`       - in case rescue work is ongoing by emergency vehicles,
 - 2 `rescueHelicopterLanding` - in case rescue helicopter is landing,
 - 3 `policeActivityOngoing`   - in case police activity is ongoing,
 - 4 `medicalEmergencyOngoing` - in case medical emergency recovery is ongoing,
 - 5 `childAbductionInProgress`- in case a child kidnapping alarm is activated and rescue work is ongoing,
 - 6-255: reserved for future usage.

* **unavailable** (0)<br>
* **emergencyVehicles** (1)<br>
* **rescueHelicopterLanding** (2)<br>
* **policeActivityOngoing** (3)<br>
* **medicalEmergencyOngoing** (4)<br>
* **childAbductionInProgress** (5)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Traffic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V1.3.1_
```asn1
RescueAndRecoveryWorkInProgressSubCauseCode ::= INTEGER {
   unavailable              (0), 
   emergencyVehicles        (1), 
   rescueHelicopterLanding  (2), 
   policeActivityOngoing    (3), 
   medicalEmergencyOngoing  (4), 
   childAbductionInProgress (5)
} (0..255)
```

### <a name="RoadType"></a>RoadType
This DE indicates the type of a road segment.
 
 The value shall be set to:
 - 0 `urban-NoStructuralSeparationToOppositeLanes`       - for an urban road with no structural separation between lanes carrying traffic in opposite directions,
 - 1 `urban-WithStructuralSeparationToOppositeLanes`     - for an urban road with structural separation between lanes carrying traffic in opposite directions,
 - 2 `nonUrban-NoStructuralSeparationToOppositeLanes`    - for an non urban road with no structural separation between lanes carrying traffic in opposite directions,
 - 3 `nonUrban-WithStructuralSeparationToOppositeLanes`  - for an non urban road with structural separation between lanes carrying traffic in opposite directions.

* **urban-NoStructuralSeparationToOppositeLanes** (0)<br>
* **urban-WithStructuralSeparationToOppositeLanes** (1)<br>
* **nonUrban-NoStructuralSeparationToOppositeLanes** (2)<br>
* **nonUrban-WithStructuralSeparationToOppositeLanes** (3)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Road Topology Information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Editorial update in V2.1.1_
```asn1
RoadType ::= ENUMERATED {
    urban-NoStructuralSeparationToOppositeLanes      (0),
    urban-WithStructuralSeparationToOppositeLanes    (1),
    nonUrban-NoStructuralSeparationToOppositeLanes   (2),
    nonUrban-WithStructuralSeparationToOppositeLanes (3)
}
```

### <a name="RoadworksSubCauseCode"></a>RoadworksSubCauseCode
This DE represents the value of the sub cause codes of the [**CauseCode**](#CauseCode) `roadworks`.
 
The value shall be set to:
 - 0 `unavailable`                 - in case further detailed information on roadworks is unavailable,
 - 1 `majorRoadworks`              - in case a major roadworks is ongoing,
 - 2 `roadMarkingWork`             - in case a road marking work is ongoing,
 - 3 `slowMovingRoadMaintenance`   - in case slow moving road maintenance work is ongoing,
 - 4 `shortTermStationaryRoadworks`- in case a short term stationary roadwork is ongoing,
 - 5 `streetCleaning`              - in case a vehicle street cleaning work is ongoing,
 - 6 `winterService`               - in case winter service work is ongoing.
 - 7-255                           - are reserved for future usage.

* **unavailable** (0)<br>
* **majorRoadworks** (1)<br>
* **roadMarkingWork** (2)<br>
* **slowMovingRoadMaintenance** (3)<br>
* **shortTermStationaryRoadworks** (4)<br>
* **streetCleaning** (5)<br>
* **winterService** (6)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Traffic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V1.3.1_
```asn1
RoadworksSubCauseCode ::= INTEGER {
    unavailable                  (0), 
    majorRoadworks               (1),
    roadMarkingWork              (2), 
    slowMovingRoadMaintenance    (3), 
    shortTermStationaryRoadworks (4), 
   streetCleaning                (5), 
   winterService                 (6)
} (0..255)
```

### <a name="SafeDistanceIndicator"></a>SafeDistanceIndicator
This DE indicates if a distance is safe. 

 The value shall be set to:
 -  `FALSE`  if  the triple  {LaD,  LoD, VD} < {MSLaD, MSLoD, MSVD} is simultaneously  satisfied with confidence level of  90 % or  more, 
 -  `TRUE` otherwise.

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Traffic information Kinematic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _created in V2.1.1_

>>>
NOTE:&emsp;the abbreviations used are Lateral Distance (LaD),  Longitudinal Distance (LoD) and Vertical Distance (VD) 
 and their respective  thresholds, Minimum  Safe  Lateral  Distance (MSLaD), Minimum  Safe  Longitudinal Distance  (MSLoD),  and  Minimum  Safe Vertical Distance (MSVD).
>>>
```asn1
SafeDistanceIndicator::= BOOLEAN
```

### <a name="SemiAxisLength"></a>SemiAxisLength
This DE indicates the horizontal position confidence value which represents the estimated absolute position accuracy, in one of the axis direction as defined in a shape of ellipse with a 
 confidence level of 95 %. 
 
 The value shall be set to:
 - `n` (`n > 0` and `n < 4 094`) if the accuracy is equal to or less than n * 0,01 metre,
 - `4 094` if the accuracy is out of range, i.e. greater than 4,093 m,
 - `4 095` if the accuracy information is unavailable.

 The value 0 shall not be used.

* **doNotUse** (0)<br>
* **outOfRange** (4094)<br>
* **unavailable** (4095)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _0,01 metre_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** GeoReference Information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Description revised in V2.1.1_

>>>
NOTE:&emsp;The fact that a position coordinate value is received with confidence value set to `unavailable(4095)`.
 can be caused by several reasons, such as:
 - the sensor cannot deliver the accuracy at the defined confidence level because it is a low-end sensor,
 - the sensor cannot calculate the accuracy due to lack of variables, or
 - there has been a vehicle bus (e.g. CAN bus) error.
 In all 3 cases above, the position coordinate value may be valid and used by the application.
 If a position coordinate value is received and its confidence value is set to `outOfRange(4094)`, it means that
 the position coordinate value is not valid and therefore cannot be trusted. Such value is not useful
 for the application.
>>>
```asn1
SemiAxisLength ::= INTEGER{
    doNotUse    (0),
    outOfRange  (4094), 
    unavailable (4095)
} (0..4095)
```

### <a name="SensorType"></a>SensorType
This DE indicates the type of sensor.
 
 The value shall be set to:
 - 0  `undefined`         - in case the sensor type is undefined. 
 - 1  `radar`             - in case the sensor is a radar,
 - 2  `lidar`             - in case the sensor is a lidar,
 - 3  `monovideo`         - in case the sensor is mono video,
 - 4  `stereovision`      - in case the sensor is stereo vision,
 - 5  `nightvision`       - in case the sensor is night vision,
 - 6  `ultrasonic`        - in case the sensor is ultrasonic,
 - 7  `pmd`               - in case the sensor is photonic mixing device,
 - 8  `inductionLoop`     - in case the sensor is an induction loop,
 - 9  `sphericalCamera`   - in case the sensor is a spherical camera,
 - 10 `uwb`               - in case the sensor is ultra wide band,
 - 11 `acoustic`          - in case the sensor is acoustic,
 - 12 `localAggregation`  - in case the information is provided by a system that aggregates information from different local sensors. Aggregation may include fusion,
 - 13 `itsAggregation`    - in case the information is provided by a system that aggregates information from other received ITS messages.
 - 14-31                  - are reserved for future usage.

* **undefined** (0)<br>
* **radar** (1)<br>
* **lidar** (2)<br>
* **monovideo** (3)<br>
* **stereovision** (4)<br>
* **nightvision** (5)<br>
* **ultrasonic** (6)<br>
* **pmd** (7)<br>
* **inductionLoop** (8)<br>
* **sphericalCamera** (9)<br>
* **uwb** (10)<br>
* **acoustic** (11)<br>
* **localAggregation** (12)<br>
* **itsAggregation** (13)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Sensing Information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _created in V2.1.1_
```asn1
SensorType ::= INTEGER {
    undefined         (0),
    radar             (1),
    lidar             (2),
    monovideo         (3),
    stereovision      (4),
    nightvision       (5),
    ultrasonic        (6),
    pmd               (7),
    inductionLoop     (8),
    sphericalCamera   (9),
    uwb               (10),
    acoustic          (11),
    localAggregation  (12),
    itsAggregation    (13)
} (0..31)
```

### <a name="SequenceNumber"></a>SequenceNumber
This DE represents a sequence number.

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Basic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V1.3.1_
```asn1
SequenceNumber ::=  INTEGER (0..65535)
```

### <a name="SignalViolationSubCauseCode"></a>SignalViolationSubCauseCode
This DE represents the value of the sub cause codes of the [**CauseCode**](#CauseCode) `signalViolation`.
 
 The value shall be set to:
 - 0 `unavailable`               - in case further detailed information on signal violation event is unavailable,
 - 1 `stopSignViolation`         - in case a stop sign violation is detected,
 - 2 `trafficLightViolation`     - in case a traffic light violation is detected,
 - 3 `turningRegulationViolation`- in case a turning regulation violation is detected.
 - 4-255                         - are reserved for future usage.

* **unavailable** (0)<br>
* **stopSignViolation** (1)<br>
* **trafficLightViolation** (2)<br>
* **turningRegulationViolation** (3)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Traffic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V1.3.1_
```asn1
SignalViolationSubCauseCode ::= INTEGER {
    unavailable                (0), 
    stopSignViolation          (1), 
    trafficLightViolation      (2), 
    turningRegulationViolation (3)
} (0..255)
```

### <a name="SlowVehicleSubCauseCode"></a>SlowVehicleSubCauseCode
This DE represents the sub cause codes of the [**CauseCode**](#CauseCode) "slowVehicle".
 
 The value shall be set to:
 - 0 `unavailable`                    - in case further detailed information on slow vehicle driving event is
                                        unavailable,
 - 1 `maintenanceVehicle`             - in case of a slow driving maintenance vehicle on the road,
 - 2 `vehiclesSlowingToLookAtAccident`- in case vehicle is temporally slowing down to look at accident, spot, etc.,
 - 3 `abnormalLoad`                   - in case an abnormal loaded vehicle is driving slowly on the road,
 - 4 `abnormalWideLoad`               - in case an abnormal wide load vehicle is driving slowly on the road,
 - 5 `convoy`                         - in case of slow driving convoy on the road,
 - 6 `snowplough`                     - in case of slow driving snow plough on the road,
 - 7 `deicing`                        - in case of slow driving de-icing vehicle on the road,
 - 8 `saltingVehicles`                - in case of slow driving salting vehicle on the road.
 - 9-255                              - are reserved for future usage.

* **unavailable** (0)<br>
* **maintenanceVehicle** (1)<br>
* **vehiclesSlowingToLookAtAccident** (2)<br>
* **abnormalLoad** (3)<br>
* **abnormalWideLoad** (4)<br>
* **convoy** (5)<br>
* **snowplough** (6)<br>
* **deicing** (7)<br>
* **saltingVehicles** (8)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Traffic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V1.3.1_
```asn1
SlowVehicleSubCauseCode ::= INTEGER {
    unavailable                     (0), 
    maintenanceVehicle              (1), 
    vehiclesSlowingToLookAtAccident (2), 
    abnormalLoad                    (3), 
    abnormalWideLoad                (4), 
    convoy                          (5), 
    snowplough                      (6), 
    deicing                         (7), 
    saltingVehicles                 (8)
} (0..255)
```

### <a name="SpecialTransportType"></a>SpecialTransportType
The DE indicates if a vehicle is carrying goods in the special transport conditions.

 The corresponding bit shall be set to 1 under the following conditions:
 - 0 `heavyLoad`        - the vehicle is carrying goods with heavy load,
 - 1 `excessWidth`      - the vehicle is carrying goods in excess of width,
 - 2 `excessLength`     - the vehicle is carrying goods in excess of length,
 - 3 `excessHeight`     - the vehicle is carrying goods in excess of height.

 Otherwise, the corresponding bit shall be set to 0.

* **heavyLoad** (0)<br>
* **excessWidth** (1)<br>
* **excessLength** (2)<br>
* **excessHeight** (3)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Vehicle information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Description revised in V2.1.1_
```asn1
SpecialTransportType ::= BIT STRING {
    heavyLoad    (0),
    excessWidth  (1), 
    excessLength (2), 
    excessHeight (3)
} (SIZE(4))
```

### <a name="SpeedConfidence"></a>SpeedConfidence
This DE indicates the speed confidence value which represents the estimated absolute accuracy of a speed value with a default confidence level of 95 %.
 If required, the confidence level can be defined by the corresponding standards applying this DE.
 
 The value shall be set to:
 - `n` (`n > 0` and `n < 126`) if the confidence value is equal to or less than n * 0,01 m/s.
 - `126` if the confidence value is out of range, i.e. greater than 1,25 m/s,
 - `127` if the confidence value information is not available.

* **outOfRange** (126)<br>
* **unavailable** (127)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _0,01 m/s_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Vehicle information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Description revised in V2.1.1_

>>>
NOTE:&emsp;If a speed value is received and its confidence value is set to `outOfRange(126)`, it means that the speed value is not valid 
 and therefore cannot be trusted. Such is not useful for the application.
>>>
```asn1
SpeedConfidence ::= INTEGER {
    outOfRange  (126), 
    unavailable (127)
} (1..127)
```

### <a name="SpeedLimit"></a>SpeedLimit
This DE represents a speed limitation applied to a geographical position, a road section or a geographical region.

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _km/h_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Infrastructure information Traffic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V1.3.1_
```asn1
SpeedLimit ::= INTEGER (1..255)
```

### <a name="SpeedValue"></a>SpeedValue
This DE represents a speed value, i.e. the magnitude of the velocity-vector. 

 The value shall be set to:
 - `0` in a standstill situation.
 - `n` (`n > 0` and `n < 16 382`) if the applicable value is equal to or less than n x 0,01 m/s, and greater than (n-1) x 0,01 m/s,
 - `16 382` for speed values greater than 163,81 m/s,
 - `16 383` if the speed accuracy information is not available.

* **standstill** (0)<br>
* **outOfRange** (16382)<br>
* **unavailable** (16383)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _0,01 m/s_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Kinematic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Description revised in V2.1.1 (the meaning of 16382 has changed slightly)_

>>>
NOTE:&emsp;the definition of standstill is out of scope of the present document.
>>>
```asn1
SpeedValue ::= INTEGER {
    standstill  (0), 
    outOfRange  (16382), 
    unavailable (16383)
} (0..16383)
```

### <a name="VelocityComponentValue"></a>VelocityComponentValue
This DE represents the value of a velocity component in a defined coordinate system.

 The value shall be set to:
 - `-16 383` if the velocity is equal to or smaller than -163,83 m/s,
 - `n` (`n > -16 383` and `n < 16 382`) if the applicable value is equal to or less than n x 0,01 m/s, and greater than (n-1) x 0,01 m/s,
 - `16 382` for velocity values equal to or greater than 163,81 m/s,
 - `16 383` if the velocity information is not available.

* **negativeOutOfRange** (-16383)<br>
* **positiveOutOfRange** (16382)<br>
* **unavailable** (16383)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _0,01 m/s_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Kinematic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
VelocityComponentValue ::= INTEGER {
    negativeOutOfRange (-16383),
    positiveOutOfRange  (16382),
    unavailable        (16383)
} (-16383..16383)
```

### <a name="StabilityLossProbability"></a>StabilityLossProbability
This DE indicates the estimated probability of a stability level and conversely also the probability of a stability loss.

 The value shall be set to:
 - `0` to indicate an estimated probability of a loss of stability of 0 %, i.e. "stable", 
 - `n` (`n > 0` and `n < 50`) to indicate the actual stability level,
 - `50` to indicate a estimated probability of a loss of stability of 100 %, i.e. "total loss of stability",
 - the values between 51 and 62 are reserved for future use,
 - `63`: this value indicates that the information is unavailable.

* **stable** (0)<br>
* **totalLossOfStability** (50)<br>
* **unavailable** (63)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _2 %_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Kinematic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
StabilityLossProbability ::= INTEGER {
    stable                  (0), 
    totalLossOfStability   (50), 
    unavailable            (63) 
} (0..63)
```

### <a name="StandardLength12b"></a>StandardLength12b
The DE represents length as a measure of distance between points or as a dimension of an object or shape.

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _0,1 metre_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Basic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
StandardLength12b::= INTEGER (0..4095)
```

### <a name="StandardLength3b"></a>StandardLength3b
The DE represents length as a measure of distance between points. 

 The value shall be set to:
 - 0 `lessThan50m`   - for distances below 50 m, 
 - 1 `lessThan100m`  - for distances below 100 m,
 - 2 `lessThan200m`  - for distances below 200 m, 
 - 3 `lessThan500m`  - for distances below 300 m, 
 - 4 `lessThan1000m` - for distances below 1 000 m,
 - 5 `lessThan5km`   - for distances below 5 000 m, 
 - 6 `lessThan10km`  - for distances below 10 000 m, 
 - 7 `over10km`      - for distances over 10 000 m.

* **lessThan50m** (0)<br>
* **lessThan100m** (1)<br>
* **lessThan200m** (2)<br>
* **lessThan500m** (3)<br>
* **lessThan1000m** (4)<br>
* **lessThan5km** (5)<br>
* **lessThan10km** (6)<br>
* **over10km** (7)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** GeoReference information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1 from RelevanceDistance_
```asn1
StandardLength3b ::= ENUMERATED {
    lessThan50m   (0), 
    lessThan100m  (1), 
    lessThan200m  (2), 
    lessThan500m  (3), 
    lessThan1000m (4), 
    lessThan5km   (5), 
    lessThan10km  (6), 
    over10km      (7)
}
```

### <a name="StandardLength9b"></a>StandardLength9b
The DE represents length as a measure of distance between points or as a dimension of an object.

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _0,1 metre_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Basic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
StandardLength9b::= INTEGER (0..511)
```

### <a name="StandardLength1B"></a>StandardLength1B
The DE represents length as a measure of distance between points or as a dimension of an object.

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _0,1 metre_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Basic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
StandardLength1B::= INTEGER (0..255)
```

### <a name="StandardLength2B"></a>StandardLength2B
The DE represents length as a measure of distance between points or as a dimension of an object.

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _0,1 metre_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Basic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
StandardLength2B::= INTEGER (0..65535)
```

### <a name="StationarySince"></a>StationarySince
This DE indicates the duration in minutes since which something is stationary.
 
 The value shall be set to:
 - 0 `lessThan1Minute`         - for being stationary since less than 1 minute, 
 - 1 `lessThan2Minutes`        - for being stationary since less than 2 minute and for equal to or more than 1 minute,
 - 2 `lessThan15Minutes`       - for being stationary since less than 15 minutes and for equal to or more than 1 minute,
 - 3 `equalOrGreater15Minutes` - for being stationary since equal to or more than 15 minutes.

* **lessThan1Minute** (0)<br>
* **lessThan2Minutes** (1)<br>
* **lessThan15Minutes** (2)<br>
* **equalOrGreater15Minutes** (3)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Kinematic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
StationarySince ::= ENUMERATED {
    lessThan1Minute         (0), 
    lessThan2Minutes        (1), 
    lessThan15Minutes       (2), 
    equalOrGreater15Minutes (3)
}
```

### <a name="StationaryVehicleSubCauseCode"></a>StationaryVehicleSubCauseCode
This DE provides the value of the sub cause codes of the [**CauseCode**](#CauseCode) "stationaryVehicle". 
 
 The value shall be set to:
 - 0 `unavailable`           - in case further detailed information on stationary vehicle is unavailable,
 - 1 `humanProblem`          - in case stationary vehicle is due to health problem of driver or passenger,
 - 2 `vehicleBreakdown`      - in case stationary vehicle is due to vehicle break down,
 - 3 `postCrash`             - in case stationary vehicle is caused by collision,
 - 4 `publicTransportStop`   - in case public transport vehicle is stationary at bus stop,
 - 5 `carryingDangerousGoods`- in case the stationary vehicle is carrying dangerous goods,
 - 6 `vehicleOnFire`         - in case of vehicle on fire.
 - 7-255 reserved for future usage.

* **unavailable** (0)<br>
* **humanProblem** (1)<br>
* **vehicleBreakdown** (2)<br>
* **postCrash** (3)<br>
* **publicTransportStop** (4)<br>
* **carryingDangerousGoods** (5)<br>
* **vehicleOnFire** (6)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Traffic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V1.3.1_
```asn1
StationaryVehicleSubCauseCode ::= INTEGER {
    unavailable            (0), 
    humanProblem           (1), 
    vehicleBreakdown       (2), 
    postCrash              (3), 
    publicTransportStop    (4), 
    carryingDangerousGoods (5), 
    vehicleOnFire          (6)
} (0..255)
```

### <a name="StationId"></a>StationId
This DE represents the identifier of an ITS-S.
 The ITS-S ID may be a pseudonym. It may change over space and/or over time.

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Basic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1 based on [**StationID**](#StationID)_
```asn1
StationId ::= INTEGER(0..4294967295)
```

### <a name="StationID"></a>StationID
This DE represents the identifier of an ITS-S.
 The ITS-S ID may be a pseudonym. It may change over space and/or over time.

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Basic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V1.3.1_

>>>
NOTE:&emsp;this DE is kept for backwards compatibility reasons only. It is recommended to use the [**StationId**](ETSI-ITS-CDD.md#StationId) instead.
>>>
```asn1
StationID ::= INTEGER(0..4294967295)
```

### <a name="StationType"></a>StationType
This DE represents the type of technical context the ITS-S is integrated in.
 The station type depends on the integration environment of ITS-S into vehicle, mobile devices or at infrastructure.
 
 The value shall be set to:
 - 0 `unknown`          - information about the ITS-S context is not provided,
 - 1 `pedestrian`       - ITS-S carried by human being not using a mechanical device for their trip (VRU profile 1),
 - 2 `cyclist`          - ITS-S mounted on non-motorized unicycles, bicycles , tricycles, quadracycles (VRU profile 2),
 - 3 `moped`            - ITS-S mounted on light motor vehicles with less than four wheels as defined in UNECE/TRANS/WP.29/78/Rev.4 [[16]](#references) 
                            class L1, L2 (VRU Profile 3),
 - 4 `motorcycles`      - ITS-S mounted on motor vehicles with less than four wheels as defined in UNECE/TRANS/WP.29/78/Rev.4 [[16]](#references) 
                            class L3, L4, L5, L6, L7 (VRU Profile 3),
 - 5 `passengerCar`     - ITS-S mounted on small passenger vehicles as defined in UNECE/TRANS/WP.29/78/Rev.4 [[16]](#references) class M1,
 - 6 `bus`              - ITS-S mounted on large passenger vehicles as defined in UNECE/TRANS/WP.29/78/Rev.4 [[16]](#references) class M2, M3,
 - 7 `lightTruck`       - ITS-S mounted on light Goods Vehicles as defined in UNECE/TRANS/WP.29/78/Rev.4 [[16]](#references) class N1,
 - 8 `heavyTruck`       - ITS-S mounted on Heavy Goods Vehicles as defined in UNECE/TRANS/WP.29/78/Rev.4 [[16]](#references) class N2 and N3,
 - 9 `trailer`          - ITS-S mounted on an unpowered vehicle that is intended to be towed by a powered vehicle as defined in 
                            UNECE/TRANS/WP.29/78/Rev.4 [[16]](#references) class O,
 - 10 `specialVehicles` - ITS-S mounted on vehicles which have special purposes other than the above (e.g. moving road works vehicle),
 - 11 `tram`            - ITS-S mounted on a vehicle which runs on tracks along public streets,
 - 12 `lightVruVehicle` - ITS-S carried by a human being traveling on light vehicle , incl. possible use of roller skates or skateboards (VRU profile 2),
 - 13 `animal`          - ITS-S carried by an animal presenting a safety risk to other road users e.g. domesticated dog in a city or horse (VRU Profile 4),
 - 14                   - reserved for future usage,
 - 15 `roadSideUnit`    - ITS-S mounted on an infrastructure typically positioned outside of the drivable roadway (e.g. on a gantry, on a pole, 
                            on a stationary road works trailer); the infrastructure is static during the entire operation period of the ITS-S (e.g. no stop and go activity),
 - 16-255               - are reserved for future usage.

* **unknown** (0)<br>
* **pedestrian** (1)<br>
* **cyclist** (2)<br>
* **moped** (3)<br>
* **motorcycle** (4)<br>
* **passengerCar** (5)<br>
* **bus** (6)<br>
* **lightTruck** (7)<br>
* **heavyTruck** (8)<br>
* **trailer** (9)<br>
* **specialVehicle** (10)<br>
* **tram** (11)<br>
* **lightVruVehicle** (12)<br>
* **animal** (13)<br>
* **roadSideUnit** (15)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Communication information. 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _revised in V2.1.1 (named values 12 and 13 added and note to value 9 deleted)_

>>>
NOTE:&emsp;this DE is kept for backwards compatibility reasons only. It is recommended to use the [**TrafficParticipantType**](#TrafficParticipantType) instead.
>>>
```asn1
StationType ::= INTEGER {
    unknown         (0), 
    pedestrian      (1), 
    cyclist         (2), 
    moped           (3), 
    motorcycle      (4), 
    passengerCar    (5), 
    bus             (6), 
    lightTruck      (7), 
    heavyTruck      (8), 
    trailer         (9), 
    specialVehicle  (10), 
    tram            (11), 
    lightVruVehicle (12), 
    animal          (13), 
    roadSideUnit    (15)
} (0..255)
```

### <a name="SteeringWheelAngleConfidence"></a>SteeringWheelAngleConfidence
This DE indicates the steering wheel angle confidence value which represents the estimated absolute accuracy for a  steering wheel angle value with a confidence level of 95 %.
 
 The value shall be set to:
 - `n` (`n > 0` and `n < 126`) if the confidence value is equal to or less than n x 1,5 degrees,
 - `126` if the confidence value is out of range, i.e. greater than 187,5 degrees,
 - `127` if the confidence value is not available.

 
 If a steering wheel angle value is received and its confidence value is set to `outOfRange(126)`,
 it means that the steering wheel angle value is not valid and therefore cannot be trusted.
 Such value is not useful for the application.

* **outOfRange** (126)<br>
* **unavailable** (127)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _1,5 degree_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Vehicle Information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Description revised in V2.1.1_

>>>
NOTE:&emsp;The fact that a steering wheel angle value is received with confidence value set to `unavailable(127)`
 can be caused by several reasons, such as:
 - the sensor cannot deliver the accuracy at the defined confidence level because it is a low-end sensor,
 - the sensor cannot calculate the accuracy due to lack of variables, or
 - there has been a vehicle bus (e.g. CAN bus) error.
 In all 3 cases above, the steering wheel angle value may be valid and used by the application.
>>>
```asn1
SteeringWheelAngleConfidence ::= INTEGER {
    outOfRange                      (126), 
    unavailable                     (127)
} (1..127)
```

### <a name="SteeringWheelAngleValue"></a>SteeringWheelAngleValue
This DE represents the steering wheel angle of the vehicle at certain point in time.
 The value shall be provided in the vehicle coordinate system as defined in ISO 8855 [[21]](#references), clause 2.11.
 
 The value shall be set to:
 - `-511` if the steering wheel angle is equal to or greater than 511 x 1,5 degrees = 766,5 degrees to the right,
 - `n` (`n > -511` and `n ≤ 0`) if  the steering wheel angle is equal to or less than n x 1,5 degrees, and greater than (n-1) x 1,5 degrees, 
      turning clockwise (i.e. to the right),
 - `n` (`n ≥ 1` and `n < 511`) if the steering wheel angle is equal to or less than n x 0,1 degrees, and greater than (n-1) x 0,1 degrees, 
      turning counter-clockwise (i.e. to the left),
 - `511` if the steering wheel angle is greater than 510 x 1,5 degrees = 765 degrees to the left,
 - `512` if information is not available.

* **negativeOutOfRange** (-511)<br>
* **positiveOutOfRange** (511)<br>
* **unavailable** (512)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _1,5 degree_

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Description revised in V2.1.1 (meaning of value 511 has changed slightly)._
```asn1
SteeringWheelAngleValue ::= INTEGER { 
    negativeOutOfRange (-511),
    positiveOutOfRange (511),
    unavailable        (512)
} (-511..512)
```

### <a name="SubCauseCodeType"></a>SubCauseCodeType
This DE indicates the generic sub cause of a detected event.

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Traffic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Description revised in V2.1.1 (this is  the generic sub cause type)_

>>>
NOTE:&emsp;The sub cause code value assignment varies based on value of [**CauseCode**](#CauseCode).
>>>
```asn1
SubCauseCodeType ::= INTEGER (0..255)
```

### <a name="Temperature"></a>Temperature
This DE indicates a temperature value.
 The value shall be set to:
 - `-60` for temperature equal to or less than -60 degrees C,
 - `n` (`n > -60` and `n < 67`) for the actual temperature n in degrees C,
 - `67` for temperature equal to or greater than 67 degrees C.

* **equalOrSmallerThanMinus60Deg** (-60)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _degrees Celsius_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Basic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Editorial update in V2.1.1_
```asn1
Temperature ::= INTEGER {
    equalOrSmallerThanMinus60Deg (-60), 
    equalOrGreaterThan67Deg(67)} (-60..67)
```

### <a name="TimestampIts"></a>TimestampIts
This DE represents the number of elapsed (TAI) milliseconds since the ITS Epoch. 
 The ITS epoch is `00:00:00.000 UTC, 1 January 2004`.
 "Elapsed" means that the true number of milliseconds is continuously counted without interruption,
  i.e. it is not altered by leap seconds, which occur in UTC.

 
 EXAMPLE: The value for TimestampIts for 1 January 2007 00:00:00.000 UTC is `94 694 401 000` milliseconds,
 which includes one leap second insertion since the ITS epoch.

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _0,001 s_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Basic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Description revised in in V2.1.1_

>>>
NOTE:&emsp;International Atomic Time (TAI) is the time reference coordinate on the basis of the readings of atomic clocks, 
 operated in accordance with the definition of the second, the unit of time of the International System of Units. 
 TAI is a continuous time scale. UTC has discontinuities, as it is occasionally adjusted by leap seconds. 
 As of 1 January, 2022, TimestampIts is 5 seconds ahead of UTC, because since the ITS epoch on 1 January 2004 00:00:00.000 UTC, 
 further 5 leap seconds have been inserted in UTC.
>>>
```asn1
TimestampIts ::= INTEGER (0..4398046511103)
```

### <a name="TrafficConditionSubCauseCode"></a>TrafficConditionSubCauseCode
This DE represents the value of the sub cause codes of the [**CauseCode**](#CauseCode) `trafficCondition`. 
 
 The value shall be set to:
 - 0 `unavailable`                 - in case further detailed information on traffic jam is unavailable,
 - 1 `increasedVolumeOfTraffic`    - in case detected jam volume is increased,
 - 2 `trafficJamSlowlyIncreasing`  - in case detected traffic jam volume is increasing slowly,
 - 3 `trafficJamIncreasing`        - in case traffic jam volume is increasing,
 - 4 `trafficJamStronglyIncreasing`- in case traffic jam volume is strongly increasing,
 - 5 `trafficStationary`           - in case traffic is stationary,
 - 6 `trafficJamSlightlyDecreasing`- in case traffic jam volume is decreasing slowly,
 - 7 `trafficJamDecreasing`        - in case traffic jam volume is decreasing,
 - 8 `trafficJamStronglyDecreasing`- in case traffic jam volume is decreasing rapidly,
 - 9-255: reserved for future usage.

* **unavailable** (0)<br>
* **increasedVolumeOfTraffic** (1)<br>
* **trafficJamSlowlyIncreasing** (2)<br>
* **trafficJamIncreasing** (3)<br>
* **trafficJamStronglyIncreasing** (4)<br>
* **trafficStationary** (5)<br>
* **trafficJamSlightlyDecreasing** (6)<br>
* **trafficJamDecreasing** (7)<br>
* **trafficJamStronglyDecreasing** (8)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Traffic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V1.3.1_
```asn1
TrafficConditionSubCauseCode ::= INTEGER {
    unavailable                  (0),
    increasedVolumeOfTraffic     (1),
    trafficJamSlowlyIncreasing   (2),
    trafficJamIncreasing         (3),
    trafficJamStronglyIncreasing (4),
    trafficStationary            (5),
    trafficJamSlightlyDecreasing (6),
    trafficJamDecreasing         (7),
    trafficJamStronglyDecreasing (8)
} (0..255)
```

### <a name="TrafficDirection"></a>TrafficDirection
This DE indicates a traffic direction that is relevant to information indicated in a message.
 
 The value shall be set to:
 - 0 `allTrafficDirections` - for all traffic directions, 
 - 1 `upstreamTraffic`      - for upstream traffic, 
 - 2 `downstreamTraffic`    - for downstream traffic, 
 - 3 `oppositeTraffic`      - for traffic in the opposite direction. 

 The terms `upstream`, `downstream` and `oppositeTraffic` are relative to the event position.

* **allTrafficDirections** (0)<br>
* **upstreamTraffic** (1)<br>
* **downstreamTraffic** (2)<br>
* **oppositeTraffic** (3)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** GeoReference information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1 from RelevanceTrafficDirection_

>>>
NOTE:&emsp;Upstream traffic corresponds to the incoming traffic towards the event position,
 and downstream traffic to the departing traffic away from the event position.
>>>
```asn1
TrafficDirection ::= ENUMERATED {
    allTrafficDirections (0), 
    upstreamTraffic      (1), 
    downstreamTraffic    (2), 
    oppositeTraffic      (3)
}
```

### <a name="TrafficParticipantType"></a>TrafficParticipantType
This DE represents the type of a traffic participant.
 
 The value shall be set to:
 - 0 `unknown`          - information about traffic participant is not provided,
 - 1 `pedestrian`       - human being not using a mechanical device for their trip (VRU profile 1),
 - 2 `cyclist`          - non-motorized unicycles, bicycles , tricycles, quadracycles (VRU profile 2),
 - 3 `moped`            - light motor vehicles with less than four wheels as defined in UNECE/TRANS/WP.29/78/Rev.4 [[16]](#references) class L1, L2 (VRU Profile 3),
 - 4 `motorcycles`      - motor vehicles with less than four wheels as defined in UNECE/TRANS/WP.29/78/Rev.4 [[16]](#references) class L3, L4, L5, L6, L7 (VRU Profile 3),
 - 5 `passengerCar`     - small passenger vehicles as defined in UNECE/TRANS/WP.29/78/Rev.4 [[16]](#references) class M1,
 - 6 `bus`              - large passenger vehicles as defined in UNECE/TRANS/WP.29/78/Rev.4 [[16]](#references) class M2, M3,
 - 7 `lightTruck`       - light Goods Vehicles as defined in UNECE/TRANS/WP.29/78/Rev.4 [[16]](#references) class N1,
 - 8 `heavyTruck`       - Heavy Goods Vehicles as defined in UNECE/TRANS/WP.29/78/Rev.4 [[16]](#references) class N2 and N3,
 - 9 `trailer`          - unpowered vehicle that is intended to be towed by a powered vehicle as defined in UNECE/TRANS/WP.29/78/Rev.4 [[16]](#references) class O,
 - 10 `specialVehicles` - vehicles which have special purposes other than the above (e.g. moving road works vehicle),
 - 11 `tram`            - vehicle which runs on tracks along public streets,
 - 12 `lightVruVehicle` - human being traveling on light vehicle, incl. possible use of roller skates or skateboards (VRU profile 2),
 - 13 `animal`          - animal presenting a safety risk to other road users e.g. domesticated dog in a city or horse (VRU Profile 4),
 - 14 `agricultural`    - agricultural and forestry vehicles as defined in UNECE/TRANS/WP.29/78/Rev.4 [[16]](#references) class T,
 - 15 `roadSideUnit`    - infrastructure typically positioned outside of the drivable roadway (e.g. on a gantry, on a pole, 
                            on a stationary road works trailer); the infrastructure is static during the entire operation period of the ITS-S (e.g. no stop and go activity),
 - 16-255               - are reserved for future usage.

* **unknown** (0)<br>
* **pedestrian** (1)<br>
* **cyclist** (2)<br>
* **moped** (3)<br>
* **motorcycle** (4)<br>
* **passengerCar** (5)<br>
* **bus** (6)<br>
* **lightTruck** (7)<br>
* **heavyTruck** (8)<br>
* **trailer** (9)<br>
* **specialVehicle** (10)<br>
* **tram** (11)<br>
* **lightVruVehicle** (12)<br>
* **animal** (13)<br>
* **agricultural** (14)<br>
* **roadSideUnit** (15)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Communication information. 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1 based on StationType_
```asn1
TrafficParticipantType ::= INTEGER {
    unknown         (0), 
    pedestrian      (1), 
    cyclist         (2), 
    moped           (3), 
    motorcycle      (4), 
    passengerCar    (5), 
    bus             (6), 
    lightTruck      (7), 
    heavyTruck      (8), 
    trailer         (9), 
    specialVehicle  (10), 
    tram            (11), 
    lightVruVehicle (12), 
    animal          (13),
    agricultural    (14), 
    roadSideUnit    (15)
} (0..255)
```

### <a name="TrafficRule"></a>TrafficRule
This DE indicates traffic rules that apply to vehicles at a certain position.

 The value shall be set to:
 - `0` - if overtaking is prohibited for all vehicles,
 - `1` - if overtaking is prohibited for trucks,
 - `2` - if vehicles should pass to the right lane,
 - `3` - if vehicles should pass to the left lane.

* **noPassing** (0)<br>
* **noPassingForTrucks** (1)<br>
* **passToRight** (2)<br>
* **passToLeft** (3)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Infrastructure information Traffic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Editorial update in V2.1.1_
```asn1
TrafficRule ::= ENUMERATED {
    noPassing          (0), 
    noPassingForTrucks (1), 
    passToRight        (2), 
    passToLeft         (3), 
 ...}
```

### <a name="TrailerPresenceInformation"></a>TrailerPresenceInformation
This DE provides information about the presence of a trailer. 

 The value shall be set to:
 - 0 `noTrailerPresent`                - to indicate that no trailer is present, i.e. either the vehicle is physically not enabled to tow a trailer or it has been detected that no trailer is present.
 - 1 `trailerPresentWithKnownLength`   - to indicate that a trailer has been detected as present and the length is included in the vehicle length value.
 - 2 `trailerPresentWithUnknownLength` - to indicate that a trailer has been detected as present and the length is not included in the vehicle length value.
 - 3 `trailerPresenceIsUnknown`        - to indicate that information about the trailer presence is unknown, i.e. the vehicle is physically enabled to tow a trailer but the detection of trailer presence/absence is not possible.
 - 4 `unavailable`                     - to indicate that the information about the presence of a trailer is not available, i.e. it is neither known whether the vehicle is able to tow a trailer 
                                         nor the detection of trailer presence/absence is possible.

* **noTrailerPresent** (0)<br>
* **trailerPresentWithKnownLength** (1)<br>
* **trailerPresentWithUnknownLength** (2)<br>
* **trailerPresenceIsUnknown** (3)<br>
* **unavailable** (4)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Vehicle information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1 based on VehicleLengthConfidenceIndication_
```asn1
TrailerPresenceInformation ::= ENUMERATED {
    noTrailerPresent                (0), 
    trailerPresentWithKnownLength   (1), 
    trailerPresentWithUnknownLength (2), 
    trailerPresenceIsUnknown        (3), 
    unavailable                     (4)
}
```

### <a name="TrajectoryInterceptionProbability"></a>TrajectoryInterceptionProbability
This  DE  defines  the  probability  that the ego trajectory  intercepts  with any  other object's  trajectory  on the  road. 
 
 The value shall be set to:
 - `n` (`n ≥ 0` and `n ≤ 50`) to indicate the actual probability,
 - the values between 51 and 62 are reserved,
 - `63`: to indicate that the information is unavailable.

* **unavailable** (63)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _2 %_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Kinematic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
TrajectoryInterceptionProbability ::= INTEGER { 
    unavailable (63) 
} (0..63)
```

### <a name="TrajectoryInterceptionConfidence"></a>TrajectoryInterceptionConfidence
This DE  defines  the  confidence level of the trajectoryInterceptionProbability.

 The value shall be set to:
 - `0` - to indicate confidence level less than 50 %,
 - `1` - to indicate confidence level greater than or equal to 50 % and less than 70 %,
 - `2` - to indicate confidence level greater than or equal to 70 % and less than 90 %,
 - `3` - to indicate confidence level greater than or equal to 90%.

* **lessthan50percent** (0)<br>
* **between50and70Percent** (1)<br>
* **between70and90Percent** (2)<br>
* **above90Percent** (3)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Kinematic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
TrajectoryInterceptionConfidence ::= INTEGER { 
    lessthan50percent     (0), 
    between50and70Percent (1),
    between70and90Percent (2), 
    above90Percent        (3) 
} (0..3)
```

### <a name="TransmissionInterval"></a>TransmissionInterval
This DE represents the time interval between two consecutive message transmissions.

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _0,001 s_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Basic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V1.3.1_

>>>
NOTE:&emsp;this DE is kept for backwards compatibility reasons only. It is recommended to use the [**DeltaTimeMilliSecondPos**](#DeltaTimeMilliSecondPos) instead.
>>>
```asn1
TransmissionInterval::= INTEGER (1..10000)
```

### <a name="TurningDirection"></a>TurningDirection
This DE provides the turning direction. 
 
 The value shall be set to:
 - `left`  for turning to te left.
 - `right` for turing to the right.

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Kinematic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
TurningDirection::= ENUMERATED {
    left, 
    right 
}
```

### <a name="TurningRadius"></a>TurningRadius
This DE represents the smallest circular turn (i.e. U-turn) that the vehicle is capable of making.

 The value shall be set to:
 - `n` (`n > 0` and `n < 254`) to indicate the applicable value is equal to or less than n x 0,4 metre, and greater than (n-1) x 0,4 metre,
 - `254` to indicate that the turning radius is  greater than 253 x 0,4 metre = 101.2 metres,
 - `255` to indicate that the information is unavailable.
 
 For vehicle with tracker, the turning radius applies to the vehicle only.

* **outOfRange** (254)<br>
* **unavailable** (255)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _0,4 metre_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Vehicle information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Description revised V2.1.1 (the meaning of 254 has changed slightly)_
```asn1
TurningRadius ::= INTEGER {
    outOfRange  (254),
    unavailable (255)
} (1..255)
```

### <a name="ValidityDuration"></a>ValidityDuration
This DE represents the duration of a traffic event validity.

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _1 s_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Basic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V1.3.1_

>>>
NOTE:&emsp;this DE is kept for backwards compatibility reasons only. It is recommended to use the [**DeltaTimeSecond**](#DeltaTimeSecond) instead.
>>>
```asn1
ValidityDuration::= INTEGER {
   timeOfDetection(0),
   oneSecondAfterDetection(1)
} (0..86400)
```

### <a name="VDS"></a>VDS
This DE represents the Vehicle Descriptor Section (VDS). The values are assigned according to ISO 3779 [[6]](#references).

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Vehicle information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V1.3.1_
```asn1
VDS ::= IA5String (SIZE(6))
```

### <a name="VehicleBreakdownSubCauseCode"></a>VehicleBreakdownSubCauseCode
This DE represents the value of the sub cause codes of the [**CauseCode**](#CauseCode) `vehicleBreakdown`. 
 
 The value shall be set to:
 - 0 `unavailable`         - in case further detailed information on cause of vehicle break down is unavailable,
 - 1 `lackOfFuel`          - in case vehicle break down is due to lack of fuel,
 - 2 `lackOfBatteryPower`  - in case vehicle break down is caused by lack of battery power,
 - 3 `engineProblem`       - in case vehicle break down is caused by an engine problem,
 - 4 `transmissionProblem` - in case vehicle break down is caused by transmission problem,
 - 5 `engineCoolingProblem`- in case vehicle break down is caused by an engine cooling problem,
 - 6 `brakingSystemProblem`- in case vehicle break down is caused by a braking system problem,
 - 7 `steeringProblem`     - in case vehicle break down is caused by a steering problem,
 - 8 `tyrePuncture`        - in case vehicle break down is caused by tyre puncture,
 - 9 `tyrePressureProblem` - in case low tyre pressure in detected,
 - 10 `vehicleOnFire`      - in case the vehicle is on fire.
 - 11-255                  - are reserved for future usage.

* **unavailable** (0)<br>
* **lackOfFuel** (1)<br>
* **lackOfBatteryPower** (2)<br>
* **engineProblem** (3)<br>
* **transmissionProblem** (4)<br>
* **engineCoolingProblem** (5)<br>
* **brakingSystemProblem** (6)<br>
* **steeringProblem** (7)<br>
* **tyrePuncture** (8)<br>
* **tyrePressureProblem** (9)<br>
* **vehicleOnFire** (10)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Traffic information 
```asn1
VehicleBreakdownSubCauseCode ::= INTEGER {
    unavailable          (0), 
    lackOfFuel           (1), 
    lackOfBatteryPower   (2), 
    engineProblem        (3), 
    transmissionProblem  (4), 
    engineCoolingProblem (5), 
    brakingSystemProblem (6), 
    steeringProblem      (7), 
    tyrePuncture         (8), 
    tyrePressureProblem  (9), 
    vehicleOnFire        (10)
} (0..255)
```

### <a name="VehicleHeight"></a>VehicleHeight
This DE represents the height of the vehicle, measured from the ground to the highest point, excluding any antennas.
 In case vehicles are equipped with adjustable ride heights, camper shells, and any other
 equipment which may result in varying height, the largest possible height shall be used.

 The value shall be set to:
 - `n` (`n >0` and `n < 127`) indicates the applicable value is equal to or less than n x 0,05 metre, and greater than (n-1) x 0,05 metre,
 - `127` indicates that the vehicle width is greater than 6,3 metres,
 - `128` indicates that the information in unavailable.

* **outOfRange** (126)<br>
* **unavailable** (127)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _0,05 metre_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Vehicle information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _created in V2.1.1_
```asn1
VehicleHeight ::= INTEGER {
    outOfRange  (126),  
    unavailable (127)
}(1..128)
```

### <a name="VehicleLengthConfidenceIndication"></a>VehicleLengthConfidenceIndication
This DE provides information about the presence of a trailer. 

 The value shall be set to:
 - 0 `noTrailerPresent`                - to indicate that no trailer is present, i.e. either the vehicle is physically not enabled to tow a trailer or it has been detected that no trailer is present,
 - 1 `trailerPresentWithKnownLength`   - to indicate that a trailer has been detected as present and the length is  included in the vehicle length value,
 - 2 `trailerPresentWithUnknownLength` - to indicate that a trailer has been detected as present and the length is not included in the vehicle length value,
 - 3 `trailerPresenceIsUnknown`        - to indicate that information about the trailer presence is unknown, i.e. the vehicle is physically enabled to tow a trailer but the detection of trailer presence/absence is not possible,
 - 4 `unavailable`                     - to indicate that the information about the presence of a trailer is not available, i.e. it is neither known whether the vehicle is able to tow a trailer, 
                                        nor the detection of trailer presence/absence is possible.

* **noTrailerPresent** (0)<br>
* **trailerPresentWithKnownLength** (1)<br>
* **trailerPresentWithUnknownLength** (2)<br>
* **trailerPresenceIsUnknown** (3)<br>
* **unavailable** (4)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Vehicle information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Description revised in V2.1.1_

>>>
NOTE:&emsp;this DE is kept for backwards compatibility reasons only. It is recommended to use the [**TrailerPresenceInformation**](#TrailerPresenceInformation) instead.
>>>
```asn1
VehicleLengthConfidenceIndication ::= ENUMERATED {
    noTrailerPresent                (0), 
    trailerPresentWithKnownLength   (1), 
    trailerPresentWithUnknownLength (2), 
    trailerPresenceIsUnknown        (3), 
    unavailable                     (4)
}
```

### <a name="VehicleLengthValue"></a>VehicleLengthValue
This DE represents the length of a vehicle.

 The value shall be set to:
 - `n` (`n > 0` and `n < 1022`) to indicate the applicable value n is equal to or less than n x 0,1 metre, and greater than (n-1) x 0,1 metre,
 - `1 022` to indicate that the vehicle length is greater than 102.1 metres,
 - `1 023` to indicate that the information in unavailable.

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _0,1 metre_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Vehicle information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Description updated in V2.1.1 (the meaning of 1 022 has changed slightly)._
```asn1
VehicleLengthValue ::= INTEGER {
    outOfRange(1022), 
    unavailable(1023)
}  (1..1023)
```

### <a name="VehicleMass"></a>VehicleMass
This DE represents the mass of an empty loaded vehicle.

 The value shall be set to: 
 - `n` (`n > 0` and `n < 1023`) to indicate that the applicable value is equal to or less than n x 10<sup>5</sup> gramm, and greater than (n-1) x 10<sup>5</sup> gramm,
 - `1 023` indicates that the vehicle mass is greater than 102 200 000 g,
 - `1 024` indicates  the vehicle mass information is unavailable.

* **outOfRange** (1023)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _10<sup>5</sup> gramm_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Vehicle information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Description updated in V2.1.1 (the meaning of 1 023 has changed slightly)._

>>>
NOTE:&emsp;The empty load vehicle is defined in ISO 1176 [[8]](#references), clause 4.6.
>>>
```asn1
VehicleMass ::= INTEGER {
    outOfRange (1023), 
    unavailable(1024)
} (1..1024)
```

### <a name="VehicleRole"></a>VehicleRole
This DE indicates the role played by a vehicle at a point in time.

 The value shall be set to:
 - 0 `default`          - to indicate the default vehicle role as indicated by the vehicle type,
 - 1 `publicTransport`  - to indicate that the vehicle is used to operate public transport service,
 - 2 `specialTransport` - to indicate that the vehicle is used for special transport purpose, e.g. oversized trucks,
 - 3 `dangerousGoods`   - to indicate that the vehicle is used for dangerous goods transportation,
 - 4 `roadWork`         - to indicate that the vehicle is used to realize roadwork or road maintenance mission,
 - 5 `rescue`           - to indicate that the vehicle is used for rescue purpose in case of an accident, e.g. as a towing service,
 - 6 `emergency`        - to indicate that the vehicle is used for emergency mission, e.g. ambulance, fire brigade,
 - 7 `safetyCar`        - to indicate that the vehicle is used for public safety, e.g. patrol,
 - 8 `agriculture`      - to indicate that the vehicle is used for agriculture, e.g. farm tractor, 
 - 9 `commercial`       - to indicate that the vehicle is used for transportation of commercial goods,
 - 10 `military`        - to indicate that the vehicle is used for military purpose, 
 - 11 `roadOperator`    - to indicate that the vehicle is used in road operator missions,
 - 12 `taxi`            - to indicate that the vehicle is used to provide an authorized taxi service.
 - 13 `reserved`        - is reserved for future usage.
 - 14 `reserved`        - is reserved for future usage.
 - 15 `reserved`        - is reserved for future usage.

* **default** (0)<br>
* **publicTransport** (1)<br>
* **dangerousGoods** (3)<br>
    
       specialTransport(2),
* **roadWork** (4)<br>
* **rescue** (5)<br>
* **emergency** (6)<br>
* **safetyCar** (7)<br>
* **agriculture** (8)<br>
* **commercial** (9)<br>
* **military** (10)<br>
* **roadOperator** (11)<br>
* **taxi** (12)<br>
* **reserved1** (13)<br>
* **reserved2** (14)<br>
* **reserved3** (15)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Vehicle Information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Description updated in V2.1.1 (removed reference to CEN/TS 16157-3)_
```asn1
VehicleRole ::= ENUMERATED {
    default         (0), 
    publicTransport (1), 
    specialTransport(2), 
    dangerousGoods  (3), 
    roadWork        (4), 
    rescue          (5), 
    emergency       (6), 
    safetyCar       (7), 
    agriculture     (8), 
    commercial      (9), 
    military        (10), 
    roadOperator    (11), 
    taxi            (12), 
    reserved1       (13), 
    reserved2       (14), 
    reserved3       (15)
}
```

### <a name="VehicleWidth"></a>VehicleWidth
This DE represents the width of a vehicle, excluding side mirrors and possible similar extensions.
 The value shall be set to:
 - `n` (`n > 0` and `n < 61`) indicates the applicable value is equal to or less than n x 0,1 metre, and greater than (n-1) x 0,1 metre,
 - `61` indicates that the vehicle width is greater than 6,0 metres,
 - `62` indicates that the information in unavailable.

* **outOfRange** (61)<br>
* **unavailable** (62)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _0,1 metre_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Vehicle information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Description updated in V2.1.1 (the meaning of 61 has changed slightly)._
```asn1
VehicleWidth ::= INTEGER {
    outOfRange  (61),  
    unavailable (62)
} (1..62)
```

### <a name="VerticalAccelerationValue"></a>VerticalAccelerationValue
This DE represents the vehicle acceleration at vertical direction in the centre of the mass of the empty vehicle.
 The value shall be provided in the vehicle coordinate system as defined in ISO 8855 [[21]](#references), clause 2.11.

 The value shall be set to:
 - `-160` for acceleration values equal to or less than -16 m/s<sup>2</sup>,
 - `n` (`n > -160` and `n ≤ 0`) to indicate downwards acceleration equal to or less than n x 0,1 m/s<sup>2</sup>, and greater than (n-1) x 0,1 m/s<sup>2</sup>,
 - `n` (`n > 0` and `n < 160`) to indicate upwards acceleration equal to or less than n x 0,1 m/s<sup>2</sup>, and greater than (n-1) x 0,1 m/s<sup>2</sup>,
 - `160` for acceleration values greater than 15,9 m/s<sup>2</sup>,
 - `161` when the data is unavailable.

* **negativeOutOfRange** (-160)<br>
* **positiveOutOfRange** (160)<br>
* **unavailable** (161)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _0,1 m/s<sup>2</sup>_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Vehicle information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Desciption updated in V2.1.1 (the meaning of 160 has changed slightly)._

>>>
NOTE:&emsp;The empty load vehicle is defined in ISO 1176 [[8]](#references), clause 4.6.
>>>
```asn1
VerticalAccelerationValue ::= INTEGER {
    negativeOutOfRange (-160),
    positiveOutOfRange (160),
    unavailable        (161)  
} (-160 .. 161)
```

### <a name="VruClusterProfiles"></a>VruClusterProfiles
This DE Identifies all the VRU profile types within a cluster.
 It consist of a Bitmap encoding VRU profiles, to allow multiple profiles to be indicated in a single cluster (heterogeneous cluster if more than one profile).
 
 The corresponding bit shall be set to 1 under the following conditions:
 - 0 `pedestrian`  - indicates that the VRU cluster contains at least one pedestrian VRU,
 - 1 `bicycle`     - indicates that the VRU cluster contains at least one bicycle VRU member,
 - 2 `motorcyclist`- indicates that the VRU cluster contains at least one motorcycle VRU member,
 - 3 `animal`      - indicates that the VRU cluster contains at least one animal VRU member.
 
 Otherwise, the corresponding bit shall be set to 0.

* **pedestrian** (0)<br>
* **bicyclist** (1)<br>
* **motorcyclist** (2)<br>
* **animal** (3)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** VRU information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
VruClusterProfiles ::= BIT STRING {
    pedestrian   (0),
    bicyclist    (1),
    motorcyclist (2),
    animal       (3)
} (SIZE(4))
```

### <a name="VruDeviceUsage"></a>VruDeviceUsage
This DE represents the possible usage conditions of the VRU device.
 - The value shall be set to:
 - 0 `unavailable`      - to indicate that the usage conditions are unavailable,
 - 1 `other`            - to indicate that the VRU device is in a state not defined below,
 - 2 `idle`             - to indicate that the human is currently not interacting with the device,
 - 3 `listeningToAudio` - to indicate that any audio source other than calling is in use,
 - 4 `typing`           - to indicate that the human is texting or performaing any other manual input activity,
 - 5 `calling`          - to indicate that the VRU device is currently receiving a call,
 - 6 `playingGames`     - to indicate that the human is playing games,
 - 7 `reading`          - to indicate that the human is reading on the VRU device,
 - 8 `viewing`          - to indicate that the human is watching dynamic content, including following navigation prompts, viewing videos or other visual contents that are not static.
 - value 9 to 255       - are reserved for future usage. Value 255 set to "max" in order to bound the size of the encoded field.

* **unavailable** (0)<br>
* **other** (1)<br>
* **idle** (2)<br>
* **listeningToAudio** (3)<br>
* **typing** (4)<br>
* **calling** (5)<br>
* **playingGames** (6)<br>
* **reading** (7)<br>
* **viewing** (8)<br>
* **max** (255)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** VRU information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
VruDeviceUsage ::= ENUMERATED {
    unavailable      (0), 
    other            (1), 
    idle             (2), 
    listeningToAudio (3), 
    typing           (4), 
    calling          (5), 
    playingGames     (6), 
    reading          (7), 
    viewing          (8), 
    max              (255)
}
```

### <a name="VruEnvironment"></a>VruEnvironment
This DE represents the possible VRU environment conditions.

 - The value shall be set to:
 - 0 `unavailable`            - to indicate that the information on the type of environment is unavailable,
 - 1 `intersectionCrossing`   - to indicate that the VRU is on an intersection or crossing,
 - 2 `zebraCrossing`          - to indicate that the VRU is on a  zebra crossing (crosswalk),
 - 3 `sidewalk`               - to indicate that the VRU is on a sidewalk,
 - 4 `onVehicleRoad`          - to indicate that the VRU is on a traffic lane,
 - 5 `protectedGeographicArea`- to indicate that the VRU is in a protected area.
 - value 5 to 255             - are reserved for future usage. Value 255 is set to "max" in order to bound the size of the encoded field.

* **unavailable** (0)<br>
* **intersectionCrossing** (1)<br>
* **zebraCrossing** (2)<br>
* **sidewalk** (3)<br>
* **onVehicleRoad** (4)<br>
* **protectedGeographicArea** (5)<br>
* **max** (255)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** VRU information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
VruEnvironment ::= ENUMERATED {
    unavailable             (0), 
    intersectionCrossing    (1), 
    zebraCrossing           (2), 
    sidewalk                (3), 
    onVehicleRoad           (4), 
    protectedGeographicArea (5), 
    max                     (255)
}
```

### <a name="VruMovementControl"></a>VruMovementControl
This DE indicates the status of the possible human control over a VRU vehicle.

 The value shall be set to:
 - 0 `unavailable`                 - to indicate that the information is unavailable,
 - 1 `braking`                     - to indicate that the VRU is braking,
 - 2 `hardBraking`                 - to indicate that the VRU is braking hard,
 - 3 `stopPedaling`                - to indicate that the VRU stopped pedaling,
 - 4 `brakingAndStopPedaling`      - to indicate that the VRU stopped pedaling an is braking,
 - 5 `hardBrakingAndStopPedaling`  - to indicate that the VRU stopped pedaling an is braking hard,
 - 6 `noReaction`                  - to indicate that the VRU is not changing its behavior.
 - 7 to 255                        - are reserved for future usage. Value 255 is set to "max" in order to bound the size of the encoded field.

* **unavailable** (0)<br>
* **braking** (1)<br>
* **hardBraking** (2)<br>
* **stopPedaling** (3)<br>
* **brakingAndStopPedaling** (4)<br>
* **hardBrakingAndStopPedaling** (5)<br>
* **noReaction** (6)<br>
* **max** (255)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** VRU information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
VruMovementControl ::= ENUMERATED {
    unavailable                (0), 
    braking                    (1), 
    hardBraking                (2), 
    stopPedaling               (3), 
    brakingAndStopPedaling     (4), 
    hardBrakingAndStopPedaling (5), 
    noReaction                 (6), 
    max                        (255)
}
```

### <a name="VruSubProfilePedestrian"></a>VruSubProfilePedestrian
This DE indicates the profile of a pedestrian.
 
 The value shall be set to:
 - 0 `unavailable`             - to indicate that the information on is unavailable,
 - 1 `ordinary-pedestrian`     - to indicate a pedestrian to which no more-specific profile applies,
 - 2 `road-worker`             - to indicate a pedestrian with the role of a road worker,
 - 3 `first-responder`         - to indicate a pedestrian with the role of a first responder.
 - value 4 to 15               - are reserved for future usage. Value 15 is set to "max" in order to bound the size of the encoded field.

* **unavailable** (0)<br>
* **ordinary-pedestrian** (1)<br>
* **road-worker** (2)<br>
* **first-responder** (3)<br>
* **max** (15)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** VRU information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
VruSubProfilePedestrian ::= ENUMERATED {
    unavailable         (0), 
    ordinary-pedestrian (1),
    road-worker         (2), 
    first-responder     (3),
    max                 (15)
}
```

### <a name="VruSubProfileBicyclist"></a>VruSubProfileBicyclist
This DE indicates the profile of a VRU and its light VRU vehicle / mounted animal. 

 The value shall be set to:
 - 0 `unavailable`           - to indicate that the information  is unavailable,
 - 1 `bicyclist `            - to indicate a cycle and bicyclist,
 - 2 `wheelchair-user`       - to indicate a wheelchair and its user,
 - 3 `horse-and-rider`       - to indicate a horse and rider,
 - 4 `rollerskater`          - to indicate a rolleskater and skater,
 - 5 `e-scooter`             - to indicate an e-scooter and rider,
 - 6 `personal-transporter`  - to indicate a personal-transporter and rider,
 - 7 `pedelec`               - to indicate a pedelec and rider,
 - 8 `speed-pedelec`         - to indicate a speed-pedelec and rider.
 - 9 to 15                   - are reserved for future usage. Value 15 is set to "max" in order to bound the size of the encoded field.

* **unavailable** (0)<br>
* **bicyclist** (1)<br>
* **wheelchair-user** (2)<br>
* **horse-and-rider** (3)<br>
* **rollerskater** (4)<br>
* **e-scooter** (5)<br>
* **personal-transporter** (6)<br>
* **pedelec** (7)<br>
* **speed-pedelec** (8)<br>
* **max** (15)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** VRU information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
VruSubProfileBicyclist ::= ENUMERATED {
    unavailable          (0), 
    bicyclist            (1), 
    wheelchair-user      (2), 
    horse-and-rider      (3), 
    rollerskater         (4), 
    e-scooter            (5), 
    personal-transporter (6),
    pedelec              (7), 
    speed-pedelec        (8),
    max                  (15)
}
```

### <a name="VruSubProfileMotorcyclist"></a>VruSubProfileMotorcyclist
This DE indicates the profile of a motorcyclist and corresponding vehicle.
 
 The value shall be set to:
 - 0 `unavailable `                  - to indicate that the information  is unavailable,
 - 1 `moped`                         - to indicate a moped and rider,
 - 2 `motorcycle`                    - to indicate a motorcycle and rider,
 - 3 `motorcycle-and-sidecar-right`  - to indicate a motorcycle with sidecar on the right and rider,
 - 4 `motorcycle-and-sidecar-left`   - to indicate  a motorcycle with sidecar on the left and rider.
 - 5 to 15                           - are reserved for future usage. Value 15 is set to "max" in order to bound the size of the encoded field.

* **unavailable** (0)<br>
* **moped** (1)<br>
* **motorcycle** (2)<br>
* **motorcycle-and-sidecar-right** (3)<br>
* **motorcycle-and-sidecar-left** (4)<br>
* **max** (15)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** VRU information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
VruSubProfileMotorcyclist ::= ENUMERATED { 
    unavailable                  (0), 
    moped                        (1), 
    motorcycle                   (2), 
    motorcycle-and-sidecar-right (3), 
    motorcycle-and-sidecar-left  (4), 
    max                          (15)
}
```

### <a name="VruSubProfileAnimal"></a>VruSubProfileAnimal
This DE indicates the profile of an animal
 
 The value shall be set to:
 - 0 `unavailable`     - to indicate that the information  is unavailable,
 - 1 `wild-animal`     - to indicate a animal living in the wildness, 
 - 2 `farm-animal`     - to indicate an animal beloning to a farm,
 - 3 `service-animal`  - to indicate an animal that supports a human being.
 - 4 to 15             - are reserved for future usage. Value 15 is set to "max" in order to bound the size of the encoded field.

* **unavailable** (0)<br>
* **wild-animal** (1)<br>
* **farm-animal** (2)<br>
* **service-animal** (3)<br>
* **max** (15)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** VRU information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
VruSubProfileAnimal ::= ENUMERATED {
    unavailable    (0), 
    wild-animal    (1), 
    farm-animal    (2), 
    service-animal (3),   
    max            (15)
}
```

### <a name="VruSizeClass"></a>VruSizeClass
This DE indicates the approximate size of a VRU including the VRU vehicle used.
 
 The value shall be set to:
 - 0 `unavailable`    - to indicate that there is no matched size class or due to privacy reasons in profile 1, 
 - 1 `low`            - to indicate that the VRU size class is low depending on the VRU profile,
 - 2 `medium`         - to indicate that the VRU size class is medium depending on the VRU profile,
 - 3 `high`           - to indicate that the VRU size class is high depending on the VRU profile.
 - 4 to 15            - are reserved for future usage. Value 15 is set to "max" in order to bound the size of the encoded field.

* **unavailable** (0)<br>
* **low** (1)<br>
* **medium** (2)<br>
* **high** (3)<br>
* **max** (15)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** VRU information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
VruSizeClass ::= ENUMERATED { 
    unavailable (0), 
    low         (1), 
    medium      (2), 
    high        (3), 
    max         (15)
}
```

### <a name="VruSpecificExteriorLights"></a>VruSpecificExteriorLights
This DE describes the status of the exterior light switches of a VRU.

 The value of each bit indicates the state of the switch, which commands the corresponding light. 
 The bit corresponding to a specific light shall be set to 1, when the corresponding switch is turned on, either manually by the driver or VRU 
 or automatically by a vehicle or VRU system: 
 - 0 `unavailable`     - indicates no information available, 
 - 1 `backFlashLight ` - indicates the status of the back flash light,
 - 2 `helmetLight`     - indicates the status of the helmet light,
 - 3 `armLight`        - indicates the status of the arm light,
 - 4 `legLight`        - indicates the status of the leg light,
 - 5 `wheelLight`      - indicates the status of the wheel light. 
 - Bits 6 to 8         - are reserved for future use. 
 The bit values do not indicate if the corresponding lamps are alight or not.
 If  VRU is not equipped with a certain light or if the light switch status information is not available, the corresponding bit shall be set to 0.

* **unavailable** (0)<br>
* **backFlashLight** (1)<br>
* **helmetLight** (2)<br>
* **armLight** (3)<br>
* **legLight** (4)<br>
* **wheelLight** (5)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** VRU information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
VruSpecificExteriorLights ::= BIT STRING {
    unavailable    (0),
    backFlashLight (1),
    helmetLight    (2),
    armLight       (3),
    legLight       (4),
    wheelLight     (5)
} (SIZE(8))
```

### <a name="WheelBaseVehicle"></a>WheelBaseVehicle
This DE indicates the perpendicular distance between front and rear axle of the wheel base of vehicle.

 The value shall be set to:
 - `n` (`n ≥ 1` and `n < 126`) if the value is equal to or less than n x 0,1 metre  and more than (n-1) x 0,1 metre,
 - `126` indicates that the wheel base distance is equal to or greater than 12,5 metres,
 - `127` indicates that the information is unavailable.

* **outOfRange** (126)<br>
* **unavailable** (127)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _0,1 metre_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Vehicle information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
WheelBaseVehicle ::= INTEGER {
    outOfRange  (126),
    unavailable (127)
} (1..127)
```

### <a name="Wgs84AngleConfidence"></a>Wgs84AngleConfidence
This DE indicates the angle confidence value which represents the estimated accuracy of an angle value with a default confidence level of 95 %.
 If required, the confidence level can be defined by the corresponding standards applying this DE.
 
 The value shall be set to:
 - `n` (`n ≥ 1` and `n < 126`) if the confidence value is equal to or less than n x 0,1 degrees and more than (n-1) x 0,1 degrees,
 - `126` if the confidence value is out of range, i.e. greater than 12,5 degrees,
 - `127` if the confidence value is not available.

* **outOfRange** (126)<br>
* **unavailable** (127)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _0,1 degrees_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** GeoReference Information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
Wgs84AngleConfidence ::= INTEGER {
    outOfRange  (126), 
    unavailable (127)  
} (1..127)
```

### <a name="Wgs84AngleValue"></a>Wgs84AngleValue
This DE represents an angle value in degrees described in the WGS84 reference system with respect to the WGS84 north.
 The specific WGS84 coordinate system is specified by the corresponding standards applying this DE.
 When the information is not available, the DE shall be set to 3 601. The value 3600 shall not be used.

* **wgs84North** (0)<br>
* **wgs84East** (900)<br>
* **wgs84South** (1800)<br>
* **wgs84West** (2700)<br>
* **doNotUse** (3600)<br>
* **unavailable** (3601)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _0,1 degrees_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** GeoReference Information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
Wgs84AngleValue ::= INTEGER { 
    wgs84North  (0),
    wgs84East   (900),
    wgs84South  (1800),
    wgs84West   (2700),
    doNotUse    (3600),
    unavailable (3601)
} (0..3601)
```

### <a name="WMInumber"></a>WMInumber
This DE represents the World Manufacturer Identifier (WMI). The values are assigned according to ISO 3779 [[6]](#references).

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Vehicle information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V1.3.1_
```asn1
WMInumber ::= IA5String (SIZE(1..3))
```

### <a name="WrongWayDrivingSubCauseCode"></a>WrongWayDrivingSubCauseCode
This DE represents the sub cause codes of the [**CauseCode**](#CauseCode) `wrongWayDriving` .
 
 The value shall be set to:
 - 0 `unavailable`    - in case further detailed information on wrong way driving event is unavailable,
 - 1 `wrongLane`      - in case vehicle is driving on a lane for which it has no authorization to use,
 - 2 `wrongDirection` - in case vehicle is driving in a direction that it is not allowed,
 - 3-255              - reserved for future usage.

* **unavailable** (0)<br>
* **wrongLane** (1)<br>
* **wrongDirection** (2)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Traffic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V1.3.1_
```asn1
WrongWayDrivingSubCauseCode ::= INTEGER {
    unavailable    (0), 
    wrongLane      (1), 
    wrongDirection (2)
} (0..255)
```

### <a name="YawRateConfidence"></a>YawRateConfidence
This DE indicates the yaw rate confidence value which represents the estimated accuracy for a yaw rate value with a default confidence level of 95 %.
 If required, the confidence level can be defined by the corresponding standards applying this DE.
 
 The value shall be set to:
 - `0` if the confidence value is equal to or less than 0,01 degree/second,
 - `1` if the confidence value is equal to or less than 0,05 degrees/second or greater than 0,01 degree/second,
 - `2` if the confidence value is equal to or less than 0,1 degree/second or greater than 0,05 degree/second,
 - `3` if the confidence value is equal to or less than 1 degree/second or greater than 0,1 degree/second,
 - `4` if the confidence value is equal to or less than 5 degrees/second or greater than 1 degrees/second,
 - `5` if the confidence value is equal to or less than 10 degrees/second or greater than 5 degrees/second,
 - `6` if the confidence value is equal to or less than 100 degrees/second or greater than 10 degrees/second,
 - `7` if the confidence value is out of range, i.e. greater than 100 degrees/second,
 - `8` if the confidence value is unavailable.
 
 NOTE: The fact that a yaw rate value is received with confidence value set to `unavailable(8)` can be caused by
 several reasons, such as:
 - the sensor cannot deliver the accuracy at the defined confidence level because it is a low-end sensor,
 - the sensor cannot calculate the accuracy due to lack of variables, or
 - there has been a vehicle bus (e.g. CAN bus) error.
 In all 3 cases above, the yaw rate value may be valid and used by the application.
 
 If a yaw rate value is received and its confidence value is set to `outOfRange(7)`, it means that the 
 yaw rate value is not valid and therefore cannot be trusted. Such value is not useful the application.

* **degSec-000-01** (0)<br>
* **degSec-000-05** (1)<br>
* **degSec-000-10** (2)<br>
* **degSec-001-00** (3)<br>
* **degSec-005-00** (4)<br>
* **degSec-010-00** (5)<br>
* **degSec-100-00** (6)<br>
* **outOfRange** (7)<br>
* **unavailable** (8)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Vehicle information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Description revised in V2.1.1_
```asn1
YawRateConfidence ::= ENUMERATED {
    degSec-000-01 (0),
    degSec-000-05 (1),
    degSec-000-10 (2),
    degSec-001-00 (3), 
    degSec-005-00 (4),
    degSec-010-00 (5),
    degSec-100-00 (6),
    outOfRange    (7),
    unavailable   (8)
}
```

### <a name="YawRateValue"></a>YawRateValue
This DE represents the vehicle rotation around z-axis of the coordinate system centred on the centre of mass of the empty-loaded
 vehicle. The leading sign denotes the direction of rotation.
 
 The value shall be provided in the vehicle coordinate system as defined in ISO 8855 [[21]](#references), clause 2.11.

 The value shall be set to:
 - `-32 766` to indicate that the yaw rate is equal to or greater than 327,66 degrees/second to the right,
 - `n` (`n > -32 766` and `n ≤ 0`) to indicate that the rotation is clockwise (i.e. to the right) and is equal to or less than n x 0,01 degrees/s, 
      and greater than (n-1) x 0,01 degrees/s,
 - `n` (`n > 0` and `n < 32 766`) to indicate that the rotation is anti-clockwise (i.e. to the left) and is equal to or less than n x 0,01 degrees/s, 
      and greater than (n-1) x 0,01 degrees/s,
 - `32 766` to indicate that the yaw rate is greater than 327.65 degrees/second to the left,
 - `32 767` to indicate that the information is not available.
 
 The yaw rate value shall be a raw data value, i.e. not filtered, smoothed or otherwise modified.
 The reading instant should be the same as for the vehicle acceleration.

* **negativeOutOfRange** (-32766)<br>
* **positiveOutOfRange** (32766)<br>
* **unavailable** (32767)<br>

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _0,01 degree per second._

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Vehicle Information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Desription revised in V2.1.1 (the meaning of 32766 has changed slightly)._

>>>
NOTE:&emsp;The empty load vehicle is defined in ISO 1176 [[8]](#references), clause 4.6.
>>>
```asn1
YawRateValue ::= INTEGER {
    negativeOutOfRange (-32766), 
    positiveOutOfRange (32766), 
    unavailable        (32767)
} (-32766..32767)
```

### <a name="Acceleration3dWithConfidence"></a>Acceleration3dWithConfidence
This DF represents an acceleration vector with associated confidence value.

 It shall include the following components:

* _polarAcceleration_ of type [**AccelerationPolarWithZ**](#AccelerationPolarWithZ) <br>
  the representation of the acceleration vector in a polar or cylindrical coordinate system. 

* _cartesianAcceleration_ of type [**AccelerationCartesian**](#AccelerationCartesian) <br>
  the representation of the acceleration vector in a cartesian coordinate system.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Kinematic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
Acceleration3dWithConfidence::= CHOICE {
    polarAcceleration                    AccelerationPolarWithZ,
    cartesianAcceleration                AccelerationCartesian 
}
```

### <a name="AccelerationPolarWithZ"></a>AccelerationPolarWithZ
This DF represents an acceleration vector in a polar or cylindrical coordinate system.
 It shall include the following components:

* _accelerationMagnitude_ of type [**AccelerationMagnitude**](#AccelerationMagnitude) <br>
  magnitude of the acceleration vector projected onto the reference plane, with the associated confidence value.

* _accelerationDirection_ of type [**CartesianAngle**](ETSI-ITS-CDD.md#CartesianAngle) <br>
  polar angle of the acceleration vector projected onto the reference plane, with the associated confidence value.

* _zAcceleration_ of type [**AccelerationComponent**](#AccelerationComponent)  OPTIONAL<br>
  the optional z component of the acceleration vector along the reference axis of the cylindrical coordinate system, with the associated confidence value.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Kinematic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
AccelerationPolarWithZ::= SEQUENCE{
    accelerationMagnitude                             AccelerationMagnitude,
    accelerationDirection                             CartesianAngle,
    zAcceleration                                     AccelerationComponent OPTIONAL
}
```

### <a name="AccelerationCartesian"></a>AccelerationCartesian
This DF represents a acceleration vector in a cartesian coordinate system.
 It shall include the following components:

* _xAcceleration_ of type [**AccelerationComponent**](#AccelerationComponent) <br>
  the x component of the acceleration vector with the associated confidence value.

* _yAcceleration_ of type [**AccelerationComponent**](#AccelerationComponent) <br>
  the y component of the acceleration vector with the associated confidence value.

* _zAcceleration_ of type [**AccelerationComponent**](#AccelerationComponent)  OPTIONAL<br>
  the optional z component of the acceleration vector with the associated confidence value.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Kinematic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
AccelerationCartesian::= SEQUENCE{
    xAcceleration      AccelerationComponent,
    yAcceleration      AccelerationComponent,
    zAcceleration      AccelerationComponent OPTIONAL
}
```

### <a name="AccelerationComponent"></a>AccelerationComponent
This DF represents an acceleration component along with a confidence value.

 It shall include the following components:

* _value_ of type [**AccelerationValue**](#AccelerationValue) <br>
  the value of the acceleration component which can be estimated as the mean of the current distribution.

* _confidence_ of type [**AccelerationConfidence**](#AccelerationConfidence) <br>
  the confidence value associated to the provided value.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Kinematic Information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
AccelerationComponent ::= SEQUENCE {
    value         AccelerationValue,
    confidence    AccelerationConfidence
}
```

### <a name="AccelerationChangeIndication"></a>AccelerationChangeIndication
This DF represents information associated to changes in acceleration. 

 It shall include the following components:

* _accelOrDecel_ of type [**AccelerationChange**](#AccelerationChange) <br>
  the indication of an acceleration change.

* _actionDeltaTime_ of type [**DeltaTimeTenthOfSecond**](#DeltaTimeTenthOfSecond) <br>
  the period over which the acceleration change action is performed.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Kinematic Information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
AccelerationChangeIndication ::= SEQUENCE {
    accelOrDecel       AccelerationChange,
    actionDeltaTime    DeltaTimeTenthOfSecond,
    ...
}
```

### <a name="AccelerationMagnitude"></a>AccelerationMagnitude
This DF represents the magnitude of the acceleration vector and associated confidence value.

 It shall include the following components:

* _accelerationMagnitudeValue_ of type [**AccelerationMagnitudeValue**](#AccelerationMagnitudeValue) <br>
  the magnitude of the acceleration vector.

* _accelerationConfidence_ of type [**AccelerationConfidence**](#AccelerationConfidence) <br>
  the confidence value of the magnitude value.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Kinematic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
AccelerationMagnitude::= SEQUENCE {
    accelerationMagnitudeValue   AccelerationMagnitudeValue,
    accelerationConfidence       AccelerationConfidence
}
```

### <a name="ActionId"></a>ActionId
This DF represents an identifier used to describe a protocol action taken by an ITS-S.
 
 It shall include the following components:

* _originatingStationId_ of type [**StationId**](ETSI-ITS-CDD.md#StationId) <br>
  Id of the ITS-S that takes the action. 

* _sequenceNumber_ of type [**SequenceNumber**](#SequenceNumber) <br>
  a sequence number. 


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Communication information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1 based on [**ActionID**](#ActionID)._
```asn1
ActionId ::= SEQUENCE {
    originatingStationId    StationId,
    sequenceNumber          SequenceNumber
}
```

### <a name="ActionID"></a>ActionID
This DF represents an identifier used to describe a protocol action taken by an ITS-S.
 
 It shall include the following components:

* _originatingStationId_ of type [**StationID**](#StationID) <br>
  Id of the ITS-S that takes the action. 

* _sequenceNumber_ of type [**SequenceNumber**](#SequenceNumber) <br>
  a sequence number. 


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Communication information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V1.3.1_

>>>
NOTE:&emsp;this DF is kept for backwards compatibility reasons only. It is recommended to use the [**ActionId**](#ActionId) instead.
>>>
```asn1
ActionID ::= SEQUENCE {
    originatingStationId    StationID,
    sequenceNumber          SequenceNumber
}
```

### <a name="ActionIdList"></a>ActionIdList
This DF shall contain a list of [**ActionId**](#ActionId).

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Communication Information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1 based on ReferenceDenms from DENM Release 1_
```asn1
ActionIdList::= SEQUENCE (SIZE(1..8, ...)) OF ActionId
```

### <a name="Altitude"></a>Altitude
This DF provides the altitude and confidence level of an altitude information in a WGS84 coordinate system.
 The specific WGS84 coordinate system is specified by the corresponding standards applying this DE.

 It shall include the following components:

* _altitudeValue_ of type [**AltitudeValue**](#AltitudeValue) <br>
  altitude of a geographical point.

* _altitudeConfidence_ of type [**AltitudeConfidence**](#AltitudeConfidence) <br>
  confidence level of the altitudeValue.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** GeoReference information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Description revised in V2.1.1_

>>>
NOTE:&emsp;this DF is kept for backwards compatibility reasons only. It is recommended to use the [**AltitudeWithConfidence**](#AltitudeWithConfidence) instead.
>>>
```asn1
Altitude ::= SEQUENCE {
    altitudeValue         AltitudeValue,
    altitudeConfidence    AltitudeConfidence
}
```

### <a name="BasicContainer"></a>BasicContainer
This DE represents a general container for usage in various types of messages.

 It shall include the following components:

* _stationType_ of type [**TrafficParticipantType**](#TrafficParticipantType) <br>
  the type of technical context in which the ITS-S that has generated the message is integrated in.

* _referencePosition_ of type [**ReferencePositionWithConfidence**](#ReferencePositionWithConfidence) <br>
  the reference position of the station that has generated the message that contains the basic container.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Basic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
BasicContainer ::= SEQUENCE {
	stationType          TrafficParticipantType,
	referencePosition    ReferencePositionWithConfidence,
	...
}
```

### <a name="CartesianAngle"></a>CartesianAngle
This DF represents a general Data Frame to describe an angle component along with a confidence value in a cartesian coordinate system.

 It shall include the following components:

* _value_ of type [**CartesianAngleValue**](#CartesianAngleValue) <br>
  The angle value which can be estimated as the mean of the current distribution.

* _confidence_ of type [**AngleConfidence**](#AngleConfidence) <br>
  The confidence value associated to the provided value.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Basic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
CartesianAngle ::= SEQUENCE {
    value         CartesianAngleValue,
    confidence    AngleConfidence
}
```

### <a name="CartesianAngularVelocityComponent"></a>CartesianAngularVelocityComponent
This DF represents an angular velocity component along with a confidence value in a cartesian coordinate system.

 It shall include the following components:

* _value_ of type [**CartesianAngularVelocityComponentValue**](#CartesianAngularVelocityComponentValue) <br>
  The angular velocity component.

* _confidence_ of type [**AngularSpeedConfidence**](#AngularSpeedConfidence) <br>
  The confidence value associated to the provided value.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Kinematic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
CartesianAngularVelocityComponent ::= SEQUENCE {
    value         CartesianAngularVelocityComponentValue,
    confidence    AngularSpeedConfidence
}
```

### <a name="CartesianAngularAccelerationComponent"></a>CartesianAngularAccelerationComponent
This DF represents a general Data Frame to describe an angular acceleration component along with a confidence value in a cartesian coordinate system.

 It shall include the following components:

* _value_ of type [**CartesianAngularAccelerationComponentValue**](#CartesianAngularAccelerationComponentValue) <br>
  The angular acceleration component value.

* _confidence_ of type [**AngularAccelerationConfidence**](#AngularAccelerationConfidence) <br>
  The confidence value associated to the provided value.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Kinematic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
CartesianAngularAccelerationComponent ::= SEQUENCE {
    value         CartesianAngularAccelerationComponentValue,
    confidence    AngularAccelerationConfidence
}
```

### <a name="CartesianCoordinateWithConfidence"></a>CartesianCoordinateWithConfidence
This DF represents a coordinate along with a confidence value in a cartesian reference system.

 It shall include the following components:

* _value_ of type [**CartesianCoordinateLarge**](#CartesianCoordinateLarge) <br>
  the coordinate value, which can be estimated as the mean of the current distribution.

* _confidence_ of type [**CoordinateConfidence**](#CoordinateConfidence) <br>
  the coordinate confidence value associated to the provided value.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** GeoReference information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
CartesianCoordinateWithConfidence ::= SEQUENCE {
    value         CartesianCoordinateLarge,
    confidence    CoordinateConfidence
}
```

### <a name="CartesianPosition3d"></a>CartesianPosition3d
This DF represents a  position in a two- or three-dimensional cartesian coordinate system.

 It shall include the following components:

* _xCoordinate_ of type [**CartesianCoordinate**](#CartesianCoordinate) <br>
  the X coordinate value.

* _yCoordinate_ of type [**CartesianCoordinate**](#CartesianCoordinate) <br>
  the Y coordinate value.

* _zCoordinate_ of type [**CartesianCoordinate**](#CartesianCoordinate)  OPTIONAL<br>
  the optional Z coordinate value.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** GeoReference information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
CartesianPosition3d::=SEQUENCE{
    xCoordinate    CartesianCoordinate,
    yCoordinate    CartesianCoordinate,
    zCoordinate    CartesianCoordinate OPTIONAL
}
```

### <a name="CartesianPosition3dWithConfidence"></a>CartesianPosition3dWithConfidence
This DF represents a  position in a two- or three-dimensional cartesian coordinate system with an associated confidence level for each coordinate.

 It shall include the following components:

* _xCoordinate_ of type [**CartesianCoordinateWithConfidence**](#CartesianCoordinateWithConfidence) <br>
  the X coordinate value with the associated confidence level.

* _yCoordinate_ of type [**CartesianCoordinateWithConfidence**](#CartesianCoordinateWithConfidence) <br>
  the Y coordinate value with the associated confidence level.

* _zCoordinate_ of type [**CartesianCoordinateWithConfidence**](#CartesianCoordinateWithConfidence)  OPTIONAL<br>
  the optional Z coordinate value with the associated confidence level.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** GeoReference information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
CartesianPosition3dWithConfidence::= SEQUENCE{    
    xCoordinate    CartesianCoordinateWithConfidence, 
    yCoordinate    CartesianCoordinateWithConfidence, 
    zCoordinate    CartesianCoordinateWithConfidence OPTIONAL
}
```

### <a name="CauseCode"></a>CauseCode
This DF is a representation of the cause code value of a traffic event. 

 It shall include the following components:

* _causeCode_ of type [**CauseCodeType**](#CauseCodeType) <br>
  the main cause of a detected event. 

* _subCauseCode_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
  the subordinate cause of a detected event. 

The semantics of the entire DF are completely defined by the component causeCode. The interpretation of the subCauseCode may 
 provide additional information that is not strictly necessary to understand the causeCode itself, and is therefore optional.

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Traffic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Editorial update in V2.1.1_

>>>
NOTE:&emsp;this DF is kept for backwards compatibility reasons only. It is recommended to use the [**CauseCodeV2**](#CauseCodeV2) instead.
>>>
```asn1
CauseCode ::= SEQUENCE {
    causeCode       CauseCodeType,
    subCauseCode    SubCauseCodeType,
    ...
}
```

### <a name="CauseCodeChoice"></a>CauseCodeChoice
This DF is a representation of the cause code value and associated sub cause code value of a traffic event.

* _reserved0_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _trafficCondition1_ of type [**TrafficConditionSubCauseCode**](#TrafficConditionSubCauseCode) <br>
* _accident2_ of type [**AccidentSubCauseCode**](#AccidentSubCauseCode) <br>
* _roadworks3_ of type [**RoadworksSubCauseCode**](#RoadworksSubCauseCode) <br>
* _reserved4_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _impassability5_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _adverseWeatherCondition-Adhesion6_ of type [**AdverseWeatherCondition-AdhesionSubCauseCode**](#AdverseWeatherCondition-AdhesionSubCauseCode) <br>
* _aquaplaning7_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved8_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _hazardousLocation-SurfaceCondition9_ of type [**HazardousLocation-SurfaceConditionSubCauseCode**](#HazardousLocation-SurfaceConditionSubCauseCode) <br>
* _hazardousLocation-ObstacleOnTheRoad10_ of type [**HazardousLocation-ObstacleOnTheRoadSubCauseCode**](#HazardousLocation-ObstacleOnTheRoadSubCauseCode) <br>
* _hazardousLocation-AnimalOnTheRoad11_ of type [**HazardousLocation-AnimalOnTheRoadSubCauseCode**](#HazardousLocation-AnimalOnTheRoadSubCauseCode) <br>
* _humanPresenceOnTheRoad12_ of type [**HumanPresenceOnTheRoadSubCauseCode**](#HumanPresenceOnTheRoadSubCauseCode) <br>
* _reserved13_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _wrongWayDriving14_ of type [**WrongWayDrivingSubCauseCode**](#WrongWayDrivingSubCauseCode) <br>
* _rescueAndRecoveryWorkInProgress15_ of type [**RescueAndRecoveryWorkInProgressSubCauseCode**](#RescueAndRecoveryWorkInProgressSubCauseCode) <br>
* _reserved16_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _adverseWeatherCondition-ExtremeWeatherCondition17_ of type [**AdverseWeatherCondition-ExtremeWeatherConditionSubCauseCode**](#AdverseWeatherCondition-ExtremeWeatherConditionSubCauseCode) <br>
* _adverseWeatherCondition-Visibility18_ of type [**AdverseWeatherCondition-VisibilitySubCauseCode**](#AdverseWeatherCondition-VisibilitySubCauseCode) <br>
* _adverseWeatherCondition-Precipitation19_ of type [**AdverseWeatherCondition-PrecipitationSubCauseCode**](#AdverseWeatherCondition-PrecipitationSubCauseCode) <br>
* _violence20_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved21_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved22_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved23_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved24_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved25_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _slowVehicle26_ of type [**SlowVehicleSubCauseCode**](#SlowVehicleSubCauseCode) <br>
* _dangerousEndOfQueue27_ of type [**DangerousEndOfQueueSubCauseCode**](#DangerousEndOfQueueSubCauseCode) <br>
* _reserved28_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved29_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved30_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved31_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved32_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved33_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved34_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved35_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved36_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved37_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved38_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved39_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved40_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved41_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved42_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved43_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved44_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved45_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved46_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved47_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved48_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved49_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved50_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved51_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved52_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved53_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved54_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved55_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved56_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved57_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved58_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved59_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved60_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved61_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved62_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved63_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved64_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved65_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved66_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved67_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved68_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved69_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved70_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved71_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved72_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved73_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved74_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved75_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved76_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved77_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved78_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved79_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved80_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved81_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved82_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved83_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved84_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved85_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved86_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved87_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved88_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved89_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved90_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _vehicleBreakdown91_ of type [**VehicleBreakdownSubCauseCode**](#VehicleBreakdownSubCauseCode) <br>
* _postCrash92_ of type [**PostCrashSubCauseCode**](#PostCrashSubCauseCode) <br>
* _humanProblem93_ of type [**HumanProblemSubCauseCode**](#HumanProblemSubCauseCode) <br>
* _stationaryVehicle94_ of type [**StationaryVehicleSubCauseCode**](#StationaryVehicleSubCauseCode) <br>
* _emergencyVehicleApproaching95_ of type [**EmergencyVehicleApproachingSubCauseCode**](#EmergencyVehicleApproachingSubCauseCode) <br>
* _hazardousLocation-DangerousCurve96_ of type [**HazardousLocation-DangerousCurveSubCauseCode**](#HazardousLocation-DangerousCurveSubCauseCode) <br>
* _collisionRisk97_ of type [**CollisionRiskSubCauseCode**](#CollisionRiskSubCauseCode) <br>
* _signalViolation98_ of type [**SignalViolationSubCauseCode**](#SignalViolationSubCauseCode) <br>
* _dangerousSituation99_ of type [**DangerousSituationSubCauseCode**](#DangerousSituationSubCauseCode) <br>
* _railwayLevelCrossing100_ of type [**RailwayLevelCrossingSubCauseCode**](#RailwayLevelCrossingSubCauseCode) <br>
* _reserved101_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved102_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved103_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved104_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved105_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved106_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved107_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved108_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved109_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved110_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved111_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved112_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved113_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved114_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved115_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved116_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved117_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved118_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved119_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved120_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved121_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved122_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved123_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved124_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved125_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved126_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved127_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>
* _reserved128_ of type [**SubCauseCodeType**](#SubCauseCodeType) <br>

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Traffic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_

>>>
NOTE:&emsp;this DF is defined for use as part of CauseCodeV2. It is recommended to use CauseCodeV2.
>>>
```asn1
CauseCodeChoice::= CHOICE {
    reserved0                                          SubCauseCodeType,
    trafficCondition1                                  TrafficConditionSubCauseCode,
    accident2                                          AccidentSubCauseCode,
    roadworks3                                         RoadworksSubCauseCode,
    reserved4                                          SubCauseCodeType,
    impassability5                                     SubCauseCodeType,
    adverseWeatherCondition-Adhesion6                  AdverseWeatherCondition-AdhesionSubCauseCode,
    aquaplaning7                                       SubCauseCodeType,
    reserved8                                          SubCauseCodeType,
    hazardousLocation-SurfaceCondition9                HazardousLocation-SurfaceConditionSubCauseCode,
    hazardousLocation-ObstacleOnTheRoad10              HazardousLocation-ObstacleOnTheRoadSubCauseCode,
    hazardousLocation-AnimalOnTheRoad11                HazardousLocation-AnimalOnTheRoadSubCauseCode,
    humanPresenceOnTheRoad12                           HumanPresenceOnTheRoadSubCauseCode,
    reserved13                                         SubCauseCodeType,
    wrongWayDriving14                                  WrongWayDrivingSubCauseCode,
    rescueAndRecoveryWorkInProgress15                  RescueAndRecoveryWorkInProgressSubCauseCode,
    reserved16                                         SubCauseCodeType,
    adverseWeatherCondition-ExtremeWeatherCondition17  AdverseWeatherCondition-ExtremeWeatherConditionSubCauseCode,
    adverseWeatherCondition-Visibility18               AdverseWeatherCondition-VisibilitySubCauseCode,
    adverseWeatherCondition-Precipitation19            AdverseWeatherCondition-PrecipitationSubCauseCode,
    violence20                                         SubCauseCodeType,
    reserved21                                         SubCauseCodeType,
    reserved22                                         SubCauseCodeType,
    reserved23                                         SubCauseCodeType,
    reserved24                                         SubCauseCodeType,
    reserved25                                         SubCauseCodeType,
    slowVehicle26                                      SlowVehicleSubCauseCode,
    dangerousEndOfQueue27                              DangerousEndOfQueueSubCauseCode,
    reserved28                                         SubCauseCodeType,
    reserved29                                         SubCauseCodeType,
    reserved30                                         SubCauseCodeType,
    reserved31                                         SubCauseCodeType,
    reserved32                                         SubCauseCodeType,
    reserved33                                         SubCauseCodeType,
    reserved34                                         SubCauseCodeType,
    reserved35                                         SubCauseCodeType,
    reserved36                                         SubCauseCodeType,
    reserved37                                         SubCauseCodeType,
    reserved38                                         SubCauseCodeType,
    reserved39                                         SubCauseCodeType,
    reserved40                                         SubCauseCodeType,
    reserved41                                         SubCauseCodeType,
    reserved42                                         SubCauseCodeType,
    reserved43                                         SubCauseCodeType,
    reserved44                                         SubCauseCodeType,
    reserved45                                         SubCauseCodeType,
    reserved46                                         SubCauseCodeType,
    reserved47                                         SubCauseCodeType,
    reserved48                                         SubCauseCodeType,
    reserved49                                         SubCauseCodeType,
    reserved50                                         SubCauseCodeType,
    reserved51                                         SubCauseCodeType,
    reserved52                                         SubCauseCodeType,
    reserved53                                         SubCauseCodeType,
    reserved54                                         SubCauseCodeType,
    reserved55                                         SubCauseCodeType,
    reserved56                                         SubCauseCodeType,
    reserved57                                         SubCauseCodeType,
    reserved58                                         SubCauseCodeType,   
    reserved59                                         SubCauseCodeType, 
    reserved60                                         SubCauseCodeType,
    reserved61                                         SubCauseCodeType,
    reserved62                                         SubCauseCodeType,
    reserved63                                         SubCauseCodeType,
    reserved64                                         SubCauseCodeType,
    reserved65                                         SubCauseCodeType,
    reserved66                                         SubCauseCodeType,    
    reserved67                                         SubCauseCodeType,
    reserved68                                         SubCauseCodeType,
    reserved69                                         SubCauseCodeType,
    reserved70                                         SubCauseCodeType,
    reserved71                                         SubCauseCodeType,
    reserved72                                         SubCauseCodeType,
    reserved73                                         SubCauseCodeType,
    reserved74                                         SubCauseCodeType,
    reserved75                                         SubCauseCodeType,
    reserved76                                         SubCauseCodeType,
    reserved77                                         SubCauseCodeType,
    reserved78                                         SubCauseCodeType,
    reserved79                                         SubCauseCodeType,
    reserved80                                         SubCauseCodeType,
    reserved81                                         SubCauseCodeType,
    reserved82                                         SubCauseCodeType,
    reserved83                                         SubCauseCodeType,
    reserved84                                         SubCauseCodeType,
    reserved85                                         SubCauseCodeType,
    reserved86                                         SubCauseCodeType,
    reserved87                                         SubCauseCodeType,
    reserved88                                         SubCauseCodeType,
    reserved89                                         SubCauseCodeType,
    reserved90                                         SubCauseCodeType,
    vehicleBreakdown91                                 VehicleBreakdownSubCauseCode,
    postCrash92                                        PostCrashSubCauseCode,
    humanProblem93                                     HumanProblemSubCauseCode,
    stationaryVehicle94                                StationaryVehicleSubCauseCode,
    emergencyVehicleApproaching95                      EmergencyVehicleApproachingSubCauseCode,
    hazardousLocation-DangerousCurve96                 HazardousLocation-DangerousCurveSubCauseCode,
    collisionRisk97                                    CollisionRiskSubCauseCode,
    signalViolation98                                  SignalViolationSubCauseCode,
    dangerousSituation99                               DangerousSituationSubCauseCode,
    railwayLevelCrossing100                            RailwayLevelCrossingSubCauseCode,
    reserved101                                        SubCauseCodeType,
    reserved102                                        SubCauseCodeType,
    reserved103                                        SubCauseCodeType,
    reserved104                                        SubCauseCodeType,
    reserved105                                        SubCauseCodeType,
    reserved106                                        SubCauseCodeType,
    reserved107                                        SubCauseCodeType,
    reserved108                                        SubCauseCodeType,
    reserved109                                        SubCauseCodeType,
    reserved110                                        SubCauseCodeType,
    reserved111                                        SubCauseCodeType,
    reserved112                                        SubCauseCodeType,
    reserved113                                        SubCauseCodeType,
    reserved114                                        SubCauseCodeType,
    reserved115                                        SubCauseCodeType,
    reserved116                                        SubCauseCodeType,
    reserved117                                        SubCauseCodeType,
    reserved118                                        SubCauseCodeType,
    reserved119                                        SubCauseCodeType,
    reserved120                                        SubCauseCodeType,
    reserved121                                        SubCauseCodeType,
    reserved122                                        SubCauseCodeType,
    reserved123                                        SubCauseCodeType,
    reserved124                                        SubCauseCodeType,
    reserved125                                        SubCauseCodeType,
    reserved126                                        SubCauseCodeType,
    reserved127                                        SubCauseCodeType,
    reserved128                                        SubCauseCodeType
  }
```

### <a name="CauseCodeV2"></a>CauseCodeV2
This DF is an alternative representation of the cause code value of a traffic event. 

 It shall include the following components:

* _ccAndScc_ of type [**CauseCodeChoice**](#CauseCodeChoice) <br>
  the main cause of a detected event. Each entry is of a different type and represents the sub cause code.

The semantics of the entire DF are completely defined by the component causeCode. The interpretation of the subCauseCode may 
 provide additional information that is not strictly necessary to understand the causeCode itself, and is therefore optional.

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Traffic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
CauseCodeV2 ::= SEQUENCE {
    ccAndScc    CauseCodeChoice,
    ...
}
```

### <a name="CenDsrcTollingZone"></a>CenDsrcTollingZone
The DF describes the position of a CEN DSRC road side equipment.

 It shall include the following components:

* _protectedZoneLatitude_ of type [**Latitude**](#Latitude) <br>
  the latitude of the CEN DSRC road side equipment.

* _protectedZoneLongitude_ of type [**Longitude**](#Longitude) <br>
  the latitude of the CEN DSRC road side equipment. 

* _cenDsrcTollingZoneId_ of type [**ProtectedZoneId**](#ProtectedZoneId)  OPTIONAL<br>
* cenDsrcTollingZoneID<br>
  the optional ID of the CEN DSRC road side equipment.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Infrastructure information Communication information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _revised in V2.1.1 (cenDsrcTollingZoneId is directly of type ProtectedZoneId)_
```asn1
CenDsrcTollingZone ::= SEQUENCE {
    protectedZoneLatitude     Latitude,
    protectedZoneLongitude    Longitude,
    cenDsrcTollingZoneId      ProtectedZoneId OPTIONAL,
    ...
}
```

### <a name="CircularShape"></a>CircularShape
This DF represents the shape of a circular area or a right cylinder that is centred on the shape's reference point. 

 It shall include the following components:

* _shapeReferencePoint_ of type [**CartesianPosition3d**](#CartesianPosition3d)  OPTIONAL<br>
  optional reference point that represents the centre of the circle, relative to an externally specified reference position. 
   If this component is absent, the externally specified reference position represents the shape's reference point. 

* _radius_ of type [**StandardLength12b**](#StandardLength12b) <br>
  the radius of the circular area.

* _height_ of type [**StandardLength12b**](#StandardLength12b)  OPTIONAL<br>
  the optional height, present if the shape is a right cylinder extending in the positive z-axis. 


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** GeoReference information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
CircularShape ::= SEQUENCE {
    shapeReferencePoint    CartesianPosition3d OPTIONAL,
    radius                 StandardLength12b,
    height                 StandardLength12b OPTIONAL
}
```

### <a name="ClosedLanes"></a>ClosedLanes
This DF indicates the opening/closure status of the lanes of a carriageway.

 It shall include the following components:

* _innerhardShoulderStatus_ of type [**HardShoulderStatus**](#HardShoulderStatus)  OPTIONAL<br>
  this information is optional and shall be included if an inner hard shoulder is present and the information is known.
   It indicates the open/closing status of inner hard shoulder lanes. 

* _outerhardShoulderStatus_ of type [**HardShoulderStatus**](#HardShoulderStatus)  OPTIONAL<br>
  this information is optional and shall be included if an outer hard shoulder is present and the information is known.
   It indicates the open/closing status of outer hard shoulder lanes. 

* _drivingLaneStatus_ of type [**DrivingLaneStatus**](#DrivingLaneStatus)  OPTIONAL<br>
  this information is optional and shall be included if the information is known.
   It indicates the open/closing status of driving lanes. 
   For carriageways with more than 13 driving lanes, the drivingLaneStatus component shall not be present.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Infrastructure information Road topology information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Description revised in V2.1.1_
```asn1
ClosedLanes ::= SEQUENCE {
    innerhardShoulderStatus    HardShoulderStatus OPTIONAL,
    outerhardShoulderStatus    HardShoulderStatus OPTIONAL,
    drivingLaneStatus          DrivingLaneStatus OPTIONAL,
    ...
}
```

### <a name="ClusterBreakupInfo"></a>ClusterBreakupInfo
This DF provides information about the breakup of a cluster.

 It shall include the following components:

* _clusterBreakupReason_ of type [**ClusterBreakupReason**](#ClusterBreakupReason) <br>
  indicates the reason for breakup.

* _breakupTime_ of type [**DeltaTimeQuarterSecond**](ETSI-ITS-CDD.md#DeltaTimeQuarterSecond) <br>
  indicates the time of breakup. 


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Cluster Information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
ClusterBreakupInfo ::= SEQUENCE {
    clusterBreakupReason    ClusterBreakupReason,
    breakupTime             DeltaTimeQuarterSecond,
    ...
}
```

### <a name="ClusterJoinInfo"></a>ClusterJoinInfo
This DF provides information about the joining of a cluster.

 It shall include the following components:

* _clusterId_ of type [**Identifier1B**](#Identifier1B) <br>
  indicates the identifier of the cluster.

* _joinTime_ of type [**DeltaTimeQuarterSecond**](ETSI-ITS-CDD.md#DeltaTimeQuarterSecond) <br>
  indicates the time of joining. 


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Cluster Information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
ClusterJoinInfo ::= SEQUENCE {
    clusterId    Identifier1B,
    joinTime     DeltaTimeQuarterSecond,
    ...
}
```

### <a name="ClusterLeaveInfo"></a>ClusterLeaveInfo
The DF provides information about the leaving of a cluster.

 It shall include the following components:

* _clusterId_ of type [**Identifier1B**](#Identifier1B) <br>
  indicates the cluster.

* _clusterLeaveReason_ of type [**ClusterLeaveReason**](#ClusterLeaveReason) <br>
  indicates the reason for leaving. 


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Cluster Information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
ClusterLeaveInfo ::= SEQUENCE {
    clusterId             Identifier1B,
    clusterLeaveReason    ClusterLeaveReason,
    ...
}
```

### <a name="CorrelationColumn"></a>CorrelationColumn
This DF represents a column of a lower triangular positive semi-definite matrix and consists of a list of correlation cell values ordered by rows.
 Given a matrix "A" of size n x n, the number of columns to be included in the lower triangular matrix is k=n-1.
 Each column "i" of the lower triangular matrix then contains k-(i-1) values (ordered by rows from 1 to n-1), where "i" refers to the column number count
 starting at 1 from the left.

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Sensing Information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
CorrelationColumn ::= SEQUENCE SIZE (1..13,...) OF CorrelationCellValue
```

### <a name="Curvature"></a>Curvature
This DF represents the curvature of the vehicle trajectory and the associated confidence value.
 The curvature detected by a vehicle represents the curvature of actual vehicle trajectory.

 It shall include the following components:

* _curvatureValue_ of type [**CurvatureValue**](#CurvatureValue) <br>
  Detected curvature of the vehicle trajectory.

* _curvatureConfidence_ of type [**CurvatureConfidence**](#CurvatureConfidence) <br>
  along with a confidence value of the curvature value with a predefined confidence level. 


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Vehicle information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Description revised in V2.1.1_
```asn1
Curvature ::= SEQUENCE {
    curvatureValue         CurvatureValue,
    curvatureConfidence    CurvatureConfidence
}
```

### <a name="DangerousGoodsExtended"></a>DangerousGoodsExtended
This DF provides a description of dangerous goods being carried by a heavy vehicle.

 It shall include the following components:

* _dangerousGoodsType_ of type [**DangerousGoodsBasic**](#DangerousGoodsBasic) <br>
  Type of dangerous goods.

* _unNumber_ of type **INTEGER**  (0..9999)<br>
  a 4-digit number that identifies the substance of the dangerous goods as specified in
   United Nations Recommendations on the Transport of Dangerous Goods - Model Regulations [[4]](#references),

* _elevatedTemperature_ of type **BOOLEAN** <br>
  whether the carried dangerous goods are transported at high temperature.
   If yes, the value shall be set to TRUE,

* _tunnelsRestricted_ of type **BOOLEAN** <br>
  whether the heavy vehicle carrying dangerous goods is restricted to enter tunnels.
   If yes, the value shall be set to TRUE,

* _limitedQuantity_ of type **BOOLEAN** <br>
  whether the carried dangerous goods are packed with limited quantity.
   If yes, the value shall be set to TRUE,

* _emergencyActionCode_ of type [**IA5String**](#IA5String)  (SIZE (1..24)) OPTIONAL<br>
  physical signage placard at the vehicle that carries information on how an emergency
   service should deal with an incident. This component is optional; it shall be present if the information is available.

* _phoneNumber_ of type [**PhoneNumber**](#PhoneNumber)  OPTIONAL<br>
  contact phone number of assistance service in case of incident or accident.
   This component is optional, it shall be present if the information is available.

* _companyName_ of type [**UTF8String**](#UTF8String)  (SIZE (1..24)) OPTIONAL<br>
  name of company that manages the transportation of the dangerous goods.
   This component is optional; it shall be present if the information is available.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Vehicle information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V1.3.1_
```asn1
DangerousGoodsExtended ::= SEQUENCE {
    dangerousGoodsType      DangerousGoodsBasic,
    unNumber                INTEGER (0..9999),
    elevatedTemperature     BOOLEAN,
    tunnelsRestricted       BOOLEAN,
    limitedQuantity         BOOLEAN,
    emergencyActionCode     IA5String (SIZE (1..24)) OPTIONAL,
    phoneNumber             PhoneNumber OPTIONAL,
    companyName             UTF8String (SIZE (1..24)) OPTIONAL,
    ...
}
```

### <a name="DeltaReferencePosition"></a>DeltaReferencePosition
This DF defines a geographical point position as a 3 dimensional offset position to a geographical reference point.

 It shall include the following components:

* _deltaLatitude_ of type [**DeltaLatitude**](#DeltaLatitude) <br>
  A delta latitude offset with regards to the latitude value of the reference position.

* _deltaLongitude_ of type [**DeltaLongitude**](#DeltaLongitude) <br>
  A delta longitude offset with regards to the longitude value of the reference position.

* _deltaAltitude_ of type [**DeltaAltitude**](#DeltaAltitude) <br>
  A delta altitude offset with regards to the altitude value of the reference position.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** GeoReference information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V1.3.1_
```asn1
DeltaReferencePosition ::= SEQUENCE {
    deltaLatitude     DeltaLatitude,
    deltaLongitude    DeltaLongitude,
    deltaAltitude     DeltaAltitude
}
```

### <a name="DigitalMap"></a>DigitalMap
This DF represents a portion of digital map. It shall contain a list of waypoints [**ReferencePosition**](#ReferencePosition).

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** GeoReference information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V1.3.1_
```asn1
DigitalMap ::= SEQUENCE (SIZE(1..256)) OF ReferencePosition
```

### <a name="EllipticalShape"></a>EllipticalShape
This DF represents the shape of an elliptical area or right elliptical cylinder that is centred on the shape's reference point. 

 It shall include the following components:

* _shapeReferencePoint_ of type [**CartesianPosition3d**](#CartesianPosition3d)  OPTIONAL<br>
  optional reference point which represents the centre of the ellipse, relative to an externally specified reference position. 
   If this component is absent, the externally specified reference position represents the shape's  reference point. 

* _semiMajorAxisLength_ of type [**StandardLength12b**](#StandardLength12b) <br>
  half length of the major axis of the ellipse.

* _semiMinorAxisLength_ of type [**StandardLength12b**](#StandardLength12b) <br>
  half length of the minor axis of the ellipse.

* _orientation_ of type [**Wgs84AngleValue**](#Wgs84AngleValue)  OPTIONAL<br>
  the optional orientation of the major axis of the ellipse in the WGS84 coordinate system.

* _height_ of type [**StandardLength12b**](#StandardLength12b)  OPTIONAL<br>
  the optional height, present if the shape is a right elliptical cylinder extending in the positive z-axis.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** GeoReference information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
EllipticalShape  ::= SEQUENCE {
    shapeReferencePoint    CartesianPosition3d OPTIONAL,
    semiMajorAxisLength    StandardLength12b,
    semiMinorAxisLength    StandardLength12b,
    orientation            Wgs84AngleValue OPTIONAL,
    height                 StandardLength12b OPTIONAL
}
```

### <a name="EulerAnglesWithConfidence"></a>EulerAnglesWithConfidence
This DF represents the Euler angles which describe the orientation of an object bounding box in a Cartesian coordinate system with an associated confidence level for each angle.

 It shall include the following components:

* _zAngle_ of type [**CartesianAngle**](ETSI-ITS-CDD.md#CartesianAngle) <br>
  z-angle of object bounding box at the time of measurement, with the associated confidence.
   The angle is measured with positive values considering the object orientation turning around the z-axis using the right-hand rule, starting from the x-axis. 
   This extrinsic rotation shall be applied around the centre point of the object bounding box before all other rotations.

* _yAngle_ of type [**CartesianAngle**](ETSI-ITS-CDD.md#CartesianAngle)  OPTIONAL<br>
  optional y-angle of object bounding box at the time of measurement, with the associated confidence.
   The angle is measured with positive values considering the object orientation turning around the y-axis using the right-hand rule, starting from the z-axis. 
   This extrinsic rotation shall be applied around the centre point of the object bounding box after the rotation by zAngle and before the rotation by xAngle.

* _xAngle_ of type [**CartesianAngle**](ETSI-ITS-CDD.md#CartesianAngle)  OPTIONAL<br>
  optional x-angle of object bounding box at the time of measurement, with the associated confidence.
   The angle is measured with positive values considering the object orientation turning around the x-axis using the right-hand rule, starting from the z-axis. 
   This extrinsic rotation shall be applied around the centre point of the object bounding box after all other rotations.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Basic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
EulerAnglesWithConfidence ::= SEQUENCE {
    zAngle CartesianAngle,
    yAngle CartesianAngle OPTIONAL,
    xAngle CartesianAngle OPTIONAL
}
```

### <a name="EuVehicleCategoryCode"></a>EuVehicleCategoryCode
This DF represents a vehicle category according to the UNECE/TRANS/WP.29/78/Rev.4 [[16]](#references).
 The following options are available:

* _euVehicleCategoryL_ of type [**EuVehicleCategoryL**](#EuVehicleCategoryL) <br>
  indicates a vehicle in the L category.

* _euVehicleCategoryM_ of type [**EuVehicleCategoryM**](#EuVehicleCategoryM) <br>
  indicates a vehicle in the M category.

* _euVehicleCategoryN_ of type [**EuVehicleCategoryN**](#EuVehicleCategoryN) <br>
  indicates a vehicle in the N category.

* _euVehicleCategoryO_ of type [**EuVehicleCategoryO**](#EuVehicleCategoryO) <br>
  indicates a vehicle in the O category.

* _euVehicleCategoryT_ of type **NULL** <br>
  indicates a vehicle in the T category.

* _euVehicleCategoryG_ of type **NULL** <br>
  indicates a vehicle in the G category.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Vehicle information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
EuVehicleCategoryCode ::= CHOICE {
	euVehicleCategoryL    EuVehicleCategoryL,  
	euVehicleCategoryM    EuVehicleCategoryM,  
	euVehicleCategoryN    EuVehicleCategoryN,   
	euVehicleCategoryO    EuVehicleCategoryO,   
	euVehicleCategoryT    NULL,
	euVehicleCategoryG    NULL    
	}
```

### <a name="EventHistory"></a>EventHistory
The DF shall contain a list of [**EventPoint**](#EventPoint).  

 The eventPosition of each [**EventPoint**](#EventPoint) is defined with respect to the previous [**EventPoint**](#EventPoint) in the list. 
 Except for the first [**EventPoint**](#EventPoint) which is defined with respect to a position outside of the context of this DF.

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** GeoReference information Traffic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Generalized the semantics in V2.1.1_

>>>
NOTE:&emsp;this DF is kept for backwards compatibility reasons only. It is recommended to use the [**EventZone**](#EventZone) instead.
>>>
```asn1
EventHistory::= SEQUENCE (SIZE(1..23)) OF EventPoint
```

### <a name="EventPoint"></a>EventPoint
This DF provides information related to an event at a defined position.

 It shall include the following components:

* _eventPosition_ of type [**DeltaReferencePosition**](#DeltaReferencePosition) <br>
  offset position of a detected event point to a defined position. 

* _eventDeltaTime_ of type [**PathDeltaTime**](#PathDeltaTime)  OPTIONAL<br>
  optional time travelled by the detecting ITS-S since the previous detected event point.

* _informationQuality_ of type [**InformationQuality**](#InformationQuality) <br>
  Information quality of the detection for this event point.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** GeoReference information Traffic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _generalized the semantics in V2.1.1_
```asn1
EventPoint ::= SEQUENCE {
    eventPosition         DeltaReferencePosition,
    eventDeltaTime        PathDeltaTime OPTIONAL,
    informationQuality    InformationQuality
}
```

### <a name="EventZone"></a>EventZone
The DF shall contain a list of [**EventPoint**](#EventPoint), where all [**EventPoint**](#EventPoint) either contain the COMPONENT eventDeltaTime 
 or do not contain the COMPONENT eventDeltaTime.  

 The eventPosition of each [**EventPoint**](#EventPoint) is defined with respect to the previous [**EventPoint**](#EventPoint) in the list. 
 Except for the first [**EventPoint**](#EventPoint) which is defined with respect to a position outside of the context of this DF.

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** GeoReference information Traffic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _created in V2.1.1 based on EventHistory_
```asn1
EventZone::= EventHistory
   ((WITH COMPONENT (WITH COMPONENTS {..., eventDeltaTime PRESENT})) |
    (WITH COMPONENT (WITH COMPONENTS {..., eventDeltaTime ABSENT})))
```

### <a name="GeneralizedLanePosition"></a>GeneralizedLanePosition
This DF indicates a transversal position in relation to the different lanes of the road. 
 It is an extension of DE_LanePosition to cover locations (sidewalks, bicycle paths), where Vehicle ITS-S would normally not be present. 

 The following options are available:

* _trafficLanePosition_ of type [**LanePosition**](ETSI-ITS-CDD.md#LanePosition) <br>
  a position on a traffic lane. 

* _nonTrafficLanePosition_ of type [**LanePositionAndType**](#LanePositionAndType) <br>
  a position on a lane which is not a traffic lane.

* _trafficIslandPosition_ of type [**TrafficIslandPosition**](#TrafficIslandPosition) <br>
  a position on a traffic island

* _mapPosition_ of type [**MapPosition**](#MapPosition) <br>
  a position on a lane identified in a MAPEM.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Road Topology information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _created in V2.1.1_
```asn1
GeneralizedLanePosition::= CHOICE {
    trafficLanePosition       LanePosition,
    nonTrafficLanePosition    LanePositionAndType,
    trafficIslandPosition     TrafficIslandPosition,
    mapPosition               MapPosition,
    ...
}
```

### <a name="Heading"></a>Heading
This DF represents the Heading in a WGS84 co-ordinates system.
 The specific WGS84 coordinate system is specified by the corresponding standards applying this DE.

 It shall include the following components:

* _headingValue_ of type [**HeadingValue**](#HeadingValue) <br>
  the heading value.

* _headingConfidence_ of type [**HeadingConfidence**](#HeadingConfidence) <br>
  the confidence value of the heading value with a predefined confidence level.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Kinematic Information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Description revised in V2.1.1_

>>>
NOTE:&emsp;this DF is kept for backwards compatibility reasons only. It is recommended to use the [**Wgs84Angle**](ETSI-ITS-CDD.md#Wgs84Angle) instead.
>>>
```asn1
Heading ::= SEQUENCE {
    headingValue         HeadingValue,
    headingConfidence    HeadingConfidence
}
```

### <a name="HeadingChangeIndication"></a>HeadingChangeIndication
This DF  provides  information  associated to heading  change indicators  such as  a  change  of  direction.

 It shall include the following components:

* _direction_ of type [**TurningDirection**](#TurningDirection) <br>
  the direction of heading change value.

* _actionDeltaTime_ of type [**DeltaTimeTenthOfSecond**](#DeltaTimeTenthOfSecond) <br>
  the period over which a direction change action is performed. 


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Kinematic Information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _created in V2.1.1_
```asn1
HeadingChangeIndication ::= SEQUENCE {
    direction          TurningDirection,
    actionDeltaTime    DeltaTimeTenthOfSecond,
    ...
}
```

### <a name="InterferenceManagementChannel"></a>InterferenceManagementChannel
This DF represents a frequency channel 

 It shall include the following components:

* _centreFrequency_ of type **INTEGER**  (1 .. 99999)<br>
  the centre frequency of the channel in 10<sup>(exp+2)</sup> Hz (where exp is exponent)

* _channelWidth_ of type **INTEGER**  (0 .. 9999)<br>
  width of the channel in 10<sup>exp</sup> Hz (where exp is exponent)

* _exponent_ of type **INTEGER**  (0 .. 15)<br>
  exponent of the power of 10 used in the calculation of the components above.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Communication information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _created in V2.1.1_
```asn1
InterferenceManagementChannel ::= SEQUENCE {
    centreFrequency    INTEGER (1 .. 99999),
    channelWidth       INTEGER (0 .. 9999),
    exponent           INTEGER (0 .. 15) 
}
```

### <a name="InterferenceManagementZone"></a>InterferenceManagementZone
This DF represents a zone  inside which the ITS communication should be restricted in order to manage interference.

 It shall include the following components:

* _zoneDefinition_ of type [**InterferenceManagementZoneDefinition**](#InterferenceManagementZoneDefinition) <br>
  contains the geographical definition of the zone.

* _managementInfo_ of type [**InterferenceManagementInfo**](#InterferenceManagementInfo) <br>
  contains interference management information applicable in the zone defined in the component zoneDefinition.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Communication information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _created in V2.1.1_
```asn1
InterferenceManagementZone ::= SEQUENCE {
	zoneDefinition    InterferenceManagementZoneDefinition,
	managementInfo    InterferenceManagementInfo
}
```

### <a name="InterferenceManagementZoneDefinition"></a>InterferenceManagementZoneDefinition
This DF represents the geographical definition of the zone where band sharing occurs. 

 It shall include the following components:

* _interferenceManagementZoneLatitude_ of type [**Latitude**](#Latitude) <br>
  Latitude of the centre point of the interference management zone.

* _interferenceManagementZoneLongitude_ of type [**Longitude**](#Longitude) <br>
  Longitude of the centre point of the interference management zone.

* _interferenceManagementZoneId_ of type [**ProtectedZoneId**](#ProtectedZoneId)  OPTIONAL<br>
  optional identification of the interference management zone. 

* _interferenceManagementZoneShape_ of type [**Shape**](#Shape)  (WITH COMPONENTS{..., radial ABSENT, radialShapes ABSENT}) OPTIONAL<br>
  shape of the interference management zone placed at the centre point. 


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Communication information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _created in V2.1.1_
```asn1
InterferenceManagementZoneDefinition::= SEQUENCE{     
    interferenceManagementZoneLatitude     Latitude, 
    interferenceManagementZoneLongitude    Longitude, 
    interferenceManagementZoneId           ProtectedZoneId OPTIONAL,
    interferenceManagementZoneShape        Shape (WITH COMPONENTS{..., radial ABSENT, radialShapes ABSENT}) OPTIONAL,
    ...
}
```

### <a name="InterferenceManagementInfo"></a>InterferenceManagementInfo
This DF shall contain a list of up to 16 definitions containing interference management information, per affected frequency channels.

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Communication information. 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _created in V2.1.1_
```asn1
InterferenceManagementInfo::= SEQUENCE (SIZE(1..16,...)) OF InterferenceManagementInfoPerChannel
```

### <a name="InterferenceManagementInfoPerChannel"></a>InterferenceManagementInfoPerChannel
This DF contains interference management information for one affected frequency channel.

 It shall include the following components:

* _interferenceManagementChannel_ of type [**InterferenceManagementChannel**](#InterferenceManagementChannel) <br>
  frequency channel for which the zone should be applied interference management 

* _interferenceManagementZoneType_ of type [**InterferenceManagementZoneType**](#InterferenceManagementZoneType) <br>
  type of the interference management zone. 

* _interferenceManagementMitigationType_ of type [**MitigationForTechnologies**](#MitigationForTechnologies)  OPTIONAL<br>
  optional type of the mitigation to be used in the interference management zone. 
   In the case where no mitigation should be applied by the ITS-S, this is indicated by the field interferenceManagementMitigationType being absent.

* _expiryTime_ of type [**TimestampIts**](#TimestampIts)  OPTIONAL<br>
  optional time at which the validity of the interference management communication zone will expire. 
   This component is present when the interference management is temporarily valid


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Communication information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _created in V2.1.1_
```asn1
InterferenceManagementInfoPerChannel ::= SEQUENCE {
    interferenceManagementChannel           InterferenceManagementChannel,
    interferenceManagementZoneType          InterferenceManagementZoneType,
    interferenceManagementMitigationType    MitigationForTechnologies OPTIONAL,
    expiryTime                              TimestampIts OPTIONAL, 
    ...
}
```

### <a name="InterferenceManagementZones"></a>InterferenceManagementZones
This DF shall contain a list of up to 16 interference  management zones.  

 **EXAMPLE**: An interference management communication zone may be defined around a CEN DSRC road side equipment or an urban rail operational area.

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Communication information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _created in V2.1.1_
```asn1
InterferenceManagementZones ::= SEQUENCE (SIZE(1..16), ...) OF InterferenceManagementZone
```

### <a name="IntersectionReferenceId"></a>IntersectionReferenceId
This DF represents a unique id for an intersection, in accordance with ETSI TS 103 301 [[15]](#references).

 It shall include the following components:

* _region_ of type [**Identifier2B**](#Identifier2B)  OPTIONAL<br>
  the optional identifier of the entity that is responsible for the region in which the intersection is placed.
   It is the duty of that entity to guarantee that the [**Id**](#Id) is unique within the region.

* _id_ of type [**Identifier2B**](#Identifier2B) <br>
  the identifier of the intersection


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Road topology information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _created in V2.1.1_

>>>
NOTE:&emsp;when the component region is present, the IntersectionReferenceId is guaranteed to be globally unique.
>>>
```asn1
IntersectionReferenceId ::= SEQUENCE {
    region    Identifier2B OPTIONAL,
    id        Identifier2B
}
```

### <a name="ItineraryPath"></a>ItineraryPath
This DF shall contain  a list of waypoints [**ReferencePosition**](#ReferencePosition).

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** GeoReference information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Editorial update in V2.1.1_
```asn1
ItineraryPath ::= SEQUENCE SIZE(1..40) OF ReferencePosition
```

### <a name="ItsPduHeader"></a>ItsPduHeader
This DF represents a common message header for application and facilities layer messages.
 It is included at the beginning of an ITS message as the message header.

 It shall include the following components:

* _protocolVersion_ of type [**OrdinalNumber1B**](#OrdinalNumber1B) <br>
  version of the ITS message.

* _messageId_ of type [**MessageId**](#MessageId) <br>
  type of the ITS message.

* _stationId_ of type [**StationId**](ETSI-ITS-CDD.md#StationId) <br>
  the identifier of the ITS-S that generated the ITS message.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Communication information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _update in V2.1.1: messageID and stationID changed to messageId and stationId; messageId is of type MessageId._
```asn1
ItsPduHeader ::= SEQUENCE {
    protocolVersion    OrdinalNumber1B,
    messageId          MessageId,
    stationId          StationId
}
```

### <a name="LanePositionAndType"></a>LanePositionAndType
This DF indicates a transversal position in resolution of lanes and the associated lane type.

 It shall include the following components:

* _transversalPosition_ of type [**LanePosition**](ETSI-ITS-CDD.md#LanePosition) <br>
  the transversal position.

* _laneType_ of type [**LaneType**](#LaneType) <br>
  the type of the lane identified in the component transversalPosition.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Road topology information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
LanePositionAndType::= SEQUENCE {
    transversalPosition    LanePosition,
    laneType               LaneType,
    ...
}
```

### <a name="LateralAcceleration"></a>LateralAcceleration
This DF indicates the vehicle acceleration at lateral direction and the confidence value of the lateral acceleration.

 It shall include the following components:

* _lateralAccelerationValue_ of type [**LateralAccelerationValue**](#LateralAccelerationValue) <br>
  lateral acceleration value at a point in time.

* _lateralAccelerationConfidence_ of type [**AccelerationConfidence**](#AccelerationConfidence) <br>
  confidence value of the lateral acceleration value.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Vehicle information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Description revised in V2.1.1_

>>>
NOTE:&emsp;this DF is kept for backwards compatibility reasons only. It is recommended to use [**AccelerationComponent**](#AccelerationComponent) instead.
>>>
```asn1
LateralAcceleration ::= SEQUENCE {
    lateralAccelerationValue         LateralAccelerationValue,
    lateralAccelerationConfidence    AccelerationConfidence
}
```

### <a name="LongitudinalAcceleration"></a>LongitudinalAcceleration
This DF indicates the vehicle acceleration at longitudinal direction and the confidence value of the longitudinal acceleration.

 It shall include the following components:

* _longitudinalAccelerationValue_ of type [**LongitudinalAccelerationValue**](#LongitudinalAccelerationValue) <br>
  longitudinal acceleration value at a point in time.

* _longitudinalAccelerationConfidence_ of type [**AccelerationConfidence**](#AccelerationConfidence) <br>
  confidence value of the longitudinal acceleration value.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Vehicle information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V1.3.1_

>>>
NOTE:&emsp;this DF is kept for backwards compatibility reasons only. It is recommended to use [**AccelerationComponent**](#AccelerationComponent) instead.
>>>
```asn1
LongitudinalAcceleration ::= SEQUENCE {
    longitudinalAccelerationValue         LongitudinalAccelerationValue,
    longitudinalAccelerationConfidence    AccelerationConfidence
}
```

### <a name="LongitudinalLanePosition"></a>LongitudinalLanePosition
This DF represents the estimated position along the longitudinal length of a particular lane. 

 It shall include the following components:

* _longitudinalLanePositionValue_ of type [**LongitudinalLanePositionValue**](#LongitudinalLanePositionValue) <br>
  the mean value of the longitudinal position within a particular length.

* _longitudinalLanePositionConfidence_ of type [**LongitudinalLanePositionConfidence**](#LongitudinalLanePositionConfidence) <br>
  The confidence value associated to the value.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Road topology information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _created in V2.1.1_
```asn1
LongitudinalLanePosition ::= SEQUENCE {
    longitudinalLanePositionValue         LongitudinalLanePositionValue,
    longitudinalLanePositionConfidence    LongitudinalLanePositionConfidence
}
```

### <a name="LowerTriangularPositiveSemidefiniteMatrices"></a>LowerTriangularPositiveSemidefiniteMatrices
This DF shall contain a list of a lower triangular positive semi-definite matrices.

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Sensing information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
LowerTriangularPositiveSemidefiniteMatrices::= SEQUENCE SIZE (1..4) OF LowerTriangularPositiveSemidefiniteMatrix
```

### <a name="LowerTriangularPositiveSemidefiniteMatrix"></a>LowerTriangularPositiveSemidefiniteMatrix
This DF represents a lower triangular positive semi-definite matrix. 

 It shall include the following components:

* _componentsIncludedIntheMatrix_ of type [**MatrixIncludedComponents**](#MatrixIncludedComponents) <br>
  the indication of which components of a [**PerceivedObject**](#PerceivedObject) are included in the matrix. 
   This component also implicitly indicates the number n of included components which defines the size (n x n) of the full correlation matrix "A".

* _matrix_ of type [**LowerTriangularPositiveSemidefiniteMatrixColumns**](#LowerTriangularPositiveSemidefiniteMatrixColumns) <br>
  the list of cells of the lower triangular positive semi-definite matrix ordered by columns and by rows. 

The number of columns to be included "k" is equal to the number of included components "n" indicated by componentsIncludedIntheMatrix minus 1: k = n-1.
 These components shall be included in the order or their appearance in componentsIncludedIntheMatrix.
 Each column "i" of the lowerTriangularCorrelationMatrixColumns contains k-(i-1) values.

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Sensing information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
LowerTriangularPositiveSemidefiniteMatrix ::= SEQUENCE{
    componentsIncludedIntheMatrix   MatrixIncludedComponents,
    matrix                          LowerTriangularPositiveSemidefiniteMatrixColumns
}
```

### <a name="LowerTriangularPositiveSemidefiniteMatrixColumns"></a>LowerTriangularPositiveSemidefiniteMatrixColumns
This DF represents the columns of a lower triangular positive semi-definite matrix, each column not including the main diagonal cell of the matrix.
 Given a matrix "A" of size n x n, the number of [**CorrelationColumn**](#CorrelationColumn) to be included in the lower triangular matrix is k=n-1.

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Sensing information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
LowerTriangularPositiveSemidefiniteMatrixColumns ::= SEQUENCE SIZE (1..13) OF CorrelationColumn
```

### <a name="MapPosition"></a>MapPosition
This DF indicates a position on a topology description transmitted in a MAPEM according to ETSI TS 103 301 [[15]](#references).

 It shall include the following components:

* _mapReference_ of type [**MapReference**](#MapReference)  OPTIONAL<br>
  optionally identifies the MAPEM containing the topology information.
   It is absent if the MAPEM topology is known from the context.

* _laneId_ of type [**Identifier1B**](#Identifier1B)  OPTIONAL<br>
  optionally identifies the lane in the road segment or intersection topology on which the position is located.

* _connectionId_ of type [**Identifier1B**](#Identifier1B)  OPTIONAL<br>
  optionally identifies the connection inside the conflict area of an intersection, i.e. it identifies a trajectory for travelling through the
   conflict area of an intersection which connects e.g an ingress with an egress lane.

* _longitudinalLanePosition_ of type [**LongitudinalLanePosition**](#LongitudinalLanePosition)  OPTIONAL<br>
  optionally indicates the longitudinal offset of the map-matched position of the object along the lane or connection.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Road topology information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
MapPosition ::= SEQUENCE {
    mapReference                MapReference OPTIONAL,
    laneId                      Identifier1B OPTIONAL,
    connectionId                Identifier1B OPTIONAL, 
    longitudinalLanePosition    LongitudinalLanePosition OPTIONAL,
    ...
}
   ((WITH COMPONENTS {..., laneId PRESENT, connectionId ABSENT }) |
    (WITH COMPONENTS {..., laneId ABSENT, connectionId PRESENT }))
```

### <a name="MapReference"></a>MapReference
This DF provides the reference to the information contained in a MAPEM according to ETSI TS 103 301 [[15]](#references). 

 The following options are provided:

* _roadsegment_ of type [**RoadSegmentReferenceId**](#RoadSegmentReferenceId) <br>
  option that identifies the description of a road segment contained in a MAPEM.

* _intersection_ of type [**IntersectionReferenceId**](#IntersectionReferenceId) <br>
  option that identifies the description of an intersection contained in a MAPEM.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Road topology information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
MapReference::= CHOICE {
	roadsegment     RoadSegmentReferenceId,
	intersection    IntersectionReferenceId
	}
```

### <a name="MessageRateHz"></a>MessageRateHz
This DE indicates a message rate.

* _mantissa_ of type **INTEGER**  (1..100)<br>
  indicates the mantissa.

* _exponent_ of type **INTEGER**  (-5..2)<br>
  indicates the exponent.

The specified message rate is: mantissa*(10<sup>exponent</sup>)

&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _Hz_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Communication information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
MessageRateHz::= SEQUENCE {
    mantissa    INTEGER (1..100),
    exponent    INTEGER (-5..2)
    }
```

### <a name="MessageSegmentationInfo"></a>MessageSegmentationInfo
This DF provides information about a message with respect to the segmentation process at the sender.

 It shall include the following components:

* _totalMsgNo_ of type [**CardinalNumber3b**](#CardinalNumber3b) <br>
  indicates the total number of messages that has been used on the transmitter side to encode the information.

* _thisMsgNo_ of type [**OrdinalNumber3b**](#OrdinalNumber3b) <br>
  indicates the position of the message within of the total set of messages.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Communication information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
MessageSegmentationInfo ::= SEQUENCE {
    totalMsgNo  CardinalNumber3b,
    thisMsgNo   OrdinalNumber3b
    }
```

### <a name="MitigationForTechnologies"></a>MitigationForTechnologies
This DF shall contain a list of [**MitigationPerTechnologyClass**](#MitigationPerTechnologyClass).

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Communication information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
MitigationForTechnologies ::= SEQUENCE (SIZE(1..8)) OF MitigationPerTechnologyClass
```

### <a name="MitigationPerTechnologyClass"></a>MitigationPerTechnologyClass
This DF represents a set of mitigation parameters for a specific technology, as specified in ETSI TS 103 724 [[24]](#references), clause 7.

 It shall include the following components:

* _accessTechnologyClass_ of type [**AccessTechnologyClass**](#AccessTechnologyClass) <br>
  channel access technology to which this mitigation is intended to be applied.

* _lowDutyCycle_ of type **INTEGER**  (0 .. 10000) OPTIONAL<br>
  duty cycle limit.

* _powerReduction_ of type **INTEGER**  (0 .. 30) OPTIONAL<br>
  the delta value of power to be reduced.

* _dmcToffLimit_ of type **INTEGER**  (0 .. 1200) OPTIONAL<br>
  idle time limit as defined in ETSI TS 103 175 [[19]](#references).

* _dmcTonLimit_ of type **INTEGER**  (0 .. 20) OPTIONAL<br>
  Transmission duration limit, as defined in ETSI EN 302 571 [[20]](#references).


&nbsp;&nbsp;&nbsp;&nbsp;**Unit:** _ms_

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Communication information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_

>>>
NOTE:&emsp;All parameters are optional, as they may not apply to some of the technologies or
 interference management zone types. Specification details are in ETSI TS 103 724 [[24]](#references), clause 7.
>>>
```asn1
MitigationPerTechnologyClass ::= SEQUENCE {
   accessTechnologyClass    AccessTechnologyClass, 
   lowDutyCycle             INTEGER (0 .. 10000) OPTIONAL, 
   powerReduction           INTEGER (0 .. 30) OPTIONAL,
   dmcToffLimit             INTEGER (0 .. 1200) OPTIONAL,   
   dmcTonLimit              INTEGER (0 .. 20) OPTIONAL,   
   ...
}
```

### <a name="ObjectClass"></a>ObjectClass
This DF indicates both the class and associated subclass that best describes an object.

 The following options are available:

* _vehicleSubClass_ of type [**TrafficParticipantType**](#TrafficParticipantType)  (unknown|passengerCar..tram|agricultural)<br>
  the object is a road vehicle and the specific subclass is specified.

* _vruSubClass_ of type [**VruProfileAndSubprofile**](ETSI-ITS-CDD.md#VruProfileAndSubprofile) <br>
  the object is a VRU and the specific subclass is specified.

* _groupSubClass_ of type [**VruClusterInformation**](ETSI-ITS-CDD.md#VruClusterInformation)  (WITH COMPONENTS{..., clusterBoundingBoxShape ABSENT})<br>
  the object is a VRU group or cluster and the cluster information is specified.

* _otherSubClass_ of type [**OtherSubClass**](#OtherSubClass) <br>
  the object is of a different type than the above and the specific subclass is specified.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Sensing information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
ObjectClass ::= CHOICE {
    vehicleSubClass      TrafficParticipantType (unknown|passengerCar..tram|agricultural),
    vruSubClass          VruProfileAndSubprofile,
    groupSubClass        VruClusterInformation (WITH COMPONENTS{..., clusterBoundingBoxShape ABSENT}),
    otherSubClass        OtherSubClass,
    ...
}
```

### <a name="ObjectClassDescription"></a>ObjectClassDescription
This DF shall contain a list of object classes.

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Sensing information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
ObjectClassDescription ::= SEQUENCE (SIZE(1..8)) OF ObjectClassWithConfidence
```

### <a name="ObjectClassWithConfidence"></a>ObjectClassWithConfidence
This DF represents the classification of a detected object together with a confidence level.

 It shall include the following components:

* _objectClass_ of type [**ObjectClass**](#ObjectClass) <br>
  the class of the object.

* _confidence_ of type [**ConfidenceLevel**](#ConfidenceLevel) <br>
* Confidence<br>
  the associated confidence level.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Sensing information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
ObjectClassWithConfidence ::= SEQUENCE {
    objectClass    ObjectClass,
    confidence     ConfidenceLevel
}
```

### <a name="ObjectDimension"></a>ObjectDimension
This DF represents a dimension of an object together with a confidence value.

 It shall include the following components:

* _value_ of type [**ObjectDimensionValue**](#ObjectDimensionValue) <br>
  the object dimension value which can be estimated as the mean of the current distribution.

* _confidence_ of type [**ObjectDimensionConfidence**](#ObjectDimensionConfidence) <br>
  the associated confidence value.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Sensing information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
ObjectDimension ::= SEQUENCE {
    value         ObjectDimensionValue,
    confidence    ObjectDimensionConfidence
}
```

### <a name="Path"></a>Path
This DF represents a path with a set of path points.
 It shall contain up to `40` [**PathPoint**](#PathPoint). 
 
 The first PathPoint presents an offset delta position with regards to an external reference position.
 Each other PathPoint presents an offset delta position and optionally an offset travel time with regards to the previous PathPoint.

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** GeoReference information Vehicle information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _created in V2.1.1 based on PathHistory_
```asn1
Path::= SEQUENCE (SIZE(0..40)) OF PathPoint
```

### <a name="PathHistory"></a>PathHistory
This DF represents a path history with a set of path points.
 It shall contain up to `40` [**PathPoint**](#PathPoint). 
 
 The first PathPoint presents an offset delta position with regards to an external reference position.
 Each other PathPoint presents an offset delta position and optionally an offset travel time with regards to the previous PathPoint.

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** GeoReference information Vehicle information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _semantics updated in V2.1.1_

>>>
NOTE:&emsp;this DF is kept for backwards compatibility reasons only. It is recommended to use [**Path**](#Path) instead.
>>>
```asn1
PathHistory::= SEQUENCE (SIZE(40)) OF PathPoint
```

### <a name="PathPredicted"></a>PathPredicted
This DF represents a predicted path with a set of path points.
 It shall contain up to `15` [**PathPoint**](#PathPoint). 
 
 The first PathPoint presents an offset delta position with regards to an external reference position.
 Each other PathPoint presents an offset delta position and optionally an offset travel time with regards to the previous PathPoint.

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** GeoReference information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _created in V2.1.1 based on PathHistory_
```asn1
PathPredicted::= SEQUENCE (SIZE(0..15,...)) OF PathPointPredicted
```

### <a name="PathPoint"></a>PathPoint
This DF defines an offset waypoint position within a path.

 It shall include the following components:

* _pathPosition_ of type [**DeltaReferencePosition**](#DeltaReferencePosition) <br>
  The waypoint position defined as an offset position with regards to a pre-defined reference position. 

* _pathDeltaTime_ of type [**PathDeltaTime**](#PathDeltaTime)  OPTIONAL<br>
  The optional travel time separated from a waypoint to the predefined reference position.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** GeoReference information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _semantics updated in V2.1.1_
```asn1
PathPoint ::= SEQUENCE {
    pathPosition     DeltaReferencePosition,
    pathDeltaTime    PathDeltaTime OPTIONAL
}
```

### <a name="PathPointPredicted"></a>PathPointPredicted
This DF  defines a predicted offset waypoint position within a path.

 It shall include the following components:

* _deltaLatitude_ of type [**DeltaLatitude**](#DeltaLatitude) <br>
  an offset latitude with regards to a pre-defined reference position. 

* _deltaLongitude_ of type [**DeltaLongitude**](#DeltaLongitude) <br>
  an offset longitude with regards to a pre-defined reference position. 

* _horizontalPositionConfidence_ of type [**PosConfidenceEllipse**](#PosConfidenceEllipse)  OPTIONAL<br>
  the confidence value associated to the horizontal geographical position.

* _deltaAltitude_ of type [**DeltaAltitude**](#DeltaAltitude)  DEFAULT unavailable<br>
  an offset altitude with regards to a pre-defined reference position. 

* _altitudeConfidence_ of type [**AltitudeConfidence**](#AltitudeConfidence)  DEFAULT unavailable<br>
  the confidence value associated to the altitude value of the geographical position.

* _pathDeltaTime_ of type [**DeltaTimeTenthOfSecond**](#DeltaTimeTenthOfSecond) <br>
  The  travel time separated from the waypoint to the predefined reference position.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** GeoReference information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _semantics updated in V2.1.1_
```asn1
PathPointPredicted::= SEQUENCE {
  deltaLatitude                 DeltaLatitude,      
  deltaLongitude                DeltaLongitude, 
  horizontalPositionConfidence  PosConfidenceEllipse OPTIONAL,   
  deltaAltitude                 DeltaAltitude DEFAULT unavailable, 
  altitudeConfidence            AltitudeConfidence DEFAULT unavailable,
  pathDeltaTime                 DeltaTimeTenthOfSecond,
  ... 
}
```

### <a name="PerceivedObject"></a>PerceivedObject
This DF contains information about a perceived object including its kinematic state and attitude vector in a pre-defined coordinate system and with respect to a reference time.
 
 It shall include the following components:

* _objectId_ of type [**Identifier2B**](#Identifier2B)  OPTIONAL<br>
  optional identifier assigned to a detected object.

* _measurementDeltaTime_ of type [**DeltaTimeMilliSecondSigned**](#DeltaTimeMilliSecondSigned) <br>
  the time difference from a reference time to the time of the  measurement of the object. 
   Negative values indicate that the provided object state refers to a point in time before the reference time.

* _position_ of type [**CartesianPosition3dWithConfidence**](#CartesianPosition3dWithConfidence) <br>
  the position of the geometric centre of the object's bounding box within the pre-defined coordinate system.

* _velocity_ of type [**Velocity3dWithConfidence**](#Velocity3dWithConfidence)  OPTIONAL<br>
  the velocity vector of the object within the pre-defined coordinate system.

* _acceleration_ of type [**Acceleration3dWithConfidence**](#Acceleration3dWithConfidence)  OPTIONAL<br>
  the acceleration vector of the object within the pre-defined coordinate system.

* _angles_ of type [**EulerAnglesWithConfidence**](#EulerAnglesWithConfidence)  OPTIONAL<br>
  optional Euler angles of the object bounding box at the time of measurement. 

* _zAngularVelocity_ of type [**CartesianAngularVelocityComponent**](#CartesianAngularVelocityComponent)  OPTIONAL<br>
  optional angular velocity of the object around the z-axis at the time of measurement.
   The angular velocity is measured with positive values considering the object orientation turning around the z-axis using the right-hand rule.

* _lowerTriangularCorrelationMatrices_ of type [**LowerTriangularPositiveSemidefiniteMatrices**](#LowerTriangularPositiveSemidefiniteMatrices)  OPTIONAL<br>
  optional set of lower triangular correlation matrices for selected components of the provided kinematic state and attitude vector.

* _objectDimensionZ_ of type [**ObjectDimension**](#ObjectDimension)  OPTIONAL<br>
  optional z-dimension of object bounding box. 
   This dimension shall be measured along the direction of the z-axis after all the rotations have been applied. 

* _objectDimensionY_ of type [**ObjectDimension**](#ObjectDimension)  OPTIONAL<br>
  optional y-dimension of the object bounding box. 
   This dimension shall be measured along the direction of the y-axis after all the rotations have been applied. 

* _objectDimensionX_ of type [**ObjectDimension**](#ObjectDimension)  OPTIONAL<br>
  optional x-dimension of object bounding box.
   This dimension shall be measured along the direction of the x-axis after all the rotations have been applied.

* _objectAge_ of type [**DeltaTimeMilliSecondSigned**](#DeltaTimeMilliSecondSigned)  (0..2047) OPTIONAL<br>
  optional age of the detected and described object, i.e. the difference in time between the moment 
   it has been first detected and the reference time of the message. Value `1500` indicates that the object has been observed for more than 1.5s.

* _objectPerceptionQuality_ of type [**ObjectPerceptionQuality**](#ObjectPerceptionQuality)  OPTIONAL<br>
  optional confidence associated to the object. 

* _sensorIdList_ of type [**SequenceOfIdentifier1B**](#SequenceOfIdentifier1B)  OPTIONAL<br>
  optional list of sensor-IDs which provided the measurement data. 

* _classification_ of type [**ObjectClassDescription**](#ObjectClassDescription)  OPTIONAL<br>
  optional classification of the described object

* _mapPosition_ of type [**MapPosition**](#MapPosition)  OPTIONAL<br>
* matchedPosition<br>
  optional map-matched position of an object.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Sensing information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _created in V2.1.1_
```asn1
PerceivedObject ::= SEQUENCE {
    objectId                                          Identifier2B OPTIONAL,
    measurementDeltaTime                              DeltaTimeMilliSecondSigned,
    position                                          CartesianPosition3dWithConfidence, 
    velocity                                          Velocity3dWithConfidence OPTIONAL,
    acceleration                                      Acceleration3dWithConfidence OPTIONAL,
    angles                                            EulerAnglesWithConfidence OPTIONAL,
    zAngularVelocity                                  CartesianAngularVelocityComponent OPTIONAL,
    lowerTriangularCorrelationMatrices                LowerTriangularPositiveSemidefiniteMatrices OPTIONAL,
    objectDimensionZ                                  ObjectDimension OPTIONAL,
    objectDimensionY                                  ObjectDimension OPTIONAL,
    objectDimensionX                                  ObjectDimension OPTIONAL,
    objectAge                                         DeltaTimeMilliSecondSigned (0..2047) OPTIONAL,
    objectPerceptionQuality                           ObjectPerceptionQuality OPTIONAL,
    sensorIdList                                      SequenceOfIdentifier1B OPTIONAL,
    classification                                    ObjectClassDescription OPTIONAL,
    mapPosition                                       MapPosition OPTIONAL,
    ...
}
```

### <a name="PolygonalShape"></a>PolygonalShape
This DF represents the shape of a polygonal area or of a right prism.

 It shall include the following components:

* _shapeReferencePoint_ of type [**CartesianPosition3d**](#CartesianPosition3d)  OPTIONAL<br>
  the optional reference point used for the definition of the shape, relative to an externally specified reference position. 
   If this component is absent, the externally specified reference position represents the shape's reference point. 

* _polygon_ of type [**SequenceOfCartesianPosition3d**](#SequenceOfCartesianPosition3d)  (SIZE(3..16,...))<br>
  the polygonal area represented by a list of minimum `3` to maximum `16` [**CartesianPosition3d**](#CartesianPosition3d).
   All nodes of the polygon shall be considered relative to the shape's reference point.

* _height_ of type [**StandardLength12b**](#StandardLength12b)  OPTIONAL<br>
  the optional height, present if the shape is a right prism extending in the positive z-axis.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** GeoReference information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _created in V2.1.1_
```asn1
PolygonalShape ::= SEQUENCE {
   shapeReferencePoint    CartesianPosition3d OPTIONAL,
   polygon                SequenceOfCartesianPosition3d (SIZE(3..16,...)),
   height                 StandardLength12b OPTIONAL
}
```

### <a name="PosConfidenceEllipse"></a>PosConfidenceEllipse
This DF indicates the horizontal position confidence ellipse which represents the estimated accuracy with a 
 confidence level of 95  %. The centre of the ellipse shape corresponds to the reference
 position point for which the position accuracy is evaluated.

 It shall include the following components:

* _semiMajorConfidence_ of type [**SemiAxisLength**](#SemiAxisLength) <br>
  half of length of the major axis, i.e. distance between the centre point
   and major axis point of the position accuracy ellipse. 

* _semiMinorConfidence_ of type [**SemiAxisLength**](#SemiAxisLength) <br>
  half of length of the minor axis, i.e. distance between the centre point
   and minor axis point of the position accuracy ellipse. 

* _semiMajorOrientation_ of type [**HeadingValue**](#HeadingValue) <br>
  orientation direction of the ellipse major axis of the position accuracy
   ellipse with regards to the WGS84 north. 
   The specific WGS84 coordinate system is specified by the corresponding standards applying this DE.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** GeoReference information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V1.3.1_
```asn1
PosConfidenceEllipse ::= SEQUENCE {
    semiMajorConfidence     SemiAxisLength,
    semiMinorConfidence     SemiAxisLength,
    semiMajorOrientation    HeadingValue
}
```

### <a name="PositionConfidenceEllipse"></a>PositionConfidenceEllipse
This DF indicates the horizontal position confidence ellipse which represents the estimated accuracy with a 
 confidence level of 95 %. The centre of the ellipse shape corresponds to the reference
 position point for which the position accuracy is evaluated.

 It shall include the following components:

* _semiMajorAxisLength_ of type [**SemiAxisLength**](#SemiAxisLength) <br>
  half of length of the major axis, i.e. distance between the centre point
   and major axis point of the position accuracy ellipse. 

* _semiMinorAxisLength_ of type [**SemiAxisLength**](#SemiAxisLength) <br>
  half of length of the minor axis, i.e. distance between the centre point
   and minor axis point of the position accuracy ellipse. 

* _semiMajorAxisOrientation_ of type [**Wgs84AngleValue**](#Wgs84AngleValue) <br>
  orientation direction of the ellipse major axis of the position accuracy
   ellipse with regards to the WGS84 north. 
   The specific WGS84 coordinate system is specified by the corresponding standards applying this DE.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** GeoReference information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _created in V2.1.1 based on [**PosConfidenceEllipse**](#PosConfidenceEllipse)_
```asn1
PositionConfidenceEllipse ::= SEQUENCE {
    semiMajorAxisLength         SemiAxisLength,
    semiMinorAxisLength         SemiAxisLength,
    semiMajorAxisOrientation    Wgs84AngleValue
}
```

### <a name="PositionOfPillars"></a>PositionOfPillars
This DF shall contain a list of distances [**PosPillar**](#PosPillar) that refer to the perpendicular distance between centre of vehicle front bumper
 and vehicle pillar A, between neighbour pillars until the last pillar of the vehicle.

 Vehicle pillars refer to the vertical or near vertical support of vehicle,
 designated respectively as the A, B, C or D and other pillars moving in side profile view from the front to rear.
 
 The first value of the DF refers to the perpendicular distance from the centre of vehicle front bumper to 
 vehicle A pillar. The second value refers to the perpendicular distance from the centre position of A pillar
 to the B pillar of vehicle and so on until the last pillar.

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Vehicle information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V1.3.1_
```asn1
PositionOfPillars ::= SEQUENCE (SIZE(1..3, ...)) OF PosPillar
```

### <a name="ProtectedCommunicationZone"></a>ProtectedCommunicationZone
This DF describes a zone of protection inside which the ITS communication should be restricted.

 It shall include the following components:

* _protectedZoneType_ of type [**ProtectedZoneType**](#ProtectedZoneType) <br>
  type of the protected zone. 

* _expiryTime_ of type [**TimestampIts**](#TimestampIts)  OPTIONAL<br>
  optional time at which the validity of the protected communication zone will expire.

* _protectedZoneLatitude_ of type [**Latitude**](#Latitude) <br>
  latitude of the centre point of the protected communication zone.

* _protectedZoneLongitude_ of type [**Longitude**](#Longitude) <br>
  longitude of the centre point of the protected communication zone.

* _protectedZoneRadius_ of type [**ProtectedZoneRadius**](#ProtectedZoneRadius)  OPTIONAL<br>
  optional radius of the protected communication zone in metres.

* _protectedZoneId_ of type [**ProtectedZoneId**](#ProtectedZoneId)  OPTIONAL<br>
  the optional ID of the protected communication zone.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Infrastructure information Communication information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _revised in V2.1.1 (changed protectedZoneID to protectedZoneId)_

>>>
NOTE:&emsp;A protected communication zone may be defined around a CEN DSRC road side equipment.
>>>
```asn1
ProtectedCommunicationZone ::= SEQUENCE {
    protectedZoneType         ProtectedZoneType,
    expiryTime                TimestampIts OPTIONAL,
    protectedZoneLatitude     Latitude,
    protectedZoneLongitude    Longitude,
    protectedZoneRadius       ProtectedZoneRadius OPTIONAL,
    protectedZoneId           ProtectedZoneId OPTIONAL,
    ...
}
```

### <a name="ProtectedCommunicationZonesRSU"></a>ProtectedCommunicationZonesRSU
This DF shall contain a list of [**ProtectedCommunicationZone**](#ProtectedCommunicationZone) provided by a road side ITS-S (Road Side Unit RSU).

 It may provide up to 16 protected communication zones information.

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Infrastructure information Communication information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V1.3.1_
```asn1
ProtectedCommunicationZonesRSU ::= SEQUENCE (SIZE(1..16)) OF ProtectedCommunicationZone
```

### <a name="PtActivation"></a>PtActivation
This DF represents activation data for real-time systems designed for operations control, traffic light priorities, track switches, barriers, etc.
 using a range of activation devices equipped in public transport vehicles.

 The activation of the corresponding equipment is triggered by the approach or passage of a public transport
 vehicle at a certain point (e.g. a beacon).

* _ptActivationType_ of type [**PtActivationType**](#PtActivationType) <br>
  type of activation. 

* _ptActivationData_ of type [**PtActivationData**](#PtActivationData) <br>
* ptActicationData<br>
  data of activation. 

Today there are different payload variants defined for public transport activation-data. The R09.x is one of
 the industry standard used by public transport vehicles (e.g. buses, trams) in Europe (e.g. Germany Austria)
 for controlling traffic lights, barriers, bollards, etc. This DF shall include information like route, course,
 destination, priority, etc.
 
 The R09.x content is defined in VDV recommendation 420 [[7]](#references). It includes following information:
 - Priority Request Information (pre-request, request, ready to start)
 - End of Prioritization procedure
 - Priority request direction
 - Public Transport line number
 - Priority of public transport
 - Route line identifier of the public transport
 - Route number identification
 - Destination of public transport vehicle

 Other countries may use different message sets defined by the local administration.

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Vehicle information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V1.3.1_
```asn1
PtActivation ::= SEQUENCE {
    ptActivationType    PtActivationType,
    ptActivationData    PtActivationData
}
```

### <a name="RadialShape"></a>RadialShape
This DF describes a radial shape. The triangular or cone-shaped volume is
 constructed by sweeping the provided range about the reference point  between a horizontal start 
 and a horizontal end angle in positive angular direction of the WGS84
 coordinate system. A vertical opening angle may be provided in a Cartesian coordinate system with
 the x-axis located in the North-East plane of the WGS84 coordinate system. The sensor height may
 be provided to reflect characteristics of sensors mounted at an altitude (e.g. sensors mounted
 above intersections).

 It shall include the following components:

* _shapeReferencePoint_ of type [**CartesianPosition3d**](#CartesianPosition3d)  OPTIONAL<br>
  the optional reference point used for the definition of the shape, relative to an externally specified reference position. 
   If this component is absent, the externally specified reference position represents the shape's  reference point. 

* _range_ of type [**StandardLength12b**](#StandardLength12b) <br>
  the radial range of the shape from the shape's reference point. 

* _stationaryHorizontalOpeningAngleStart_ of type [**Wgs84AngleValue**](#Wgs84AngleValue) <br>
  the orientation indicating the beginning of the 
   shape's horizontal opening angle in positive angular direction with respect to the 
   WGS84 coordinate system.

* _stationaryHorizontalOpeningAngleEnd_ of type [**Wgs84AngleValue**](#Wgs84AngleValue) <br>
  The orientation indicating the end of the shape's 
   horizontal opening angle in positive angular direction with respect to the WGS84 coordinate system.

* _verticalOpeningAngleStart_ of type [**CartesianAngleValue**](#CartesianAngleValue)  OPTIONAL<br>
  optional orientation indicating the beginning of the shape's
   opening angle in positive angular direction of a Cartesian coordinate system with its x-axis 
   located in the north-east plane of the WGS84 coordinate system.

* _verticalOpeningAngleEnd_ of type [**CartesianAngleValue**](#CartesianAngleValue)  OPTIONAL<br>
  optional orientation indicating the end of the shape's 
   vertical opening angle in positive angular direction of a Cartesian coordinate system with its x-axis 
   located in the north-east plane of the WGS84 coordinate system. 


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** GeoReference information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _created in V2.1.1_
```asn1
RadialShape ::= SEQUENCE { 
    shapeReferencePoint                      CartesianPosition3d OPTIONAL,
    range                                    StandardLength12b,
    stationaryHorizontalOpeningAngleStart    Wgs84AngleValue, 
    stationaryHorizontalOpeningAngleEnd      Wgs84AngleValue, 
    verticalOpeningAngleStart                CartesianAngleValue OPTIONAL,
    verticalOpeningAngleEnd                  CartesianAngleValue OPTIONAL
}
```

### <a name="RadialShapes"></a>RadialShapes
This DF describes a list of radial shapes. 

 It shall include the following components:

* _refPointId_ of type [**Identifier1B**](#Identifier1B) <br>
  the identification of the reference point in case of a sensor mounted to trailer. Defaults to ITS ReferencePoint (0).

* _xCoordinate_ of type [**CartesianCoordinateSmall**](#CartesianCoordinateSmall) <br>
  the x-coordinate of the offset point.

* _yCoordinate_ of type [**CartesianCoordinateSmall**](#CartesianCoordinateSmall) <br>
  the y-coordinate of the offset point.

* _zCoordinate_ of type [**CartesianCoordinateSmall**](#CartesianCoordinateSmall)  OPTIONAL<br>
  the optional z-coordinate of the offset point.

* _radialShapesList_ of type [**RadialShapesList**](#RadialShapesList) <br>
  the list of radial shape details.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Georeference information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _created in V2.1.1_
```asn1
RadialShapes ::= SEQUENCE {
    refPointId          Identifier1B,
    xCoordinate         CartesianCoordinateSmall, 
    yCoordinate         CartesianCoordinateSmall,
    zCoordinate         CartesianCoordinateSmall OPTIONAL,
    radialShapesList    RadialShapesList
}
```

### <a name="RadialShapesList"></a>RadialShapesList
The DF contains a list of [**RadialShapeDetails**](#RadialShapeDetails).

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Georeference information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _created in V2.1.1_
```asn1
RadialShapesList ::= SEQUENCE SIZE(1..16,...) OF RadialShapeDetails
```

### <a name="RadialShapeDetails"></a>RadialShapeDetails
This DF describes a radial shape details. The triangular or cone-shaped volume is
 constructed by sweeping the provided range about the reference point  or about the offset
 point (if provided) between a horizontal start and a horizontal end angle in positive angular direction of the WGS84
 coordinate system. A vertical opening angle may be provided in a Cartesian coordinate system with
 the x-axis located in the North-East plane of the WGS84 coordinate system. The sensor height may
 be provided to reflect characteristics of sensors mounted at an altitude (e.g. sensors mounted
 above intersections).

 It shall include the following components:

* _range_ of type [**StandardLength12b**](#StandardLength12b) <br>
  the radial range of the sensor from the reference point or sensor point offset. 

* _horizontalOpeningAngleStart_ of type [**CartesianAngleValue**](#CartesianAngleValue) <br>
  the orientation indicating the beginning of the 
   shape's horizontal opening angle in positive angular direction.

* _horizontalOpeningAngleEnd_ of type [**CartesianAngleValue**](#CartesianAngleValue) <br>
  The orientation indicating the end of the shape's horizontal 
   opening angle in positive angular direction.

* _verticalOpeningAngleStart_ of type [**CartesianAngleValue**](#CartesianAngleValue)  OPTIONAL<br>
  optional orientation indicating the beginning of the shape's 
   vertical opening angle in positive angular direction of a Cartesian coordinate system with its x-axis 
   located in the north-east plane of the WGS84 coordinate system.

* _verticalOpeningAngleEnd_ of type [**CartesianAngleValue**](#CartesianAngleValue)  OPTIONAL<br>
  optional orientation indicating the end of the shape's 
   vertical opening angle in positive angular direction of a Cartesian coordinate system with its x-axis 
   located in the north-east plane of the WGS84 coordinate system. 


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Georeference information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _created in V2.1.1_
```asn1
RadialShapeDetails ::= SEQUENCE {
    range                          StandardLength12b,
    horizontalOpeningAngleStart    CartesianAngleValue,
    horizontalOpeningAngleEnd      CartesianAngleValue,
    verticalOpeningAngleStart      CartesianAngleValue OPTIONAL,
    verticalOpeningAngleEnd        CartesianAngleValue OPTIONAL
}
```

### <a name="RectangularShape"></a>RectangularShape
This DF represents the shape of a rectangular area or a right rectangular prism that is centred on a reference position defined outside of the context of this DF. 

 It shall include the following components:

* _centerPoint_ of type [**CartesianPosition3d**](#CartesianPosition3d)  OPTIONAL<br>
  represents an optional offset point which the rectangle is centred on with respect to the reference position.

* _semiLength_ of type [**StandardLength12b**](#StandardLength12b) <br>
  represents half the length of the rectangle.

* _semiBreadth_ of type [**StandardLength12b**](#StandardLength12b) <br>
  represents half the breadth of the rectangle.

* _orientation_ of type [**Wgs84AngleValue**](#Wgs84AngleValue)  OPTIONAL<br>
  represents the optional orientation of the lenght of the rectangle in the WGS84 coordinate system.
   The specific WGS84 coordinate system is specified by the corresponding standards applying this DE.

* _height_ of type [**StandardLength12b**](#StandardLength12b)  OPTIONAL<br>
  represents the optional height, present if the shape is a right rectangular prism with height extending in the positive z-axis.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** GeoReference information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _created in V2.1.1_
```asn1
RectangularShape ::= SEQUENCE { 
    centerPoint    CartesianPosition3d OPTIONAL,
    semiLength     StandardLength12b,
    semiBreadth    StandardLength12b,
    orientation    Wgs84AngleValue OPTIONAL,
    height         StandardLength12b OPTIONAL
}
```

### <a name="ReferencePosition"></a>ReferencePosition
A position within a geographic coordinate system together with a confidence ellipse. 

 It shall include the following components:

* _latitude_ of type [**Latitude**](#Latitude) <br>
  the latitude of the geographical point.

* _longitude_ of type [**Longitude**](#Longitude) <br>
  the longitude of the geographical point.

* _positionConfidenceEllipse_ of type [**PosConfidenceEllipse**](#PosConfidenceEllipse) <br>
  the confidence ellipse associated to the geographical position.

* _altitude_ of type [**Altitude**](#Altitude) <br>
  the altitude and an altitude accuracy of the geographical point.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** GeoReference information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _description updated in V2.1.1_

>>>
NOTE:&emsp;this DE is kept for backwards compatibility reasons only. It is recommended to use the [**ReferencePositionWithConfidence**](#ReferencePositionWithConfidence) instead.
>>>
```asn1
ReferencePosition ::= SEQUENCE {
    latitude                     Latitude,
    longitude                    Longitude,
    positionConfidenceEllipse    PosConfidenceEllipse,
    altitude                     Altitude
}
```

### <a name="ReferencePositionWithConfidence"></a>ReferencePositionWithConfidence
A position within a geographic coordinate system together with a confidence ellipse. 

 It shall include the following components:

* _latitude_ of type [**Latitude**](#Latitude) <br>
  the latitude of the geographical point.

* _longitude_ of type [**Longitude**](#Longitude) <br>
  the longitude of the geographical point.

* _positionConfidenceEllipse_ of type [**PositionConfidenceEllipse**](#PositionConfidenceEllipse) <br>
  the confidence ellipse associated to the geographical position.

* _altitude_ of type [**Altitude**](#Altitude) <br>
  the altitude and an altitude accuracy of the geographical point.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** GeoReference information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _created in V2.1.1 based on [**ReferencePosition**](#ReferencePosition) but using [**PositionConfidenceEllipse**](#PositionConfidenceEllipse)._
```asn1
ReferencePositionWithConfidence ::= SEQUENCE {
    latitude                     Latitude,
    longitude                    Longitude,
    positionConfidenceEllipse    PositionConfidenceEllipse,
    altitude                     Altitude
}
```

### <a name="RestrictedTypes"></a>RestrictedTypes
This DF shall contain a list of [**StationType**](#StationType). to which a certain traffic restriction, e.g. the speed limit, applies.

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Infrastructure information Traffic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V1.3.1_
```asn1
RestrictedTypes ::= SEQUENCE (SIZE(1..3, ...)) OF StationType
```

### <a name="RoadSegmentReferenceId"></a>RoadSegmentReferenceId
This DF represents a unique id for a road segment

 It shall include the following components:

* _region_ of type [**Identifier2B**](#Identifier2B)  OPTIONAL<br>
  the optional identifier of the entity that is responsible for the region in which the road segment is placed.
   It is the duty of that entity to guarantee that the [**Id**](#Id) is unique within the region.

* _id_ of type [**Identifier2B**](#Identifier2B) <br>
  the identifier of the road segment.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** GeoReference information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _created in V2.1.1_

>>>
NOTE:&emsp;when the component region is present, the RoadSegmentReferenceId is guaranteed to be globally unique.
>>>
```asn1
RoadSegmentReferenceId ::= SEQUENCE {
    region    Identifier2B OPTIONAL,
    id        Identifier2B
}
```

### <a name="SafeDistanceIndication"></a>SafeDistanceIndication
This DF provides the safe distance indication of a traffic participant with other traffic participant(s).

 It shall include the following components:

* _subjectStation_ of type [**StationId**](ETSI-ITS-CDD.md#StationId)  OPTIONAL<br>
  optionally indicates one "other" traffic participant identified by its ITS-S.

* _safeDistanceIndicator_ of type [**SafeDistanceIndicator**](#SafeDistanceIndicator) <br>
  indicates whether the distance between the ego ITS-S and the traffic participant(s) is safe.
   If subjectStation is present then it indicates whether the distance between the ego ITS-S and the traffic participant indicated in the component subjectStation is safe. 

* _timeToCollision_ of type [**DeltaTimeTenthOfSecond**](#DeltaTimeTenthOfSecond)  OPTIONAL<br>
  optionally indicated the time-to-collision calculated as sqrt(LaDi<sup>2</sup> + LoDi<sup>2</sup> + VDi<sup>2</sup>/relative speed 
   and represented in  the  nearest 100  ms. This component may be present only if subjectStation is present. 


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Traffic information Kinematic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _created in V2.1.1_

>>>
NOTE:&emsp;the abbreviations used are Lateral Distance (LaD),  Longitudinal Distance (LoD) and Vertical Distance (VD) 
 and their respective  thresholds, Minimum  Safe  Lateral  Distance (MSLaD), Minimum  Safe  Longitudinal Distance  (MSLoD),  and  Minimum  Safe Vertical Distance (MSVD).
>>>
```asn1
SafeDistanceIndication ::= SEQUENCE {
    subjectStation           StationId OPTIONAL,
    safeDistanceIndicator    SafeDistanceIndicator,
    timeToCollision          DeltaTimeTenthOfSecond OPTIONAL,
    ...
}
```

### <a name="SequenceOfCartesianPosition3d"></a>SequenceOfCartesianPosition3d
This DF shall contain a list of DF [**CartesianPosition3d**](#CartesianPosition3d).

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** GeoReference information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _created in V2.1.1_
```asn1
SequenceOfCartesianPosition3d ::= SEQUENCE (SIZE(1..16, ...)) OF CartesianPosition3d
```

### <a name="SequenceOfIdentifier1B"></a>SequenceOfIdentifier1B
The DF contains a list of DE [**Identifier1B**](#Identifier1B).

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Basic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _created in V2.1.1_
```asn1
SequenceOfIdentifier1B ::= SEQUENCE SIZE(1..128, ...) OF Identifier1B
```

### <a name="SequenceOfSafeDistanceIndication"></a>SequenceOfSafeDistanceIndication
The DF contains a list of DF [**SafeDistanceIndication**](#SafeDistanceIndication).

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Traffic information Kinematic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _created in V2.1.1_
```asn1
SequenceOfSafeDistanceIndication ::= SEQUENCE(SIZE(1..8,...)) OF SafeDistanceIndication
```

### <a name="SequenceOfTrajectoryInterceptionIndication"></a>SequenceOfTrajectoryInterceptionIndication
The DF shall contain a list of DF [**TrajectoryInterceptionIndication**](ETSI-ITS-CDD.md#TrajectoryInterceptionIndication).

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Traffic information Kinematic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _created in V2.1.1_
```asn1
SequenceOfTrajectoryInterceptionIndication ::=  SEQUENCE (SIZE(1..8,...)) OF TrajectoryInterceptionIndication
```

### <a name="Shape"></a>Shape
This DF provides the definition of a geographical area or volume, based on different options.

 It is a choice of the following components:

* _rectangular_ of type [**RectangularShape**](#RectangularShape) <br>
  definition of an rectangular area or a right rectangular prism (with a rectangular base) also called a cuboid, or informally a rectangular box.

* _circular_ of type [**CircularShape**](#CircularShape) <br>
  definition of an area of circular shape or a right circular cylinder.

* _polygonal_ of type [**PolygonalShape**](#PolygonalShape) <br>
  definition of an area of polygonal shape or a right prism.

* _elliptical_ of type [**EllipticalShape**](#EllipticalShape) <br>
  definition of an area of elliptical shape or a right elliptical cylinder.

* _radial_ of type [**RadialShape**](#RadialShape) <br>
  definition of a radial shape.

* _radialShapes_ of type [**RadialShapes**](#RadialShapes) <br>
* radialList<br>
  definition of list of radial shapes.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** GeoReference information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
Shape::= CHOICE {
   rectangular       RectangularShape,
   circular          CircularShape, 
   polygonal         PolygonalShape,
   elliptical        EllipticalShape,
   radial            RadialShape,
   radialShapes      RadialShapes,
   ...
}
```

### <a name="Speed"></a>Speed
This DF represents the speed and associated confidence value.

 It shall include the following components:

* _speedValue_ of type [**SpeedValue**](#SpeedValue) <br>
  the speed value.

* _speedConfidence_ of type [**SpeedConfidence**](#SpeedConfidence) <br>
  the confidence value of the speed value.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Kinematic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V1.3.1_
```asn1
Speed ::= SEQUENCE {
    speedValue         SpeedValue,
    speedConfidence    SpeedConfidence
}
```

### <a name="StabilityChangeIndication"></a>StabilityChangeIndication
This DF  provides the  indication of  change in stability.

 It shall include the following components:

* _lossProbability_ of type [**StabilityLossProbability**](#StabilityLossProbability) <br>
  the probability of stability loss. 

* _actionDeltaTime_ of type [**DeltaTimeTenthOfSecond**](#DeltaTimeTenthOfSecond) <br>
  the period over which the the probability of stability loss is estimated. 


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Kinematic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V2.1.1_
```asn1
StabilityChangeIndication ::= SEQUENCE {
    lossProbability     StabilityLossProbability,
    actionDeltaTime     DeltaTimeTenthOfSecond,
    ...
}
```

### <a name="SteeringWheelAngle"></a>SteeringWheelAngle
This DF represents the steering wheel angle of the vehicle at certain point in time.

 It shall include the following components:

* _steeringWheelAngleValue_ of type [**SteeringWheelAngleValue**](#SteeringWheelAngleValue) <br>
  steering wheel angle value.

* _steeringWheelAngleConfidence_ of type [**SteeringWheelAngleConfidence**](#SteeringWheelAngleConfidence) <br>
  confidence value of the steering wheel angle value.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Vehicle information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
SteeringWheelAngle ::= SEQUENCE {
    steeringWheelAngleValue         SteeringWheelAngleValue,
    steeringWheelAngleConfidence    SteeringWheelAngleConfidence
}
```

### <a name="Traces"></a>Traces
This DF represents one or more paths using [**PathHistory**](ETSI-ITS-CDD.md#PathHistory).

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** GeoReference information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Description revised in V2.1.1. Is is now based on Path and not on PathHistory_
```asn1
Traces ::= SEQUENCE SIZE(1..7) OF Path
```

### <a name="TrafficIslandPosition"></a>TrafficIslandPosition
Ths DF represents the a position on a traffic island between two lanes. 

 It shall include the following components:

* _oneSide_ of type [**LanePositionAndType**](#LanePositionAndType) <br>
  represents one lane.

* _otherSide_ of type [**LanePositionAndType**](#LanePositionAndType) <br>
  represents the other lane.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Road Topology information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
TrafficIslandPosition ::= SEQUENCE {
    oneSide      LanePositionAndType,
    otherSide    LanePositionAndType,
    ...
}
```

### <a name="TrailerData"></a>TrailerData
This DF provides detailed information about an attached trailer.

 It shall include the following components:

* _refPointId_ of type [**Identifier1B**](#Identifier1B) <br>
  identifier of the reference point of the trailer.

* _hitchPointOffset_ of type [**StandardLength1B**](#StandardLength1B) <br>
  optional position of the hitch point in negative x-direction (according to ISO 8855) from the
   vehicle Reference Point.

* _frontOverhang_ of type [**StandardLength1B**](#StandardLength1B)  OPTIONAL<br>
  optional length of the trailer overhang in the positive x direction (according to ISO 8855) from the
   trailer Reference Point indicated by the refPointID. The value defaults to 0 in case the trailer
   is not overhanging to the front with respect to the trailer reference point.

* _rearOverhang_ of type [**StandardLength1B**](#StandardLength1B)  OPTIONAL<br>
  optional length of the trailer overhang in the negative x direction (according to ISO 8855) from the
   trailer Reference Point indicated by the refPointID.

* _trailerWidth_ of type [**VehicleWidth**](#VehicleWidth)  OPTIONAL<br>
  optional width of the trailer.

* _hitchAngle_ of type [**CartesianAngle**](ETSI-ITS-CDD.md#CartesianAngle) <br>
  optional Value and confidence value of the angle between the trailer orientation (corresponding to the x
   direction of the ISO 8855 [[21]](#references) coordinate system centered on the trailer) and the direction of
   the segment having as end points the reference point of the trailer and the reference point of
   the pulling vehicle, which can be another trailer or a vehicle looking on the horizontal plane
   xy, described in the local Cartesian coordinate system of the trailer. The
   angle is measured with negative values considering the trailer orientation turning clockwise
   starting from the segment direction. The angle value accuracy is provided with the
   confidence level of 95 %.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Vehicle information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
TrailerData ::= SEQUENCE { 
    refPointId          Identifier1B,
    hitchPointOffset    StandardLength1B, 
    frontOverhang       StandardLength1B OPTIONAL, 
    rearOverhang        StandardLength1B OPTIONAL, 
    trailerWidth        VehicleWidth OPTIONAL,
    hitchAngle          CartesianAngle,
    ...
}
```

### <a name="TrajectoryInterceptionIndication"></a>TrajectoryInterceptionIndication
This DF  provides the trajectory  interception  indication  of  ego-VRU  ITS-S  with another ITS-Ss. 

 It shall include the following components:

* _subjectStation_ of type [**StationId**](ETSI-ITS-CDD.md#StationId)  OPTIONAL<br>
  indicates the subject station.

* _trajectoryInterceptionProbability_ of type [**TrajectoryInterceptionProbability**](#TrajectoryInterceptionProbability) <br>
  indicates the propbability of the interception of the subject station trajectory 
   with the trajectory of the station indicated in the component subjectStation.

* _trajectoryInterceptionConfidence_ of type [**TrajectoryInterceptionConfidence**](#TrajectoryInterceptionConfidence)  OPTIONAL<br>
  indicates the confidence of interception of the subject station trajectory 
   with the trajectory of the station indicated in the component subjectStation.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Vehicle information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
TrajectoryInterceptionIndication  ::= SEQUENCE {
   subjectStation                     StationId OPTIONAL, 
   trajectoryInterceptionProbability  TrajectoryInterceptionProbability,
   trajectoryInterceptionConfidence   TrajectoryInterceptionConfidence OPTIONAL,
        ... 
}
```

### <a name="VarLengthNumber"></a>VarLengthNumber
This DF together with its sub DFs Ext1, Ext2 and the DE Ext3 provides the custom (i.e. not ASN.1 standard) definition of an integer with variable lenght, that can be used for example to encode the ITS-AID.

* **content** [0] INTEGER(0..127)<br>
* **extension** [1]	Ext1<br>
    -- one octet length

&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Basic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
VarLengthNumber::=CHOICE{
	content	    [0] INTEGER(0..127), 
	extension	[1]	Ext1
	}
Ext1::=CHOICE{
	content	    [0]	INTEGER(128..16511), 
	extension	[1]	Ext2
}
Ext2::=CHOICE{
	content	    [0]	INTEGER(16512..2113663), 
	extension	[1]	Ext3
	}
Ext3::= INTEGER(2113664..270549119,...) 
```

### <a name="VerticalAcceleration"></a>VerticalAcceleration
This DF indicates the vehicle acceleration at vertical direction and the associated confidence value.

 It shall include the following components:

* _verticalAccelerationValue_ of type [**VerticalAccelerationValue**](#VerticalAccelerationValue) <br>
  vertical acceleration value at a point in time.

* _verticalAccelerationConfidence_ of type [**AccelerationConfidence**](#AccelerationConfidence) <br>
  confidence value of the vertical acceleration value with a predefined confidence level.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Vehicle information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Description revised in V2.1.1_

>>>
NOTE:&emsp;this DF is kept for backwards compatibility reasons only. It is recommended to use [**AccelerationComponent**](#AccelerationComponent) instead.
>>>
```asn1
VerticalAcceleration ::= SEQUENCE {
    verticalAccelerationValue         VerticalAccelerationValue,
    verticalAccelerationConfidence    AccelerationConfidence
}
```

### <a name="VehicleIdentification"></a>VehicleIdentification
This DF provides information related to the identification of a vehicle.

 It shall include the following components:

* _wMInumber_ of type [**WMInumber**](#WMInumber)  OPTIONAL<br>
  World Manufacturer Identifier (WMI) code.

* _vDS_ of type [**VDS**](#VDS)  OPTIONAL<br>
  Vehicle Descriptor Section (VDS). 


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Vehicle information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V1.3.1_
```asn1
VehicleIdentification ::= SEQUENCE {
    wMInumber    WMInumber OPTIONAL,
    vDS          VDS OPTIONAL,
    ...
}
```

### <a name="VehicleLength"></a>VehicleLength
This DF represents the length of vehicle and accuracy indication information.

 It shall include the following components:

* _vehicleLengthValue_ of type [**VehicleLengthValue**](#VehicleLengthValue) <br>
  length of vehicle. 

* _vehicleLengthConfidenceIndication_ of type [**VehicleLengthConfidenceIndication**](#VehicleLengthConfidenceIndication) <br>
  indication of the length value confidence.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Vehicle information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V1.3.1_

>>>
NOTE:&emsp;this DF is kept for backwards compatibility reasons only. It is recommended to use [**VehicleLengthV2**](#VehicleLengthV2) instead.
>>>
```asn1
VehicleLength ::= SEQUENCE {
    vehicleLengthValue                   VehicleLengthValue,
    vehicleLengthConfidenceIndication    VehicleLengthConfidenceIndication
}
```

### <a name="VehicleLengthV2"></a>VehicleLengthV2
This DF represents the length of vehicle and accuracy indication information.

 It shall include the following components:

* _vehicleLengthValue_ of type [**VehicleLengthValue**](#VehicleLengthValue) <br>
  length of vehicle. 

* _trailerPresenceInformation_ of type [**TrailerPresenceInformation**](#TrailerPresenceInformation) <br>
  information about the trailer presence.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Vehicle information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _created in V2.1.1 based on [**VehicleLength**](#VehicleLength) but using [**TrailerPresenceInformation**](#TrailerPresenceInformation)._
```asn1
VehicleLengthV2 ::= SEQUENCE {
    vehicleLengthValue            VehicleLengthValue,
    trailerPresenceInformation    TrailerPresenceInformation
}
```

### <a name="Velocity3dWithConfidence"></a>Velocity3dWithConfidence
This DF represents a velocity vector with associated confidence value.

 The following options are available:

* _polarVelocity_ of type [**VelocityPolarWithZ**](#VelocityPolarWithZ) <br>
  the representation of the velocity vector in a polar or cylindrical coordinate system. 

* _cartesianVelocity_ of type [**VelocityCartesian**](#VelocityCartesian) <br>
  the representation of the velocity vector in a cartesian coordinate system.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Kinematic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
Velocity3dWithConfidence::= CHOICE{
    polarVelocity          VelocityPolarWithZ, 
    cartesianVelocity      VelocityCartesian
}
```

### <a name="VelocityCartesian"></a>VelocityCartesian
This DF represents a velocity vector in a cartesian coordinate system.
 It shall include the following components:

* _xVelocity_ of type [**VelocityComponent**](#VelocityComponent) <br>
  the x component of the velocity vector with the associated confidence value.

* _yVelocity_ of type [**VelocityComponent**](#VelocityComponent) <br>
  the y component of the velocity vector with the associated confidence value.

* _zVelocity_ of type [**VelocityComponent**](#VelocityComponent)  OPTIONAL<br>
  the optional z component of the velocity vector with the associated confidence value.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Kinematic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
VelocityCartesian::= SEQUENCE {
    xVelocity   VelocityComponent,
    yVelocity   VelocityComponent,
    zVelocity   VelocityComponent OPTIONAL
}
```

### <a name="VelocityComponent"></a>VelocityComponent
This DF represents a component of the velocity vector and the associated confidence value.

 It shall include the following components:

* _value_ of type [**VelocityComponentValue**](#VelocityComponentValue) <br>
  the value of the component.

* _confidence_ of type [**SpeedConfidence**](#SpeedConfidence) <br>
  the confidence value of the value.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Kinematic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V2.1.1_
```asn1
VelocityComponent ::= SEQUENCE {
    value         VelocityComponentValue,
    confidence    SpeedConfidence
}
```

### <a name="VelocityPolarWithZ"></a>VelocityPolarWithZ
This DF represents a velocity vector in a polar or cylindrical coordinate system.

 It shall include the following components:

* _velocityMagnitude_ of type [**Speed**](ETSI-ITS-CDD.md#Speed) <br>
  magnitude of the velocity vector on the reference plane, with the associated confidence value.

* _velocityDirection_ of type [**CartesianAngle**](ETSI-ITS-CDD.md#CartesianAngle) <br>
  polar angle of the velocity vector on the reference plane, with the associated confidence value.

* _zVelocity_ of type [**VelocityComponent**](#VelocityComponent)  OPTIONAL<br>
  the optional z component of the velocity vector along the reference axis of the cylindrical coordinate system, with the associated confidence value.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Kinematic information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
VelocityPolarWithZ::= SEQUENCE {
    velocityMagnitude    Speed, 
    velocityDirection    CartesianAngle,
    zVelocity            VelocityComponent OPTIONAL
}
```

### <a name="VruClusterInformation"></a>VruClusterInformation
This DF provides information about a VRU cluster.

 It shall include the following components:

* _clusterId_ of type [**Identifier1B**](#Identifier1B)  OPTIONAL<br>
  optional identifier of a VRU cluster .

* _clusterBoundingBoxShape_ of type [**Shape**](#Shape)  (WITH COMPONENTS{..., elliptical ABSENT, radial ABSENT, radialShapes ABSENT}) OPTIONAL<br>
  optionally indicates the shape of the cluster bounding box.

* _clusterCardinalitySize_ of type [**CardinalNumber1B**](#CardinalNumber1B) <br>
  indicates an estimation of the number of VRUs in the group, i.e. the known members in the cluster + 1 (for the cluster leader) .

* _clusterProfiles_ of type [**VruClusterProfiles**](#VruClusterProfiles)  OPTIONAL<br>
  optionally identifies all the VRU profile types that are known to be within the cluster.
   if this component is absent it means that the information is unavailable. 


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** VRU information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
VruClusterInformation ::= SEQUENCE { 
   clusterId                  Identifier1B OPTIONAL,
   clusterBoundingBoxShape    Shape (WITH COMPONENTS{..., elliptical ABSENT, radial ABSENT, radialShapes ABSENT}) OPTIONAL,
   clusterCardinalitySize     CardinalNumber1B,
   clusterProfiles            VruClusterProfiles OPTIONAL,
   ...
}
```

### <a name="VruExteriorLights"></a>VruExteriorLights
This DF represents the status of the exterior light switches of a VRU.
 This DF is an extension of the vehicular DE [**ExteriorLights**](#ExteriorLights).

 It shall include the following components:

* _vehicular_ of type [**ExteriorLights**](#ExteriorLights) <br>
  represents the status of the exterior light switches of a road vehicle.

* _vruSpecific_ of type [**VruSpecificExteriorLights**](#VruSpecificExteriorLights) <br>
  represents the status of the exterior light switches of a VRU.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** VRU information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _created in V2.1.1_
```asn1
VruExteriorLights ::= SEQUENCE {
   vehicular      ExteriorLights, 
   vruSpecific    VruSpecificExteriorLights,
   ...
}
```

### <a name="VruProfileAndSubprofile"></a>VruProfileAndSubprofile
This DF indicates the profile of a VRU including sub-profile information
 It identifies four options corresponding to the four types of VRU profiles specified in ETSI TS 103 300-2 [[18]](#references):

* _pedestrian_ of type [**VruSubProfilePedestrian**](#VruSubProfilePedestrian) <br>
  VRU Profile 1 - Pedestrian.

* _bicyclistAndLightVruVehicle_ of type [**VruSubProfileBicyclist**](#VruSubProfileBicyclist) <br>
  VRU Profile  2 - Bicyclist.

* _motorcyclist_ of type [**VruSubProfileMotorcyclist**](ETSI-ITS-CDD.md#VruSubProfileMotorcyclist) <br>
  VRU Profile 3  - Motorcyclist.

* _animal_ of type [**VruSubProfileAnimal**](#VruSubProfileAnimal) <br>
  VRU Profile  4 -  Animal.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** VRU information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
VruProfileAndSubprofile ::= CHOICE {
   pedestrian                     VruSubProfilePedestrian,
   bicyclistAndLightVruVehicle    VruSubProfileBicyclist,
   motorcyclist                   VruSubProfileMotorcyclist,
   animal                         VruSubProfileAnimal,
   ...
}
```

### <a name="Wgs84Angle"></a>Wgs84Angle
This DF represents an angular component along with a confidence value in the WGS84 coordinate system.
 The specific WGS84 coordinate system is specified by the corresponding standards applying this DE.

 It shall include the following components:

* _value_ of type [**Wgs84AngleValue**](#Wgs84AngleValue) <br>
  the angle value, which can be estimated as the mean of the current distribution.

* _confidence_ of type [**Wgs84AngleConfidence**](#Wgs84AngleConfidence) <br>
  the confidence value associated to the angle value.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** GeoReference information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _Created in V2.1.1_
```asn1
Wgs84Angle ::= SEQUENCE {
    value         Wgs84AngleValue,
    confidence    Wgs84AngleConfidence
}
```

### <a name="YawRate"></a>YawRate
This DF represents a yaw rate of vehicle at a point in time.

 It shall include the following components:

* _yawRateValue_ of type [**YawRateValue**](#YawRateValue) <br>
  yaw rate value at a point in time.

* _yawRateConfidence_ of type [**YawRateConfidence**](#YawRateConfidence) <br>
  confidence value associated to the yaw rate value.


&nbsp;&nbsp;&nbsp;&nbsp;**Categories:** Vehicle Information 

&nbsp;&nbsp;&nbsp;&nbsp;**Revision:** _V1.3.1_
```asn1
YawRate::= SEQUENCE {
    yawRateValue         YawRateValue,
    yawRateConfidence    YawRateConfidence
}
```



## References:
 1.   ETSI TS 103 900: "Intelligent Transport Systems (ITS); Vehicular Communications; Basic Set of Applications; Part 2: Specification of Cooperative Awareness Basic Service; Release 2".
 2.   ETSI TS 103 831: "Intelligent Transport Systems (ITS); Vehicular Communications; Basic Set of Applications; Part 3: Specifications of Decentralized Environmental Notification Basic Service"; Release 2.
 3.   [European Agreement (Applicable as from 1 January 2011): "Concerning the International Carriage of Dangerous Goods by Road"](http://www.unece.org/trans/danger/publi/adr/adr2011/11ContentsE.html).
 4.   [United Nations: "Recommendations on the Transport of Dangerous Goods - Model Regulations", Twelfth revised edition](http://www.unece.org/trans/danger/publi/unrec/12_e.html).
 5.   ETSI TS 101 539-1: "Intelligent Transport Systems (ITS); V2X Applications; Part 1: Road Hazard Signalling (RHS) application requirements specification".
 6.   ISO 3779 (2011-07): "Road vehicles - Vehicle identification number (VIN) Content and structure".
 7.   VDV recommendation 420 (1992): "Technical Requirements for Automatic Vehicle Location / Control Systems - Radio Data Transmission (BON Version) with Supplement 1 and Supplement 2".
 8.   ISO 1176:1990: "Road vehicles - Masses - Vocabulary and codes".
 9.   ETSI TS 101 556-1: "Intelligent Transport Systems (ITS); Infrastructure to Vehicle Communication; Electric Vehicle Charging Spot Notification Specification".
 10.  ETSI TS 101 556-2: "Intelligent Transport Systems (ITS); Infrastructure to Vehicle Communication; Part 2: Communication system specification to support application requirements for Tyre Information System (TIS) and Tyre Pressure Gauge (TPG) interoperability".
 11.  ETSI TS 101 556-3: "Intelligent Transport Systems (ITS); Infrastructure to Vehicle Communications; Part 3: Communications system for the planning and reservation of EV energy supply using wireless networks".
 12.  ETSI TS 103 300-3: "Intelligent Transport Systems (ITS);  Vulnerable Road Users (VRU) awareness;  Part 3: Specification of VRU awareness basic service; Release 2"
 13.  ETSI TS 103 724: "Intelligent Transport Systems (ITS); Facilities layer  function; Interference Management Zone Message (IMZM); Release 2"
 14.	ETSI TS 102 792: "Intelligent Transport Systems (ITS); Mitigation techniques to avoid interference between European CEN Dedicated Short Range Communication (CEN DSRC) equipment and Intelligent Transport Systems (ITS) operating in the 5 GHz frequency range".
 15.	ETSI TS 103 301: "Intelligent Transport Systems (ITS); Vehicular Communications; Basic Set of Applications; Facilities layer protocols and communication requirements for infrastructure services; Release 2".
 16.	UNECE/TRANS/WP.29/78/Rev.4: "Consolidated Resolution on the Construction of Vehicles (R.E.3)".
 17.	ETSI EN 302 890-1: "Intelligent Transport Systems (ITS); Facilities layer function; Part 1: Services Announcement (SA) specification".
 18.	ETSI TS 103 300-2 "Intelligent Transport System (ITS); Vulnerable Road Users (VRU) awareness; Part 2: Functional  Architecture and Requirements definition; Release 2"
 19.	ETSI TS 103 175  "Intelligent Transport Systems (ITS); Cross  Layer DCC Management  Entity for operation in  the ITS G5A  and ITS G5B medium"
 20.	ETSI EN 302 571  "Intelligent Transport Systems (ITS); Radiocommunications equipment operating in the 5 855 MHz to 5 925 MHz frequency  band; Harmonised Standard  covering  the essential  requirements of article 3.2 of  Directive 2014/53/EU"
 21.	ISO 8855: "Road vehicles - Vehicle dynamics and road-holding ability - Vocabulary".
 22.  ISO 3833, "Road vehicles - Types - Terms and definitions".


