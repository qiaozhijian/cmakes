cmake_minimum_required(VERSION 3.10.2)
project(renameImage)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenCV 3.0 QUIET)
if(NOT OpenCV_FOUND)
    find_package(OpenCV 2.4.3 QUIET)
    if(NOT OpenCV_FOUND)
        message(FATAL_ERROR "OpenCV > 2.4.3 not found.")
    endif()
endif()

find_package(Eigen3 3.1.0 REQUIRED)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
find_package(Boost REQUIRED COMPONENTS regex thread system filesystem)
add_definitions(-DBOOST_NO_CXX11_SCOPED_ENUMS)

include_directories(
        ${PROJECT_SOURCE_DIR}
        ${PROJECT_SOURCE_DIR}/include
        ${EIGEN3_INCLUDE_DIR}
        ${Boost_INCLUDE_DIRS}
        "/usr/include "
)

add_library(mylib SHARED
        src/util.cpp
        )
target_link_libraries(mylib
        ${Boost_LIBRARIES})

add_executable(renameImage main.cpp)
target_link_libraries(renameImage  mylib)