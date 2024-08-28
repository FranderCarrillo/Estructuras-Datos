#include<iostream>

using namespace std;

// estructura del nodo
struct Nodo{
	int dato;
	Nodo *siguiente;
};
//variables
Nodo *lista=NULL;
//métodos
void menu();
void insertarLista(Nodo *&, int);
void mostrarLista(Nodo *);

//principal
int main(){
	
	menu();
	
	
	
}//principal
///////menu////////////////////
void menu(){
	int opcion, dato;
	do{
		cout<<"\t ...MENU... \n";
		cout<<"1. Insertar elementos en la lista\n";
		cout<<"2. Mostrar los elementos en la lista\n";
		cout<<"3. Buscar un elementos en la lista\n";
		cout<<"4. Eliminar un elementos en la lista\n";
		cout<<"5. Salir\n";
		cout<<"Opcion: \n";
		cin>>opcion;
		system("cls");//para limpiar la pantalla usa libreria stdlib.h
		
		switch(opcion){
		case 1:	cout<<"Digite un numero a insertar: ";
		cin>>dato;
		insertarLista(lista, dato);
		system("pause");
		break;
		case 2:	mostrarLista(lista);
		system("pause");
		break;
		case 3: cout<<"Digite un numero a buscar";
		cin>>dato;
		//buscarLista(lista, dato);	
		system("pause");
		break;
		
		case 4:
			cout<<"Digite un numero a eliminar";
			cin>>dato;
			//eliminarElemento(lista, dato);	
			system("pause");
			break;
		case 5:
			break;
			
		}
		
	}while(opcion!=5);
}
///////fin de menu//////////

////////insertar/////////
	void insertarLista(Nodo *&lista,int d){
		Nodo *nuevoNodo = new Nodo();
		nuevoNodo->dato=d;
		
		Nodo *aux1=lista;
		Nodo *aux2;//para poner ordenado
		
		while((aux1!=NULL)&&(aux1->dato < d)){
			aux2=aux1;
			aux1=aux1->siguiente;
		}
		
		if(lista==aux1){
			lista=nuevoNodo;
		}
		else{
			aux2->siguiente=nuevoNodo;
		}
		nuevoNodo->siguiente=aux1;
		
	
	
	
}//fin de metodo insertar
		
////////mostrar/////
void mostrarLista(Nodo *lista){
	Nodo *actual =new Nodo();
	actual=lista;
	
	while(actual!=NULL){
		cout<<actual->dato<<" -> ";
		actual=actual->siguiente;
	}
	
	
}