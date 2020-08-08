cmake_minimum_required(VERSION 3.13...3.16 FATAL_ERROR)
project(thanote VERSION 0.0.1 LANGUAGES CXX)

# Use the package PkgConfig to detect GTK+ headers/library files
FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(GTK3 REQUIRED gtkmm-3.0)

# add all conan related libraries
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# Setup CMake to use GTK+, tell the compiler where to look for headers
# and to the linker where to look for libraries
INCLUDE_DIRECTORIES(${GTK3_INCLUDE_DIRS})
LINK_DIRECTORIES(${GTK3_LIBRARY_DIRS})

# Add other flags to the compiler
ADD_DEFINITIONS(${GTK3_CFLAGS_OTHER})

# add every needed sourcefile here
add_executable(thanote 	src/main.cpp 
						src/MainWindow.cpp
						src/plusone.cpp
						)

# this makes sure cmake choses the right cpp standard (ie c++11 or c++14 etc.) for details see here
# https://stackoverflow.com/questions/51463552/how-can-i-make-certain-c-features-required-in-my-cmake-project
target_compile_features(thanote PRIVATE cxx_auto_type
										cxx_std_17			# sol2 needs c++17
										)

# Bibliotheken linken
TARGET_LINK_LIBRARIES(thanote ${GTK3_LIBRARIES} ${CONAN_LIBS})


#------------------------------------------------------------------------------
# add testing
#------------------------------------------------------------------------------
ENABLE_TESTING()

add_executable(tests tests/plusone_test.cpp src/plusone.cpp)
TARGET_LINK_LIBRARIES(tests ${CONAN_LIBS})
# TARGET_LINK_LIBRARIES(test ${CONAN_LIBS_GTEST}) //todo herausfinden warum das nicht ausreicht
add_test(Tests bin/tests)