#pragma once
#include <cstring>
#include <iostream>
class Item{
    protected:
        char* Name;
    public:
        Item(const char* Name);
        virtual ~Item();
        virtual void ShowInfo() const = 0;
};

class ProductType: public Item{
    protected:
        int Cost;
    public:
        ProductType(const char* Name, int Cost);
        ~ProductType() override;
        void ShowInfo() const override;
};

class Toy: public ProductType{
    protected:
        bool Softness;
    public:
        Toy(const char* Name, int Cost, bool Softness);
        ~Toy() override;
        void ShowInfo() const override;
};

class MilkProduct: public ProductType{
    protected:
        int FatPercent;
    public:
        MilkProduct(const char* Name, int cost, int FatPercent);
        ~MilkProduct() override;
        void ShowInfo() const override;
};
