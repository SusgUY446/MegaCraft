cmake_minimum_required(VERSION 3.20)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

project(MegaCraft)

# Set the binary output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c")
list(APPEND MY_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/glad/src/glad.c")

add_executable("${CMAKE_PROJECT_NAME}")

set_property(TARGET "${CMAKE_PROJECT_NAME}" PROPERTY C_STANDARD 99)

target_sources("${CMAKE_PROJECT_NAME}" PRIVATE ${MY_SOURCES})

find_package(glfw3 REQUIRED)

target_include_directories("${CMAKE_PROJECT_NAME}" 
    PUBLIC 
    "include/"
    "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/glad/include"  
)

target_link_libraries("${CMAKE_PROJECT_NAME}" PRIVATE glfw)

find_package(OpenGL REQUIRED)
target_link_libraries("${CMAKE_PROJECT_NAME}" PRIVATE OpenGL::GL)
