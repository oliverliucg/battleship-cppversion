cmake_minimum_required(VERSION 3.20)
project(battleship_cppversion)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(battleship_cppversion "")
target_include_directories(battleship_cppversion PRIVATE Source)
add_subdirectory(Source)
#target_include_directories(battleship_cppversion PRIVATE Test)
#add_subdirectory(Test)
