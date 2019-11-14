cmake_minimum_required(VERSION 3.14)
project(CollisionBasedPiCalculator)

set(CMAKE_CXX_STANDARD 14)

add_executable(CollisionBasedPiCalculator main.cpp block.h)

set(OpenCV_DIR)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(CollisionBasedPiCalculator ${OpenCV_LIBS})