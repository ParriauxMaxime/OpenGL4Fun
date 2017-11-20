//
//  Engine.cpp
//  OpenGL
//
//  Created by Maxime Parriaux on 20/11/2017.
//
//

#include <iostream>
#include "Engine.hpp"

Engine::Engine() : window(NULL), event(NULL), running(false) {
        this->InitSDL();
}

void Engine::CrashEngine(std::string const &why) {
        std::cerr << why << SDL_GetError() << std::endl;
        if (!this->window)
                SDL_DestroyWindow(this->window);
        SDL_Quit();
        exit(1);
}

void Engine::InitSDL() {
        if (SDL_Init(SDL_INIT_VIDEO) < 0)
                this->CrashEngine("Bad SDL_Init");
        else {
                this->window = SDL_CreateWindow(
                        "Test SDL 2.0",
                        SDL_WINDOWPOS_CENTERED,
                        SDL_WINDOWPOS_CENTERED,
                        800,
                        600,
                        SDL_WINDOW_SHOWN
                        );
                if (this->window == NULL)
                        this->CrashEngine("Bad window creation");
        }
}

void Engine::run() {
        if (this->running)
                return;
        if (!this->window)
                this->InitSDL();
        if (!this->event)
                this->event = new SDL_Event();
        this->running = true;
        while (this->running)
        {
                SDL_WaitEvent(this->event);
                switch(this->event->window.event)
                {
                case SDL_WINDOWEVENT_CLOSE:
                        this->running = false;
                        break;
                }
        }
        this->CrashEngine("");
}

Engine::~Engine() {
        if (this->window)
                SDL_DestroyWindow(this->window);
        SDL_Quit();
}
