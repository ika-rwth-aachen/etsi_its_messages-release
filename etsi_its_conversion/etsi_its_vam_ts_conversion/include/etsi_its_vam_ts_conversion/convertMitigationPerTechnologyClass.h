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

#include <etsi_its_vam_ts_coding/vam_ts_MitigationPerTechnologyClass.h>
#include <etsi_its_vam_ts_coding/INTEGER.h>
#include <etsi_its_primitives_conversion/convertINTEGER.h>
#include <etsi_its_vam_ts_conversion/convertAccessTechnologyClass.h>
#ifdef ROS1
#include <etsi_its_vam_ts_msgs/MitigationPerTechnologyClass.h>
namespace vam_ts_msgs = etsi_its_vam_ts_msgs;
#else
#include <etsi_its_vam_ts_msgs/msg/mitigation_per_technology_class.hpp>
namespace vam_ts_msgs = etsi_its_vam_ts_msgs::msg;
#endif


namespace etsi_its_vam_ts_conversion {

void toRos_MitigationPerTechnologyClass(const vam_ts_MitigationPerTechnologyClass_t& in, vam_ts_msgs::MitigationPerTechnologyClass& out) {
  toRos_AccessTechnologyClass(in.accessTechnologyClass, out.access_technology_class);
  if (in.lowDutyCycle) {
    etsi_its_primitives_conversion::toRos_INTEGER(*in.lowDutyCycle, out.low_duty_cycle);
    out.low_duty_cycle_is_present = true;
  }
  if (in.powerReduction) {
    etsi_its_primitives_conversion::toRos_INTEGER(*in.powerReduction, out.power_reduction);
    out.power_reduction_is_present = true;
  }
  if (in.dmcToffLimit) {
    etsi_its_primitives_conversion::toRos_INTEGER(*in.dmcToffLimit, out.dmc_toff_limit);
    out.dmc_toff_limit_is_present = true;
  }
  if (in.dmcTonLimit) {
    etsi_its_primitives_conversion::toRos_INTEGER(*in.dmcTonLimit, out.dmc_ton_limit);
    out.dmc_ton_limit_is_present = true;
  }
}

void toStruct_MitigationPerTechnologyClass(const vam_ts_msgs::MitigationPerTechnologyClass& in, vam_ts_MitigationPerTechnologyClass_t& out) {
  memset(&out, 0, sizeof(vam_ts_MitigationPerTechnologyClass_t));

  toStruct_AccessTechnologyClass(in.access_technology_class, out.accessTechnologyClass);
  if (in.low_duty_cycle_is_present) {
    out.lowDutyCycle = (INTEGER_t*) calloc(1, sizeof(INTEGER_t));
    etsi_its_primitives_conversion::toStruct_INTEGER(in.low_duty_cycle, *out.lowDutyCycle);
  }
  if (in.power_reduction_is_present) {
    out.powerReduction = (INTEGER_t*) calloc(1, sizeof(INTEGER_t));
    etsi_its_primitives_conversion::toStruct_INTEGER(in.power_reduction, *out.powerReduction);
  }
  if (in.dmc_toff_limit_is_present) {
    out.dmcToffLimit = (INTEGER_t*) calloc(1, sizeof(INTEGER_t));
    etsi_its_primitives_conversion::toStruct_INTEGER(in.dmc_toff_limit, *out.dmcToffLimit);
  }
  if (in.dmc_ton_limit_is_present) {
    out.dmcTonLimit = (INTEGER_t*) calloc(1, sizeof(INTEGER_t));
    etsi_its_primitives_conversion::toStruct_INTEGER(in.dmc_ton_limit, *out.dmcTonLimit);
  }
}

}
