#!/bin/bash

g++ -g -Wall -I../ -o thread-test thread-test.cpp ../Thread.cpp -lpthread
g++ -g -Wall -I../ -std=c++11 -o stopwatch-test stopwatch-test.cpp

