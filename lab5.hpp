#pragma once
#include <cstring>
#include <iostream>

const int OriginMaxSize = 1;

template<class Any>
class MyVector {
 protected:
    int CurMaxSize;
    int CurSize;
    Any* arrange;
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
        NewArrange[i] = arrange[i];
    }
    delete[] arrange;
    arrange = NewArrange;
}

template<class Any>
MyVector<Any>::MyVector(Any element , int MaxSize) : CurMaxSize(MaxSize), CurSize(0) {
    arrange = new Any[CurMaxSize];
    if (element) {
        AddElement(element);
    }
}

template<>
MyVector<char*>::MyVector(const MyVector& Vector) {
    CurMaxSize = Vector.CurMaxSize;
    CurSize = Vector.CurSize;
    arrange = new char*[CurMaxSize];
    for (int i = 0; i < CurSize; ++i) {
        arrange[i]=new char[strlen(Vector[i])+1];
        strcpy(arrange[i],Vector[i]);
    }
}

template<class Any>
MyVector<Any>::MyVector(const MyVector& Vector) {
    CurMaxSize = Vector.CurMaxSize;
    CurSize = Vector.CurSize;
    arrange = new Any[CurMaxSize];
    for (int i = 0; i < CurSize; ++i) {
        arrange[i] = Vector.arrange[i];
    }
}

template<>
MyVector<char*>::~MyVector() {
    for(int i =0;i<CurMaxSize;++i){
        delete[] arrange[i];
    }
    delete[] arrange;
}

template<class Any>
MyVector<Any>::~MyVector() {
    delete[] arrange;
}

template<>
void MyVector<char*>::AddElement(char* element) {
    if (CurSize >= CurMaxSize) {
        ChangeArrSize();
    }
    arrange[CurSize]=new char[strlen(element)+1];
    strcpy(arrange[CurSize],element);
    ++CurSize;
}

template<class Any>
void MyVector<Any>::AddElement(Any element) {
    if (CurSize >= CurMaxSize) {
        ChangeArrSize();
    }
    arrange[CurSize] = element;
    ++CurSize;
}

template<>
bool MyVector<char*>::DeleteElement(int i) {
    if (CurSize == 0 || i < 0 || i >= CurSize) {
        return false;
    }
    for (int j = i; j < CurSize - 1; ++j) {
        delete[] arrange[j];
        arrange[j]=new char[strlen(arrange[j+1])+1];
        strcpy(arrange[j],arrange[j+1]);
    }
    --CurSize;
    if (CurSize < CurMaxSize / 4) {
        CurMaxSize = CurMaxSize / 2;
    }
    return true;
}

template<class Any>
bool MyVector<Any>::DeleteElement(int i) {
    if (CurSize == 0 || i < 0 || i >= CurSize) {
        return false;
    }
    for (int j = i; j < CurSize - 1; ++j) {
        arrange[j] = arrange[j + 1];
    }
    --CurSize;
    if (CurSize < CurMaxSize / 4) {
        CurMaxSize = CurMaxSize / 2;
    }
    return true;
}

template<>
void MyVector<char*>::SortVector() {
    if (!arrange) {
        return;
    }
    for (int i = 0; i < CurSize; ++i) {
        for (int j = 0; j < CurSize - i - 1; ++j) {
            if (!(strcmp(arrange[j + 1], arrange[j]) > 0)) {
                std::swap(arrange[j], arrange[j + 1]);
            }
        }
    }
} //ВОЗМОЖНО, НУЖНО ТАКОЕ ЖЕ, НО КОНСТ

template<class Any>
void MyVector<Any>::SortVector() {
    if (!arrange) {
        return;
    }
    for (int i = 0; i < CurSize; ++i) {
        for (int j = 0; j < CurSize - i - 1; ++j) {
            if (arrange[j] > arrange[j + 1]) {
                std::swap(arrange[j], arrange[j + 1]);
            }
        }
    }
}

template<>
int MyVector<char*>::FindElement(char* element) {
    for (int i = 0; i < this->CurSize; ++i) {
        if (!strcmp(arrange[i], element)) {
            return i;
        }
    }
    return -1;
} // ВОЗМОЖНО, НУЖНО ТАКОЕ ЖЕ, НО КОНСТ ЧАР

template<class Any>
int MyVector<Any>::FindElement(Any element) {
    for (int i = 0; i < this->CurSize; ++i) {
        if (arrange[i] == element) {
            return i;
        }
    }
    return -1;
}

template<>
MyVector<char*>& MyVector<char*>::operator=(const MyVector<char*>& Vector) {
    if(this==&Vector){
        return *this;
    }
    delete[] arrange;
    this->CurMaxSize = Vector.CurMaxSize;
    this->CurSize = Vector.CurSize;
    this->arrange = new char*[CurMaxSize];
    for (int i = 0; i < CurSize; ++i) {
        delete[] this->arrange[i];
        this->arrange[i]=new char[strlen(Vector[i])+1];
        strcpy(this->arrange[i],Vector[i]);
    }
    return *this;
}

template<class Any>
MyVector<Any>& MyVector<Any>::operator=(const MyVector<Any>& Vector) {
    if(this==&Vector){
        return *this;
    }
    delete[] arrange;
    this->CurMaxSize = Vector.CurMaxSize;
    this->CurSize = Vector.CurSize;
    this->arrange = new Any[CurMaxSize];
    for (int i = 0; i < CurSize; ++i) {
        this->arrange[i] = Vector.arrange[i];
    }
    return *this;
}

template<class Any>
const Any& MyVector<Any>::operator[](int i) const {
    if (i < 0 || i >= CurSize) {
        throw std::invalid_argument("NONVALID");
    }
    return arrange[i];
}

template<class OtherAny>
std::ostream& operator<<(std::ostream& out, MyVector<OtherAny>& Vector) {
    for (int i = 0; i < Vector.CurSize; ++i) {
        out << Vector[i] << ' ';
    }
    out << '\n';
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
    friend std::ostream& operator<<(std::ostream& out, const MySet<OtherAny>& s);
    template <class OtherAny>
    friend bool operator==(const MySet<OtherAny>& Alpha,const MySet<OtherAny>& Betta);
    template <class OtherAny>
    friend MySet<OtherAny>& operator+=( MySet<OtherAny>& Alpha,const MySet<OtherAny>& Betta);
    template <class OtherAny>
    friend MySet<OtherAny>& operator-=( MySet<OtherAny>& Alpha,const MySet<OtherAny>& Betta);
    template <class OtherAny>
    friend MySet<OtherAny>& operator*=( MySet<OtherAny>& Alpha,const MySet<OtherAny>& Betta);
    template <class OtherAny>
    friend MySet<OtherAny> operator+(const MySet<OtherAny>& s1, const MySet<OtherAny>& s2);
    template <class OtherAny>
    friend MySet<OtherAny> operator-(const MySet<OtherAny>& s1, const MySet<OtherAny>& s2);
    template <class OtherAny>
    friend MySet<OtherAny> operator*(const MySet<OtherAny>& s1, const MySet<OtherAny>& s2);
};

template<class Any>
void MySet<Any>::AddElement(Any element) {
    if (!this->IsInArrange(element)) {
        MyVector<Any>::AddElement(element);
        this->SortVector();
    }
}

template<class Any>
void MySet<Any>::DeleteElement(Any element) {
    int index = this->FindElement(element);
    if (index != -1) {
        MyVector<Any>::DeleteElement(index);
    }
}

template<>
bool MySet<char*>::IsInArrange(char* element) const{
    int left = 0;
    int right = this->CurSize - 1;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (std::strcmp((*this)[middle],  element) > 0) {
            right = middle - 1;
        }
         else {
            left = middle + 1;
        }
        if (std::strcmp((*this)[middle],  element) == 0) {
            return true;
        }
    }
    return false;
} // ВОЗМОЖНО, НУЖНО ТАКОЕ ЖЕ, НО КОНСТ ЧАР

template<class Any>
bool MySet<Any>::IsInArrange(Any element)const  {
    int left = 0;
    int right = this->CurSize - 1;
    while (left <= right) {
        int middle = (left + right) / 2;
        if ((*this)[middle] > element) {
            right = middle - 1;
        } else {
            left = middle + 1;
        }
        if ((*this)[middle] == element) {
            return true;
        }
    }
    return false;
}

template<class OtherAny>
std::ostream& operator<<(std::ostream& out, const MySet<OtherAny>& s) {
    out << "{";
    for (int i = 0; i < s.CurSize; ++i) {
        if (i > 0) {
            out << ", ";
        }
        out << s[i];
    }
    out << "}";
    return out;
}

template<class OtherAny>
bool operator==(const MySet<OtherAny>& Alpha,const MySet<OtherAny>& Betta){
    if (Alpha.CurSize != Betta.CurSize) {
        return false;
    }
    for (int i = 0; i < Alpha.CurSize; ++i) {
        if (!Betta.IsInArrange(Alpha[i])) {
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
        if (!Betta.IsInArrange(Alpha[i])) {
            Alpha.DeleteElement(Alpha[i--]);
        }
    }
    return Alpha;
}

template<class OtherAny>
MySet<OtherAny> operator+(const MySet<OtherAny>& s1, const MySet<OtherAny>& s2) {
    MySet<OtherAny> result = s1;
    result += s2;
    return result;
}

template<class OtherAny>
MySet<OtherAny> operator-(const MySet<OtherAny>& s1, const MySet<OtherAny>& s2) {
    MySet<OtherAny> result = s1;
    result -= s2;
    return result;
}

template<class OtherAny>
MySet<OtherAny> operator*(const MySet<OtherAny>& s1, const MySet<OtherAny>& s2) {
    MySet<OtherAny> result = s1;
    result *= s2;
    return result;
}
