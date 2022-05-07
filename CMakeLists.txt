cmake_minimum_required(VERSION 3.7...3.23)

# if version is less than 3.12, set it policy to os version
if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

set(SOURCES
    src/util.cpp
    src/day_1.cpp
    src/day_2.cpp
    src/day_3.cpp
    src/day_4.cpp
    src/day_5/line.cpp
    src/day_5/day_5.cpp
    src/day_6.cpp
    src/day_7.cpp
    src/day_8.cpp
)

project(advent_of_code VERSION 1.0
                  DESCRIPTION "Advent of Code Coding Challenges"
                  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# add_library(solutions STATIC ${SOURCES} ${INCLUDES})
# target_include_directories(solutions PUBLIC include)
# add_library(day_1 STATIC src/day_1.cpp include/day_1.hpp)

# headers will be ignored, but can be added to make them show up in IDEs
add_executable(advent_of_code src/main.cpp ${SOURCES})
target_include_directories(advent_of_code PUBLIC include)

# target_link_libraries(advent_of_code PUBLIC solutions)
# target_link_libraries(one PUBLIC day_1)