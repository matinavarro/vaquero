#ifndef PERSONAJES_H
#define PERSONAJES_H
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include <iostream>

using namespace sf;
using namespace std;

class Personajes {//Definimos personajes en un arreglo
    Texture personajes[4];
    Sprite _personajes[4];
    bool _estavivo;
    bool _estavisible;
    Vector2f randomPos(Vector2u maxpos);
    Clock clockenemigo;
    float _tiempoVisible = 1.0f;
    float _tiempoapagado = 1.0f;
 
public:
    Personajes() {//Cargamos distintos personajes
        personajes[0].loadFromFile("enemigo1.png");
        _personajes[0].setTexture(personajes[0]);
        _personajes[0].setScale(1.2f, 1.2f);
        personajes[1].loadFromFile("enemigo2.png");
        _personajes[1].setTexture(personajes[1]);
        _personajes[1].setScale(1.2f, 1.2f);
        personajes[2].loadFromFile("bueno1.png");
        _personajes[2].setTexture(personajes[2]);
        _personajes[2].setScale(1.2f, 1.2f);
        personajes[3].loadFromFile("bueno2.png");
        _personajes[3].setTexture(personajes[3]);
        _personajes[3].setScale(1.2f, 1.2f);
 
        _estavivo = true;
        _estavisible = false;
    }
    void Dibujar(RenderWindow* wind);

    bool PosicionEnemigo1(float x, float y);
    bool PosicionEnemigo2(float x, float y);
    bool PosicionBueno1(float x, float y);
    bool PosicionBueno2(float x, float y);

    bool personajeVivo() { return _estavivo; }
    bool personajeVisible() { return _estavivo && _estavisible; }
    void Derrotar();
    void ActualizarEnemigo(RenderWindow* wind);
};

#endif