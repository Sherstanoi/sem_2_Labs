#include <iostream>
#include <fstream>
#include <cstring>

class Drob {
    private:

    int numerator = 1;
    int denominator = 1;
    int FullPiece = 0;
    char* Unturned;

    public:

    Drob();
    Drob(double frac);
    Drob(int num, int den);
    Drob(Drob& alpha);
    Drob(const char* unturn);

    int GetNumerator();
    int GetDenominator();
    int GetFull();

    void SetNumerator(int NewNum);
    void SetDenominator(int NewDen);
    void SetFull(int NewFull);

    void SetDrob(int num, int den);

    void ChangeDrob();

    Drob& operator=(const Drob& alpha);
    friend Drob& operator+(Drob alpha, Drob betta);
    friend Drob& operator+=(Drob& alpha, Drob& betta);
    friend Drob& operator+(Drob alpha, double betta);
    friend Drob& operator+(double betta,Drob alpha);
    friend Drob& operator+=(double betta,Drob& alpha);
    friend Drob& operator+=(Drob& alpha, double betta);

    friend std::ostream& operator<<(std::ostream& out,const Drob& alpha);
    friend std::istream& operator>>(std::istream& in,Drob& alpha);

    ~Drob() {
        delete[] Unturned;
    }
    void SetUnturned(const char* betta);
};
