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

using namespace ci;
using namespace ci::app;
using namespace std;


namespace bongiovi {
    class Scene {
        public:
        
        Scene();
        
        void    update();
        void    render();
        CameraPersp* camera;
        CameraOrtho* cameraOrtho;
        
        
        private:
        
        void    _init();
        void    _initTextures();
        void    _initViews();
        void    _loop();
        
        void	windowDraw();
        
        signals::scoped_connection mCbUpdate;
    };
}

#endif /* Scene_hpp */
