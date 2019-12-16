#ifndef __TREE_H
#define __TREE_H

#include "Node.h"
//NOTE TO SELF
/*
study traversal
*/

class Tree {
private:
  Node *root;

public:
  Tree( );
  //~Tree( );
  void insert(const string &);
  void preOrder( ) const;
  void inOrder( ) const;
  void postOrder( ) const;
  void remove(const string &);
  bool search (const string &) const;


private:
  // Add additional functions/variables here
  void preOrder(Node*) const;
  void inOrder(Node*) const;
  void postOrder(Node*) const;
  Node* search(Node*, const string &) const;
  void splitLeaf(Node*, const string&);
  void splitInternal(Node*, Node*, const string&);
  string findSuccessor(const string&) const;
  void remove(Node*, const string&);
  Node* leftSibling(Node*) const;
  Node* middleSibling(Node*) const;
  Node* rightSibling(Node*) const;

};

#endif
