#https://github.com/dmonopoly/gtest-cmake-example/blob/master/CMakeLists.txt
cmake_minimum_required(VERSION 2.8)

# Options. Turn on with 'cmake -Dmyvarname=ON'.
option(test "Build all tests." OFF) # Makes boolean 'test' available.

# Make PROJECT_SOURCE_DIR, PROJECT_BINARY_DIR, and PROJECT_NAME available.
set(PROJECT_NAME GameTest)
project(${PROJECT_NAME})

set(EXECUTABLE_NAME "GameTest")

set(CMAKE_CXX_FLAGS "-g -Wall --std=gnu++14")

set( CMAKE_EXPORT_COMPILE_COMMANDS 1 )

# If you want your own include/ directory, set this, and then you can do
# include_directories(${COMMON_INCLUDES}) in other CMakeLists.txt files.
# set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/include)

################################
# Normal Libraries & Executables
################################
#add_library(text-query-system_lib Line.cpp Word.cpp Paragraph.cpp)
add_executable(${EXECUTABLE_NAME} main.cpp Game.cpp GameWorldScreen.cpp Laser.cpp Player.cpp)
#target_link_libraries(GameTest text-query-system_lib)
# Key idea: SEPARATE OUT your main() function into its own file so it can be its
# own executable. Separating out main() means you can add this library to be
# used elsewhere.

################################
# SFML
################################
#add_subdirectory(../SFML-2.3.1 ${CMAKE_CURRENT_BINARY_DIR}/SFML)
#include_directories(${SFML_INCLUDE_DIR})
#target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
set(SFML_ROOT "${CMAKE_SOURCE_DIR}/../SFML-2.3.1/")
## Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/../SFML-2.3.1/cmake/Modules" ${CMAKE_MODULE_PATH})
##Find any version 2.X of SFML
##See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
  message(${SFML_LIBRARIES})
endif()


################################
# Testing
################################
if (test)
  # This adds another subdirectory, which has 'project(gtest)'.
  add_subdirectory(../../googletest ${CMAKE_CURRENT_BINARY_DIR}/googletest)

  enable_testing()
  set(CTEST_OUTPUT_ON_FAILURE 1)

  # Include the gtest library. gtest_SOURCE_DIR is available due to
  # 'project(gtest)' above.
  include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

  ##############
  # Unit Tests
  ##############
  add_executable(runUnitTests TextQueryTests.cpp FileReader.cpp)

  # Standard linking to gtest stuff.
  target_link_libraries(runUnitTests gtest gtest_main)

  # Extra linking for the project.
  target_link_libraries(runUnitTests text-query-system_lib)

  # This is so you can do 'make test' to see all your tests run, instead of
  # manually running the executable runUnitTests to see those specific tests.
  add_test(NAME that-test-I-made COMMAND runUnitTests)

  # You can also omit NAME and COMMAND. The second argument could be some other
  # test executable.
  add_test(that-other-test-I-made runUnitTests --gtest_color=yes)

  add_custom_target(t COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure)
endif()
