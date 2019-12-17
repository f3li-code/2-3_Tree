#ifndef __NODE_H
#define __NODE_H

#include <string>
#include <iostream>

using namespace std;

class Node {

    friend class Tree;

private:
    string small;
    string large;

    Node *left;
    Node *middle;
    Node *right;
    Node *parent;

    // Add additional functions/variables here. Remember, you may not add any
    // Node * or string variables.
private:
    bool isFull() const {
        return (this->large != "");
    }

    bool isLeaf() const {
        return (this->middle == nullptr);
    }

    string smallest(const string &str) const {
        if (str < this->small) {
            return str;
        }
        return this->small;
    }

    string medium(const string &str) const {
        if (str < this->small) {
            return this->small;
        } else if (str > this->large) {
            return this->large;
        }
        return str;
    }

    string largest(const string &str) const {
        if (str > this->large) {
            return str;
        }
        return this->large;
    }

    void printSmall() const {
        cout << small << ", ";
        return;
    }

    void printLarge() const {
        cout << large << ", ";
        return;
    }

    void sort() {
        if (large < small) {
            string tmp = large;
            large = small;
            small = tmp;
        }
        return;
    }

public:
    Node() {
        left = nullptr;
        right = nullptr;
        middle = nullptr;
        parent = nullptr;
        small = "";
        large = "";
    }

    Node(const string &str) {
        left = nullptr;
        right = nullptr;
        middle = nullptr;
        parent = nullptr;
        small = str;
        large = "";
    }
};


#endif
