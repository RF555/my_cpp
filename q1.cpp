#include <iostream>
using namespace std;
class A {
public:
  A() { cout << "A(0)" << endl; }
  A(const A &a) { cout << "A(1)" << endl; }
};

class B {
public:
  B() : a() { cout << "B(0)" << endl; }
  B(const B &b) { cout << "B(1)" << endl; }

private:
  A a;
};

int main() {
  B object1;
  B object2 = object1;
  return 0;
}