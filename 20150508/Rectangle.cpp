//
// Created by pan on 5/8/15.
//

#include "Rectangle.h"
#include <iostream>

using namespace std;

void Rectangle::draw() {
    cout << "I am a rectangle @ " << this->x << "," << this->y \
         << " with height " << this->w << " width " << this->h <<endl;
}