#include "Lab_2.hpp"

void Classes::Planet::SetName(char *Name) {
  delete[] name;
  name = new char[strlen(Name) + 1];
  strcpy(name, Name);
  name[strlen(Name) + 1] = '\0';
}

void Classes::Planet::SetDiameter(int D) { diameter = D; }

void Classes::Planet::SetLife(bool Life) { life = Life; }

void Classes::Planet::SetSatellites(int Satellites) { satellites = Satellites; }

char *Classes::Planet::GetName() { return name; }

int Classes::Planet::GetDiameter() { return diameter; }

bool Classes::Planet::GetLife() { return life; }

int Classes::Planet::GetSatellites() { return satellites; }

int Classes::Planet::amount = 0;

namespace Functions {

void SortPlanets(Classes::Planet *SolarSystem, int SolarAmount) {
  Classes::Planet Temp;
  for (int k = SolarAmount; k > 0; --k) {
    if (SolarSystem[k].GetDiameter() < SolarSystem[k - 1].GetDiameter()) {
      for (int i = k - 1; i < SolarAmount; ++i) {
        if (SolarSystem[i].GetDiameter() > SolarSystem[i + 1].GetDiameter()) {
          Temp = SolarSystem[i];
          SolarSystem[i] = SolarSystem[i + 1];
          SolarSystem[i + 1] = Temp;
        }
      }
    }
  }
}

void PrintResult(Classes::Planet *planets, int Len) {
  for (int i = 0; i < Len; i++) {
    std::cout << planets[i].GetName() << "\n";
    std::cout << planets[i].GetDiameter() << " ";
    std::cout << planets[i].GetLife() << " ";
    std::cout << planets[i].GetSatellites() << "\n";
  }
}

Classes::Planet* AddPlanet(Classes::Planet *SolarSystem, int &Len) {
  Len += 1;
  Classes::Planet *Temp = new Classes::Planet[Len];
  for (int i = 0; i < Len - 1; ++i) {
    Temp[i] = SolarSystem[i];
  }
  char NewName[100]{};
  int NewDiameter;
  int NewLIfe;
  int NewSetellites;

  std::cout << "Введите Нзвание новой планеты, пожалуйста:" << std::endl;
  std::cin >> NewName;
  std::cout << "А теперь диаметр, пожалуйста:" << std::endl;
  std::cin >> NewDiameter;
  std::cout << "Есть ли на ней жизнь? (1= да, 0 = нет)" << std::endl;
  std::cin >> NewLIfe;
  if (NewLIfe > 1) {
    std::cout << "Ну я же написал, какие результаты существуют..." << std::endl;
    return SolarSystem;
  }
  std::cout << "А сколько спутников? " << std::endl;
  std::cin >> NewSetellites;
  std::cout << NewSetellites;
  Classes::Planet NewPlanet(NewName, NewDiameter, NewLIfe, NewSetellites);
  Temp[Len - 1] = NewPlanet;
  delete[] SolarSystem;
  SolarSystem = Temp;
  return SolarSystem;
  // SolarSystem = new Classes::Planet[Len];
  // for (int i = 0; i < Len; ++i) {
  //   SolarSystem[i] = Temp[i];
  // }
  // delete[] Temp;
}

Classes::Planet* AddPlanet(Classes::Planet *SolarSystem, const char *Name, int diameter,
               int life, int satelites, int &Len) {
  Len += 1;
  Classes::Planet *Temp = new Classes::Planet[Len];
  Temp = SolarSystem;
  Classes::Planet NewPlanet(Name, diameter, life, satelites);
  Temp[Len - 1] = NewPlanet;
  delete[] SolarSystem;
  //SolarSystem = new Classes::Planet[*Len];
  SolarSystem = Temp;
  return SolarSystem;
  //delete[] Temp;
}

void PlanetFileReading(Classes::Planet *SolarSystem, int Len) {
  std::ifstream planets("planetsRawInfo.txt");
  char strin[100]{};
  int diameter = 0, satellite = 0;
  bool life = 0;
  int jk = 0;
  while (planets && (planets >> strin >> diameter >> life >> satellite)) {
    if (jk > Len - 1) {
      AddPlanet(SolarSystem, strin, diameter, life, satellite, Len);
      ++jk;
    } else {
      SolarSystem[jk].SetDiameter(diameter);
      SolarSystem[jk].SetName(strin);
      SolarSystem[jk].SetLife(life);
      SolarSystem[jk].SetSatellites(satellite);
      ++jk;
    }
  }
}

Classes::Planet* ChangeSystem(Classes::Planet *SolarSystem, int Len) {
  for (int i = 0; i < Len; ++i) {
    std::cout << i << "." << SolarSystem[i].GetName() << "\n";
  }
  std::cout << "Какую планету вы хотели бы изменить? (Введите цифру)";
  int PlanetChange;
  std::cin >> PlanetChange;
  std::cout << "Что бы вы хотели изменить? \n 1.Имя \n 2.Диаметр \n 3. Наличие "
               "жизни \n 4. количество спутников"
            << std::endl;
  int Characteristic;
  std::cin >> Characteristic;

  switch (Characteristic) {
  case 1: {
    std::cout << "Задайте новое имя: ";
    char NewName[100]{};
    std::cin >> NewName;
    SolarSystem[PlanetChange].SetName(NewName);
    std::cout << std::endl;
    break;
  }
  case 2: {
    std::cout << "Здайте новый диаметр: ";
    int NewDiametr = 0;
    std::cin>>NewDiametr;
    SolarSystem[PlanetChange].SetDiameter(NewDiametr);
    std::cout << std::endl;
    break;
  }
  case 3: {
    std::cout << "Здайте Наличие жизни: ";
    int NewLife = 0;
    std::cin>>NewLife;
    SolarSystem[PlanetChange].SetDiameter(NewLife);
    std::cout << std::endl;
    break;
  }
  case 4: {
    std::cout << "Здайте новое количество спуников: ";
    int NewSatellites = 0;
    std::cin>> NewSatellites;
    SolarSystem[PlanetChange].SetDiameter(NewSatellites);
    std::cout << std::endl;
    break;
  }
  default:
    std::cout << "Ткого варианта не предусмотрено";
    break;
  }
  return SolarSystem;
}

Classes::Planet* DeletePlanet(Classes::Planet *SolarSystem, int &Len) {
  Classes::Planet *Temp = new Classes::Planet[Len];
  if(SolarSystem[0].GetDiameter()) {
  for (int i = 0; i < Len; ++i) {
    std::cout << i << "." << SolarSystem[i].GetName() << "\n";
  }
  std::cout << "Какую планету вы хотели бы удалить? (Введите цифру)";
  int PlanetDelete;
  std::cin >> PlanetDelete;
  for (int i = 0; i < Len; ++i) {
    if (i < PlanetDelete ) {
      Temp[i] = SolarSystem[i];
    } else if(i> PlanetDelete){
      Temp[i-1] = SolarSystem[i];
    }
  }
  Len -= 1;
  delete[] SolarSystem;
  //SolarSystem = new Classes::Planet[Len];
  SolarSystem = Temp;
} else {
  std::cout<< "В файле больше нет планет";
}
  return SolarSystem;
  //delete[] Temp;
}

void PlanetFileWriting(Classes::Planet *SolarSystem, int Len) {
  std::ofstream planets("planetsSortedInfo.txt");
  for (int i = 0; i < Len; ++i) {
    planets << SolarSystem[i].GetName() << " " << SolarSystem[i].GetDiameter()
            << " " << SolarSystem[i].GetLife() << " "
            << SolarSystem[i].GetSatellites() << std::endl;
  }
  planets.close();
}

} // namespace Functions
