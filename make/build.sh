#!/bin/bash
echo emulate change f1.cpp
touch f1.cpp

eecho run make
make all

echo run ./app1 and ./app2
