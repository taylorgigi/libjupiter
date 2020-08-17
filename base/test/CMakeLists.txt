cmake_minimum_required(VERSION 3.8)
project(test VERSION 1.0.0.0 LANGUAGES CXX)

SET(CMAKE_CXX_COMPILER "g++")
SET(CMAKE_CXX_FLAGS "-g -Wall -O0")
include_directories(AFTER SYSTEM /usr/local/include $ENV{HOME}/boost_1_73_0)
link_directories(/usr/local/lib $ENV{HOME}/boost_1_73_0/stage/lib)

add_executable(stopwatch-test stopwatch-test.cpp)
target_link_libraries(stopwatch-test base pthread)

add_executable(count_down_latch-test count_down_latch-test.cpp)
target_link_libraries(count_down_latch-test base pthread)

add_executable(thread_pool-test thread_pool-test.cpp)
target_link_libraries(thread_pool-test base pthread)
