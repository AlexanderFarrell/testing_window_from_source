cmake_minimum_required(VERSION 3.22)
project(gl_source)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(external/sdl2)
add_subdirectory(external/glm)

set (CMAKE_EXE_LINKER_FLAGS "-lGL" )
if (WIN32)
    add_subdirectory(external/glad)
elseif(APPLE)
    find_package(OpenGL REQUIRED)
elseif(LINUX)
endif()

include_directories(external/sdl2/include)

find_package(OpenGL REQUIRED)

add_executable(gl_source main.cpp)

if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()

target_link_libraries(${PROJECT_NAME}
        SDL2-static
        glm
        OpenGL::GL)

if (LINUX)
    target_link_libraries(${PROJECT_NAME}
        OpenGL::GL
    )
endif()