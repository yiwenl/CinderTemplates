#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Camera.h"
#include "bongiovi/Scene.hpp"
#include "bongiovi/ViewAxis.hpp"
#include "bongiovi/ViewDotsPlane.hpp"
#include "bongiovi/ViewBall.hpp"
#include "bongiovi/OrbitalControl.hpp"
#include "ViewTest.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;
using namespace bongiovi;

class BasicTemplateApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
    CameraPersp* camera;
    
    private:
    float time = 0.0f;
    Scene* _scene;
    ViewAxis* _vAxis;
    ViewDotsPlane* _vDotsPlane;
    ViewBall*   _vBall;
    ViewTest*   _vTest;
};

void BasicTemplateApp::setup()
{
//    _scene = new Scene();
    
    setWindowPos(0, 0);
    setWindowSize(1280, 720);
    setFrameRate(60);
    gl::enableAlphaBlending();
    gl::enable(GL_CULL_FACE);
    gl::enable(GL_DEPTH_TEST);
    
    camera = new CameraPersp();
    camera->setPerspective(90, getWindowAspectRatio(), .25, 500);
    
    new OrbitalControl(camera);
    
    _vAxis = new ViewAxis();
    _vDotsPlane = new ViewDotsPlane();
    _vBall = new ViewBall();
    
    _vTest = new ViewTest();
}

void BasicTemplateApp::mouseDown( MouseEvent event )
{
}

void BasicTemplateApp::update()
{
}

void BasicTemplateApp::draw()
{
	// clear out the window with black
    time += 0.05;
	gl::clear( Color( 0, 0, 0 ) );
    gl::setMatrices(*camera);
    _vAxis->render();
    _vDotsPlane->render();
    
    _vBall->position.x = cos(time) * 2;
    _vBall->position.z = sin(time) * 2;
    
    float scale = cos(time*0.5) * .5 + .5;
    scale = .1 + scale * .2;
    _vBall->scale.set(scale, scale, scale);
    
    _vTest->render();
    _vBall->render();
}

CINDER_APP_NATIVE( BasicTemplateApp, RendererGl )
