#pragma once
#include <iostream>
// #include "MyStack/MyStack.hpp"
#include "Product.hpp"

#pragma once

namespace StartApp{
enum class Task {
    Add = 1,
    Print = 2,
    Delete = 3,
    Clear = 4,
    Demo = 5,
    Exit = 6
};
enum class ProductType {
    Toy = 1,
    MilkProduct = 2,
    Item= 3
};

// void print(MyStack<ProductType*>& Products);
// bool remove(MyStack<ProductType*>& Products, int index);
// void clear(MyStack<ProductType*>& Products);

// void Menu();
// void AddEl(MyStac<ProductType*>& Products);
// void Print(MyStack<ProductType*>& Products);
// void Clear(MyStack<ProductType*>& Products);
// void Remove(MyStack<ProductType*>& Products, int index);
}
