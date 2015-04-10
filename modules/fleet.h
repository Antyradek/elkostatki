#ifndef FLEET_H_
#define FLEET_H_

#include "ship.h"
#include "board.h"

#define SHIPS_NUMBER 10
#define FOUR_MAST_NUMBER 1
#define THREE_MAST_NUMBER 2
#define TWO_MAST_NUMBER 3
#define ONE_MAST_NUMBER 4


/**
 * @class Fleet
 * Reprezentuje flotę - zbiór statków gracza
 */
class Fleet
{
private:
	/// Tablica statków
	Ship* ships[SHIPS_NUMBER];
	
public:
	/**
	 * Konstruktor
	 */
	Fleet();
	
	/**
	 * Sprawdza, czy są jeszcze niezatopione statki
	 * @returns true jeśli są niezatopione statki
	 */
	bool hasShipsLeft();
	
	/**
	 * Rozstawia statki na planszy
	 */
	void rollPlacement();
	
	/**
	 * Sprawdza, czy statek może zostać ustawiony na planszy
	 */
	bool canPlaceShip(const Ship & ship, const Board & board);
	
	/// TO DO
	/// ustalić algorytm losowania pozycji
	/// dopisać niezbędne metody pomocnicze
};

#endif
