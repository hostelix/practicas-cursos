#include <iostream>
#include <signal.h>
#include <array>

using namespace std;

#define MAX 8

#define VACIO 0
#define PEON 1
#define REINA 2
#define REY 3
#define ALFIL 4
#define TORRE 5
#define CABALLO 6

typedef struct {
	int tabla[MAX][MAX];
}Tablero;


void senal_terminar_programa(int senal)
{
	int respuesta = 0;
	if (senal == SIGINT){
		cout << "Desea salir del programa? SI[1] - NO[0]" << endl;
		cin >> respuesta;
		
		if(respuesta){
			exit(EXIT_SUCCESS);
		}
	}
}
void llenar_tablero(Tablero *tablero_ajedrez){
	for(int fila = 0; fila < MAX; fila++){
		for(int colum = 0; colum < MAX; colum++){
			if(fila == 1 || fila == 6){
				tablero_ajedrez->tabla[fila][colum] = PEON;
			}
			else{
				tablero_ajedrez->tabla[fila][colum] = VACIO;
			}
		}
	}
}
void mostrar_tablero(Tablero *tablero_ajedrez){
	for(int fila = 0; fila < MAX; fila++){
		for(int colum = 0; colum < MAX; colum++){
			switch(tablero_ajedrez->tabla[fila][colum]){
				case PEON:
					cout << "[" << PEON << "]";
					break;	
				case REINA:
					cout << "[" << REINA << "]";
					break;
				case REY:
					cout << "[" << REY << "]";
					break;
				case TORRE:
					cout << "[" << TORRE << "]";
					break;
				case ALFIL:
					cout << "[" << ALFIL << "]";
					break;
				case CABALLO:
					cout << "[" << CABALLO << "]";
					break;
				default:
					cout << "[ ]";
					break;
			}
		}
		cout << endl;
	}
}



int main()
{/*
	//Se llama la funcion signal que escuchara el SIGINT
	signal(SIGINT, senal_terminar_programa);
	
	//Bucle infinito para la senal
	while(1){
		
	}*/
	
	Tablero *tablero_juego = new Tablero;
	
	llenar_tablero(tablero_juego);
	
	mostrar_tablero(tablero_juego);
	
	
	return 0;
}
