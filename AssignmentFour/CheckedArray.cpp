//#include "CheckedArray.hpp"
//#include <stdexcept>
//
//namespace Sean {
//
//CheckedArray::CheckedArray(size_t size) {
//    try {
//        bits.resize(size);
//    }
//    catch(const std::bad_alloc& e) {
//        throw CheckedArrayException("Unable to allocate memory");
//    }
//}
//
//CheckedArray::CheckedArray(const std::vector<int>& bits) : bits(bits) {}
//
//bool CheckedArray::inBounds(int index) const {
//    return index >= 0 && index < static_cast<int>(bits.size());
//}
//
//int& CheckedArray::at(int index) {
//    if (!inBounds(index)) {
//        throw CheckedArrayException("Index out of bounds");
//    }
//    return bits[index];
//}
//
//
//const int& CheckedArray::at(int index) const {
//    if (!inBounds(index)) {
//        throw std::out_of_range("Index out of bounds");
//    }
//    return bits[index];
//}
//
//int& CheckedArray::operator[](int index) {
//    return at(index);
//}
//
//const int& CheckedArray::operator[](int index) const {
//    return at(index);
//}
//
//std::string CheckedArray::toString() const {
//    std::string result = "";
//    for (size_t i = 0; i < bits.size(); i++) {
//        result += bits[i] ? "1" : "0";
//    }
//    return result;
//}
//}
