all: app1 app2

app1: app1.cpp f1.cpp f1.hpp Makefile
	g++ -o app1 -g --std=c++14 -Wall -Wextra -Wold-style-cast f1.cpp app1.cpp

app2: app2.cpp f1.cpp f1.hpp Makefile
	g++ -o app2 -g --std=c++14 -Wall -Wextra -Wold-style-cast f1.cpp app2.cpp

