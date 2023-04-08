//
//  main.cpp
//  Assignment 4
//  ID 0266099
//  Created by Sean Madzelonka on 4/7/23.
//

// main.cpp
#include <iostream>
#include "byte.hpp"
#include "menu.hpp"

void addOperation();
void subOperation();
void mulOperation();
void divOperation();
void exitProgram();

Menu m; // create the Menu object in the global scope of main.cpp

int main() {
    m.addMenu("1. Add operation", addOperation);
    m.addMenu("2. Sub operation", subOperation);
    m.addMenu("3. Mul operation", mulOperation);
    m.addMenu("4. Div operation", divOperation);
    m.addMenu("5. Exit", exitProgram);
    m.runMenu();

    return 0;
}

void addOperation() {
    int num1, num2;
    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;

    Byte bite1(num1);
    Byte bite2(num2);
    Byte result = bite1.add(bite2.toInt());

    std::cout << "Int:    " << result.toInt() << std::endl;
    std::cout << "String: " << result.toString() << std::endl;

    m.waitKey(); // call waitKey function
}

void subOperation() {
    int num1, num2;
    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;

    Byte bite1(num1);
    Byte bite2(num2);
    Byte result = bite1.sub(bite2.toInt());

    std::cout << "Int:    " << result.toInt() << std::endl;
    std::cout << "String: " << result.toString() << std::endl;

    m.waitKey(); // call waitKey function
}

void mulOperation() {
    int num1, num2;
    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;

    Byte bite1(num1);
    Byte bite2(num2);
    Byte result = bite1.mul(bite2.toInt());

    std::cout << "Int:    " << result.toInt() << std::endl;
    std::cout << "String: " << result.toString() << std::endl;

    m.waitKey(); // call waitKey function
}

void divOperation() {
    int num1, num2;
    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;

    Byte bite1(num1);
    Byte bite2(num2);
    Byte result = bite1.div(bite2.toInt());

    std::cout << "Int:    " << result.toInt() << std::endl;
    std::cout << "String: " << result.toString() << std::endl;

    m.waitKey(); // call waitKey function
}

void exitProgram() {
    std::cout << "Goodbye!" << std::endl;
    exit(0);
}
