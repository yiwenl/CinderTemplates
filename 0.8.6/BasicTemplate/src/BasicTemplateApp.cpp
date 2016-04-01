#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "bongiovi/Scene.hpp"
#include "bongiovi/ViewAxis.hpp"
#include "cinder/Camera.h"

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
};

void BasicTemplateApp::setup()
{
//    _scene = new Scene();
    
    setWindowPos(0, 0);
    setWindowSize(1280, 720);
    setFrameRate(60);
    
    camera = new CameraPersp();
    camera->setPerspective(90, getWindowAspectRatio(), 1, 500);
    
    camera->lookAt(Vec3f(0.0, 0.0, -5.0), Vec3f(0.0, 0.0, 0.0));
    
    _vAxis = new ViewAxis();
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
    
    
    time += 0.01;
    float r = 5.0;
    float x = cos(time) * r;
    float z = sin(time) * r;
    camera->lookAt(Vec3f(x, 1.0, z), Vec3f(0.0, 0.0, 0.0));
    
    
    _vAxis->render();
}

CINDER_APP_NATIVE( BasicTemplateApp, RendererGl )
