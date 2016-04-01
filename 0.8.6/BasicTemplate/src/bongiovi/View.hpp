//
//  View.hpp
//  BasicTemplate
//
//  Created by Yi-Wen Lin on 2016/4/1.
//
//

#ifndef View_hpp
#define View_hpp

#include <stdio.h>
#include "cinder/gl/GlslProg.h"
#include "cinder/gl/Texture.h"
#include "cinder/gl/Vbo.h"

using namespace ci;
using namespace ci::app;
using namespace std;

namespace bongiovi {
    class View {
        public:
        View();
        View(string, string);
        gl::GlslProg*   shader;
        gl::VboMesh     mesh;
        string          _vsPath;
        string          _fsPath;
        
        void    render();
        
        private:
        void    _init();
        void    _initShader();
    };
}

#endif /* View_hpp */
