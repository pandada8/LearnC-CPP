#include <iostream>

using namespace std;

static int data[3] = {0,1,2};
static int n = 0;
int func(){
    
    return data[n++];
}

int main(void){
    cout << func() << func() << func();
//    cout << boolalpha << endl << stack.pop() << endl << stack.pop() << endl << stack.isEmpty() << endl;
// DAMN CPP COUT
    return 0;
}
