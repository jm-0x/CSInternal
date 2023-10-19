cmake_minimum_required(VERSION 3.27.7)

project(Core VERSION 1.0)

add_library(${PROJECT_NAME} SHARED "")


target_sources(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME} Architecture)
set(CMAKE_CXX_FLAGS "/std:c++latest ${CMAKE_CXX_FLAGS}")







