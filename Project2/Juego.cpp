#include "juego.h"
#include <ctime>

using namespace sf;
using namespace std;

void Juego::Loop() {
	while (wind->isOpen()) {//Controlamos distintos eventos
		ProcesarEventos();
		Actualizar();
		Dibujar();
		if (FinJuego() != 0) {//Verificamos si se gano o perdió
			if (FinJuego() == 1) {
				_tiempo = tiempo.getElapsedTime();
				if (_tiempo.asSeconds() > 10) {//Luego del tiempo estimado cierra el juego
					wind->close();
				}
			}
			if (FinJuego() == 2) {
				_tiempo = tiempo.getElapsedTime();//Luego del tiempo estimado cierra el juego
				if (_tiempo.asSeconds() > 20){
					wind->close();
				}
			}
		}
		
	}
}
void Juego::ProcesarEventos() {
	Event evt;
	while (wind->pollEvent(evt)) {//capturo evento
		switch (evt.type) {//Proceso los eventos
		case Event::Closed://Controlo si se cerró la ventana
			wind->close();//cierro aplicacion
			break;
		case Event::MouseMoved://Controlo mouse
			mira->PosicionMira(evt.mouseMove.x, evt.mouseMove.y);
			break;
		case Event::MouseButtonPressed://Controlo click derecho del mouse
			if (evt.mouseButton.button == Mouse::Button::Left)
				Disparar();
			break;
		}
	}
}
void Juego::Actualizar() { //Actualiza la posicion de los personajes
	Vector2i mousePos = Mouse::getPosition(*wind);
	_personajes->ActualizarEnemigo(wind);
}

void Juego::Disparar() {//Obtiene la posicion de los personajes, al clickear encima de cada uno
	Vector2f miraPos = mira->Obtenerposicion();
	if (_personajes->PosicionEnemigo1(miraPos.x, miraPos.y)) {
		puntajes++;//suma puntaje enemigos
		_personajes->Derrotar();//Eliminamos personaje de la posicion
	}
	if (_personajes->PosicionEnemigo2(miraPos.x, miraPos.y)) {
		puntajes++;//suma puntaje enemigos
		_personajes->Derrotar();//Eliminamos personaje de la posicion
	}
	if (_personajes->PosicionBueno1(miraPos.x, miraPos.y)) {
		puntajeBuenos++;//suma puntaje buenos
		vidas--;
		_personajes->Derrotar();//Eliminamos personaje de la posicion
	}
	if (_personajes->PosicionBueno2(miraPos.x, miraPos.y)) {
		puntajeBuenos++;//suma puntaje buenos
		vidas--;
		_personajes->Derrotar();//Eliminamos personaje de la posicion
	}
	Mostrarpuntaje();
}
void Juego::Mostrarpuntaje() {//convierte el puntaje es un string
	string puntos;
	string puntosamigos;
	string _vidas;
	_vidas = to_string(vidas);
	textvida.setString(_vidas);
	puntos = to_string(puntajes);
	puntosamigos = to_string(puntajeBuenos);
	_puntos.setString(puntos);
	_puntosamigos.setString(puntosamigos);
}

int Juego::FinJuego() {
	if (puntajeBuenos == 3) {//Si le disparo a 3 buenos pierde
		wind->draw(_info[1]);
		return 1;
	}
	if (puntajes == 10) {//controlo 10 aciertos en los disparos
		wind->draw(_info[2]);
		return 2;
	}
	return 0;
}
void Juego::Dibujar() {//Dibujo los distintos elementos del juego
	wind->clear();
	wind->draw(_puntaje[0]);
	wind->draw(_puntaje[1]);
	wind->draw(_puntos);
	wind->draw(_puntosamigos);
	wind->draw(_info[0]);
	_personajes->Dibujar(wind);
	wind->draw(_salon);
	wind->draw(_info[3]);
	wind->draw(textvida);
	FinJuego();
	mira->Dibujar(wind);
	wind->display();
}