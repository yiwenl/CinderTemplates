//
//  Scene.cpp
//  BasicTemplate
//
//  Created by Yi-Wen Lin on 2016/4/1.
//
//

#include "Scene.hpp"

using namespace bongiovi;

Scene::Scene() {
    _init();
}


void Scene::_init() {
    //  window
    app::WindowRef window = getWindow();
    
    //  loop bind
    mCbUpdate       = window->getSignalDraw().connect( std::bind(&Scene::_loop, this));
    
    //  camera
    camera = new CameraPersp();
    camera->setPerspective(120, getWindowAspectRatio(), .1, 100);
    cameraOrtho = new CameraOrtho();
    cameraOrtho->setOrtho( -1, 1, 1, -1, -1, 1 );
    
    _initTextures();
    _initViews();
    
}


void Scene::_initTextures() {
    cout << " Init Textures " << endl;
}


void Scene::_initViews() {
    cout << " Init Views " << endl;
}



void Scene::_loop() {
    cout << " looping" << endl;
    update();
    render();
}


void Scene::update() {
    gl::setMatrices(*camera);
    
}


void Scene::render() {
    
}