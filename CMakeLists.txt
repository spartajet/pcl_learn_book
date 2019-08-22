cmake_minimum_required(VERSION 3.12)
project(pcl_learn_book)

set(CMAKE_CXX_STANDARD 17)
find_package(PCL 1.9.1 REQUIRED)
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_definitions(-D_CRT_SECURE_NO_WARNINGS)

add_executable(pcl_learn_book main.cpp)
target_link_libraries (pcl_learn_book ${PCL_LIBRARIES})
add_subdirectory(charpter2)
