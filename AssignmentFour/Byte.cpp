#include "Byte.hpp"
#include <algorithm>

namespace Sean {

Byte::Byte() : CheckedArray(8) {}

Byte::Byte(int val) : CheckedArray(8) {
    try {
        for (int i = 0; i < 8; i++) {
            at(i) = false;
        }
        
        int i = 7;
        while (val > 0 && i >= 0) {
            at(i) = val % 2;
            val /= 2;
            i--;
        }
    }
    catch (const CheckedArrayException& e) {
        throw;
    }
}

Byte::Byte(int ar[]) : CheckedArray(8) {
    for (int i = 0; i < 8; i++) {
        at(i) = false;
    }
    
    for (int i = 0; i < 8 && ar[i] >= 0 && ar[i] <= 1; i++) {
        at(i) = ar[i];
    }
}

Byte::Byte(const Byte& other) : CheckedArray(other.bits.size()) {
    bits = other.bits;
}

Byte& Byte::operator=(const Byte& other) {
    if (this != &other) {
        bits = other.bits;
    }
    return *this;
}

Byte::Byte(Byte&& other) noexcept : CheckedArray(0) {
    bits.swap(other.bits);
}

Byte& Byte::operator=(Byte&& other) noexcept {
    if (this != &other) {
        bits.swap(other.bits);
    }
    return *this;
}

Byte* Byte::add(const Byte& other) const {
    int result = toInt() + other.toInt();
    return new Byte(result);
}

Byte* Byte::sub(const Byte& other) const {
    int result = toInt() - other.toInt();
    return new Byte(result);
}

Byte* Byte::mul(const Byte& other) const {
    int result = toInt() * other.toInt();
    return new Byte(result);
}

Byte* Byte::div(const Byte& other) const {
    int result = toInt() / other.toInt();
    return new Byte(result);
}

Byte Byte::operator+(const Byte& other) const {
    int result = toInt() + other.toInt();
    return Byte(result);
}

Byte Byte::operator-(const Byte& other) const {
    int result = toInt() - other.toInt();
    return Byte(result);
}

Byte Byte::operator*(const Byte& other) const {
    int result = toInt() * other.toInt();
    return Byte(result);
}

Byte Byte::operator/(const Byte& other) const {
    int result = toInt() / other.toInt();
    return Byte(result);
}

int Byte::toInt() const {
    int result = 0;
    int multiplier = 1;
    for (int i = 7; i >= 0; i--) {
        if (at(i)) {
            result += multiplier;
        }
        multiplier *= 2;
    }
    return result;
}

std::string Byte::toString() const {
    std::string result = CheckedArray::toString();
    std::reverse(result.begin(), result.end());
    return result;
}
}
