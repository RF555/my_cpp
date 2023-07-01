#include <iostream>
using namespace std;

class A;

class B {
public:
  explicit B(A &o) { cout << "B(A)" << endl; }
};

class A {
public:
  A() { cout << "A()" << endl; }
};

void printit(B arg) {}

int main() {
  A a;
  B b(a);
  printit(b);
  return 0;
}