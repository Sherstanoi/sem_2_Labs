#include "lab6.hpp"
Term::Term(): Multiplier(0), Degree(0) {}

Term::Term(int SomeMult, int SomeDegree): Multiplier(SomeMult), Degree(SomeDegree) {}

Term::Term(char* cterm) {
    // std::cout << cterm << '\n';
    int MultSign = 1;
    int TempMult = 0;
    int DegreeSign = 1;
    int TempDegree = 0;
    int schet = 0;
    bool MultFlag = false;
    bool DegreeFlag = false;
    while (cterm[schet] == ' ') {
        schet += 1;
    }
    if (cterm[schet] == '-') {
        MultSign = -1;
        schet+=1;
    } else if (cterm[schet] == '+') {
        schet+=1;
    }
    while (cterm[schet] == ' ') {
        schet += 1;
    }
    for (int i = schet; i < static_cast<int>(strlen(cterm)); i++) {
        if (cterm[i] == ' ') {
            break;
        } else if (cterm[i] == 'x') {
            break;
        }
        if (!isdigit(cterm[i]) && i < static_cast<int>(strlen(cterm))) {
            Multiplier = 0;
            Degree = 0;
            return;
        }
        TempMult *= 10;
        TempMult += (static_cast<int>(cterm[i]) - static_cast<int>('0'));
        schet += 1;
        MultFlag = true;
    }
    schet+=1;
    while (cterm[schet] == ' ' || cterm[schet] == 'x' || cterm[schet] == '^' ) {
        schet += 1;
    }
    if (cterm[schet] == '-'){
        DegreeSign = -1;
        schet+=1;
    }
    while (cterm[schet] == ' ') {
        schet += 1;
    }
    for (int i = schet; i < static_cast<int>(std::strlen(cterm)); i++){
        if (i >= static_cast<int>(strlen(cterm))) {
            break;
        }
        if (cterm[i] == ' '){
            break;
        }
        if (!isdigit(cterm[i])){
            //std::cout << "такого нет\n";
            Multiplier = 0;
            Degree = 0;
            return;
        }
        TempDegree *= 10;
        TempDegree += (static_cast<int>(cterm[i]) - static_cast<int>('0'));
        schet += 1;
        DegreeFlag = true;
    }
    Multiplier = TempMult * MultSign;
    Degree = TempDegree * DegreeSign;
    if (not MultFlag and DegreeFlag) {
        Multiplier = MultSign;
    }
    if (Multiplier == 0) {
        Degree = 0;
    }
    // std::cout << *this;
    // std::cout << "\n||||||||||||\n"; // meeh
    return;
}

int Term::GetDegree() const {
    return Degree;
}

int Term::GetCoeff() const {
    return Multiplier;
}

// int Term::GetDegree(){ // delete
//     return Degree;
// }

// int Term::GetCoeff(){
//     return Multiplier;
// }

Term& Term::operator+=(const Term& other) {
    if (Degree == other.Degree) {
        Multiplier += other.Multiplier;
    }
    return *this;
}

Term operator+(const Term& Alpha, const Term& Betta) {
    Term TempElement = Alpha;
    TempElement += Betta;
    return TempElement;
}

std::istream& operator>>(std::istream& in, Term& Alpha) {
    char cterm[1000];
    in.getline(cterm, 1000);
    Alpha = Term(cterm);
    return in;
}

std::ostream& operator<<(std::ostream& out, const Term& Alpha) {
    int TempMult = Alpha.Multiplier;
    int TempDegree = Alpha.Degree;
    if (TempMult == 0) {
        out << '0';
        return out;
    } else if (TempDegree == 0) {
        out << TempMult;
        return out;
    } else if (TempMult != 1 && TempMult != -1) {
        out << TempMult;
    }
    out << 'x';
    if (TempDegree != 1) {
        out << '^' << TempDegree;
    }
    return out;
}

Polynomial::Polynomial(): Element(new Term[4]), CurrentElements(0), MaxElements(4) {}

Polynomial::Polynomial(const Polynomial& other): Element(new Term[other.MaxElements]), CurrentElements(other.CurrentElements), MaxElements(other.MaxElements) {
    for (int i = 0; i < CurrentElements; ++i) {
        Element[i] = other.Element[i];
    }
}

Polynomial::~Polynomial() {
    delete[] Element;
}

void Polynomial::ChangeMaxElementsAmount() {
    if (CurrentElements < MaxElements) {
        return;
    }
    int NewMaxElements = MaxElements * 2;
    Term* TempElement = new Term[NewMaxElements];
    for (int i = 0; i < CurrentElements; ++i) {
        TempElement[i] = Element[i];
    }
    delete[] Element;
    Element = TempElement;
    MaxElements = NewMaxElements;
}

void Polynomial::sort_desc() {
    for (int i = 0; i < CurrentElements - 1; ++i)
        for (int j = i + 1; j < CurrentElements; ++j)
            if (Element[j].GetDegree() > Element[i].GetDegree()) {
                Term TempElement = Element[i];
                Element[i] = Element[j];
                Element[j] = TempElement;
            }
}

void Polynomial::AddElement(const Term& SomeElement) {
    for (int i = 0; i < CurrentElements; ++i) {
        if (Element[i].GetDegree() == SomeElement.GetDegree()) {
            Element[i] += SomeElement;
            if (Element[i].GetCoeff() == 0) {
                for (int j = i; j < CurrentElements - 1; ++j) {
                     Element[j] = Element[j+1];
                }
                CurrentElements--;
            }
            return;
        }
    }
    ChangeMaxElementsAmount();
    Element[CurrentElements++] = SomeElement;
    sort_desc();
}

char* CutTheTerm(char* String, int Beggining, int End) {
    String[std::min(End+1, static_cast<int>(strlen(String)))] = '\0';
    return String+Beggining;
}

bool IsEnd(char String[1000], int Index) {
    return Index > static_cast<int>(std::strlen(String));
}

Polynomial& Polynomial::operator=(const Polynomial& other) {
    if (this != &other) {
        delete[] Element;
        MaxElements = other.MaxElements;
        CurrentElements = other.CurrentElements;
        Element = new Term[MaxElements];
        for (int i = 0; i < CurrentElements; ++i) {
            Element[i] = other.Element[i];
        }
    }
    return *this;
}

std::istream& operator>>(std::istream& in, Polynomial& Alpha) {
    char String[1000];
    in.getline(String, 1000);
    int CheckpointEl = 0;
    int CurEl = 0;
    bool short_T;
    char slice_cpol[1000]{};
    bool NumberCheck = false;
    while (true) {
        std::strcpy(slice_cpol, String);
        NumberCheck = false;
        while (String[CurEl] != 'x'){
            CurEl+=1;
            if (IsEnd(String, CurEl)) {
                break;
            }
            if (String[CurEl] == '-' || String[CurEl] == '+') {
                if (NumberCheck) {
                    Alpha.AddElement(Term(CutTheTerm(slice_cpol, CheckpointEl, CurEl-1)));
                    CheckpointEl=CurEl;
                    continue;
                }
                NumberCheck = true;
            }
        }
        std::strcpy(slice_cpol, String);
        if (IsEnd(String, CurEl)) {
            Alpha.AddElement(Term(CutTheTerm(slice_cpol, CheckpointEl, CurEl-1)));
            break;
        }
        CurEl+=1;
        short_T = false;
        while (String[CurEl] != '^'){
            CurEl+=1;
            if (String[CurEl] == '-' || String[CurEl] == '+') {
            CurEl-=1;
            short_T = true;
            break;
        }
    }
        CurEl+=1;
        if (short_T) {
            Alpha.AddElement(Term(CutTheTerm(slice_cpol, CheckpointEl, CurEl+1)));
            CheckpointEl=CurEl+1;
            continue;
        }
        while (String[CurEl] == ' '){
            CurEl+=1;
        }
        while (isdigit(String[CurEl])){
            CurEl+=1;
        }
        Term s = Term(CutTheTerm(slice_cpol, CheckpointEl, CurEl+1));
        Alpha.AddElement(s);
        CheckpointEl=CurEl+1;
        continue;
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, const Polynomial& Alpha) {
    if (Alpha.CurrentElements == 0) {
        out << '0';
        return out;
    }
    for (int i = 0; i < Alpha.CurrentElements; ++i) {
        int SomeCoef = Alpha.Element[i].GetCoeff();
        if (SomeCoef == 0) {
            continue;
        }
        int n = Alpha.Element[i].GetDegree();
        if (i > 0) {
            out << (SomeCoef >= 0 ? " + " : " - ");
        }
        else if (SomeCoef < 0) {
            out << '-';
        }
        int AbsSomeCoef = SomeCoef < 0 ? -SomeCoef : SomeCoef;
        if (n == 0) {
            out << AbsSomeCoef;
        }
        else {
            if (AbsSomeCoef != 1) {
                out << AbsSomeCoef;
            }
            if (n != 0){
            out << 'x';
            if (n != 1) out << '^' << n;
            }
        }
    }
    return out;
}

Polynomial operator+(const Polynomial& Alpha, const Polynomial& Betta) {
    Polynomial TempPolynomal = Alpha;
    for (int i = 0; i < Betta.CurrentElements; ++i) {
        TempPolynomal.AddElement(Betta.Element[i]);
    }
    TempPolynomal.sort_desc();
    return TempPolynomal;
}

Polynomial operator-(const Polynomial& Alpha, const Polynomial& Betta) {
    Polynomial TempPolynomal = Alpha;
    for (int i = 0; i < Betta.CurrentElements; ++i){
        Term new_Term(-Betta.Element[i].GetCoeff(), Betta.Element[i].GetDegree());
        TempPolynomal.AddElement(new_Term);
    }
    TempPolynomal.sort_desc();
    return TempPolynomal;
}

Polynomial operator*(const Polynomial& Alpha, const Polynomial& Betta) {
    Polynomial TempPolynomal;
    std::cout<<Alpha << "\n";
    std::cout<<Betta << "\n";
    for (int i = 0; i < Alpha.CurrentElements; ++i){
        for (int j = 0; j < Betta.CurrentElements; ++j){
            TempPolynomal.AddElement(Term(Alpha.Element[i].GetCoeff() * Betta.Element[j].GetCoeff(),
                           Alpha.Element[i].GetDegree() + Betta.Element[j].GetDegree()));
        }
    }
    TempPolynomal.sort_desc();
    return TempPolynomal;
}
