#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <cstring>

using namespace std;

class Node {
 public:
  Node(char*);
  ~Node();
  char* getValue();
  void setValue(char*);
  Node* getRight();
  Node* getLeft();
  void setRight(Node*);
  void setLeft(Node*);
 private:
  Node* left;
  Node* right;
  char* value;
}
