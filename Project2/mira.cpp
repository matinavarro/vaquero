#include "mira.h"
#include "juego.h"
#include <ctime>

using namespace sf;

void Mira::Dibujar(RenderWindow* wind) {//Dibujamos mira
	wind->draw(_Mira);
}

void Mira::PosicionMira(float x, float y) {//Seteo de mira
	_Mira.setPosition(x, y);

}