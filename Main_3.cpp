#include "Lab_3.hpp"

int main() {
  std::cout << "Здравствуйте!" << "\n";
  bool Flag = true;
  int choice = 0;
  while (Flag) {
    std::cout
        << "Какой функцией вы хотелись бы воспользоваться? \n 1. вывести и конвертировать любую дробь \n 2.Вывести то, что должно быть по тз \n 3. закончить \n";
    std::cin >> choice;
    Drob x;
    Drob y;
    switch (choice) {
    case 1: {
      std::cout << "какую дробь вы хотели бы вывести?" << std::endl;
      std::cin>>x;
      std::cout<<x;
    }
    case 2: {
      // ввод дроби с клавиатуры
      std::cout << "Введите дробь: \n";
      Drob z;
      std::cin >> z;
      std::cout << "z=" << z << std::endl;
      // проверка конструкторов
      Drob fr1(10, 14), fr2;
      std::cout << "fr2=" << fr2 << std::endl;
      std::cout << "fr1=" << fr1 << std::endl;
      Drob fr = "-1 4/8";
      std::cout << "fr=" << fr << std::endl;
      Drob x(z), y;

      std::cout << "x=" << x << std::endl;
      double dbl = -1.25;
      Drob f = dbl;
      std::cout << "f=" << f << std::endl;
      // проверка перегруженной операции
      y = x + z;
      std::cout << "y=" << y << std::endl;
      y += x;
      f += dbl / 2;
      std::cout << "f=" << f << std::endl;
      y = x + dbl;
      std::cout << "y=" << y << std::endl;
      y = dbl + y;
      std::cout << "y=" << y << std::endl;
      y += dbl;
      std::cout << "y=" << y << std::endl;
      int i = 5;
      y += i;
      std::cout << "y=" << y << std::endl;
      y = i + x;
      std::cout << "y=" << y << std::endl;
      y = x + i;
      std::cout << "y=" << y << std::endl;
      y += dbl + i + x;
      std::cout << "y=" << y << std::endl;
      break;
    }
    case 3:
      Flag = false;
      break;
    default:
      break;
    }
  }
}
