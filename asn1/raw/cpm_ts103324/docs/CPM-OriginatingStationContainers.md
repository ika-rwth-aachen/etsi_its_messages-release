# <a name="CPM-OriginatingStationContainers"></a>ASN.1 module CPM-OriginatingStationContainers
OID: _{itu-t (0) identified-organization (4) etsi (0) itsDomain (5) wg1 (1) ts (103324) originatingStationContainers (2) major-version-1 (1) minor-version-1(1)}_

## Imports:
* **[ETSI-ITS-CDD](ETSI-ITS-CDD.md)** *{itu-t (0) identified-organization (4) etsi (0) itsDomain (5) wg1 (1) ts (102894) cdd (2) major-version-3 (3) minor-version-1 (1)}*<br/>
## Data Elements:
### <a name="OriginatingVehicleContainer"></a>OriginatingVehicleContainer
This DF  represents the Originating Vehicle Container

 It shall include the following components:

* _orientationAngle_ of type [**Wgs84Angle**](ETSI-ITS-CDD.md#Wgs84Angle) <br>
  the angle and angle accuracy of the absolute orientation of the disseminating vehicle in the WGS84 coordinate system with respect to true North.

* _pitchAngle_ of type [**CartesianAngle**](ETSI-ITS-CDD.md#CartesianAngle)  OPTIONAL<br>
  the optional angle and angle accuracy between the ground plane and the current orientation of the vehicle's x-axis with respect to the ground plane about the y-axis according to the ISO 8855.

* _rollAngle_ of type [**CartesianAngle**](ETSI-ITS-CDD.md#CartesianAngle)  OPTIONAL<br>
  the optional angle and angle accuracy between the ground plane and the current orientation of a vehicle's y-axis with respect to the ground plane about the x-axis according to the ISO 8855

* _trailerDataSet_ of type [**TrailerDataSet**](#TrailerDataSet)  OPTIONAL<br>
* trailerData<br>
  information about the trailer dimensions and orientation in case a trailer is present.

```asn1
OriginatingVehicleContainer ::= SEQUENCE {
    orientationAngle   Wgs84Angle,
    pitchAngle         CartesianAngle OPTIONAL,
    rollAngle          CartesianAngle OPTIONAL,
    trailerDataSet     TrailerDataSet OPTIONAL,
    ...
}
```

### <a name="OriginatingRsuContainer"></a>OriginatingRsuContainer
This DF  represents the Originating RSU Container.

 It shall include the following components:

* _mapReference_ of type [**MapReference**](ETSI-ITS-CDD.md#MapReference)  OPTIONAL<br>
  identifies the MAPEM containing the topology information reference in the Perceived Object Container

```asn1
OriginatingRsuContainer ::= SEQUENCE{
    mapReference    MapReference OPTIONAL,
    ...
}
```

### <a name="TrailerDataSet"></a>TrailerDataSet
This DF  represents a list of trailer data.
```asn1
TrailerDataSet::= SEQUENCE SIZE(1..8,...) OF TrailerData (WITH COMPONENTS {... ,frontOverhang ABSENT, rearOverhang ABSENT, trailerWidth ABSENT})
```



