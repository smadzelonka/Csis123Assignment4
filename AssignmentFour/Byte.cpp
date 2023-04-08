//
//  Byte.cpp
//  AssignmentFour
//
//  Created by Sean Madzelonka on 4/7/23.
//

#include "Byte.hpp"

Byte::Byte() : Byte(0) {}

Byte::Byte(int val) : bits(8) {
    int i = 7;
    while (val > 0 && i >= 0) {
        bits[i] = val % 2;
        val /= 2;
        i--;
    }
}

Byte::Byte(const std::vector<int>& ar) : bits(8) {
    for (int i = 0; i < 8 && i < ar.size(); i++) {
        bits[i] = ar[i] == 1;
    }
}

Byte Byte::add(const Byte& other) {
    int result = this->toInt() + other.toInt();
    return Byte(result);
}

Byte Byte::sub(const Byte& other) {
    int result = this->toInt() - other.toInt();
    return Byte(result);
}

Byte Byte::mul(const Byte& other) {
    int result = this->toInt() * other.toInt();
    return Byte(result);
}

Byte Byte::div(const Byte& other) {
    int result = this->toInt() / other.toInt();
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
