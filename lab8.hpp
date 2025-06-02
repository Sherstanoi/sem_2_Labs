#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <random>
#include <cmath>
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
    bool DoublingTask4Vector();

    //номер 5
    int Task5();
   class Complex {
    public:
    double Material;
    double Imaginary;
        Complex() : Material(0), Imaginary(0) {}
        Complex(double Mat, double Imag) : Material(Mat), Imaginary(Imag) {
            if(floor(Material) == Material) {
                Material+=0.1;
            }
        }
        Complex(const Complex& alpha) {
            Material = alpha.Material;
            Imaginary = alpha.Imaginary;
        }
        friend std::ostream& operator<<(std::ostream& out, Complex& CompNumb);
        Complex operator+(Complex& alpha);
    };

    //номер 6
    int Task6();
    void PrintTask6(std::list<int> list);
    void DoubleListNumbers(std::list<int>& list);

    //номер 7
    int Task7();
    class Rectangle {
        private:
        double Width;
        double Length;

        public:
        Rectangle() : Width(1), Length(1) {}
        Rectangle(double SomeWidth, double SomeLength) : Width(SomeWidth), Length(SomeLength) {}
        bool operator==(const Rectangle& other) const { return (Width == other.Width && Length == other.Length); }
        bool operator<(const Rectangle& other) const { return (Width*Length < other.Width*other.Length); }
        friend std::ostream& operator<<(std::ostream& out, Rectangle& CompNumb);
    };
    void PrintTask7(std::list<Rectangle> SomeRect);

    //номер 8
    int Task8();

    //номер 9
    int Task9();
    void PrintTask9(std::map<std::string, std::string> cities);
