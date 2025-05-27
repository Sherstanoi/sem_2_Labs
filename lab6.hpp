#include <iostream>
#include <cstring>
#pragma once

class Term {
private:
    int Multiplier;
    int Degree;
public:
    Term();
    Term(int k, int n=0);
    Term(char* alpha);

    int degree() const;
    int coeff() const;

    int get_n_();
    int get_k_();

    Term& operator+=(const Term& Alpha);
    friend Term operator+(const Term& Alpha, const Term& Betta);
    friend std::istream& operator>>(std::istream& in, Term& Alpha);
    friend std::ostream& operator<<(std::ostream& out, const Term& Alpha);
};

class Polynomial {
private:
    Term* Element;

    int CurrentElements;
    int MaxElements;

    void ChangeMaxElementsAmount();
    void sort_desc();
public:
    Polynomial();
    Polynomial(const Polynomial& Alpha);
    ~Polynomial();

    void AddElement(const Term& Betta);

    Polynomial& operator=(const Polynomial& Alpha);
    friend Polynomial operator+(const Polynomial& Alpha, const Polynomial& Betta);
    friend Polynomial operator*(const Polynomial& Alpha, const Polynomial& Betta);
    friend Polynomial operator-(const Polynomial& Alpha, const Polynomial& Betta);
    friend std::istream& operator>>(std::istream& in, Polynomial& poly);
    friend std::ostream& operator<<(std::ostream& out, const Polynomial& poly);
};
