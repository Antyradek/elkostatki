#ifndef GAME_H_
#define GAME_H_

#include "player.h"
#include "skynet.h"

class Game
{
private:
	Player player;
	
	SkyNet skynet;

public:
	/**
	 * Konstruktor
	 */
	Game();

	/**
	 * Strzela w pole o współrzednych (x,y)
	 * @returns ShotStatus (patrz: fleet.h) rzutowany do char
	 */
	char shoot(unsigned short x, unsigned short y);
	
	/**
	 * Pyta o typ pola z planszy gracza o współrzednych (x,y)
	 * @returns SquareType (patrz: board.h) rzutowany do char
	 */
	char getPlayerSquare(unsigned short x, unsigned short y);
	
	/**
	 * Pyta o typ pola z planszy AI o współrzednych (x,y)
	 * UWAGA: pytanie jest o plansze widzianą przez gracza, nieodkryte pola są widziane jako woda
	 * @returns SquareType (patrz: board.h) rzutowany do char
	 */
	char getSkynetSquare(unsigned short x, unsigned short y);
};

#endif