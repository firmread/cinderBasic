#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class basic1_2DApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
};

void basic1_2DApp::setup()
{
}

void basic1_2DApp::mouseDown( MouseEvent event )
{
}

void basic1_2DApp::update()
{
}

void basic1_2DApp::draw()
{
    
    gl::clear();
    // 0 - start drawing
        gl::drawSolidCircle(getWindowCenter(), 200);
    
    /*
     // 1 - draw more
     vec2 center = getWindowCenter();
     float r = 100;
     
     gl::color(1,0,0);
     gl::drawSolidCircle(center + vec2(-r,r), r);
     gl::color(0,1,0);
     gl::drawSolidCircle(center + vec2(r,r), r);
     gl::color(0,0,1);
     gl::drawSolidCircle(center + vec2(0,-.73*r), r);
     */
    
    /*
     // 2 - translate & setMatricesWindow
     gl::setMatricesWindow(getWindowSize());
     
     gl::translate(getWindowCenter().x, 75);
     gl::color(1, 0, 0);
     gl::drawSolidCircle(vec2(0), 70);
     
     gl::translate(0,150);
     gl::color(1, 1, 0);
     gl::drawSolidCircle(vec2(0), 70);
     
     gl::translate(0,150);
     gl::color(0, 1, 0);
     gl::drawSolidCircle(vec2(0), 70);
     */
    
    /*
     // 3 - push/pop model matrix
     gl::pushModelMatrix();
     gl::translate(getWindowCenter());
     
     int numCircles = 16;
     float radius = getWindowHeight() /2 - 30;
     
     for (int c = 0; c<numCircles; ++c) {
     float rel = c / (float)numCircles;
     float angle = rel * M_PI * 2;
     vec2 offset(cos(angle), sin(angle));
     
     gl::pushModelMatrix();
     gl::translate(offset*radius);
     gl::color(Color(CM_HSV, rel, 1, 1));
     gl::drawStrokedCircle(vec2(), 30);
     gl::popModelMatrix();
     }
     
     gl::color(1, 1, 1);
     gl::drawSolidCircle(vec2(), 15);
     gl::popModelMatrix();
     */
    
    /*
     // 4 - more matrix manipulation, rotate&scale
     gl::pushModelMatrix();
     gl::translate(getWindowCenter());
     
     int numCircles = 32;
     float radius = getWindowHeight() /2 -30;
     
     for (int c = 0; c< numCircles; ++c) {
     float rel = c / (float)numCircles;
     float angle = rel * M_PI * 2;
     vec2 offset(cos(angle), sin(angle));
     
     gl::pushModelMatrix();
     gl::translate(offset*radius);
     gl::rotate(angle);
     gl::scale(8,0.25f);
     gl::color(Color(CM_HSV, rel, 1,1));
     gl::drawSolidCircle(vec2(), 20);
     gl::popModelMatrix();
     }
     
     gl::popModelMatrix();
     
     */
    
    /* 4.5 - just switch rotate&scale lines
     gl::pushModelMatrix();
     gl::translate(getWindowCenter());
     
     int numCircles = 32;
     float radius = getWindowHeight() /2 -30;
     
     for (int c = 0; c< numCircles; ++c) {
     float rel = c / (float)numCircles;
     float angle = rel * M_PI * 2;
     vec2 offset(cos(angle), sin(angle));
     
     gl::pushModelMatrix();
     gl::translate(offset*radius);
     gl::scale(8,0.25f);
     gl::rotate(angle);
     gl::color(Color(CM_HSV, rel, 1,1));
     gl::drawSolidCircle(vec2(), 20);
     gl::popModelMatrix();
     }
     
     gl::popModelMatrix();
     */

}

CINDER_APP( basic1_2DApp, RendererGl )
