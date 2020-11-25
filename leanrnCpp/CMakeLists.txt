cmake_minimum_required(VERSION 3.10.2)
project(learncpp)

set(CMAKE_CXX_STANDARD 11)
#编译选项为-Wall O3的优化,无论是release还是debug
#CMAKE_C_FLAGS原本为空
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}  -Wall  -O0 -march=native ")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall   -O0 -march=native")

# Check C++11 or C++0x support,如果支持则进行编译
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
    add_definitions(-DCOMPILEDWITHC11)
    message(STATUS "Using flag -std=c++11." ${CMAKE_CXX_FLAGS})
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
    add_definitions(-DCOMPILEDWITHC0X)
    message(STATUS "Using flag -std=c++0x.")
else()
    message(FATAL_ERROR "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

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
        src/classSelf.cpp
        )
target_link_libraries(mylib
        ${Boost_LIBRARIES})

add_executable(thread thread.cpp)
target_link_libraries(thread  mylib)

add_executable(class class.cpp)
target_link_libraries(class  mylib)

add_executable(rwBin rwBin.cpp)
target_link_libraries(rwBin  mylib)