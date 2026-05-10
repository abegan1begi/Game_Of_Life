#include "game_of_life.h"

bool game_of_life::slucajna_vrijednost()
{
    int num = rand() % (5 - 0 + 1) + 0;
    return (num == 5) ? true : false;
}

bool game_of_life::celija_zauzeta(int i, int j)
{
    return _generacija[i][j];
}

int game_of_life::broj_susjednih(int i, int j)
{
    int br=0;
    int x, y;
    for (int r = -1; r <= 1; r++)
    {
        for (int s = -1; s <= 1; s++) {
            x = (i + r + REDAKA) % REDAKA;
            y = (j + s + STUPACA) % STUPACA;
            if (!(r==0 and y==0)) {
                //cout << x << " " << y << " " << _generacija[x][y] << endl;
                if (_generacija[x][y] == true) {
                    br++;
                }
            }
        }
    }
    return br;
}

game_of_life::game_of_life()
{
    for (int r = 0; r < REDAKA; r++)
    {
        for (int s = 0;s < STUPACA; s++) {
            _generacija[r][s] = slucajna_vrijednost();
        }
    }
}

void game_of_life::sljedeca_generacija()
{
    for (int r = 0; r < REDAKA; r++)
    {
        for (int s = 0;s < STUPACA; s++) {
            bool val = _generacija[r][s];
            int sused = broj_susjednih(r, s);
            if (val == true) {
                if (sused > 3 || sused < 2) {
                    _sljedeca_generacija[r][s] = false;
                }
                else {
                    _sljedeca_generacija[r][s] = true;
                }
            }
            else {
                if (sused == 3) {
                    _sljedeca_generacija[r][s] = true;
                }
                else {
                    _sljedeca_generacija[r][s] = false;
                }
            }
        }
    }
    for (int r = 0; r < REDAKA; r++)
    {
        for (int s = 0;s < STUPACA; s++) {
            _generacija[r][s] = _sljedeca_generacija[r][s];
        }
    }
}

void game_of_life::iscrtaj()
{
    for (int r = 0; r < REDAKA; r++)
    {
        for (int s = 0;s < STUPACA; s++) {
            bool val = _generacija[r][s];
            if (val == true) {
                cout << "O";
            }
            else {
                cout << "-";
            }
        }
        cout << endl;
    }

}
