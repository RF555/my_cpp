#include <iostream>
#include <string>

class string{
  const char* p;
public:
  string(const char* p){this->p=p;}
};

int main() {
  string s="abc";
}