cmake_minimum_required(VERSION 3.27.7)

project(Architecture VERSION 1.0)

set(LIBRARY_NAME ${PROJECT_NAME})


add_library(${LIBRARY_NAME} "")
target_sources(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/src/main.cpp)



target_include_directories(${LIBRARY_NAME} PRIVATE 
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/${LIBRARY_NAME}>
$<INSTALL_INTERFACE:include/${LIBRARY_NAME}>)

target_include_directories(${LIBRARY_NAME} PUBLIC 
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
$<INSTALL_INTERFACE:include)

set(CMAKE_CXX_FLAGS "/std:c++latest ${CMAKE_CXX_FLAGS}")







