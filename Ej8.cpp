#include <iostream>
#include "Lista/CircList.h"
#include <string>
#include <thread>
#include <chrono>
using namespace std;

int main()
{
    CircList<string> listadoPalabras;
    string palabralista, borrarpalabra;
    bool t = true;
    int deletef = 0;

    for (int i = 0; i < 3; i++)
    {
        cout << "Ingrese una palabra o frase: " << endl;
        getline(cin, palabralista, '\n');
        listadoPalabras.insertarUltimo(palabralista);
    }

    cout << "Ingrese 1 para eliminar una palabra" << endl;
    cin >> deletef;

    if (deletef == 1)
    {
        cout << "Ingrese la frase que desea eliminar" << endl;
        cin.ignore();
        getline(cin, borrarpalabra);
        listadoPalabras.eliminarPorValor(borrarpalabra);
    }

    while (t)
    {
        listadoPalabras.imprimir();
        cout << "" << endl;
        this_thread::sleep_for(chrono::seconds(3)); // Retraso de 3 segundo
    }
}
