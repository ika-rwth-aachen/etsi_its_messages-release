/** ============================================================================
MIT License

Copyright (c) 2023 Institute for Automotive Engineering (ika), RWTH Aachen University

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

// --- Auto-generated by asn1ToConversionHeader.py -----------------------------

#pragma once

#include <etsi_its_cam_coding/BasicContainer.h>
#include <etsi_its_cam_conversion/convertStationType.h>
#include <etsi_its_cam_conversion/convertReferencePosition.h>
#ifdef ROS1
#include <etsi_its_cam_msgs/BasicContainer.h>
namespace cam_msgs = etsi_its_cam_msgs;
#else
#include <etsi_its_cam_msgs/msg/basic_container.hpp>
namespace cam_msgs = etsi_its_cam_msgs::msg;
#endif


namespace etsi_its_cam_conversion {

void toRos_BasicContainer(const BasicContainer_t& in, cam_msgs::BasicContainer& out) {

  toRos_StationType(in.stationType, out.station_type);
  toRos_ReferencePosition(in.referencePosition, out.reference_position);
}

void toStruct_BasicContainer(const cam_msgs::BasicContainer& in, BasicContainer_t& out) {

  memset(&out, 0, sizeof(BasicContainer_t));

  toStruct_StationType(in.station_type, out.stationType);
  toStruct_ReferencePosition(in.reference_position, out.referencePosition);
}

}