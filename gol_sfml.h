#pragma once
#include<vector>
#include<iostream>
#include<SFML/Graphics.hpp>

using namespace std;

class gol_sfml
{
	static const unsigned int STUPACA = 40;
	static const unsigned int REDAKA = 60;
	vector<vector<bool>> _generacija;
	vector<vector<bool>> _sljedeca_generacija;
	vector<vector<sf::RectangleShape>> _toRender;
	bool slucajna_vrijednost();
	int broj_susjednih(int i, int j);
	sf::RenderWindow* win;
	sf::RectangleShape polje(int i, int j, bool zivo);
	void updatePolje(int i, int j, bool zivo);
	

public:
	gol_sfml();
	void sljedeca_generacija();
	void iscrtaj();
	void setWin(sf::RenderWindow* win);
	pair<int,int> getWinSize();
};

