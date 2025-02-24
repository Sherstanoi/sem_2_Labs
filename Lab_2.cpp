#include "Lab_2.hpp"

void Classes::Planet::SetName(char* Name) {
    int i = 0;
    while(name[i]) {
        name[i] = Name[i];
        ++i;
    }
}

void Classes::Planet::SetDiameter(int D) {
    diameter = D;
}

void Classes::Planet::SetLife(bool Life) {
    life = Life;
}

void Classes::Planet::SetSatellites(int Satellites) {
    satellites = Satellites;
}

char* Classes::Planet::GetName() {
    return name;
}

int Classes::Planet::GetDiameter() {
    return diameter;
}

bool Classes::Planet::GetLife() {
    return life;
}

int Classes::Planet::GetSatellites() {
    return satellites;
}

int Classes::Planet::amount = 0;

namespace Functions {
    void PlanetFileReading(Classes::Planet* SolarSystem, int i) {
        // std::ifstream planets;
        // if(i = 1) {
        std::ifstream planets("planetsRawInfo.txt");
        // }else {
        //     std::ifstream planets("planetsRawInfo.txt");
        // }
        // if(!planets) {
        //     std::cout<< "Файл пуст или не существует";
        // }
            char strin[100];
            int diameter = 0, satellite = 0;
            bool life = 0;
            int jk = 0;
            while(planets && (planets >> strin >> diameter >> life >> satellite) ) {
                SolarSystem[jk].SetDiameter(diameter);
                //SolarSystem[jk].SetName(strin);
                SolarSystem[jk].SetLife(life);
                SolarSystem[jk].SetSatellites(satellite);
                ++jk;
            }
        }
        void SortPlanets(Classes::Planet* SolarSystem, int SolarAmount) {
            for(int k = SolarAmount; k >0 ; --k) {
                if(SolarSystem[k].GetDiameter() < SolarSystem[k-1].GetDiameter()) {
                    for(int i = k; i>0; --i ) {
                        if(SolarSystem[i].GetDiameter() < SolarSystem[i-1].GetDiameter()) {
                            std::cout<<SolarSystem[i].GetDiameter() << " ";
                            std::cout<<SolarSystem[i-1].GetDiameter() << " ";
                            std::cout<<SolarSystem[SolarAmount].GetDiameter() << "\n";
                            SolarSystem[SolarAmount].SetDiameter(SolarSystem[i-1].GetDiameter());
                            //SolarSystem[jk].SetName(strin); ПОЧЕМУ Я НЕ МОГУ СДЕЛАТЬ ТЕМП????????
                            SolarSystem[SolarAmount].SetLife(SolarSystem[i-1].GetLife());
                            SolarSystem[SolarAmount].SetSatellites(SolarSystem[i-1].GetSatellites());

                            std::cout<<SolarSystem[i].GetDiameter() << " ";
                            std::cout<<SolarSystem[i-1].GetDiameter() << " ";
                            std::cout<<SolarSystem[SolarAmount].GetDiameter() << "\n";

                            SolarSystem[i-1].SetDiameter(SolarSystem[i].GetDiameter());
                            //SolarSystem[jk].SetName(strin); ПОЧЕМУ Я НЕ МОГУ СДЕЛАТЬ ТЕМП????????
                            SolarSystem[i-1].SetLife(SolarSystem[i].GetLife());
                            SolarSystem[i-1].SetSatellites(SolarSystem[i].GetSatellites());

                            SolarSystem[i].SetDiameter(SolarSystem[SolarAmount].GetDiameter());
                            //SolarSystem[jk].SetName(strin); ПОЧЕМУ Я НЕ МОГУ СДЕЛАТЬ ТЕМП????????
                            SolarSystem[i].SetLife(SolarSystem[SolarAmount].GetLife());
                            SolarSystem[i].SetSatellites(SolarSystem[SolarAmount].GetSatellites());

                            std::cout<<SolarSystem[i].GetDiameter() << " ";
                            std::cout<<SolarSystem[i-1].GetDiameter() << " ";
                            std::cout<<SolarSystem[SolarAmount].GetDiameter() << "\n";
                            std::cout<< "\n";
                        }
                    }
                }
            }
        }
        void PrintResult(Classes::Planet* planets) {
            for(int i = 0; i<9; i++) {
                //std::cout << planets[i].GetName()<< "\n";
                std::cout << planets[i].GetDiameter() << " ";
                std::cout << planets[i].GetLife() << " ";
                std::cout << planets[i].GetSatellites() << "\n";
                }
        }
    }
