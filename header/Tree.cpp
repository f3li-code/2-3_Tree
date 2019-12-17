#include "Tree.h"
#include <iostream>
using namespace std;

Tree::Tree()
{
    root = nullptr;
}

void Tree::preOrder() const{
    return preOrder(root);
    cout << endl;
}
void Tree::preOrder(Node* n) const{
    if (n == nullptr){
        return;
    }
    if (n->small != ""){
        n->printSmall();
    }
    preOrder(n->left);
    if (n->large != ""){
        n->printLarge();
    }
    preOrder(n->middle);
    preOrder(n->right);
}

void Tree::inOrder() const{
    return inOrder(root);
    cout << endl;
}
void Tree::inOrder(Node* n) const{
    if (n == nullptr){
        return;
    }
    inOrder(n->left);
    if (n->small != ""){
        n->printSmall();
    }
    inOrder(n->middle);
    if (n->large != ""){
        n->printLarge();
    }
    inOrder(n->right);

}

void Tree::postOrder() const{
    return postOrder(root);
    cout << endl;
}
void Tree::postOrder(Node* n) const{
    if (n == nullptr){
        return;
    }
    postOrder(n->left);
    postOrder(n->middle);
    if (n->large != ""){
        n->printSmall();
        postOrder(n->right);
        n->printLarge();
    }
    else {
        postOrder(n->right);
        n->printSmall();
    }
}

bool Tree::search(const string& key) const{
    Node* n = search(root, key);
    if (n != nullptr){
        return true;
    }
    return false;
}
Node* Tree::search(Node* n, const string& key) const{ //THIS PIECE OF CODE BELONGS TO nghia nhan duong
    if (n != nullptr) {
        if (n->small == key || n->large == key) {
            return n;
        }
        else {
            if (n->small > key) {
                return search(n->left, key);
            }
            else if (!n->isFull() || key < n->large ) {
                return search(n->middle, key);
            }
            else {
                return search(n->right, key);
            }
        }
    }
    return nullptr;
}

void Tree::insert(const string& str){
    if (search(str)){// IF IT ALREADY EXISTS
        return;
    }
    if (root == nullptr){//IF TREE IS EMPTY
        Node* addNode = new Node(str);
        root = addNode;
        return;
    }
    Node* cur = root;
    while (cur->left != nullptr){ //LOCATING CORRECT LEAF NODE
        if (cur->isFull()){//CUR IS FULL
            if (str < cur->small){
                cur = cur->left;
            }
            else if (str > cur->small && str < cur->large){
                cur = cur->middle;
            }
            else {
                cur = cur->right;
            }
        }
        else {//CUR IS NOT FULL
            if (str < cur->small){
                cur = cur->left;
            }
            else {
                cur = cur->middle;
            }
        }
    }
    if (cur->isFull()){//IF TARGET NODE IS FULL
        splitLeaf(cur, str);

    }
    else {
        cur->large = str;
        cur->sort();
    }
    return;
}

void Tree::splitLeaf(Node* n, const string& key){
    string s = n->smallest(key);
    string m = n->medium(key);
    string l = n->largest(key);
    if (root == n){//IF SPLITING ROOT NODE
        Node* newl = new Node(s);
        Node* newr = new Node(l);
        Node* newroot = new Node(m);
        delete n;//DELETE OLD ROOT DATA;
        root = newroot;
        newroot->left = newl;
        newroot->middle = newr;
        newl->parent = newroot;
        newr->parent = newroot;
        return;
    }


    else { //IF NOT SPLITING ROOT NODE
        if (!n->parent->isFull()){//IF PARENT IS NOT FULL
            Node* par = n->parent;
            Node* newl = new Node(s);
            Node* newr = new Node(l);
            //INSERT MEDIUM DATA into PARENT
            par->large = m;
            par->sort();

            if (par->left == n){//IF N IS LEFT CHILD OF PAR
                //MOVE OLD MIDDLE to RIGHT
                par->right = par->middle;
                //CLEAR OLD DATA
                delete n;
                par->left = newl;
                par->middle = newr;
                return;
            }
            else {//IF N IS MIDDLE CHILD OF PAR
                delete n;
                par->middle = newl;
                par->right = newr;
                return;
            }
            newl->parent = par;
            newr->parent = par;
        }
        else {//IF PARENT IS FULL    //IF PARENT IS FULL
            n->small = s;
            n->large = l;
            splitInternal(n, n->parent, m);
            return;
        }
    }
}

void Tree::splitInternal(Node* giver, Node* target, const string& key){
    //GIVER SHOULD BE SPLITTED to TWO NODES
    //BOTH GIVER AND TARGET ARE FULL
    string ts = target->smallest(key);
    string tm = target->medium(key);
    string tl = target->largest(key);
    string gs = giver->smallest(key);
    string gl = giver->largest(key);
    Node* newl = new Node(ts);
    Node* newr = new Node(tl);
    Node* newTargetl = new Node(gs);
    Node* newTargetr = new Node(gl);
    if (target == root){//IF SPLITING ROOT
        Node* newroot = new Node(tm);
        //FIX LV 2
        newroot->left = newl;
        newl->parent = newroot;
        newroot->middle = newr;
        newr->parent = newroot;
        if (target->left == giver){//IF GIVER IS TARGET'S LEFT CHILD
            //FIX LV 3
            newl->left = newTargetl;
            newl->middle = newTargetr;
            newr->left = target->middle;
            newr->middle = target->right;

        }
        else if (target->middle == giver){//IF GIVER IS TARGET's MIDDLE CHILD
            //FIX LV 3
            newl->left = target->left;
            newl->middle = newTargetl;
            newr->left = newTargetr;
            newr->middle = target->right;
        }
        else {//IF GIVER IS TARGET's RIGHT CHILD
            newl->left = target->left;
            newl->middle = target->middle;
            newr->left = newTargetl;
            newr->middle = newTargetr;
        }
        newl->left->parent = newl;
        newl->middle->parent = newl;
        newr->left->parent = newr;
        newr->middle->parent = newr;
        //DELETE OLD DATA FOR ALL CASES
        delete root;
        root = newroot;
        delete target;
        delete giver;
    }
}





