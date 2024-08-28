#include "iostream"
#include "stdio.h"

using namespace std;

int funcion(int valor)
{
    valor = valor + 10; //Se le suma 10
    return valor;
}

int funcionPunteros(int *valor)
{
    *valor = *valor + 10; //Se le suma 10 a la posición en memoria
    return *valor;
}

int main()
{
    int numero = 10;

    cout << "Antes de funcion " << numero << "\n"; //10

    funcion(numero); //Se pasa por valor

    cout << "Despues de funcion " << numero << "\n"; //10

    cout << "Antes de funcionPunteros " << numero << "\n"; //10

    funcionPunteros(&numero); //Se envía la dirección de memoria y la función resuelve la referencia

    cout << "Despues de funcionPunteros " << numero << "\n"; //20 (10+10)

    system("pause");

    return 0;
}