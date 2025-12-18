cmake_minimum_required(VERSION 3.10)

project(2D_Animation LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    add_compile_options(/W4) # Dla Visual Studio
else()
    add_compile_options(-Wall -Wextra) # Dla GCC/Clang
endif()


#file(GLOB SRC "src/*.cpp")

set(SRC
    src/vector4.cpp
    src/shape.cpp
    src/renderer.cpp
    src/matrix4x4.cpp
)


add_executable(prog main.cpp ${SRC})
target_include_directories(prog PUBLIC ${CMAKE_SOURCE_DIR}/src)
