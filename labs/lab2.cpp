#include <iostream>

using namespace::std;

struct nodo{
	int dato;
	nodo* siguiente;
	nodo* atras;
} *primero, *ultimo;

void insertarNodo();
void buscarNodo();
void modificarNodo();
void eliminarNodo();
void PrimeroUltimo();
void UltimoPrimero();

int main(){

	int opcion_menu=0;
	do
	{
	
		cout << "\n| 1. Insertar";
		cout << "\n| 2. Buscar";
		cout << "\n| 3. Modificar";
		cout << "\n| 4. Eliminar";
		cout << "\n| 5. Mostrar primero al ultimo ** ";
		cout << "\n| 6. Mostrar del ultimo al primero** ";
		cout << "\n| 7. Salir        				 |";
		cout << "\n|------------------|------------------|";
		cout << "\n\n Escoja una Opcion: ";
		cin >> opcion_menu;
		
		switch(opcion_menu){
		case 1:
			
			insertarNodo();
			break;
		case 2:
			
			buscarNodo();
			break;
		case 3:
		
			modificarNodo();
			break;
		case 4:
			
			eliminarNodo();
			break;
		case 5: 
            PrimeroUltimo();
			
			break;
		case 6:
            UltimoPrimero();
			break;
		case 7:
			cout << "\n\n Programa finalizado...";
			break;
		default:
			cout << "\n\n Opcion No Valida \n\n";
		}
	} while (opcion_menu != 7);	
	return 0;
}

void insertarNodo(){
	nodo* nuevo = new nodo();
	cout << " Ingrese el dato que contendra el nuevo Nodo: ";
	cin >> nuevo->dato;
	
	if(primero==NULL){
		primero = nuevo;
		primero->siguiente = NULL;
		primero->atras = NULL;
		ultimo = primero;
	}else{
		ultimo->siguiente = nuevo;
		nuevo->siguiente = NULL;
		nuevo->atras = ultimo;
		ultimo = nuevo;
	}
	cout << "\n Nodo Ingresado\n\n";
}

void buscarNodo(){
	nodo* actual = new nodo();
	actual = primero;
	bool encontrado = false;
	int nodoBuscado = 0;
	cout << " Ingrese el dato del Nodo a Buscar: ";
	cin >> nodoBuscado;
	if(primero!=NULL){
		
		while(actual!=NULL && encontrado!=true){
			
			if(actual->dato == nodoBuscado){
				cout << "\n Nodo con el dato ( " << nodoBuscado << " ) Encontrado\n\n";
				encontrado = true;
			}
			
			actual = actual->siguiente;
		}
		
		if(!encontrado){
			cout << "\n Nodo no Encontrado\n\n";
		}
		
	}else{
		cout << "\n La listas se encuentra Vacia\n\n";
	}
}

void modificarNodo(){
	nodo* actual = new nodo();
	actual = primero;
	bool encontrado = false;
	int nodoBuscado = 0;
	cout << " Ingrese el dato del Nodo a Buscar para Modificar: ";
	cin >> nodoBuscado;
	if(primero!=NULL){
		
		while(actual!=NULL && encontrado!=true){
			
			if(actual->dato == nodoBuscado){
				cout << "\n Nodo con el dato ( " << nodoBuscado << " ) Encontrado";
				cout << "\n Ingrese el nuevo dato para este Nodo: ";
				cin >> actual->dato;
				cout << " Nodo Modificado\n\n";
				encontrado = true;
			}
			
			actual = actual->siguiente;
		}
		
		if(!encontrado){
			cout << "\n Nodo no Encontrado\n\n";
		}
		
	}else{
		cout << "\n La listas se encuentra Vacia\n\n";
	}
}

void eliminarNodo(){
	nodo* actual = new nodo();
	actual = primero;
	nodo* anterior = new nodo();
	anterior = NULL;
	bool encontrado = false;
	int nodoBuscado = 0;
	cout << " Ingrese el dato del Nodo a Buscar para Eliminar: ";
	cin >> nodoBuscado;
	if(primero!=NULL){
		
		while(actual!=NULL && encontrado!=true){
			
			if(actual->dato == nodoBuscado){
				cout << "\n Nodo con el dato ( " << nodoBuscado << " ) Encontrado";
				
				if(actual==primero){
					primero = primero->siguiente;
					primero->atras = NULL;
				}else if(actual==ultimo){
					anterior->siguiente = NULL;
					ultimo = anterior;
				}else{
					anterior->siguiente = actual->siguiente;
					actual->siguiente->atras = anterior;
				}
				
				cout << "\n Nodo Eliminado";
				encontrado = true;
			}
			anterior = actual;
			actual = actual->siguiente;
		}
		
		if(!encontrado){
			cout << "\n Nodo no Encontrado\n\n";
		}
		
	}else{
		cout << "\n La listas se encuentra Vacia\n\n";
	}
}

void PrimeroUltimo(){
    nodo *actual = new nodo();
    actual = primero;

    if (primero == NULL){
        cout << "La lista se encentra vacia\n";
    }else{
        while (actual!=NULL){
            cout  <<"->" << actual->dato << endl; 
            actual = actual->siguiente;
        }
    }
}

void UltimoPrimero(){
    nodo *actual = new nodo();
    actual = ultimo;

    if (ultimo == NULL){
        cout << "La lista se encentra vacia\n";
    }else{
        while (actual!=NULL){
            cout  <<"->" << actual->dato << endl; 
            actual = actual->atras;
        }
    }
}


