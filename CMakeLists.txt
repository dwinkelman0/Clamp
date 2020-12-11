cmake_minimum_required (VERSION 3.10)
set (CMAKE_BUILD_TYPE Release)
set (CMAKE_CXX_STANDARD 11)
add_definitions(-DBOOST_NO_CXX11_SCOPED_ENUMS)

project (Clamp)
set (TargetName_Clamp clamp)
set (TargetName_Tests ${TargetName_Clamp}-tests)

include_directories("src")

file(GLOB CLAMP_SOURCES "src/*.cc")
add_library(${TargetName_Clamp} SHARED ${CLAMP_SOURCES})

find_package(Boost 1.65 COMPONENTS program_options REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
target_link_libraries(${TargetName_Clamp} LINK_PUBLIC ${Boost_LIBRARIES})

include(GoogleTest)
file(GLOB TESTS_SOURCES "tests/*.cc")
add_executable(${TargetName_Tests} ${TESTS_SOURCES})
target_link_libraries(${TargetName_Tests} ${TargetName_Clamp} gtest pthread)
