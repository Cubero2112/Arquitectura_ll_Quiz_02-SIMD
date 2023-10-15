#include <iostream>

int main() {
    std::cout << "Size of bool: " << sizeof(bool) << " bytes" << std::endl;
    std::cout << "Size of char: " << sizeof(char) << " bytes" << std::endl;
    std::cout << "Size of short: " << sizeof(short) << " bytes" << std::endl;
    std::cout << "Size of int: " << sizeof(int) << " bytes" << std::endl;
    std::cout << "Size of long: " << sizeof(long) << " bytes" << std::endl;
    std::cout << "Size of long long: " << sizeof(long long) << " bytes" << std::endl;
    std::cout << "Size of float: " << sizeof(float) << " bytes" << std::endl;
    std::cout << "Size of double: " << sizeof(double) << " bytes" << std::endl;
    std::cout << "Size of long double: " << sizeof(long double) << " bytes" << std::endl;
    std::cout << "Size of size_t: " << sizeof(std::size_t) << " bytes" << std::endl;
    std::cout << "Size of ptrdiff_t: " << sizeof(std::ptrdiff_t) << " bytes" << std::endl;
    std::cout << "Size of void*: " << sizeof(void*) << " bytes" << std::endl;
    std::cout << "Size of wchar_t: " << sizeof(wchar_t) << " bytes" << std::endl;

    return 0;
}
