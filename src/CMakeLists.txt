##################################################################
#                      Project Info Header                       #
##################################################################
set(presets_rplidar_connection "/dev/ttyUSB0" CACHE STRING "Serial connection to rplidar.")
set(presets_rplidar_baud_rate "115200" CACHE STRING "Baud rate of rplidar serial connection.")
configure_file(common/project_info.hpp.in ${CMAKE_CURRENT_SOURCE_DIR}/common/project_info.hpp @ONLY)

##################################################################
#                         RPlidar Example                        #
##################################################################
add_executable(ExampleRPlidar examples/rplidar.cpp)
target_link_libraries(ExampleRPlidar PRIVATE RPlidar)
target_include_directories(ExampleRPlidar PRIVATE common)
