#include <iostream>
#pragma once

template <class INF>
class Stack;

template <class INF, class FRIEND>
class ListNode {
private:
  INF Number;
  ListNode *NextElementAddress;

  ListNode() {
    NextElementAddress = nullptr;
  }
  ListNode(const ListNode &betta) {
    *this->Number = betta.Number;
    *this->NextElementAddress = nullptr;
  }
  ListNode &operator=(const ListNode &betta) {
    if (this != &betta) {
      *this->Number = betta.Number;
      *this->NextElementAddressext = betta.NextElementAddress;
    }
    return *this;
  }

  friend FRIEND;
  template <class T>
  friend std::ostream &operator<<(std::ostream &out, const Stack<T> &Element);

  public:
    INF GetNumber(){
      return Number;
    }
  ListNode* GetNextElement(){
      return NextElementAddress;
    }
  void SetNextElement(ListNode* NewNextElementAddress){
      NextElementAddress=NewNextElementAddress;
    }
};

template <class INF>
class Stack {
  private:
    typedef class ListNode<INF, Stack<INF>> Node;
    Node *FirstElement;

  public:
    Stack(void);
    ~Stack(void);

    bool EmptyCheck();
    void PushElement(INF NewElement);
    void PopElement();
    INF FirstElementInf();
    Node* GetTopElementInfo(){
      return FirstElement;
    }
  void SetTopElementInfo(Node* NewTopElement ){
      FirstElement = NewTopElement;
    }

    Stack(const Stack &other);
    Stack<INF> &operator=(const Stack<INF> &other);
    Stack<INF> &operator+( Stack<INF> &other);

    friend std::ostream &operator<< <>(std::ostream &out, const Stack &Element);
};

template <class INF>
bool Stack<INF>::EmptyCheck() {
  if (FirstElement) {
    return false;
  }
  return true;
}

template <class INF>
void Stack<INF>::PushElement(INF InputNumber) {
  Node *NewStackElement = new Node;
  NewStackElement->Number = InputNumber;
  NewStackElement->NextElementAddress = FirstElement;
  FirstElement = NewStackElement;
  return;
}

template <class INF>
void Stack<INF>::PopElement() {
  if (!EmptyCheck()) {
    Node *DeletingElment = FirstElement;
    FirstElement = FirstElement->NextElementAddress;
    delete DeletingElment;
    return;
  } else {
    std::cout<<"В стеке нет элементов" << std::endl;
    return;
  }
  return;
}

template <class INF>
INF Stack<INF>::FirstElementInf() {
  if (EmptyCheck()) {
    std::cout<<"В стеке нет элементов" << '\n';
    return 0;
  }
  return FirstElement->Number;
}

template <class INF> Stack<INF>::Stack() {
  FirstElement = nullptr;
}

template <class INF> Stack<INF>::~Stack() {
  while (!EmptyCheck()) {
    PopElement();
  }
}

template <class INF>
Stack<INF> &Stack<INF>::operator=(const Stack &other) {
  FirstElement = nullptr;
  if (this == &other) {
    return *this;
  }
  while (!EmptyCheck()) {
    PopElement();
  }
  if (other.FirstElement) {
    Node *CurrentElement = other.FirstElement;
    Node *PreviousElement = nullptr;
    while (CurrentElement) {
      Node *NewStackElement = new Node;
      NewStackElement->Number = CurrentElement->Number;
      if (!FirstElement) {
        FirstElement = NewStackElement;
      } else {
        PreviousElement->NextElementAddress = NewStackElement;
      }
      PreviousElement = NewStackElement;
      CurrentElement = CurrentElement->NextElementAddress;
    }
  }
  return *this;
}

template <class INF>
Stack<INF>& Stack<INF>::operator+(Stack &other) {
  Node* CurrentElement =  new Node;
  Node* OtherElement = new Node;
  CurrentElement = FirstElement;
  OtherElement = other.FirstElement;
    while(OtherElement) {
    PushElement(OtherElement->Number);
    OtherElement = OtherElement->NextElementAddress;
  }
  return *this;
}

template <class INF>
Stack<INF>::Stack(const Stack &other) {
  *this = other;
}

template <class INF>
std::ostream &operator<<(std::ostream &out, const Stack<INF> &Element) {
  typename Stack<INF>::Node *CurrentElement = Element.FirstElement;
  out << CurrentElement->Number;
  CurrentElement = CurrentElement->NextElementAddress;
  while (CurrentElement) {
    out << "*" << CurrentElement->Number;
    CurrentElement = CurrentElement->NextElementAddress;
  }

  return out;
}

template <class DATA>
void FindDeviders(int Devisible, Stack<DATA> &stack) {
  for (int i = 2; i <= Devisible; ++i) {
     if(Devisible % i == 0) {
      Devisible /= i;
      stack.PushElement(i);
      i--;
    }
  }
}

template <class DATA>
void FlipTheStack(Stack<DATA> &stack) {
  Stack<DATA> TemporaryStack;
  while (!(stack.EmptyCheck())) {
    TemporaryStack.PushElement(stack.FirstElementInf());
    stack.PopElement();
  }
  stack = TemporaryStack;
}

template <class INF>
void PrintTheStack(const Stack<INF> &stack, int InputNumber) {
  std::cout << InputNumber << " = " << stack << std::endl;
}

template <class INF>
void PrintTheSumStack(const Stack<INF> &stack) {
  std::cout << "Сложение стеков: " << stack <<std::endl;
}

namespace Functions{
  void StartProgramm();
}
