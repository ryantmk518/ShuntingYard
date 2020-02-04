#include <iostream>
#include <cstring>

using namespace std;

void add(char* value);

int main(){
  bool oper = false;
  bool num = false;
  char* input = new char[99];
  int* space = new int[99];
  cout << "Enter input" << endl;
  cin >> input;
  int b = 0;
  for (int a = 0; a < strlen(input); a++) { //Finds where the spaces are
    if (input[a] == " ") {
       space[b]=input[a];
       ++b;
     }
  }
}

void add(char* value){
  
}
