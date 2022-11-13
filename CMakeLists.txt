cmake_minimum_required(VERSION 3.23)
project(gl_source)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(external/sdl2)
add_subdirectory(external/glm)

if (WIN32)
    add_subdirectory(external/glad)
elseif(APPLE)
    find_package(OpenGL REQUIRED)
endif()

include_directories(external/sdl2/include)

add_executable(gl_source main.cpp)

if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()

target_link_libraries(${PROJECT_NAME}
        SDL2-static
        glm)