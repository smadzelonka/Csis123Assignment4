//
//  Byte.hpp
//  AssignmentFour
//
//  Created by Sean Madzelonka on 4/7/23.
//

#ifndef Byte_hpp
#define Byte_hpp

#include <iostream>
#include <string>
#include <vector>

class Byte {
private:
    std::vector<bool> bits;

public:
    Byte();
    Byte(int val);
    Byte(const std::vector<int>& ar);
    Byte add(const Byte& other);
    Byte sub(const Byte& other);
    Byte mul(const Byte& other);
    Byte div(const Byte& other);
    int toInt() const;
    std::string toString() const;
};

#endif /* Byte_hpp */
