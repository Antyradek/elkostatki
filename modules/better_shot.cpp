#include "elkostatki.h"
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

bool pole_cmp(pair<char,int> a, pair<char,int> b)
{
    return a.second<b.second;
}

class spodziewany_statek
{
public:
    vector<pair<char,int> > pola;
    char orientacja;//u, v, h
    spodziewany_statek(char stan, int pozycja)
    {
        orientacja='u';//nieznana orientacja
        pair tmp=make_pair(stan, pozycja);
        pola.push_back(tmp);
    }
    void add_pole(char stan, int pozycja)
    {
        pair tmp=make_pair(stan, pozycja);
        pola.push_back(tmp);
        sort(pola.begin(),pola.end(),pole_cmp());//czasem pola statku moga wpasc nie pokoleji
    }
    bool zawiera_pole(int p)
    {
        for(int i=0;i<pola.size();i++)
        {
            if(pola.at(i).second==p && pola.at(i).first=='t')
            {
                return true;
            }
        }
        return false;
    }
}

int better_shot(string fields)
{
    /*
    znalezc zatopione i nie zatopione statki
    sprawdzic dlugosci
    ustalic gdzie jest szansa, ze trafimy nastepny segment juz trafionego statku
    jesli takiego nie ma to zrobic zaawansowana mape gdzie nie ma sensu strzelac
    losowo strzelic tam gdzie jest sens
    */
    vector<spodziewany_statek> statki;
    for(int i=0;i<SIZE*SIZE;i++)
    {
        if(fields.at(i)=='t')//znalezlismy trafiony
        {
            statki.push_back(spodziewany_statek('t',i));
            if(i-1>=0 && i%SIZE!=0)//lewo
            {
                if(fields.at(i-1)=='p')
            }
            else
            {
                statki.at(statki.size()-1).add_pole('x',i-1);//brzeg planszy z lewej
            }
            if(i+1<SIZE*SIZE && i%SIZE!=(SIZE-1))//prawo
            {
                if(fields.at(i+1)=='t')
            }
            else
            {
                statki.at(statki.size()+1).add_pole('x',i+1);//brzeg planszy z prawej
            }

        }
    }
    return -1;
}
