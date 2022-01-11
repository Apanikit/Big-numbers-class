#include "./Big_numb/Big_numb.h"
#include <iostream>

int main(){
  Big_numb a;
  Big_numb b;
  std::cin >> a;
  std::cin >> b;

  std::cout << std::endl;

  std::cout << a + b << std::endl;
  std::cout << a - b << std::endl;
  std::cout << a * b << std::endl;
  std::cout << a / b << std::endl;

  return 0;
}