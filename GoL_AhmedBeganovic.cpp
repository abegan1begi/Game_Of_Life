#include <iostream>
#include <string>
#include <fstream>
#include<ctime>
#include "game_of_life.h"
#include "gol_vec.h";
#include <SFML/Graphics.hpp>
#include "gol_sfml.h"
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
using namespace std;

int main() {
	srand(time(nullptr));
	int odabir;
	cout << "[1] Konzola"<<endl;
	cout << "[2] Konzola (vektor)"<<endl;
	cout << "[3] Graficki"<<endl;
	cout << "[0] Exit"<<endl;
	cout << "> ";
	cin >> odabir;

	if (odabir == 1) {
		game_of_life the_game;
		bool dalje;
		do {
			system("CLS");
			the_game.iscrtaj();
			the_game.sljedeca_generacija();

			cout << "Dalje (1/0): ";
			cin >> dalje;
		} while (dalje);
	}
	else if (odabir == 2) {
		gol_vec game;
		bool dalje;
		do {
			system("CLS");
			game.iscrtaj();
			game.sljedeca_generacija();

			cout << "Dalje (1/0): ";
			cin >> dalje;
		} while (dalje);
	}
	else if (odabir == 3) {
		gol_sfml game;
		auto winsize = game.getWinSize();
		sf::RenderWindow window(sf::VideoMode(winsize.first, winsize.second), "Game of Life - Ahmed Beganovic");
		window.setFramerateLimit(60);

		game.setWin(&window);

		MessageBoxA(NULL, "Da bi ste igrali igricu potrebno je da kliknete strelicu desno na vasoj tastaturi kako biste presli na novu generaciju\n\n PRESS [>] TO PLAY", "UPUTE", MB_OK);

		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed) {
					window.close();
				} else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right) {
					game.sljedeca_generacija();
				}
			}
			window.clear();

			game.iscrtaj();

			window.display();
		}
	}
	else {
		return 21;
	}

	return 0;
}