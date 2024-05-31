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

#include <etsi_its_denm_coding/StationaryVehicleContainer.h>
#include <etsi_its_denm_conversion/convertStationarySince.h>
#include <etsi_its_denm_conversion/convertCauseCode.h>
#include <etsi_its_denm_conversion/convertDangerousGoodsExtended.h>
#include <etsi_its_denm_conversion/convertNumberOfOccupants.h>
#include <etsi_its_denm_conversion/convertVehicleIdentification.h>
#include <etsi_its_denm_conversion/convertEnergyStorageType.h>
#ifdef ROS1
#include <etsi_its_denm_msgs/StationaryVehicleContainer.h>
namespace denm_msgs = etsi_its_denm_msgs;
#else
#include <etsi_its_denm_msgs/msg/stationary_vehicle_container.hpp>
namespace denm_msgs = etsi_its_denm_msgs::msg;
#endif


namespace etsi_its_denm_conversion {

void toRos_StationaryVehicleContainer(const StationaryVehicleContainer_t& in, denm_msgs::StationaryVehicleContainer& out) {

  if (in.stationarySince) {
    toRos_StationarySince(*in.stationarySince, out.stationary_since);
    out.stationary_since_is_present = true;
  }

  if (in.stationaryCause) {
    toRos_CauseCode(*in.stationaryCause, out.stationary_cause);
    out.stationary_cause_is_present = true;
  }

  if (in.carryingDangerousGoods) {
    toRos_DangerousGoodsExtended(*in.carryingDangerousGoods, out.carrying_dangerous_goods);
    out.carrying_dangerous_goods_is_present = true;
  }

  if (in.numberOfOccupants) {
    toRos_NumberOfOccupants(*in.numberOfOccupants, out.number_of_occupants);
    out.number_of_occupants_is_present = true;
  }

  if (in.vehicleIdentification) {
    toRos_VehicleIdentification(*in.vehicleIdentification, out.vehicle_identification);
    out.vehicle_identification_is_present = true;
  }

  if (in.energyStorageType) {
    toRos_EnergyStorageType(*in.energyStorageType, out.energy_storage_type);
    out.energy_storage_type_is_present = true;
  }

}

void toStruct_StationaryVehicleContainer(const denm_msgs::StationaryVehicleContainer& in, StationaryVehicleContainer_t& out) {

  memset(&out, 0, sizeof(StationaryVehicleContainer_t));

  if (in.stationary_since_is_present) {
    StationarySince_t stationary_since;
    toStruct_StationarySince(in.stationary_since, stationary_since);
    out.stationarySince = new StationarySince_t(stationary_since);
  }

  if (in.stationary_cause_is_present) {
    CauseCode_t stationary_cause;
    toStruct_CauseCode(in.stationary_cause, stationary_cause);
    out.stationaryCause = new CauseCode_t(stationary_cause);
  }

  if (in.carrying_dangerous_goods_is_present) {
    DangerousGoodsExtended_t carrying_dangerous_goods;
    toStruct_DangerousGoodsExtended(in.carrying_dangerous_goods, carrying_dangerous_goods);
    out.carryingDangerousGoods = new DangerousGoodsExtended_t(carrying_dangerous_goods);
  }

  if (in.number_of_occupants_is_present) {
    NumberOfOccupants_t number_of_occupants;
    toStruct_NumberOfOccupants(in.number_of_occupants, number_of_occupants);
    out.numberOfOccupants = new NumberOfOccupants_t(number_of_occupants);
  }

  if (in.vehicle_identification_is_present) {
    VehicleIdentification_t vehicle_identification;
    toStruct_VehicleIdentification(in.vehicle_identification, vehicle_identification);
    out.vehicleIdentification = new VehicleIdentification_t(vehicle_identification);
  }

  if (in.energy_storage_type_is_present) {
    EnergyStorageType_t energy_storage_type;
    toStruct_EnergyStorageType(in.energy_storage_type, energy_storage_type);
    out.energyStorageType = new EnergyStorageType_t(energy_storage_type);
  }

}

}