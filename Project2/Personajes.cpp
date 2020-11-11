#include "Personajes.h"
#include "juego.h"
#include <ctime>

using namespace sf;


void Personajes::Dibujar(RenderWindow* wind) {//Dibujamos personajes
	wind->draw(_personajes[0]);
	wind->draw(_personajes[1]);
	wind->draw(_personajes[2]);
	wind->draw(_personajes[3]);
}

Vector2f Personajes::randomPos(Vector2u maxpos) {//Definimos posiciones para los personajes
	switch (rand()%5+1) {
		case 1: {
			Vector2f random1(maxpos.x = 135, maxpos.y = 110);
			return random1; break;
		}
		case 2: {
			Vector2f random2(maxpos.x = 110, maxpos.y = 370);
			return random2; break;
		}
		case 3: {
			Vector2f random3(maxpos.x = 580, maxpos.y = 110);
			return random3; break;
		}
		case 4: {
			Vector2f random4(maxpos.x = 350, maxpos.y = 400);
			return random4; break;
		}
		case 5: {
			Vector2f random4(maxpos.x = 600, maxpos.y = 370);
			return random4; break;
		}
		default:break;
	}
}

bool Personajes::PosicionEnemigo1(float x, float y) {//Posicionamos enemigo1
	FloatRect bounds1 = _personajes[0].getGlobalBounds();
	return bounds1.contains(x, y);
}

bool Personajes::PosicionEnemigo2(float x, float y) {//Posicionamos enemigo2
	FloatRect bounds2 = _personajes[1].getGlobalBounds();
	return bounds2.contains(x, y);
}

bool Personajes::PosicionBueno1(float x, float y) {//Posicionamos personaje bueno1
	FloatRect bounds3 = _personajes[2].getGlobalBounds();
	return bounds3.contains(x, y);
}

bool Personajes::PosicionBueno2(float x, float y) {//Posicionamos personaje bueno2
	FloatRect bounds4 = _personajes[3].getGlobalBounds();
	return bounds4.contains(x, y);
}

void Personajes::Derrotar() {//Cada vez que hacenos click en los personajes sacamos de escena
	_personajes[0].setPosition(1000, 1000);
	_personajes[1].setPosition(1000, 1000);
	_personajes[2].setPosition(1000, 1000);
	_personajes[3].setPosition(1000, 1000);
}

void Personajes::ActualizarEnemigo(RenderWindow* wind) {//Actualizamos posicion de los personajes
	if (!_estavivo) {
		return;
	}
	if (!_estavisible) {
		clockenemigo.restart();
		if (clockenemigo.getElapsedTime().asSeconds() < _tiempoapagado) {//si el tiempo es menor al tiempo apagado dibujamos persaonej en una posicion
			if (rand() % 100 < 80) {
				_estavisible = true;
				int numrandom;
				numrandom = rand() % 4;
				switch (numrandom) {
					case 0: {
						_personajes[0].setPosition(randomPos(wind->getSize()));

						break;
					}
					case 1: {
						_personajes[1].setPosition(randomPos(wind->getSize()));
						break;
					}
					case 2: {
						_personajes[2].setPosition(randomPos(wind->getSize()));
						break;
					}
					case 3: {
						_personajes[3].setPosition(randomPos(wind->getSize()));
						break;
					}
					default:break;
				}
				}
			}
		}
	else {
		if (clockenemigo.getElapsedTime().asSeconds() > _tiempoVisible) {//si el tiempo es mayor al tiempo apagado eliminamos personajes de la posicion designada
			_estavisible = false;
			_personajes[0].setPosition(1000, 1000);
			_personajes[1].setPosition(1000, 1000);
			_personajes[2].setPosition(1000, 1000);
			_personajes[3].setPosition(1000, 1000);
			clockenemigo.restart();
		}
	}
}
