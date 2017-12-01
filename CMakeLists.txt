cmake_minimum_required(VERSION 3.8)
project(Tyrannosaurus-R)
if (NOT WIN32)
    set (CMAKE_CXX_FLAGS "-Wall -Wextra -Werror")
endif (NOT WIN32)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
FILE(GLOB SOURCES_FILES src/*.cpp)
FILE(GLOB INCLUDE_FILES include/*.hpp)
INCLUDE_DIRECTORIES("include")

add_executable(pbrain-Tyrannosaurus-R ${INCLUDE_FILES} ${SOURCES_FILES})
