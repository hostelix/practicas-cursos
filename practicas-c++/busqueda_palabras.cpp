#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string.h>

using namespace std;

#define NOMBRE_ARCHIVO "diccionario.txt"


typedef vector<char *> VectorPalabras;


void crear_archivo(){
	FILE *archivo = fopen(NOMBRE_ARCHIVO, "a+");
	
	if (archivo == NULL){
		cout << "Error al abrir el archivo" << endl;
		exit(1);
	}
	
	fclose(archivo);
}

void escribir_palabra(const char palabra[]){
	FILE *archivo = fopen(NOMBRE_ARCHIVO, "a+");
	
	if (archivo == NULL){
		cout << "Error al abrir el archivo" << endl;
		exit(1);
	}
	
	fprintf(archivo,"%s\n",palabra);
	
	fclose(archivo);
}

int obtener_numero_palabras(){
	FILE *archivo = fopen(NOMBRE_ARCHIVO, "r");
	int lineas = 0;
	char caracter;
	
	if (archivo == NULL){
		cout << "Error al abrir el archivo" << endl;
		exit(1);
	}
	
	while(!feof(archivo)){	
		caracter = fgetc(archivo);
		if(caracter == '\n'){
			lineas++;
		}
	}
	
	fclose(archivo);
	
	return lineas;
	
}

VectorPalabras leer_palabras(){
	FILE *archivo = fopen(NOMBRE_ARCHIVO, "r");

	char *linea_archivo = NULL;
	size_t tamano_linea = 0;
	
	if (archivo == NULL){
		cout << "Error al abrir el archivo" << endl;
		exit(1);
	}
	
	//Inicializamos el vector con el numero de palabras registradas
	VectorPalabras palabras;
	
	while ((getline(&linea_archivo, &tamano_linea, archivo)) != -1) {
		
		char *nueva = new char[tamano_linea];
		strcpy(nueva, linea_archivo);
		
		palabras.push_back(nueva);
	}
	
	fclose(archivo);
	
	return palabras;
}

bool existe_palabra_diccionario(VectorPalabras vector, char palabra[]){
	
	for(unsigned i=0; i<vector.size(); i++){
		
		char *palabra_tmp = strtok(vector[i],"\n");
		
		if(strcmp(palabra_tmp, palabra) == 0){
		
			return true;
		}
	}
	
	return false;
}

bool buscar_palabra_diccionario(VectorPalabras vector, char palabra[]){
	
	for(unsigned i=0; i<vector.size(); i++){
		
		char *palabra_tmp = strtok(vector[i],"\n");
		
		if(strcmp(palabra_tmp, palabra) == 0){
			
			cout << endl << "- - - - - - - Palabra encontrada - - - - - - -" << endl << endl;
			
			return true;
		}
	}
	
	cout << endl << "%%%%%% PALABRA NO ENCONTRADA %%%%%%%%" << endl << endl;
	return false;
}


int main() {
	
	bool salir_programa = false;
	int op = 0;
	
	crear_archivo(); //Creamos el archivo 
		
	VectorPalabras diccionario_palabras = leer_palabras(); //Vector contiene las palabras en el archivo
	
	do{
		cout << "Diccionario de palabras" << endl;
		cout << "1) Registrar una nueva palabra" << endl;
		cout << "2) Ver palabras registradas" << endl;
		cout << "3) Buscar una palabra en el diccionario" << endl;
		cout << "4) Salir" << endl;
		cin >> op;
	
		
		switch(op){
			case 1:{
				char palabra_tmp[50];
				cout << "Introduce la nueva palabra >"; cin >> palabra_tmp;
				
				if(!existe_palabra_diccionario(diccionario_palabras,palabra_tmp)){
					escribir_palabra(palabra_tmp);
					
					cout << "Palabra guardada con exito" << endl;
					
					diccionario_palabras.clear(); //vaciamos el vector de palabras para cargarlo nuevamente
					diccionario_palabras = leer_palabras();
					
					cout << endl;
				}
				else{
					cout << endl << "$$$$$$$$$$$  Esta palabra ya existe en el diccionario $$$$$$$$$$$" << endl << endl;
				}
			break;
			}
				
			case 2:{
					
				diccionario_palabras.clear(); //vaciamos el vector de palabras para cargarlo nuevamente
				diccionario_palabras = leer_palabras();
								
				cout << endl;
				cout << "Lista de palabras registradas" << endl;
				for(unsigned i=0; i<diccionario_palabras.size(); i++){
					cout << "Palabra: " << diccionario_palabras[i];
				}
				cout << endl;
				break;
			}
			case 3:{
				char palabra_tmp[50];
				cout << "Introduce la nueva palabra >"; cin >> palabra_tmp;
				
				buscar_palabra_diccionario(diccionario_palabras, palabra_tmp);
				break;
			}
				
			case 4:
				salir_programa = true;
			break;
		}
		
	}while(!salir_programa);
	
	return 0;
}

