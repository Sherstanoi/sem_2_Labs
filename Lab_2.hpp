#include <iostream>
#include <fstream>
#include "mymath/mymath.h"

namespace Classes {
    class Planet {
        private:
        static int amount;
        char* name;
        int diameter;
        bool life;
        int satellites;
        public:
        Planet(char* planetName, int diameter, bool life, int satellite) {
            amount++;
            SetName(planetName);
            SetDiameter(diameter);
            SetSatellites(satellite);
            SetLife(life);
        }
        Planet() {
            amount++;
            //char* Al = new char[12];
            //SetName(Al);
            SetDiameter(1);
            SetSatellites(1);
            SetLife(1);
        }
        ~Planet() {
            amount--;
        }

        char* GetName();
        int GetDiameter();
        int GetSatellites();
        bool GetLife();

        void SetName(char* Name);
        void SetDiameter(int diameter);
        void SetSatellites(int Satellites);
        void SetLife(bool life);

        friend void ChangePlaces(Planet* SolarSystem,int SolarAmount);
    };
    class Applications {
        private:

        public:
    };

}
namespace Functions {
    void PlanetFileReading(Classes::Planet* SolarSystem, int i);

    void SortPlanets(Classes::Planet* SolarSystem, int SolarAmount);

    void PrintResult(Classes::Planet* planets);
}
