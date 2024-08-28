#include <iostream>
using namespace std;

struct nodo 
{
    int dato;
    nodo *siguiente;
    nodo *atras;
}*primero, *ultimo;

void insertarNodo(){
    nodo *nuevo = new nodo();

    cout << "Ingrese el dato que contendra el nuevo Nodo: ";
    nuevo->dato = 10;

    if (primero == NULL){
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
    cout << "\nNodo Ingresado...\n";
}

int main() 
{
    insertarNodo();
}