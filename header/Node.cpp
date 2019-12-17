/*

#include "Node.h"
#include <iostream>
#include <string>
using namespace std;

Node::Node()
{
    left = nullptr;
    right = nullptr;
    middle = nullptr;
    parent = nullptr;
    small = "";
    large = "";
}
Node::Node(const string& str){
    left = nullptr;
    right = nullptr;
    middle = nullptr;
    parent = nullptr;
    small = str;
    large = "";
}

bool Node::isFull() const {
    if (large != ""){
        return true;
    }
    return false;
}
bool Node::isLeaf() const{
    if (middle == nullptr){
        return true;
    }
    return false;
}

string Node::smallest(const string& str) const{
    if (str < small){
        return str;
    }
    return small;
}
string Node::medium(const string& str) const{
    if (str < small){
        return small;
    }
    else if (str > large){
        return large;
    }
    return str;
}
string Node::largest(const string& str) const{
    if (str > large){
        return str;
    }
    return large;
}

void Node::printSmall() const{
    cout << small << ", ";
    return;
}
void Node::printLarge() const{
    cout << large << ", ";
    return;
}

void Node::sort(){
    if (large < small){
        string tmp = large;
        large = small;
        small = tmp;
    }
    return;
}

*/
