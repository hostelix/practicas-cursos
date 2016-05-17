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

#define ARCHIVO_INSTRUCCION "instrucciones.txt"
#define ARCHIVO_CREDITOS "creditos.txt"
#define ARCHIVO_RESULTADOS "resultados.txt"

using namespace std;

typedef vector<int> VectorResultados;
//Estructura para almacenar el puntaje de cada jugador que entre al juego
typedef struct{
	char nombre[50];
	VectorResultados aciertos;
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

void generar_operacion_aritmetica(char array_operaciones[], int min, int max, TJugador &jugador);

int puntaje_total_jugador(TJugador jugador);

void leer_archivo(const char *nom_archivo);

void escribir_resultados(TJugador jugador);

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
		cout << "3) Instrucciones" << endl;
		cout << "4) Creditos" << endl;
		cout << "5) Salir" << endl;
		cin >> opcion_1;
		
		switch(opcion_1){
			case 1:{
				
				TJugador nuevo_jugador = crear_jugador();
				
				nuevo_juego(nuevo_jugador,rango_min, rango_max, operaciones_matematicas, vector_jugadores);
				break;
			}
				
			case 2:{
					
				system("clear");
				
				cout << endl;
				cout << "*************** TABLA DE RESULTADOS JUGADORES *****************" << endl;
				
				for(unsigned int i=0; i< vector_jugadores.size(); i++){
					cout << "JUGADOR: " << vector_jugadores[i].nombre << " - ACIERTOS: " << vector_jugadores[i].aciertos.size() << " - PUNTAJE: " <<  puntaje_total_jugador(vector_jugadores[i]) << endl;
					
					//Escribimos los resultados en el ARCHIVO_CREDITOS
					escribir_resultados(vector_jugadores[i]);
				}
				
				
				break;
			}
			
			case 3:{
				leer_archivo(ARCHIVO_INSTRUCCION);
				cout << endl;
				break;
			}
				
			case 4:{
				leer_archivo(ARCHIVO_CREDITOS);	
				cout << endl;
				break;
			}
			case 5:
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
	
	cout << "Bien hecho " << jugador.nombre << " Obtuviste un puntaje de : " << puntaje_total_jugador(jugador) << endl;
	cout << "Numero de aciertos: " << jugador.aciertos.size() << endl;
	cout << "En un tiempo de " << TIEMPO_MAX << " segundos" << endl;
	
	//Anexamos el nuevo jugador al vector
	lista_jugadores.push_back(jugador);
	
	pausa_mensaje("Presione una tecla para continuar");
	
	system("clear");
	
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
		jugador.aciertos.push_back(puntaje_actual); // Agregamos el nuevo puntaje al vector de puntajes
	}
	else{
		cout << "Respuesta incorrecta :( No eres tan bueno con las matematicas" << endl;
	}		
}

int puntaje_total_jugador(TJugador jugador){
	int total = 0;
	for(unsigned int i=0; i<jugador.aciertos.size(); i++){
		total += jugador.aciertos[i];
	}
	return total;
}


void leer_archivo(const char *nom_archivo){
	FILE *archivo = fopen(nom_archivo, "r");
	
	char *linea_archivo = NULL;
	size_t tamano_linea = 0;
	
	if (archivo == NULL){
		cout << "Error al abrir el archivo" << endl;
		exit(1);
	}
	
	
	while ((getline(&linea_archivo, &tamano_linea, archivo)) != -1) {
		
		cout << linea_archivo;
	}
	
	fclose(archivo);
}


void escribir_resultados(TJugador jugador){
	FILE *archivo = fopen(ARCHIVO_RESULTADOS, "a+");
	
	if (archivo == NULL){
		cout << "Error al abrir el archivo" << endl;
		exit(1);
	}
	
	fprintf(archivo,"Nombre: %s - Aciertos: %d - Resultado: %d \n",jugador.nombre, jugador.aciertos.size(), puntaje_total_jugador(jugador));
	
	fclose(archivo);
}
