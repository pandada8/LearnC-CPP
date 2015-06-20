#include <vector>
#include <iostream>

using namespace std;

#define Item int

class Queue{
public:
    Iterator * createIter();
    void push(Item x){
        numbers.push_back(x);
    }
    int count(){
        return numbers.size();
    }
    friend class Iterator;
private:
    vector<int> numbers;
};

class Iterator{
public:
    Iterator(Queue * queue) : queue(queue), index(0) {};
    Item * first();
    Item * end();
    Item * next();
private:
    Queue * queue;
    int index;
};
