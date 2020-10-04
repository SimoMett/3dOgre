cmake_minimum_required(VERSION 3.13)
project(3dOgre)

set(CMAKE_CXX_STANDARD 14)

find_package(ZLIB REQUIRED)
find_package(SDL2 REQUIRED)
find_package(OGRE 1.12 REQUIRED COMPONENTS Bites RTShaderSystem)

add_executable(3dOgre main.cpp MainApp.h InputManager.h InputManager.cpp DFFObject.cpp DFFObject.h)

target_link_libraries(3dOgre OgreBites OgreRTShaderSystem OIS)