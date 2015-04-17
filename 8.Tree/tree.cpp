#include <vector>
#include "tree.h"

Node::Node(int value){
    data = value;
}
void Node::append(Node* node){
    childs.push_back(node);
    node -> setParent(this);
    return;
}

int Node::countNode(){
    int tmp = 1;
    for (vector<Node*>::iterator vi=childs.begin(); vi != childs.end(); ++ vi){
        tmp += (*vi) -> countNode();
    }
    return tmp;
}

int Node::getValue(){
    return data;
}

void Node::setParent(Node * parent){
    this -> parent = parent;
    return;
}
Node * Node::getParent(){
    return this -> parent;
}
