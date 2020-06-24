cmake_minimum_required( VERSION 2.8 )
project( imageBasics )

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}  -Wall  -O3 -march=native ")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall   -O3 -march=native")

# Check C++11 or C++0x support
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
    add_definitions(-DCOMPILEDWITHC11)
    message(STATUS "Using flag -std=c++11.")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
    add_definitions(-DCOMPILEDWITHC0X)
    message(STATUS "Using flag -std=c++0x.")
else()
    message(FATAL_ERROR "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()


# 添加c++ 11标准支持
set( CMAKE_CXX_FLAGS "-std=c++11" )


# 寻找OpenCV库
find_package( OpenCV 3 REQUIRED PATHS /usr/local/opencv-3.4.5)
# 添加头文件
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable( stereo_vo stereo_vo.cpp )
# 链接OpenCV库
target_link_libraries( stereo_vo ${OpenCV_LIBS} )

add_executable( stereo_cali stereo_cali.cpp )
# 链接OpenCV库
target_link_libraries( stereo_cali ${OpenCV_LIBS} )
