#include <iostream>
#include "Lista/Lista.h"
using namespace std;

void nrepetidos(Lista<int> &nums)
{
    int num, contador = 0;
    Lista<int> repetidos;
    for (int i = 0; i < nums.getTamanio(); i++)
    {
        bool band = true;
        num = nums.getDato(i);
        contador = 0;
        for (int j = 0; j < nums.getTamanio(); j++)
        {
            if (num == nums.getDato(j))
            {
                contador++;
            }
        }
        if (contador > 1)
        {
            if (repetidos.esVacia())
            {
                repetidos.insertarUltimo(num);
            }
            else
            {
                for (int h = 0; h < repetidos.getTamanio(); h++)
                {
                    if (num == repetidos.getDato(h))
                    {
                        band = false;
                    }
                }
                if (band == true)
                {
                    repetidos.insertarUltimo(num);
                }
            }
        }
    }
    if (repetidos.esVacia())
    {
        cout << "No hay numeros repetidos" << endl;
    }
    else
    {
        cout << "Los numeros repetidos son: " << endl;
        repetidos.print();
    }
}

int main()
{
    int num1, cant;
    Lista<int> numeros1;

    cout << "Ingrese la cantidad de numero  que quiere agregar" << endl;
    cin >> cant;

    for (int i = 0; i < cant; i++)
    {
        cout << "Ingrese los numeros" << endl;
        cin >> num1;
        numeros1.insertarUltimo(num1);
    }
    nrepetidos(numeros1);
}