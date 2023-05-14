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

    class CheckedArray {
    protected:
        std::vector<int> bits;

    public:
        CheckedArray(size_t size);
        CheckedArray(const std::vector<int>& bits);

        bool inBounds(int index) const;
        int& at(int index);
        const int& at(int index) const;
        int& operator[](int index);
        const int& operator[](int index) const;
        virtual std::string toString() const;
    };
}

#endif /* CheckedArray_hpp */
