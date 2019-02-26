cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(visualization)

find_package(PCL 1.2 REQUIRED)
find_package(Boost 1.40 REQUIRED)

include_directories(${PCL_INCLUDE_DIRS})
include_directories(${Boost_INCLUDE_DIRS})

link_directories(${PCL_LIBRARY_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

add_definitions(${PCL_DEFINITIONS})
add_definitions(${Boost_DEFINITIONS})

add_executable (visualize_mesh src/visualize_mesh.cpp)

target_link_libraries (visualize_mesh ${PCL_LIBRARIES})
target_link_libraries (visualize_mesh ${Boost_LIBRARIES})
