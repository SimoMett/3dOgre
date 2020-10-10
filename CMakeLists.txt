cmake_minimum_required(VERSION 3.13)
project(3dOgre)

set(CMAKE_CXX_STANDARD 14)

find_package(ZLIB REQUIRED)
find_package(SDL2 REQUIRED)
find_package(OGRE 1.12 REQUIRED COMPONENTS Bites RTShaderSystem)

add_executable(3dOgre src/main.cpp src/MainApp.h src/InputManager.h src/InputManager.cpp src/dff/DffObject.cpp src/dff/DffObject.h src/dff/Section.cpp src/dff/Section.h src/dff/Clump.cpp src/dff/Clump.h src/dff/GeometryList.cpp src/dff/GeometryList.h src/dff/Geometry.cpp src/dff/Geometry.h src/dff/FrameList.cpp src/dff/FrameList.h src/dff/Atomic.cpp src/dff/Atomic.h src/dff/Material.cpp src/dff/Material.h src/dff/Texture.cpp src/dff/Texture.h src/dff_nodes/DffRoot.cpp src/dff_nodes/DffRoot.h src/dff_nodes/SectionNode.cpp src/dff_nodes/SectionNode.h)

target_link_libraries(3dOgre OgreBites OgreRTShaderSystem OIS)

add_subdirectory(tests)