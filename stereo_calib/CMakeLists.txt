cmake_minimum_required( VERSION 2.8 )
project( stereo_calib )

#编译选项为-Wall O3的优化,无论是release还是debug
#CMAKE_C_FLAGS原本为空
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}  -Wall  -O3 -march=native ")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall   -O3 -march=native")

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

# 寻找OpenCV库
find_package( OpenCV 3 REQUIRED PATHS /usr/local/opencv-3.4.5)
find_package(Boost REQUIRED COMPONENTS regex thread system filesystem)
add_definitions(-DBOOST_NO_CXX11_SCOPED_ENUMS)

# 添加头文件
include_directories(
        ${OpenCV_INCLUDE_DIRS}
        ${Boost_INCLUDE_DIRS}
        ${PROJECT_SOURCE_DIR}/include
)


add_library(mylib SHARED
        src/util.cpp
        )

target_link_libraries(mylib
        ${Boost_LIBRARIES}
        ${OpenCV_LIBS}
)

# 双目标定和双目矫正
add_executable( stereo_calib src/stereo_calib.cpp)
# 链接OpenCV库
target_link_libraries( stereo_calib mylib)


