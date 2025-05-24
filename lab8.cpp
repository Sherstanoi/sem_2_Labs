#include "lab8.hpp"

//номер 1
int Task1(){
    std::string String{};
    std::getline(std::cin,String);
    std::vector<int> positions{};
    int FoundPosition=0;
    int start=0;
    while(true){
        FoundPosition=String.find('@',start);
        if(FoundPosition!=std::string::npos){
            positions.push_back(FoundPosition);
            start=FoundPosition+1;
        }else{
            break;
        }
    }
    for(int i =0;i<positions.size();++i){
        std::cout<<positions[i]<<' ';
    }
    positions.clear();
    return 0;
}

//номер 2
int Task2(){
    std::string String{};
    std::getline(std::cin,String);
    for(int i = 0;i<(String.length()/2);++i){
        std::swap(String[i],String[String.length()-(i-1)]);
    }
    for(int i =0;i<String.length();++i){
        std::cout<<String[i];
    }
    return 0;
}

//номер 3
int Task3(){
    std::string String{};
    std::ifstream in("in.txt"); //Проверь файлы в гите
    std::ofstream out("out.txt");
    if(in&&out){
        while(in>>String){
            out<<String<<'\n';
        }
    }
    return 0;
}

//номер 4 ПЕРЕДЕЛАТЬ
bool RandomNumMultitask() {
    std::random_device Rand{};
    std::default_random_engine randomEngine(Rand()); //?
    std::uniform_int_distribution distribution(0, 1);
    return distribution(randomEngine);
}

void PrintTask4(std::vector<bool> vector) {
    for(int i = 0;i<vector.size();++i){
        std::cout<<vector[i]<<' ';
    }
    std::cout << std::endl;
}

int Task4() {
    std::vector<bool> Vector4;
    for (int i = 0; i < 20; ++i) {
        Vector4.push_back(RandomNumMultitask());
    }
    PrintTask4(Vector4);
    int counterTrue = std::count(Vector4.begin(), Vector4.end(), true);
    int counterFalse = std::count(Vector4.begin(), Vector4.end(), false);
    std::cout << "True: " << counterTrue << " False: " << counterFalse << std::endl;
    Vector4.erase(Vector4.begin(), Vector4.begin() + 10);
    PrintTask4(Vector4);
    return 0;
}

//номер 5 ПЕРЕДЕЛАТЬ
// void PrintTask5(std::vector<Rectangle> vector){
//     for(int i = 0;i<vector.size();++i){
//         std::cout<<vector[i];
//     }
// }

// int Task5() {
//     std::vector<Rectangle> Rectangles={{1.2,6.3},{4.0,0.7}};
//     //{Rectangle(1.2, 6.3),Rectangle(4.0, 0.7),Rectangle(7.2, 0.8),Rectangle(5.3, 3.0),Rectangle(4.9, 6.6),Rectangle(9.3, 0.2)};
//     PrintTask5(Rectangles);
//     Rectangle maxi{};
//     double ms=0; //?
//     int msi=0;
//     for (int i = 0; i < Rectangles.size(); ++i) {
//         ms=std::max(ms,Rectangles[i].GetS());
//         if(ms==Rectangles[i].GetS()){
//             msi=i;
//         }
//     }
//     std::cout << "BiggestRECTANGLE " << Rectangles[msi];
//     Rectangles.clear();
//     return 0;
// }

//номер 6 ПЕРЕДЕЛАТЬ
void FindptrTask6(std::list<bool> list,std::list<bool>::iterator& Iterator){
    int i=0;
    while(i<10){
        ++Iterator;
        ++i;
    }
}

void PrintTask6(std::list<bool> list) { //СРАВНИ ПРИНТЫ
    std::list<bool>::iterator Iterator;
    for(Iterator = list.begin();Iterator!= list.end();++Iterator){
        std::cout<< *Iterator<<' ';
    }
    std::cout << std::endl;
}

int Task6() {
    std::list<bool> list;
    for (int i = 0; i < 20; ++i) {
        list.push_back(RandomNumMultitask());
    }
    PrintTask6(list);
    int counterTrue = std::count(list.begin(), list.end(), true);
    int counterFalse = std::count(list.begin(), list.end(), false);
    std::cout << "True: " << counterTrue << " False: " << counterFalse << std::endl;
    std::list<bool>::iterator Iterator=list.begin();;
    FindptrTask6(list,Iterator);
    list.erase(list.begin(),Iterator);
    PrintTask6(list);
    return 0;
}

//номер 7 ПЕРЕДЕЛАТЬ
// void PrintTask7(std::list<Date> list) {
//     std::list<Date>::iterator Iterator;
//     for(Iterator = list.begin();Iterator!= list.end();++Iterator){
//         std::cout<< *Iterator;
//     }
//     std::cout << std::endl;
// }

// int Task7() {
//     std::list<Date> dates={Date(1, 2, 1963),Date(14, 7, 1995),Date(7, 12, 2088),Date(5, 3, 2030),Date(24, 9, 2013),Date(19, 9, 2025)};
//     PrintTask7(dates);
//     Date today={17,4,2025};
//     std::list<Date> futureDates;
//     for (Date date : dates) {
//         if (today<date) {
//             futureDates.push_back(date);
//         }
//     }

//     std::cout << "Future" << std::endl;
//     PrintTask7(futureDates);
//     return 0;
// }

//номер 8
int Task8(){
    std::map<std::string, int> planets;
    planets["Меркурий"] = 0;
    planets["Венера"] = 0;
    planets["Земля"] = 1;
    planets["Марс"] = 2;
    planets["Юпитер"] = 69;
    planets["Сатурн"] = 62;
    planets["Уран"] = 27;
    planets["Нептун"] = 14;
    planets["Плутон"] = 10;
    std::cout << "Planets"<<'\n';
    for (std::map<std::string, int>::iterator Iterator = planets.begin(); Iterator != planets.end(); ++Iterator) {
        std::cout <<'"'<<Iterator->first<<'"' << "," << Iterator->second << "\n";
    }
    std::map<std::string, int>::iterator maxPlanet = planets.begin();
    for (std::map<std::string, int>::iterator Iterator = planets.begin(); Iterator != planets.end(); ++Iterator) {
        if (maxPlanet->second<Iterator->second) {
            maxPlanet = Iterator;
        }
    }
    std::cout << "MaxPlanet " << maxPlanet->first << " " << maxPlanet->second<<std::endl;
    return 0;
}

//номер 9
void PrintTask9(std::map<std::string, int> cities) {
    std::cout << "Список городов и их расстояние от Москвы:\n";
    std::map<std::string, int>::const_iterator Iterator;
    for (Iterator = cities.begin(); Iterator != cities.end(); ++Iterator) {
        std::cout <<'"' <<Iterator->first <<'"'<< ": " << Iterator->second << ",\n";
    }
    std::cout << std::endl;
}

int Task9() {
    std::map<std::string, int> cities;
    cities["Минск"] = 713;
    cities["Киев"] = 856;
    cities["Санкт-Петербург"] = 786;
    cities["Астана"] = 2748;
    cities["Нижний Новгород"] = 421;
    cities["Владивосток"] = 9141;
    PrintTask9(cities);
    std::map<std::string, int>::iterator minCity = cities.begin();
    std::map<std::string, int>::iterator maxCity = cities.begin();
    std::map<std::string, int>::iterator Iterator;
    for  (Iterator = cities.begin(); Iterator != cities.end(); ++Iterator) {
        if (Iterator->second < minCity->second) {
            minCity = Iterator;
        }
        if (maxCity->second<Iterator->second) {
            maxCity = Iterator;
        }
    }
    std::cout << "Ближайший: " <<'"' <<minCity->first <<'"'<< ": " << minCity->second << ",\n";;
    std::cout << "Дальний: " <<'"' <<maxCity->first <<'"'<< ": " << maxCity->second << ",\n";
    return 0;
}
