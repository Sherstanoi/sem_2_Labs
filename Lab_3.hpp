#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>

namespace {
    bool endFlag = true;
}

class Drob {
    private:

    int numerator = 1;
    int denominator = 1;
    int FullPiece = 0;
    char* Unturned;
    bool errorFlag = false;

    public:

    Drob();
    Drob(double frac);
    Drob(int full);
    Drob(int num, int den);
    Drob(Drob& alpha);
    Drob(const char* unturn);

    int GetNumerator();
    int GetDenominator();
    int GetFull();
    bool GetFlag();

    void SetNumerator(int NewNum);
    void SetDenominator(int NewDen);
    void SetFull(int NewFull);

    void SetDrob(int num, int den);

    void ChangeDrob();

    void ConvertDrob();

    Drob& operator=(const Drob& alpha);
    Drob& operator=(const char* alpha);
    Drob& operator=(double alpha);
    friend Drob& operator+(Drob alpha, Drob betta);
    friend Drob& operator+=(Drob& alpha, Drob& betta);
    friend Drob& operator+(Drob alpha, double betta);
    friend Drob& operator+(double betta,Drob alpha);
    friend Drob& operator+=(double betta,Drob& alpha);
    friend Drob& operator+=(Drob& alpha, double betta);
    friend Drob& operator-=(Drob& alpha, double betta);

    friend std::ostream& operator<<(std::ostream& out,Drob& alpha);
    friend std::istream& operator>>(std::istream& in,Drob& alpha);

    ~Drob() {
        delete[] Unturned;
    }
    void SetUnturned(const char* betta);
};
