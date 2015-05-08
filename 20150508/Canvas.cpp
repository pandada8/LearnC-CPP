//
// Created by pan on 5/8/15.
//

#include "Canvas.h"

void Canvas::append(Paintable * x) {
    this->data.push_back(x);
}

void Canvas::draw() {
    for(auto p: this->data){
        p->draw();
    }
}