# <a name="VRU-Motorcyclist-Special-Container"></a>ASN.1 module VRU-Motorcyclist-Special-Container
OID: _{itu-t(0) identified-organization(4) etsi(0) itsDomain(5) wg1(1) 103300 motorcyclist-special-container(2) version2(2)}_

## Imports:
* **[ETSI-ITS-CDD](ETSI-ITS-CDD.md)** *{itu-t(0) identified-organization(4) etsi(0) itsDomain(5) wg1(1) 102894 cdd(2) major-version-3(3) minor-version-1(1)}*<br/>
## Data Elements:
### <a name="MotorcylistSpecialContainer"></a>MotorcylistSpecialContainer

* _motorcyclist_ of type [**VruSubProfileMotorcyclist**](ETSI-ITS-CDD.md#VruSubProfileMotorcyclist) <br>
* _sizeClass_ of type [**VruSizeClass**](ETSI-ITS-CDD.md#VruSizeClass) <br>
* _rollAngle_ of type [**CartesianAngle**](ETSI-ITS-CDD.md#CartesianAngle)  OPTIONAL<br>
* _orientation_ of type [**Wgs84Angle**](ETSI-ITS-CDD.md#Wgs84Angle)  OPTIONAL<br>
* _safeDistance_ of type [**SequenceOfSafeDistanceIndication**](ETSI-ITS-CDD.md#SequenceOfSafeDistanceIndication)  OPTIONAL<br>
* _pathPrediction_ of type [**PathPredicted**](ETSI-ITS-CDD.md#PathPredicted)  OPTIONAL<br>
* _stabilityChangeIndication_ of type [**StabilityChangeIndication**](ETSI-ITS-CDD.md#StabilityChangeIndication)  OPTIONAL<br>
```asn1
MotorcylistSpecialContainer ::= SEQUENCE {
   motorcyclist                VruSubProfileMotorcyclist,
   sizeClass                   VruSizeClass,
   rollAngle                   CartesianAngle OPTIONAL, 
   orientation                 Wgs84Angle OPTIONAL,
   safeDistance                SequenceOfSafeDistanceIndication OPTIONAL,
   pathPrediction              PathPredicted OPTIONAL,
   stabilityChangeIndication   StabilityChangeIndication OPTIONAL,
   ...
}
```



