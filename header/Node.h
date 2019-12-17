#ifndef __NODE_H
#define __NODE_H

#include <string>

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
    bool isFull() const;
    bool isLeaf() const;
    string smallest(const string&) const;
    string medium(const string&) const;
    string largest(const string&) const;
    void printSmall() const;
    void printLarge() const;
    void sort();

public:
    Node();
    Node(const string& str);
};


#endif
