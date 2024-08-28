#include <iostream>
using namespace std;

struct Nodo {
	int dato;
	Nodo* siguiente;
};

Nodo* Pila = NULL;
Nodo* Cola = NULL;
Nodo* ultimo = NULL;

void insertarPila();
void insertarCola();
void menuInsertar();
void eliminarCola(Nodo*&);
void menu();

void MostarPila() {
	Nodo* pilita = new Nodo();
	if (Pila == NULL){
		cout << "No hay datos en la Pila...\n";
	}else{
	pilita = Pila;
	cout << "Numero : " << Pila->dato;
	}

}

void MostraCola() {
	Nodo* colita = new Nodo();
	colita = Cola;
	if (Cola == NULL) {
		cout << "No hay datos en la cola...\n";
	}
	else {
		cout << "Numero : " << colita->dato;
	}
}

int main() {
	menu();
}

void insertarPila() {
	Nodo* pilita = new Nodo();
	cout << " Ingrese el dato que contendra el nuevo Nodo: ";
	cin >> pilita->dato;
	pilita->siguiente = NULL;

	if (Pila == NULL) {
		Pila = pilita;
	}
	else {
		pilita->siguiente = Pila;
		Pila = pilita;
	}
	cout << "\n Nodo ingresado corractamente\n\n";
	system("pause");
}

void insertarCola() {
	Nodo* colita = new Nodo();
	cout << " Ingrese el dato que contendra el nuevo Nodo: ";
	cin >> colita->dato;
	colita->siguiente = NULL;

	if (Cola == NULL) {
		Cola = colita;
		ultimo = Cola;
	}
	else {
		ultimo->siguiente = colita;
		ultimo = colita;
	}
	cout << "\n Nodo ingresado corractamente\n\n";
	system("pause");
}

void eliminarCola(Nodo*& cola) {
	if (Cola == NULL) {
		cout << "No hay valoes en cola...\n";
	}
	else {

		Nodo* eliminar = cola;
		cola = cola->siguiente;
		delete eliminar;
	}
}

void eliminarPila(Nodo*& pila) {
	if (Pila == NULL) {
		cout << "No hay valoes en cola...\n";
	}
	else {

		Nodo* eliminar = pila;
		pila = pila->siguiente;
		delete eliminar;
	}
}

void vaciarPila()
{
	if (Pila != NULL) {
		while (Pila != NULL)
		{
			eliminarPila(Pila);
		}
	}
	else {
		cout << "Se encuentra vacío" << endl;
	}
}
void vaciarCola()
{
	if (Cola != NULL)
	{
		while (Cola != NULL)
		{
			eliminarCola(Cola);

		}
	}
	else {
		cout << "Se encuentra vacío" << endl;
	}
}


void menu() {

	int opcion_menu = 0;
	do {
		system("cls");
		cout << "\n 1. para Pilas";
		cout << "\n 2. para Colas";
		cout << "\n 3. Salir";
		cout << "\n|------------------|------------------|";
		cout << "\n\n Escoja una Opcion: ";
		cin >> opcion_menu;

		switch (opcion_menu)
		{
		case 1: {
			int opcion_menu2;
			do {
				system("cls");
				cout << "\n 1. para ingresar";
				cout << "\n 2. para mostar";
				cout << "\n 3. para eliminar";
				cout << "\n 4. para vaciar";
				cout << "\n 5. Salir";
				cout << "\n|------------------|------------------|";
				cout << "\n\n Escoja una Opcion: ";
				cin >> opcion_menu2;

				switch (opcion_menu2)
				{
				case 1: {
					insertarPila();
					system("pause");
					break;
				}
				case 2: {
					MostarPila();
					system("pause");
					break;
				}

				case 3: {
					eliminarPila (Pila);
				break;}

				case 4:{
					vaciarPila();
				break;}

				case 5: {
					cout << "Saliendo" << endl;
					system("pause");
					break;
				}
				default: {
					cout << "Ingrese una opcion valida" << endl;
					system("pause");
					break;
				}
				}
			} while (opcion_menu2 != 5);

		}
		case 2: {
			int opcion_menu3;
			do {
				system("cls");
				cout << "\n 1. para ingresar";
				cout << "\n 2. para mostar";
				cout << "\n 3. para eliminar";
				cout << "\n 4. para vaciar";
				cout << "\n 5. Salir";
				cout << "\n|------------------|------------------|";
				cout << "\n\n Escoja una Opcion: ";
				cin >> opcion_menu3;

				switch (opcion_menu3)
				{
				case 1: {
					insertarCola();
					system("pause");
					break;
				}
				case 2: {
					MostraCola();
					system("pause");
					break;
				}
				case 3: {
					eliminarCola(Cola);
					system("pause");
					break;
				}	

				case 4:{
					vaciarCola();
				break;}

				case 5: {
					cout << "Saliendo" << endl;
					system("pause");
					break;
				}
				default: {
					cout << "Ingrese una opcion valida" << endl;
					system("pause");
					break;
				}
				}
			} while (opcion_menu3 != 5);
		}
		default: {
			cout << "Ingrese una opcion valida" << endl;
			system("pause");
			break;
		}
		}
	} while (opcion_menu != 3);
}