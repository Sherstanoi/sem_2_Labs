#include "Product.hpp"

Item::Item(const char* Name){
    this->Name = new char[strlen(Name) + 1];
    strcpy(this->Name, Name);
    std::cout << "Item()" << std::endl;
}
Item::~Item(){
    delete[] Name;
    std::cout << "~Item()" << std::endl;
}

ProductType::ProductType(const char* Name, int Cost): Item(Name),Cost(Cost){
    std::cout << "ProductType()" << std::endl;
}
ProductType::~ProductType(){
    std::cout << "~ProductType()" << std::endl;
}

void ProductType::ShowInfo() const{
    std::cout<<"Название товара: "<<Name<<", его цена: "<<Cost<<std::endl;
}

Toy::Toy(const char* Name, int Cost,bool Softness): ProductType(Name,Cost),Softness(Softness){
    std::cout << "Toy()" << std::endl;
}
Toy::~Toy(){
    std::cout << "~Toy()" << std::endl;
}

void Toy::ShowInfo() const{
    std::cout << "Назваие игрушки: " << Name << ", стоимостью " << Cost << " рублей, мягкость: " << Softness << std::endl;
}

MilkProduct::MilkProduct(const char* Name, int Cost, int FatPercent): ProductType(Name,Cost),FatPercent(FatPercent){
    std::cout << "MilkProduct()" << std::endl;
}
MilkProduct::~MilkProduct(){
    std::cout << "~MilkProduct()" << std::endl;
}

void MilkProduct::ShowInfo() const{
    std::cout << "Назваие молочного продукта: " << Name << ",его стоимость: " << Cost << " рублей, количсетво жира: " << FatPercent << "%" <<std::endl;;
}
