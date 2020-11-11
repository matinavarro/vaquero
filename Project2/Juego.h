#ifndef JUEGO_H
#define JUEGO_H
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include <iostream>
#include "mira.h"
#include "Personajes.h"

using namespace sf;
using namespace std;

class Juego {//Definimos elementos en el escenario
	RenderWindow* wind;
	Texture saloon;
	Sprite _salon;
	Texture puntaje[2];
	Sprite _puntaje[2];
	Texture info[4];
	Sprite _info[4];
	Mira* mira;
	Personajes* _personajes;
	Text _puntos;
	Text _puntosamigos;
	Text textvida;
	Font fuente;
	Clock tiempo;
	Time _tiempo;
	float Fintiempo= 0.5f;
	int puntajes = 0;
	int puntajeBuenos = 0;
	int vidas = 3;
	void Mostrarpuntaje();

public:
	Juego() {//Cargamos distintos elementos
		wind = new RenderWindow(VideoMode(800, 800), "Vaqueros");
		mira = new Mira;
		_personajes = new Personajes;

		saloon.loadFromFile("salon.png");
		_salon.setTexture(saloon);
		_salon.setScale(0.32f, 0.32f);
		puntaje[0].loadFromFile("puntajeEnemigos.png");
		_puntaje[0].setTexture(puntaje[0]);
		_puntaje[0].setScale(0.12f, 0.12f);
		_puntaje[0].setPosition(20,650);
		puntaje[1].loadFromFile("puntajeAmigos.png");
		_puntaje[1].setTexture(puntaje[1]);
		_puntaje[1].setScale(0.12f, 0.12f);
		_puntaje[1].setPosition(400, 650);
		info[0].loadFromFile("nombre.png");
		_info[0].setTexture(info[0]);
		_info[0].setPosition(20, 700);
		info[1].loadFromFile("gameover.png");
		_info[1].setTexture(info[1]);
		_info[1].setPosition(135, 70);
		_info[1].setScale(1.5f,1.5f);
		info[2].loadFromFile("ganador.png");
		_info[2].setTexture(info[2]);
		_info[2].setPosition(20, 80);
		_info[2].setScale(0.4f, 0.4f);
		info[3].loadFromFile("vida.png");
		_info[3].setTexture(info[3]);
		_info[3].setPosition(20, 10);
		_info[3].setScale(0.1f, 0.1f);
		_puntos.setPosition(340 , 646);
		_puntos.setCharacterSize(30);
		_puntos.setFont(fuente);
		textvida.setPosition(105, 10);
		textvida.setCharacterSize(25);
		textvida.setFont(fuente);
		_puntosamigos.setPosition(685, 646);
		_puntosamigos.setCharacterSize(30);
		_puntosamigos.setFont(fuente);
		fuente.loadFromFile("cp.ttf");
		Mostrarpuntaje();
	}
	int FinJuego();
	void Loop();
	void ProcesarEventos();
	void Actualizar();
	void Disparar();
	void Dibujar();

	~Juego() {//Destructores correspondientes
		delete _personajes;
		delete mira;
		delete wind;
	}
};

#endif 