#include <cstring>
#include <fstream>
#include <iostream>

namespace Classes {
class JobApplication {
private:
  static int amount;
  char *Name;
  char *job;
  int WorkHours;
  int Sellary;

public:
  JobApplication(const char *PersonName, const char* Job, int WorkHours, int Sellary) {
    amount++;
    Name = new char[strlen(PersonName) + 1];
    strcpy(Name, PersonName);
    Name[strlen(PersonName) + 1] = '\0';
    job = new char[strlen(Job) + 1];
    strcpy(job, Job);
    job[strlen(Job) + 1] = '\0';
    SetWorkHours(WorkHours);
    SetSellary(Sellary);
  }
  JobApplication() {
    amount++;
    Name = new char[1];
    Name[0] = '\0';
    job = new char[1];
    job[0] = '\0';
    SetWorkHours(0);
    SetSellary(1);
  }
  JobApplication(const JobApplication &OldApplication) {
    Name = new char[strlen(OldApplication.Name) + 1];
    strcpy(Name, OldApplication.Name);
    Name[strlen(OldApplication.Name) + 1] = '\0';
    SetWorkHours(OldApplication.WorkHours);
    SetSellary(OldApplication.Sellary);
  }

  JobApplication &operator=(const JobApplication &oldPlanet) {
    if (this == &oldPlanet) {
      return *this;
    }
    SetName(oldPlanet.Name);
    SetJob(oldPlanet.job);
    SetWorkHours(oldPlanet.WorkHours);
    SetSellary(oldPlanet.Sellary);
    return *this;
  }

  friend std::ostream &operator<<(std::ostream&out, const JobApplication& obj) {
    out << "Имя: "<< obj.Name << " Работа:  " << obj.job << " Часы работы:  " << obj.WorkHours << " Зарплата: " << obj.Sellary << std::endl;
    return out;
  }

  friend JobApplication &operator>>(std::istream& in, JobApplication& obj) {
    char strin[100]{};
    char secondStrin[100]{};
    int workHours = 0, Sellary = 0;
    in >> strin >> secondStrin >> workHours >> Sellary;

    obj.Name = new char[strlen(strin) + 1];
    strcpy(obj.Name,  strin);
    obj.Name[strlen(strin) + 1] = '\0';

    obj.job = new char[strlen(secondStrin) + 1];
    strcpy(obj.job, secondStrin);
    obj.job[strlen(secondStrin) + 1] = '\0';

    obj.SetWorkHours(workHours);
    obj.SetSellary(Sellary);
    return obj;
  }

  ~JobApplication() {
    amount--;
    delete[] Name;
  }

  char *GetName();
  char* GetJob();
  int GetWorkHours();
  int GetSellary();

  void SetName(char *Name);
  void SetWorkHours(int diameter);
  void SetSellary(int Satellites);
  void SetJob(char* Job);

  static void ApplicationFileReading(Classes::JobApplication *ApplicationBase,
                                     int &Len);

  static void ApplicationFileWriting(Classes::JobApplication *ApplicationBase,
                                     int Len);

  static Classes::JobApplication *
  AddApplication(Classes::JobApplication *ApplicationBase, int &Len);

  static Classes::JobApplication *
  DeleteApplication(Classes::JobApplication *ApplicationBase, int &Len);

  static void SortAppications(Classes::JobApplication *ApplicationBase,
                              int SolarAmount);

  static void PrintResult(Classes::JobApplication *planets, int Len);

  static Classes::JobApplication *
  ChangeBase(Classes::JobApplication *ApplicationBase, int Len);
};

} // namespace Classes
