#pragma once
#include <cstring>
#include <iostream>

const int OriginMaxSize = 1;

template<class Any>
class MyVector {
 protected:
    int CurMaxSize;
    int CurSize;
    Any* Arrange;
    void ChangeArrSize();

 public:
    MyVector(Any element = NULL, int MaxSize = OriginMaxSize);
    MyVector(const MyVector& Vector);
    ~MyVector();

    void AddElement(Any element);
    bool DeleteElement(int i);
    void SortVector();
    int FindElement(Any element);

    MyVector<Any>& operator=(const MyVector<Any>& Vector);
    const Any& operator[](int i) const;
    template <class OtherAny>
    friend std::ostream& operator<<(std::ostream& out, MyVector<OtherAny>& Vector);
};

template<class Any>
void MyVector<Any>::ChangeArrSize() {
    CurMaxSize *= 2;
    Any* NewArrange = new Any[CurMaxSize];
    for (int i = 0; i < CurSize; ++i) {
        NewArrange[i] = Arrange[i];
    }
    delete[] Arrange;
    Arrange = NewArrange;
}

template<class Any>
MyVector<Any>::MyVector(Any element , int MaxSize) {
    CurMaxSize = MaxSize;
    CurSize = 0;
    Arrange = new Any[CurMaxSize];
    if (element) {
        AddElement(element);
    }
}

template<class Any>
MyVector<Any>::MyVector(const MyVector& Vector) {
    CurMaxSize = Vector.CurMaxSize;
    CurSize = Vector.CurSize;
    Arrange = new Any[CurMaxSize];
    for (int i = 0; i < CurSize; ++i) {
        Arrange[i] = Vector.Arrange[i];
    }
}

template<>
MyVector<char*>::MyVector(const MyVector& Vector) {
    CurMaxSize = Vector.CurMaxSize;
    CurSize = Vector.CurSize;
    Arrange = new char*[CurMaxSize];
    for (int i = 0; i < CurSize; ++i) {
        Arrange[i]=new char[strlen(Vector[i])+1];
        strcpy(Arrange[i],Vector[i]);
    }
}

template<class Any>
MyVector<Any>::~MyVector() {
    delete[] Arrange;
}

template<>
MyVector<char*>::~MyVector() {
    for(int i =0;i<CurMaxSize;++i){
        delete[] Arrange[i];
    }
    delete[] Arrange;
}

template<class Any>
void MyVector<Any>::AddElement(Any element) {
    if (CurSize >= CurMaxSize) {
        ChangeArrSize();
    }
    Arrange[CurSize] = element;
    ++CurSize;
}

template<>
void MyVector<char*>::AddElement(char* element) {
    if (CurSize >= CurMaxSize) {
        ChangeArrSize();
    }
    Arrange[CurSize]=new char[strlen(element)+1];
    strcpy(Arrange[CurSize],element);
    ++CurSize;
}

template<class Any>
bool MyVector<Any>::DeleteElement(int i) {
    if (CurSize == 0 || i < 0 || i >= CurSize) {
        return false;
    }
    for (int j = 0; j < CurSize - 1; ++j) {
        if(j>=i) {
            Arrange[j] = Arrange[j + 1];
        }
    }
    --CurSize;
    if (CurSize < CurMaxSize / 4) {
        CurMaxSize = CurMaxSize / 2;
    }
    return true;
}

template<>
bool MyVector<char*>::DeleteElement(int i) {
    if (CurSize == 0 || i < 0 || i >= CurSize) {
        return false;
    }
    for (int j = i; j < CurSize - 1; ++j) {
        delete[] Arrange[j];
        Arrange[j] = Arrange[j+1];
    }
    --CurSize;
    if (CurSize < CurMaxSize / 4) {
        CurMaxSize = CurMaxSize / 2;
    }
    return true;
}

template<class Any>
void MyVector<Any>::SortVector() {
    if (!Arrange) {
        return;
    }
    for (int i = 0; i < CurSize; ++i) {
        for (int j = 0; j < CurSize - i - 1; ++j) {
            if (Arrange[j] > Arrange[j + 1]) {
                std::swap(Arrange[j], Arrange[j + 1]);
            }
        }
    }
}

template<>
void MyVector<char*>::SortVector() {
    if (!Arrange) {
        return;
    }
    for (int i = 0; i < CurSize; ++i) {
        for (int j = 0; j < CurSize - i - 1; ++j) {
            if (strcmp(Arrange[j + 1], Arrange[j]) < 0) {
                std::swap(Arrange[j], Arrange[j + 1]);
            }
        }
    }
}

template<class Any>
int MyVector<Any>::FindElement(Any element) {
    int Placement = -1;
    for (int i = 0; i < this->CurSize; ++i) {
        if (Arrange[i] == element) {
            Placement = i;
        }
    }
    return Placement;
}

template<>
int MyVector<char*>::FindElement(char* element) {
    int Placement = -1;
    for (int i = 0; i < this->CurSize; ++i) {
        if (!strcmp(Arrange[i], element)) {
            Placement =  i;
        }
    }
    return Placement;
}

template<class Any>
MyVector<Any>& MyVector<Any>::operator=(const MyVector<Any>& Vector) {
    if(this==&Vector){
        return *this;
    }
    delete[] Arrange;
    this->CurMaxSize = Vector.CurMaxSize;
    this->CurSize = Vector.CurSize;
    this->Arrange = new Any[CurMaxSize];
    for (int i = 0; i < CurSize; ++i) {
        this->Arrange[i] = Vector[i];
    }
    return *this;
}

template<>
MyVector<char*>& MyVector<char*>::operator=(const MyVector<char*>& Vector) {
    if(this==&Vector){
        return *this;
    }
    delete[] Arrange;
    this->CurMaxSize = Vector.CurMaxSize;
    this->CurSize = Vector.CurSize;
    this->Arrange = new char*[CurMaxSize];
    for (int i = 0; i < CurSize; ++i) {
        delete[] this->Arrange[i];
        this->Arrange[i]=new char[strlen(Vector[i])+1];
        strcpy(this->Arrange[i],Vector[i]);
    }
    return *this;
}

template<class Any>
const Any& MyVector<Any>::operator[](int i) const {
    if (i < 0 || i >= CurSize) {
        std::cout<<"Введены некорректные данные";
        return Arrange[CurMaxSize];
    }
    return Arrange[i];
}

template<class OtherAny>
std::ostream& operator<<(std::ostream& out, MyVector<OtherAny>& Vector) {
    for (int i = 0; i < Vector.CurSize; ++i) {
        out << Vector[i] << ' ';
    }
    return out;
}

template<class Any=const char*>
class MySet : public MyVector<Any> {
 public:
    MySet(Any element = NULL) : MyVector<Any>(element) {}

    void AddElement(Any element);
    void DeleteElement(Any element);
    bool IsInArrange(Any element) const;

    template <class OtherAny>
    friend std::ostream& operator<<(std::ostream& out, const MySet<OtherAny>& Set);
    template <class OtherAny>
    friend bool operator==(const MySet<OtherAny>& Alpha,const MySet<OtherAny>& Betta);
    template <class OtherAny>
    friend MySet<OtherAny>& operator+=( MySet<OtherAny>& Alpha,const MySet<OtherAny>& Betta);
    template <class OtherAny>
    friend MySet<OtherAny>& operator-=( MySet<OtherAny>& Alpha,const MySet<OtherAny>& Betta);
    template <class OtherAny>
    friend MySet<OtherAny>& operator*=( MySet<OtherAny>& Alpha,const MySet<OtherAny>& Betta);
    template <class OtherAny>
    friend MySet<OtherAny> operator+(const MySet<OtherAny>& Alpha, const MySet<OtherAny>& Betta);
    template <class OtherAny>
    friend MySet<OtherAny> operator-(const MySet<OtherAny>& Alpha, const MySet<OtherAny>& Betta);
    template <class OtherAny>
    friend MySet<OtherAny> operator*(const MySet<OtherAny>& Alpha, const MySet<OtherAny>& Betta);
};

template<class Any>
void MySet<Any>::AddElement(Any element) {
    if (!this->IsInArrange(element)) {
        MyVector<Any>::AddElement(element);
        this->SortVector();
    }
    return;
}

template<class Any>
void MySet<Any>::DeleteElement(Any element) {
    int index = this->FindElement(element);
    if (index != -1) {
        MyVector<Any>::DeleteElement(index);
    }
    return;
}

template<class Any>
bool MySet<Any>::IsInArrange(Any element)const  {
    for (int i = 0; i < this->CurSize; ++i) {
        if ((*this)[i] == element) {
            return true;
        }
    }
    return false;
}

template<>
bool MySet<char*>::IsInArrange(char* element) const{
    for (int i = 0; i < this->CurSize; ++i) {
        if (!strcmp((*this)[i], element)) {
            return true;
        }
    }
    return false;
}

template<class OtherAny>
std::ostream& operator<<(std::ostream& out, const MySet<OtherAny>& Set) {
    std::cout << "{";
    for (int i = 0; i < Set.CurSize; ++i) {
        if (i > 0) {
            std::cout << ", ";
        }
        std::cout << Set[i];
    }
    std::cout << "}";
    return out;
}

template<class OtherAny>
bool operator==(const MySet<OtherAny>& Alpha,const MySet<OtherAny>& Betta){
    if (Alpha.CurSize != Betta.CurSize) {
        return false;
    }
    for (int i = 0; i < Alpha.CurSize; ++i) {
        if (!(Betta.IsInArrange(Alpha[i]))) {
            return false;
        }
    }
    return true;
}

template<class OtherAny>
MySet<OtherAny>& operator+=(MySet<OtherAny>& Alpha,const MySet<OtherAny>& Betta) {
    for (int i = 0; i < Betta.CurSize; ++i) {
        Alpha.AddElement(Betta[i]);
    }
    return Alpha;
}

template<class OtherAny>
MySet<OtherAny>& operator-=( MySet<OtherAny>& Alpha,const MySet<OtherAny>& Betta) {
    for (int i = 0; i < Alpha.CurSize; ++i) {
        if (Betta.IsInArrange((Alpha[i]))) {
            Alpha.DeleteElement(Alpha[i--]);
        }
    }
    return Alpha;
}

template<class OtherAny>
MySet<OtherAny>& operator*=( MySet<OtherAny>& Alpha,const MySet<OtherAny>& Betta) {
    for (int i = 0; i < Alpha.CurSize; ++i) {
        if (!(Betta.IsInArrange(Alpha[i]))) {
            Alpha.DeleteElement(Alpha[i--]);
        }
    }
    return Alpha;
}

template<class OtherAny>
MySet<OtherAny> operator+(const MySet<OtherAny>& Alpha, const MySet<OtherAny>& Betta) {
    MySet<OtherAny> result = Alpha;
    result += Betta;
    return result;
}

template<class OtherAny>
MySet<OtherAny> operator-(const MySet<OtherAny>& Alpha, const MySet<OtherAny>& Betta) {
    MySet<OtherAny> result = Alpha;
    result -= Betta;
    return result;
}

template<class OtherAny>
MySet<OtherAny> operator*(const MySet<OtherAny>& Alpha, const MySet<OtherAny>& Betta) {
    MySet<OtherAny> result = Alpha;
    result *= Betta;
    return result;
}
