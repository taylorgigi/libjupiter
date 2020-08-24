cmake_minimum_required(VERSION 3.8)
project(base VERSION 1.0.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

include_directories(AFTER SYSTEM /usr/local/include $ENV{HOME}/boost_1_73_0)
link_directories(/usr/local/lib $ENV{HOME}/boost_1_73_0/stage/lib)

add_library(base SHARED Mutex.cpp Condition.cpp Thread.cpp CountDownLatch.cpp ThreadPool.cpp Logger.cpp)
target_link_libraries(base boost_filesystem pthread)

add_subdirectory(test)
