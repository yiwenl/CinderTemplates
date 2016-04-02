#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "SceneApp.hpp"

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
    
    private:
    SceneApp*       _scene;
};

void BasicTemplateApp::setup()
{
    setWindowPos(0, 0);
    setWindowSize(1280, 720);
    setFrameRate(60);
    gl::enableAlphaBlending();
    gl::enable(GL_CULL_FACE);
    gl::enable(GL_DEPTH_TEST);
    
    _scene = new SceneApp();
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
    _scene->render();
}

CINDER_APP_NATIVE( BasicTemplateApp, RendererGl )
