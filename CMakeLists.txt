cmake_minimum_required(VERSION 3.8)
project(BoostCMakeDemo LANGUAGES CXX)

#========================================================
# Note: this would normally be part of my toolchain file

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRE True)

if(MSVC)
	add_compile_options( /permissive-)
	add_definitions( -DBOOST_ALL_NO_LIB )
else()
	add_compile_options( $<$<CONFIG:Debug>:-fsanitize=undefined> )
	set(CMAKE_EXE_LINKER_FLAGS_DEBUG ${CMAKE_EXE_LINKER_FLAGS} -fsanitize=undefined)
endif()

#========================================================

add_subdirectory(libs/boost)

add_executable(boost_demo main.cpp)

#find_package(Boost REQUIRED COMPONENTS system)

target_link_libraries(boost_demo Boost::system)

