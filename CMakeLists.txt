cmake_minimum_required(VERSION 4.0.1)

project(Tenis)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
             PROPERTY VS_STARTUP_PROJECT Tenis)

add_executable(Tenis src/main.cpp
					 src/Game.cpp
					 src/Display.cpp
					 src/ARacket.cpp
					 src/HRacket.cpp
					 src/VRacket.cpp

					 include/Game.h
					 include/Display.h
					 include/ARacket.h 
				     include/HRacket.h
					 include/VRacket.h
					 include/Coord.h)