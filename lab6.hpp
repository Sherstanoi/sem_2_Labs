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
    Polynomial(int alpha);
    Polynomial(const Term& SomeTerm);
    Polynomial(const Polynomial& alpha);
    ~Polynomial();

    Polynomial& operator=(const Polynomial& alpha);
    Polynomial& operator+=(const Polynomial& alpha);
    Polynomial& operator*=(const Polynomial& alpha);

    friend std::ostream& operator<<(std::ostream& out, Polynomial& alpha);
    friend std::istream& operator>>(std::istream& in, Polynomial& alpha);
    friend Polynomial operator+(const Polynomial& alpha, const Polynomial& betta);
    friend Polynomial operator*(const Polynomial& alpha, const Polynomial& betta);

    void SortPolynomial(bool increase = true);
};

namespace{
    bool ContinueFlag = true;
    int Choice;
    int schet = 0;
    int schet2 = 0;
}
