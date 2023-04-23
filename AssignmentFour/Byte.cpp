#include "Byte.hpp"

namespace Sean{

    Byte::Byte() : bits(8) {
        for (int i = 0; i < 8; i++) {
            bits[i] = false;
        }
    }

    Byte::Byte(int val) : bits(8) {
        for (int i = 0; i < 8; i++) {
            bits[i] = false;
        }

        int i = 7;
        while (val > 0 && i >= 0) {
            bits[i] = val % 2;
            val /= 2;
            i--;
        }
    }

    Byte::Byte(int ar[]) : bits(8) {
        for (int i = 0; i < 8; i++) {
            bits[i] = false;
        }

        for (int i = 0; i < 8 && ar[i] >= 0 && ar[i] <= 1; i++) {
            bits[i] = ar[i];
        }
    }

    Byte::Byte(const Byte& other) : bits(other.bits) {}

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

    Byte* Byte::operator+(const Byte& other) const {
        return add(other);
    }

    Byte* Byte::operator-(const Byte& other) const {
        return sub(other);
    }

    Byte* Byte::operator*(const Byte& other) const {
        return mul(other);
    }

    Byte* Byte::operator/(const Byte& other) const {
        return div(other);
    }

    bool Byte::operator==(const Byte& other) const {
        return bits == other.bits;
    }

    bool Byte::operator!=(const Byte& other) const {
        return !(*this == other);
    }

    std::vector<bool>::reference Byte::operator[](int index) {
        return bits[index];
    }

    std::vector<bool>::const_reference Byte::operator[](int index) const {
        return bits[index];
    }
}
