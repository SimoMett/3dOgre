cmake_minimum_required(VERSION 3.13)
project(3dOgre)

set(CMAKE_CXX_STANDARD 14)

find_package(ZLIB REQUIRED)
find_package(SDL2 REQUIRED)
find_package(OGRE 1.12 REQUIRED COMPONENTS Bites RTShaderSystem)

add_executable(3dOgre src/main.cpp src/MainApp.h src/InputManager.h src/InputManager.cpp dff/DffObject.cpp dff/DffObject.h dff/DffSection.cpp dff/DffSection.h tests/all_tests.cpp)

target_link_libraries(3dOgre OgreBites OgreRTShaderSystem OIS)

add_subdirectory(tests)