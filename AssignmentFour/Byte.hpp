//
//  Byte.hpp
//  AssignmentFour
//
//  Created by Sean Madzelonka on 4/7/23.
//

#ifndef Byte_hpp
#define Byte_hpp

#include <vector>
#include <string>

namespace Sean {
    

    class Byte {
    private:
        std::vector<bool> bits;

    public:
        Byte();
        Byte(int val);
        Byte(int ar[]);
        Byte(const Byte& other);
        Byte& operator=(const Byte& other);
        Byte(Byte&& other) noexcept;
        Byte& operator=(Byte&& other) noexcept;
        Byte* add(const Byte& other) const;
        Byte* sub(const Byte& other) const;
        Byte* mul(const Byte& other) const;
        Byte* div(const Byte& other) const;
        int toInt() const;
        std::string toString() const;
        bool operator==(const Byte& other) const;
        bool operator!=(const Byte& other) const;
        Byte* operator+(const Byte& other) const;
        Byte* operator-(const Byte& other) const;
        Byte* operator*(const Byte& other) const;
        Byte* operator/(const Byte& other) const;
        std::vector<bool>::const_reference operator[](int index) const;
        std::vector<bool>::reference operator[](int index);
    };
}

#endif /* Byte_hpp */
