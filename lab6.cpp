#include "lab6.hpp"

Term::Term() {
    Ratio = 0;
    Power = 0;
}
Term::Term(int SomeRatio) {
    Ratio = SomeRatio;
    Power = 0;
}
Term::Term(int SomeRatio, int SomePower) {
    Ratio = SomeRatio;
    Power = SomePower;
}

Term operator+(const Term& Alpha, const Term& Betta) {
    if (Alpha.Power != Betta.Power) {  //ТУУУТ
        throw "INVALID";
    }
    return Term(Alpha.Ratio + Betta.Ratio, Alpha.Power);
}

std::ostream& operator<<(std::ostream& out, Term& Alpha) {
    if (Alpha.Ratio == 0) {
        return out;
    }
    if (Alpha.Power == 0) {
        out << Alpha.Ratio;
    } else {
        if (Alpha.Ratio == 1) {
            out << "x";
        } else if (Alpha.Ratio == -1) {
            out << "-x";
        } else {
            out << Alpha.Ratio << "x";
        }
        if (Alpha.Power != 1) {
            out << "^" << Alpha.Power;
        }
    }
    return out;
}

std::istream& operator>>(std::istream& in, Term& Alpha) {
    char buffer[50]{};
    in.getline(buffer, 50);
    char* xCoords = strchr(buffer, 'x');  //??????
    if (xCoords) {
        *xCoords = '\0';
        if (*buffer == '\0' || strcmp(buffer, "+") == 0) {
            Alpha.Ratio = 1;
        } else if (strcmp(buffer, "-") == 0) {
            Alpha.Ratio = -1;
        } else {
            Alpha.Ratio = atoi(buffer);
        }
        char* degPart = strchr(xCoords + 1, '^');
        if (degPart) {
            Alpha.Power= atoi(degPart + 1);
        } else {
            Alpha.Power = 1;
        }
    } else {
        Alpha.Ratio = atoi(buffer);
        Alpha.Power = 0;
    }
    return in;
}

int Term::GetRatio(){
    return Ratio;
}

Polynomial::Polynomial(){
    Element=nullptr;
    Power=0;
    Size=0;
    order_=true;
}

Polynomial::Polynomial(int SomePower){
    Element = new Term[1];
    Element[0] = Term(SomePower, 0);
    Power=0;
    Size=1;
    order_=true;
}

Polynomial::Polynomial(const Term& SomeTerm) {
    Element = new Term[1];
    Element[0] = SomeTerm;
    Power=SomeTerm.Power;
    Size=1;
    order_=true;
}

Polynomial::Polynomial(const Polynomial& SomePoly) {
    Element = new Term[Size];
    for (int i = 0; i < Size; ++i) {
        Element[i] = SomePoly.Element[i];
    }
    Power = SomePoly.Power;
    Size = SomePoly.Size;
    order_ = SomePoly.order_;
}

Polynomial::~Polynomial() {
    delete[] Element;
}

Polynomial& Polynomial::operator=(const Polynomial& SomePoly) {
    if (this == &SomePoly)
        return *this;
    delete[] Element;
    Element = new Term[Size];
    for (int i = 0; i < Size; i++) {
        Element[i] = SomePoly.Element[i];
    }
    Size = SomePoly.Size;
    Power = SomePoly.Power;
    order_ = true;
    return *this;
}

Polynomial& Polynomial::operator+=(const Polynomial& SomePoly) {
    bool FindingFlag = false;
    for (int i = 0; i < SomePoly.Size; ++i) {
        for (int j = 0; j < Size; ++j) {
            if (Element[j].Power == SomePoly.Element[i].Power) {
                Element[j] = Element[j] + SomePoly.Element[i];
                FindingFlag = true;
                break;
            }
        }
        if (!FindingFlag) {
            Term* newPoly = new Term[Size + 1];
            for (int j = 0; j < Size; ++j) {
                newPoly[j] = Element[j];
            }
            newPoly[Size] = SomePoly.Element[i];
            delete[] Element;
            Element = newPoly;
            ++Size;
        }
    }
    Power = std::max(Power, SomePoly.Power);
    return *this;
}

Polynomial& Polynomial::operator*=(const Polynomial& SomePoly) {
    Polynomial result;
    for (int i = 0; i < Size; ++i) {
        for (int j = 0; j < SomePoly.Size; ++j) {
            result += Polynomial(Term(Element[i].Ratio * SomePoly.Element[j].Ratio,Element[i].Power + SomePoly.Element[j].Power));
        }
    }
    *this = result;
    return *this;
}

Polynomial operator+(const Polynomial& p1, const Polynomial& p2) {
    Polynomial result = p1;
    result += p2;
    return result;
}

Polynomial operator*(const Polynomial& p1, const Polynomial& p2) {
    Polynomial result = p1;
    result *= p2;
    return result;
}

void Polynomial::SortPolynomial(bool Increase) {
    order_ = Increase;
    for (int i = 0; i < Size - 1; ++i) {
        for (int j = 0; j < Size - i - 1; ++j) {
            if ((Increase && Element[j].Power > Element[j + 1].Power) || (!Increase && Element[j].Power < Element[j + 1].Power)) {
                std::swap(Element[j], Element[j + 1]);
            }
        }
    }
}

std::ostream& operator<<(std::ostream& out, Polynomial& SomePoly) {
    if (SomePoly.Size == 0) {
        return out << 0;
    }
    int SomeRatio=0;
    for (int i = 0; i < SomePoly.Size; ++i) {
        if(SomePoly.Element[i].GetRatio()!=0){
            if(SomePoly.Element[i].GetRatio()>0 && SomeRatio>0){
                out<<"+";
            }
            out<<SomePoly.Element[i]<<" ";
            SomeRatio++;
        }
    }
    return out;
}

std::istream& operator>>(std::istream& in, Polynomial& SomePoly) {  ///???????
    char buffer[1000];
    in.getline(buffer, 1000);
    char* ptr = buffer;
    char Sign = '+';
    while (*ptr == ' ') {
        ++ptr;
    }
    if (*ptr == '+' || *ptr == '-') {
        Sign = *ptr;
        ++ptr;
    }
    while (*ptr) {
        while (*ptr == ' ') {
            ++ptr;
        }
        char* op = std::strchr(ptr, '+');
        char* minus = std::strchr(ptr, '-');
        if (minus && (!op || minus < op)) {
            op = minus;
        }
        char termBuffer[50];
        termBuffer[0] = Sign;
        std::strcpy(termBuffer + 1, ptr);
        std::istringstream tempStream(termBuffer);
        Term temp;
        tempStream >> temp;
        SomePoly += Polynomial(temp);
        if (op) {
            Sign = *op;
            ptr = op + 1;
        } else {
            break;
        }
    }
    return in;
}
