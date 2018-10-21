cmake_minimum_required(VERSION 3.12)
project(server)

set(CMAKE_CXX_STANDARD 98)

add_executable(server server.cpp)

find_package(Boost 1.67.0 COMPONENTS system filesystem REQUIRED)
target_link_libraries(server ${Boost_LIBRARIES})
