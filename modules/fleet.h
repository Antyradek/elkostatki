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
 * @enum efekt strzału
 * @var MISS pudło
 * @var HIT trafienie (bez zatopienia)
 * @var SUNK trafienie (statek zatopiony)
 */
enum ShotStatus
{
	SHOT_MISS = 'M',
	SHOT_HIT = 'H',
	SHOT_SUNK = 'S'
};

/**
 * @class Fleet
 * Reprezentuje flotę - zbiór statków gracza
 */
class Fleet
{
private:
	/// Tablica statków
	Ship ships[];
	
	/// Plansza gracza
	Board myBoard;
	
	/// Plansza wroga
	Board enemyBoard;
	
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
	 * Rozstawia statki na planszy w sposób losowy
	 */
	void rollPlacement();
	
	/**
	 * Próbuje ustawić statek na planszy
	 * @returns true jeśli się udało, false, jeśli to niemożliwe
	 */
	bool placeShip(const Ship & ship, const Board & board);
	
	/**
	 * Strzela w dane pole
	 * @returns efekt strzału
	 */
	ShotStatus shoot(Coord position);
	
	/// TO DO
	/// ustalić algorytm losowania pozycji
	/// dopisać niezbędne metody pomocnicze
};

#endif
