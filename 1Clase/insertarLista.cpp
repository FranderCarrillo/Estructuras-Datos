#include <iostream>
using namespace std;  

// estructura del nodo
struct Nodo{
    int dato;
    Nodo *siguiente;
};

// variables 

Nodo *lista=NULL; // se declara la lista nula

//Funciones
void insertarLista (Nodo *&lista, int d){
    Nodo *nuevoNodo = new Nodo();
    Nodo *auxiliar = lista; // sirve para recorrer la lista 

    nuevoNodo->siguiente = NULL; // el ultimo dato siempre es nulo
    nuevoNodo->dato=d; // nuevo nodo

    if (lista==NULL){  // se verifica que la lista esta vacia 
        lista=nuevoNodo;
    }
    else{ // en caso que la lista no este vacia y se utiliza el auxiliar 
        while (auxiliar->siguiente!=NULL)
        {
            auxiliar = auxiliar->siguiente;
        }
        auxiliar->siguiente = nuevoNodo;
    }
}

void mostrarLista(Nodo *lista){
    Nodo *actual = new Nodo();
    actual = lista;

    while (actual!=NULL){
        cout <<actual->dato << "->";
        actual=actual->siguiente;
    }
    
} // final mostrar lista 

void BuscarLista(Nodo *lista, int valor){
    Nodo *buscar = new Nodo();
    buscar = lista;

    while (buscar!=NULL){
        if (buscar->dato == valor){
            cout <<endl << valor << " Existe...\n";
            return;
        }else{
            cout << endl << valor << "No existe...\n";
            return;
        }
    }
}

void BorrarValor(Nodo *&lista, int valor) {

    Nodo *actual = lista;
    Nodo *anterior = NULL;

    if (lista == NULL)
    {
        cout << "No hay datos para eliminar...\n";
        return;
    }

    if (actual->dato == valor) 
    {
        lista = actual->siguiente;
        delete actual; 
        return;
    }


    while (actual != NULL && actual->dato != valor)
    {
        anterior = actual;
        actual = actual->siguiente;
    }


    if (actual == NULL)
    {
        cout << "Valor no encontrado en la lista...\n";
        return;
    }

    anterior->siguiente = actual->siguiente;
    delete actual; 
}




int main () 
{
    insertarLista(lista,5);
    insertarLista(lista,9);
    insertarLista(lista,3);

    mostrarLista(lista);
    BuscarLista(lista, 5);
    BorrarValor(lista, 5);
    mostrarLista(lista);
    return 0;
}