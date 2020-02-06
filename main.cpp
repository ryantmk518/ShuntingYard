#include <iostream>
#include <cstring>

using namespace std;

void add(Node* first, char* value);
Node* head = null;

int main(){
  bool oper = false;
  bool num = false;
  char* input = new char[99];
  int* space = new int[99];
  char* temp = new char[99];
  cout << "Enter input" << endl;
  cin >> input;
  int b = 0;
  for (int a = 0; a < strlen(input); a++) { //Finds where the spaces are
    if (input[a] == " ") {
       space[b]=input[a];
       ++b;
     }
  }
  int c = 0;
  int d = 0;
  for (int i=0; a<strlen[space]+1; a++) {
    while (d<space[i]){
      temp[c] = input[d];
      ++c;
      ++d;
    }
  }
}

void add(Node* first, char* value){ //Add function to construct the linked list
  Value* null = NULL;
  Value* newvalue = value;
  Node* current = first;
  if (current==NULL){
    first  -> setValue(value);
  }
  else if (current -> getNext() = NULL ) {
    current -> setNext(new Node(null));
    current -> setValue(value);
  }
  else if (current -> getNext != NULL) {
    add(current-> getNext(), value);
  }
}
 
