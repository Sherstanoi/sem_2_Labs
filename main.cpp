#include "lab_4.hpp"

int main() {
  MyStack<char> CharStack;
  MyStack<char> CharStackSecond;
  CharStack.PushElement('a');
  CharStack.PushElement('b');
  CharStack.PushElement('c');
  CharStackSecond.PushElement('f');
  CharStackSecond.PushElement('e');
  CharStackSecond.PushElement('d');
  MyStack<char> CharStackThird(CharStack);
  MyStack<char> CharStackFourd = CharStackSecond;
  std::cout<<"CharStackA:"<<CharStackThird << "\n";
  std::cout<<"CharStackB:"<<CharStackFourd << "\n";
  std::cout<<"Sum A+B:" << CharStackSecond + CharStack << "\n";
    Functions::StartProgramm();

  return 0;
}
