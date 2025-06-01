#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <random>
#include <iomanip>
#include <list>
#include <map>
#pragma once

namespace{
        int Choice;
        bool Flag = true;
}

    //номер 1
    int Task1();
    //номер 2
    int Task2();
    //номер 3
    int Task3();
    //номер 4
    int Task4();
    void PrintTask4(std::vector<bool> vector);
    bool RandomNumMultitask();
    //номер 5
    int Task5();
   // class Rectangle {
    // public:
    // double a;  // ширина
    // double b;  // длина
    //     Rectangle() : a(0), b(0) {}
    //     Rectangle(double a, double b) : a(a), b(b) {}
    //     friend std::ostream& operator<<(std::ostream& out, Rectangle& rec){
    //         out<<std::fixed << std::setprecision(1)<<std::setw(4)<<rec.a<<' '<<std::setw(4)<<rec.b<<'\n';
    //         return out;
    //     }
    //     bool Rectangle::operator<(Rectangle& rec){
    //         int s1=a*b;
    //         int s2=rec.a*rec.b;
    //         if(s1<s2){
    //             return true;
    //         }
    //         return false;
    //     }
    //     bool Rectangle::operator==(Rectangle& rec){
    //         int s1=a*b;
    //         int s2=rec.a*rec.b;
    //         if(s1==s2){
    //             return true;
    //         }
    //         return false;
    //     }
    //     double GetS(){
    //         return a*b;
    //     }
    // };
    //void PrintTask5(std::vector<Rectangle> vector);
    //номер 6
    int Task6();
    void PrintTask6(std::list<bool> list);
    void FindptrTask6(std::list<bool> list,std::list<bool>::iterator& iter);
    //номер 7
    int Task7();
    // class Date {
    //     private:
    //     int day;
    //     int month;
    //     int year;
    //     public:
    //     Date() : day(1), month(1), year(1970) {}
    //     Date(int d, int m, int y) : day(d), month(m), year(y) {}
    //     bool operator==(const Date& other) const { return (day == other.day && month == other.month && year == other.year); }
    //     bool operator<(const Date& other) const {
    //         if (year != other.year)
    //             return year < other.year;
    //         if (month != other.month)
    //             return month < other.month;
    //         return day < other.day;
    //     }
    //     friend std::ostream& operator<<(std::ostream& out, Date& rec);
    //     int GetYear() const { return year; }
    // };
    // std::ostream& operator<<(std::ostream& out,Date& rec){
    //     if(rec.day>9&&rec.month>9 ){
    //         out<<rec.day<<'.'<<rec.month<<'.'<<rec.year<<'\n';
    //     }
    //     if(rec.day>9&&rec.month<=9 ){
    //         out<<rec.day<<'.'<<'0'<<rec.month<<'.'<<rec.year<<'\n';
    //     }
    //     if(rec.day<=9&&rec.month>9 ){
    //         out<<'0'<<rec.day<<'.'<<rec.month<<'.'<<rec.year<<'\n';
    //     }
    //     if(rec.day<=9&&rec.month<=9 ){
    //         out<<'0'<<rec.day<<'.'<<'0'<<rec.month<<'.'<<rec.year<<'\n';
    //     }
    //     return out;
    // }
    // void PrintTask7(std::list<Date> list);
    //номер 8
    int Task8();
    //номер 9
    int Task9();
    void PrintTask9(std::map<std::string, int> cities);
