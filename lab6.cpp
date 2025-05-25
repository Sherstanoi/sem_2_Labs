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

Term operator+(const Term& Alpha, const Term& Betta) {
    return Term(Alpha.Ratio + Betta.Ratio, Alpha.Power);
}

int Term::GetRatio(){
    return Ratio;
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
    for(int i = 49; buffer[i]!= '\0'; --i) {
        schet = i;
    };
    // std::cout<<schet << " " << buffer[schet] << " ";
    // if(buffer[schet] == '+' || buffer[schet] == '-') {
    //     while(buffer[schet] != '-' || buffer[schet] != '+' || buffer[schet] != 'x') {
    //         ++schet;
    //         if(buffer[schet] == '-' || buffer[schet] == '+') {
    //             buffer[schet-1] = '\0';
    //             Alpha.Ratio = atoi(buffer);
    //             Alpha.Power = 0;
    //             return in;
    //         } else if(buffer[schet]=='x') {
    //             break;
    //         }
    //     }
    // }
    char* XIndex = strchr(buffer, 'x'); //Может ли ошибка быть тут?
    if (XIndex) {
        while(*(buffer+schet) != *XIndex) {
            schet++;
        }
        *XIndex = '\0';
        char* SomeIndex;
        for(int i = schet-1; buffer[i] != '\0'; --i) {
            if(buffer[i] == '+' || buffer[i] == '-') {
                schet2 +=1;
                if(schet2 > 1) {
                    SomeIndex = strchr(buffer, ' ');
                    *SomeIndex = '\0';
                    Alpha.Ratio = atoi(buffer);
                    Alpha.Power = 0;
                    return in;
                }
            }
        }
        std::cout<<buffer;
        if (*buffer == '\0' || strcmp(buffer, "+") == 0) {
            Alpha.Ratio = 1;
        } else if (strcmp(buffer, "-") == 0) {
            Alpha.Ratio = -1;
        } else {
            Alpha.Ratio = atoi(buffer);
        }
        char* PowerSymbolIndex = strchr(XIndex + 1, '^');
        if (PowerSymbolIndex && PowerSymbolIndex-XIndex < 2) {
            Alpha.Power= atoi(PowerSymbolIndex + 1);
        } else {
            Alpha.Power = 1;
        }
    } else {
        Alpha.Ratio = atoi(buffer);
        Alpha.Power = 0;
    }
    return in;
}

Polynomial& Polynomial::operator=(const Polynomial& SomePoly) {
    if (this == &SomePoly)
        return *this;
    delete[] Element;
    Element = new Term[SomePoly.Size];
    for (int i = 0; i < SomePoly.Size; i++) {
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

Polynomial& Polynomial::operator*=(const Polynomial& SomePoly) { //ТУт возможно
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

void Polynomial::SortPolynomial(bool Increase) { // Тут должна быть
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

std::istream& operator>>(std::istream& in, Polynomial& SomePoly) {  
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
        char* FirstSign = std::strchr(ptr, '+');
        char* AlternativeSign = std::strchr(ptr, '-');
        if (AlternativeSign && (!FirstSign || AlternativeSign < FirstSign)) {
            FirstSign = AlternativeSign;
        }
        char termBuffer[50];
        termBuffer[0] = Sign;
        std::cout<< "\n" << buffer<<"\n";
        std::strcpy(termBuffer + 1, ptr);
        std::istringstream tempStream(termBuffer);
        Term temp;
        tempStream >> temp;
        std::cout << temp;
        SomePoly += Polynomial(temp);
        if (FirstSign) {
            Sign = *FirstSign;
            ptr = FirstSign + 1;
        } else {
            break;
        }
    }
    return in;
}
