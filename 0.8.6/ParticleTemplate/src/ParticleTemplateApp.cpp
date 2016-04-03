#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "SceneApp.hpp"


using namespace ci;
using namespace ci::app;
using namespace std;

class ParticleTemplateApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
private:
    SceneApp*       _scene;
};

void ParticleTemplateApp::setup()
{
    setWindowPos(0, 0);
    setWindowSize(1280, 720);
    setFrameRate(60);
    gl::enableAlphaBlending();
    gl::enable(GL_CULL_FACE);
    gl::enable(GL_DEPTH_TEST);
    gl::enable(GL_VERTEX_PROGRAM_POINT_SIZE);
    
    _scene = new SceneApp();
}

void ParticleTemplateApp::mouseDown( MouseEvent event )
{
}

void ParticleTemplateApp::update()
{
}

void ParticleTemplateApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
    
    _scene->render();
}

CINDER_APP_NATIVE( ParticleTemplateApp, RendererGl )
