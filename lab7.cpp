#include "lab7.hpp"
typedef ListNode<Item*, Stack<Item*>> Node;

namespace Start{

    void Menu() {
        Stack<Item*> ItemsList;
        int Choice = 0;
        while (static_cast<Task>(Choice) != Task::Exit) {
            std::cout << "Выберите номер, интересующего вас действия, и введите его в консоль для перехода\n1. Добавить элемент в список\n2. Печать списка\n3. Удалить элемент по индексу\n4. Очистить список\n 5. Выход\n";
            std::cin >> Choice;
            std::cout << std::endl;
            switch (static_cast<Task>(Choice)) {
                case Task::Add:
                    AddElement(ItemsList);
                    break;
                case Task::PrintStack:
                    PrintStack(ItemsList);
                    break;
                case Task::Delete: {
                    int index;
                    std::cout << "Введите индекс элемента для удаления: "<<std::endl;
                    std::cin >> index;
                    RemoveElement(ItemsList, index);
                    break;
                }
                case Task::ClearStack:
                    ClearStack(ItemsList);
                    break;
                case Task::Exit:
                    ClearStack(ItemsList);
                    break;
                default:
                    std::cout << "Введены некорректные данные" << std::endl;
                    break;
            }
        }
    }

void ClearStack(Stack<Item*>& ItemsList){
    while (!ItemsList.EmptyCheck()) {
        Item* ElementOfStack = ItemsList.FirstElementInf();
        delete ElementOfStack;
        ItemsList.PopElement();
    }
    return;
}

void PrintStack(Stack<Item*>& ItemsList){
    if (ItemsList.EmptyCheck()) {
        std::cout << "Стек пуст" << std::endl;
        return;
    }
    int i = 0;
    std::cout << "Содержимое стека:" << std::endl;
    Node* ElementOfStack = ItemsList.GetTopElementInfo();
    std::cout << i++ << ") ";
    ((ElementOfStack->GetNumber()))->ShowInfo();
    ElementOfStack = ElementOfStack->GetNextElement();
    while (ElementOfStack) {
        std::cout << i++ << ") ";
        ((ElementOfStack->GetNumber()))->ShowInfo();
        ElementOfStack=ElementOfStack->GetNextElement();
    }
    return;
}

void RemoveElement(Stack<Item*>& ItemsList, int index){
    if (ItemsList.EmptyCheck()) {
        std::cout << "Список пуст" << std::endl;
    }
    Node* ElementOfStack = ItemsList.GetTopElementInfo();
    Node* PreviousElement = ItemsList.GetTopElementInfo();
    int i = 0;
    while(ElementOfStack){
        if(i == index){
            if(ElementOfStack->GetNextElement()){
                if(i == 0){
                    ItemsList.SetTopElementInfo(ElementOfStack->GetNextElement());
                }else{
                    PreviousElement->SetNextElement(ElementOfStack->GetNextElement());
                }
            }else{
                PreviousElement->SetNextElement(nullptr);
            }
            if (i==0 && !(ElementOfStack->GetNextElement())){ //По идее, можно удалить
                ItemsList.SetTopElementInfo(nullptr);
            }
            delete ElementOfStack->GetNumber();
            delete ElementOfStack;
            break;
        }
        ++i;
        PreviousElement=ElementOfStack;
        ElementOfStack=ElementOfStack->GetNextElement();
    }
    if(!ElementOfStack){
        std::cout<<"Такого индекса нет"<<std::endl;
    }
}

void AddElement(Stack<Item*>& ItemsList) {
    int type;
    std::cout << "Выберите вид продукта, пожалуйста:" << std::endl;
    std::cout << "1. Игрушка" << std::endl;
    std::cout << "2. Молочное изделие" << std::endl;
    std::cout << "3. Неклассифицированные товары" << std::endl;
    std::cin >> type;
    char Name[100];
    std::cout << "Введите название, пожалуйста: "<< std::endl;
    std::cin.ignore();
    std::cin.getline(Name, 100);
    switch (static_cast<ItemType>(type)) {
        case ItemType::Toy: {
            bool TempSoftness;
            char* Answer;
            int Cost;
            std::cout << "мягкая ли игрушка(yes/no): "<<std::endl;
            std::cin >> Cost;
            std::cout << "Мягкая ли игрушка(yes/no): "<<std::endl;
            std::cin >> Answer;
            if(Answer == "yes" || Answer == "Yes") {
                TempSoftness = true;
            } else if(Answer == "no" || Answer == "No") {
                TempSoftness = false;
            } else {
                std::cout<< "Введены некорректные данные";
                break;
            }
            ItemsList.PushElement(new Toy(Name,Cost,TempSoftness));
            break;
        }
        case ItemType::MilkProduct: {
            int TempFatPercent;
            int Cost;
            std::cout << "Введите цену товара, пожалуйста "<<std::endl;
            std::cin >> Cost;
            std::cout << "Введите количество жира в процентах, пожалуйста: "<<std::endl;
            std::cin >> TempFatPercent;
            ItemsList.PushElement(new MilkProduct(Name,Cost,TempFatPercent));
            break;
        }
        case ItemType::ProductType: {
            int Cost;
            std::cout << "Введите цену,пожалуйста: "<<std::endl;
            std::cin >> Cost;
            ItemsList.PushElement(new ProductType(Name, Cost));
            break;
        }
        default:
            std::cout << "Такого типа нет" << std::endl;
    }
    std::cout <<'\n';
    }
}
