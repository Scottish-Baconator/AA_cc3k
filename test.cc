
#include <iostream>

class Enemy{
  int val;
public:
  Enemy(int h):val{h}{}
  int getVal(){return val;}
};

class Dwarf : public Enemy{
public:
  Dwarf(int h):Enemy{h}{}
};

class Human : public Enemy{
public:
  Human(int h):Enemy{h}{}
};

class Player {

public:
  virtual int attackEffect(Enemy *other)=0;
  virtual int attack(Enemy *other){
    return other->getVal()*attackEffect(other);
  }
  ~Player(){};
};

class Vampire : public Player {

public:
  
  int drainEffect(Dwarf other){
    return -1;
  }

  int drainEffect(Human other){
    return 10;
  }
  
 // int attackEffect(Enemy other) override{
  //  return drainEffect(other);
  //}

};

int main(){

  Player *p = new Vampire();
  
  Enemy *e1 = new Dwarf(5);
  Enemy *e2 = new Human(10);

  std::cout << p->attack(e1) << std::endl;
  std::cout << p->attack(e2) << std::endl;  
}
