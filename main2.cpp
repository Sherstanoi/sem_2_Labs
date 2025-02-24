#include "Lab_2.hpp"
#include <typeinfo>

int main() {
    int choise;
    std::cin >> choise;
    Classes::Planet planets[10];
    // char a[2] = {'y', 'a'};
    // planets[10] = {a,1,1,1};
    switch (choise) {
    case 1:
        Functions::PlanetFileReading(planets,1);
        Functions::PrintResult(planets);
        std::cout<< "\n";
        Functions::SortPlanets(planets, 9);
        Functions::PrintResult(planets);
        break;
    case 2:
        Functions::PlanetFileReading(planets,2);
        Functions::PrintResult(planets);
    default:
        break;
    }


    return 0;
}
