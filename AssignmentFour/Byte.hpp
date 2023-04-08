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
    Byte add(int val);
    Byte sub(int val);
    Byte mul(int val);
    Byte div(int val);
    int toInt();
    std::string toString();
};



#endif /* Byte_hpp */
