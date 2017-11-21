//
//  Scene.hpp
//  OpenGL
//
//  Created by Maxime Parriaux on 20/11/2017.
//
//

#ifndef Scene_hpp
#define Scene_hpp

#include "Engine.hpp"
#include <thread>
#include <stdio.h>
#include <string>


class Scene {
private:
    std::thread    engineThread;
    Engine         engine;

public:
    Scene();
    Scene(Engine const & e);
    ~Scene();
    void                RunEngine();
protected:

};


#endif /* Scene_hpp */
