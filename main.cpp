#include <iostream>
#include <cstring>
#include <vector>
#include "node.h"

using namespace std;
void enqueue(Node* &head, Node* h,  char* value);
Node* dequeue(Node* &head, Node* h);
Node* peek(Node* head);
Node* pop(Node* &head, Node* &current);
void print(Node* first);
void push(Node* &head, char* value);
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
    cout << "Starting cycle" << endl;
    if (input[a] == '+' || input[a] == '-' || input[a] == '*' || input[a] == '/' || input[a] == '^'){
      cout << "Operator" << endl;
      if (stackHead != NULL) {
        cout << "Stack is not empty" << endl;
        cout << stackHead->getValue() << endl;
        while((getPrio(*(peek(stackHead)->getValue())) > getPrio(input[a]) || (getPrio(*(peek(stackHead)->getValue())) == getPrio(input[a]) && asc(input[a]))) && *(peek(stackHead)->getValue()) != '(' ) {
          cout << "Adding" << endl;
          enqueue(queueHead,queueHead,peek(stackHead) -> getValue());
          pop(stackHead,stackHead);
          if(stackHead != NULL) {
            cout << "Stack is now empty" << endl;
            break;
          }
        }
        char temp[2] = {'\0','\0'};
        temp[0]=input[a];
        push(stackHead, temp);
        ++a;
      }
      else {
        cout << "Stack empty" << endl;
        char temp[2] = "";
        temp[0]=input[a];
        temp[1] = '\0';
        push(stackHead, temp);
        ++a;
        cout << "In stack:" << endl;
        //print(stackHead);
      }
    }
    else if (input[a] == '(') {
      cout << "Left P" << endl;
      char temp[2] = "(";
      push( stackHead, temp);
      ++a;
    }
    else if (input[a] == ')') {
      cout << "Right P" << endl;
      while (*(peek(stackHead)->getValue())!= '(') {
        enqueue(queueHead, queueHead, peek(stackHead)->getValue());
        pop(stackHead, stackHead);
      }
      if (*(peek(stackHead) -> getValue()) == '(') {
        pop(stackHead, stackHead);
      }
      ++a;
    }
    else if (input[a] == ' '){
      cout << "Space" << endl;
      ++a;
    }
    else {
      cout << "Number" << endl;
      char temp[9] = {'\0','\0','\0','\0','\0','\0','\0','\0','\0'};
      int b = a;
      int c = 0;
      while (isalnum(input[b])) {
        cout << input[a] << endl;
        temp[c] = input[b];
        ++b;
        ++c;
      }
      a = a + c;
      enqueue(queueHead, queueHead, temp);
    }
    cout << "Cycle done" << endl;
  }
  cout << "Beginning output" << endl;
  while (stackHead != NULL) {
    cout << stackHead -> getValue() << endl;
    cout << "Stack contains components" << endl;
    cout << peek(stackHead) -> getValue();
    enqueue(queueHead, queueHead, peek(stackHead)->getValue());
    cout << "Added to queue" << endl;
    pop(stackHead,stackHead);
    cout << "Stack is dumped" << endl;
  }
  print(queueHead);

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

Node* peek(Node* head) {
  if(head == NULL) {
    return NULL;
  }
  while(head->getNext() != NULL) {
    cout << "Not NULL" << endl;
    //cout << head->getNext() << endl;
    head = head->getNext();
    cout<< "Current is now next" << endl;
  }
  cout << "Ayayaya" << endl;
  return head;
}


void enqueue(Node* &head, Node* h, char* value){ //Push function to add to the linked list
  if (head == NULL) {
    head = new Node(NULL);
    head->setValue(value);
    head->setNext(NULL);
    cout << "Head null, setting head" << endl;
  }
  else if (h->getNext() == NULL) {
    Node* newNode = new Node(NULL);
    newNode -> setValue(value);
    h -> setNext(newNode);
    newNode -> setNext(NULL);
    cout << "Found null, setting new" << endl;
  }
  else {
    enqueue(head, h->getNext(), value);
  }
}

Node* pop(Node* &head, Node* &current) {
  cout << "Removing head" << endl;
  if(head == NULL) {
    cout << "Head is null, return null" << endl;
    return NULL;
  }
  else if(current ->getNext() != NULL) {
    while(current->getNext()->getNext() != NULL) {
      current = current->getNext();
    }
    cout << "Found last" << endl;
    current->setNext(NULL);
    return current;
  }
  else if(current->getNext() == NULL) {
    //current -> ~Node();
    delete current;
    current = NULL;
    cout << "Setting head to NULL" << endl;
  }

  return current;
}


Node* dequeue(Node* &head, Node* current) {
  int count = 0;
  if(head == NULL) {
    return NULL;
  }
  else if(head->getNext() == NULL) {
    head = NULL;
    return NULL;
  }
  else {
    head= current->getNext();
    return current;
  }
}

void print(Node* first) {
  if (first == NULL) {
    return;
  }
  cout << first->getValue() << endl;
  if (first -> getNext() != NULL) {
    Node* n = first->getNext();
    print(n);
  }
}


void push(Node* &head, char* value) {
  if (head == NULL) {
    head = new Node(NULL);
    head->setValue(value);
  }
  else if(head->getNext() != NULL){
    Node* n = head->getNext();
    push(n, value);
  }else{
    Node* newNode = new Node(NULL);
    newNode -> setValue(value);
  }
}

void pushSide(Node* &head, Node* h,  char* value) {
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
    push(head,  value);
  }
}

bool isEmpty(Node* head) {
  if(head == NULL) {
    return true;
  }
  return false;
}
