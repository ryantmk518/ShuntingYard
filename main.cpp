#include <iostream>
#include <cstring>
#include <vector>
#include "node.h"


//Shunting Yard. Ryan Thammakhoune. Takes infix notation and converts it to infix, postfix and prefix.

using namespace std;
void enqueue(Node* &head, Node* h,  char* value);
Node* dequeue(Node* &head, Node* h);
Node* peek(Node* head);
Node* pop(Node* &head, Node* &current);
void print(Node* first);
void push(Node* &head, char* value);
void pushSide(Node* &head, char* lvalue, char* rvalue);
int getPrio(char p);
bool isEmpty(Node* head);
bool asc(char a);
void infix(Node * treeHead);
void prefix(Node* treeHead);

int main(){
  Node* queueHead = NULL; //Initialize heads
  Node* stackHead = NULL;
  Node* treeHead = NULL;
  char input[99];
  char array[99];
  char array2[99];
  cout << "Enter input" << endl;
  cin.get(input, 99); //Get input
  int a = 0;
  while (a < strlen(input)) {


    //All cout statements are essentially what the part of the code does


    //cout << "Starting cycle" << endl;
    if (input[a] == '+' || input[a] == '-' || input[a] == '*' || input[a] == '/' || input[a] == '^'){
      //cout << "Operator" << endl;
      if (stackHead != NULL) {
        //cout << "Stack is not empty" << endl;
        //cout << peek(stackHead)->getValue() << endl;
        while((getPrio(*(peek(stackHead)->getValue())) > getPrio(input[a]) || (getPrio(*(peek(stackHead)->getValue())) == getPrio(input[a]) && asc(input[a]))) && *(peek(stackHead)->getValue()) != '(' ) { //While operator at top of stack with higher prec, equal prec and is left asc, and is not left paren
          //cout << "Adding" << endl;
          enqueue(queueHead,queueHead,peek(stackHead) -> getValue());
          pop(stackHead,stackHead);
          if(&stackHead != NULL) {
            //cout << "Stack is now empty" << endl;
            break;
          }
          else {
            //cout << "Stack not yet empty" << endl;
            //cout << peek(stackHead)->getValue() << endl;
          }
        }
        char* temp = new char[2]();
        temp[0]=input[a];
        push(stackHead, temp);
        ++a;
      }
      else {
        //cout << "Stack empty" << endl;
        char* temp = new char[2]();
        temp[0]=input[a];
        //cout << temp << endl;
        push(stackHead, temp);
        ++a;
        //cout << "In stack:" << endl;
        //print(stackHead);
      }
    }
    else if (input[a] == '(') {
      //cout << "Left P" << endl;
      char* par = new char[2]();
      strcpy(par, (char*) "(");
      push(stackHead, par);
      ++a;
    }
    else if (input[a] == ')') {
      //cout << "Right P" << endl;
      while (*(peek(stackHead)->getValue())!= '(') {
        //cout << peek(stackHead) -> getValue() << endl;
        enqueue(queueHead, queueHead, peek(stackHead)->getValue());
        pop(stackHead, stackHead);
      }
      if (*(peek(stackHead) -> getValue()) == '(') {
        pop(stackHead, stackHead);
      }
      ++a;
    }
    else if (input[a] == ' '){
      //cout << "Space" << endl;
      ++a;
    }
    else {
      //cout << "Number" << endl;
      char* temp = new char[9]();
      int b = a;
      int c = 0;
      while (isalnum(input[b])) {
        temp[c] = input[b];
        ++b;
        ++c;
      }
      a = a + c;
      enqueue(queueHead, queueHead, temp);
    }
    //cout << "Cycle done" << endl;
  }
  while (stackHead != NULL) {
    //cout << "Stack contains components" << endl;
    //cout << peek(stackHead) -> getValue();
    enqueue(queueHead, queueHead, peek(stackHead)->getValue());
    //cout << "Added to queue" << endl;
    pop(stackHead,stackHead);
    //cout << "Stack is dumped" << endl;
  }
  cout << "Postfix: " << endl;
  print(queueHead);




  while (queueHead != NULL) {
    if (isalnum(*(queueHead)->getValue())) {
      push(treeHead, queueHead->getValue());
      dequeue(queueHead, queueHead);
    }
    else {
      Node* temp = new Node(queueHead->getValue());
      temp -> setRight(peek(treeHead));
      pop(treeHead, treeHead);
      temp -> setLeft(peek(treeHead));
      pop(treeHead, treeHead);
      push(treeHead, queueHead->getValue());
      dequeue(queueHead, queueHead);
    }
  }

  //Infix and prefix
  cout << "\n" << "Infix:" << endl;
  cout << "(" << input << ")" << endl;
  cout << "Postfix:" << endl;
  prefix(treeHead);
}

void infix(Node * treeHead) {
  if(treeHead != NULL) {
    if(*(treeHead->getValue()) == '+' || *(treeHead->getValue()) == '-' || *(treeHead->getValue()) == '*' || *(treeHead->getValue()) == '/') {
      cout << "(";
    }
    if(treeHead->getLeft() != NULL) {
      infix(treeHead->getLeft());
    }
    cout << treeHead->getValue();
    if(treeHead->getRight() != NULL) {
      infix(treeHead->getRight());
    }
    if(*(treeHead->getValue()) == '+' || *(treeHead->getValue()) == '-' || *(treeHead->getValue()) == '*' || *(treeHead->getValue()) == '/') {
      cout << ")";
    }
  }
}

void prefix(Node* treeHead) {
  if (treeHead != NULL){ 
    cout << treeHead -> getValue() << " ";
    if (treeHead -> getLeft() != NULL) {
      prefix(treeHead -> getLeft()); 
    }
    if (treeHead -> getRight() != NULL) {
      prefix(treeHead -> getRight()); 
    }
  }
  cout << "\n" << endl;
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
    //cout << "Not NULL" << endl;
    //cout << head->getNext() << endl;
    head = head->getNext();
    //cout << "Current is now next" << endl;
  }
  //cout << "Ayayaya" << endl;
  return head;
}


void enqueue(Node* &head, Node* h, char* value){ //Add to the queue
  if (head == NULL) {
    head = new Node(NULL);
    head->setValue(value);
    head->setNext(NULL);
    //cout << "Head null, setting head" << endl;
  }
  else if (h->getNext() == NULL) {
    Node* newNode = new Node(NULL);
    newNode -> setValue(value);
    h -> setNext(newNode);
    newNode -> setNext(NULL);
    //cout << "Found null, setting new" << endl;
  }
  else {
    enqueue(head, h->getNext(), value);
  }
}

Node* pop(Node* &head, Node* &current) {
  //cout << "Removing head" << endl;
  if(head == NULL) {
    //cout << "Head is null, return null" << endl;
    return NULL;
  }
  else if(current ->getNext() != NULL) {
    while(current->getNext()->getNext() != NULL) {
      current = current->getNext();
    }
    //cout << "Found last" << endl;
    current->setNext(NULL);
    return current;
  }
  else if(current->getNext() == NULL) {
    //current -> ~Node();
    delete current;
    current = NULL;
    //cout << "Setting head to NULL" << endl;
    return NULL;
  }
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
  cout << first->getValue();
  if (first -> getNext() != NULL) {
    Node* n = first->getNext();
    print(n);
  }
}


void push(Node* &head, char* value) {
  if (head == NULL) {
    head = new Node(NULL);
    head->setValue(value);
    head->setNext(NULL);
  }
  else if(head->getNext() != NULL){
    Node* n = head->getNext();
    push(n, value);
  }else{
    Node* newNode = new Node(NULL);
    newNode -> setValue(value);
    newNode -> setNext(NULL);
    head -> setNext(newNode);
  }
}

void pushSide(Node* &head, char* lvalue, char* rvalue) {
  if (head == NULL) {
    head = new Node(NULL);
    Node* right = new Node(rvalue);
    Node* left = new Node(lvalue);
    head->setRight(right);
    head->setLeft(left);
    }
  else if(head->getNext() != NULL){
    Node* n = head->getNext();
    pushSide(n, lvalue, rvalue);
  }
  else{
    Node* right = new Node(NULL);
    Node* left = new Node(NULL);
    head -> setLeft(left);
    head -> setRight(right);;
  }
}

bool isEmpty(Node* head) {
  if(head == NULL) {
    return true;
  }
  return false;
}
