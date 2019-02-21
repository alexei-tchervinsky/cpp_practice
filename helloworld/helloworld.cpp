// helloworld
//
#include <iostream>

int main(int argc, char *argv[])
{
    std::cout << argc << std::endl;
    std::cout << argv[0] << std::endl;
    
    if (argc == 2) {
        std::cout << argv[1] << std::endl;
    } else {
        std::cout << "Invalid number of arguments" << std::endl;
        return 10;
    }
    /*
     argv[0]  char*
     argv[1]  char*
     */
    
    
	std::cout << "Hello, world! :-)" << std::endl;
	return 0;
}

