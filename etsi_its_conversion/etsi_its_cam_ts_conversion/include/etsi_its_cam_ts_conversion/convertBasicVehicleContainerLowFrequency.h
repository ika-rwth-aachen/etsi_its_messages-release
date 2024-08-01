/** ============================================================================
MIT License

Copyright (c) 2023-2024 Institute for Automotive Engineering (ika), RWTH Aachen University
Copyright (c) 2024 Instituto de Telecomunicações, Universidade de Aveiro

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

#include <etsi_its_cam_ts_coding/cam_ts_BasicVehicleContainerLowFrequency.h>
#include <etsi_its_cam_ts_conversion/convertExteriorLights.h>
#include <etsi_its_cam_ts_conversion/convertPath.h>
#include <etsi_its_cam_ts_conversion/convertVehicleRole.h>
#ifdef ROS1
#include <etsi_its_cam_ts_msgs/BasicVehicleContainerLowFrequency.h>
namespace cam_ts_msgs = etsi_its_cam_ts_msgs;
#else
#include <etsi_its_cam_ts_msgs/msg/basic_vehicle_container_low_frequency.hpp>
namespace cam_ts_msgs = etsi_its_cam_ts_msgs::msg;
#endif


namespace etsi_its_cam_ts_conversion {

void toRos_BasicVehicleContainerLowFrequency(const cam_ts_BasicVehicleContainerLowFrequency_t& in, cam_ts_msgs::BasicVehicleContainerLowFrequency& out) {
  toRos_VehicleRole(in.vehicleRole, out.vehicle_role);
  toRos_ExteriorLights(in.exteriorLights, out.exterior_lights);
  toRos_Path(in.pathHistory, out.path_history);
}

void toStruct_BasicVehicleContainerLowFrequency(const cam_ts_msgs::BasicVehicleContainerLowFrequency& in, cam_ts_BasicVehicleContainerLowFrequency_t& out) {
  memset(&out, 0, sizeof(cam_ts_BasicVehicleContainerLowFrequency_t));

  toStruct_VehicleRole(in.vehicle_role, out.vehicleRole);
  toStruct_ExteriorLights(in.exterior_lights, out.exteriorLights);
  toStruct_Path(in.path_history, out.pathHistory);
}

}
