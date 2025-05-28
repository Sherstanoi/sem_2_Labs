#include "lab6.hpp"

int main() {
    bool ContinueFlag = true;
    while(ContinueFlag) {
        std::cout<< "Что бы вы хотели сделать: \n1)вывести любой полином\n2)сложить два полинома\n3)вычесть два полинома\n4)перемножить два полинома\n5)закончить выполнение программы: ";
        int Choice = 0;
        std::cin >> Choice;
        switch (Choice)
        {
        case 1: {
            Polynomial p1;
            std::cin >> p1;
            std::cout << "Введите первый многочлен: ";
            std::cin >> p1;
            std::cout << "Первый: " << p1 << "\n";
            break;
        }
        case 2: {
            Polynomial p1;
            Polynomial p2;
            std::cin >> p1;
            std::cout << "Введите первый многочлен: ";
            std::cin >> p1;
            std::cout << "Введите второй многочлен: ";
            std::cin >> p2;
            Polynomial sum = p1 + p2;
            std::cout << "Сумма: " << sum << "\n";
            break;
        }
        case 3: {
            Polynomial p1;
            Polynomial p2;
            std::cin >> p1;
            std::cout << "Введите первый многочлен: ";
            std::cin >> p1;
            std::cout << "Введите второй многочлен: ";
            std::cin >> p2;
            Polynomial raz = p1 - p2;
            std::cout << "Разность: " << raz << "\n";
            break;
        }
        case 4: {
            Polynomial p1;
            Polynomial p2;
            std::cin >> p1;
            std::cout << "Введите первый многочлен: ";
            std::cin >> p1;
            std::cout << "Введите второй многочлен: ";
            std::cin >> p2;
            Polynomial prod = p1 * p2;
            std::cout << "Произведение: " << prod << "\n";
            break;
        }
        case 5: {
            ContinueFlag = false;
            break;
        }
        default:
            std::cout<<"Введены некорректные данные";
            break;
        }
}
    return 0;
}
