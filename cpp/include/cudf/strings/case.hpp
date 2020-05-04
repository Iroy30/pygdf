/*
 * Copyright (c) 2019, NVIDIA CORPORATION.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once

#include <cudf/column/column.hpp>
#include <cudf/strings/strings_column_view.hpp>

namespace cudf {
namespace strings {
/**
 * @brief Convert upper/lower case of strings columns
 * @ingroup strings_apis
 * @addtogroup strings_case Case
 * @{
 */

/**
 * @brief Converts a column of strings to lower case.
 *
 * Only upper case alphabetical characters are converted. All other characters are copied.
 * Case conversion may result in strings that are longer or shorter than the
 * original string in bytes.
 *
 * Any null entries create null entries in the output column.
 *
 * @param strings Strings instance for this operation.
 * @param mr Resource for allocating device memory.
 * @return New column of strings with characters converted.
 */
std::unique_ptr<column> to_lower(
  strings_column_view const& strings,
  rmm::mr::device_memory_resource* mr = rmm::mr::get_default_resource());

/**
 * @brief Converts a column of strings to upper case.
 *
 * Only lower case alphabetical characters are converted. All other characters are copied.
 * Case conversion may result in strings that are longer or shorter than the
 * original string in bytes.
 *
 * Any null entries create null entries in the output column.
 *
 * @param strings Strings instance for this operation.
 * @param mr Resource for allocating device memory.
 * @return New column of strings with characters converted.
 */
std::unique_ptr<column> to_upper(
  strings_column_view const& strings,
  rmm::mr::device_memory_resource* mr = rmm::mr::get_default_resource());

/**
 * @brief Returns a column of strings converting lower case characters to
 * upper case and vice versa.
 *
 * Only upper or lower case alphabetical characters are converted. All other characters are copied.
 * Case conversion may result in strings that are longer or shorter than the
 * original string in bytes.
 *
 * Any null entries create null entries in the output column.
 *
 * @param strings Strings instance for this operation.
 * @param mr Resource for allocating device memory.
 * @return New column of strings with characters converted.
 */
std::unique_ptr<column> swapcase(
  strings_column_view const& strings,
  rmm::mr::device_memory_resource* mr = rmm::mr::get_default_resource());

/** @} */  // end of doxygen group
}  // namespace strings
}  // namespace cudf
