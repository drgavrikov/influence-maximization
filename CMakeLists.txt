cmake_minimum_required(VERSION 3.23.2)

project(influence-maximization CXX)

# Set C++ standard and compiler flags
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON) # Ensure the C++20 standard is mandatory
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wconversion -Wpedantic")

##############################################
# Set project directories and source files

# Define the include directory for header files
set(PROJECT_INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Define the source directory for implementation files
set(PROJECT_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Collect all .cpp files from the source directory
file(GLOB_RECURSE PROJECT_SOURCES ${PROJECT_SRC_DIR}/*.cpp)

# Throw an error if no source files are found
if(NOT PROJECT_SOURCES)
    message(FATAL_ERROR "No source files found in ${PROJECT_SRC_DIR}")
endif()

# Add the executable target and include directories
add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_INC_DIR})

##############################################
# Find and link with required libraries

# Locate Boost libraries
find_package(Boost REQUIRED COMPONENTS program_options serialization)

# Link Boost libraries if found
if(Boost_FOUND)
    message(STATUS "Boost found: ${Boost_INCLUDE_DIRS}")
    target_include_directories(${PROJECT_NAME} PRIVATE ${Boost_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME} PRIVATE Boost::program_options Boost::serialization)
else()
    # Terminate if Boost is not available
    message(FATAL_ERROR "Boost libraries not found. Ensure Boost is installed and components are specified correctly.")
endif()

##############################################
# Installation instructions

# Define installation paths for runtime and libraries
install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static)

# Install header files to the include directory
install(DIRECTORY ${PROJECT_INC_DIR} DESTINATION include)
