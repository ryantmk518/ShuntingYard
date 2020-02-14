#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;
void push(Node* first, char* value);
Node* queueHead = NULL;
void pop(Node* first);
void enqueue(Node* first, char* value);
void dequeue(Node* first);

int main(){
  bool oper = false;
  bool num = false;
  char input[99];
  char temp[99];
  cout << "Enter input" << endl;
  cin.get(input, 99);
  int a = 0;
  for (int i = 0; i < strlen(input); i++) {
    if (input[i] != ' ') {
      char temp[a];
      temp[a] = input[i];
      ++a;
    }
    else if (input[i] == ' ') {
      a = 0;
      push(queueHead, temp);
    }
  }
  push(queueHead, temp);
}

void push(Node* first, char* value){ //Push function to add to the linked list
  Node* current = first;
  if (current == NULL){
    cout << "Check" << endl;
    current = new Node(NULL);
    current -> setValue(value);
  }
  else if (current -> getNext() == NULL ) {
    Node* newNode = new Node(value);
    current -> setNext(newNode);
    cout << current->getNext()->getValue();
  }
  else if (current -> getNext() != NULL) {
    push(current-> getNext(), value);
  }
}

void enqueue(Node* first, char* value){ //Push function to add to the linked list
  Node* current = first;
  if (current == NULL){
    cout << "Check" << endl;
    current = new Node(NULL);
    current -> setValue(value);
  }
  else if (current -> getNext() == NULL ) {
    Node* newNode = new Node(value);
    current -> setNext(newNode);
    cout << current->getNext()->getValue();
  }
  else if (current -> getNext() != NULL) {
    push(current-> getNext(), value);
  }
}

void pop(Node* first) {
  if (first->getNext()->getNext() == NULL) {
    if (first->getNext() == NULL) {
      cout << first -> getValue();
      first -> ~Node();
    }
    else {
      first ->setNext(NULL);
      cout << first->getValue();
      first ->getNext()-> ~Node();
    }
  }
  else {
    pop(first->getNext());
  }
}

void dequeue(Node* first) {
  Node* temp = new Node(NULL);
  temp = first;
  first = first -> getNext();
  temp -> ~Node();
}

