cmake_minimum_required (VERSION 2.6)

project (schunk_sdh_control_interface)

find_package(libntcan)
find_package(libpcan)
set(sdh_package_path /home/shehzad/rosws/hydro/robocuphome_ws/src/schunk_modular_robotics/schunk_sdh)

###########
## Build ##
###########
if(“${CMAKE_SYSTEM_PROCESSOR}” STREQUAL “x86_64”)
  message(STATUS "++++++++++++++++++++++++++ DETECTED 64 bit +++++++++++++++++++++++++++++++++++")
  set(MYARCH "x86_64")
else(“${CMAKE_SYSTEM_PROCESSOR}” STREQUAL “x86_64”)
  message(STATUS "++++++++++++++++++++++++++ DETECTED 32 bit +++++++++++++++++++++++++++++++++++")
  set(MYARCH "i686")
endif(“${CMAKE_SYSTEM_PROCESSOR}” STREQUAL “x86_64”)
    
message(${sdh_package_path})

add_custom_target(
    copy_SDHLIB ALL 
    COMMAND /bin/ln -sf ${sdh_package_path}/common/lib/${MYARCH}/libSDHLibrary-CPP.so ${sdh_package_path}/common/lib/libSDHLibrary-CPP.so
    DEPENDS ${sdh_package_path}/common/lib/${MYARCH}/libSDHLibrary-CPP.so
    )


include_directories(${sdh_package_path}/common/include ${Boost_INCLUDE_DIRS}  ${libntcan_INCLUDE_DIRS} ${libpcan_INCLUDE_DIRS} )

add_library(SDHLibrary SHARED IMPORTED )
add_dependencies(SDHLibrary copy_SDHLIB)
set_property(TARGET SDHLibrary PROPERTY IMPORTED_LOCATION ${sdh_package_path}/common/lib/libSDHLibrary-CPP.so)

add_executable(${PROJECT_NAME} cpp/src/schunk_sdh_control_interface.cpp)
set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS "-DOSNAME_LINUX -DWITH_ESD_CAN")
add_dependencies(${PROJECT_NAME} ${PROJECT_NAME}_gencpp)
target_link_libraries(${PROJECT_NAME} SDHLibrary ${libntcan_LIBRARIES} ${libpcan_LIBRARIES})