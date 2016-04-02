#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Camera.h"
#include "bongiovi/Scene.hpp"
#include "bongiovi/ViewAxis.hpp"
#include "bongiovi/ViewDotsPlane.hpp"
#include "bongiovi/OrbitalControl.hpp"

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
};

void BasicTemplateApp::setup()
{
//    _scene = new Scene();
    
    setWindowPos(0, 0);
    setWindowSize(1280, 720);
    setFrameRate(60);
    gl::enableAlphaBlending();
    
    camera = new CameraPersp();
    camera->setPerspective(90, getWindowAspectRatio(), .25, 500);
    
    new OrbitalControl(camera);
    
//    camera->lookAt(Vec3f(0.0, 0.0, -5.0), Vec3f(0.0, 0.0, 0.0));
    
    
    
    _vAxis = new ViewAxis();
    _vDotsPlane = new ViewDotsPlane();
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
	gl::clear( Color( 0, 0, 0 ) );
    gl::setMatrices(*camera);
    _vAxis->render();
    _vDotsPlane->render();
}

CINDER_APP_NATIVE( BasicTemplateApp, RendererGl )
