# For clang complete:
# CXX="~/.vim/bundle/clang_complete/bin/cc_args.py g++" cmake ..
# and/or
# cmake-gui -> cmake export compile commands

PROJECT(Project01)
CMAKE_MINIMUM_REQUIRED( VERSION 2.8)

SET( CMAKE_MODULE_PATH  "${CMAKE_CURRENT_SOURCE_DIR}/CMakeModules/")

FIND_PACKAGE( GLM REQUIRED)
FIND_PACKAGE( PkgConfig)
PKG_CHECK_MODULES(SDL2 REQUIRED sdl2)
PKG_CHECK_MODULES(SDL2_ttf REQUIRED SDL2_ttf)

INCLUDE_DIRECTORIES( ${SDL2_INCLUDE_DIRS})
INCLUDE_DIRECTORIES( ${SDL2_ttf__INCLUDE_DIRS})
INCLUDE_DIRECTORIES( ${GLM_INCLUDE_DIRS})

SET ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -pedantic -g3 -ggdb3")

SET( SOURCE_FILES
	main.cpp
	source/window.cpp
	source/simple_block.cpp
	source/game.cpp
)

INCLUDE_DIRECTORIES( include)
SET( HEADER_FILES
	include/window.h
	include/entity.h
	include/simple_block.h
	include/game.h
)

ADD_EXECUTABLE(Project01 ${SOURCE_FILES})
TARGET_LINK_LIBRARIES(Project01 ${SDL2_LIBRARIES} ${SDL2_ttf_LIBRARIES})

ADD_SUBDIRECTORY(font)
