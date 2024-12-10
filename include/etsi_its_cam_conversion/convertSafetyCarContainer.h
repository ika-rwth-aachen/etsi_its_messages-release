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
  asn1/raw/cam_en302637_2/CAM-PDU-Descriptions.asn \
  asn1/raw/cam_en302637_2/cdd/ITS-Container.asn \
  -t \
  cam \
  -o \
  etsi_its_conversion/etsi_its_cam_conversion/include/etsi_its_cam_conversion
----------------------------------------------------------------------------- */

/** ASN.1 Definition -----------------------------------------------------------
SafetyCarContainer ::= SEQUENCE {
	lightBarSirenInUse LightBarSirenInUse,
	incidentIndication CauseCode OPTIONAL,
	trafficRule TrafficRule OPTIONAL,
	speedLimit SpeedLimit OPTIONAL
}
----------------------------------------------------------------------------- */

#pragma once

#include <etsi_its_cam_coding/cam_SafetyCarContainer.h>
#include <etsi_its_cam_conversion/convertCauseCode.h>
#include <etsi_its_cam_conversion/convertLightBarSirenInUse.h>
#include <etsi_its_cam_conversion/convertSpeedLimit.h>
#include <etsi_its_cam_conversion/convertTrafficRule.h>
#ifdef ROS1
#include <etsi_its_cam_msgs/SafetyCarContainer.h>
namespace cam_msgs = etsi_its_cam_msgs;
#else
#include <etsi_its_cam_msgs/msg/safety_car_container.hpp>
namespace cam_msgs = etsi_its_cam_msgs::msg;
#endif


namespace etsi_its_cam_conversion {

void toRos_SafetyCarContainer(const cam_SafetyCarContainer_t& in, cam_msgs::SafetyCarContainer& out) {
  toRos_LightBarSirenInUse(in.lightBarSirenInUse, out.light_bar_siren_in_use);
  if (in.incidentIndication) {
    toRos_CauseCode(*in.incidentIndication, out.incident_indication);
    out.incident_indication_is_present = true;
  }
  if (in.trafficRule) {
    toRos_TrafficRule(*in.trafficRule, out.traffic_rule);
    out.traffic_rule_is_present = true;
  }
  if (in.speedLimit) {
    toRos_SpeedLimit(*in.speedLimit, out.speed_limit);
    out.speed_limit_is_present = true;
  }
}

void toStruct_SafetyCarContainer(const cam_msgs::SafetyCarContainer& in, cam_SafetyCarContainer_t& out) {
  memset(&out, 0, sizeof(cam_SafetyCarContainer_t));
  toStruct_LightBarSirenInUse(in.light_bar_siren_in_use, out.lightBarSirenInUse);
  if (in.incident_indication_is_present) {
    out.incidentIndication = (cam_CauseCode_t*) calloc(1, sizeof(cam_CauseCode_t));
    toStruct_CauseCode(in.incident_indication, *out.incidentIndication);
  }
  if (in.traffic_rule_is_present) {
    out.trafficRule = (cam_TrafficRule_t*) calloc(1, sizeof(cam_TrafficRule_t));
    toStruct_TrafficRule(in.traffic_rule, *out.trafficRule);
  }
  if (in.speed_limit_is_present) {
    out.speedLimit = (cam_SpeedLimit_t*) calloc(1, sizeof(cam_SpeedLimit_t));
    toStruct_SpeedLimit(in.speed_limit, *out.speedLimit);
  }
}

}