#include "Lab_2_pers.hpp"

void Classes::JobApplication::SetName(char *name) {
  delete[] Name;
  Name = new char[strlen(name) + 1];
  strcpy(Name, name);
  Name[strlen(name) + 1] = '\0';
}

void Classes::JobApplication::SetJob(char *Job) {
  delete[] job;
  job = new char[strlen(Job) + 1];
  strcpy(job, Job);
  job[strlen(Job) + 1] = '\0';
}

void Classes::JobApplication::SetWorkHours(int D) { WorkHours = D; }

void Classes::JobApplication::SetSellary(int Satellites) {
  Sellary = Satellites;
}

char *Classes::JobApplication::GetName() { return Name; }

char *Classes::JobApplication::GetJob() { return job; }

int Classes::JobApplication::GetWorkHours() { return WorkHours; }

int Classes::JobApplication::GetSellary() { return Sellary; }

int Classes::JobApplication::amount = 0;

void Classes::JobApplication::SortAppications(JobApplication *ApplicationBase,
                                              int SolarAmount) {
  JobApplication Temp("yz", "nn", 1, 1);
  for (int k = SolarAmount; k > 0; --k) {
    char *a = ApplicationBase[k].GetName();
    char *b = ApplicationBase[k - 1].GetName();
    if (std::strcmp(a, b) < 0) {
      for (int i = k - 1; i < SolarAmount; ++i) {
        if (std::strcmp(ApplicationBase[i].GetName(),
                        ApplicationBase[i + 1].GetName()) > 0) {
          Temp = ApplicationBase[i];
          ApplicationBase[i] = ApplicationBase[i + 1];
          ApplicationBase[i + 1] = Temp;
        }
      }
    }
  }
}

void Classes::JobApplication::PrintResult(JobApplication *apploications,
                                          int Len) {
  for (int i = 0; i < Len; i++) {
    std::cout << apploications[i];
  }
}

Classes::JobApplication *
Classes::JobApplication::AddApplication(JobApplication *ApplicationBase,
                                        int &Len) {
  Len += 1;
  JobApplication *Temp = new JobApplication[Len];
  for (int i = 0; i < Len - 1; ++i) {
    Temp[i] = ApplicationBase[i];
  }

  char NewName[100]{};
  int NewWorkHour;
  char NewJob[100]{};
  int NewSellary;

  std::cout << "Введите имя заявителя, пожалуйста: " << std::endl;
  std::cin >> NewName;
  std::cout << "А теперь работу, пожалуйста: " << std::endl;
  std::cin >> NewJob;
  std::cout << "сколько заявитель будет работать? " << std::endl;
  std::cin >> NewWorkHour;
  std::cout << "А сколько получать за это? " << std::endl;
  std::cin >> NewSellary;
  Classes::JobApplication NewApplication(NewName, NewJob, NewWorkHour,
                                         NewSellary);
  Temp[Len - 1] = NewApplication;
  delete[] ApplicationBase;
  ApplicationBase = Temp;
  return ApplicationBase;
}

void Classes::JobApplication::ApplicationFileReading(
    JobApplication *ApplicationBase, int &Len) {
  std::ifstream applications("ApplicationsRawInfo.txt");
  int jk = 0;
  while (applications) {
    if (jk > Len) {
      applications >> ApplicationBase[jk];
      Len += 1;
      ++jk;
    } else {
      applications >> ApplicationBase[jk];
      ++jk;
    }
  }
}

Classes::JobApplication *
Classes::JobApplication::ChangeBase(JobApplication *ApplicationBase, int Len) {
  for (int i = 0; i < Len; ++i) {
    std::cout << i << "." << ApplicationBase[i].GetName() << "\n";
  }
  std::cout << "Какую заявку вы хотели бы изменить? (Введите цифру)";
  int ApplicationChange;
  std::cin >> ApplicationChange;
  std::cout << "Что бы вы хотели изменить? \n 1.Имя заявителя \n 2.работу \n "
               "3. часы работы \n 4. зарплату"
            << std::endl;
  int Characteristic;
  std::cin >> Characteristic;

  switch (Characteristic) {
  case 1: {
    std::cout << "Задайте новое имя заявителя: ";
    char NewName[100]{};
    std::cin >> NewName;
    ApplicationBase[ApplicationChange].SetName(NewName);
    std::cout << std::endl;
    break;
  }
  case 2: {
    std::cout << "Здайте новую работу: ";
    char NewJob[100]{};
    std::cin >> NewJob;
    ApplicationBase[ApplicationChange].SetJob(NewJob);
    std::cout << std::endl;
    break;
  }
  case 3: {
    std::cout << "Задайте часы работы: ";
    int NewWorkHours = 0;
    std::cin >> NewWorkHours;
    ApplicationBase[ApplicationChange].SetWorkHours(NewWorkHours);
    std::cout << std::endl;
    break;
  }
  case 4: {
    std::cout << "Здайте новую зарплату: ";
    int NewSellary = 0;
    std::cin >> NewSellary;
    ApplicationBase[ApplicationChange].SetWorkHours(NewSellary);
    std::cout << std::endl;
    break;
  }
  default:
    std::cout << "Такого варианта не предусмотрено";
    break;
  }
  return ApplicationBase;
}

Classes::JobApplication *
Classes::JobApplication::DeleteApplication(JobApplication *ApplicationBase,
                                           int &Len) {
  JobApplication *Temp = new JobApplication[Len];
  if (ApplicationBase[0].GetWorkHours()) {
    for (int i = 0; i < Len; ++i) {
      std::cout << i << "." << ApplicationBase[i].GetName() << "\n";
    }
    std::cout << "Какую заявку вы хотели бы удалить? (Введите цифру)";
    int ApplicationDelete;
    std::cin >> ApplicationDelete;
    for (int i = 0; i < Len; ++i) {
      if (i < ApplicationDelete) {
        Temp[i] = ApplicationBase[i];
      } else if (i > ApplicationDelete) {
        Temp[i - 1] = ApplicationBase[i];
      }
    }
    Len -= 1;
    delete[] ApplicationBase;
    ApplicationBase = Temp;
  } else {
    std::cout << "В файле больше нет заявок";
  }
  return ApplicationBase;
}

void Classes::JobApplication::ApplicationFileWriting(
    JobApplication *ApplicationBase, int Len) {
  std::ofstream planets("ApplicationsSortedInfo.txt");
  for (int i = 0; i < Len; ++i) {
    planets << ApplicationBase[i];
  }
  planets.close();
}
