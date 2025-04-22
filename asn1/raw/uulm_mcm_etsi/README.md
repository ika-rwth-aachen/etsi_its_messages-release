Maneuver Coordination Message (MCM)
===================================

This repository contains the ASN.1 definition of a custom version of the Maneuver Coordination Message (MCM) that was proposed in [An Extended Maneuver Coordination Protocol with Support for Urban Scenarios and Mixed Traffic](https://ieeexplore.ieee.org/document/9644632).

ASN.1 Definitions
=================

 - The MCM was independently developed as parts of multiple projects of our research institute (see Acknowledgements).
 - The CDD is based on the original definition found [here](https://forge.etsi.org/rep/ITS/asn1/cdd_ts102894_2) (branch release2 commit 60799344)

Summary of changes for the CDD:
 - AngleConfidence, SpeedConfidence: Increased number of bits to express higher variances
 - MatrixIncludedComponents: Allow correlation entries between object dimensions and other state variables
 - PerceivedObject: Added optional associatedStationID field for tracks associated with recognized ITS stations (by matching CAMs to tracks)
 - PerceivedObject: Added container datatype for trajectory predictions (PredictionsContainer)

A summary of the changes can also be found [here](https://github.com/uulm-mrm/v2x_etsi_asn1/commit/f812f7a86b002a7acebf74427a6a76fb76aaa886).

License
=======

License: Apache 2.0

Author: Robin Dehler (UULM-MRM)

Maintainer: Robin Dehler (UULM-MRM)

Affiliation: Institute of Measurement, Control and Microtechnology (MRM), Ulm University (UULM)

Acknowledgements
================

The basic versions of the adapted ASN.1 files are based on our joint developments with the project partners within the project [LUKAS](https://projekt-lukas.de/). This project was financially supported by the Federal Ministry of Economic Affairs and Climate Action of Germany within the program "Highly and Fully Automated Driving in Demanding Driving Situations" (project LUKAS, grant number 19A20004F).

Parts of the further developments have been made as part of the [PoDIUM](https://podium-project.eu/) project and the [EVENTS](https://www.events-project.eu/) project, which both are funded by the European Union under grant agreement No. 101069547 and No. 101069614, respectively. Views and opinions expressed are however those of the authors only and do not necessarily reflect those of the European Union or European Commission. Neither the European Union nor the granting authority can be held responsible for them.

Parts of the further developments have been financially supported by the Federal Ministry of Education and Research (project [autotech.agil](https://www.autotechagil.de/), FKZ 01IS22088W).

Citation
========

Please use the following citation when referencing our work:

**An Extended Maneuver Coordination Protocol with Support for Urban Scenarios and Mixed Traffic**

Max Mertens, Johannes Müller, Robin Dehler *et al.*


```
@inproceedings{9644632,
  author={Mertens, Max Bastian and Müller, Johannes and Dehler, Robin and Klimke, Marvin and Maier, Matthias and Gherekhloo, Soheil and Völz, Benjamin and Henn, Rüdiger-Walter and Buchholz, Michael},
  booktitle={2021 IEEE Vehicular Networking Conference (VNC)}, 
  title={An Extended Maneuver Coordination Protocol with Support for Urban Scenarios and Mixed Traffic}, 
  year={2021},
  volume={},
  number={},
  pages={32-35},
  keywords={Protocols;Connected vehicles;Roads;Conferences;Bandwidth;Proposals},
  doi={10.1109/VNC52810.2021.9644632}}
```
