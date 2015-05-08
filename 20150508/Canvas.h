//
// Created by pan on 5/8/15.
//

#ifndef CANDCPP_CANVAS_H
#define CANDCPP_CANVAS_H

#include <vector>
#include "Paintable.h"

using  namespace std;

class Canvas {
public:
    Canvas(){};
    void append(Paintable * x);
    void draw();
private:
    vector<Paintable *> data;
};


#endif //CANDCPP_CANVAS_H
