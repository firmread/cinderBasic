#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class basic3_batchApp : public App {
  public:
	void setup() override;
	void draw() override;

    CameraPersp mCam;
    gl::BatchRef mBox;
};

void basic3_batchApp::setup()
{
    auto lambert = gl::ShaderDef().lambert().color();
    gl::GlslProgRef shader = gl::getStockShader(lambert);
    mBox = gl::Batch::create(geom::Cube(), shader);
    
    mCam.lookAt(vec3(3,4.5,4.5), vec3(0,1,0));
}


void basic3_batchApp::draw()
{
	gl::clear();
    gl::enableDepthRead();
    gl::enableDepthWrite();
    
    gl::setMatrices(mCam);
    
    int numSpheres = 64;
    float maxAngle = M_PI * 7;
    float spiralRadius = 1;
    float height = 2;
    float boxSize = 0.05f;
    float anim = getElapsedFrames() / 60.0f;
    
    for (int s = 0; s<numSpheres; ++s) {
        float rel = s/(float)numSpheres;
        float angle = rel * maxAngle;
        float y = fabs(cos(rel*M_PI*anim))*height;
        float r = rel * spiralRadius;
        vec3 offset(r*cos(angle), y/2, r*sin(angle));
        
        gl::pushModelMatrix();
        gl::translate(offset);
        gl::scale(vec3(boxSize, y, boxSize));
        gl::color(Color(CM_HSV, rel, 1, 1));
        mBox->draw();
        gl::popModelMatrix();
    }
}

CINDER_APP( basic3_batchApp, RendererGl )
