# etsi_its_messages

<p align="center">
  <img src="https://img.shields.io/github/v/release/ika-rwth-aachen/etsi_its_messages"/>
  <img src="https://img.shields.io/github/license/ika-rwth-aachen/etsi_its_messages"/>
  <a href="https://github.com/ika-rwth-aachen/etsi_its_messages/actions/workflows/codegen.yml"><img src="https://github.com/ika-rwth-aachen/etsi_its_messages/actions/workflows/codegen.yml/badge.svg"/></a>
  <a href="https://github.com/ika-rwth-aachen/etsi_its_messages/actions/workflows/docker-ros.yml"><img src="https://github.com/ika-rwth-aachen/etsi_its_messages/actions/workflows/docker-ros.yml/badge.svg"/></a>
  <a href="https://github.com/ika-rwth-aachen/etsi_its_messages/actions/workflows/doc.yml"><img src="https://github.com/ika-rwth-aachen/etsi_its_messages/actions/workflows/doc.yml/badge.svg"/></a>
  <img src="https://img.shields.io/badge/ROS-noetic-blueviolet"/>
  <img src="https://img.shields.io/badge/ROS 2-humble|iron-blueviolet"/>
</p>

**ROS / ROS 2 Support for ETSI ITS Messages for V2X Communication**

<img src="assets/teaser.gif" align="right" height=220>

<p align="left">The <i>etsi_its_messages</i> package stack allows to use standardized ETSI ITS messages for V2X communication in ROS / ROS 2 systems. Apart from the definition of ROS message equivalents to the ETSI ITS standards, this package stack also includes a conversion node for serializing the messages to and from a UDP payload, as well as RViz plugins for visualization (ROS 2 only).</p>

All message definitions and conversion functions are automatically generated based on the [ASN.1 definitions](https://forge.etsi.org/rep/ITS/asn1) of the standardized ETSI ITS messages.

> [!IMPORTANT]  
> This repository is open-sourced and maintained by the [**Institute for Automotive Engineering (ika) at RWTH Aachen University**](https://www.ika.rwth-aachen.de/).  
> **V2X Communication** is one of many research topics within our [*Vehicle Intelligence & Automated Driving*](https://www.ika.rwth-aachen.de/en/competences/fields-of-research/vehicle-intelligence-automated-driving.html) domain.  
> If you would like to learn more about how we can support your advanced driver assistance and automated driving efforts, feel free to reach out to us!  
> &nbsp;&nbsp;&nbsp;&nbsp; *Timo Woopen - Manager Research Area Vehicle Intelligence & Automated Driving*  
> &nbsp;&nbsp;&nbsp;&nbsp; *+49 241 80 23549*  
> &nbsp;&nbsp;&nbsp;&nbsp; *timo.woopen@ika.rwth-aachen.de*  

- [etsi\_its\_messages](#etsi_its_messages)
  - [Concept](#concept)
  - [Supported ETSI ITS Messages](#supported-etsi-its-messages)
  - [Packages](#packages)
    - [`etsi_its_msgs`](#etsi_its_msgs)
      - [Automated Generation](#automated-generation)
      - [Access Functions Documentation](#access-functions-documentation)
    - [`etsi_its_coding`](#etsi_its_coding)
      - [Automated Generation](#automated-generation-1)
    - [`etsi_its_conversion`](#etsi_its_conversion)
      - [Usage](#usage)
        - [Subscribed Topics](#subscribed-topics)
        - [Published Topics](#published-topics)
        - [Parameters](#parameters)
      - [Automated Generation](#automated-generation-2)
  - [Installation](#installation)
    - [docker-ros](#docker-ros)
  - [Acknowledgements](#acknowledgements)
  - [Notice](#notice)


## Concept

![Framework](assets/framework.png)

The core concept of the *etsi_its_messages* is to automatically generate the ROS support code based on the [ASN.1 definitions](https://forge.etsi.org/rep/ITS/asn1) of the standardized ETSI ITS messages *(CodeGen)*. The ROS support then allows ROS applications to not only natively use corresponding ETSI ITS message types, but to also exchange encoded ETSI ITS message payloads with the world outside of ROS *(Runtime)*.

A given ASN.1 definition is used to generate corresponding C-structures, ROS message definitions, as well as conversion functions between those two formats.

During runtime, the `etsi_its_conversion` ROS node converts incoming UDP payloads into corresponding ROS messages and vice versa. The ROS equivalents of the ETSI ITS messages can be used in any downstream ROS applications or visualized using the provided RViz plugins.


## Supported ETSI ITS Messages

| Status | Acronym | Name | Version | Definition | Repository |
| --- | --- | --- | --- | --- | --- |
| :white_check_mark: | CAM | Cooperative Awareness Message | 1.4.1 | [Link](https://www.etsi.org/deliver/etsi_en/302600_302699/30263702/01.04.01_60/en_30263702v010401p.pdf) | [Link](https://forge.etsi.org/rep/ITS/asn1/cam_en302637_2) |
| :white_check_mark: | DENM | Decentralized Environmental Notification Message | 1.3.1 | [Link](https://www.etsi.org/deliver/etsi_en/302600_302699/30263703/01.03.01_60/en_30263703v010301p.pdf) | [Link](https://forge.etsi.org/rep/ITS/asn1/denm_en302637_3) |
| :soon: | MAPEM | Map Extended Message | - | - | - |
| :soon: | SPATEM | Signal Phase and Timing Extended Message | - | - | - |
| :soon: | CPM | Collective Perception Message | - | - | - |


## Packages

```bash
etsi_its_messages
├── etsi_its_coding
│   ├── etsi_its_coding         # metapackage including all coding packages
│   ├── etsi_its_cam_coding
│   └── etsi_its_denm_coding
├── etsi_its_conversion
│   ├── etsi_its_conversion     # conversion node depending on all conversion packages
│   ├── etsi_its_cam_conversion
│   ├── etsi_its_denm_conversion
│   └── etsi_its_primitives_conversion
├── etsi_its_messages           # metapackage including all others
├── etsi_its_msgs
│   ├── etsi_its_msgs           # metapackage including all msg packages
│   ├── etsi_its_cam_msgs
│   └── etsi_its_denm_msgs
├── etsi_its_msgs_utils
└── etsi_its_rviz_plugins
```

### `etsi_its_msgs`

The `etsi_its_msgs` metapackage includes one dedicated package for each ETSI ITS message type, e.g., `etsi_its_cam_msgs`. These packages define the ROS message equivalents to the ETSI ITS message types, e.g., [`etsi_its_cam_msgs/msg/CAM`](etsi_its_msgs/etsi_its_cam_msgs/msg/CAM-PDU-Descriptions/CAM.msg).

In addition, the `etsi_its_msgs_utils` package contains header-only libraries providing helpful access functions for modifying the deeply nested ROS messages.

#### Automated Generation

The ROS message files are auto-generated based on the [ASN.1 definitions](https://forge.etsi.org/rep/ITS/asn1) of the ETSI ITS message standards.

```bash
# etsi_its_messages$
./utils/codegen/scripts/asn1ToRosMsg.py \
  asn1/raw/cam_en302637_2/CAM-PDU-Descriptions.asn \
  asn1/raw/cam_en302637_2/cdd/ITS-Container.asn \
  -o etsi_its_msgs/etsi_its_cam_msgs/msg
```

#### Access Functions Documentation

The access functions implemented in the `etsi_its_msgs_utils` package are documented [here](https://ika-rwth-aachen.github.io/etsi_its_messages).

The documentation can be generated by running [Doxygen](https://doxygen.nl/).

```bash
# etsi_its_messages/doc$
doxygen
```

### `etsi_its_coding`

The `etsi_its_coding` metapackage includes one dedicated package for each ETSI ITS message type, e.g., `etsi_its_cam_coding`. These packages provide C++ libraries containing a `struct` implementation of the ETSI ITS message types including functions for encoding and decoding the structures to binary buffers.

#### Automated Generation

The C/C++ implementation of the message types is auto-generated based on the [ASN.1 definitions](https://forge.etsi.org/rep/ITS/asn1) of the ETSI ITS message standards, using the [ASN.1 Compiler asn1c](https://github.com/vlm/asn1c).

```bash
# etsi_its_messages$
./utils/codegen/scripts/asn1ToC.py
  asn1/raw/cam_en302637_2/CAM-PDU-Descriptions.asn \
  asn1/raw/cam_en302637_2/cdd/ITS-Container.asn \
  -o etsi_its_coding/etsi_its_cam_coding
```

### `etsi_its_conversion`

The `etsi_its_conversion` package provides a C++ ROS nodelet or ROS 2 component node for converting `etsi_its_msgs` ROS messages to and from [UPER-encoded](https://www.oss.com/asn1/resources/asn1-made-simple/asn1-quick-reference/packed-encoding-rules.html) [`udp_msgs/msg/UdpPacket`](https://github.com/flynneva/udp_msgs/blob/main/msg/UdpPacket.msg) payloads. This way, ETSI ITS messages cannot only be used within the ROS ecosystem, but may also be received from or sent to outside applications.

The package depends on one dedicated package for each ETSI ITS message type, e.g., `etsi_its_cam_conversion`. These packages hold header-only libraries with recursive conversion functions for each nested message type.

#### Usage

The conversion node bridges all ETSI ITS message types at the same time in both directions.

```bash
# ROS 2
ros2 launch etsi_its_conversion converter.launch.py
# or
ros2 run etsi_its_conversion etsi_its_conversion_node --ros-args -p etsi_types:=[cam,denm] -p has_btp_destination_port:=true -p btp_destination_port_offset:=8 -p etsi_message_payload_offset:=78

# ROS
roslaunch etsi_its_conversion converter.ros1.launch
# or
rosrun nodelet nodelet standalone etsi_its_conversion/Converter _etsi_types:=[cam,denm] _has_btp_destination_port:=true _btp_destination_port_offset:=8 _etsi_message_payload_offset:=78
```

##### Subscribed Topics

| Topic | Type | Description |
| --- | --- | --- |
| `~/udp/in` | `udp_msgs/msg/UdpPacket` | UDP payload for conversion to ROS |
| `~/cam/in` | `etsi_its_cam_msgs/msg/CAM` | CAM for conversion to UDP |
| `~/denm/in` | `etsi_its_denm_msgs/msg/DENM` | DENM for conversion to UDP |

##### Published Topics

| Topic | Type | Description |
| --- | --- | --- |
| `~/udp/out` | `udp_msgs/msg/UdpPacket` | UDP payload converted from ROS message |
| `~/cam/out` | `etsi_its_cam_msgs/msg/CAM` | CAM converted from UDP payload |
| `~/denm/out` | `etsi_its_denm_msgs/msg/DENM` | DENM converted from UDP payload |

##### Parameters

| Parameter | Type | Description | Options |
| --- | --- | --- | --- |
| `has_btp_destination_port` | `bool` | whether incoming/outgoing UDP messages include a [2-byte BTP destination port](https://www.etsi.org/deliver/etsi_en/302600_302699/3026360501/02.01.00_20/en_3026360501v020100a.pdf) |
| `btp_destination_port_offset` | `int` | number of bytes before an optional 2-byte BTP destination port, see `has_btp_destination_port` |
| `etsi_message_payload_offset` | `int` | number of bytes before actual ETSI message payload |
| `etsi_types` | `string[]` | list of ETSI types to convert | `cam`, `denm` |


#### Automated Generation

The C++ conversion functions are auto-generated based on the [ASN.1 definitions](https://forge.etsi.org/rep/ITS/asn1) of the ETSI ITS message standards.

```bash
# etsi_its_messages$
./utils/codegen/scripts/asn1ToConversionHeader.py
  asn1/raw/cam_en302637_2/CAM-PDU-Descriptions.asn \
  asn1/raw/cam_en302637_2/cdd/ITS-Container.asn \
  -t cam \
  -o etsi_its_conversion/etsi_its_cam_conversion/include/etsi_its_cam_conversion
```


## Installation

All *etsi_its_messages* packages are released as official ROS / ROS 2 packages and can easily be installed via a package manager.

> [!WARNING]
> The initial release may not have been synced to the package managers yet. In the meantime, please refer to installation from source as shown below.

```bash
sudo apt update
sudo apt install ros-$ROS_DISTRO-etsi-its-messages
```

If you would like to install *etsi_its_messages* from source, simply clone this repository into your ROS workspace. All dependencies that are listed in the packages' `package.xml` can be installed using [*rosdep*](http://wiki.ros.org/rosdep).

```bash
# etsi_its_messages$
rosdep install -r --ignore-src --from-paths .

# ROS 2
# workspace$
colcon build --packages-up-to etsi_its_messages --cmake-args -DCMAKE_BUILD_TYPE=Release

# ROS
# workspace$
catkin build -DCMAKE_BUILD_TYPE=Release etsi_its_messages
```

### docker-ros

The *etsi_its_messages* package stack is also available as a Docker image, containerized through [*docker-ros*](https://github.com/ika-rwth-aachen/docker-ros). Note that launching these containers starts the `etsi_its_conversion` node by default.

```bash
# ROS 2
docker run --rm ghcr.io/ika-rwth-aachen/etsi_its_messages:ros2

# ROS
docker run --rm ghcr.io/ika-rwth-aachen/etsi_its_messages:ros
```


## Acknowledgements

This work is accomplished within the projects AIthena, 6GEM and AUTOtech.*agil*. We acknowledge the financial support for the projects by
- the *European Union’s Horizon Europe Research and Innovation Programme* :eu: under Grant Agreement No 101076754 for AIthena,
- and the *Federal Ministry of Education and Research of Germany (BMBF)* :de: for 6GEM (FKZ 16KISK036K) and AUTOtech.*agil* (FKZ 01IS22088A).

## Notice

This repository is not endorsed by or otherwise affiliated with [ETSI](https://www.etsi.org).

This repository uses the following software. For full license details, please refer to the specific license files of the respective software.

- [asn1c](https://github.com/vlm/asn1c)
    ```
    BSD 2-Clause License
    Copyright (c) 2003-2017  Lev Walkin <vlm@lionet.info> and contributors.
    All rights reserved.
    ```
- [asn1tools](https://github.com/eerimoq/asn1tools)
    ```
    MIT License
    Copyright (c) 2017-2019 Erik Moqvist
    ```
- [ETSI ITS ASN1](https://forge.etsi.org/rep/ITS/asn1)
    ```
    BSD 3-Clause License
    Copyright (c) ETSI
    ```
- [GeographicLib](https://github.com/geographiclib/geographiclib)
    ```
    MIT License
    Copyright (c) 2008-2023, Charles Karney
    ```
- [ROS](https://www.ros.org/)
    ```
    BSD 3-Clause License
    All rights reserved.
    ```
- [ROS 2](https://www.ros2.org/)
    ```
    Apache 2.0 License
    All rights reserved.
    ```
