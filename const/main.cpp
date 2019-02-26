// const demo

#include <iostream>
#include <string.h>

int main(void)
{
  const char source[] = "qwerty";
  std::string dest(source);
  dest[0] = 'Q';
  std::cout << __LINE__ << ": " << dest << std::endl;
  
 #if 0 
  std::cout << __LINE__ << ": " << "пробуем изменить константу" << std::endl;
  source[0] = 'Q';
  std::cout <<  __LINE__ << ": " << source << std::endl;
#endif  
  return 0;
}
