#include <iostream>
#include <cstring>
#include "Node.h"

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

Node* Node::getNext(){
  return next;
}

void Node::setNext(Node* newnext) {
  next = newnext;
}

void Node::setLeft(Node* newleft) {
  left = newleft;
}

void Node::setRight(Node* newright) {
  right = newright;
}
