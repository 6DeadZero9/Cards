cmake_minimum_required(VERSION 3.16)

project(Cards)

set(INCLUDE_DIR "inc")
set(SRC_DIR "src")

set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_FLAGS "-g")

file(GLOB ALL_SRC
        "${PROJECT_SOURCE_DIR}/inc/*.hpp"
        "${PROJECT_SOURCE_DIR}/src/*.cpp"
        )

add_executable(${PROJECT_NAME} ${ALL_SRC})

