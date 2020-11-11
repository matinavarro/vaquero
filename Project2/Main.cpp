#include "juego.h"
#include <ctime>

//Declaración de variable

int main(int argc, char* argv[]) {
	srand(time(NULL));
	Juego J;
	J.Loop();
	return 0;
}