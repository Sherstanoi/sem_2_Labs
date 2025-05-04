#include "Stack.hpp"

void Functions::StartProgramm() {
    int Choice;
    bool Flag = true;
    while(Flag) {
        std::cout<< "Что бы вы хотели сделать? \n1. Разложить число по множетелям \n2. Разложить два СТека и сложить их\n3. Закончить выполнение программы \n";
        std::cin>>Choice;
        if(Choice == 1){
            char InputNumber[100] = {};
            std::cout << "Введите целое число, пожалуйста:" << std::endl; //ПРОВЕРКУ НА ЕДИНИЦУ?
            std::cout<<std::endl;
            std::cin >> InputNumber;
            if(std::atoi(InputNumber) <= 0) {
                std::cout<<"Введены некорректные данные " << "\n" << std::endl;
            } else if(atoi(InputNumber) == 1) {
                std::cout << "1 = 1" << "\n" << "1 = 1" << "\n" << std::endl;
            } else {
            Stack<int> Stack;
            FindDeviders(atoi(InputNumber), Stack);
            Stack<int> AnotherStack = Stack;
            FlipTheStack(AnotherStack);
            PrintTheStack(Stack, atoi(InputNumber));
            PrintTheStack(AnotherStack, atoi(InputNumber));
            std::cout << std::endl;
        }
        } else if(Choice == 2) {
            char FirstInputNumber[100] = {};
            char SecondInputNumber[100] = {};
            Stack<int> FirstStack;
            Stack<int> SecondStack;
            std::cout << "Введите целое число A, пожалуйста:" << std::endl;
            std::cin >> FirstInputNumber;
            std::cout << "Введите целое число Б, пожалуйста:" <<  std::endl;
            std::cin >> SecondInputNumber;
            std::cout << "\n";
            if(std::atoi(FirstInputNumber) <= 0 || std::atoi(SecondInputNumber) <= 0) {
                std::cout<<"Введены некорректные данные " << "\n" << std::endl;
            } else if(atoi(FirstInputNumber) == 1) {
                std::cout << "1 = 1" << "\n" << "1 = 1" << "\n" << std::endl;
            } else {
            FindDeviders(atoi(FirstInputNumber), FirstStack);
            Stack<int> AnotherStack = FirstStack;
            FlipTheStack(AnotherStack);
            PrintTheStack(FirstStack, atoi(FirstInputNumber));
            PrintTheStack(AnotherStack, atoi(FirstInputNumber));
            std::cout<<std::endl;
            }
            if(atoi(SecondInputNumber) == 1) {
                std::cout << "1 = 1" << "\n" << "1 = 1" << "\n" << std::endl;
            } else {
            FindDeviders(atoi(SecondInputNumber), SecondStack);
            Stack<int> AnotherSecondStack = SecondStack;
            FlipTheStack(AnotherSecondStack);
            PrintTheStack(SecondStack, atoi(SecondInputNumber));
            PrintTheStack(AnotherSecondStack, atoi(SecondInputNumber));
            std::cout<<std::endl;
            }
            Stack<int> ThirdStack = FirstStack + SecondStack;
            PrintTheSumStack(ThirdStack);
        } else if(Choice == 3) {
            Flag = false;
        } else {
        std::cout<<"Введены некорректные данные" << "\n" << std::endl;
        }
    }
    return;
}
