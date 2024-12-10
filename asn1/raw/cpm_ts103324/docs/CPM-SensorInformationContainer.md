# <a name="CPM-SensorInformationContainer"></a>ASN.1 module CPM-SensorInformationContainer
OID: _{itu-t (0) identified-organization (4) etsi (0) itsDomain (5) wg1 (1) ts (103324) sensorInformationContainer (3) major-version-1 (1) minor-version-1(1)}_

## Imports:
* **[ETSI-ITS-CDD](ETSI-ITS-CDD.md)** *{itu-t (0) identified-organization (4) etsi (0) itsDomain (5) wg1 (1) ts (102894) cdd (2) major-version-3 (3) minor-version-1 (1) }*<br/>
## Data Elements:
### <a name="SensorInformationContainer"></a>SensorInformationContainer
This DF  represents the Sensor Information Container as a list of information objects about the sensors or data fusion systems from which the station provides information about detected objects.
```asn1
SensorInformationContainer ::= SEQUENCE SIZE(1..128, ...) OF SensorInformation
```

### <a name="SensorInformation"></a>SensorInformation
This DF  represents the characteristics of a single sensor or data fusion system.

 It shall include the following components:

* _sensorId_ of type [**Identifier1B**](ETSI-ITS-CDD.md#Identifier1B) <br>
  identifier of the sensor or data fusion system used to relate the perceived object in the Perceived Object Container to the sensor that detected it.
   this identifier shall uniquely identify the sensor inside the CPM, but may be changed from one CPM to the next.

* _sensorType_ of type [**SensorType**](ETSI-ITS-CDD.md#SensorType) <br>
  the type of the sensor.

* _perceptionRegionShape_ of type [**Shape**](ETSI-ITS-CDD.md#Shape)  OPTIONAL<br>
  the perception region of the sensor.

* _perceptionRegionConfidence_ of type [**ConfidenceLevel**](ETSI-ITS-CDD.md#ConfidenceLevel)  OPTIONAL<br>
  the homogeneous perception region confidence that can be assumed for the entire perception region shape of this sensor. 

* _shadowingApplies_ of type **BOOLEAN** <br>
  indicates if the standard shadowing approach applies to the described perception region.

```asn1
SensorInformation ::= SEQUENCE {
    sensorId          		    Identifier1B,
    sensorType        		    SensorType,
    perceptionRegionShape		Shape OPTIONAL,
    perceptionRegionConfidence  ConfidenceLevel OPTIONAL,
    shadowingApplies            BOOLEAN,
   ...
}
```



