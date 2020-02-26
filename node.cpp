#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;

//Node class


Node::Node(char* newvalue) { //Initialize node
  //strcpy(value, newvalue);
  value = newvalue;
  right = NULL;
  left = NULL;
}

Node::~Node() { //Delete node
  //delete value;
  value = NULL;
}

void Node::setValue(char* newvalue) { //Set value
  value = newvalue;
}

char* Node::getValue(){ //Returns value
  return value;
}

Node* Node::getRight() { //Returns right node
  return right;
}

Node* Node::getLeft() { //Returns left node
  return left;
}

Node* Node::getNext(){ //Returns next node
  return next;
}

void Node::setNext(Node* newnext) { //Sets next node
  next = newnext;
}

void Node::setLeft(Node* newleft) { //Sets left node
  left = newleft;
}

void Node::setRight(Node* newright) { //Sets right node
  right = newright;
}

