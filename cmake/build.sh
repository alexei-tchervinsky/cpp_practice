#!/bin/bash

echo configure make file
cd build
cmake ..

echo build wih Makefile
make all

echo run application with 'build/helloworld'
