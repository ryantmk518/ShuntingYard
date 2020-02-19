#include <iostream>
#include <cstring>
#include <vector>
#include "node.h"

using namespace std;
void push(Node* first, char* value);
Node* queueHead = NULL;
Node* stackHead = NULL;
void pop(Node* first, vector<char*> output);
void enqueue(Node* first, char* value);
void dequeue(Node* first);

int main(){
  cout << "Put spaces between the numbers, operators, and parantheses" << endl;
  char input[99];
  int prio = 0;
  vector<char*> output;
  cout << "Enter input" << endl;
  cin.get(input, 99);
  int a = 0;
  while (a < strlen(input)){
    if (input[a] == '+' || input[a] == '-' || input[a] == '*' || input[a] == '/' || input[a] == '^'){
      if (input[a] == '+') {
        prio = 2;
      } 
      else if (input[a] == '-') {
        prio = 2;
      }
      else if (input[a] == '*') {
        prio = 3;
      }
      else if (input[a] == '/') {
        prio = 3;
      }
      else if (input[a] == '^') {
        prio = 4;
      }

      char temp[1] = "";
      temp[0]=input[a];
      push(stackHead, temp);
      ++a;
    }
    else if (input[a] == '(') {
      char temp[2] = "(";
      push(stackHead, temp);
    }
    else if (input[a] == ')') {
      char temp[2] = ")";
      push(stackHead, temp);
    }
    else if (input[a] == ' '){
      ++a;
    }
    else {
      char temp[9] = "";
      int b = a;
      int c = 0;
      while (input[b] == '0' || input[b] == '1' || input[b] == '2' || input[b] == '3' || input[b] == '4' || input[b] == '5' || input[b] == '6' || input[b] == '7' || input[b] == '8' || input[b] == '9') {
        temp[c] = input[b];
        ++b;
        ++c;
      }
      a = a + c;
      temp[c] = '\n';
      cout << temp << endl;
      push(queueHead, temp);
    }
  }
}





void push(Node* first, char* value){ //Push function to add to the linked list
  Node* current = first;
  if (current == NULL){
    cout << value << endl;
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

void pop(Node* first, vector<char*> output) {
  if (first->getNext()->getNext() == NULL) {
    if (first->getNext() == NULL) {
      cout << first -> getValue();
      output.push_back(first -> getValue());
      first -> ~Node();
    }
    else {
      first ->setNext(NULL);
      cout << first->getValue();
      first ->getNext()-> ~Node();
    }
  }
  else {
    pop(first->getNext(), output);
  }
}

void dequeue(Node* first) {
  Node* temp = new Node(NULL);
  temp = first;
  first = first -> getNext();
  temp -> ~Node();
}

