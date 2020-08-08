cmake_minimum_required(VERSION 2.8.3)
project(pcl_project)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O3")
set( CMAKE_BUILD_TYPE "Release" )

list( APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules )

find_package(PCL REQUIRED QUIET)
include_directories(
        ${PROJECT_SOURCE_DIR}
        "/usr/local/include/eigen3/"
        ${PROJECT_SOURCE_DIR}/include
        ${PCL_INCLUDE_DIRS}
)


add_executable(pcl_save pcl_save.cpp )
target_link_libraries( pcl_save ${PCL_LIBRARIES})

