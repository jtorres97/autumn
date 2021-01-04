cmake_minimum_required(VERSION 3.14)
project(Autumn CXX)

include("${CMAKE_BINARY_DIR}/conanbuildinfo.cmake")
conan_basic_setup()

file(GLOB_RECURSE AUTUMN_SRC "${CMAKE_SOURCE_DIR}/src/*.h" "${CMAKE_SOURCE_DIR}/src/*.cpp")

add_executable("${PROJECT_NAME}" "${AUTUMN_SRC}")
set_property(TARGET "${PROJECT_NAME}" PROPERTY CXX_STANDARD 17)

target_include_directories("${PROJECT_NAME}" PRIVATE "${CMAKE_SOURCE_DIR}/src/Autumn")
target_include_directories("${PROJECT_NAME}" PRIVATE "${CMAKE_SOURCE_DIR}/src/Sandbox")
target_include_directories("${PROJECT_NAME}" PRIVATE "${CMAKE_SOURCE_DIR}/src/Vendor")

if (MSVC)
    message("DETECTED MSVC COMPILER")
    add_compile_options(/permissive- /W4 /w14640)
elseif()
    add_compile_options(-Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic)
endif()

# Find OpenGL
find_package(OpenGL)

set_target_properties("${PROJECT_NAME}" PROPERTIES LINK_FLAGS ${CONAN_EXE_LINKER_FLAGS})
target_link_libraries("${PROJECT_NAME}" PRIVATE ${CONAN_LIBS} OpenGL::GL) 