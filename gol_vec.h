#pragma once
#include<vector>
#include<iostream>

using namespace std;

class gol_vec
{
	static const unsigned int STUPACA = 40;
	static const unsigned int REDAKA = 20;
	vector<vector<bool>> _generacija;
	vector<vector<bool>> _sljedeca_generacija;
	bool slucajna_vrijednost();
	int broj_susjednih(int i, int j);

public:
	gol_vec();
	void sljedeca_generacija();
	void iscrtaj();
};

