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

#include <etsi_its_vam_ts_coding/vam_ts_GeneralizedLanePosition.h>
#include <etsi_its_vam_ts_conversion/convertLanePosition.h>
#include <etsi_its_vam_ts_conversion/convertLanePositionAndType.h>
#include <etsi_its_vam_ts_conversion/convertMapPosition.h>
#include <etsi_its_vam_ts_conversion/convertTrafficIslandPosition.h>
#ifdef ROS1
#include <etsi_its_vam_ts_msgs/GeneralizedLanePosition.h>
namespace vam_ts_msgs = etsi_its_vam_ts_msgs;
#else
#include <etsi_its_vam_ts_msgs/msg/generalized_lane_position.hpp>
namespace vam_ts_msgs = etsi_its_vam_ts_msgs::msg;
#endif


namespace etsi_its_vam_ts_conversion {

void toRos_GeneralizedLanePosition(const vam_ts_GeneralizedLanePosition_t& in, vam_ts_msgs::GeneralizedLanePosition& out) {
  switch (in.present) {
  case vam_ts_GeneralizedLanePosition_PR_trafficLanePosition:
    toRos_LanePosition(in.choice.trafficLanePosition, out.traffic_lane_position);
    out.choice = vam_ts_msgs::GeneralizedLanePosition::CHOICE_TRAFFIC_LANE_POSITION;
    break;
  case vam_ts_GeneralizedLanePosition_PR_nonTrafficLanePosition:
    toRos_LanePositionAndType(in.choice.nonTrafficLanePosition, out.non_traffic_lane_position);
    out.choice = vam_ts_msgs::GeneralizedLanePosition::CHOICE_NON_TRAFFIC_LANE_POSITION;
    break;
  case vam_ts_GeneralizedLanePosition_PR_trafficIslandPosition:
    toRos_TrafficIslandPosition(in.choice.trafficIslandPosition, out.traffic_island_position);
    out.choice = vam_ts_msgs::GeneralizedLanePosition::CHOICE_TRAFFIC_ISLAND_POSITION;
    break;
  case vam_ts_GeneralizedLanePosition_PR_mapPosition:
    toRos_MapPosition(in.choice.mapPosition, out.map_position);
    out.choice = vam_ts_msgs::GeneralizedLanePosition::CHOICE_MAP_POSITION;
    break;
  default: break;
  }
}

void toStruct_GeneralizedLanePosition(const vam_ts_msgs::GeneralizedLanePosition& in, vam_ts_GeneralizedLanePosition_t& out) {
  memset(&out, 0, sizeof(vam_ts_GeneralizedLanePosition_t));

  switch (in.choice) {
  case vam_ts_msgs::GeneralizedLanePosition::CHOICE_TRAFFIC_LANE_POSITION:
    toStruct_LanePosition(in.traffic_lane_position, out.choice.trafficLanePosition);
    out.present = vam_ts_GeneralizedLanePosition_PR::vam_ts_GeneralizedLanePosition_PR_trafficLanePosition;
    break;
  case vam_ts_msgs::GeneralizedLanePosition::CHOICE_NON_TRAFFIC_LANE_POSITION:
    toStruct_LanePositionAndType(in.non_traffic_lane_position, out.choice.nonTrafficLanePosition);
    out.present = vam_ts_GeneralizedLanePosition_PR::vam_ts_GeneralizedLanePosition_PR_nonTrafficLanePosition;
    break;
  case vam_ts_msgs::GeneralizedLanePosition::CHOICE_TRAFFIC_ISLAND_POSITION:
    toStruct_TrafficIslandPosition(in.traffic_island_position, out.choice.trafficIslandPosition);
    out.present = vam_ts_GeneralizedLanePosition_PR::vam_ts_GeneralizedLanePosition_PR_trafficIslandPosition;
    break;
  case vam_ts_msgs::GeneralizedLanePosition::CHOICE_MAP_POSITION:
    toStruct_MapPosition(in.map_position, out.choice.mapPosition);
    out.present = vam_ts_GeneralizedLanePosition_PR::vam_ts_GeneralizedLanePosition_PR_mapPosition;
    break;
  default: break;
  }
}

}
