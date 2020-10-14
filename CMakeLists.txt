cmake_minimum_required(VERSION 3.5)
project(lunabotics2021)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

#set(phoenix_DIR "F:/dev/colcon_ws/src/lunabotics2021/include/ctre")

#////////////////////////////////////////////////////////////////
# STEP 1: ADD DEPENDENCIES///////////////////////////////////////
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
#find_package(phoenix REQUIRED)

include_directories(hello ${CMAKE_CURRENT_SOURCE_DIR}/lib/cpp/motorcontrol)
include_directories(hello ${CMAKE_CURRENT_SOURCE_DIR}/lib/cpp/motorcontrol/can)

# STEP 2: ADD EXECUTABLE AND AMENT DEPENDENCIES/////////////////

add_executable(hello src/hello.cpp)
ament_target_dependencies(hello rclcpp std_msgs)

add_executable(listen src/listen.cpp)
ament_target_dependencies(listen rclcpp std_msgs)

target_include_directories(hello PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE::include>)
  
target_include_directories(listen PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE::include>)

# STEP 3: ADD INSTALL///////////////////////////////////////////

install(TARGETS hello DESTINATION lib/${PROJECT_NAME})
install(TARGETS listen DESTINATION lib/${PROJECT_NAME})

#////////////////////////////////////////////////////////////////

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

target_link_libraries(hello ${CMAKE_SOURCE_DIR}/lib/api-cpp-5.18.3-windowsx86-64/windows/x86-64/shared/CTRE_Phoenix.lib)
#target_link_libraries(hello ${CMAKE_SOURCE_DIR}/lib/x86-64/libCTRE_PhoenixCanutils.a)
#target_link_libraries(hello ${CMAKE_SOURCE_DIR}/lib/x86-64/libCTRE_PhoenixCCI.a)
#starget_link_libraries(hello ${CMAKE_SOURCE_DIR}/lib/x86-64/libCTRE_PhoenixPlatformLinuxSocketCan.a)

ament_package()