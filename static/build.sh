#!/bin/bash

echo Компилируем
g++ -g -o main -Wall -Wextra -Wold-style-cast main.cpp

echo Запускаем
./main

echo Статические переменные удобны для отладки, в разработке следует избегать их использования. 
