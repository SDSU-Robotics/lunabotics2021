# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_lunabotics2021_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED lunabotics2021_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(lunabotics2021_FOUND FALSE)
  elseif(NOT lunabotics2021_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(lunabotics2021_FOUND FALSE)
  endif()
  return()
endif()
set(_lunabotics2021_CONFIG_INCLUDED TRUE)

# output package information
if(NOT lunabotics2021_FIND_QUIETLY)
  message(STATUS "Found lunabotics2021: 0.0.0 (${lunabotics2021_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'lunabotics2021' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${lunabotics2021_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(lunabotics2021_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${lunabotics2021_DIR}/${_extra}")
endforeach()
