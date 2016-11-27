#include <iostream>
#include <string.h>
using namespace std;

#define ANIO_ACTUAL 2016

class Fecha{
	int dia, mes, anio;
	
	void registrar_fecha(){
		cout << "Dia: "; cin >> this->dia;
		cout << "Mes: "; cin >> this->mes;
		cout << "Año: "; cin >> this->anio;
	}
	
	int calcular_edad(){
		return ANIO_ACTUAL - this->anio;
	}
};

class Producto {
	private:
		char nombre[30];
		char categoria[30];// cosecha, media barrica, crianza, reserva, gran reserva, reserva especial
		float precio;
	public:
		char *get_nombre(){
			return this->nombre;
		}
		char *get_categoria(){
			return this->categoria;
		}
		float get_precio(){
			return this->precio;
		}
		
		void set_nombre(char *nombre){
			strcpy(this->nombre, nombre);
		}
		void set_categoria(char *categoria){
			strcpy(this->categoria, categoria);
		}
		void set_precio(float precio){
			this->precio = precio;
		}
		
		void registrar_datos(){
			cout << "Nombre: ";
			cin >> this->nombre;
			
			cout << "Categoria: ";
			cin >> this->categoria;
			
			cout << "Precio: ";
			cin >> this->precio;
		}
		
		Producto(){}
		~Producto(){}
};

class Vino: public Producto{
	private:
		char temperatura[10];
		char comentario[80];
		char formato[20]; // media botella, tres cuartos, litro y medio, cinco litros

	public:
		float get_temperatura(){
			return this->temperatura;
		}
		void set_temperatura(float temperatura){
			this->temperatura = temperatura;
		}
		
		char *get_comentario(){
			return this->comentario;
		}
		void set_comentario(char *comentario){
			strcpy(this->comentario, comentario);
		}
		
		char *get_formato(){
			return this->formato;
		}
		void set_formato(char *formato){
			strcpy(this->formato, formato);
		}
		
		void registrar_datos(){
			Producto::registrar_datos();
			
			cout << "Temperatura: ";
			cin >> this->temperatura;
			
			cout << "Formato: ";
			cin >> this->formato;
			
			cout << "Comentario: ";
			cin >> this->comentario;
		}
		
		Vino() : Producto(){}
};

class Bodega {
	private:
		char nombre[30];
		char direccion[40];
		char correo[30];
		char telefono[15];
		
	public:
		char *get_nombre(){
			return this->nombre;
		}
		char *get_direccion(){
			return this->direccion;
		}
		char *get_correo(){
			return this->correo;
		}
		char *get_telefono(){
			return this->telefono;
		}
		
		void set_nombre(){
			strcpy(this->nombre, nombre);
		}
		void set_direccion(){
			strcpy(this->direccion, direccion);;
		}
		void set_correo(){
			strcpy(this->correo, correo);
		}
		void set_telefono(char *telefono){
			strcpy(this->telefono, telefono);
		}
};

class Cliente {
	private:
		char nombre[20];
		char correo[40];
		char telefono[15];
	public:
		char *get_nombre(){
			return this->nombre;
		}
		char *get_correo(){
			return this->correo;
		}
		char *get_telefono(){
			return this->telefono;
		}
		
		void set_nombre(char *nombre){
			strcpy(this->nombre, nombre);
		}
		void set_correo(){
			strcpy(this->correo, correo);
		}
		void set_telefono(char *telefono){
			strcpy(this->telefono, telefono);
		}
		void set_fecha_nacimiento(){
			this->fecha_nacimiento.registrar_fecha();
		}
};

class PesonaNatural: public Cliente{
	private:
		char apellido[20];
		Fecha fecha_nacimiento;
	public:
		char *get_apellido(){
			return this->apellido;
		}
		char *get_cedula(){
			return this->cedula;
		}
		
		
		void set_apellido(char *apellido){
			strcpy(this->apellido, apellido);
		}
		void set_cedula(char *cedula){
			strcpy(this->cedula, cedula);
		}
		void set_fecha_nacimiento(){
			this->fecha_nacimiento.registrar_fecha();
		}
};

class PersonaJuridica: public Cliente{
	private:
		char rif[15];
	public:
		char *get_rif(){
			return this->rif;
		}
		
		void set_rif(char *rif){
			strcpy(this->rif, rif);
		}
};
int main(int argc, char *argv[]) {
	
	return 0;
}

