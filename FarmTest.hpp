#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>

struct Seed{
    const char* name;
    int TimeGrowth;
    int BuyCost;
    int SellCost;
    int Number;
};

struct Vegatebles {
    const char* name;
    int SellCost;
    int Number;
    int amount;  //ЧТО ЭТО ???
};

class SeedBed {
    public:
        time_t TimeLanding; //функция
        int NumberSeed;
        bool buse; //занято?
};

void garden();
void shop();
void storehouse();
void basicFarm();
void menu();
