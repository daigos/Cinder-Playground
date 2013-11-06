#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class ResizeRespondApp : public AppNative {
public:
    void setup();
    void resize();
    void update();
    void draw();
    
    void setCornerRects();
    
    Rectf rect;
    Rectf rect_top_left;
    Rectf rect_top_right;
    Rectf rect_bottom_left;
    Rectf rect_bottom_right;

    float margin;
    float width, height;
};

void ResizeRespondApp::setup()
{
    margin = 20.0f;
    width = height = 50.0f;

    setCornerRects();
}

void ResizeRespondApp::setCornerRects()
{
    int x = getWindowSize().x;
    int y = getWindowSize().y;
    
    // x1, y1, x2, y2
    rect.set( margin, margin,
              x - margin, y - margin );
    
    rect_top_left.set( margin, margin, margin + width, margin + height );
    rect_top_right.set( x - margin - width, margin, x - margin, margin + height );
    rect_bottom_right.set( x - margin -width, y - margin - height, x - margin, y - margin );
    rect_bottom_left.set( margin, y - margin - height, margin + width, y - margin );
}

void ResizeRespondApp::resize()
{
    console() << "window size: " << getWindowSize() << endl;
    setCornerRects();
}

void ResizeRespondApp::update()
{
}

void ResizeRespondApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
    
    gl::color( 0.3f, 0.3f, 0.3f );
    gl::drawSolidRect( rect );
    
    gl::color( Color::white() );
    gl::drawSolidRect( rect_top_left );
    gl::drawSolidRect( rect_top_right );
    gl::drawSolidRect( rect_bottom_right );
    gl::drawSolidRect( rect_bottom_left );
}

CINDER_APP_NATIVE( ResizeRespondApp, RendererGl )
