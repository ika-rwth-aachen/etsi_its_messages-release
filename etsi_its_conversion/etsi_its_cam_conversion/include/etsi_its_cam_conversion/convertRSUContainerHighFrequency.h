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

#include <etsi_its_cam_coding/RSUContainerHighFrequency.h>
#include <etsi_its_cam_conversion/convertProtectedCommunicationZonesRSU.h>
#ifdef ROS1
#include <etsi_its_cam_msgs/RSUContainerHighFrequency.h>
namespace cam_msgs = etsi_its_cam_msgs;
#else
#include <etsi_its_cam_msgs/msg/rsu_container_high_frequency.hpp>
namespace cam_msgs = etsi_its_cam_msgs::msg;
#endif


namespace etsi_its_cam_conversion {

void toRos_RSUContainerHighFrequency(const RSUContainerHighFrequency_t& in, cam_msgs::RSUContainerHighFrequency& out) {

  if (in.protectedCommunicationZonesRSU) {
    toRos_ProtectedCommunicationZonesRSU(*in.protectedCommunicationZonesRSU, out.protected_communication_zones_rsu);
    out.protected_communication_zones_rsu_is_present = true;
  }

}

void toStruct_RSUContainerHighFrequency(const cam_msgs::RSUContainerHighFrequency& in, RSUContainerHighFrequency_t& out) {

  memset(&out, 0, sizeof(RSUContainerHighFrequency_t));

  if (in.protected_communication_zones_rsu_is_present) {
    ProtectedCommunicationZonesRSU_t protected_communication_zones_rsu;
    toStruct_ProtectedCommunicationZonesRSU(in.protected_communication_zones_rsu, protected_communication_zones_rsu);
    out.protectedCommunicationZonesRSU = new ProtectedCommunicationZonesRSU_t(protected_communication_zones_rsu);
  }

}

}