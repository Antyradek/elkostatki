#ifndef SHIP_H_
#define SHIP_H_

#include "coord.h"

/**
 * @class Ship
 * Reprezentuje statek
 * Położenie statku jest określone przez kierunek ustawienia, długość i wpółrzedne segmentu najbliżej punktu (0,0)
 */
class Ship
{
private:
	/// Flaga "nie zatopiony"; true - pływa, flase - na dnie
	bool afloat;
	
	/// Flaga ustawienia statku; true - pionowo, false - poziomo
	bool vertical;
	
	/// Rozmiar statku
	const unsigned short size;
	
	/// Tablica flag dla segmentów statku; true - segment nienaruszony, false - segment trafony
	bool segments[];
	
	/// Pozycja segmentu początkowego (najbliższego punktowi (0,0))
	Coord position;
	
public:
	/**
	 * Główny konstruktor - żadne inne nie są potrzebne w tym projekcie
	 */
	 Ship(const unsigned short size);
	 
	/**
	 * Setter flagi vertical
	 * @param vertical true jeśli statek jest ustawiony pionowo
	 */
	void setVertical(bool vertical);
	
	/**
	 * Setter pozycji pierwszego segmentu
	 * @param position wspołrzedne pierwszego segmentu
	 */
	void setPosition(Coord position);
	 
	/**
	 * Sprawdza, czy statek zostal trafiony i obsługuje ewentualne trafienie
	 * @param position współrzedne sprawdzanego pola
	 * @returns true jeśli trafiny, false jeśli nie
	 */
	bool isHit(const Coord position);
	
	/**
	 * Sprawdza, czy statek nie został zniszczony
	 * @returns true jeśli statek nie został zniszczony
	 */	
	bool isAfloat();
};

#endif