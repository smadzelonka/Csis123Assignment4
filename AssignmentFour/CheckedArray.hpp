#ifndef CheckedArray_hpp
#define CheckedArray_hpp

#include <vector>
#include <string>

namespace Sean {

class CheckedArrayException: public std::exception {
private:
    std::string message;
public:
    CheckedArrayException(const std::string& msg): message(msg) {}
    CheckedArrayException(): CheckedArrayException("Checked Array Error") {}
    virtual const char* what() const noexcept override {
        return message.c_str();
    }
};

template <class T>
class CheckedArray {
protected:
    std::vector<T> bits;
    
public:
    CheckedArray(size_t size);
    CheckedArray(const std::vector<T>& bits);
    
    bool inBounds(int index) const;
    T& at(int index);
    const T& at(int index) const;
    T& operator[](int index);
    const T& operator[](int index) const;
    virtual std::string toString() const;
};

template <class T>
CheckedArray<T>::CheckedArray(size_t size) {
    try {
        bits.resize(size);
    }
    catch(const std::bad_alloc& e) {
        throw CheckedArrayException("Unable to allocate memory");
    }
}

template <class T>
CheckedArray<T>::CheckedArray(const std::vector<T>& bits) : bits(bits) {}

template <class T>
bool CheckedArray<T>::inBounds(int index) const {
    return index >= 0 && index < static_cast<int>(bits.size());
}

template <class T>
T& CheckedArray<T>::at(int index) {
    if (!inBounds(index)) {
        throw CheckedArrayException("Index out of bounds");
    }
    return bits[index];
}

template <class T>
const T& CheckedArray<T>::at(int index) const {
    if (!inBounds(index)) {
        throw CheckedArrayException("Index out of bounds");
    }
    return bits[index];
}

template <class T>
T& CheckedArray<T>::operator[](int index) {
    return at(index);
}

template <class T>
const T& CheckedArray<T>::operator[](int index) const {
    return at(index);
}

template <class T>
std::string CheckedArray<T>::toString() const {
    std::string result = "";
    for (size_t i = 0; i < bits.size(); i++) {
        result += bits[i] ? "1" : "0";
    }
    return result;
}
}

#endif /* CheckedArray_hpp */
