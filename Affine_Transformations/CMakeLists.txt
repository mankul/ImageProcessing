cmake_minimum_required(VERSION 2.8)
project( AffineTransformations )
find_package(OpenCV REQUIRED)

find_package(CURL REQUIRED)

include_directories( ${OpenCV_INCLUDE_DIRS} )
include_directories( ${CURL_INCLUDE_DIR})

set(NETWORK_DIR , "/Users/mankulgupta/mankul/software/ImageProcessing/Network")

add_executable( AffineTransformations main.cpp )

target_include_directories(AffineTransformations PRIVATE 
    ${NETWORK_DIR}
    )

target_sources(AffineTransformations PRIVATE 
    "/Users/mankulgupta/mankul/software/ImageProcessing/Network/network.cpp"
    # ${NETWORK_DIR}/network.cpp
)


# message(${NETWORK_DIR}/network.cpp)
# message(${CURL_LIBRARIES})




target_link_libraries( AffineTransformations  ${OpenCV_LIBS})
target_link_libraries( AffineTransformations ${CURL_LIBRARIES})