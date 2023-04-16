////
////  main.cpp
////  Assignment 5
////  ID 0266099
////  Created by Sean Madzelonka on 4/15/23.
////
//
#include <iostream>
#include <cstdlib>
#include "Menu.hpp"
#include "Byte.hpp"

using namespace std;

void addByte();
void subByte();
void mulByte();
void divByte();
void bitByte();
void waitKey();
void Exit();

Menu m;

int main() {
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
    Byte b1(val1);

    cout << "Enter the second byte value (0-255): ";
    cin >> val2;
    Byte b2(val2);

    Byte b3 = b1.add(b2);
    cout << "Int:    " << b3.toInt() << endl;
    cout << "String: " << b3.toString() << endl;
    
    // Access individual bits
        cout << "Bit at Index 1: " << b3[1] << std::endl;

    waitKey();
}

void subByte() {
    int val1, val2;
    cout << "Enter the first byte value (0-255): ";
    cin >> val1;
    Byte b1(val1);

    cout << "Enter the second byte value (0-255): ";
    cin >> val2;
    Byte b2(val2);

    Byte b3 = b1.sub(b2);
    cout << "Int:    " << b3.toInt() << endl;
    cout << "String: " << b3.toString() << endl;
    
    cout << "Bit at Index 1: " << b3[1] << std::endl;

    waitKey();
}

void mulByte() {
    int val1, val2;
    cout << "Enter the first byte value (0-255): ";
    cin >> val1;
    Byte b1(val1);

    cout << "Enter the second byte value (0-255): ";
    cin >> val2;
    Byte b2(val2);

    Byte b3 = b1.mul(b2);
    cout << "Int:    " << b3.toInt() << endl;
    cout << "String: " << b3.toString() << endl;

    
    cout << "Bit at Index 1: " << b3[1] << std::endl;
    waitKey();
}

void divByte() {
    int val1, val2;
    cout << "Enter the first byte value (0-255): ";
    cin >> val1;
    Byte b1(val1);

    cout << "Enter the second byte value (0-255): ";
    cin >> val2;
    Byte b2(val2);

    Byte b3 = b1.div(b2);
    cout << "Int:    " << b3.toInt() << endl;
    cout << "String: " << b3.toString() << endl;
    
    cout << "Bit at Index 1: " << b3[1] << std::endl;

    waitKey();
}

void bitByte() {
    int val, bit;
    cout << "Enter the byte value (0-255): ";
    cin >> val;
    Byte b(val);

    cout << "Enter the bit index (0-7): ";
    cin >> bit;

    cout << "Bit value: " << b[bit] << endl;
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
