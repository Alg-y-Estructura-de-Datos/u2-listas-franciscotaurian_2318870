#include <iostream>
#include "Lista/Lista.h"
#include <string>
using namespace std;

/*
Escribir un programa que pida al usuario una palabra o frase y la almacene en una Lista
separando letra por letra, luego pedirá al usuario una vocal que desee contar y, por último, se
debe imprimir por pantalla la lista y el número de veces que aparece la vocal en la palabra o
frase. Validar que la Lista no esté vacía y que la letra a contar que introduzca el usuario sea
una vocal.
*/

int contarVocal(Lista<char> &Lista1, char voca)
{

    int contador = 0;
    for (int i = 0; i < Lista1.getTamanio(); i++)
    {
        if (Lista1.getDato(i) == voca)
        {
            contador++;
        }
    }
    return contador;
}

int main()
{

    cout << "Ejercicio N° 4" << endl;
    string palabra;
    char vocal, minuscula,palabraminuscula;
    bool vocalentrada = true;
    int size;
    cout << "Ingrese una palabra" << endl;
    getline(cin, palabra);

    size = palabra.size();
    Lista<char> lista;
    for (int i = 0; i < size; i++)
    {
        palabraminuscula = tolower(palabra[i]);
        lista.insertarUltimo(palabraminuscula);
    }
    do
    {
        cout << "Ingrese la vocal que desea buscar" << endl;
        cin >> vocal;

        minuscula = tolower(vocal);
        if (minuscula == 'a' || minuscula == 'e' || minuscula == 'i' || minuscula == 'o' || minuscula == 'u')
        {
            cout << "La cantidad de veces que aparece la vocal: " << vocal <<". En la palabra: "<<palabra<<". Es: " << contarVocal(lista, minuscula) << endl;

            vocalentrada = true;
        }
        else
        {
            cout << "Ingrese una vocal" << endl;
            vocalentrada = false;
        }
    } while (vocalentrada == false);
}
