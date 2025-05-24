#include "lab8.hpp"

int main() {
    std::cout<<"Какое задание вы хотели бы выполнить? \n1)Задача 1\n2)Задача 2\n3)Задача 3\n4)Задача 4\n5)Задача 5\n6)Задача 6\n7)Задача 7\n8)Задача 8\n9)Задача 9\n";
    std::cin>>Choice;
    switch (Choice)
    {
    case 1:
        Task1();
        break;
    case 2:
        Task2();
        break;
    case 3:
        Task3();
        break;
    case 4:
        Task4();
        break;
    case 5:
        //Task5();
        break;
    case 6:
        Task6();
        break;
    case 7:
        //Task7();
        break;
    case 8:
        Task8();
        break;
    case 9:
        Task9();
        break;
    default:
        std::cout<<"Введены неправильные данные";
        break;
    }
    return 0;
}
