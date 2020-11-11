#ifndef MIRA_H
#define MIRA_H
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include <iostream>

using namespace sf;
using namespace std;

class Mira {//Definimos la mira

	Texture mira;
	Sprite _Mira;

public:
	Mira() {//Cargamos la mira
		mira.loadFromFile("Mira.png");
		_Mira.setTexture(mira);
		_Mira.setScale(0.1f, 0.1f);
		Vector2u size = mira.getSize();
		_Mira.setOrigin(size.x / 2.0f, size.y / 2.0f);
	}

	void Dibujar(RenderWindow* wind);

	Vector2f Obtenerposicion() { return _Mira.getPosition(); }

	void PosicionMira(float x, float y);
};

#endif