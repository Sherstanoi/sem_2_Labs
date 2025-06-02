#include "lab8.hpp"

//номер 1
int Task1(){
    std::string FirstString{};
    std::string SecondString{};
    std::string ThirdString{};
    std::string FinaleString{};
    std::cout<<"Введите три слова через пробел: ";
    std::cin >> FirstString >> SecondString >> ThirdString;
    FinaleString += FirstString[0];
    FinaleString += " ";
    FinaleString += SecondString[0];
    FinaleString += " ";
    FinaleString += ThirdString[0];
    std::cout<<FinaleString <<std::endl;
    return 0;
}

//номер 2
int Task2(){ // Сделай С и БЕЗ substr
    std::cin.ignore();
    std::string Sentance{};
    std::cout << "Введите предложение: ";
    std::getline(std::cin,Sentance);
    std::string FirstWord;
    std::string SecondWord;
    std::string FinaleSentance;
    int LastSpace = 0;
    int FirstSpace = 0;
    int SpaceCounter = 0;
    for(int i = 0; i< size(Sentance); ++i) {
        if(Sentance[i] == ' ' && Sentance[i-1] != ' ' && i!= 0) {
            SpaceCounter+=1;
            if(SpaceCounter == 1) {
                FirstSpace = i;
                FirstWord = Sentance.substr(0, i);
            }
            LastSpace = i;
        }
    }
    SecondWord = Sentance.substr(LastSpace+1, size(Sentance)- LastSpace);
    FinaleSentance = SecondWord + Sentance.substr(FirstSpace, LastSpace-(FirstSpace-1)) + FirstWord;
    std::cout<<FinaleSentance << std::endl;
    return 0;
}

//номер 3
int Task3(){
    std::string MessageFromFile{};
    std::ifstream in("Input.txt");
    std::ofstream out("Output.txt");
    while(getline(in,MessageFromFile)) {
        MessageFromFile = "e-mail: " + MessageFromFile + "\n";
        out<<MessageFromFile;
    }
    std::cout<<"Выполнено! проверьте, пожалуйста, файл Output.txt\n";
    return 0;
}

//номер 4 ПЕРЕДЕЛАТЬ
void DoublingTask4Vector(std::vector<int>& alpha) {
    for(int i = 0; i<size(alpha);i++) {
        alpha[i]*=2;
    }
    return;
}

void PrintTask4(std::vector<int> alpha) {
    for(int i = 0;i<alpha.size();++i){
        std::cout<<alpha[i]<<' ';
    }
    std::cout << std::endl;
}

int Task4() {
    std::vector<int> VectorTask4;
    for(int i = 0; i<5; ++i) {
        VectorTask4.push_back(rand()%100);
    }
    PrintTask4(VectorTask4);
    DoublingTask4Vector(VectorTask4);
    PrintTask4(VectorTask4);
    VectorTask4.erase(VectorTask4.begin()+2,VectorTask4.end()-2);
    PrintTask4(VectorTask4);
    return 0;
}

//номер 5
std::ostream& operator<<(std::ostream& out, Complex& CompNumb) {
    out<<CompNumb.Material;
    if(CompNumb.Imaginary <0) {
        out<<" - i * " << (CompNumb.Imaginary*-1) << "\n";
    } else{
        out<<" + i * " << CompNumb.Imaginary << "\n";
    }
    return out;
}
Complex Complex::operator+(Complex& alpha){
    Material+=alpha.Material;
    Imaginary+=alpha.Imaginary;
    return *this;
}

int Task5() {
    std::vector<Complex> ComplexNumbers =
    {Complex(-1.2, 6.3),Complex(4.0, 0.7),Complex(7.2, -0.8),Complex(5.3, 3.0),Complex(-4.9, 6.6),Complex(-9.3, 0.2)};
    for(int i = 0; i<size(ComplexNumbers); ++i) {
        std::cout<<ComplexNumbers[i];
    }
    Complex Summa = ComplexNumbers[0]+ComplexNumbers[1]+ComplexNumbers[2]+ComplexNumbers[3]+ComplexNumbers[4]+ComplexNumbers[5];
    std::cout << "\n" << "А теперь их сумма: " << Summa;
    return 0;
}

//номер 6
void PrintTask6(std::list<int> ListTask6) {
    std::cout << "Вот ваш список: ";
    for(int i : ListTask6) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return;
}

void DoubleListNumbers(std::list<int>& List) {
    std::list<int>::iterator Iterator = List.begin();
    for(int i : List) {
        *Iterator *=2;
        ++Iterator;
    }
    return;
}


int Task6() {
    std::list<int> ListTask6;
    for (int i = 0; i < 5; ++i) {
        ListTask6.push_back(rand()%100);
    }
    PrintTask6(ListTask6);
    DoubleListNumbers(ListTask6);
    PrintTask6(ListTask6);
    std::list<int>::iterator Iterator = ListTask6.begin();
    std::advance(Iterator,2);
    ListTask6.erase(Iterator);
    PrintTask6(ListTask6);
    return 0;
}

//номер 7
void PrintTask7(std::list<Rectangle> Rects) {
    for(Rectangle i : Rects) {
        std::cout<<i;
    }
    std::cout << std::endl;
}

std::ostream& operator<<(std::ostream& out,Rectangle& SomeRect){
    std::cout << "Длина: " << SomeRect.Length << " Ширина: " << SomeRect.Width << std::endl;
    return out;
}

int Task7() {
    std::list<Rectangle> Rectangles = {Rectangle(1.2, 6.3),Rectangle(4.0, 0.7),Rectangle(7.2, 0.8),Rectangle(5.3, 3.0),Rectangle(4.9, 6.6),Rectangle(9.3, 0.2)};
    PrintTask7(Rectangles);
    Rectangle MaxRect(0,0);
    for (Rectangle i : Rectangles) {
        if (MaxRect<i) {
            MaxRect = i;
        }
    }
    std::cout<< "Наибольший прямоугольник - " <<MaxRect << std::endl;;
    return 0;
}

//номер 8
int Task8(){
    std::map<std::string, int> Hundreds;
    Hundreds["one"] = 100;
    Hundreds["two"] = 200;
    Hundreds["three"] = 300;
    Hundreds["four"] = 400;
    Hundreds["five"] = 500;
    Hundreds["six"] = 600;
    std::cout << "Planets"<<'\n';
    for (std::map<std::string, int>::iterator Iterator = Hundreds.begin(); Iterator != Hundreds.end(); ++Iterator) {
        std::cout <<'"'<<Iterator->first<<'"' << "," << Iterator->second << "\n";
    }
    Hundreds.erase("five");
    Hundreds.erase("six");
    std::cout<< "\n" << "после удаления:" << "\n";
        for (std::map<std::string, int>::iterator Iterator = Hundreds.begin(); Iterator != Hundreds.end(); ++Iterator) {
        std::cout <<'"'<<Iterator->first<<'"' << "," << Iterator->second << "\n";
    }
    return 0;
}

//номер 9
void PrintTask9(std::map<std::string, std::string> PhoneNumbers) {
    std::cout << "Ваша телефонная книга:\n";
    std::map<std::string, std::string>::const_iterator Iterator;
    for (Iterator = PhoneNumbers.begin(); Iterator != PhoneNumbers.end(); ++Iterator) {
        std::cout <<'"' <<Iterator->first <<'"'<< ": " << Iterator->second << ",\n";
    }
    std::cout << std::endl;
}

int Task9() {
    std::map<std::string, std::string> PhoneNumbers;
    int Amount = 0;
    std::string Line;
    std::string Name;
    std::string PhoneNumber;
    std::cout<< "Сколько номеров вы хотите поместить в телефонную книгу? ";
    std::cin>>Amount;
    std::cin.ignore();
    for(int i = 0; i < Amount; ++i) {
        std::cout<<"Введите имя абонента и номер телефона через пробел^ ";
        std::getline(std::cin,Line);
        Name = Line.substr(0, Line.find(" "));
        PhoneNumber = Line.substr(Line.find(" ")+1, Line.size() - Line.find(" ")+1);
        PhoneNumbers[Name] = PhoneNumber;
    }
    PrintTask9(PhoneNumbers);
    std::cout << "Какой Абонент вы хотели бы удалить? Введите имя: ";
    std::cin>>Line;
    PhoneNumbers.erase(Line);
    PrintTask9(PhoneNumbers);
    return 0;
}
