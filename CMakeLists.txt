cmake_minimum_required(VERSION 3.5)

project(
    EuropeanVanillaOptions
    VERSION 0.1
    DESCRIPTION "European Vanilla Call and Put Options"
    LANGUAGES CXX)

#set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE HEADERS "src/*.hpp")
file(GLOB_RECURSE SOURCES "src/*.cpp")

# -O3: max speed optimization
# -ffast-math: math optimization, again for speed
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall -O3 -ffast-math")

add_executable(main src/main.cpp)
