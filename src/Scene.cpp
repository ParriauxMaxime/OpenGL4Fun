//
//  Scene.cpp
//  OpenGL
//
//  Created by Maxime Parriaux on 20/11/2017.
//
//

#include "Scene.hpp"

Scene::Scene(Engine const & e): engine(e)  {

}
Scene::Scene(): engine(new Engine())  {
}

Scene::~Scene() {
}

void Scene::RunEngine() {
    this->engine.run();
}
