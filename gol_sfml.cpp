#include "gol_sfml.h"
#include<iostream>

bool gol_sfml::slucajna_vrijednost()
{
    int num = rand() % (5 - 0 + 1) + 0;
    return (num == 5) ? true : false;
}


int gol_sfml::broj_susjednih(int i, int j)
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

sf::RectangleShape gol_sfml::polje(int i, int j, bool zivo)
{
    sf::RectangleShape cell(sf::Vector2f(20.f, 20.f));
    if (zivo) {
        cell.setFillColor(sf::Color(0, 255, 0));
    }
    else {
        cell.setFillColor(sf::Color::Black);
    }
    cell.setOutlineThickness(2.f);
    cell.setOutlineColor(sf::Color(20,20,20));
    cell.setPosition(sf::Vector2f((i * 20.f), (j * 20.f)));
    return cell;
}

void gol_sfml::updatePolje(int i,int j,bool zivo)
{
    if (zivo == true) {
        _toRender[i][j].setFillColor(sf::Color(0, 255, 0));
    }
    else {
        _toRender[i][j].setFillColor(sf::Color(0, 0, 0));
    }
}

gol_sfml::gol_sfml()
{
    for (int r = 0; r < REDAKA; r++)
    {
        vector<bool> vc;
        vector<sf::RectangleShape> vrs;
        for (int s = 0;s < STUPACA; s++) {
            vc.push_back(slucajna_vrijednost());
            vrs.push_back(polje(r, s, vc[s]));
        }
        _generacija.push_back(vc);
        _toRender.push_back(vrs);
    }
}

void gol_sfml::sljedeca_generacija()
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
            updatePolje(r, s, vc[s]);
        }
        _sljedeca_generacija.push_back(vc);
    }
    _generacija.swap(_sljedeca_generacija);
}

void gol_sfml::iscrtaj()
{
    for (auto r : _toRender) {
        for (auto cell : r) {
            win->draw(cell);
        }
    }
}

void gol_sfml::setWin(sf::RenderWindow* pwin)
{
    win = pwin;
}

pair<int, int> gol_sfml::getWinSize()
{
    return {REDAKA*20, STUPACA*20};
}

