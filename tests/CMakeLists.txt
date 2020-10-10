set (Boost_USE_STATIC_LIBS OFF)
find_package (Boost REQUIRED COMPONENTS unit_test_framework)
include_directories (${Boost_INCLUDE_DIRS})



add_executable (boost_test all_tests.cpp ../src/dff/DffObject.h ../src/dff/DffObject.cpp ../src/dff/Section.h ../src/dff/Section.cpp ../src/dff/Clump.h ../src/dff/Clump.cpp)
target_link_libraries (boost_test ${Boost_LIBRARIES})