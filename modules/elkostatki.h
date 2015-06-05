/** \file elkostatki.h
 * plik nagłówkowy
 */

#include <iostream>
#include <string>
#include <cstdlib> //Random
#include <ctime> //Ziarno Losowości
#include <cstring>
#include <boost/python.hpp>
#define SIZE 10

bool isPermitted(bool* board, int x, int y);
void setBoard(bool* board, int x, int y, bool val);
void putShip(bool* board, bool* shipBoard, int size);
