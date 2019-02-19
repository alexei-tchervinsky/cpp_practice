#!/bin/bash
echo compile with gcc
g++ -g -o helloworld --std=c++14 -Wall -Wextra -Wold-style-cast helloworld.cpp
echo compilation complete
echo run application with './helloworld'

