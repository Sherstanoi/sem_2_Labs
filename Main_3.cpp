#include "Lab_3.hpp"

int main() {
  std::cout << "Здравствуйте!" << "/n";
  bool Flag = true;
  int choice = 0;
  while (Flag) {
    std::cout
        << "Какой функцией вы хотелись бы воспользоваться? /n 1.сложить "
           "дроби /n 2.вычесть дроби /n 3.перемножить дроби /n 4.поделить "
           "дроби /n 5 закончить /n";
    std::cin >> choice;
    Drob x;
    Drob y;
    switch (choice) {
    case 1: {
      std::cout << "какие дроби вы хотели бы сложить?" << std::endl;
      std::cout<< "X(число вида 1/1  или 1.0): " << std::endl;
      std::cin>>x;
      std::cout<<"Y: " <<std::endl;
      std::cin>>y;
      std::cout<< "x + y" << x + y;
      break;
    }
    case 2:{
        std::cout << "какие дроби вы хотели бы вычесть?" << std::endl;
        std::cout<< "X(число вида 1/1  или 1.0): " << std::endl;
        std::cin>>x;
        std::cout<<"Y: " <<std::endl;
        std::cin>>y;
        std::cout<< "x - y" << x - y;
        break;
      }
    case 3:{
        std::cout << "какие дроби вы хотели бы сложить?" << std::endl;
        std::cout<< "X(число вида 1/1  или 1.0): " << std::endl;
        std::cin>>x;
        std::cout<<"Y: " <<std::endl;
        std::cin>>y;
        std::cout<< "x * y" << x * y;
        break;
      }
    case 4:{
        std::cout << "какие дроби вы хотели бы сложить?" << std::endl;
        std::cout<< "X(число вида 1/1  или 1.0): " << std::endl;
        std::cin>>x;
        std::cout<<"Y: " <<std::endl;
        std::cin>>y;
        std::cout<< "x / y" << x / y;
        break;
      }
    case 5:
      Flag = false;
      break;
    default:
      break;
    }
  }
}
