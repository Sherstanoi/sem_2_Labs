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

    void SetDrob(int num, int den);

    void ChangeDrob();

    Drob& operator=(const Drob& alpha);
    Drob& operator+(const Drob& alpha);
    Drob& operator-(const Drob& alpha);
    Drob& operator*(const Drob& alpha);
    Drob& operator/(const Drob& alpha);

    friend std::ostream& operator<<(std::ostream& out,const Drob& alpha);
    friend std::istream& operator>>(std::istream& in,Drob& alpha);

    ~Drob() {
        delete[] Unturned;
    }
    void SetUnturned(char* betta);
};
