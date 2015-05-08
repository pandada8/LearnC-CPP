//
// Created by pan on 5/8/15.
//

#include <iostream>
#include "Paintable.h"
#include "Circle.h"
#include "Canvas.h"
#include "Rectangle.h"

using namespace std;

int main(){
    Canvas canvas;
    Circle c1(11, 2, 5);
    Circle c2(20,30,100);


    Rectangle r1(10,20,5,3);

    canvas.append(&c1);
    canvas.append(&r1);
    canvas.append(&c2);
    canvas.draw();
    return 0;
}
