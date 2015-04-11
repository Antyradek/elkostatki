#ifndef SKYNET_H_
#define SKYNET_H_

#include "player.h"
#include <list>

/**
 * @class SkyNet
 * @brief AI gry
 */
class SkyNet : Player
{
private:
	/// pozycja ostatniego strzału; dla przyspieszenia algorytmu
	Coord lastShotPosition;
	
	/// lista pól z planszy gracza, których typu AI nie zna (cel ostrzału)
	std::list<Coord> unknownSquares;	// taka lista pozwala uniknąć wielokrotnego losowania i sprawdzania typu wybranego pola
	
public:
	/**
	 * Konstruktor
	 */
	SkyNet();

	/**
	 * Wybiera pole z planszy gracza, w które zostanie oddany strzał
	 * @returns wybrane pole
	 */
	Coord shoot();

	
};

#endif