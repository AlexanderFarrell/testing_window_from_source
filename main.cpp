#include <iostream>

// MAC
//#include <OpenGL/gl3.h>

// LINUX
//#include "gl/gl.h"
#include <GL/gl.h>

//#include <glad/glad.h>
#include <SDL.h>
#include <glm/glm.hpp>

int main() {
    int width = 1280;
    int height = 720;

    int window_flags = SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout
                << "Couldn't initialize SDL: "
                << SDL_GetError()
                << std::endl;
        exit(1);
    }


    SDL_Window* window = SDL_CreateWindow(
            "Hello",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            width,
            height,
            window_flags
            );

    if (!window) {
        std::cout << "Failed to open window: \n"  << SDL_GetError();
        exit(1);
    }

    bool running = true;

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
                        SDL_GL_CONTEXT_PROFILE_CORE);
    auto gl = SDL_GL_CreateContext(window);

    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    running = false;
                    break;
            }
        }
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glFlush();
        SDL_GL_SwapWindow(window);
    }
    SDL_GL_DeleteContext(gl);

    SDL_DestroyWindow(window);
    SDL_Quit();
}
