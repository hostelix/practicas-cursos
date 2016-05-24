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

#define PIEZA_PEON "[P]"
#define PIEZA_REINA "[R]"
#define PIEZA_REY "[K]"
#define PIEZA_ALFIL "[A]"
#define PIEZA_TORRE "[T]"
#define PIEZA_CABALLO "[C]"

#define COLOR_ROJO     91
#define COLOR_VERDE    92


#define IMPRIME_COLOR_PIEZA(color, texto) printf("\x1b[%dm%s\x1b[0m",color, texto)


typedef struct{
	int pieza; // Numero de la pieza identidificada en las constantes simbolicas
	int color_pieza; //Numero del color identificada en las contantes simbolicas
}Pieza;

typedef struct {
	Pieza tabla[MAX][MAX];
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
			//Peones
			if(fila == 1){
				tablero_ajedrez->tabla[fila][colum].pieza = PEON;
				tablero_ajedrez->tabla[fila][colum].color_pieza = COLOR_ROJO;
			}
			else if(fila == 6){
				tablero_ajedrez->tabla[fila][colum].pieza = PEON;
				tablero_ajedrez->tabla[fila][colum].color_pieza = COLOR_VERDE;
			}
			
			//Torres
			else if((fila == 0 && colum == 0) || (fila == 0 && colum == 7)){
				tablero_ajedrez->tabla[fila][colum].pieza = TORRE;
				tablero_ajedrez->tabla[fila][colum].color_pieza = COLOR_ROJO;
			}
			else if((fila == 7 && colum == 0)|| (fila == 7 && colum == 7)){
				tablero_ajedrez->tabla[fila][colum].pieza = TORRE;
				tablero_ajedrez->tabla[fila][colum].color_pieza = COLOR_VERDE;
			}
			//Caballos
			else if((fila == 0 && colum == 1) || (fila == 0 && colum == 6)){
				tablero_ajedrez->tabla[fila][colum].pieza = CABALLO;
				tablero_ajedrez->tabla[fila][colum].color_pieza = COLOR_ROJO;
			}
			else if((fila == 7 && colum == 1) || (fila == 7 && colum == 6)){
				tablero_ajedrez->tabla[fila][colum].pieza = CABALLO;
				tablero_ajedrez->tabla[fila][colum].color_pieza = COLOR_VERDE;
			}
			//Alfiles
			else if((fila == 0 && colum == 2) || (fila == 0 && colum == 5)){
				tablero_ajedrez->tabla[fila][colum].pieza = ALFIL;
				tablero_ajedrez->tabla[fila][colum].color_pieza = COLOR_ROJO;
			}
			else if((fila == 7 && colum == 2) || (fila == 7 && colum == 5)){
				tablero_ajedrez->tabla[fila][colum].pieza = ALFIL;
				tablero_ajedrez->tabla[fila][colum].color_pieza = COLOR_VERDE;
			}
			//Reina
			else if((fila == 0 && colum == 3)){
				tablero_ajedrez->tabla[fila][colum].pieza = REINA;
				tablero_ajedrez->tabla[fila][colum].color_pieza = COLOR_ROJO;
				
			}
			else if((fila == 7 && colum == 3)){
				tablero_ajedrez->tabla[fila][colum].pieza = REINA;
				tablero_ajedrez->tabla[fila][colum].color_pieza = COLOR_VERDE;
			}
			//Rey
			else if((fila == 0 && colum == 4)){
				tablero_ajedrez->tabla[fila][colum].pieza = REY;
				tablero_ajedrez->tabla[fila][colum].color_pieza = COLOR_ROJO;
			}
			else if((fila == 7 && colum == 4)){
				tablero_ajedrez->tabla[fila][colum].pieza = REY;
				tablero_ajedrez->tabla[fila][colum].color_pieza = COLOR_VERDE;
			}
			else{
				tablero_ajedrez->tabla[fila][colum].pieza = VACIO;
			}
		}
	}
}
void mostrar_tablero(Tablero *tablero_ajedrez){
	for(int fila = 0; fila < MAX; fila++){
		for(int colum = 0; colum < MAX; colum++){
			switch(tablero_ajedrez->tabla[fila][colum].pieza){
				case PEON:
					IMPRIME_COLOR_PIEZA(tablero_ajedrez->tabla[fila][colum].color_pieza,PIEZA_PEON);
					break;	
				case REINA:
					IMPRIME_COLOR_PIEZA(tablero_ajedrez->tabla[fila][colum].color_pieza,PIEZA_REINA);
					break;
				case REY:
					IMPRIME_COLOR_PIEZA(tablero_ajedrez->tabla[fila][colum].color_pieza,PIEZA_REY);
					break;
				case TORRE:
					IMPRIME_COLOR_PIEZA(tablero_ajedrez->tabla[fila][colum].color_pieza,PIEZA_TORRE);
					break;
				case ALFIL:
					IMPRIME_COLOR_PIEZA(tablero_ajedrez->tabla[fila][colum].color_pieza,PIEZA_ALFIL);
					break;
				case CABALLO:
					IMPRIME_COLOR_PIEZA(tablero_ajedrez->tabla[fila][colum].color_pieza,PIEZA_CABALLO);
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