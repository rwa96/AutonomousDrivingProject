find_package(Threads REQUIRED)

configure_file(RPLidar_CMakeLists.txt.in rplidar/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G ${CMAKE_GENERATOR} .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${PROJECT_BINARY_DIR}/rplidar
)
if(result)
    message(FATAL_ERROR "CMake step for rplidar failed: ${result}")
endif()

execute_process(COMMAND ${CMAKE_COMMAND} --build .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${PROJECT_BINARY_DIR}/rplidar
)
if(result)
    message(FATAL_ERROR "Build step for rplidar failed: ${result}")
endif()


add_library(RPlidar STATIC IMPORTED)
set_property(TARGET RPlidar PROPERTY IMPORTED_LOCATION ${PROJECT_BINARY_DIR}/rplidar/src/RPLidar/sdk/output/Linux/Release/librplidar_sdk.a)
set_property(TARGET RPlidar APPEND PROPERTY INTERFACE_INCLUDE_DIRECTORIES
    $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/rplidar/src/RPLidar/sdk/sdk/include>
    $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/rplidar/src/RPLidar/sdk/sdk/src>
)
set_property(TARGET RPlidar APPEND PROPERTY INTERFACE_LINK_LIBRARIES
    $<BUILD_INTERFACE:Threads::Threads>
)