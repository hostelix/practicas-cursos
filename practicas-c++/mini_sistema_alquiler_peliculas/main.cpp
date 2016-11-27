#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

#define TARIFA_CREDITO 300
#define TARIFA_IVA 0.12


class Persona {
	private:
		char nombre[30];
		char apellido[30];
		char cedula[30];
	public:
		char *get_nombre(){
			return this->nombre;
		}
		char *get_apellido(){
			return this->apellido;
		}
		char *get_cedula(){
			return this->cedula;
		}
		
		void set_nombre(char *nombre){
			strcpy(this->nombre, nombre);
		}
		void set_apellido(char *apellido){
			strcpy(this->apellido, apellido);
		}
		void set_cedula(char *cedula){
			strcpy(this->cedula, cedula);
		}
		
		void registrar_datos(){
			cout << "Nombre: ";
			cin >> this->nombre;
			
			cout << "Apellido: ";
			cin >> this->apellido;
			
			cout << "Cedula: ";
			cin >> this->cedula;
		}
		
	Persona(){}
	~Persona(){}
};

class Cliente : public Persona {
	private:
		int periodo_alquiler;
		float creditos;
		
	public:
		int get_periodo_alquiler(){
			return this->periodo_alquiler;
		}
		float get_creditos(){
			return this->creditos;
		}
		
		void set_creditos(float creditos){
			this->creditos = creditos;
		}
		void agregar_creditos(float creditos){
			this->creditos += creditos;
		}
		void reducir_creditos(float creditos){
			this->creditos -= creditos;
		}
		void set_periodo_alquiler(int periodo){
			this->periodo_alquiler = periodo;
		}
		
		void registrar_datos()
		{
			int resp;
			Persona::registrar_datos();
			cout << "Periodo de alquiler" << endl;
			cout << "1) 24 horas" << endl;
			cout << "2) 48 horas" << endl;
			cout << "3) Semanal" << endl;
			cin >> resp;
			this->set_periodo_alquiler(resp);
		}
		
		void imprimir_datos(){
			cout << endl;
			cout << "Nombre: " << this->get_nombre() << endl;
			cout << "Apellido: " << this->get_apellido() << endl;
			cout << "Cedula: " << this->get_cedula()<< endl;
			cout << "Periodo Alquiler: " << this->get_periodo_alquiler() << endl;
			cout << "Creditos: " << this->get_creditos() << endl << endl;
		}
		
	Cliente(): Persona(){
		this->creditos = 0;
		this->periodo_alquiler = 0;
	}
	~Cliente(){}
};

class VectorClientes {
	private:
		Cliente *vector_;
		int tamano;
		int tamano_actual;
		int posicion_actual;
	
	public:
		void agregar_cliente(Cliente client){
			this->vector_[this->posicion_actual] = client;
			this->posicion_actual++;
			this->tamano_actual++;
		}
		
		Cliente *get_vector_clientes(){
			return this->vector_;
		}
		
		int buscar_cliente(char *cedula){
			int posicion_encontrado = -1;
			
			for(int i=0; i<this->tamano_actual; i++){
				if(strcmp(this->vector_[i].get_cedula(), cedula) == 0){
					posicion_encontrado = i;
					break;
				}
			}
			return posicion_encontrado;
		}
		
		Cliente get_cliente(int posicion){
			return this->vector_[posicion];
		}
		
		void set_cliente(Cliente client, int posicion){
			this->vector_[posicion] = client;
		}
		
		int get_tamano_vector(){
			return this->tamano_actual;
		}
		
	VectorClientes(){
		this->tamano = 100;
		this->vector_ = new Cliente[this->tamano];
		this->posicion_actual = 0;
		this->tamano_actual = 0;
	}
		
};

class Pelicula {
	private:
		int identificador;
		char nombre[70];
		char categoria[30];
		char tipo[20]; // Serie, Pelicula
		bool estado; // Disponible, ocupado
		int valor;
	public:
		char *get_nombre(){
			return this->nombre;
		}
		void set_nombre(char *nombre){
			strcpy(this->nombre, nombre);
		}
		
		char *get_categoria(){
			return this->categoria;
		}
		void set_categoria(char *categoria){
			strcpy(this->categoria, categoria);
		}
		
		char *get_tipo(){
			return this->tipo;
		}
		void set_tipo(char *tipo){
			strcpy(this->tipo, tipo);
		}
		
		bool get_estado(){
			return this->estado;
		}
		void set_estado(bool estado){
			this->estado = estado;
		}
		
		void set_identificador(int identi){
			this->identificador = identi;
		}
		int get_identificador(){
			return this->identificador;
		}
		
		void set_valor(int valor){
			this->valor = valor;
		}
		int get_valor(){
			return this->valor;
		}
		
		void imprimir_datos(){
			cout << endl;
			cout << "Identificador: " << this->get_identificador()<< endl;
			cout << "Nombre: " << this->get_nombre() << endl;
			cout << "Categoria: " << this->get_categoria() << endl;
			cout << "Tipo: " << this->get_tipo()<< endl;
			cout << "Estado: " << ((this->get_estado())?("Disponible"):("No Disponible")) << endl;
			cout << "Valor: " << this->get_valor() << endl;
		}
};


class VectorPeliculas{
	private:
		Pelicula *vector_;
		int tamano;
		int tamano_actual;
		int posicion_actual;
		
	public:
		void agregar_pelicula(Pelicula peli){
			peli.set_identificador(this->posicion_actual+1);
			this->vector_[this->posicion_actual] = peli;
			this->posicion_actual++;
			this->tamano_actual++;
		}
		
		Pelicula *get_vector(){
			return this->vector_;
		}
		

		Pelicula get_pelicula(int posicion){
			return this->vector_[posicion];
		}
		
		void set_pelicula(Pelicula peli, int posicion){
			this->vector_[posicion] = peli;
		}
		
		int get_tamano_vector(){
			return this->tamano_actual;
		}
		
		VectorPeliculas(){
			this->tamano = 100;
			this->vector_ = new Pelicula[this->tamano];
			this->posicion_actual = 0;
			this->tamano_actual = 0;
		}
	
};

void generar_recibo_recarga(Cliente client, float nuevos_creditos){
	cout << "Cliente: " << client.get_nombre() << " " << client.get_apellido() << endl;
	cout << "Cedula: " << client.get_cedula() << endl;
	cout << "Catidad de creditos a recargar: " << nuevos_creditos << endl;
	cout << "Precio unitario de cada credito: " << TARIFA_CREDITO << " Bs" << endl;
	cout << "Subtotal: " << nuevos_creditos << " x " << TARIFA_CREDITO << ": " << nuevos_creditos*TARIFA_CREDITO << " Bs"<< endl;
	cout << "IVA 12%: " << nuevos_creditos*TARIFA_CREDITO*TARIFA_IVA << " Bs" << endl;
	cout << "Monto Total (+ IVA): " << nuevos_creditos*TARIFA_CREDITO*(1+TARIFA_IVA) <<  " Bs" <<endl;
}

void registro_clientes(VectorClientes *vector_clientes){
	Cliente tmp;
	tmp.registrar_datos();
	
	vector_clientes->agregar_cliente(tmp);
	cout << "Cliente registrado con exito" << endl;
}
void recargar_clientes(VectorClientes *vector_clientes){
	char cedula_tmp[8];
	cout << "Introduzca la cedula del cliente que recargara creditos" << endl << ">";
	cin >> cedula_tmp;
	
	int id_cliente = vector_clientes->buscar_cliente(cedula_tmp);
	
	if(id_cliente == -1){
		cout << "No existe ningun registro con esta cedula" << endl;
	}
	else{
		float creditos_tmp;
		Cliente cliente_recarga = vector_clientes->get_cliente(id_cliente);
		cliente_recarga.imprimir_datos();
		
		cout << "Introduzca la cantidad de creditos que desea recargar" << endl;
		cin >> creditos_tmp;
		
		cliente_recarga.agregar_creditos(creditos_tmp);
		
		generar_recibo_recarga(cliente_recarga, creditos_tmp);
		
		vector_clientes->set_cliente(cliente_recarga, id_cliente);
	}
}

void mostrar_clientes(VectorClientes *vector_clientes){
	for(int i=0; i<vector_clientes->get_tamano_vector(); i++){
		vector_clientes->get_cliente(i).imprimir_datos();
	}
}

void cargar_catalogo_peliculas(VectorPeliculas *vector_peliculas){
	
	Pelicula tmp;
	
	tmp.set_nombre((char*)"Doctor Strange");
	tmp.set_categoria((char*)"Accion");
	tmp.set_tipo((char*)"Pelicula");
	tmp.set_estado(true);
	tmp.set_valor(10);
	vector_peliculas->agregar_pelicula(tmp);
	
	tmp.set_nombre((char*)"La llegada");
	tmp.set_categoria((char*)"Drama");
	tmp.set_tipo((char*)"Pelicula");
	tmp.set_estado(true);
	tmp.set_valor(8);
	vector_peliculas->agregar_pelicula(tmp);
	
	tmp.set_nombre((char*)"Escuadrón Suicida");
	tmp.set_categoria((char*)"Fantasia");
	tmp.set_tipo((char*)"Pelicula");
	tmp.set_estado(true);
	tmp.set_valor(5);
	vector_peliculas->agregar_pelicula(tmp);
	
	tmp.set_nombre((char*)"Buscando a Dory");
	tmp.set_categoria((char*)"Animada");
	tmp.set_tipo((char*)"Pelicula");
	tmp.set_estado(true);
	tmp.set_valor(2);
	vector_peliculas->agregar_pelicula(tmp);
	
	tmp.set_nombre((char*)"Interstellar");
	tmp.set_categoria((char*)"Ciencia Ficcion");
	tmp.set_tipo((char*)"Pelicula");
	tmp.set_estado(true);
	tmp.set_valor(8);
	vector_peliculas->agregar_pelicula(tmp);
	
	tmp.set_nombre((char*)"Lucifer");
	tmp.set_categoria((char*)"Crimen");
	tmp.set_tipo((char*)"Serie");
	tmp.set_estado(true);
	tmp.set_valor(12);
	vector_peliculas->agregar_pelicula(tmp);
	
	tmp.set_nombre((char*)"Van Helsing");
	tmp.set_categoria((char*)"Aventura");
	tmp.set_tipo((char*)"Serie");
	tmp.set_estado(true);
	tmp.set_valor(2);
	vector_peliculas->agregar_pelicula(tmp);
	
}

void consultar_cliente(VectorClientes *vector_clientes){
	char cedula_tmp[8];
	cout << "Introduzca la cedula del cliente que desea consultar" << endl << ">";
	cin >> cedula_tmp;
	
	int id_cliente = vector_clientes->buscar_cliente(cedula_tmp);
	
	if(id_cliente == -1){
		cout << "No existe ningun registro con esta cedula" << endl;
	}
	else{
		vector_clientes->get_cliente(id_cliente).imprimir_datos();
	}
}


void mostrar_peliculas(VectorPeliculas *vector_peliculas){
	for(int i=0; i<vector_peliculas->get_tamano_vector(); i++){
		vector_peliculas->get_pelicula(i).imprimir_datos();
	}
}

void generar_comprobante_alquiler(int *peliculas_seleccionadas, int tam_vector, Cliente client, VectorPeliculas *vector_peliculas){
	int total_creditos=0;
	
	for(int i=0; i<tam_vector; i++){
		total_creditos += vector_peliculas->get_pelicula(peliculas_seleccionadas[i]).get_valor();
	}
	cout << endl << endl << "------------------------ Comprobante ----------------------------" << endl;
	cout << "Cliente: " << client.get_nombre() << " " << client.get_apellido() << endl;
	cout << "Cedula: " << client.get_cedula() << endl;
	cout << "Catidad de creditos: " << total_creditos << endl;
	cout << "Peliculas Seleccionadas" << endl;
	for(int i=0; i<tam_vector; i++){
		vector_peliculas->get_pelicula(peliculas_seleccionadas[i]).imprimir_datos();
	}
	cout << "Subtotal: " << total_creditos << " x " << TARIFA_CREDITO << ": " << total_creditos*TARIFA_CREDITO << " Bs"<< endl;
	cout << "IVA 12%: " << total_creditos*TARIFA_CREDITO*TARIFA_IVA << " Bs" << endl;
	cout << "Monto Total (+ IVA): " << total_creditos*TARIFA_CREDITO*(1+TARIFA_IVA) <<  " Bs" <<endl;
	cout << "------------------------ Comprobante ----------------------------" << endl;
}

void alquilar_peliculas(VectorClientes *vector_clientes,VectorPeliculas *vector_peliculas){
	Cliente cliente_alquiler;
	char cedula_cliente[8];
	int peliculas_selccionadas[10] = {0};
	int identi, tam_vector_seleccionadas = 0, total_creditos_seleccionados=0;
	
	
	cout << "Introduzca la cedula del cliente >"; cin >> cedula_cliente;
	
	int id_cliente = vector_clientes->buscar_cliente(cedula_cliente);
	
	if(id_cliente == -1){
		cout << "No existe ningun registro con esta cedula" << endl;
	}
	else{
		cliente_alquiler = vector_clientes->get_cliente(id_cliente);
		
		do{
			cout << "------- Listado de peliculas -------" << endl;
			mostrar_peliculas(vector_peliculas);
			cout << "Seleccione las peliculas que desea, Escribiendo el identificador - Escriba 0 para salir" << endl;
			cout << "> ";
			cin >> identi;

			if(identi != 0){
				if(identi > vector_peliculas->get_tamano_vector()){
					cout << "Error identificador no existe" << endl;
				}else{
					int id_pelicula = identi-1;
					
					if(vector_peliculas->get_pelicula(id_pelicula).get_estado()){
						peliculas_selccionadas[tam_vector_seleccionadas] = id_pelicula;
						tam_vector_seleccionadas++;
					}
					else{
						cout << "Esta pelicula no esta disponible" << endl;
					}
					
				}
			}
			
		} while(identi != 0);
		
		//Sumamos todos los creditos de las peliculas seleccionadas
		for(int i=0; i<tam_vector_seleccionadas; i++){
			total_creditos_seleccionados += vector_peliculas->get_pelicula(peliculas_selccionadas[i]).get_valor();
		}
		
		if(cliente_alquiler.get_creditos() >= total_creditos_seleccionados){
			//Reducimos los creditos del cliente
			vector_clientes->get_cliente(id_cliente).reducir_creditos(total_creditos_seleccionados);
			
			//Actualizamos el estado de las peliculas
			for(int i=0; i<tam_vector_seleccionadas; i++){
				Pelicula pelicula_tmp = vector_peliculas->get_pelicula(peliculas_selccionadas[i]);
				pelicula_tmp.set_estado(false);
				vector_peliculas->set_pelicula(pelicula_tmp,peliculas_selccionadas[i]);
			}
			
			generar_comprobante_alquiler(peliculas_selccionadas,tam_vector_seleccionadas,cliente_alquiler,vector_peliculas);
			
		}else{
			cout << "Creditos cliente: " << cliente_alquiler.get_creditos() << endl;
			cout << "Total de creditos seleccionados: " << total_creditos_seleccionados << endl;
			cout << "Lo siento usted no tiene disponibilidad de creditos" << endl;
		}
		
	}
	
}


int main() {
	
	int opcion_1, opcion_2, opcion_3;
	bool salir_menu_1 = false, salir_menu_2 = false;
	
	VectorClientes *db_clientes = new VectorClientes;
	VectorPeliculas *db_peliculas = new VectorPeliculas;
	
	cargar_catalogo_peliculas(db_peliculas);
	
	do{
		cout << "|*******| Bienvenido al centro de alquiler de peliculas HEPBURN |*******|" << endl;
		cout << "1) Registro de clientes y recarga de creditos" << endl;
		cout << "2) Alquiler de peliculas" << endl;
		cout << "3) Proveedores de peliculas" << endl;
		cout << "4) Consultar" << endl;
		cout << "5) Salir" << endl;
		
		cin >> opcion_1;
		
		switch(opcion_1){
			case 1:
				do{
					cout << "|*******| Bienvenido al centro de alquiler de peliculas HEPBURN |*******|" << endl;
					cout << "1) Registro de clientes" << endl;
					cout << "2) Recarga de creditos" << endl;
					cout << "3) Mostrar clientes" << endl;
					cout << "4) Salir" << endl;
					
					cin >> opcion_2;
					
					switch(opcion_2){
						case 1:
							registro_clientes(db_clientes);
							break;
						case 2:
							recargar_clientes(db_clientes);
							break;
						case 3:
							mostrar_clientes(db_clientes);
							break;
						case 4:
							salir_menu_2 = true;
							break;
					}
					
				} while(!salir_menu_2);
				break;
			case 2:
				do{
					
					cout << "|*******| Bienvenido al centro de alquiler de peliculas HEPBURN |*******|" << endl;
					cout << "1) Alquilar Pelicula" << endl;
					cout << "2) Mostrar Peliculas" << endl;
					cout << "3) Salir" << endl;
					
					cin >> opcion_2;
					
					switch(opcion_2){
						case 1:
							alquilar_peliculas(db_clientes,db_peliculas);
							break;
						case 2:
							mostrar_peliculas(db_peliculas);
							break;
						case 3:
							salir_menu_2 = true;
							break;
					}
					
				} while(!salir_menu_2);
				break;
			case 3:
				do{
					
				} while(!salir_menu_2);
				break;
			case 4:
				consultar_cliente(db_clientes);
				break;
			case  5:
				salir_menu_1 = true;
			break;
		}
	} while(!salir_menu_1);
	return 0;
}

