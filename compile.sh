#!/bin/bash

#SOURCE_FILE=$1

#if [[ -z "$SOURCE_FILE" ]]; then
#	SOURCE_FILE="main"
#fi

SOURCE_FILE=./src/main.cpp
BUILD_FILE=./build/linux/main

if [[ -f "$BUILD_FILE" ]]; then
	echo "Removing $BUILD_FILE..."
	
	rm $BUILD_FILE
fi

if [[ ! -f "$SOURCE_FILE.cpp" ]]; then
	echo "!! $SOURCE_FILE.cpp not found, exiting..."
	exit
fi

echo "Compiling $1..."

g++ -std=c++11 $SOURCE_FILE -I/root/sfml/include -L/root/sfml/lib -lsfml-graphics -lsfml-window -lsfml-system -o $BUILD_FILE > logs/linux_output.txt &2>logs/linux_error.txt
#g++ -std=c++11 -c $SOURCE_FILE -I/root/sfml/include
#g++ -std=c++11 $SOURCE_FILE.o -o build/linux/$SOURCE_FILE -L/root/sfml/lib -lsfml-graphics -lsfml-window -lsfml-system

if [[ -f "$BUILD_FILE" ]]; then
	export LD_LIBRARY_PATH=/root/sfml/lib && $BUILD_FILE
	
	rm $BUILD_FILE
fi



#if [[ -f "$SOURCE_FILE.o" ]]; then
#	rm $BUILD_FILE
#fi