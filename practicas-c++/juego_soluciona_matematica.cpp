#include <iostream>
#include <time.h> //Libreria para manejar le time()
#include <stdlib.h> //Libreria para manejar le rand()
#include <vector>

//Tiempo maximo para realizar las operaciones
#define TIEMPO_MAX 10

#define PUNTAJE_SUMA 100
#define PUNTAJE_RESTA 500
#define PUNTAJE_MULTIPLICACION 800
#define PUNTAJE_DIVISION 1600


using namespace std;

//Estructura para almacenar el puntaje de cada jugador que entre al juego
typedef struct{
	char nombre[50];
	float puntaje;
}TJugador;

//Estructura para almacenar la lista de jugadores dinamica
typedef vector<TJugador> ListaJugadores;

//funcion para generar numeros aleatorios
int obtener_numero_aleatorio(int limite_inferior, int limite_superior);

//Funcion para crear un nuevo jugador
TJugador crear_jugador();

//Funcion que ejecuta el juego
void nuevo_juego(TJugador jugador, int rango_min, int rango_max, char array_operaciones[], ListaJugadores &lista_jugadores);

//Funcion para pausar el juego
void pausa_mensaje(const char *mensaje);

bool verficar_tiempo(double tiempo);

void generar_operacion_aritmetica(char array_operaciones[], int min, int max, TJugador &jugador){
	
	int operacion = obtener_numero_aleatorio(0,3);
	int num_a = obtener_numero_aleatorio(min, max);
	int num_b = obtener_numero_aleatorio(min, max);
	float resultado_real=0, respuesta_jugador=0;
	int puntaje_actual = 0;
	
	
	cout << endl;
	
	switch(array_operaciones[operacion]){
		case '+':
			cout << "Operacion SUMA" << endl;
			resultado_real = num_a + num_b;
			puntaje_actual = PUNTAJE_SUMA;
		break;
		case '-':
			cout << "Operacion RESTA" << endl;
			resultado_real = num_a - num_b;
			puntaje_actual = PUNTAJE_RESTA;
		break;
		case '*':
			cout << "Operacion MULTIPLICACION" << endl;
			resultado_real = num_a * num_b;
			puntaje_actual = PUNTAJE_MULTIPLICACION;
		break;
		case '/':
			cout << "Operacion DIVISION" << endl;
			resultado_real = num_a / num_b;
			puntaje_actual = PUNTAJE_DIVISION;
		break;
			
	}
	
	cout << num_a << array_operaciones[operacion] << num_b << " : ?" << endl;
	cout << "Introduce la respuesta >"; cin >> respuesta_jugador;
	
	if(resultado_real == respuesta_jugador){
		cout << "Excelente, respuesta correcta" << endl;
		jugador.puntaje += puntaje_actual;
	}
	else{
		cout << "Respuesta incorrecta :( No eres tan bueno con las matematicas" << endl;
	}
	
	
}


int main() {
	
	char operaciones_matematicas[4] = {'+','-','*','/'};
	
	//La semilla para generar numeros aleatorios
	srand(time(NULL));
	
	//Variables para manejar el rango de los numero generados
	int rango_min = 1;
	int rango_max = 50;
	
	//variable para manejar las opciones
	int opcion_1;
	
	//vector que contendra los jugadores
	ListaJugadores vector_jugadores;
	
	bool salir = false;
	
	do{		
		cout << "Bienvenidos al juego Soluciona La Matematica" << endl;
		cout << "1) Juego Nuevo" << endl;
		cout << "2) Ver resultados" << endl;
		cout << "3) Salir" << endl;
		cin >> opcion_1;
		
		switch(opcion_1){
			case 1:{
				
				TJugador nuevo_jugador = crear_jugador();
				
				nuevo_juego(nuevo_jugador,rango_min, rango_max, operaciones_matematicas, vector_jugadores);
				break;
			}
				
			case 2:{
				
				cout << endl;
				cout << "*************** TABLA DE RESULTADOS JUGADORES *****************" << endl;
				
				for(int i=0; i< vector_jugadores.size(); i++){
					cout << "JUGADOR: " << vector_jugadores[i].nombre << " - PUNTAJE: " <<  vector_jugadores[i].puntaje << endl;
				}
				break;
			}
				
			case 3:
				salir = true;
			break;
				
		}
	
	} while(!salir);
	
	return 0;
}


//funcion para generar numeros aleatorios
int obtener_numero_aleatorio(int limite_inferior, int limite_superior){
	return(limite_inferior + rand() % (limite_superior +1 - limite_inferior));
}

TJugador crear_jugador(){
	TJugador nuevo;
	
	cout << "Ingrese el nombre del jugador >"; cin >> nuevo.nombre; //Se lee el nombre del jugador
	
	nuevo.puntaje = 0; //Se guarda el puntaje 0 porque no comienza el juego aun
	
	return nuevo;
}

//se le colocaron los aspersan para que sean parametros de entrada y salida, osea que se puedan modificar dentro de la funcion
void cambiar_rango_numeros_aleatorios(int &min, int &max){
	int tmp;
	
	cout << "Rango actual: min[" << min << "] - max[" << max << "]" << endl << endl;
	
	cout << "Introduce el rango minimo " << endl << "(introduzca 0 si se desea dejar el por defecto)" << endl << ">";
	cin >> tmp;
	
	if(tmp != 0){
		min = tmp;
	}
	
	cout << "Introduce el rango maximo " << endl << "(introduzca 0 si se desea dejar el por defecto)" << endl << ">";
	cin >> tmp;
	
	if(tmp != 0){
		max = tmp;
	}
	
	cout << "Nuevo rango establecido min[" << min << "] - max[" << max << "]" << endl << endl;
}

void nuevo_juego(TJugador jugador, int rango_min, int rango_max, char array_operaciones[], ListaJugadores &lista_jugadores){
	
	int resp;
	double tiempo_total_juego = 0;
	
	time_t tiempo_inicio_operacion, tiempo_fin_operacion; // variables para controlar el tiempo que tarda respondiendo la respuesta
	
	cout << "Bienvenido al juego " << jugador.nombre << endl << endl;
	
	cout << "Desea cambiar el rango de numeros aleatorios? SI[1] - NO[0] " << endl;
	cin >> resp;
	
	if(resp){
		cambiar_rango_numeros_aleatorios(rango_min, rango_max);
	}
	
	pausa_mensaje("Presione una tecla para comenzar el juego");
	
	system("clear");
	
	
	do{
		time(&tiempo_inicio_operacion); // Obtenemos el tiempo actual
		
		generar_operacion_aritmetica(array_operaciones,rango_min, rango_max, jugador);
		
		time(&tiempo_fin_operacion); // Obtenemos el tiempo actual
		
		//Acumulamos el tiempo que tardo en responder la operacion
		tiempo_total_juego += difftime(tiempo_fin_operacion,tiempo_inicio_operacion);
		
	} while(verficar_tiempo(tiempo_total_juego));
	
	cout << endl << " **************  Lo siento se acabo tu tiempo ************" << endl << endl;
	
	cout << "Bien hecho " << jugador.nombre << " Obtuviste un puntaje de : " << jugador.puntaje << endl;
	cout << "En un tiempo de " << TIEMPO_MAX << " segundos" << endl;
	
	//Anexamos el nuevo jugador al vector
	lista_jugadores.push_back(jugador);
	
}

void pausa_mensaje(const char *mensaje){
	setbuf(stdin, NULL);
	cout << mensaje << endl;
	getchar();
}


bool verficar_tiempo(double tiempo){
	if(tiempo>=TIEMPO_MAX){
		return false;
	}
	return true;
}

