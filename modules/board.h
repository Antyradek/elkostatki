#ifndef BOARD_H_
#define BOARD_H_

#include "coord.h"

#define BOARD_SIZE 10

/**
 * @enum pola planszy
 * @var SQ_FREE niezajęte pole, na którym można postawić statek
 * @var SQ_SHIP pole zajęte przez statek
 * @var SQ_HIT pole zajęte przez trafiony segment statku
 * @var SQ_WRECK pole zjęte przez zatopiony statek
 * @var SQ_PROHIBITED pole sasiadujące ze statkiem
 * @var SQ_UNKNOWN pole, ktorego typu gracz nie zna (tylko plansza przeciwnika)
 */
enum SquareType
{
	SQ_FREE = 'F',
	SQ_SHIP = 'S',
	SQ_HIT = 'H',
	SQ_WRECK = 'W',
	SQ_PROHIBITED = 'P',
	SQ_UNKNOWN = 'U'
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