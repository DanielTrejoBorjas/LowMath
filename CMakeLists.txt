cmake_minimum_required(VERSION 3.31)
project(LowMath VERSION 1.0 LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 20)

option(LOWMATH_BUILD_SHARED "Build LowMath as a shared library" OFF)
option(LOWMATH_TEST "Build LowMath test executable" OFF)

if(LOWMATH_BUILD_SHARED)
    set(LIB_TYPE SHARED)
else()
    set(LIB_TYPE STATIC)
endif()

add_library(LowMath ${LIB_TYPE}
        source/vector/Vector2.cpp
        source/vector/Vector3.cpp
        source/vector/Vector4.cpp

        source/matrix/Matrix2x2.cpp
        source/matrix/Matrix3x3.cpp
        source/matrix/Matrix4x4.cpp

        source/quaternion/Quaternion.cpp
)

target_include_directories(LowMath PUBLIC include)

message(STATUS "LowMath: Building as ${LIB_TYPE} library")

if(LOWMATH_TEST)
    add_executable(LowMathTest main.cpp)
    target_link_libraries(LowMathTest PRIVATE LowMath)
    message(STATUS "LowMath: Test executable enabled")
endif()
