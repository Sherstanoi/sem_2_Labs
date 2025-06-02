#include "lab8.hpp"

int main() {
    while(Flag){
        std::cout<<"Какое задание вы хотели бы выполнить?\nВведите номе задания от 1 до 9(чтобы выйти напишите 10): ";
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
            Task5();
            break;
        case 6:
            Task6();
            break;
        case 7:
            Task7();
            break;
        case 8:
            Task8();
            break;
        case 9:
            Task9();
            break;
        case 10:
            Flag = false;
            break;
        default:
            std::cout<<"Введены неправильные данные";
            break;
        }
}
    return 0;
}
