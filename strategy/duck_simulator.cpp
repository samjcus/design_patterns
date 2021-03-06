// A better duck simulator. Behaviours are inherited
// and can be changed at runtime

#include <iostream>
using namespace std;

class FlyBehaviour {
  // abstract class (interface in java-speak)
public:
  virtual void fly() = 0;
  virtual ~FlyBehaviour(){}
};

class FlyWithWings: public FlyBehaviour {
public:
  void fly() {
    cout << "up up and away, I'm flying" << endl;
  }
};

class FlyNoWay: public FlyBehaviour {
public:
  void fly() {
    cout << "sorry guys, I'm grounded" << endl;
  }
};

class QuackBehaviour {
  // abstract class (interface in java-speak)
public:
  virtual void quack() = 0;
  virtual ~QuackBehaviour() {}
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
    delete flybehaviour;
    flybehaviour = input;
  }
  void setQuackBehaviour(QuackBehaviour *input)
  {
    delete quackbehaviour;
    quackbehaviour = input;
  }
  // OTHER duck-like methods
  virtual ~Duck()
  {
    delete flybehaviour;
    delete quackbehaviour;
  }
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
  Duck *bruce = new MallardDuck();
  QuackBehaviour *overridequack = new Squeak();
  FlyBehaviour *overridefly = new FlyNoWay();
  bruce->performQuack();
  bruce->performFly();
  bruce->setQuackBehaviour(overridequack);
  bruce->setFlyBehaviour(overridefly);
  bruce->performQuack();
  bruce->performFly();
  delete bruce;
  return 0;
}
