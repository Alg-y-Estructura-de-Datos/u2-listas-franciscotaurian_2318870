#include <iostream>
#include "Lista/ListaDoble.h"
using namespace std;

void menu()
{
    cout << "***MENU***" << endl;
    cout << "1-Mostrar Historial." << endl;
    cout << "2-Añadir." << endl;
    cout << "3-Avanzar" << endl;
    cout << "4-Retroceder" << endl;
    cout << "5-Salir" << endl;
}

void aniadirpag(ListaDoble<string> &url, int &mov)
{
    string urls;
    cout << "Ingrese el url de la pagina visitada" << endl;
    cin.ignore();
    getline(cin, urls);

    url.insertarUltimo(urls);
    mov = url.getTamanio() - 1;
}

void mostrarHistorico(ListaDoble<string> &url)
{
    cout << "**HISTORIAL**" << endl;
    url.imprimir();
}

int main()
{
    ListaDoble<string> url;
    int mover = 0, option;

    if (url.esVacia())
    {
        aniadirpag(url, mover);
        cout << "Estas en la pagina: " << url.getDato(mover) << endl;
    }

    do
    {
        menu();
        cout << "Ingrese una opcion" << endl;
        cin >> option;

        switch (option)
        {
        case 1:
            mostrarHistorico(url);
            break;
        case 2:
            aniadirpag(url, mover);
            break;
        case 3:
            if (mover == url.getTamanio() - 1)
            {
                cout << "Fin del historial" << endl;
            }
            else
            {
                mover++;
            }

            break;
        case 4:
            if (mover == 0)
            {
                cout << "Fin del historial" << endl;
            }
            else
            {
                mover--;
            }
            break;
        case 5:
            cout << "Saliendo..." << endl;
            break;

        default:
            cout << "Opcion no valida" << endl;
            break;
        }

        cout << "Estas en la pagina: " << url.getDato(mover) << endl;
    } while (option != 5);

    return 0;
}