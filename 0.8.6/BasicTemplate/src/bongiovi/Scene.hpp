//
//  Scene.hpp
//  BasicTemplate
//
//  Created by Yi-Wen Lin on 2016/4/1.
//
//

#ifndef Scene_hpp
#define Scene_hpp

#include <stdio.h>
#include "cinder/App/App.h"
#include "cinder/Camera.h"
#include "OrbitalControl.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;


namespace bongiovi {
    class Scene {
        public:
        
        Scene() {
            _init();
        }
        
        CameraPersp* camera;
        CameraOrtho* cameraOrtho;
        OrbitalControl* orbitalControl;
        void    render();
        void    update() {
            gl::setMatrices(*camera);
        }
        
        private:
        
        void    _init() {
            //  window
            app::WindowRef window = getWindow();
            
            //  loop bind
            mCbUpdate       = window->getSignalDraw().connect( std::bind(&Scene::_loop, this));
            
            //  camera
            camera = new CameraPersp();
            camera->setPerspective(120, getWindowAspectRatio(), .1, 100);
            cameraOrtho = new CameraOrtho();
            cameraOrtho->setOrtho( -1, 1, 1, -1, -1, 1 );
            
            orbitalControl = new OrbitalControl(camera);
        }
        
        void    _loop() {
            update();
        }
        
        signals::scoped_connection mCbUpdate;
    };
}

#endif /* Scene_hpp */
