cmake_minimum_required(VERSION 2.8)
project( AffineTransformations )
find_package(OpenCV REQUIRED)


include_directories( ${OpenCV_INCLUDE_DIRS} )

set(NETWORK_DIR , "/Users/mankulgupta/mankul/software/ImageProcessing/Network")

add_executable( AffineTransformations main.cpp )

target_include_directories(AffineTransformations PRIVATE 
    ${NETWORK_DIR}
    )

target_sources(AffineTransformations PRIVATE 
    ${NETWORK_DIR}"/network.cpp"
)

# include_directories("/Users/mankulgupta/mankul/software/ImageProcessing/Network")


# Network .hpp files;
# SET(
#     network.hpp
# )

# # Network .cpp files;
# SET(
#     network.cpp
# )



target_link_libraries( AffineTransformations  ${OpenCV_LIBS})
