//
//  Engine.cpp
//  OpenGL
//
//  Created by Maxime Parriaux on 20/11/2017.
//
//

#include <iostream>
#include "Engine.hpp"

EngineParameter::EngineParameter(EngineParameter const * p) :
name(p->name), height(p->height), width(p->width) {

 }

Engine::Engine()  : parameters(&(const EngineParameter &)new EngineParameter()) {
    this->InitSDL();
    this->InitOpenGLContext();}

Engine::Engine(Engine const &e): parameters(e.parameters) {
    this->InitSDL();
    this->InitOpenGLContext();
 }

Engine::Engine(Engine  *e): parameters(e->parameters) {
    this->InitSDL();
    this->InitOpenGLContext();
 }

Engine::Engine(const EngineParameter& p) : parameters(p) {
        this->InitSDL();
        this->InitOpenGLContext();
}

void Engine::CrashEngine(std::string const &why) {
        std::cerr << why << SDL_GetError() << std::endl;
        this->killContext();
        SDL_Quit();
        exit(1);
}

void Engine::InitSDL() {
        if (SDL_Init(SDL_INIT_VIDEO) < 0)
                this->CrashEngine("Bad SDL_Init");
        else {
                this->window = SDL_CreateWindow(
                        this->parameters.name.c_str(),
                        SDL_WINDOWPOS_CENTERED,
                        SDL_WINDOWPOS_CENTERED,
                        this->parameters.width,
                        this->parameters.height,
                        SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL
                        );
                if (this->window == NULL)
                        this->CrashEngine("Bad window creation");
        }
}

void Engine::InitOpenGLContext()
{
        if (!this->window)
                this->CrashEngine("No window have been created");
        this->openGLContext = SDL_GL_CreateContext(this->window);
        if (!this->openGLContext) {
                this->CrashEngine("");
        }

        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
        glewInit();
        SDL_GL_SetSwapInterval(1);
        //Hack for win32
    #ifdef WIN32
        GLenum initialisationGLEW( glewInit() );
        if(initialisationGLEW != GLEW_OK)
        {
                std::cout << "Erreur d'initialisation de GLEW : " << glewGetErrorString(initialisationGLEW) << std::endl;
                this->CrashEngine("");
        }
    #endif
}


void Engine::Render() {
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_TRIANGLES);
        glColor3ub(255,0,0);    glVertex2d(-0.75,-0.75);
        glColor3ub(0,255,0);    glVertex2d(0,0.75);
        glColor3ub(0,0,255);    glVertex2d(0.75,-0.75);
        glEnd();
        glFlush();

        SDL_GL_SwapWindow(this->window);
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
            printf("Hello world\n");
                SDL_WaitEvent(this->event);
                switch(this->event->window.event)
                {
                case SDL_WINDOWEVENT_CLOSE:
                        this->running = false;
                        break;
                }
                this->Render();
        }
        this->CrashEngine("");
}

void Engine::killContext() {
        if (this->window)
                SDL_DestroyWindow(this->window);
        if (this->openGLContext)
                SDL_GL_DeleteContext(this->openGLContext);
}

Engine::~Engine() {
        this->killContext();
        SDL_Quit();
}
