//
//  SceneApp.cpp
//  BasicTemplate
//
//  Created by Yi-Wen Lin on 2016/4/2.
//
//

#include "SceneApp.hpp"

#include "GlobalSettings.hpp"
void SceneApp::_initTextures() {
    cout << "Init textures" << endl;
    
    gl::Fbo::Format format;
    format.setColorInternalFormat(GL_RGBA32F_ARB);
    format.setMinFilter(GL_NEAREST);
    format.setMagFilter(GL_NEAREST);
    int size = GlobalSettings::getInstance().numParticles;
    
    _fboCurrPos = new Fbo(size, size, format);
    _fboNextPos = new Fbo(size, size, format);
    _fboCurrVel = new Fbo(size, size, format);
    _fboNextVel = new Fbo(size, size, format);
    _fboExtra   = new Fbo(size, size, format);
    
    _fboCurrPos->bindFramebuffer();
    gl::clear(ColorAf(0, 0, 0, 0));
    _fboCurrPos->unbindFramebuffer();
    
    _fboNextPos->bindFramebuffer();
    gl::clear(ColorAf(0, 0, 0, 0));
    _fboNextPos->unbindFramebuffer();
    
    _fboCurrVel->bindFramebuffer();
    gl::clear(ColorAf(0, 0, 0, 0));
    _fboCurrVel->unbindFramebuffer();
    
    _fboNextVel->bindFramebuffer();
    gl::clear(ColorAf(0, 0, 0, 0));
    _fboNextVel->unbindFramebuffer();

    _fboExtra->bindFramebuffer();
    gl::clear(ColorAf(0, 0, 0, 0));
    _fboExtra->unbindFramebuffer();

}

void SceneApp::_initViews() {
    cout << "Init views" << endl;
    
    _vAxis = new ViewAxis();
    _vDots = new ViewDotsPlane();
    
    _vTest = new ViewTest();
    _vSave = new ViewSave();
    _vCopy = new ViewCopy();
    _vRender    = new ViewRender();
    _vAddVel    = new ViewAddVel();
    _vSim       = new ViewSim();
    
    
    gl::setMatrices(*cameraOrtho);
    Area viewport = gl::getViewport();
    gl::setViewport(_fboCurrPos->getBounds());
    
    _fboCurrPos->bindFramebuffer();
    gl::clear(Color(0, 0, 0));
    _vSave->render();
    _fboCurrPos->unbindFramebuffer();
    
    _fboExtra->bindFramebuffer();
    gl::clear(Color(0, 0, 0));
    _vSave->renderExtra();
    _fboExtra->unbindFramebuffer();
    
    
    gl::setViewport(viewport);
    
    orbitalControl->rx->setValue(.3);
    orbitalControl->ry->setValue(1.3);
}

void SceneApp::render() {
    
    _vAxis->render();
    _vDots->render();
    
    
    Area viewport = gl::getViewport();
    gl::setViewport(_fboCurrPos->getBounds());
    
    _fboNextVel->bindFramebuffer();
    gl::clear(Color(0, 0, 0));
    _vSim->render(_fboCurrPos->getTexture(), _fboCurrVel->getTexture(), _fboExtra->getTexture());
    _fboNextVel->unbindFramebuffer();
    
    _fboNextPos->bindFramebuffer();
    gl::clear(Color(0, 0, 0));
    _vAddVel->render(_fboCurrPos->getTexture(), _fboNextVel->getTexture());
    _fboNextPos->unbindFramebuffer();
    
    
    gl::setViewport(viewport);
    _vRender->render(_fboCurrPos->getTexture(), _fboExtra->getTexture());
    
    
    int size = 256;
    
    Area bounds = gl::getViewport();
    gl::setViewport(Area(0, 0, size, size));
    _vCopy->render(_fboNextPos->getTexture());
    gl::setViewport(Area(size, 0, size, size));
    _vCopy->render(_fboNextVel->getTexture());
    gl::setViewport(bounds);
    
    
    swap(_fboCurrVel, _fboNextVel);
    swap(_fboCurrPos, _fboNextPos);
}