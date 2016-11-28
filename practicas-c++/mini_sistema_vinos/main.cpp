#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

#define ANIO_ACTUAL 2016
#define CLIENTE_PERSONA 1
#define CLIENTE_EMPRESA 2

#define BOTELLA 1
#define CAJA_BOTELLA 2


class PersonaJuridica;
class PersonaNatural;
class ProductoInventario;
class ProductoCarrito;
class Pedido;
class Factura;

typedef vector<PersonaNatural> ArrayClientesPersonas;
typedef vector<PersonaJuridica> ArrayClientesEmpresas;
typedef vector<ProductoInventario> ArrayInventario;
typedef vector<ProductoCarrito> ArrayCarritoCompra;
typedef vector<Pedido> ArrayPedidos;
typedef vector<Factura> ArrayFacturas;

class Fecha{
	int dia, mes, anio;
	
	public :
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
		float temperatura;
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
		
		void imprimir_datos(){
			cout << "Nombre: " << this->get_nombre() << endl;
			cout << "Categoria: " << this->get_categoria() << endl;
			cout << "Precio: " << this->get_precio() << endl;
			cout << "Temperatura: " << this->get_temperatura() << endl;
			cout << "Comentario: " << this->get_comentario() << endl;
			cout << "Formato: " << this->get_formato() << endl;
		}
		
		Vino() : Producto(){}
};

class ProductoInventario {
	public:
		Vino producto_vino;
		int cantidad_botellas;
		int tipo_producto; //1 - botella, 2- caja botellas
		int cantidad_disponible;
		
		void imprimir_datos(){
			producto_vino.imprimir_datos();
			cout << "Cantidad de botellas: " << this->cantidad_botellas << endl;
			cout << "Tipo Producto: " << ((this->tipo_producto == BOTELLA)?("Botella"):("Caja Botellas")) << endl;
			cout << "Cantidad Disponible: " << this->cantidad_disponible << endl;
			cout << "--------------------------------------------------------" << endl;
		}
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
		
		void set_nombre(char *nombre){
			strcpy(this->nombre, nombre);
		}
		void set_direccion(char *direccion){
			strcpy(this->direccion, direccion);;
		}
		void set_correo(char *correo){
			strcpy(this->correo, correo);
		}
		void set_telefono(char *telefono){
			strcpy(this->telefono, telefono);
		}
	Bodega(){}
};

class Cliente {
	private:
		char nombre[20];
		char correo[40];
		char telefono[15];
		char direccion[30];
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
		
		char *get_direccion(){
			return this->direccion;
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
		
		void registrar_datos(){
			cout << "Nombre: ";
			cin >> this->nombre;
			
			cout << "Correo: ";
			cin >> this->correo;
			
			cout << "Telefono: ";
			cin >> this->telefono;
			
			cout << "Direccion: ";
			cin >> this->direccion;
		}
};

class PersonaNatural: public Cliente{
	private:
		char apellido[20];
		char cedula[9];
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
		void registrar_datos(){
			Cliente::registrar_datos();
			cout << "Apellido: "; cin >> this->apellido;
			cout << "Cedula: "; cin >> this->cedula;
			this->set_fecha_nacimiento();
		}

	PersonaNatural(): Cliente(){}
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
		
		void registrar_datos(){
			Cliente::registrar_datos();
			cout << "Rif: "; cin >> this->rif;
		}
		
	PersonaJuridica(): Cliente(){}
};

class ProductoCarrito {
	private:
		ProductoInventario producto;
		int cantidad;
	public:
		
		void set_producto(ProductoInventario nuevo_producto){
			this->producto = nuevo_producto;
		}
		
		void set_cantidad(int cantidad){
			this->cantidad = cantidad;
		}
		
		ProductoInventario get_producto(){
			return this->producto;
		}
		int get_cantidad_solicitada(){
			return this->cantidad;
		}
	
	ProductoCarrito(){}
	ProductoCarrito(ProductoInventario nuevo_producto, int cantidad){
		this->cantidad = cantidad;
		this->producto = nuevo_producto;
	}
};

class Pedido {
	private:
		ArrayCarritoCompra *carrito;
		Cliente cliente_pedido;
		int facturado;
		int num_pedido;
		Fecha fecha_pedido;
		Bodega *bodegon;
		
	public:
		int es_regalo;
		char direccion[30];
		
		ArrayCarritoCompra *get_carrito(){
			return this->carrito;
		}
		void set_carrito(ArrayCarritoCompra *carrito){
			this->carrito = carrito;
		}
		
		void set_direccion_envio(char *direccion){
			strcpy(this->direccion, direccion);
		}
		
		void set_cliente(Cliente cliente){
			this->cliente_pedido = cliente;
		}
		Cliente get_cliente(){
			return this->cliente_pedido;
		}
		
		void set_bodega(Bodega *bodega){
			this->bodegon = bodega;
		}
		Bodega *get_bodega(){
			return this->bodegon;
		}
		
		int get_num_pedido(){
			return this->num_pedido;
		}
		
		void set_facturado(int facturado){
			this->facturado = facturado;
		}
		int get_facturado(){
			return this->facturado;
		}
	
	Pedido(){
		this->facturado = 0;
		this->bodegon = new Bodega;
		this->num_pedido = rand();
	}
};

class Factura{
	private:
		int num_factura;
		Pedido pedido;
		Fecha fecha_factura;
	public:
		void set_pedido(Pedido pedido){
			this->pedido = pedido;
		}
		void generar_hora(){
			
		}
		char *get_fecha(){
			return (char*)"";
		}
	
	Factura(){
		this->num_factura = rand();
	}
	
};


void registrar_cliente_persona(ArrayClientesPersonas *array){

	PersonaNatural nuevo_cliente;
	nuevo_cliente.registrar_datos();
	array->push_back(nuevo_cliente);
}

void registrar_cliente_empresa(ArrayClientesEmpresas *array){
	
	PersonaJuridica nuevo_cliente;
	nuevo_cliente.registrar_datos();
	array->push_back(nuevo_cliente);

}

void imprimir_total_carrito(ArrayCarritoCompra *carrito){
	int precio_total_sin_iva = 0;
	ProductoCarrito elemento;
	
	cout << "====================================================================" << endl;
	for(ArrayCarritoCompra::iterator i = carrito->begin();i!=carrito->end(); i++){
		elemento = (*i);
		precio_total_sin_iva += (elemento.get_producto().cantidad_botellas*elemento.get_producto().producto_vino.get_precio());
		
		cout << elemento.get_producto().producto_vino.get_nombre()  << " | " ;
		cout << elemento.get_producto().producto_vino.get_precio() << " Bs | " ;
		cout << elemento.get_cantidad_solicitada() << " | ";
		cout << (elemento.get_producto().cantidad_botellas*elemento.get_producto().producto_vino.get_precio()) << " Bs" << endl;
	}
	cout << "Total de la compra sin iva: " << precio_total_sin_iva << " Bs" <<endl;
	cout << "====================================================================" << endl;
}

void proceso_compra(ArrayInventario *array_inventario, ArrayPedidos *array_pedidos, Cliente cliente_compra, Bodega *bodegon){
	
	

	int indice = 0, opcion_producto = -1, cantidad_solicitada = 0, tipo_tarjeta = 0;
	int es_regalo = 0;
	char tarjeta_credito[20], direccion_regalo[30];
	
	ArrayCarritoCompra *carrito = new ArrayCarritoCompra;
	Pedido nuevo_pedido;
	
	do{
		cout << "***********************************************************" << endl;
		cout << "Catalogo de vinos" << endl;
		
		indice = 0;
		for(ArrayInventario::iterator i = array_inventario->begin();i!=array_inventario->end(); i++){
			cout << "---------------- Numero de producto " << indice <<  "----------------" << endl;
			(*i).imprimir_datos();
			indice++;
		}
		
		imprimir_total_carrito(carrito);
		
		cout <<  "Selecciona el producto por el numero que esta en la parte de arriba de cada uno"  << endl;
		cout << "Para confimar su cuenta escriba -1" << endl;
		cin >> opcion_producto;
		
		if(opcion_producto != -1){
			
			if(opcion_producto > 0 && opcion_producto < array_inventario->size()){
				
				cout << "Ingrese la cantidad que requiere > "; cin >> cantidad_solicitada;
				
				if(cantidad_solicitada > array_inventario->at(opcion_producto).cantidad_disponible){
					cout << endl << "?????????????????????????????"<< endl;
					cout << "La cantidad solicitada excede a la existente" << endl;
					cout << "No hay disponibilidad para esta producto" << endl;
					cout << "?????????????????????????????"<< endl;
				}else{
					carrito->push_back( ProductoCarrito(array_inventario->at(opcion_producto),cantidad_solicitada) );
				}
			}else{
				cout << endl << "?????????????????????????????"<< endl;
				cout << "Numero de Producto incorrecto" << endl;
				cout << "?????????????????????????????"<< endl;
			}
		}
	} while(opcion_producto != -1);
	
	if(carrito->size() != 0){
		cout << "Porfavor Ingrese los datos de la tarjeta de credito" << endl;
		cin >> tarjeta_credito;
		cout << "1) MasterCard 2) Visa 3) AmericanExpress 4) Otros" << endl;
		cin >> tipo_tarjeta;
		
		cout << "Verificando datos con la entidad bancaria . . . . . . . .  OK." << endl << endl;
		
		cout << "La compra es un regalo? 1)SI 2)NO >"; cin >> es_regalo;
		if(es_regalo == 1){
			cout << "Introduzca la direccion de envio > "; cin >> direccion_regalo;
			nuevo_pedido.set_direccion_envio(direccion_regalo);
		}else{
			nuevo_pedido.set_direccion_envio(cliente_compra.get_direccion());
		}
		
		nuevo_pedido.es_regalo = es_regalo;
		nuevo_pedido.set_carrito(carrito);
		nuevo_pedido.set_cliente(cliente_compra);
		nuevo_pedido.set_bodega(bodegon);
		
		array_pedidos->push_back(nuevo_pedido);
		
		cout << "*********************************" << endl;
		cout << "Su pedido fue realizado con exito" << endl;
		cout << "*********************************" << endl;
	}
}

void proceso_compra_empresa(ArrayClientesEmpresas *array, ArrayInventario *array_inventario, ArrayPedidos *array_pedidos, Bodega *bodegon){
	char rif[15];
	int encontrado = 0;
	
	cout << "Ingrese el rif del cliente" << endl;
	cin >> rif;
	
	PersonaJuridica cliente_compra;
	
	for(ArrayClientesEmpresas::iterator i = array->begin();i!=array->end(); i++){
		if(strcmp((*i).get_rif(), rif) == 0){
			cliente_compra = *i;
			encontrado = 1;
			break;
		}
	}
	
	if(encontrado){
		proceso_compra(array_inventario, array_pedidos, cliente_compra, bodegon);
		
	}else{
		cout << endl << "?????????????????????????????"<< endl;
		cout << "No se ha encontrado ningun cliente con este rif, registrelo en la opcion 1 del menu" << endl;
		cout << "?????????????????????????????"<< endl;
	}
}

void proceso_compra_persona(ArrayClientesPersonas *array, ArrayInventario *array_inventario, ArrayPedidos *array_pedidos, Bodega *bodegon){
	char cedula[9];
	int encontrado = 0;
	
	cout << "Ingrese la cedula del cliente" << endl;
	cin >> cedula;
	
	PersonaNatural cliente_compra;
	
	for(ArrayClientesPersonas::iterator i = array->begin();i!=array->end(); i++){
		if(strcmp((*i).get_cedula(), cedula) == 0){
			cliente_compra = *i;
			encontrado = 1;
			break;
		}
	}
	
	if(encontrado){
		proceso_compra(array_inventario, array_pedidos, cliente_compra, bodegon);
		
	}else{
		cout << endl << "?????????????????????????????"<< endl;
		cout << "No se ha encontrado ningun cliente con esta cedula, registrelo en la opcion 1 del menu" << endl;
		cout << "?????????????????????????????"<< endl;
	}
}
int menu_tipo_cliente(){
	int resp;
	cout << "Seleccione el tipo de cliente" << endl;
	cout << "1) Persona Natural" << endl;
	cout << "2) Persona Juridica" << endl;
	cin >> resp;
	
	return resp;
}

void cargar_catalogo_inventario(ArrayInventario *array){
	ProductoInventario nuevo_producto;
	
	nuevo_producto.producto_vino.set_nombre((char*)"Santa teresa");
	nuevo_producto.producto_vino.set_categoria((char*)"Reserva");
	nuevo_producto.producto_vino.set_precio(12300);
	nuevo_producto.producto_vino.set_temperatura(1.12);
	nuevo_producto.producto_vino.set_formato((char*)"Medio litro");
	nuevo_producto.producto_vino.set_comentario((char*)"Ron añejo");
	nuevo_producto.cantidad_botellas = 1;
	nuevo_producto.tipo_producto = BOTELLA;
	nuevo_producto.cantidad_disponible = 10;
	array->push_back(nuevo_producto);
	
	nuevo_producto.producto_vino.set_nombre((char*)"Cacique");
	nuevo_producto.producto_vino.set_categoria((char*)"cosecha");
	nuevo_producto.producto_vino.set_precio(10000);
	nuevo_producto.producto_vino.set_temperatura(1.00);
	nuevo_producto.producto_vino.set_formato((char*)"5 litros");
	nuevo_producto.producto_vino.set_comentario((char*)"Ron añejo");
	nuevo_producto.cantidad_botellas = 6;
	nuevo_producto.tipo_producto = CAJA_BOTELLA;
	nuevo_producto.cantidad_disponible = 20;
	array->push_back(nuevo_producto);
	
	nuevo_producto.producto_vino.set_nombre((char*)"Ramón Bilbao Reserva");
	nuevo_producto.producto_vino.set_categoria((char*)"Reserva");
	nuevo_producto.producto_vino.set_precio(12300);
	nuevo_producto.producto_vino.set_temperatura(1.12);
	nuevo_producto.producto_vino.set_formato((char*)"Medio litro");
	nuevo_producto.producto_vino.set_comentario((char*)"De coleccion");
	nuevo_producto.cantidad_botellas = 1;
	nuevo_producto.tipo_producto = BOTELLA;	
	nuevo_producto.cantidad_disponible = 400;
	array->push_back(nuevo_producto);
	
	nuevo_producto.producto_vino.set_nombre((char*)"Marqués de Griñon Reserva");
	nuevo_producto.producto_vino.set_categoria((char*)"Reserva");
	nuevo_producto.producto_vino.set_precio(122300);
	nuevo_producto.producto_vino.set_temperatura(1.12);
	nuevo_producto.producto_vino.set_formato((char*)"media botella");
	nuevo_producto.producto_vino.set_comentario((char*)"vino tinto");
	nuevo_producto.cantidad_botellas = 4;
	nuevo_producto.tipo_producto = CAJA_BOTELLA;	
	nuevo_producto.cantidad_disponible = 130;
	array->push_back(nuevo_producto);
	
	nuevo_producto.producto_vino.set_nombre((char*)"Etchart Mendoza");
	nuevo_producto.producto_vino.set_categoria((char*)"Reserva");
	nuevo_producto.producto_vino.set_precio(11300);
	nuevo_producto.producto_vino.set_temperatura(1.11);
	nuevo_producto.producto_vino.set_formato((char*)"tres cuartos");
	nuevo_producto.producto_vino.set_comentario((char*)"de la cosecha");
	nuevo_producto.cantidad_botellas = 1;
	nuevo_producto.tipo_producto = BOTELLA;	
	nuevo_producto.cantidad_disponible = 100;
	array->push_back(nuevo_producto);
	
}

void cargar_datos_bodega(Bodega *nueva_bodega){
	nueva_bodega->set_nombre((char*)"Bodegón Hermanos Gouveia");
	nueva_bodega->set_direccion((char*)"Pto fijo estado falcon");
	nueva_bodega->set_correo((char*)"bodegon@gmail.com");
	nueva_bodega->set_telefono((char*)"123456789");
}

void mostrar_pedidos(ArrayPedidos *pedidos){
	int num_pedido = 0;
	for(ArrayPedidos::iterator i = pedidos->begin(); i!=pedidos->end(); i++){
		Pedido pedido = (*i);
		
		cout << "_______________-PEDIDO Nro " << num_pedido << " -_________________" << endl;
		cout << "Codigo Pedido: " << pedido.get_num_pedido() << endl;
		cout << "Bodegon: " << pedido.get_bodega()->get_nombre() << endl;
		cout << "Cliente: " << pedido.get_cliente().get_nombre() << endl;
		cout << "Direccion Envio: " << pedido.direccion << endl;
		cout << "Correo: " << pedido.get_cliente().get_correo() << endl;
		cout << "Es Regalo: " << ((pedido.es_regalo == 1)?("SI"):("NO")) << endl;
		cout << "Facturado: " << ((pedido.get_facturado() == 1)?("SI"):("NO")) << endl;
		imprimir_total_carrito(pedido.get_carrito());
		num_pedido++;
	}
}

void imprimir_factura(Pedido pedido){
	int precio_total_sin_iva = 0;
	ProductoCarrito elemento;
	ArrayCarritoCompra *carrito = pedido.get_carrito();
	Factura nueva_factura;
	
	cout << "====================================================================" << endl;
	cout << "Codigo Factura: " << nueva_factura.get_fecha() << endl;
	cout << "Bodegon: " << pedido.get_bodega()->get_nombre() << endl;
	cout << "Cliente: " << pedido.get_cliente().get_nombre() << endl;
	cout << "Direccion Envio: " << pedido.direccion << endl;
	cout << "Correo: " << pedido.get_cliente().get_correo() << endl;
	cout << "Es Regalo: " << ((pedido.es_regalo == 1)?("SI"):("NO")) << endl;
	
	for(ArrayCarritoCompra::iterator i = carrito->begin();i!=carrito->end(); i++){
		elemento = (*i);
		precio_total_sin_iva += (elemento.get_producto().cantidad_botellas*elemento.get_producto().producto_vino.get_precio());
		
		cout << elemento.get_producto().producto_vino.get_nombre()  << " | " ;
		cout << elemento.get_producto().producto_vino.get_precio() << " Bs | " ;
		cout << elemento.get_cantidad_solicitada() << " | ";
		cout << (elemento.get_producto().cantidad_botellas*elemento.get_producto().producto_vino.get_precio()) << " Bs" << endl;
	}
	cout << "Total de la compra sin iva: " << precio_total_sin_iva << " Bs" <<endl;
	cout << "Total de la compra (12%): " << precio_total_sin_iva*(1.12) << " Bs" <<endl;
	cout << "====================================================================" << endl;
}

void procesar_pedidos(ArrayPedidos *pedidos, ArrayFacturas *facturas){
	int num_pedido_facturar;
	mostrar_pedidos(pedidos);
	if(pedidos->size()){
		cout << "Seleccione el numero del pedido que desea facturar" << endl;
		cout << ">"; cin >> num_pedido_facturar;
		
		Pedido pedido_seleccionado = pedidos->at(num_pedido_facturar);
		pedido_seleccionado.set_facturado(1);
		pedidos->at(num_pedido_facturar) = pedido_seleccionado;
		
		imprimir_factura(pedido_seleccionado);
	}
}



int main(int argc, char *argv[]) {
	
	int exit = 0, opcion = 0, resp = 0;
	
	ArrayClientesPersonas *v_clientes_per = new ArrayClientesPersonas;
	ArrayClientesEmpresas *v_clientes_emp = new ArrayClientesEmpresas;
	ArrayInventario *v_inventario = new ArrayInventario;
	ArrayPedidos *v_pedidos = new ArrayPedidos;
	ArrayFacturas *v_facturas = new ArrayFacturas;
	Bodega * bodegon = new Bodega;
	
	cargar_catalogo_inventario(v_inventario);
	cargar_datos_bodega(bodegon);
	
	do{
		cout << "######################################################" << endl;
		cout << "############## Bodegón Hermanos Gouveia ##############" << endl;
		cout << "######################################################" << endl;
		cout << "1) Registro de clientes en el sistema" << endl;
		cout << "2) Compra de vino" << endl;
		cout << "3) Mostrar pedidos" << endl;
		cout << "4) Procesar Pedidos" << endl;
		cout << "5) Salir" << endl;
		cin >> opcion;
		
		switch(opcion){
			case 1:
				resp = menu_tipo_cliente();
				if(resp == CLIENTE_PERSONA){
					registrar_cliente_persona(v_clientes_per);
				}
				else if(resp == CLIENTE_EMPRESA){
					registrar_cliente_empresa(v_clientes_emp);
				}
				else{
					cout << "Tipo de cliente desconocido" << endl;
				}
				break;
			case 2:
				resp = menu_tipo_cliente();
				if(resp == CLIENTE_PERSONA){
					proceso_compra_persona(v_clientes_per, v_inventario, v_pedidos, bodegon);
				}
				else if(resp == CLIENTE_EMPRESA){
					proceso_compra_empresa(v_clientes_emp, v_inventario, v_pedidos, bodegon);
				}
				else{
					cout << "Tipo de cliente desconocido" << endl;
				}
				break;
			case 3:
				mostrar_pedidos(v_pedidos);
				break;
			case 4:
				procesar_pedidos(v_pedidos, v_facturas);
				break;
			case 5:
				exit = 1;
				break;
		}
	} while(!exit);
	return 0;
}

