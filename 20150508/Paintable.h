//
// Created by pan on 5/8/15.
//

#ifndef CANDCPP_PAINTABLE_H
#define CANDCPP_PAINTABLE_H


class Paintable {
public:
    Paintable(int x, int y): x(x), y(y){};
    void virtual draw(){};
protected:
    int x,y;
};


#endif //CANDCPP_PAINTABLE_H
