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

#include <etsi_its_denm_coding/denm_ImpactReductionContainer.h>
#include <etsi_its_denm_conversion/convertHeightLonCarr.h>
#include <etsi_its_denm_conversion/convertPosCentMass.h>
#include <etsi_its_denm_conversion/convertPosFrontAx.h>
#include <etsi_its_denm_conversion/convertPosLonCarr.h>
#include <etsi_its_denm_conversion/convertPositionOfOccupants.h>
#include <etsi_its_denm_conversion/convertPositionOfPillars.h>
#include <etsi_its_denm_conversion/convertRequestResponseIndication.h>
#include <etsi_its_denm_conversion/convertTurningRadius.h>
#include <etsi_its_denm_conversion/convertVehicleMass.h>
#include <etsi_its_denm_conversion/convertWheelBaseVehicle.h>
#ifdef ROS1
#include <etsi_its_denm_msgs/ImpactReductionContainer.h>
namespace denm_msgs = etsi_its_denm_msgs;
#else
#include <etsi_its_denm_msgs/msg/impact_reduction_container.hpp>
namespace denm_msgs = etsi_its_denm_msgs::msg;
#endif


namespace etsi_its_denm_conversion {

void toRos_ImpactReductionContainer(const denm_ImpactReductionContainer_t& in, denm_msgs::ImpactReductionContainer& out) {
  toRos_HeightLonCarr(in.heightLonCarrLeft, out.height_lon_carr_left);
  toRos_HeightLonCarr(in.heightLonCarrRight, out.height_lon_carr_right);
  toRos_PosLonCarr(in.posLonCarrLeft, out.pos_lon_carr_left);
  toRos_PosLonCarr(in.posLonCarrRight, out.pos_lon_carr_right);
  toRos_PositionOfPillars(in.positionOfPillars, out.position_of_pillars);
  toRos_PosCentMass(in.posCentMass, out.pos_cent_mass);
  toRos_WheelBaseVehicle(in.wheelBaseVehicle, out.wheel_base_vehicle);
  toRos_TurningRadius(in.turningRadius, out.turning_radius);
  toRos_PosFrontAx(in.posFrontAx, out.pos_front_ax);
  toRos_PositionOfOccupants(in.positionOfOccupants, out.position_of_occupants);
  toRos_VehicleMass(in.vehicleMass, out.vehicle_mass);
  toRos_RequestResponseIndication(in.requestResponseIndication, out.request_response_indication);
}

void toStruct_ImpactReductionContainer(const denm_msgs::ImpactReductionContainer& in, denm_ImpactReductionContainer_t& out) {
  memset(&out, 0, sizeof(denm_ImpactReductionContainer_t));

  toStruct_HeightLonCarr(in.height_lon_carr_left, out.heightLonCarrLeft);
  toStruct_HeightLonCarr(in.height_lon_carr_right, out.heightLonCarrRight);
  toStruct_PosLonCarr(in.pos_lon_carr_left, out.posLonCarrLeft);
  toStruct_PosLonCarr(in.pos_lon_carr_right, out.posLonCarrRight);
  toStruct_PositionOfPillars(in.position_of_pillars, out.positionOfPillars);
  toStruct_PosCentMass(in.pos_cent_mass, out.posCentMass);
  toStruct_WheelBaseVehicle(in.wheel_base_vehicle, out.wheelBaseVehicle);
  toStruct_TurningRadius(in.turning_radius, out.turningRadius);
  toStruct_PosFrontAx(in.pos_front_ax, out.posFrontAx);
  toStruct_PositionOfOccupants(in.position_of_occupants, out.positionOfOccupants);
  toStruct_VehicleMass(in.vehicle_mass, out.vehicleMass);
  toStruct_RequestResponseIndication(in.request_response_indication, out.requestResponseIndication);
}

}
