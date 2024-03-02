
#compile with following cmake command
cmake -Bbuild -DCMAKE_BUILD_TYPE=Release

#Include following CmakeLists.txt file for opencv on cpp
cmake_minimum_required(VERSION 2.8)
project( ImageNegatives )
find_package(OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( ImageNegatives main.cpp )
target_link_libraries( ImageNegatives  ${OpenCV_LIBS})
