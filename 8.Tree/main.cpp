#include <iostream>
#include "tree.h"

using namespace std;

int main(){
    Node * root = new Node(100);
    Node * child1 = new Node(200);
    Node * child2 = new Node(300);
    Node * child1_1 = new Node(400);
    Node * child2_1 = new Node(500);
    root -> append(child1);
    root -> append(child2);
    child1 -> append(child1_1);
    child2 -> append(child2_1);
    cout << "Counts: " << root -> countNode() << endl;
    cout << "Root Value:" << root -> getValue() << endl;
    cout << "Yet another Root:" << child1 -> getParent() -> getValue() << endl;
    return 0;
}
