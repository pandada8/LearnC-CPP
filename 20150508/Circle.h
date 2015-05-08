//
// Created by pan on 5/8/15.
//

#ifndef CANDCPP_CIRCLE_H
#define CANDCPP_CIRCLE_H

#include "Paintable.h"

class Circle : public Paintable{
public:
    Circle(int x, int y, int r): Paintable(x, y){this->r = r;};
    void draw();
private:
    int r;
};


#endif //CANDCPP_CIRCLE_H
