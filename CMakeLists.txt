cmake_minimum_required(VERSION 3.26)
project(intrusive-list)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(${PROJECT_NAME} src/main.cpp src/intrusive_list.hpp src/point_list.hpp)