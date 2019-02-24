#!/bin/bash
echo Ddemo for GNU autotools \(most Linux subsystem are built with this tools\)
echo You should install autotools 
autoreconf -iv
./configure 
make
./justdoit
