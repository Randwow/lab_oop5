
//
//  main.cpp
//  lab_oop5
//a)    Создать иерархии наследования: самолет, корабль - водный самолет.
//b)    Создать иерархии наследования: транспорт - самолет, корабль - водный самолет.

//  Created by Nikita Makeev on 10/30/20.
//

#include <iostream>
using namespace std;
 
class Transport {
public:
    Transport() {
        cout << "Constructor of the Transport\n";
    }
    virtual ~Transport() {
        cout << "Destructor of the Transport\n";
    }
 
    virtual void move(){
        cout << "I can move!\n";
    }
};
 
class Airplane : virtual public Transport {
public:
    Airplane(char) {
        cout << "Constructor of the Airplane\n";
    }
 
    ~Airplane() {
        cout << "Destructor of the Airplane\n";
    }
 
    void move() {
        cout << "I can fly!\n";
    }
};
 
class Ship : virtual public Transport {
public:
    Ship(int, double) {
        cout << "Constructor of the Ship\n";
    }
 
    ~Ship() {
        cout << "Destructor of the Ship\n";
    }
 
    void move() {
        cout << "I can ship!\n";
    }
};
 
class AirShip : public Ship, public Airplane {
public:
    AirShip(char c, int i, double d) : Ship(i, d), Airplane(c) {
        cout << "Constructor of the AirShip\n";
    }
 
    ~AirShip() {
        cout << "Destructor of the AirShip\n";
    }
 
    void move() {
        Airplane::move();
        Ship::move();
    }
};
 
int main() {
    Transport* t = new AirShip('a', 10, 11.5);
    t->move();
    delete t;
    return 0;
}

