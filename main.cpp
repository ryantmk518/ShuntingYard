#include <iostream>
#include <cstring>
#include <vector>
#include "node.h"

using namespace std;
void enqueue(Node* &head, Node* h,  char* value);
void dequeue(Node* first);
Node* peek(Node* &head, Node* current);
Node* pop(Node* &head, Node* current);
void print(Node* first);
void push(Node* &head, Node* h, char* value);
int getPrio(char p);
bool isEmpty(Node* head);
bool asc(char a);

int main(){
  Node* queueHead = NULL;
  Node* stackHead = NULL;
  cout << "Put spaces between the numbers, operators, and parantheses" << endl;
  char input[99];
  char array[99];
  char array2[99];
  cout << "Enter input" << endl;
  cin.get(input, 99);
  int a = 0;
  while (a < strlen(input)) {
    if (input[a] == '+' || input[a] == '-' || input[a] == '*' || input[a] == '/' || input[a] == '^'){
      if (isEmpty(stackHead) == false) {
        while((getPrio(*(peek(stackHead,stackHead)->getValue())) > getPrio(input[a]) || (getPrio(*(peek(stackHead,stackHead)->getValue())) == getPrio(input[a]) && asc(input[a]))) && *(peek(stackHead,stackHead)->getValue()) != '(' ) {
          cout << "Adding" << endl;
          enqueue(queueHead,queueHead,peek(stackHead,stackHead) -> getValue());
          pop(stackHead,stackHead);
          if(isEmpty(stackHead)) {
            break;
          }
        }
        char temp[2] = "";
        temp[0]=input[a];
        push(stackHead, stackHead, temp);
        ++a;
      }
      else {
        char temp[2] = "";
        temp[0]=input[a];
        push(stackHead, stackHead, temp);
        ++a;
      }
    }
    else if (input[a] == '(') {
      char temp[2] = "(";
      push(stackHead, stackHead, temp);
    }
    else if (input[a] == ')') {
      while (*(peek(stackHead, stackHead)->getValue())!= '(') {
        enqueue(queueHead, queueHead, peek(stackHead, stackHead)->getValue());
        pop(stackHead, stackHead);
      }
      if (*(peek(stackHead,stackHead) -> getValue()) == '(') {
        pop(stackHead, stackHead);
      }
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
      enqueue(queueHead, queueHead, temp);
    }
  }
  while (stackHead != NULL) {
    enqueue(queueHead, queueHead, peek(stackHead,stackHead)->getValue());
    pop(stackHead,stackHead);
  }
  /*
  while (queueHead != NULL) {
    if (isdigit(*(queueHead)->getValue())) {
      Node* temp = new Node(queueHead->getValue());

    }
  }
  */
}

int getPrio(char p) {
  if (p == '+' || p == '-') {
    return 2;
  }
  else if (p == '*' || p == '/'){
    return 3;
  }

  else if (p == '^'){
    return 4;
  }
}

bool asc(char a) {
  if (a == '^') {
    return false;
  }
  else {
    return true;
  }
}

Node* peek(Node* &head, Node* current) {
  if(head == NULL) {
    return NULL;
  }
  while(current->getNext() != NULL) {
    current = current->getNext();
  }
  return current;
}


void enqueue(Node* &head, Node* h, char* value){ //Push function to add to the linked list
  if (head == NULL) {
    head = new Node(NULL);
    head->setValue(value);
    head->setNext(NULL);
  }
  else if (head->getNext() == NULL) {
    Node* newNode = new Node(NULL);
    newNode -> setValue(value);
    h -> setNext(newNode);
    newNode -> setNext(NULL);
  }
  else {
    enqueue(head, h->getNext(), value);
  }
}

Node* pop(Node* &head, Node* current) {
  if(head == NULL) {
    return NULL;
  }
  else if(current ->getNext() != NULL) {
    while(current->getNext()->getNext() != NULL) {
      current = current->getNext();
    }
    Node* temp = new Node(NULL);
    temp = NULL;
    current->setNext(temp);
    return current;
  }
  else if(current->getNext() == NULL) {
    head = NULL;
    cout << "e" << endl;
  }
  return current;
}


void dequeue(Node* first) {
  Node* temp = new Node(NULL);
  temp = first;
  first = first -> getNext();
  temp -> ~Node();
}

void print(Node* first) {
  //cout << "Printing" << endl;
  if (first != NULL) {
    cout << first -> getValue() << endl;
  }
  if (first -> getNext() != NULL) {
    print (first->getNext());
  }
}


void push(Node* &head, Node* h,  char* value) {
  if (head == NULL) {
    head = new Node(NULL);
    head->setValue(value);
    head->setNext(NULL);
  }
  else if (head->getNext() == NULL) {
    Node* newNode = new Node(NULL);
    newNode -> setValue(value);
    h -> setNext(newNode);
    newNode -> setNext(NULL);
  }
  else {
    push(head, h->getNext(), value);
  }
}

bool isEmpty(Node* head) {
  if(head == NULL) {
    return true;
  }
  return false;
}
