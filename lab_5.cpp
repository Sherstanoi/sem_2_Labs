#include "lab5.hpp"
#include "Lab5Fun.hpp"

void start() {
    MyVector v("Hello!");
    v.AddElement("Привет!");
    v.AddElement("Привет!");
    v.AddElement("Привет!");
    v.AddElement("Привет!");
    v.AddElement("Привет!");
    std::cout << "Вектор v: " << v << std::endl;
    v.AddElement("Привет!");
    v.AddElement("Привет!");
    v.AddElement("Привет!");
    std::cout << "Вектор v: " << v << std::endl;
    MyVector v1 = v;
    std::cout << "Вектор v1: " << v1 << std::endl;
    for (int i = 0; i < OriginMaxSize; i++)
        v1.DeleteElement(0);
    std::cout << "Вектор v1: " << v1 << std::endl;
    MySet s("Yes"), s1, s2;
    s.AddElement("Привет!");
    s.AddElement("No");
    const char* str = "Hello!";
    s.AddElement(str);
    std::cout << "Множество s: " << s << std::endl;
    s1.AddElement("Cat");
    s1.AddElement("No");
    s1.AddElement("Привет!");
    std::cout << "Множество s1: " << s1 << std::endl;
    s2 = s1 - s;
    std::cout << "Множество s2=s1-s: " << s2 << std::endl;
    std::cout << "Множество s1: " << s1 << std::endl;
    std::cout << "Множество s: " << s << std::endl;
    s2 = s - s1;
    std::cout << "Множество s2=s-s1: " << s2 << std::endl;
    std::cout << "Множество s1: " << s1 << std::endl;
    std::cout << "Множество s: " << s << std::endl;
    s2 = s1 + s;
    std::cout << "Множество s2=s1+s: " << s2 << std::endl;
    std::cout << "Множество s1: " << s1 << std::endl;
    std::cout << "Множество s: " << s << std::endl;
    s2 = s1 * s;
    std::cout << "Множество s2=s1*s: " << s2 << std::endl;
    std::cout << "Множество s1: " << s1 << std::endl;
    std::cout << "Множество s: " << s << std::endl;
    MySet s3 = s2;
    std::cout << "Множество s3=s2: " << s3 << std::endl;
    if (s3 == s2)
        std::cout << "Множество s3=s2\n";
    else
        std::cout << "Множество s3!=s2\n";
    if (s3 == s1)
        std::cout << "Множество s3=s1\n";
    else
        std::cout << "Множество s3!=s1\n";
    if (s1 == s3)
        std::cout << "Множество s1=s3\n";
    else
        std::cout << "Множество s1!=s3\n";
    MySet s9(1);
    s9.AddElement(4);
    s9.AddElement(5);
    s9.AddElement(6);
    MySet s10(1);
    s10.AddElement(2);
    s10.AddElement(3);
    s10.AddElement(4);
    std::cout<<s9<<std::endl;
    std::cout<<s10<<std::endl;
    MySet ss=s9+s10;
    std::cout<<"+"<<ss<<std::endl;
    MySet ss1=s9*s10;
    std::cout<<"*"<<ss1<<std::endl;
    ss=s9-s10;
    std::cout<<"-"<<ss<<std::endl;
    return;
}
