#ifndef VALUE_H
#define VALUE_H
#include <iostream>
#include <cstring>

using namespace std;

class Value {
 public:
  Value(char* value);
  ~Value();
  char* getValue();
 private:
  char* value;
}
