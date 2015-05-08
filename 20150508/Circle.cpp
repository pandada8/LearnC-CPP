//
// Created by pan on 5/8/15.
//

#include "Circle.h"
#include <iostream>

using namespace std;

void Circle::draw() {
    cout <<  "I am a Circle @ " << this->x << ", " << this->y \
         <<  " with R " << this->r << endl;
}