#include <cstring>
#include <fstream>
#include <iostream>

namespace Classes {
class Planet {
private:
  static int amount;
  char *name;
  int diameter;
  bool life;
  int satellites;

public:
  Planet(const char *planetName, int diameter, bool life, int satellite) {
    amount++;
    name = new char[strlen(planetName) + 1];
    strcpy(name, planetName);
    name[strlen(planetName) + 1] = '\0';
    SetDiameter(diameter);
    SetSatellites(satellite);
    SetLife(life);
  }
  Planet() {
    amount++;
    name = new char[1];
    name[0] = '\0';
    SetDiameter(0);
    SetSatellites(1);
    SetLife(1);
  }
  Planet(const Planet &oldPlanet) {
    name = new char[strlen(oldPlanet.name) + 1];
    strcpy(name, oldPlanet.name);
    name[strlen(oldPlanet.name) + 1] = '\0';
    SetDiameter(oldPlanet.diameter);
    SetLife(oldPlanet.life);
    SetSatellites(oldPlanet.satellites);
  }
  Planet &operator=(const Planet &oldPlanet) {
    if (this == &oldPlanet) {
      return *this;
    }
    SetName(oldPlanet.name);
    SetDiameter(oldPlanet.diameter);
    SetLife(oldPlanet.life);
    SetSatellites(oldPlanet.satellites);
    return *this;
  }
  ~Planet() {
    amount--;
    delete[] name;
  }

  char *GetName();
  int GetDiameter();
  int GetSatellites();
  bool GetLife();

  void SetName(char *Name);
  void SetDiameter(int diameter);
  void SetSatellites(int Satellites);
  void SetLife(bool life);

  //friend void ChangePlaces(Planet *SolarSystem, int SolarAmount);
};
class Applications {
private:
public:
};

} // namespace Classes
namespace Functions {
void PlanetFileReading(Classes::Planet *SolarSystem, int Len); //done

void PlanetFileWriting(Classes::Planet *SolarSystem, int Len);

Classes::Planet* AddPlanet(Classes::Planet *SolarSystem, int &Len); //done

void AddPlanet(Classes::Planet *SolarSystem, const char *Name, int diameter,
               int life, int satelites, int *Len); //done

Classes::Planet* DeletePlanet(Classes::Planet *SolarSystem, int &Len);

void SortPlanets(Classes::Planet *SolarSystem, int SolarAmount);

void PrintResult(Classes::Planet *planets, int Len); // done

Classes::Planet* ChangeSystem(Classes::Planet *SolarSystem, int Len);
}
