#include <iostream>
#include "mymath/mymath.h"

int main() {
    setlocale(LC_ALL, "Russian");
    std::cout << "Я умею возводить факториалы! смотри 34! ";
    std::cout << mymath::factorial(10) << std::endl;

    return 0;
}
