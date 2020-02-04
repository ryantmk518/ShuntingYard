#include <iostream>
#include <cstring>
#include "value.h"

using namespace std;

Value::Value(char* newvalue) {
  value = newvalue;
}

Value::~Value() {
  delete &value;
}

char* Value::getValue(){
  return value;
}
