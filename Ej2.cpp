#include <iostream>
#include "Lista/Lista.h"
using namespace std;

/*
Implementar una función que recibe una lista de números enteros y un número entero “n” y
que modifique la lista borrando todos los elementos de la lista que tengan el número “n”.
Imprimir la lista antes de hacer el llamado a la función y luego del llamado a la función para
mostrar que la lista original cambió. ej: lista: 1->2->3->4->5->3->7->8->3->10 con n=3 debe
pasar con la función a 1->2->4->5->7->8.
*/

void eliminarnumeros(Lista<int>&l1, int n){

    int tamanio=l1.getTamanio();
    for (int i = 0; i < tamanio; i++)
    {
        if (n==l1.getDato(i))
        {
            l1.remover(i);
            tamanio--;//recordar que al eliminar se achica el tamano de la lista;
            i--;
        }
        
    }
    

}


int main() {

    cout << "Ejercicio N° 2" << endl;

    Lista<int> Lista1;

    int t,d,n1;

    cout<<"Ingrese el tamanio que tendra su lista"<<endl;
    cin>>t;

    for (int i = 0; i < t; i++)
    {
        cout<<"Ingrese el numero a almacenar en la posicion: "<<i<<endl;
        cin>>d;
        Lista1.insertarUltimo(d);
    }

    cout<<"Ingrese el numero que desea borrar."<<endl;
    cin>>n1;
    
    cout<<"Lista original"<<endl;

    Lista1.print();

    eliminarnumeros(Lista1,n1);

    cout<<"Nueva lista"<<endl;
    Lista1.print();
    
    return 0;
}
