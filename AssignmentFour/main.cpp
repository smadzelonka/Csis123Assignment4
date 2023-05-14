//
//  main.cpp
//  Assignment 12
//  ID 0266099
//  Created by Sean Madzelonka on 5/05/23.
//
#include <iostream>
#include "Byte.hpp"

int main() {
    try {
        Sean::Byte myByte(0b11010101); // Initialize a Byte with a binary value

        // Accessing and modifying bits
        std::cout << "Initial value: " << myByte.toString() << std::endl;
        myByte[0] = 1; // Set the first bit to 1
        std::cout << "After setting the first bit to 1: " << myByte.toString() << std::endl;

        // Perform some operation on the Byte, for example, adding two Byte objects
        Sean::Byte anotherByte(0b00110011);
        Sean::Byte sumByte = myByte + anotherByte;
        std::cout << "Sum of the two Byte objects: " << sumByte.toString() << std::endl;
        
        // Now, try to access an out-of-bounds index
                std::cout << "Accessing out-of-bounds index: " << myByte[10] << std::endl;
    } catch (const Sean::CheckedArrayException& e) {
        std::cout << "Caught an exception: " << e.what() << std::endl;
    }
    

    return 0;
}
