cmake_minimum_required(VERSION 3.20)
project(weave)

include(cmake/CompileOptions.cmake)
include(cmake/Sanitizers.cmake)
include(cmake/PrintSystemInfo.cmake)

add_subdirectory(weave)
