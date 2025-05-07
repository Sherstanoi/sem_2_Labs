#include "lab5.hpp"
#include "Lab5Fun.hpp"

void start() {
    bool Flag = true;
    while(Flag) {
        int Choice = 0;
        std::cout<< "Какой функцией вы хотели бы воспользоваться? \n1.вывести задние по ТЗ \n2. закончить \n";
        std::cin>> Choice;
        switch (Choice)
        {
        case 1: {
            MyVector TestVector("Hello!");
            TestVector.AddElement("How");
            TestVector.AddElement("Are");
            TestVector.AddElement("You");
            TestVector.AddElement("Doing?");
            TestVector.AddElement("Привет!");
            std::cout << "Вектор TestVector: " << TestVector << std::endl;
            TestVector.AddElement("Как");
            TestVector.AddElement("твои");
            TestVector.AddElement("дела?");
            std::cout << "Вектор TestVector: " << TestVector << std::endl;
            MyVector SecondTestVector = TestVector;
            std::cout << "Вектор SecondTestVector: " << SecondTestVector << std::endl;
            for (int i = 0; i < OriginMaxSize; i++)
                SecondTestVector.DeleteElement(0);
            std::cout << "Вектор SecondTestVector: " << SecondTestVector << std::endl;
            std::cout<<"\n";
            MySet FirstTestSet("Yes"), SecondTestSet, ThirdTestSet;
            FirstTestSet.AddElement("Привет!");
            FirstTestSet.AddElement("No");
            const char* Line = "Hello!";
            FirstTestSet.AddElement(Line);
            std::cout << "Множество FirstTestSet: " << FirstTestSet << std::endl;
            SecondTestSet.AddElement("Cat");
            SecondTestSet.AddElement("No");
            SecondTestSet.AddElement("Привет!");
            std::cout << "Множество SecondTestSet: " << SecondTestSet << std::endl;
            ThirdTestSet = SecondTestSet - FirstTestSet;
            std::cout << "Множество ThirdTestSet=SecondTestSet-FirstTestSet: " << ThirdTestSet << std::endl;
            std::cout << "Множество SecondTestSet: " << SecondTestSet << std::endl;
            std::cout << "Множество FirstTestSet: " << FirstTestSet << std::endl;
            ThirdTestSet = FirstTestSet - SecondTestSet;
            std::cout << "Множество ThirdTestSet=FirstTestSet-SecondTestSet: " << ThirdTestSet << std::endl;
            std::cout << "Множество SecondTestSet: " << SecondTestSet << std::endl;
            std::cout << "Множество FirstTestSet: " << FirstTestSet << std::endl;
            ThirdTestSet = SecondTestSet + FirstTestSet;
            std::cout << "Множество ThirdTestSet=SecondTestSet+FirstTestSet: " << ThirdTestSet << std::endl;
            std::cout << "Множество SecondTestSet: " << SecondTestSet << std::endl;
            std::cout << "Множество FirstTestSet: " << FirstTestSet << std::endl;
            ThirdTestSet = SecondTestSet * FirstTestSet;
            std::cout << "Множество ThirdTestSet=SecondTestSet*FirstTestSet: " << ThirdTestSet << std::endl;
            std::cout << "Множество SecondTestSet: " << SecondTestSet << std::endl;
            std::cout << "Множество FirstTestSet: " << FirstTestSet << std::endl;
            MySet FourthTestSet = ThirdTestSet;
            std::cout << "Множество FourthTestSet=ThirdTestSet: " << FourthTestSet << std::endl;
            if (FourthTestSet == ThirdTestSet)
                std::cout << "Множество FourthTestSet=ThirdTestSet\n";
            else
                std::cout << "Множество FourthTestSet!=ThirdTestSet\n";
            if (FourthTestSet == SecondTestSet)
                std::cout << "Множество FourthTestSet=SecondTestSet\n";
            else
                std::cout << "Множество FourthTestSet!=SecondTestSet\n";
            if (SecondTestSet == FourthTestSet)
                std::cout << "Множество SecondTestSet=FourthTestSet\n";
            else
                std::cout << "Множество SecondTestSet!=FourthTestSet\n";
            std::cout<<"\n";
            MySet FifthTestSet(1);
            FifthTestSet.AddElement(4);
            FifthTestSet.AddElement(5);
            FifthTestSet.AddElement(6);
            MySet SixthTestSet(1);
            SixthTestSet.AddElement(2);
            SixthTestSet.AddElement(3);
            SixthTestSet.AddElement(4);
            std::cout<<FifthTestSet<<std::endl;
            std::cout<<SixthTestSet<<std::endl;
            MySet PreLastTestSet=FifthTestSet+SixthTestSet;
            std::cout<<"+"<<PreLastTestSet<<std::endl;
            MySet LastTestSet=FifthTestSet*SixthTestSet;
            std::cout<<"*"<<LastTestSet<<std::endl;
            PreLastTestSet=FifthTestSet-SixthTestSet;
            std::cout<<"-"<<PreLastTestSet<<std::endl;
            break;
            }
        case 2:
            Flag = false;
            break;
        default:
            std::cout<<"Введены неправильныеданные";
            break;
        }
    }
    return;
}
