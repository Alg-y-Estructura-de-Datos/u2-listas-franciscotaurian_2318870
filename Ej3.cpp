#include <iostream>
#include "Lista/Lista.h"
using namespace std;

/*
Implementar una función que intercambie los elementos entre 2 listas de números enteros
que recibe como parámetros. Si los tamaños de las listas son distintos, igual debe cambiar los
datos y cambiarían los tamaños de cada lista. Ejemplo sea lista1= 15->1->8->35->40->25->12 y
lista2= 3->4->912->45->66 al ejecutar la función quedarían lista1= 3->4->912->45->66 y
lista2=15->1->8->35->40->25->12.
*/

void intercambiar(Lista<int> &l1, Lista<int> &l2)
{

    Lista<int> aux1, aux2;

    for (int i = 0; i < l1.getTamanio(); i++)
    {
        aux1.insertarUltimo(l1.getDato(i));
    }

    for (int i = 0; i < l2.getTamanio(); i++)
    {
        aux2.insertarUltimo(l2.getDato(i));
    }

    l1.vaciar();
    l2.vaciar();

    for (int i = 0; i < aux1.getTamanio(); i++)
    {
        l2.insertarUltimo(aux1.getDato(i));
    }

    for (int i = 0; i < aux2.getTamanio(); i++)
    {
        l1.insertarUltimo(aux2.getDato(i));
    }
}

int main()
{

    cout << "Ejercicio N° 3" << endl;
    Lista<int> Lista1, Lista2;

    int t1, t2, d;

    cout << "Ingrese el tamanio que tendra su lista 1" << endl;
    cin >> t1;

    for (int i = 0; i < t1; i++)
    {
        cout << "Ingrese el numero a almacenar en la posicion: " << i << endl;
        cin >> d;
        Lista1.insertarUltimo(d);
    }

    cout << "Ingrese el tamanio que tendra su lista 2" << endl;
    cin >> t2;

    for (int i = 0; i < t2; i++)
    {
        cout << "Ingrese el numero a almacenar en la posicion: " << i << endl;
        cin >> d;
        Lista2.insertarUltimo(d);
    }

    cout << "Lista 1: " << endl;
    Lista1.print();
    cout << "Lista 2: " << endl;
    Lista2.print();

    intercambiar(Lista1, Lista2);

    cout << "Lista 1: " << endl;
    Lista1.print();
    cout << "Lista 2: " << endl;
    Lista2.print();

    return 0;
}
