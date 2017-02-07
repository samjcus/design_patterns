// A better duck simulator. Behaviours are inherited
// and can be changed at runtime

#include <iostream>
using namespace std;

class FlyBehaviour {
  // abstract class (interface in java-speak)
public:
  virtual void fly() = 0;
};

class FlyWithWings: public FlyBehaviour {
public:
  void fly() {
    cout << "up up and away, I'm flying" << endl;
  }
};

class FlyNoWay: public FlyBehaviour {
public:
  // override to do nothing
  void fly() {}
};

class QuackBehaviour {
  // abstract class (interface in java-speak)
public:
  virtual void quack() = 0;
};

class Quack: public QuackBehaviour {
public:
  void quack() {
    cout << "Quack, Quack" << endl;
  }
};

class Squeak: public QuackBehaviour {
public:
  void quack() {
    cout << "Squeak, Squeak" << endl;
  }
};

class MuteQuack: public QuackBehaviour {
public:
  void quack() {}
};

class Duck {
  // Duck base class
public:
  void swim() {
    cout << "swimming, swimming in a swimming pool" << endl;
  }
  void display() {
    cout << "I'm a duck yo" << endl;
  }
  void performQuack()
  {
    quackbehaviour->quack();
  }
  void performFly()
  {
    flybehaviour->fly();
  }
  void setFlyBehaviour(FlyBehaviour *input)
  {
    flybehaviour = input;
  }
  void setQuackBehaviour(QuackBehaviour *input)
  {
    quackbehaviour = input;
  }
  // OTHER duck-like methods
protected:
  QuackBehaviour *quackbehaviour;
  FlyBehaviour *flybehaviour;
};

class MallardDuck: public Duck{
public:
  MallardDuck(){
    quackbehaviour = new Quack();
    flybehaviour = new FlyWithWings();
  }  
};
  
int main(void){
  MallardDuck bruce;
  Squeak overridequack;
  FlyNoWay overridefly;
  bruce.performQuack();
  bruce.performFly();
  bruce.setQuackBehaviour(&overridequack);
  bruce.setFlyBehaviour(&overridefly);
  bruce.performQuack();
  // no output here - fly has been overriden
  bruce.performFly();
  return 0;
}
