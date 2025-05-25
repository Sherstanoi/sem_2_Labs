#include "lab6.hpp"

int main() {
  while(ContinueFlag) {
    Polynomial FirstPolynom;
    std::cout << "Введите первый полином, пожалуйста: " << std::endl;
    std::cin >> FirstPolynom;
    std::cout << "Вот он: " << FirstPolynom << std::endl;
    Polynomial SecondPolynom;
    SecondPolynom = FirstPolynom;
    std::cout << "Второй полином, приравненный к первому: " << SecondPolynom << std::endl;
    Polynomial ThirdPolynom;
    std::cout << "Введите третий полином, пожалуйста: " << std::endl;
    std::cin >> ThirdPolynom;
    std::cout << "Вот он: " << ThirdPolynom << std::endl;
    ThirdPolynom *= FirstPolynom;
    std::cout << "Третий полином *= первый полином " << ThirdPolynom << std::endl;
    ThirdPolynom += FirstPolynom;
    std::cout << "Новый третий полином += первый полином " << ThirdPolynom << std::endl;
    ThirdPolynom.SortPolynomial(true);
    std::cout << "Сортировка третьего по возрастанию: " << ThirdPolynom << std::endl;
    ThirdPolynom.SortPolynomial(false);
    std::cout << "Сортировка третьего по убыванию: " << ThirdPolynom << std::endl;
    std::cout<< "продолжить? 1/0 ";
    // std::cin>>Choice;
    // if (Choice == 0) {
    //   ContinueFlag = false;
    // }
    // std::cin.clear();
  }
  return 0;
}
