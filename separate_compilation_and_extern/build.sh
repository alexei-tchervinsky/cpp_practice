#!/bin/bash
echo Пример трансляции с раздельной компиляцией и extern для глобальной переменной

echo Компилируем \(ключ -c\) исходные файлы в объектные \(*.o\)
g++ -std=c++14 -Wall -Wextra -Wold-style-cast -c h1.cpp
g++ -std=c++14 -Wall -Wextra -Wold-style-cast -c main.cpp

echo Смотрим таблицу имен объектных файлов \(обратите внимание на func \(mangled\) и global_i\)
objdump -t main.o
objdump -t h1.o

echo Линкуем объектные файлы в исполняемый файл
g++ -o main main.o h1.o

echo Запускаем исполняемый файл
./main 

echo Компилируем и линкуем одной командой, как делаем обычно
g++ -o main1 -std=c++14 -Wall -Wextra -Wold-style-cast h1.cpp main.cpp

echo Запускаем исполняемый файл
./main1 


