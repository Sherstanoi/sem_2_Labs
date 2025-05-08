#pragma once
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <limits>
#include <algorithm>
#include <sstream>

class Term{
private:
    int Ratio = 0;
    int Power = 0;

public:
    Term();
    Term(int NewRatio);
    Term(int NewRatio, int NewPower);

    friend Term operator+(const Term& Alpha,const Term& Betta);
    friend std::ostream& operator<<(std::ostream& out, Term& ThisTerm);
    friend std::istream& operator>>(std::istream& in, Term& ThisTerm);

    friend class Polynomial;

    int GetRatio();
};

class Polynomial {
    Term* Element;
    int Power;
    int Size;
    bool order_;

 public:
    Polynomial();
    Polynomial(int PolyPower);
    Polynomial(const Term& SomeTerm);
    Polynomial(const Polynomial& PolyPower);
    ~Polynomial();

    Polynomial& operator=(const Polynomial& PolyPower);
    Polynomial& operator+=(const Polynomial& PolyPower);
    Polynomial& operator*=(const Polynomial& PolyPower);

    friend std::ostream& operator<<(std::ostream& out, Polynomial& PolyPower);
    friend std::istream& operator>>(std::istream& in, Polynomial& PolyPower);
    friend Polynomial operator+(const Polynomial& PowerOfFirst, const Polynomial& PowerOfSecond);
    friend Polynomial operator*(const Polynomial& PowerOfFirst, const Polynomial& PowerOfSecond);

    void SortPolynomial(bool increase = true);
};
