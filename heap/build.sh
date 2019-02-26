#!/bin/bash

echo Компилируем
g++ -g -o main -Wall -Wextra -Wold-style-cast main.cpp

echo Запускаем
./main

