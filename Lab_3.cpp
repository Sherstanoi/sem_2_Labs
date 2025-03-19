#include "Lab_3.hpp"

Drob::Drob() {
    numerator = 1;
    denominator = 1;
    FullPiece = 0;
    Unturned = new char;
}
Drob::Drob(int num, int den) {
    numerator = num;
    denominator = den;
    FullPiece = 0;
    Unturned = new char;
}
Drob::Drob(double frac) {
    numerator = 1;
    denominator = 1;
    FullPiece = frac;
    Unturned = new char;
}

Drob::Drob(const char* unturn) {
    numerator = 1;
    denominator = 1;
    FullPiece = 0;
    *Unturned = *unturn;
}

void Drob::SetUnturned(char* betta) {
    Unturned = new char[std::strlen(betta)];
    Unturned = betta;
}
void Drob::SetDrob(int num, int den) {

}

void Drob::ChangeDrob() {
    int tempNum= 0;
    int tempDen = 0;
    bool Flag = true;
    int schet = 0;
    while(Flag) {
        if(Unturned[schet] != '/'){
            tempNum = tempNum*10 + Unturned[schet];
            ++schet;
        }
        else{
            Flag = false;
        }
    }
    Flag = true;
    schet = std::strlen(Unturned)-1;
    while(Flag) {
        if(Unturned[schet] != '/'){
            tempDen = tempDen*10 + Unturned[schet];
            --schet;
        }
        else{
            Flag = false;
        }
    }
    numerator = tempNum;
    denominator = tempDen;
}

Drob& Drob::operator=(const Drob& alpha) {
    return *this;
}
Drob& Drob::operator+(const Drob& alpha) {
    numerator += alpha.numerator;
    return *this;
}
Drob& Drob::operator-(const Drob& alpha) {
    numerator -= alpha.numerator;
    return *this;
}
Drob& Drob::operator*(const Drob& alpha) {
    numerator *= alpha.numerator;
    denominator *= alpha.denominator;
    return *this;
}
Drob& Drob::operator/(const Drob& alpha) {
    numerator /= alpha.numerator;
    denominator /= alpha.denominator;
    return *this;
}

std::ostream& operator<<(std::ostream& out,const Drob& alpha) {
    std::cout << alpha.numerator << '/' << alpha.denominator;
    return out;
}
std::istream& operator>>(std::istream& in, Drob& alpha) {
    char betta[100000000];
    in >> betta;
    // delete[] alpha.Unturned;
    // alpha.SetUnturned(betta);
    // alpha.ChangeDrob();
    return in;
}

void ChangeDrob() {

}
