#include "lab_4.hpp"

int main(int, char**) {
    try {
        int N{};
        /* MyStack<char> lol;
        lol.push('a');
        lol.push('b');
        lol.push('c');
        MyStack<char> lol1 = lol;
        MyStack<char> lol2;
        lol2.push('f');
        std::cout<<"lol2 based "<<lol2<<std::endl;
        std::cout<<"lol" << lol<<std::endl;
        lol2=lol1;
        std::cout<<"lol1 happened "<<lol1<<std::endl;


        std::cout<<"lol2 = "<<lol2<<std::endl; */





        std::cout<<"Введите целое число N:"<<std::endl;
        std::cin>>N;
        if (N <= 0) {
            throw std::runtime_error("Число N не валидно.");
        }
        MyStack<int> stack;
        Multipliers(N,stack);
        MyStack<int> stack2=stack;
        Reverse(stack2);
        Print(stack,N);
        Print(stack2,N);


    } catch (std::runtime_error& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}
