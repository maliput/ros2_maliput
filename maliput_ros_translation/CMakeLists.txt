##############################################################################
# Project
##############################################################################

cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(maliput_ros_translation LANGUAGES C CXX VERSION 0.1.0)

##############################################################################
# Find 3rd Party Packages
##############################################################################

message(STATUS "\n\n====== Finding 3rd Party Packages ======\n")

find_package(ament_cmake REQUIRED)
find_package(builtin_interfaces REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(maliput REQUIRED)
find_package(maliput_ros_interfaces REQUIRED)

##############################################################################
# Project Configuration
##############################################################################

message(STATUS "\n\n========= Project Configuration ========\n")

set(BUILD_SHARED_LIBS true)

include(${PROJECT_SOURCE_DIR}/cmake/DefaultCFlags.cmake)
include(${PROJECT_SOURCE_DIR}/cmake/SanitizersConfig.cmake)

ament_environment_hooks(
  "${ament_cmake_package_templates_ENVIRONMENT_HOOK_LIBRARY_PATH}"
)

##############################################################################
# Docs
##############################################################################

if(BUILD_DOCS)
  message(STATUS "Doxygen generation - Enabled")
  find_package(ament_cmake_doxygen REQUIRED)
    ament_doxygen_generate(doxygen_maliput_ros_translation
      CONFIG_OVERLAY doc/Doxyfile.overlay.in
      TEST_ON_WARNS
    )
  add_definitions(-DBUILD_DOCS)
else()
  message(STATUS "Doxygen generation - Disabled")
endif()

##############################################################################
# Sources
##############################################################################
add_subdirectory(src)

##############################################################################
# Tests
##############################################################################

if(BUILD_TESTING)
  find_package(ament_cmake_clang_format REQUIRED)
  enable_testing()
  add_subdirectory(test)
  ament_clang_format(CONFIG_FILE ${CMAKE_CURRENT_SOURCE_DIR}/.clang-format)
endif()

##############################################################################
# Export
##############################################################################

install(
  DIRECTORY include/
  DESTINATION include
)

ament_export_include_directories(include)

ament_environment_hooks(setup.sh.in)
ament_export_dependencies(ament_cmake)
ament_export_dependencies(builtin_interfaces)
ament_export_dependencies(geometry_msgs)
ament_export_dependencies(maliput)
ament_export_dependencies(maliput_ros_interfaces)
ament_export_targets(${PROJECT_NAME}-targets HAS_LIBRARY_TARGET)
ament_package()
