#include "lab6.hpp"

int main() {
  Term FirstTerm;
  std::cout << "Введите первый элемент, пожалуйста: " << std::endl;
  std::cin >> FirstTerm;
  std::cout << "Вот он: " << FirstTerm << std::endl;
  Term SecondTerm;
  std::cout << "Введите второй элемент, пожалуйста: " << std::endl;
  std::cin >> SecondTerm;
  std::cout << "А вот это уже он: " << SecondTerm << std::endl;
  Term SumOfTerms;
  SumOfTerms = FirstTerm + SecondTerm;
  std::cout << "Их сумма: " << SumOfTerms << std::endl;

  Polynomial FirstPolynom;
  std::cout << "Введите первый полином, пожалуйста: " << std::endl;
  std::cin >> FirstPolynom;
  std::cout << "Вот он: " << FirstPolynom << std::endl;
  Polynomial SecondPolynom;
  SecondPolynom = FirstPolynom;
  std::cout << "Другой полином, равный первому: " << SecondPolynom << std::endl;
  Polynomial ThirdPolynom;
  std::cout << "Введите третий полином, пожалуйста: " << std::endl;
  std::cin >> ThirdPolynom;
  std::cout << "Вот он: " << ThirdPolynom << std::endl;
  ThirdPolynom *= FirstPolynom;
  std::cout << "Третий полином *= первый полином " << ThirdPolynom << std::endl;
  ThirdPolynom += FirstPolynom;
  std::cout << "Третий полином += первый полином " << ThirdPolynom << std::endl;
  ThirdPolynom.SortPolynomial(true);
  std::cout << "Сортировка третьего по возрастанию: " << ThirdPolynom << std::endl;
  ThirdPolynom.SortPolynomial(false);
  std::cout << "Сортировка третьего по убыванию: " << ThirdPolynom << std::endl;

  return 0;
}
