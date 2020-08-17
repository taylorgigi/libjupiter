cmake_minimum_required(VERSION 3.8)
project(base VERSION 1.0.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_library(base SHARED Mutex.cpp Condition.cpp Thread.cpp CountDownLatch.cpp)
target_link_libraries(base pthread)

add_subdirectory(test)
