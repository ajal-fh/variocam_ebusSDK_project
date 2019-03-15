#indicates the name of resulting workspace
cmake_minimum_required(VERSION 2.8.3)
project (vario_cam_ebus)

find_package(OpenCV REQUIRED)
find_package(Ebus REQUIRED)
#setting compiler and library support for ISO c++ 2011 standard
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")



#adding extra include directories

include_directories(/opt/pleora/ebus_sdk/Ubuntu-x86_64/include)
include_directories(/opt/pleora/ebus_sdk/Ubuntu-x86_64/share/samples)
include_directories( ${OpenCV_INCLUDE_DIRS})
#adding extra lib directories

link_directories(/opt/pleora/ebus_sdk/Ubuntu-x86_64/lib)

#adds an executable target to the build process (no ext_libraries here)
add_executable (vario_cam_ebus vario_cam_ebus.cpp)



#specify dependency on an extra library
find_library(JPEG jpeg)
target_link_libraries(vario_cam_ebus ${JPEG})
target_link_libraries(vario_cam_ebus ${OpenCV_LIBS})

target_link_libraries(vario_cam_ebus libPvBase.so libPvDevice.so libPvBuffer.so libPvGenICam.so libPvTransmitter.so libPvVirtualDevice.so libPvAppUtils.so libPvPersistence.so libPvSerial.so libPvStream.so)

