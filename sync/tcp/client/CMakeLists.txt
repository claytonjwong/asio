cmake_minimum_required(VERSION 3.12)

project(client)

set(CMAKE_CXX_STANDARD 98)

add_executable(client client.cpp)

find_package(Boost 1.67.0 COMPONENTS system filesystem REQUIRED)
target_link_libraries(client ${Boost_LIBRARIES})
