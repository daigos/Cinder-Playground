#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "cinder/PolyLine.h"
#include <map>

using namespace ci;
using namespace ci::app;
using namespace std;

class TouchInputApp : public AppNative {
public:
    void setup();
    void update();
    void draw();
    
    void touchesBegan( TouchEvent ev );
    void touchesMoved( TouchEvent ev );
    void touchesEnded( TouchEvent ev );
    
    map<uint32_t, PolyLine<Vec2f>> lines;   // idと位置座標のペア
    
    typedef vector<TouchEvent::Touch> touch_vector;
    typedef map<uint32_t, PolyLine<Vec2f>> touch_map;
};

void TouchInputApp::setup()
{
}

void TouchInputApp::touchesBegan( TouchEvent ev )
{
    const touch_vector& touches = ev.getTouches();
    for( touch_vector::const_iterator iter = touches.begin(); iter != touches.end(); ++iter) {
        const TouchEvent::Touch& touch = *iter;
        
        lines[ touch.getId() ] = PolyLine<Vec2f>();
    }
}

void TouchInputApp::touchesMoved( TouchEvent ev )
{
    const touch_vector& touches = ev.getTouches();
    for( touch_vector::const_iterator iter = touches.begin(); iter != touches.end(); ++iter) {
        const TouchEvent::Touch& touch = *iter;
        
        lines[ touch.getId() ].push_back( touch.getPos() );
    }
}

void TouchInputApp::touchesEnded( TouchEvent ev )
{
    const touch_vector& touches = ev.getTouches();
    for( touch_vector::const_iterator iter = touches.begin(); iter != touches.end(); ++iter) {
        const TouchEvent::Touch& touch = *iter;
        
        lines.erase( touch.getId() );
    }
}

void TouchInputApp::update()
{
}

void TouchInputApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
    
    gl::color( Color::white() );
    for( touch_map::iterator iter = lines.begin(); iter != lines.end(); ++iter ) {
        gl::draw( iter->second );
    }
    
    const touch_vector& activeTouch = getActiveTouches();
    gl::color( Color( 1.0f, 0.0f, 0.0f ) );
    for( touch_vector::const_iterator iter = activeTouch.begin(); iter!= activeTouch.end(); ++iter ) {
        const TouchEvent::Touch& touch = *iter;
        gl::drawSolidCircle( touch.getPos(), 10.0f );
    }
}

CINDER_APP_NATIVE( TouchInputApp, RendererGl )
