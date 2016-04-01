//
//  View.cpp
//  BasicTemplate
//
//  Created by Yi-Wen Lin on 2016/4/1.
//
//

#include "View.hpp"

using namespace bongiovi;

View::View() {
    _vsPath = "shaders/basic.vert";
    _fsPath = "shaders/basic.frag";
    
    _initShader();
    _init();
}


View::View(string vsPath, string fsPath) : _vsPath(vsPath), _fsPath(fsPath) {
    _initShader();
    _init();
}


void View::_initShader() {
    try {
        shader = new ci::gl::GlslProg( loadResource(_vsPath), loadResource(_fsPath) );
    }
    catch( gl::GlslProgCompileExc &exc ) {
        console() << "Cannot compile shader: " << exc.what() << std::endl;
        exit(1);
    }
    catch( Exception &exc ){
        console() << "Cannot load shader: " << exc.what() << std::endl;
        exit(1);
    }
    cout << "Creating shader program : " << _vsPath << ", " << _fsPath << endl;

}


void View::_init() {
    
}


void View::render() {
    
}