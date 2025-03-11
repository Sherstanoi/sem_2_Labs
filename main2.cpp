#include "Lab_2_pers.hpp"
#include <typeinfo>

int main() {
  int StartLen = 5;
  int choise;
  std::cout
      << "Какую функцию вы хотели бы задействовать? \n 1. Считать базу "
         "данных из файла \n 2. Вывести базу данных на экран \n 3. "
         "Отсортировать базу данных \n 4. Изменить данные об одной анкете \n 5. Добавить элемент в базу данных \n 6. "
         "Удалить элемент из базы данных \n 7. Записать базу данных в файл"
      << std::endl;
  std::cin >> choise;
  char choiceToContinue = 'y';
  Classes::JobApplication *applications = new Classes::JobApplication[StartLen];
  bool LazyFlag = false;
  while(choiceToContinue == 'y') {
        switch (choise) {
        case 1:
            LazyFlag = true;
            applications[0].ApplicationFileReading(applications, StartLen);
            break;
        case 2:
            if(LazyFlag) {
                applications[0].PrintResult(applications, StartLen);
            }
            else {
                std::cout<< "Вы не считали файлл. без этого невозможно выполнение программы";
            }
            break;
        case 3:
            std::cout<<"aaa";
            if(LazyFlag) {
                applications[0].SortAppications(applications, StartLen-1);
            }
            else {
                std::cout<< "Вы не считали файлл. без этого невозможно выполнение программы";
            }
            break;
        case 4:
            if(LazyFlag) {
                applications = applications[0].ChangeBase(applications, StartLen);
            }
            else {
                std::cout<< "Вы не считали файлл. без этого невозможно выполнение программы";
            }
            break;
        case 5:
            if(LazyFlag) {
                applications = applications[0].AddApplication(applications, StartLen);
            }
            else {
                std::cout<< "Вы не считали файлл. без этого невозможно выполнение программы";
            }
            break;
        case 6:
            if(LazyFlag) {
                Classes::JobApplication* Temp = new Classes::JobApplication[StartLen-1];
                applications = applications[0].DeleteApplication(applications, StartLen);
            }
            else {
                std::cout<< "Вы не считали файлл. без этого невозможно выполнение программы";
            }
            break;
        case 7:
            if(LazyFlag) {
                applications[0].ApplicationFileWriting(applications, StartLen);
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
       "Отсортировать базу данных \n 4. Изменить данные об одной анкете \n 5. Добавить элемент в базу данных \n 6. "
       "Удалить элемент из базы данных \n 7. Записать базу данных в файл"
    << std::endl;
     std::cin >> choise;
    }

  return 0;
}
