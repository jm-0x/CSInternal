cmake_minimum_required(VERSION 3.26)

project(Architecture VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(${PROJECT_NAME} STATIC "")
target_sources(${PROJECT_NAME} PRIVATE  "src/GUI.cpp")

find_package(PolyHook_2 CONFIG REQUIRED)


target_include_directories(${PROJECT_NAME} PRIVATE 
$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include/${PROJECT_NAME}>
$<INSTALL_INTERFACE:include/${PROJECT_NAME}>)

target_include_directories(${PROJECT_NAME} PUBLIC 
$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include/>
$<INSTALL_INTERFACE:include>)

target_link_libraries(${PROJECT_NAME} PUBLIC PolyHook_2::PolyHook_2)

set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 20)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD_REQUIRED ON)
set_target_properties(${PROJECT_NAME} PROPERTIES MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")









