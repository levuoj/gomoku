cmake_minimum_required(VERSION 3.8)
project(Tyranosaurus_R)
if (NOT WIN32)
    set (CMAKE_CXX_FLAGS "-Wall -Wextra -Werror")
endif (NOT WIN32)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(SOURCES_FILES src/main.cpp)

include_directories("./include")

add_executable(Tyranosaurus_R ${SOURCES_FILES})