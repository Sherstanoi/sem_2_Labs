#include "lab6.hpp"
Term::Term(): Multiplier(0), Degree(0) {}

Term::Term(int SomeMult, int SomeDegree): Multiplier(SomeMult), Degree(SomeDegree) {}

Term::Term(char* cterm) {
    std::cout << cterm << '\n';
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
    } else if (cterm[schet] == '+') { //Можно понтанутться
        schet+=1;
    }
    while (cterm[schet] == ' ') {
        schet += 1;
    }
    for (int i = schet; i < static_cast<int>(strlen(cterm)); i++) { //Если есть ошибка, то тут
        // if (i >= ) { //попытайся поменять тут
        //     break;
        // }
        if (cterm[i] == ' ') {
            break;
        } else if (cterm[i] == 'x') { // ПОменяй
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
        if (i >= static_cast<int>(strlen(cterm))) { //???
            break;
        }
        if (cterm[i] == ' '){
            break;
        }
        if (!isdigit(cterm[i])){
            std::cout << "3небыло небыло\n";
            Multiplier = 0; //Попробуй заменить на временный, который считали до этого?
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
    std::cout << *this;
    std::cout << "\n||||||||||||\n"; // meeh
    return;
}

int Term::degree() const {
    return Degree;
}

int Term::coeff() const {
    return Multiplier;
}

int Term::get_n_(){ // delete
    return Degree;
}

int Term::get_k_(){
    return Multiplier;
}

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
            if (Element[j].degree() > Element[i].degree()) {
                Term TempElement = Element[i];
                Element[i] = Element[j];
                Element[j] = TempElement;
            }
}

void Polynomial::AddElement(const Term& SomeElement) {
    for (int i = 0; i < CurrentElements; ++i) {
        if (Element[i].degree() == SomeElement.degree()) {
            Element[i] += SomeElement;
            if (Element[i].coeff() == 0) {
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

std::istream& operator>>(std::istream& in, Polynomial& Alpha) { // остоноаочка
    char String[1000];
    in.getline(String, 1000);
    int i = 0;
    int j = 0;
    bool short_T;
    char slice_cpol[1000];
    bool NumberCheck = false;
    while (true) {
        std::strcpy(slice_cpol, String);
        NumberCheck = false;
        while (String[j] != 'x'){
            j+=1;
            if (IsEnd(String, j)) {
                break;
            }
            if (String[j] == '-' or String[j] == '+') {
                if (NumberCheck) {
                    Alpha.AddElement(Term(CutTheTerm(slice_cpol, i, j-1)));
                    i=j;
                    continue;
                }
                NumberCheck = true;
            }
        }
        std::strcpy(slice_cpol, String);
        if (IsEnd(String, j)) {
            Alpha.AddElement(Term(CutTheTerm(slice_cpol, i, j-1)));
            break;
        }
        j+=1;
        short_T = false;
        while (String[j] != '^'){j+=1; if (String[j] == '-' or String[j] == '+') {
            j-=1; short_T = true; break;
        }
    }
        j+=1;
        if (short_T) {
            Alpha.AddElement(Term(CutTheTerm(slice_cpol, i, j+1)));
            i=j+1;
            continue;
        }
        while (String[j] == ' '){
            j+=1;
        }
        while (isdigit(String[j])){
            j+=1;
        }
        Term s = Term(CutTheTerm(slice_cpol, i, j+1));
        Alpha.AddElement(s);
        i=j+1;
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
        int k = Alpha.Element[i].coeff();
        if (k == 0) {
            continue;
        }
        int n = Alpha.Element[i].degree();
        if (i > 0) {
            out << (k >= 0 ? " + " : " - ");
        }
        else if (k < 0) {
            out << '-';
        }
        int absK = k < 0 ? -k : k;
        if (n == 0) {
            out << absK;
        }
        else {
            if (absK != 1) {
                out << absK;
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
        Term new_Term(-Betta.Element[i].get_k_(), Betta.Element[i].get_n_());
        TempPolynomal.AddElement(new_Term);
    }
    TempPolynomal.sort_desc();
    return TempPolynomal;
}

Polynomial operator*(const Polynomial& Alpha, const Polynomial& Betta) {
    Polynomial TempPolynomal;
    for (int i = 0; i < Alpha.CurrentElements; ++i){
        for (int j = 0; j < Betta.CurrentElements; ++j){
            TempPolynomal.AddElement(Term(Alpha.Element[i].coeff() * Betta.Element[j].coeff(),
                           Alpha.Element[i].degree() + Betta.Element[j].degree()));
        }
    }
    TempPolynomal.sort_desc();
    return TempPolynomal;
}
