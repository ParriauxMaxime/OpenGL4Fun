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

class Engine {
private:
    SDL_Window*     window;
    SDL_Event*           event;
    bool                    running;


    void                    InitSDL();
    void                    CrashEngine(std::string const &why);
    bool                    InitSDLContext();
public:
    Engine();
    void run();
    ~Engine();
protected:
};


#endif /* Engine_hpp */
