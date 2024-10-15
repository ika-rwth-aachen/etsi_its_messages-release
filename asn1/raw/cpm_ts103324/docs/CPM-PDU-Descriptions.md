# <a name="CPM-PDU-Descriptions"></a>ASN.1 module CPM-PDU-Descriptions
OID: _{ itu-t (0) identified-organization (4) etsi (0) itsDomain (5) wg1 (1) ts (103324) cpm (1) major-version-1 (1) minor-version-1(1)}_

## Imports:
* **[ETSI-ITS-CDD](ETSI-ITS-CDD.md)** *{itu-t (0) identified-organization (4) etsi (0) itsDomain (5) wg1 (1) ts (102894) cdd (2) major-version-3 (3) minor-version-1 (1)} WITH SUCCESSORS*<br/>
* **[CPM-OriginatingStationContainers](CPM-OriginatingStationContainers.md)** *{itu-t (0) identified-organization (4) etsi (0) itsDomain (5) wg1 (1) ts (103324) originatingStationContainers (2) major-version-1 (1) minor-version-1(1)} WITH SUCCESSORS*<br/>
* **[CPM-SensorInformationContainer](CPM-SensorInformationContainer.md)** *{itu-t (0) identified-organization (4) etsi (0) itsDomain (5) wg1 (1) ts (103324) sensorInformationContainer (3) major-version-1 (1) minor-version-1(1)} WITH SUCCESSORS*<br/>
* **[CPM-PerceptionRegionContainer](CPM-PerceptionRegionContainer.md)** *{itu-t (0) identified-organization (4) etsi (0) itsDomain (5) wg1 (1) ts (103324) perceptionRegionContainer (5) major-version-1 (1) minor-version-1(1)} WITH SUCCESSORS*<br/>
* **[CPM-PerceivedObjectContainer](CPM-PerceivedObjectContainer.md)** *{itu-t (0) identified-organization (4) etsi (0) itsDomain (5) wg1 (1) ts (103324) perceivedObjectContainer (4) major-version-1 (1) minor-version-1(1)} WITH SUCCESSORS*<br/>
## Data Elements:
### <a name="CollectivePerceptionMessage"></a>CollectivePerceptionMessage
This DF  represents the Collective Perception Message (CPM) and is the top level Protocol Data Unit. 

 It shall include the following components:

* _header_ of type [**ItsPduHeader**](ETSI-ITS-CDD.md#ItsPduHeader)  (WITH COMPONENTS {... , protocolVersion (2), messageId(cpm)})<br>
  the common message header for the facilities layer message. 

* _payload_ of type [**CpmPayload**](#CpmPayload) <br>
  the payload of the message. 

```asn1
CollectivePerceptionMessage ::= SEQUENCE {
    header     ItsPduHeader (WITH COMPONENTS {... , protocolVersion (2), messageId(cpm)}),
    payload    CpmPayload
}
```

### <a name="CpmPayload"></a>CpmPayload
This DF  represents the payload of the CPM. 

 It shall include the following components:

* _managementContainer_ of type [**ManagementContainer**](#ManagementContainer) <br>
  the management container. 

* _cpmContainers_ of type [**ConstraintWrappedCpmContainers**](#ConstraintWrappedCpmContainers) <br>
  the list of CPM containers, including its container type identifier and including either one or none of originatingVehicleContainer and/or originatingRsuContainer. 

```asn1
CpmPayload ::= SEQUENCE {
    managementContainer   ManagementContainer,
    cpmContainers         ConstraintWrappedCpmContainers,
    ...
}
```

### <a name="ManagementContainer"></a>ManagementContainer
This DF  represents the management container of the CPM. 
 The management container provides basic information about the originating ITS-S, which are not specific to a specific type of station.

 It shall include the following components:

* _referenceTime_ of type [**TimestampIts**](ETSI-ITS-CDD.md#TimestampIts) <br>
  the reference time for all time related information in the CPM.

* _referencePosition_ of type [**ReferencePosition**](ETSI-ITS-CDD.md#ReferencePosition) <br>
  the reference position for all position related information in the CPM.

* _segmentationInfo_ of type [**MessageSegmentationInfo**](ETSI-ITS-CDD.md#MessageSegmentationInfo)  OPTIONAL<br>
  information regarding the message segmentation on facility layer.

* _messageRateRange_ of type [**MessageRateRange**](#MessageRateRange)  OPTIONAL<br>
  the planned or expected range of the CPM generation rate.

```asn1
ManagementContainer ::= SEQUENCE {
    referenceTime      TimestampIts,
    referencePosition  ReferencePosition,
    segmentationInfo   MessageSegmentationInfo OPTIONAL,
    messageRateRange   MessageRateRange OPTIONAL,
    ...
}
```

### <a name="CPM-CONTAINER-ID-AND-TYPE"></a>CPM-CONTAINER-ID-AND-TYPE
This information object class is an abstract template to instantiate containers.

 It shall include the following components:

* _id_ of type [**CpmContainerId**](#CpmContainerId)  UNIQUE<br>
  the identifier of the container type.

* Type<br>
  the container content.

```asn1
CPM-CONTAINER-ID-AND-TYPE ::= CLASS {
    &id     CpmContainerId UNIQUE,
    &Type
} WITH SYNTAX {&Type IDENTIFIED BY &id}
```

### <a name="CpmContainerId"></a>CpmContainerId
This DE represents the identifier of the container type.
```asn1
CpmContainerId ::= INTEGER (1..16)
```

These value assignements represent specific values of the container type identifier.

```asn1
originatingVehicleContainer CpmContainerId ::= 1
originatingRsuContainer CpmContainerId ::= 2
sensorInformationContainer CpmContainerId ::= 3
perceptionRegionContainer CpmContainerId ::= 4
perceivedObjectContainer CpmContainerId ::= 5
```

### <a name="CpmContainers"></a>CpmContainers
This information object set represents the association between the container type and the container content.
```asn1
CpmContainers CPM-CONTAINER-ID-AND-TYPE ::= {
    {OriginatingVehicleContainer IDENTIFIED BY originatingVehicleContainer} |
    {OriginatingRsuContainer IDENTIFIED BY originatingRsuContainer} |
    {SensorInformationContainer IDENTIFIED BY sensorInformationContainer} |
    {PerceptionRegionContainer IDENTIFIED BY perceptionRegionContainer} |
    {PerceivedObjectContainer IDENTIFIED BY perceivedObjectContainer},
    ...
}
```

### <a name="WrappedCpmContainer"></a>WrappedCpmContainer
This DF represents a CPM container preceded by its type identifier and a lenght indicator.

 It shall include the following components:

* _containerId_ of type [**CPM-CONTAINER-ID-AND-TYPE**](#CPM-CONTAINER-ID-AND-TYPE) .&id( {CpmContainers} )<br>
  the identifier of the container type.

* _containerData_ of type [**CPM-CONTAINER-ID-AND-TYPE**](#CPM-CONTAINER-ID-AND-TYPE) .&Type( {CpmContainers}{@containerId} )<br>
  the container content consistent with the container type.

```asn1
WrappedCpmContainer ::= SEQUENCE {
   containerId     CPM-CONTAINER-ID-AND-TYPE.&id( {CpmContainers} ),
   containerData   CPM-CONTAINER-ID-AND-TYPE.&Type( {CpmContainers}{@containerId} )
}
```

### <a name="WrappedCpmContainers"></a>WrappedCpmContainers
This DF represents a list of CPM containers, each with their type identifier.
```asn1
WrappedCpmContainers::= SEQUENCE SIZE(1..8,...) OF WrappedCpmContainer
```

### <a name="ConstraintWrappedCpmContainers"></a>ConstraintWrappedCpmContainers
This DF represents a list of CPM containers, each with their type identifier with an additional constraint.
```asn1
ConstraintWrappedCpmContainers ::= WrappedCpmContainers
    ((WITH COMPONENT (WITH COMPONENTS {..., containerId (ALL EXCEPT 1)})) |
    (WITH COMPONENT (WITH COMPONENTS {..., containerId (ALL EXCEPT 2)})))
```

### <a name="MessageRateRange"></a>MessageRateRange
This DF  represents the planned or expected range of the message generation rate.

 It shall include the following components:

* _messageRateMin_ of type [**MessageRateHz**](ETSI-ITS-CDD.md#MessageRateHz) <br>
  the minimum planned or expected message rate.

* _messageRateMax_ of type [**MessageRateHz**](ETSI-ITS-CDD.md#MessageRateHz) <br>
  the maximum planned or expected message rate.

```asn1
MessageRateRange::= SEQUENCE{
   messageRateMin   MessageRateHz,
   messageRateMax   MessageRateHz
}
```



