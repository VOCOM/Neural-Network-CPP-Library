project(src)

# Add test directory to build tree
add_subdirectory(Tests)

# Include Test source files
set(testFiles
    Tests/nodeTest.cpp
    Tests/layerTest.cpp
)

add_executable(RSE4207_AI_MODEL ${testFiles} main.cpp)