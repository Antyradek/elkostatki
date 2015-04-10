#ifndef COORD_H_
#define COORD_H_

/**
 * @class Coord
 * reprezentuje parę współrzednych (x,y)
 */
class Coord
{
public:
	/// współrzędna x
	unsigned short x;
	/// współrzędna y
	unsigned short y;

public:
	/**
	 * podstawowy konstruktor
	 */
	Coord(const unsigned short x = 0, const unsigned short y = 0);
	
	/**
	 * konstruktor kopiujący
	 */
	Coord(const Coord & source);
	
	/**
	 * operator przypisania, dla świętego spokoju
	 */
	Coord & operator=(const Coord & source);
	
	/**
	 * operator porównania ==, dla świętego spokoju
	 * @returns true jeśli równe
	 */
	bool operator==(const Coord & comp);
	
	/**
	 * operator porównania !=, dla świętego spokoju
	 * @returns true jeśli nierówne
	 */
	bool operator!=(const Coord & comp);
};

#endif