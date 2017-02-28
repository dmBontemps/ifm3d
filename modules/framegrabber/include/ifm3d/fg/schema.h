// -*- c++ -*-
/*
 * Copyright (C) 2017 Love Park Robotics, LLC
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distribted on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __IFM3D_FG_SCHEMA_H__
#define __IFM3D_FG_SCHEMA_H__

#include <cstdint>
#include <string>

namespace ifm3d
{
  extern const std::uint16_t DEFAULT_SCHEMA_MASK;

  // Constants used to create "pluggable schema masks"
  extern const std::uint16_t IMG_RDIS; // radial distance
  extern const std::uint16_t IMG_AMP;  // normalized amplitude
  extern const std::uint16_t IMG_RAMP; // raw amplitude
  extern const std::uint16_t IMG_CART; // Cartesian
  extern const std::uint16_t IMG_UVEC; // Unit vectors
  extern const std::uint16_t EXP_TIME; // Exposure times
  extern const std::uint16_t IMG_GRAY; // Grayscale (ambient light)

  /**
   * Utility function to build an image acquisition result schema from a mask.
   *
   * @param[in] mask The mask to use to build the schema
   * @return A json-string encoding the schema
   */
  std::string make_schema(std::uint16_t mask);

  /**
   * Utility function to create a schema mask from a string.
   *
   * The passed in string should contain valid symbolic constants `OR'd`
   * together. For example: IMG_RDIS|IMG_AMP|IMG_RAMP|IMG_CART|IMG_UVEC
   *
   * @param[in] in The string to parse to generate the mask
   * @return The schema encoded by the `in` string.
   */
  std::uint16_t schema_mask_from_string(const std::string& in);

} // end: namespace ifm3d

#endif // __IFM3D_FG_SCHEMA_H__