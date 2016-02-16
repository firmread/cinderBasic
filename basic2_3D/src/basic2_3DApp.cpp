#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class basic2_3DApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
};

void basic2_3DApp::setup()
{
}

void basic2_3DApp::mouseDown( MouseEvent event )
{
}

void basic2_3DApp::update()
{
}

void basic2_3DApp::draw()
{
	gl::clear();
    
    // 3D! NOPE not that easy...
    //    gl::drawCube(vec3(), vec3(2));
    
    
    /*
     // 1 - we need a camera!
    CameraPersp cam;
    cam.lookAt(vec3(3),vec3(0));
    gl::setMatrices(cam);
    
    gl::drawCube(vec3(), vec3(2));
    */
    
    
    //check out CameraPersp sample
    //    console() << gl::getProjectionMatrix() << std::endl;
    
    
    /*
     // 2 - lambert shading
     CameraPersp cam;
     cam.lookAt(vec3(3), vec3(0));
     gl::setMatrices(cam);
     
     auto lambert = gl::ShaderDef().lambert();
     auto shader = gl::getStockShader(lambert);
     shader->bind();
     gl::drawSphere(vec3(), 1.0f);
     
     */
    
    
    /*
     // 3 - z buffering & sphere subdivisions
    gl::enableDepthRead();
    gl::enableDepthWrite();
    
    CameraPersp cam;
    cam.lookAt(vec3(3), vec3(0));
    gl::setMatrices(cam);
    
    auto lambert = gl::ShaderDef().lambert();
    auto shader = gl::getStockShader(lambert);
    shader->bind();
    gl::drawSphere(vec3(), 1.0f, 40);
     */
    
    
    /*
     // 4 - 3d with matrix transformations
    gl::enableDepthRead();
    gl::enableDepthWrite();
    
    CameraPersp cam;
    cam.lookAt(vec3(5,2,5), vec3(0,1,0));
    gl::setMatrices(cam);
    
    auto lambert = gl::ShaderDef().lambert().color();
    auto shader = gl::getStockShader(lambert);
    shader->bind();
    
    int numSpheres = 64;
    float maxAngle = M_PI * 7;
    float spiralRadius = 1;
    float height = 3;
    
    for (int s = 0; s< numSpheres; ++s) {
        float rel = s / (float)numSpheres;
        float angle = rel * maxAngle;
        float y = rel * height;
        float r = rel * spiralRadius * spiralRadius;
        vec3 offset(r*cos(angle), y , r*sin(angle));
        
        gl::pushModelMatrix();
        gl::translate(offset);
        gl::color(Color(CM_HSV, rel , 1, 1));
        gl::drawSphere(vec3(), 0.1f, 30);
        gl::popModelMatrix();
    }
     
     */
    
    /*
    // 5 - anim from getElapsedFrames
    gl::enableDepthRead();
    gl::enableDepthWrite();
    
    CameraPersp cam;
    cam.lookAt(vec3(3,4.5,4.5), vec3(0,1,0));
    gl::setMatrices(cam);
    
    auto lambert = gl::ShaderDef().lambert().color();
    auto shader = gl::getStockShader(lambert);
    shader->bind();
    
    int numSpheres = 64;
    float maxAngle = M_PI * 7;
    float spiralRadius = 1;
    float height = 2;
    float anim = getElapsedFrames() / 30.0f;
    
    for (int s = 0; s<numSpheres; ++s) {
        float rel = s/(float)numSpheres;
        float angle = rel * maxAngle;
        float y = fabs(cos(rel*M_PI + anim))*height;
        float r = rel * spiralRadius;
        vec3 offset(r*cos(angle), y/2, r*sin(angle));
        
        gl::pushModelMatrix();
        gl::translate(offset);
        gl::scale(vec3(0.05f, y, 0.05f));
        gl::color(Color(CM_HSV, rel, 1, 1));
        gl::drawCube(vec3(), vec3(1));
        gl::popModelMatrix();
    }
     */
    
    
}

CINDER_APP( basic2_3DApp, RendererGl )
