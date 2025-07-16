cmake_minimum_required(VERSION 3.15)
project (PrFinalED25 C)

# Set output directories for binaries and libraries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)

# Add source files
file(GLOB SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/modules/*.c
)

# Add executable
add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})

# Enable warnings
if (CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic)
endif()

# Include directories
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/src/modules
	${CMAKE_CURRENT_SOURCE_DIR}/src
	${CMAKE_CURRENT_SOURCE_DIR}/libs
)

#os
#se windows
if (WIN32)
	# Windows-specific settings
	target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE _WIN32)
else()
#se linux
	# Linux-specific settings
	target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE _LINUX)
endif()


# Link libraries (if any)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/libs/
)