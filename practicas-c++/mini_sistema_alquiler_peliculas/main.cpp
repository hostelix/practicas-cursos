#include <iostream>
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
		
	VectorClientes(){
		this->tamano = 100;
		this->vector_ = new Cliente[this->tamano];
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
		
		generar_recibo_recarga(cliente_recarga, creditos_tmp);
		
		vector_clientes->set_cliente(cliente_recarga, id_cliente);
	}
}

void mostrar_clientes(VectorClientes *vector_clientes){}

int main() {
	
	int opcion_1, opcion_2, opcion_3;
	bool salir_menu_1 = false, salir_menu_2 = false;
	
	VectorClientes *db_clientes = new VectorClientes;
	
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
					
				} while(!salir_menu_2);
				break;
			case 3:
				do{
					
				} while(!salir_menu_2);
				break;
			case 4:
				do{
					
				} while(!salir_menu_2);
				break;
			case  5:
				salir_menu_1 = true;
			break;
		}
	} while(!salir_menu_1);
	return 0;
}

