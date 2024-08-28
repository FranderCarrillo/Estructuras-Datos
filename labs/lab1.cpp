#include <iostream>
#include <stdlib.h>
using namespace std;

struct nodo{
    int dato;
    nodo *siguiente;
}; // la estructura de los nodos 


int conteo = 1; // variabele de conteo para ingresar datos automaticos 
nodo *lista = NULL; // lista vacia 

void insertarList(nodo *&lista, int valor){
    nodo *nuevo = new nodo();
    nuevo->dato = valor;
    nuevo->siguiente = lista;
    lista=nuevo;

    cout << "\n Valor '  "<< nuevo->dato << "  ' ingresado con exito al inicio de la lista..\n\n";
}

void mostarLista(nodo *lista){
    nodo *actual = lista;
    
    if (actual == NULL){
        cout << "no hay datos para mostrar...\n";
    }else{
    while (actual!=NULL)
    {
        cout << "| " << actual->dato << "| <-";
        actual = actual->siguiente;
    }
    }
}
void eliminarValor(nodo *&lista)
{
    if (lista == NULL)
    {
        cout << "no hay datos..." << endl;
    }else{
    nodo *eliminar = lista;
    lista = lista->siguiente;
    delete eliminar;
    conteo--;
    cout << "El dato " << conteo << " ha sido eliminado con exito...\b";
    }
}

int numeroPares (nodo *lista){
    int sumar = 0;
    nodo *pares = lista;

    if (lista == NULL){
        cout << "no hay datos...\n";
    }else{
        while (pares != NULL){
            if (pares->dato % 2 == 0){
                sumar++;
            }
            pares = pares->siguiente;
        }
    }
    return sumar;
}

bool esPrimo(int valor)
{
    if (valor <= 1) return false;
    for (int i = 2; i < valor; i++)
    {
        if (valor % i == 0) return false;
    }
    return true;
}

int contarPrimos(nodo *lista)
{
    if (lista == NULL)
    {
        cout << "No hay datos...\n";
    }else {
    int sumar = 0;
    nodo *primos = lista;
    while (primos != NULL)
    {
        if (esPrimo(primos->dato))
        {
            sumar++;
        }
        primos = primos->siguiente;
    }
    return sumar;
    }
}

double calcularPromedio(nodo *lista)
{
    if (lista== NULL){
        cout << "No hay datos...\n";
    }else{
    int sumar = 0;
    int cant = 0;
    nodo *promedio = lista;
    while (promedio != NULL)
    {
        sumar += promedio->dato;
        cant++;
        promedio = promedio->siguiente;
    }
    if (cant == 0){return 0; }
    else{
        return (double)sumar / cant;
    }
    }
}

int main()
{
    setlocale(LC_CTYPE, "spanish");
    int menu;
    do
    {
        system("cls");
        cout << "\nMENU" << endl;
        cout << "1) ingresar elemento al inicio  " << endl;
        cout << "2) mostrar lista                " << endl;
        cout << "3) Eliminar valor final   " << endl;
        cout << "4) Contar valores pares      " << endl;
        cout << "5) Contar valores primos      " << endl;
        cout << "6) Calcular promedio de los valores     " << endl;
        cout << "0) Salir " << endl;
        cout << "Ingrese una opcion: ";
        cin >> menu;

        switch (menu)
        {
        case 1:{
            system("cls");
            insertarList(lista, conteo++);
            system("pause");
            break;}

        case 2:{
            system("cls");
            cout << "Lista:";
            mostarLista(lista);
            system("pause");
            break;}

        case 3:{
            system("cls");
            eliminarValor(lista);
            system("pause");
            break;}

        case 4:{
            system("cls");
            cout << "Valores pares -> " << numeroPares(lista) << "\n";
            system("pause");
            break;}

        case 5:{
            system("cls");
            cout << "Valores primos -> " << contarPrimos(lista) << "\n";
            system("pause");
            break;}

        case 6:{
            system("cls");
            cout << "Promedio -> " << calcularPromedio(lista) << "\n";
            system("pause");
            break;}

        case 0:{
            cout << "saliste...\n" << "\n";
            break;}

        default:{
            cout << "Opcion invalida...\n";
            break;}

    } 
    }while (menu != 0);
}




// insetar automatico
// mostar
// mostrar pares
// mostrar primos
// calcular promedio
