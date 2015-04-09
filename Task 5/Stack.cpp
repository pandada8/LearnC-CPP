#include <iostream>

using namespace std;

#define STACK_SIZE 50

class Stack{
    private:
        int data[STACK_SIZE];
        
    public:
        int position;
        Stack(){
            position = -1;
        };
        void push(int d){
            data[++position] = d;
        };
        int pop(void){
            return data[position--];
        };
        bool isEmpty(){
            return position == -1;
        };
        void debug(){
            for (int i=0;i<=position;i++){
                cout << data[i];
            }
            cout << endl;
        };
};

int main(void){
    Stack stack;
    stack.push(0);
    stack.push(1);
    stack.push(2);
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << boolalpha << stack.isEmpty() << endl;
//    cout << boolalpha << endl << stack.pop() << endl << stack.pop() << endl << stack.isEmpty() << endl;
// DAMN CPP COUT
    return 0;
}
