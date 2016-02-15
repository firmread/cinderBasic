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
    
    // 5 - 3D! NOPE not that easy...
    //    gl::drawCube(vec3(), vec3(2));
    
    /*
     // we need a camera!
     CameraPersp cam;
     cam.lookAt(vec3(3),vec3(0));
     gl::setMatrices(cam);
     */
    
    //    gl::drawCube(vec3(), vec3(2));
    
    
    //check out CameraPersp sample
    //    console() << gl::getProjectionMatrix() << std::endl;
    
    /*
     
     CameraPersp cam;
     cam.lookAt(vec3(3), vec3(0));
     gl::setMatrices(cam);
     
     auto lambert = gl::ShaderDef().lambert();
     auto shader = gl::getStockShader(lambert);
     shader->bind();
     gl::drawSphere(vec3(), 1.0f);
     
     */
    
    gl::enableDepthRead();
    gl::enableDepthWrite();
    
    CameraPersp cam;
    cam.lookAt(vec3(3), vec3(0));
    gl::setMatrices(cam);
    
    auto lambert = gl::ShaderDef().lambert();
    auto shader = gl::getStockShader(lambert);
    shader->bind();
    gl::drawSphere(vec3(), 1.0f, 40);
}

CINDER_APP( basic2_3DApp, RendererGl )
