cmake_minimum_required(VERSION 3.3)

project(sorters CXX)
add_executable(main main.cpp base.cpp bitonic.cpp bubble.cpp comb.cpp heap.cpp quick.cpp)
set_property( DIRECTORY PROPERTY VS_STARTUP_PROJECT "main" )
