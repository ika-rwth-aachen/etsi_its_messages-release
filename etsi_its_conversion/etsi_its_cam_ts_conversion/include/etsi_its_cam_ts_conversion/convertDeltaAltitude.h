/** ============================================================================
MIT License

Copyright (c) 2023-2024 Institute for Automotive Engineering (ika), RWTH Aachen University

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
============================================================================= */

/** Auto-generated by https://github.com/ika-rwth-aachen/etsi_its_messages -----
python3 \
  utils/codegen/codegen-py/asn1ToConversionHeader.py \
  asn1/raw/cam_ts103900/CAM-PDU-Descriptions.asn \
  asn1/patched/cam_ts103900/cdd/ETSI-ITS-CDD.asn \
  -t \
  cam_ts \
  -o \
  etsi_its_conversion/etsi_its_cam_ts_conversion/include/etsi_its_cam_ts_conversion
----------------------------------------------------------------------------- */

/** ASN.1 Definition -----------------------------------------------------------
*
 * This DE represents an offset altitude with regards to a defined altitude value.
 * It may be used to describe a geographical point with regards to a specific reference geographical position.
 *
 * The value shall be set to:
 * - `-12 700` for values equal to or lower than -127 metres,
 * - `n` (`n > -12 700` and `n <= 0`) for altitude offset n x 0,01 metre below the reference position,
 * - `0` for no altitudinal offset,
 * - `n` (`n > 0` and `n < 12799`) for altitude offset n x 0,01 metre above the reference position,
 * - `12 799` for values equal to or greater than 127,99 metres,
 * - `12 800` when the information is unavailable.
 *
 * @unit: 0,01 metre
 * @category: GeoReference information
 * @revision: editorial update in V2.1.1
 *
DeltaAltitude ::= INTEGER {
    negativeOutOfRange (-12700),
    positiveOutOfRange (12799),
    unavailable        (12800)
} (-12700..12800)
----------------------------------------------------------------------------- */

#pragma once

#include <etsi_its_cam_ts_coding/cam_ts_DeltaAltitude.h>
#include <etsi_its_cam_ts_coding/INTEGER.h>
#include <etsi_its_primitives_conversion/convertINTEGER.h>
#ifdef ROS1
#include <etsi_its_cam_ts_msgs/DeltaAltitude.h>
namespace cam_ts_msgs = etsi_its_cam_ts_msgs;
#else
#include <etsi_its_cam_ts_msgs/msg/delta_altitude.hpp>
namespace cam_ts_msgs = etsi_its_cam_ts_msgs::msg;
#endif


namespace etsi_its_cam_ts_conversion {

void toRos_DeltaAltitude(const cam_ts_DeltaAltitude_t& in, cam_ts_msgs::DeltaAltitude& out) {
  etsi_its_primitives_conversion::toRos_INTEGER(in, out.value);
}

void toStruct_DeltaAltitude(const cam_ts_msgs::DeltaAltitude& in, cam_ts_DeltaAltitude_t& out) {
  memset(&out, 0, sizeof(cam_ts_DeltaAltitude_t));
  etsi_its_primitives_conversion::toStruct_INTEGER(in.value, out);
}

}
