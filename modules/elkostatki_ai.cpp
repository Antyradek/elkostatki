#include "elkostatki.h"

using namespace std;
using namespace boost::python;

unsigned int seed=0;/*globalny modyfikator ziarna rozkladu.
dzieki temu nie bedzie identycznych rozkladow pod rzad*/
enum difficulties {LOW=1, MEDIUM=2, HIGH=3};
enum difficulties difficulty=MEDIUM;

///Algorytm zsuwania, losujemy pole i kierunek i próbujemy wsadzić na to miejsce statek.
///Jeśli się nie uda, wybieramy następne pole po prawej i znowu próbujemy.
string generate_field()
{
	bool permittedField[SIZE * SIZE]; //czy dozwolone do postawienia statku
	bool shipBoard[SIZE * SIZE]; //czy są statki
	for(int i = 0; i < SIZE*SIZE; i++)
	{
		permittedField[i] = true;
		shipBoard[i] = false;
	}
	string out = "";
	srand(time(nullptr)+(++seed));
	putShip(permittedField, shipBoard, 4);
	putShip(permittedField, shipBoard, 3);
	putShip(permittedField, shipBoard, 3);
	putShip(permittedField, shipBoard, 2);
	putShip(permittedField, shipBoard, 2);
	putShip(permittedField, shipBoard, 2);
	putShip(permittedField, shipBoard, 1);
	putShip(permittedField, shipBoard, 1);
	putShip(permittedField, shipBoard, 1);
	putShip(permittedField, shipBoard, 1);
	for(int i=0; i<SIZE*SIZE; i++)
	{
		if(shipBoard[i])
		{
			out += 's';
		}
		else
		{
			out += 'w';
		}
	}
	return out;
}

///Czy dozwolone jest postawienie statku na tym polu
bool isPermitted(bool* board, int x, int y)
{
	if(x < 0 || x >= SIZE || y < 0 || y >= SIZE)
	{
		//poza planszą nie możemy stawiać
		return false;
	}
	return board[SIZE * y + x];
}

///Ustaw planszę na wartość (lub nie, jeśli poza planszą)
void setBoard(bool* board, int x, int y, bool val)
{
	if(x >= 0 && x < SIZE && y >= 0 && y < SIZE)
	{
		board[SIZE * y + x] = val;
	}
}

///Wsadź statek o określonej wielkości losowo na planszę
void putShip(bool* board, bool* shipBoard, int size)
{
	//pozycja na którą najpierw spróbujemy wrzucić
	int targetPosX = rand() % SIZE;
	int targetPosY = rand() % SIZE;
	//pozycja po zsunięciu
	int currPosX = targetPosX;
	int currPosY = targetPosY;
	//kierunek statku
	int dirX = 0;
	int dirY = 0;
	if(rand() % 2 == 0)
	{
		//poziomo
		dirX = 1;
	}
	else
	{
		//pionowo
		dirY = 1;
	}
	//algorytm zawsze znajdzie rozwiązanie, nie da się zrobić tak, aby nie można było postawić żadnego statku
	while(true)
	{
		//czy udało się znaleźć miejsce
		bool success = true;
		for(int i=0; i<size; i++)
		{
			if(!isPermitted(board, currPosX + i * dirX,currPosY + i * dirY))
			{
				success = false;
				break;
			}
		}
		if(!success)
		{
			//nie udało się postawić, zjazd o jedno pole w prawo
			currPosX += 1;
			//przeskok na końcu wiersza
			if(currPosX >= SIZE)
			{
				currPosX = 0;
				currPosY += 1;
			}
			//przeskok na początek planszy
			if(currPosY >= SIZE)
			{
				currPosX = 0;
				currPosY = 0;
			}
		}
		else
		{
			//udało się postawić
			for(int i=0; i<size; i++)
			{
				//ustaw statek na planszy
				setBoard(shipBoard, currPosX + i * dirX, currPosY + i * dirY, true);
				//ustaw pola zabronione na i wokół statku
				setBoard(board, currPosX + i * dirX, currPosY + i * dirY, false);
				setBoard(board, currPosX + i * dirX + 1, currPosY + i * dirY, false);
				setBoard(board, currPosX + i * dirX - 1, currPosY + i * dirY, false);
				setBoard(board, currPosX + i * dirX, currPosY + i * dirY + 1, false);
				setBoard(board, currPosX + i * dirX, currPosY + i * dirY - 1, false);
			}
			return;
		}
	}
}



int shoot(string fields)
{
    clog<<fields<<endl;
	//puki co strzela w losowe miejsce
	unsigned int tmp=0;
	srand(time(nullptr)+(++seed));
	/*rozwiazanie to jest metoda Monte Carlo. dzieki niej zachowujemy rozklad rownomierny*/
	do
	{
        if(difficulty==LOW)
        {
            tmp=rand() % (SIZE * SIZE);
        }
        else if(difficulty==MEDIUM)
        {
            tmp=rand() % (SIZE * SIZE);
            for(int i=0;i<SIZE*SIZE;i++)//pola poziome
            {
                if(fields.at(i)=='t')
                {
                clog<<"t";
                    if(i-1>=0 && i%SIZE!=0)//lewo
                    {
                        if(fields.at(i-1)!='t' && fields.at(i-1)!='p')
                        {
                            clog<<"l";
                            tmp=i-1;
                            break;
                        }
                    }
                    if(i+1<SIZE*SIZE && i%SIZE!=(SIZE-1))//prawo
                    {
                        if(fields.at(i+1)!='t' && fields.at(i+1)!='p')
                        {
                            clog<<"p";
                            tmp=i+1;
                            break;
                        }
                    }
                    if(i-SIZE>=0)//gora
                    {
                        if(fields.at(i-SIZE)!='t' && fields.at(i-SIZE)!='p')
                        {
                            clog<<"g";
                            tmp=i-SIZE;
                            break;
                        }
                    }
                    if(i+SIZE<SIZE*SIZE)//dol
                    {
                        if(fields.at(i+SIZE)!='t' && fields.at(i+SIZE)!='p')
                        {
                            clog<<"d";
                            tmp=i+SIZE;
                            break;
                        }
                    }
                }
            }
        }
        clog<<tmp<<endl;
    }
    while(fields.at(tmp)=='t' || fields.at(tmp)=='p');/*powszechnie przyjetym jest, ze nie strzela sie
                                                        dwa razy w to samo pole*/
	return tmp;
}

BOOST_PYTHON_MODULE(elkostatki_ai)
{
    boost::python::def("generate_field", generate_field);
    boost::python::def("shoot", shoot);
}
