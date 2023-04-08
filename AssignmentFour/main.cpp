//
//  main.cpp
//  Assignment 4
//  ID 0266099
//  Created by Sean Madzelonka on 4/7/23.
//

#include <iostream>
#include "Byte.hpp"

void  Addition();
void  Subtraction();
void  Multiplication();
void  Division();
void exitProgram();

int main() {
    int choice;

    do {
        std::cout << "Byte Calculator\n";
        std::cout << "1.   Addition\n";
        std::cout << "2.   Subtraction\n";
        std::cout << "3.   Multiplication\n";
        std::cout << "4.   Division\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                 Addition();
                break;
            case 2:
                 Subtraction();
                break;
            case 3:
                 Multiplication();
                break;
            case 4:
                 Division();
                break;
            case 5:
                exitProgram();
                break;
            default:
                std::cout << "Press any key to continue..." << std::endl;
                std::cin.get();
        }
    } while (choice != 5);

    return 0;
}

void  Addition() {
    int a, b;
    std::cout << "Enter two integers for addition: ";
    std::cin >> a >> b;

    Byte byteA(a);
    Byte byteB(b);
    Byte result = byteA.add(byteB);

    std::cout << "Result: " << result.toInt() << " (" << result.toString() << ")\n";
}

void  Subtraction() {
    int a, b;
    std::cout << "Enter two integers for subtraction: ";
    std::cin >> a >> b;

    Byte byteA(a);
    Byte byteB(b);
    Byte result = byteA.sub(byteB);

    std::cout << "Result: " << result.toInt() << " (" << result.toString() << ")\n";
}

void  Multiplication() {
    int a, b;
    std::cout << "Enter two integers for multiplication: ";
    std::cin >> a >> b;

    Byte byteA(a);
    Byte byteB(b);
    Byte result = byteA.mul(byteB);

    std::cout << "Result: " << result.toInt() << " (" << result.toString() << ")\n";
}

void  Division() {
    int a, b;
    std::cout << "Enter two integers for division: ";
    std::cin >> a >> b;

    if (b == 0) {
        std::cout << "Error: Division by zero is not allowed.\n";
        return;
    }

    Byte byteA(a);
    Byte byteB(b);
    Byte result = byteA.div(byteB);

    std::cout << "Result: " << result.toInt() << " (" << result.toString() << ")\n";
}

void exitProgram() {
    std::cout << "Exiting the program...\n";
}
