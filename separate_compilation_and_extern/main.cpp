// extern to global variable

#include <iostream>
#include "h1.hpp"

int main(void)
{
  global_i = 1; 

  func();
  
  std::cout << global_i << std::endl;

  return 0;
}
