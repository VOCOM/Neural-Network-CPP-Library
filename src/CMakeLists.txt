cmake_minimum_required(VERSION 3.16)
project(src)

# Add test directory to build tree
add_subdirectory(Tests)

# Include Test source files
set(testFiles
    Tests/testFunctions.cpp
    Tests/nodeTest.cpp
    Tests/layerTest.cpp
    Tests/nnTests.cpp
)

add_executable(RSE4207_AI_MODEL ${testFiles} main.cpp)