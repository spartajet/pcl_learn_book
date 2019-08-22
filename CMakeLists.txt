cmake_minimum_required(VERSION 3.12)
project(pcl_learn_book)

set(CMAKE_CXX_STANDARD 17)

# PCL
find_package(PCL 1.9.1 REQUIRED)
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

#armadillo
set(ARMADILLO_INCLUDE_DIRS "E:/Librarys/armadillo-9.400.4/include")
set(ARMADILLO_LIBRARIES "E:/Librarys/armadillo-9.400.4/libs")

include_directories(${ARMADILLO_INCLUDE_DIRS})
link_directories(${ARMADILLO_LIBRARIES})


# 编译器设置
add_definitions(-D_CRT_SECURE_NO_WARNINGS)



add_executable(pcl_learn_book main.cpp)
target_link_libraries (pcl_learn_book ${PCL_LIBRARIES})
target_link_libraries(pcl_learn_book blas_win64_MT lapack_win64_MT)

add_subdirectory(charpter2)
add_subdirectory(pcd)
