cmake_minimum_required(VERSION 3.10)

# Project name and version
project(PLAYER VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)

# Define the shared library (the .so file)
add_library(PLAYER SHARED
    src/Player.cpp        # Implementation of Player class
    src/Mp3AudioPlayer.cpp
    src/audiodriver/impl/LinuxAudioDriver.cpp
    src/Notification/PlatformNotification.cpp
    src/playerinterface/audioplayer/AudioPlayer.cpp
)

# Include directories
# We will expose the 'include' directory (and subdirectories) to the client
target_include_directories(PLAYER 
    PUBLIC
        ${CMAKE_SOURCE_DIR}/include    # Public headers are in 'include' directory
        ${CMAKE_SOURCE_DIR}/include/ui # UI-related headers (ButtonInterface.h, VerticalScrollBar.h)
    PRIVATE
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/src/audiodriver
        ${CMAKE_SOURCE_DIR}/src/audiodriver/impl
        ${CMAKE_SOURCE_DIR}/src/common
        ${CMAKE_SOURCE_DIR}/src/Notification
        ${CMAKE_SOURCE_DIR}/src/PlayBackStrategy
        ${CMAKE_SOURCE_DIR}/src/playerinterface
        ${CMAKE_SOURCE_DIR}/src/playerinterface/audioplayer
)

# Optional: Set output directories for the shared library
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

# Optional: Installation rules (if you plan to install)
install(TARGETS PLAYER DESTINATION /usr/local/lib)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/ DESTINATION /usr/local/include)

# Enable testing
enable_testing()

# Add a test executable
add_executable(PlayerTest test/PlayerTest.cpp)

# Link the PLAYER library to the test executable
target_link_libraries(PlayerTest PRIVATE PLAYER)

# Add the test to CTest (to be run via ctest)
add_test(NAME PlayerTest COMMAND PlayerTest)

# Optional: Set output directories for test builds
set(TEST_OUTPUT_PATH ${CMAKE_BINARY_DIR}/test_output)
set_target_properties(PlayerTest PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${TEST_OUTPUT_PATH})

