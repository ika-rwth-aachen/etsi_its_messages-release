# <a name="CPM-PerceivedObjectContainer"></a>ASN.1 module CPM-PerceivedObjectContainer
OID: _{itu-t (0) identified-organization (4) etsi (0) itsDomain (5) wg1 (1) ts (103324) perceivedObjectContainer (4) major-version-1 (1) minor-version-1(1)}_

## Imports:
* **[ETSI-ITS-CDD](ETSI-ITS-CDD.md)** *{itu-t (0) identified-organization (4) etsi (0) itsDomain (5) wg1 (1) ts (102894) cdd (2) major-version-3 (3) minor-version-1 (1)}*<br/>
## Data Elements:
### <a name="PerceivedObjectContainer"></a>PerceivedObjectContainer
This DF  represents the Perceived Object Container 

 It shall include the following components:

* _numberOfPerceivedObjects_ of type [**CardinalNumber1B**](ETSI-ITS-CDD.md#CardinalNumber1B) <br>
  the total number of perceived objects at the time of generating the message. 

* _perceivedObjects_ of type [**PerceivedObjects**](#PerceivedObjects) <br>
  the list of perceived objects.

```asn1
PerceivedObjectContainer ::= SEQUENCE {
    numberOfPerceivedObjects    CardinalNumber1B,
    perceivedObjects            PerceivedObjects,
    ...
}
```

### <a name="PerceivedObjects"></a>Perceived Objects
 This DF provides a list of perceived objects represented in the coordinate system in which the y-axis corresponds to the North direction, the x-axis to the East direction, and the z- axis to the vertical direction.

```asn1
PerceivedObjects::= SEQUENCE SIZE(0..255, ...) OF PerceivedObject (WITH COMPONENTS {... ,objectId PRESENT})
```



