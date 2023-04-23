//
//  main.cpp
//  Assignment 8
//  ID 0266099
//  Created by Sean Madzelonka on 4/23/23.
//
#include <iostream>
#include <cstdlib>
#include "Menu.hpp"
#include "Byte.hpp"


using namespace std;
using namespace Sean;

void addByte();
void subByte();
void mulByte();
void divByte();
void bitByte();
void waitKey();
void Exit();


int main() {
    Menu& m = Menu::getInstance();
    m.addMenu("1. Add Bytes", addByte);
    m.addMenu("2. Subtract Bytes", subByte);
    m.addMenu("3. Multiply Bytes", mulByte);
    m.addMenu("4. Divide Bytes", divByte);
    m.addMenu("5. Test Bit Value", bitByte);
    m.addMenu("6. Exit", Exit);
    m.runMenu();
}

void addByte() {
    int val1, val2;
    cout << "Enter the first byte value (0-255): ";
    cin >> val1;
    Byte* b1 = new Byte(val1);
    
    cout << "Enter the second byte value (0-255): ";
    cin >> val2;
    Byte* b2 = new Byte(val2);
    
    if (!b1 || !b2) {
        cout << "Unable to allocate memory for Byte object" << endl;
        waitKey();
        return;
    }
    
    Byte* b3 = b1->operator+(*b2);
    if (!b3) {
        cout << "Unable to allocate memory for Byte object" << endl;
        waitKey();
        delete b1;
        delete b2;
        return;
    }
    
    cout << "Int:    " << b3->toInt() << endl;
    cout << "String: " << b3->toString() << endl;
    cout << "Bit at Index 1: " << (*b3)[1] << std::endl;
    
    delete b1;
    delete b2;
    delete b3;
    
    waitKey();
}

void subByte() {
    int val1, val2;
    cout << "Enter the first byte value (0-255): ";
    cin >> val1;
    Byte* b1 = new Byte(val1);
    
    cout << "Enter the second byte value (0-255): ";
    cin >> val2;
    Byte* b2 = new Byte(val2);
    
    if (!b1 || !b2) {
        cout << "Unable to allocate memory for Byte object" << endl;
        waitKey();
        return;
    }
    
    Byte* b3 = b1->operator-(*b2);
    if (!b3) {
        cout << "Unable to allocate memory for Byte object" << endl;
        waitKey();
        delete b1;
        delete b2;
        return;
    }
    cout << "Int:    " << b3->toInt() << endl;
    cout << "String: " << b3->toString() << endl;
    cout << "Bit at Index 1: " << (*b3)[1] << std::endl;
    
    delete b1;
    delete b2;
    delete b3;
    
    waitKey();
}

void mulByte() {
    int val1, val2;
    cout << "Enter the first byte value (0-255): ";
    cin >> val1;
    Byte* b1 = new Byte(val1);
    
    cout << "Enter the second byte value (0-255): ";
    cin >> val2;
    Byte* b2 = new Byte(val2);
    
    if (!b1 || !b2) {
        cout << "Unable to allocate memory for Byte object" << endl;
        waitKey();
        return;
    }
    
    Byte* b3 = b1->operator*(*b2);
    if (!b3) {
        cout << "Unable to allocate memory for Byte object" << endl;
        waitKey();
        delete b1;
        delete b2;
        return;
    }
    cout << "Int:    " << b3->toInt() << endl;
    cout << "String: " << b3->toString() << endl;
    cout << "Bit at Index 1: " << (*b3)[1] << std::endl;
    
    delete b1;
    delete b2;
    delete b3;
    
    waitKey();
}

void divByte() {
    int val1, val2;
    cout << "Enter the first byte value (0-255): ";
    cin >> val1;
    Byte* b1 = new Byte(val1);
    
    cout << "Enter the second byte value (0-255): ";
    cin >> val2;
    Byte* b2 = new Byte(val2);
    
    if (!b1 || !b2) {
        cout << "Unable to allocate memory for Byte object" << endl;
        waitKey();
        return;
    }
    
    if (b2->toInt() == 0) {
        cout << "Division by zero is not allowed" << endl;
        waitKey();
        return;
    }
    
    Byte* b3 = b1->operator/(*b2);
    if (!b3) {
        cout << "Unable to allocate memory for Byte object" << endl;
        waitKey();
        delete b1;
        delete b2;
        return;
    }
    cout << "Int:    " << b3->toInt() << endl;
    cout << "String: " << b3->toString() << endl;
    cout << "Bit at Index 1: " << (*b3)[1] << endl;
    
    delete b1;
    delete b2;
    delete b3;
    
    waitKey();
}

void bitByte() {
    int val, bit;
    cout << "Enter the byte value (0-255): ";
    cin >> val;
    Byte* b = new Byte(val);
    
    cout << "Enter the bit index (0-7): ";
    cin >> bit;
    
    cout << "Bit value: " << (*b)[bit] << endl;
    delete b;
    waitKey();
}

void waitKey() {
    cout << "Press any key to continue...";
    cin.ignore();
    cin.get();
}

void Exit() {
    cout << "Goodbye!" << endl;
    exit(0);
}
