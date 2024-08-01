/*
=============================================================================
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
=============================================================================
*/

/**
 * @file impl/cdd/cdd_setters_common.h
 * @brief Common setter functions for the ETSI ITS Common Data Dictionary (CDD) v1.3.1 and v2.1.1
 */

#pragma once

#include <cstring>
#include <etsi_its_msgs_utils/impl/cdd/cdd_checks.h>
#include <etsi_its_msgs_utils/impl/constants.h>
#include <GeographicLib/UTMUPS.hpp>



/**
 * @brief Set the TimestampITS object
 *
 * @param[in] timestamp_its TimestampITS object to set the timestamp
 * @param[in] unix_nanosecs Unix-Nanoseconds to set the timestamp for
 * @param[in] n_leap_seconds Number of leap-seconds since 2004. (Default: etsi_its_msgs::LEAP_SECOND_INSERTIONS_SINCE_2004.end()->second)
 * @param[in] epoch_offset Unix-Timestamp in seconds for the 01.01.2004 at 00:00:00
 */
inline void setTimestampITS(TimestampIts& timestamp_its, const uint64_t unix_nanosecs, const uint16_t n_leap_seconds = etsi_its_msgs::LEAP_SECOND_INSERTIONS_SINCE_2004.end()->second) {
  uint64_t t_its = unix_nanosecs*1e-6 + (uint64_t)(n_leap_seconds*1e3) - etsi_its_msgs::UNIX_SECONDS_2004*1e3;
  throwIfOutOfRange(t_its, TimestampIts::MIN, TimestampIts::MAX, "TimestampIts");
  timestamp_its.value = t_its;
}

/**
 * @brief Set the Latitude object
 *
 * @param latitude object to set
 * @param deg Latitude value in degree as decimal number
 */
inline void setLatitude(Latitude& latitude, const double deg) {
  int64_t angle_in_10_micro_degree = (int64_t)std::round(deg*1e7);
  throwIfOutOfRange(angle_in_10_micro_degree, Latitude::MIN, Latitude::MAX, "Latitude");
  latitude.value = angle_in_10_micro_degree;
}

/**
 * @brief Set the Longitude object
 *
 * @param longitude object to set
 * @param deg Longitude value in degree as decimal number
 */
inline void setLongitude(Longitude& longitude, const double deg) {
  int64_t angle_in_10_micro_degree = (int64_t)std::round(deg*1e7);
  throwIfOutOfRange(angle_in_10_micro_degree, Longitude::MIN, Longitude::MAX, "Longitude");
  longitude.value = angle_in_10_micro_degree;
}

/**
 * @brief Set the AltitudeValue object
 *
 * @param altitude object to set
 * @param value AltitudeValue value (above the reference ellipsoid surface) in meter as decimal number
 */
inline void setAltitudeValue(AltitudeValue& altitude, const double value) {
  int64_t alt_in_cm = (int64_t)std::round(value*1e2);
  if(alt_in_cm>=AltitudeValue::MIN && alt_in_cm<=AltitudeValue::MAX) altitude.value = alt_in_cm;
  else if(alt_in_cm<AltitudeValue::MIN) altitude.value = AltitudeValue::MIN;
  else if(alt_in_cm>AltitudeValue::MAX) altitude.value = AltitudeValue::MAX;
}

/**
 * @brief Set the Altitude object
 *
 * AltitudeConfidence is set to UNAVAILABLE
 *
 * @param altitude object to set
 * @param value Altitude value (above the reference ellipsoid surface) in meter as decimal number
 */
inline void setAltitude(Altitude& altitude, const double value) {
  altitude.altitude_confidence.value = AltitudeConfidence::UNAVAILABLE;
  setAltitudeValue(altitude.altitude_value, value);
}

/**
 * @brief Set the HeadingValue object
 *
 * 0.0° equals WGS84 North, 90.0° equals WGS84 East, 180.0° equals WGS84 South and 270.0° equals WGS84 West
 *
 * @param heading object to set
 * @param value Heading value in degree as decimal number
 */
inline void setHeadingValue(HeadingValue& heading, const double value) {
  int64_t deg = (int64_t)std::round(value*1e1);
  throwIfOutOfRange(deg, HeadingValue::MIN, HeadingValue::MAX, "HeadingValue");
  heading.value = deg;
}

/**
 * @brief Set the Heading object
 *
 * 0.0° equals WGS84 North, 90.0° equals WGS84 East, 180.0° equals WGS84 South and 270.0° equals WGS84 West
 * HeadingConfidence is set to UNAVAILABLE
 *
 * @param heading object to set
 * @param value Heading value in degree as decimal number
 */
inline void setHeading(Heading& heading, const double value) {
  heading.heading_confidence.value = HeadingConfidence::UNAVAILABLE;
  setHeadingValue(heading.heading_value, value);
}

/**
 * @brief Set the VehicleLengthValue object
 *
 * @param vehicle_length object to set
 * @param value VehicleLengthValue in meter as decimal number
 */
inline void setVehicleLengthValue(VehicleLengthValue& vehicle_length, const double value) {
  int64_t length = (int64_t)std::round(value*1e1);
  throwIfOutOfRange(length, VehicleLengthValue::MIN, VehicleLengthValue::MAX, "VehicleLengthValue");
  vehicle_length.value = length;
}

/**
 * @brief Set the VehicleLength object
 *
 * VehicleLengthConfidenceIndication is set to UNAVAILABLE
 *
 * @param vehicle_length object to set
 * @param value  VehicleLengthValue in meter as decimal number
 */
inline void setVehicleLength(VehicleLength& vehicle_length, const double value) {
  vehicle_length.vehicle_length_confidence_indication.value = VehicleLengthConfidenceIndication::UNAVAILABLE;
  setVehicleLengthValue(vehicle_length.vehicle_length_value, value);
}

/**
 * @brief Set the VehicleWidth object
 *
 * @param vehicle_width object to set
 * @param value VehicleWidth in meter as decimal number
 */
inline void setVehicleWidth(VehicleWidth& vehicle_width, const double value) {
  int64_t width = (int64_t)std::round(value*1e1);
  throwIfOutOfRange(width, VehicleWidth::MIN, VehicleWidth::MAX, "VehicleWidthValue");
  vehicle_width.value = width;
}

/**
 * @brief Set the SpeedValue object
 *
 * @param speed object to set
 * @param value SpeedValue in m/s as decimal number
 */
inline void setSpeedValue(SpeedValue& speed, const double value) {
  int64_t speed_val = (int64_t)std::round(value*1e2);
  throwIfOutOfRange(speed_val, SpeedValue::MIN, SpeedValue::MAX, "SpeedValue");
  speed.value = speed_val;
}

/**
 * @brief Set the Speed object
 *
 * SpeedConfidence is set to UNAVAILABLE
 *
 * @param speed object to set
 * @param value  Speed in in m/s as decimal number
 */
inline void setSpeed(Speed& speed, const double value) {
  speed.speed_confidence.value = SpeedConfidence::UNAVAILABLE;
  setSpeedValue(speed.speed_value, value);
}

/**
 * @brief Set a Bit String by a vector of bools
 *
 * @tparam T
 * @param bitstring BitString to set
 * @param bits vector of bools
 */
template <typename T>
inline void setBitString(T& bitstring, const std::vector<bool>& bits) {
  // bit string size
  const int bits_per_byte = 8;
  const int n_bytes = (bits.size() - 1) / bits_per_byte + 1;
  const int n_bits = n_bytes * bits_per_byte;

  // init output
  bitstring.bits_unused = n_bits - bits.size();
  bitstring.value = std::vector<uint8_t>(n_bytes);

  // loop over all bytes in reverse order
  for (int byte_idx = n_bytes - 1; byte_idx >= 0; byte_idx--) {

    // loop over bits in a byte
    for (int bit_idx_in_byte = 0; bit_idx_in_byte < bits_per_byte; bit_idx_in_byte++) {

      // map bit index in byte to bit index in total bitstring
      int bit_idx = (n_bytes - byte_idx - 1) * bits_per_byte + bit_idx_in_byte;
      if (byte_idx == 0 && bit_idx >= n_bits - bitstring.bits_unused) break;

      // set bit in output bitstring appropriately
      bitstring.value[byte_idx] |= bits[bit_idx] << bit_idx_in_byte;
    }
  }
}

/**
 * @brief Set the Acceleration Control by a vector of bools
 *
 * @param acceleration_control
 * @param bits
 */
inline void setAccelerationControl(AccelerationControl& acceleration_control, const std::vector<bool>& bits) {
  setBitString(acceleration_control, bits);
}

/**
 * @brief Set the Driving Lane Status by a vector of bools
 *
 * @param driving_lane_status
 * @param bits
 */
inline void setDrivingLaneStatus(DrivingLaneStatus& driving_lane_status, const std::vector<bool>& bits) {
  setBitString(driving_lane_status, bits);
}

/**
 * @brief Set the Exterior Lights by a vector of bools
 *
 * @param exterior_lights
 * @param bits
 */
inline void setExteriorLights(ExteriorLights& exterior_lights, const std::vector<bool>& bits) {
  setBitString(exterior_lights, bits);
}

/**
 * @brief Set the Special Transport Type by a vector of bools
 *
 * @param special_transport_type
 * @param bits
 */
inline void setSpecialTransportType(SpecialTransportType& special_transport_type, const std::vector<bool>& bits) {
  setBitString(special_transport_type, bits);
}

/**
 * @brief Set the Lightbar Siren In Use by a vector of bools
 *
 * @param light_bar_siren_in_use
 * @param bits
 */
inline void setLightBarSirenInUse(LightBarSirenInUse& light_bar_siren_in_use, const std::vector<bool>& bits) {
  setBitString(light_bar_siren_in_use, bits);
}

/**
 * @brief Set the Emergency Priority by a vector of bools
 *
 * @param emergency_priority
 * @param bits
 */
inline void setEmergencyPriority(EmergencyPriority& emergency_priority, const std::vector<bool>& bits) {
  setBitString(emergency_priority, bits);
}