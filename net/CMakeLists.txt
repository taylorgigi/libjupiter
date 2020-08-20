cmake_minimum_required(VERSION 3.8)
project(net VERSION 1.0.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

add_library(net SHARED Channel.cpp EPoller.cpp EventLoop.cpp Poller.cpp)
target_link_libraries(net base pthread)
