#include <vector>

using namespace std;

class Node{
    private:
        vector<Node*> childs;
        int data;
        Node* parent; 
    public:
        Node(int);
        void append(Node* node);
        int countNode();
        int getValue();
        void setParent(Node *);
        Node* getParent();
};
