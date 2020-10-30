//
//  main.cpp
//  taskB
//
//  Created by Nikita Makeev on 10/30/20.
//

#include <iostream>
using namespace std;
 
class Airplane {
public:
    Airplane(char) {
        cout << "Constructor of the Airplane\n";
    }
 
    virtual ~Airplane() {
        cout << "Destructor of the Airplane\n";
    }
 
    virtual void move() {
        cout << "I can fly!\n";
    }
};
 
class Ship {
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
    Airplane * t = new AirShip('a', 10, 11.5);

    t->move();
    delete t;
    return 0;
}
