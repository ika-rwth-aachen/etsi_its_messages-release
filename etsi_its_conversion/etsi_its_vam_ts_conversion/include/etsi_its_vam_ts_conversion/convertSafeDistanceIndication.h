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
  asn1/raw/vam-ts103300_3/VAM-PDU-Descriptions.asn \
  asn1/patched/vam-ts103300_3/cdd/ETSI-ITS-CDD.asn \
  -t \
  vam_ts \
  -o \
  etsi_its_conversion/etsi_its_vam_ts_conversion/include/etsi_its_vam_ts_conversion
----------------------------------------------------------------------------- */

/** ASN.1 Definition -----------------------------------------------------------
*
 * This DF provides the safe distance indication of a traffic participant with other traffic participant(s).
 *
 * It shall include the following components: 
 * 
 * @field subjectStation: optionally indicates one "other" traffic participant identified by its ITS-S.
 *  
 * @field safeDistanceIndicator: indicates whether the distance between the ego ITS-S and the traffic participant(s) is safe.
 * If subjectStation is present then it indicates whether the distance between the ego ITS-S and the traffic participant indicated in the component subjectStation is safe. 
 *
 * @field timeToCollision: optionally indicated the time-to-collision calculated as sqrt(LaDi^2 + LoDi^2 + VDi^2/relative speed 
 * and represented in  the  nearest 100  ms. This component may be present only if subjectStation is present. 
 *
 * @note: the abbreviations used are Lateral Distance (LaD),  Longitudinal Distance (LoD) and Vertical Distance (VD) 
 * and their respective  thresholds, Minimum  Safe  Lateral  Distance (MSLaD), Minimum  Safe  Longitudinal Distance  (MSLoD),  and  Minimum  Safe Vertical Distance (MSVD).
 *
 * @category: Traffic information, Kinematic information
 * @revision: created in V2.1.1
 *
SafeDistanceIndication ::= SEQUENCE {
    subjectStation           StationId OPTIONAL,
    safeDistanceIndicator    SafeDistanceIndicator,
    timeToCollision          DeltaTimeTenthOfSecond OPTIONAL,
    ...
}
----------------------------------------------------------------------------- */

#pragma once

#include <etsi_its_vam_ts_coding/vam_ts_SafeDistanceIndication.h>
#include <etsi_its_vam_ts_conversion/convertDeltaTimeTenthOfSecond.h>
#include <etsi_its_vam_ts_conversion/convertSafeDistanceIndicator.h>
#include <etsi_its_vam_ts_conversion/convertStationId.h>
#ifdef ROS1
#include <etsi_its_vam_ts_msgs/SafeDistanceIndication.h>
namespace vam_ts_msgs = etsi_its_vam_ts_msgs;
#else
#include <etsi_its_vam_ts_msgs/msg/safe_distance_indication.hpp>
namespace vam_ts_msgs = etsi_its_vam_ts_msgs::msg;
#endif


namespace etsi_its_vam_ts_conversion {

void toRos_SafeDistanceIndication(const vam_ts_SafeDistanceIndication_t& in, vam_ts_msgs::SafeDistanceIndication& out) {
  if (in.subjectStation) {
    toRos_StationId(*in.subjectStation, out.subject_station);
    out.subject_station_is_present = true;
  }
  toRos_SafeDistanceIndicator(in.safeDistanceIndicator, out.safe_distance_indicator);
  if (in.timeToCollision) {
    toRos_DeltaTimeTenthOfSecond(*in.timeToCollision, out.time_to_collision);
    out.time_to_collision_is_present = true;
  }
}

void toStruct_SafeDistanceIndication(const vam_ts_msgs::SafeDistanceIndication& in, vam_ts_SafeDistanceIndication_t& out) {
  memset(&out, 0, sizeof(vam_ts_SafeDistanceIndication_t));
  if (in.subject_station_is_present) {
    out.subjectStation = (vam_ts_StationId_t*) calloc(1, sizeof(vam_ts_StationId_t));
    toStruct_StationId(in.subject_station, *out.subjectStation);
  }
  toStruct_SafeDistanceIndicator(in.safe_distance_indicator, out.safeDistanceIndicator);
  if (in.time_to_collision_is_present) {
    out.timeToCollision = (vam_ts_DeltaTimeTenthOfSecond_t*) calloc(1, sizeof(vam_ts_DeltaTimeTenthOfSecond_t));
    toStruct_DeltaTimeTenthOfSecond(in.time_to_collision, *out.timeToCollision);
  }
}

}
