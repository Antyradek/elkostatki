#include <iostream>
#include <string>
#include <cstdlib> //Random
#include <ctime> //Ziarno Losowości
#include <cstring>
#define SIZE 10

using namespace std;
int main(int argc, char** args)
{
	if(argc < 2)
	{
		cout << "Użyj \"-g\", aby wygenerować planszę 10x10" << endl;
		return -1;
	}
	//tutaj zrób wszystko, co potrzebujesz do generacji itp
	if(strcmp(args[1], "-g") == 0)
	{
		srand(time(nullptr));
		//tymczasowo na chama wypisujemy, 0.1 pól to statki 1x1
		for(int y = 0; y < SIZE; y++)
		{
			for(int x = 0; x < SIZE; x++)
			{
				if(rand() % 10 == 0)
				{
					cout << "1";
				}
				else
				{
					cout << "*";
				}
			}
			cout << endl;
		}
	}
	return 0;
}
