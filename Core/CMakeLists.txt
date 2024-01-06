cmake_minimum_required(VERSION 3.26)

project(Core VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# add_library(${PROJECT_NAME} SHARED "")
add_executable(${PROJECT_NAME} "")

target_sources(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/src/main.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME} Architecture)


set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 20)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD_REQUIRED ON)
set_target_properties(${PROJECT_NAME} PROPERTIES MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")






