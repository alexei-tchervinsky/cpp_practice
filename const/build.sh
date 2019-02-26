#!/bin/bash

echo Компилируем
g++ -o main -std=c++14 -Wall -Wextra -Wold-style-cast main.cpp

echo Запускаем
./main

echo Компилируем для получения промежуточного файла на языке ассемблера
g++ -S -o main.asm main.cpp

echo Откройте файл main.asm любым редактором и найдите строку 'qwerty'. Обратите внимание, в каком типе памяти она находится - const

