cmake_minimum_required(VERSION 3.8)
project(jupiter VERSION 1.0.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

include_directories(AFTER SYSTEM /usr/local/include $ENV{HOME}/boost_1_73_0)
link_directories(/usr/local/lib $ENV{HOME}/boost_1_73_0/stage/lib)

add_subdirectory(base)
add_subdirectory(net)
