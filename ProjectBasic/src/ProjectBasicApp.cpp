#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class ProjectBasicApp : public AppNative {
public:
    void prepareSettings( Settings *settings );
    void setup();
    void update();
    void draw();
};

void ProjectBasicApp::prepareSettings( Settings *settings )
{
    settings->setWindowSize( 1024, 768 );
    settings->setFrameRate( 60.0f );
}

void ProjectBasicApp::setup()
{
    
}

void ProjectBasicApp::update()
{
}

void ProjectBasicApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_NATIVE( ProjectBasicApp, RendererGl )
