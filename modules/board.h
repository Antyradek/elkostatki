#ifndef BOARD_H_
#define BOARD_H_

#include "coord.h"

#define BOARD_SIZE 10

/**
 * @enum pola planszy
 * @var FREE pole, na którym można ustawić statek
 * @var SHIP pole zajęte przez statek
 * @var HIT pole zajęte przez trafiony segment statku
 * @var WRECK pole zjęte przez zatopiony statek
 * @var FORBIDDEN pole sasiadujące ze statkiem
 */
enum SquareType
{
	FREE,
	SHIP,
	HIT,
	WRECK,
	FORBIDDEN
};

/**
 * @class Board
 * Reprezentuje planszę w sposób naturalny dla człowieka (macierz pól)
 */
class Board
{
private:
	/// Plansza jako macierz pól
	SquareType board[BOARD_SIZE][BOARD_SIZE];

public:
	/**
	 * Konstruktor
	 */
	Board();
	
	/**
	 * Setter typu pola
	 * @param position współrzedne pola
	 * @param type typ pola
	 */
	void setSquare(Coord position, SquareType type);
	
	/**
	 * Getter typu pola
	 * @param position współrzedne pola
	 * @returns typ pola
	 */
	SquareType getSquare(Coord position);
};

#endif