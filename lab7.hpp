#pragma once
#include <iostream>
#include "stack/Stack.hpp"
#include "Product.hpp"

#pragma once

namespace Start{
    enum class ItemType {
        Toy = 1,
        MilkProduct = 2,
        ProductType= 3
    };

    void Menu();
    void AddElement(Stack<Item*>& Products);
    void PrintStack(Stack<Item*>& Products);
    void ClearStack(Stack<Item*>& Products);
    void RemoveElement(Stack<Item*>& Products, int index);
}
