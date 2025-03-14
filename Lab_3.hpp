#include <iostream>
#include <fstream>

class Drob {
    private:

    int numerator = 1;
    int denominator = 1;
    int FullPiesce = 0;
    char* Unturned;

    public:

    Drob();
    Drob(double frac);
    Drob(int num, int den);
    Drob(Drob& alpha);
    void SetDrob(int num, int den);

    friend Drob& operator+(const Drob& alpha,const Drob& Betta);
    friend Drob& operator-(const Drob& alpha,const Drob& Betta);
    friend Drob& operator*(const Drob& alpha,const Drob& Betta);
    friend Drob& operator/(const Drob& alpha,const Drob& Betta);
    friend std::ostream& operator<<(std::ostream& out,const Drob& alpha);
    friend std::istream& operator+(std::istream& in,const Drob& Betta);
    friend Drob& operator=(const Drob& alpha);
};
