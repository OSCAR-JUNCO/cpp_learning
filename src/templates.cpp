#include "templates.h"

template <typename T>
T sum(const T& a, const T& b) {
    if constexpr(std::is_same<T, bool>::value) {
        std::cout << "Unsupported type!" << std::endl;
    } else if constexpr(std::is_arithmetic<T>::value) {
        // If it's real number
        return a + b;
    } else if constexpr(std::is_same<T, std::string>::value) {
        // If it's string
        return a + " " + b;
    }
    return a;
}

template int sum<int>(const int& a, const int& b);
template std::string sum<std::string>(const std::string& a, const std::string& b);
template bool sum<bool>(const bool& a, const bool& b);