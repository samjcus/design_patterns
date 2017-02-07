// A naive SimUDuck class heirarchy.

// This scheme does not cope well with changing requirements. For
// example, the RubberDuck does not fly so it's method must be
// explicitly overridden. This is potentially error prone and does
// not scale well to many variants of the parent class (many differnt
// types of duck).

// This is an example of programming to implementation rather than
// programming to an interface

#include <iostream>
using namespace std;

class Duck{
public:
  void quack() {
    cout << "quack!" << endl;
  }
  void swim() {
    cout << "swimming, swimming in a swimming pool" << endl;
  }
  void display() {
    cout << "I'm a duck yo" << endl;
  }
  void fly() {
    cout << "up up and away, I'm flying" << endl;
  }
};

class MallardDuck: public Duck{
};

class RubberDuck: public Duck{
public:
  void quack() {
    cout << "Squeak, Squeak" << endl;
  }
  void display() {
    cout << "I look like a rubber duck in a bath" << endl;
  }
  // override to do nothing- rubber ducks are thrown, they don't fly
  void fly() {}
};

int main(void){
  cout << "here is Reggie, the Mallard Duck" << endl;
  MallardDuck reggie;  
  reggie.quack();
  reggie.swim();
  reggie.display();
  reggie.fly();

  cout << endl << "here is Paul, the Rubber Duck" <<endl;
  RubberDuck paul;
  paul.quack();
  paul.swim();
  paul.display();
  paul.fly();
  
  return 0;
}
