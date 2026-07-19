cmake_minimum_required(VERSION 3.16)
project(Pengionia CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build." FORCE)
endif()

# Configure Raylib build options
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES OFF CACHE BOOL "" FORCE)

include(FetchContent)
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG        6.0
    GIT_SHALLOW    TRUE
)
FetchContent_MakeAvailable(raylib)

set(PROJECT_SOURCES
    src/main.cpp
    src/game_loop.cpp
    src/init_engine.cpp
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE include)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

# Compiler options
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
elseif(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
endif()

# Enable Link Time Optimization (LTO) for Release builds
include(CheckIPOSupported)
check_ipo_supported(RESULT lto_supported)
if(lto_supported AND CMAKE_BUILD_TYPE STREQUAL "Release")
    set_property(TARGET ${PROJECT_NAME} PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)
endif()

# Platform specific configurations
if(EMSCRIPTEN)
    set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".html")
    target_compile_definitions(${PROJECT_NAME} PRIVATE PLATFORM_WEB)
    
    # Preload the assets directory for the web virtual filesystem
    target_link_options(${PROJECT_NAME} PRIVATE
        "-s" "USE_GLFW=3"
        "-s" "FORCE_FILESYSTEM=1"
        "-s" "ALLOW_MEMORY_GROWTH=1"
        "--preload-file" "${CMAKE_CURRENT_SOURCE_DIR}/assets@assets"
    )
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        target_link_options(${PROJECT_NAME} PRIVATE "-s" "ASSERTIONS=1")
    endif()
else()
    # Copy assets to the build directory for desktop runtime
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_CURRENT_SOURCE_DIR}/assets"
        "$<TARGET_FILE_DIR:${PROJECT_NAME}>/assets"
    )
endif()