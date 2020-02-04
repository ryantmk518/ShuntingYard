#include <iostream>
#include <cstring>
#include "Node.h"
#include "Value.h"

using namespace std;

Node::Node(char* newvalue) {
  value = newvalue;
  right = NULL;
  left = NULL;
}

Node::~Node() {
  delete &value;
}

void Node::setValue(char* newvalue) {
  value = newvalue;
}

char* Node::getValue(){
  return value;
}

Node* Node::getRight() {
  return right;
}

Node* Node::getLeft() {
  return left;
}
