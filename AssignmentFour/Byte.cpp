//
//  Byte.cpp
//  AssignmentFour
//
//  Created by Sean Madzelonka on 4/7/23.
//

#include "Byte.hpp"

Byte::Byte() : bits(8) {
    // Set all bits to 0 initially
    for (int i = 0; i < 8; i++) {
        bits[i] = false;
    }
}

Byte::Byte(int val) : bits(8) {
    // Set all bits to 0 initially
    for (int i = 0; i < 8; i++) {
        bits[i] = false;
    }

    // Convert the value to binary and store it in bits
    int i = 7;
    while (val > 0 && i >= 0) {
        bits[i] = val % 2;
        val /= 2;
        i--;
    }
}

Byte::Byte(int ar[]) : bits(8) {
    // Set all bits to 0 initially
    for (int i = 0; i < 8; i++) {
        bits[i] = false;
    }

    // Set the bits according to the values in the array
    for (int i = 0; i < 8 && ar[i] >= 0 && ar[i] <= 1; i++) {
        bits[i] = ar[i];
    }
}

Byte::Byte(const Byte& other) : bits(other.bits) {}

Byte Byte::add(const Byte& other) const {
    int result = toInt() + other.toInt();
    return Byte(result);
}

Byte Byte::sub(const Byte& other) const {
    int result = toInt() - other.toInt();
    return Byte(result);
}

Byte Byte::mul(const Byte& other) const {
    int result = toInt() * other.toInt();
    return Byte(result);
}

Byte Byte::div(const Byte& other) const {
    int result = toInt() / other.toInt();
    return Byte(result);
}

int Byte::toInt() const {
    int result = 0;
    int multiplier = 1;
    for (int i = 7; i >= 0; i--) {
        if (bits[i]) {
            result += multiplier;
        }
        multiplier *= 2;
    }
    return result;
}

std::string Byte::toString() const {
    std::string result = "";
    for (int i = 0; i < 8; i++) {
        result += bits[i] ? "1" : "0";
    }
    return result;
}
