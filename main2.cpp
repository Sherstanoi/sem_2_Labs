#include "Lab_2_pers.hpp"
#include <typeinfo>

int main() {
  int StartLen = 9;
  int choise;
  std::cout
      << "Какую функцию вы хотели бы задействовать? \n 1. Считать базу "
         "данных из файла \n 2. Вывести базу данных на экран \n 3. "
         "Отсортировать базу данных \n 4. Изменить данные об одной планете \n 5. Добавить элемент в базу данных \n 6. "
         "Удалить элемент из базы данных \n 7. Записать базу данных в файл"
      << std::endl;
  std::cin >> choise;
  char choiceToContinue = 'y';
  Classes::Planet *planets = new Classes::Planet[StartLen];
  bool LazyFlag = false;
  while(choiceToContinue == 'y') {
        switch (choise) {
        case 1:
            LazyFlag = true;
            Functions::PlanetFileReading(planets, StartLen);
            break;
        case 2:
            if(LazyFlag) {
                Functions::PrintResult(planets, StartLen);
            }
            else {
                std::cout<< "Вы не считали файлл. без этого невозможно выполнение программы";
            }
            break;
        case 3:
            if(LazyFlag) {
                Functions::SortPlanets(planets, StartLen-1);
            }
            else {
                std::cout<< "Вы не считали файлл. без этого невозможно выполнение программы";
            }
            break;
        case 4:
            if(LazyFlag) {
                planets = Functions::ChangeSystem(planets, StartLen);
            }
            else {
                std::cout<< "Вы не считали файлл. без этого невозможно выполнение программы";
            }
            break;
        case 5:
            if(LazyFlag) {
                planets = Functions::AddPlanet(planets, StartLen);
            }
            else {
                std::cout<< "Вы не считали файлл. без этого невозможно выполнение программы";
            }
            break;
        case 6:
            if(LazyFlag) {
                Classes::Planet* Temp = new Classes::Planet[StartLen-1];
                planets = Functions::DeletePlanet(planets, StartLen);
            }
            else {
                std::cout<< "Вы не считали файлл. без этого невозможно выполнение программы";
            }
            break;
        case 7:
            if(LazyFlag) {
                Functions::PlanetFileWriting(planets, StartLen);
            }
            else {
                std::cout<< "Вы не считали файлл. без этого невозможно выполнение программы";
            }
            break;
        default:
            std::cout<< "Такой команды не существует(y/n)" << std::endl;
            break;
        }
    std::cout<< "Вы хотите продоллжать? y/n";
    std::cin>>choiceToContinue;
    if(choiceToContinue != 'y') {
        break;
    }
    std::cout
    << "Какую функцию вы хотели бы задействовать? \n 1. Считать базу "
       "данных из файла \n 2. Вывести базу данных на экран \n 3. "
       "Отсортировать базу данных \n 4. Изменить данные об одной планете \n 5. Добавить элемент в базу данных \n 6. "
       "Удалить элемент из базы данных \n 7. Записать базу данных в файл"
    << std::endl;
     std::cin >> choise;
    }

  return 0;
}
