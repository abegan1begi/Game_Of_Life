#include "gol_vec.h"

bool gol_vec::slucajna_vrijednost()
{
	int num = rand() % (5 - 0 + 1) + 0;
	return (num == 5) ? true : false;
}


int gol_vec::broj_susjednih(int i, int j)
{
    int br = 0;
    int x, y;
    for (int r = -1; r <= 1; r++)
    {
        for (int s = -1; s <= 1; s++) {
            x = (i + r + REDAKA) % REDAKA;
            y = (j + s + STUPACA) % STUPACA;
            if (!(r == 0 and y == 0)) {
                //cout << x << " " << y << " " << _generacija[x][y] << endl;
                if (_generacija[x][y] == true) {
                    br++;
                }
            }
        }
    }
    return br;
}

gol_vec::gol_vec()
{
    for (int r = 0; r < REDAKA; r++)
    {
        vector<bool> vc;
        for (int s = 0;s < STUPACA; s++) {
            vc.push_back(slucajna_vrijednost());
        }
        _generacija.push_back(vc);
    }
}

void gol_vec::sljedeca_generacija()
{
    _sljedeca_generacija.clear();
    for (int r = 0; r < REDAKA; r++)
    {
        vector<bool> vc;
        for (int s = 0;s < STUPACA; s++) {
            bool val = _generacija[r][s];
            int susjedi = broj_susjednih(r, s);
            if (val == true) {
                if (susjedi > 3 || susjedi < 2) {
                    vc.push_back(false);
                }
                else {
                    vc.push_back(true);
                }
            }
            else {
                if (susjedi == 3) {
                    vc.push_back(true);
                }
                else {
                    vc.push_back(false);
                }
            }
        }
        _sljedeca_generacija.push_back(vc);
    }
    _generacija.swap(_sljedeca_generacija);
}

void gol_vec::iscrtaj()
{
	for (auto vc : _generacija) {
		for (auto cell : vc) {
            if (cell == true) {
                cout << "O";
            }
            else {
                cout << "-";
            }
		}
		cout << endl;
	}
}
