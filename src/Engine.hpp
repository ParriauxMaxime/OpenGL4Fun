//
//  Engine.hpp
//  OpenGL
//
//  Created by Maxime Parriaux on 20/11/2017.
//
//

#ifndef Engine_hpp
#define Engine_hpp
#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>
#include <GL/glew.h>
#define GL3_PROTOTYPES 1

class EngineParameter
{
public:
    const std::string          name;
    unsigned int     height, width;
    EngineParameter(): name("Default Engine Name"), height(600), width(800) {}
    EngineParameter(std::string const & n, unsigned int w, unsigned int h): name(n), height(h), width(w) {}
    //EngineParameter(EngineParameter const & p);
     EngineParameter(EngineParameter const * p) ;
    ~EngineParameter() {}
};

class Engine {
private:
    EngineParameter const & parameters;
    SDL_Window*     window = NULL;
    SDL_Event*         event = NULL;
    SDL_GLContext   openGLContext;
    bool                    running;

    void                    Render();
    void                    InitSDL();
    void                    CrashEngine(std::string const &why);
    void                    InitOpenGLContext();
    void                    killContext();
public:
    Engine();
    Engine(EngineParameter const & p);
    Engine(Engine const &);
    Engine(Engine *);
    ~Engine();
    void                    run();
protected:
};


#endif /* Engine_hpp */
