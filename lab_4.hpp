#include <iostream>

#ifndef lab_4_hpp
#define lab_4_hpp

template <class INF>
class MyStack;

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
  friend std::ostream &operator<<(std::ostream &out, const MyStack<T> &Element);
};

template <class INF>
class MyStack {
  private:
    typedef class ListNode<INF, MyStack<INF>> Node;
    Node *FirstElement;

  public:
    MyStack(void);
    ~MyStack(void);

    bool EmptyCheck();
    void PushElement(INF n);
    void PopElement();
    INF FirstElement_inf();

    MyStack(const MyStack &other);
    MyStack<INF> &operator=(const MyStack<INF> &other);
    MyStack<INF> &operator+( MyStack<INF> &other);

    friend std::ostream &operator<< <>(std::ostream &out, const MyStack &Element);
};

template <class INF>
bool MyStack<INF>::EmptyCheck() {
  if (FirstElement) {
    return false;
  }
  return true;
}

template <class INF>
void MyStack<INF>::PushElement(INF InputNumber) {
  Node *NewStackElement = new Node;
  NewStackElement->Number = InputNumber;
  NewStackElement->NextElementAddress = FirstElement;
  FirstElement = NewStackElement;
  return;
}

template <class INF>
void MyStack<INF>::PopElement() {
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
INF MyStack<INF>::FirstElement_inf() {
  if (EmptyCheck()) {
    std::cout<<"В стеке нет элементов" << '\n';
    return 0;
  }
  return FirstElement->Number;
}

template <class INF> MyStack<INF>::MyStack() {
  FirstElement = nullptr;
}

template <class INF> MyStack<INF>::~MyStack() {
  while (!EmptyCheck()) {
    PopElement();
  }
}

template <class INF>
MyStack<INF> &MyStack<INF>::operator=(const MyStack &other) {
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
MyStack<INF>& MyStack<INF>::operator+(MyStack &other) {
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
MyStack<INF>::MyStack(const MyStack &other) {
  *this = other;
}

template <class INF>
std::ostream &operator<<(std::ostream &out, const MyStack<INF> &Element) {
  typename MyStack<INF>::Node *CurrentElement = Element.FirstElement;
  out << CurrentElement->Number;
  CurrentElement = CurrentElement->NextElementAddress;
  while (CurrentElement) {
    out << "*" << CurrentElement->Number;
    CurrentElement = CurrentElement->NextElementAddress;
  }

  return out;
}

template <class DATA>
void FindDeviders(int Devisible, MyStack<DATA> &stack) {
  for (int i = 2; i <= Devisible; ++i) {
     if(Devisible % i == 0) {
      Devisible /= i;
      stack.PushElement(i);
      i--;
    }
  }
}

template <class DATA>
void FlipTheStack(MyStack<DATA> &stack) {
  MyStack<DATA> TemporaryStack;
  while (!(stack.EmptyCheck())) {
    TemporaryStack.PushElement(stack.FirstElement_inf());
    stack.PopElement();
  }
  stack = TemporaryStack;
}

template <class INF>
void PrintTheStack(const MyStack<INF> &stack, int InputNumber) {
  std::cout << InputNumber << " = " << stack << std::endl;
}

template <class INF>
void PrintTheSumStack(const MyStack<INF> &stack) {
  std::cout << "Сложение стеков: " << stack <<std::endl;
}

#endif

namespace Functions{
  void StartProgramm();
}
