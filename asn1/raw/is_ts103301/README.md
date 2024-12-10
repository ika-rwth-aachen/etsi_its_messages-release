# Abstract syntax notation module for ETSI TS 103 301

These modules will be published as a part of delivery **[ETSI TS 103 301 v2.1.1](https://www.etsi.org/deliver/etsi_ts/103300_103399/103301/01.02.01_60/ts_103301v010201p.pdf) (2021-??)**

## License

The content of this repository and the files contained are released under the BSD-3-Clause license.

See the attached LICENSE file or visit https://forge.etsi.org/legal-matters.

## Dependencies

* The **[ITS-Container](https://forge.etsi.org/rep/ITS/asn1/cdd_ts102894_2)** module from **[ETSI TS 102 894-2 v1.3.1](https://www.etsi.org/deliver/etsi_ts/102800_102899/10289402/01.03.01_60/ts_10289402v010301p.pdf)**: "Intelligent Transport Systems (ITS); Users and applications requirements; Part 2: Applications and facilities layer common data dictionary".
* The **[DSRC](https://standards.iso.org/iso/ts/19091/ed-2/en)** module from  **CEN ISO/TS 19091-2018**: "Intelligent transport systems - Cooperative ITS - Using V2I and I2V communications for applications related to signalized intersections".
* The **[IVI](https://standards.iso.org/iso/ts/19321/ed-2/en/)** module from **CEN ISO/TS 19321-2020**: "Intelligent transport systems - Cooperative ITS - Dictionary of in-vehicle information (IVI) data structures".


## Syntax check

The correctness of these ASN.1 files can be verified using the bash script **syntax_check.bash**

See the notes in this script for further details.

For convenience a Dockerfile is available that might be useful for this.

```
Usage:
	>docker build -t etsi-its-asn-is:2.1.1 .
	>docker run -v `pwd`:/home/etsi-its-asn1 etsi-its-asn-is:2.1.1
```
