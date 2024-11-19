# <a name="CPM-PerceptionRegionContainer"></a>ASN.1 module CPM-PerceptionRegionContainer
OID: _{itu-t (0) identified-organization (4) etsi (0) itsDomain (5) wg1 (1) ts (103324) perceptionRegionContainer (5) major-version-1 (1) minor-version-1(1)}_

## Imports:
* **[ETSI-ITS-CDD](ETSI-ITS-CDD.md)** *{itu-t (0) identified-organization (4) etsi (0) itsDomain (5) wg1 (1) ts (102894) cdd (2) major-version-3 (3) minor-version-1 (1)}*<br/>
## Data Elements:
### <a name="PerceptionRegionContainer"></a>PerceptionRegionContainer
This DF  represents the Perception Region Container as a list of perception region information objects.
```asn1
PerceptionRegionContainer ::= SEQUENCE SIZE(1..256, ...) OF PerceptionRegion
```

### <a name="PerceptionRegion"></a>PerceptionRegion
This DF represents the actual perception capabilities available to the transmitting ITS-S, offering additional (often dynamic) details to the information provided in the sensor information container.

 It shall include the following components:

* _measurementDeltaTime_ of type [**DeltaTimeMilliSecondSigned**](ETSI-ITS-CDD.md#DeltaTimeMilliSecondSigned) <br>
  difference between the time of estimation of the perception region and the reference time. Positive values indicates that the provided information refers to a point in time after the reference time.

* _perceptionRegionConfidence_ of type [**ConfidenceLevel**](ETSI-ITS-CDD.md#ConfidenceLevel) <br>
  the perception confidence.

* _perceptionRegionShape_ of type [**Shape**](ETSI-ITS-CDD.md#Shape) <br>
  specification of the shape of the perception region.

* _shadowingApplies_ of type **BOOLEAN** <br>
  indicates if the standard shadowing approach applies to the described perception region.

* _sensorIdList_ of type [**SequenceOfIdentifier1B**](ETSI-ITS-CDD.md#SequenceOfIdentifier1B)  OPTIONAL<br>
  the optional list of identifiers of the sensors which are involved in perceiving the region.

* _numberOfPerceivedObjects_ of type [**CardinalNumber1B**](ETSI-ITS-CDD.md#CardinalNumber1B)  OPTIONAL<br>
  the optional number of perceived objects contained in the perception region specified in the component perceptionRegionShape. 

* _perceivedObjectIds_ of type [**PerceivedObjectIds**](#PerceivedObjectIds)  OPTIONAL<br>
  the optional list of identifiers of the objects specified in the Perceived Object Container that are contained in the perception region specified in the component perceptionRegionShape.

```asn1
PerceptionRegion ::= SEQUENCE {
    measurementDeltaTime         DeltaTimeMilliSecondSigned,     
    perceptionRegionConfidence   ConfidenceLevel,
    perceptionRegionShape        Shape, 
    shadowingApplies             BOOLEAN,
    sensorIdList                 SequenceOfIdentifier1B OPTIONAL,
    numberOfPerceivedObjects     CardinalNumber1B OPTIONAL,
    perceivedObjectIds           PerceivedObjectIds OPTIONAL,
	...
}
```

### <a name="PerceivedObjectIds"></a>PerceivedObjectIds
This DF  represents a list of identifiers of perceived objects.
```asn1
PerceivedObjectIds::= SEQUENCE SIZE(0..255, ...) OF Identifier2B
```



