//
// Created by pan on 15-4-24.
//

#include "queue.h"
#include <iostream>
using namespace std;
int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << q.count();
    return 0;
}