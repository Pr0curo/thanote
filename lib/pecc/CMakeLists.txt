cmake_minimum_required(VERSION 3.12.4...3.16 FATAL_ERROR)
project(libpecc VERSION 0.0.1 LANGUAGES CXX)

add_library(pecc ${CMAKE_CURRENT_SOURCE_DIR}/src/pecc.cpp)


# interne header im src verzeichnis, externe header im 'include' verzeichnis

target_include_directories(pecc 
    PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

ADD_EXECUTABLE(pecc_lib_tests 	tests/pecc_tests.cpp )
TARGET_LINK_LIBRARIES(pecc_lib_tests  pecc)

