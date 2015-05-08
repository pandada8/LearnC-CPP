//
// Created by pan on 5/8/15.
//

#ifndef CANDCPP_RECTANGLE_H
#define CANDCPP_RECTANGLE_H

#include "Paintable.h"

class Rectangle : public Paintable {
public:
    Rectangle(int x, int y, int w, int h) : Paintable(x, y), w(w), h(h){};
    void draw();
private:
    int w, h;
};


#endif //CANDCPP_RECTANGLE_H
