project(Project01)
CMAKE_MINIMUM_REQUIRED( VERSION 2.8)

SET( CMAKE_MODULE_PATH  "${CMAKE_CURRENT_SOURCE_DIR}/CMakeModules/")

FIND_PACKAGE( GLM REQUIRED)
FIND_PACKAGE( PkgConfig)
PKG_CHECK_MODULES(SDL2 REQUIRED sdl2)

INCLUDE_DIRECTORIES( ${SDL2_INCLUDE_DIRS})
INCLUDE_DIRECTORIES( ${GLM_INCLUDE_DIRS})

SET ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -pedantic -g3 -ggdb3")

set( SOURCE_FILES
	main.cpp
	source/window.cpp
)

include_directories( include)
SET( HEADER_FILES
	include/window.h
)

add_executable(Project01 ${SOURCE_FILES})
target_link_libraries(Project01 ${SDL2_LIBRARIES})
