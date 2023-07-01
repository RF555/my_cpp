#include <iostream>

using namespace std;

class Shape{
public:
  virtual void draw()=0;
  virtual ~Shape(){cout<<"~Shape()"<<endl;}
};


class Circle:public Shape{
public:
  void draw(){cout<<"Circle::draw()"<<endl;}
  ~Circle(){cout<<"~Circle()"<<endl;}
};


void drawTheShape(Shape& s){
  s.draw();
}

int main() {
  Circle c;
  drawTheShape(c);
  return 0;
}