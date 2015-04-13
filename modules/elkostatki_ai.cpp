#include <iostream>
#include <string>
#include <cstdlib> //Random
#include <ctime> //Ziarno Losowości
#include <cstring>
#include <boost/python.hpp>
#define SIZE 10

using namespace std;
using namespace boost::python;

string generate_field()
{
	string out = "";
	srand(time(nullptr));
	//tymczasowo na chama wypisujemy, 0.1 pól to statki 1x1
	for(int y = 0; y < SIZE; y++)
	{
		for(int x = 0; x < SIZE; x++)
		{
			if(rand() % 10 == 0)
			{
				out += "s";
			}
			else
			{
				out += "w";
			}
		}
	}
	return out;
}

BOOST_PYTHON_MODULE(elkostatki_ai)
{
    boost::python::def("generate_field", generate_field);
}
