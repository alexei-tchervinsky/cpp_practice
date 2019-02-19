#!/bin/bash
echo run make
make

echo run ./app1 and ./app2

echo emulate change f1.cpp
touch f1.cpp

echo run make again
make

echo run ./app1 and ./app2
