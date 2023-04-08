//
//  Byte.cpp
//  AssignmentFour
//
//  Created by Sean Madzelonka on 4/7/23.
//

#include "Byte.hpp"

Byte::Byte() : Byte(0) {}

Byte::Byte(int val) {
    bits.resize(8, false);

    int i = 7;
    while (val > 0 && i >= 0) {
        bits[i] = val % 2;
        val /= 2;
        i--;
    }
}

Byte::Byte(const std::vector<int>& ar) {
    bits.resize(8, false);

    for (int i = 0; i < 8 && i < ar.size() && ar[i] >= 0 && ar[i] <= 1; i++) {
        bits[i] = ar[i];
    }
}

Byte Byte::add(int val) {
    int result = toInt() + val;
    return Byte(result);
}

Byte Byte::sub(int val) {
    int result = toInt() - val;
    return Byte(result);
}

Byte Byte::mul(int val) {
    int result = toInt() * val;
    return Byte(result);
}

Byte Byte::div(int val) {
    int result = toInt() / val;
    return Byte(result);
}

int Byte::toInt() {
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

std::string Byte::toString() {
    std::string result = "";
    for (int i = 0; i < 8; i++) {
        result += bits[i] ? "1" : "0";
    }
    return result;
}
