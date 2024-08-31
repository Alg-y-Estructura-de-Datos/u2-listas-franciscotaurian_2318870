#include <iostream>
#include "Lista/CircList.h"

using namespace std;

class contacto
{
private:
    string name;
    string number;

public:
    contacto();
    void setname(string);
    void setnumber(string);
    string getname();
    string getnumber();
};

contacto::contacto()
{
}
void contacto::setname(string nombre)
{
    name = nombre;
}
void contacto::setnumber(string numerotel)
{
    number = numerotel;
}
string contacto::getname()
{
    return name;
}
string contacto::getnumber()
{
    return number;
}

void menu()
{
    cout << "***MENU***" << endl;
    cout << "1-Agregar contacto" << endl;
    cout << "2-Eliminar contacto" << endl;
    cout << "3-Listar contactos" << endl;
    cout << "4 Buscar contacto" << endl;
    cout << "5-Cantidad de contactos" << endl;
    cout << "6-Salir" << endl;
}

void agregarcontacto(CircList<contacto> &contactos)
{
    contacto nuevo;
    string nombre, numero;
    cout << "Ingrese el nombre del contacto" << endl;
    cin >> nombre;
    cout << "Ingrese el numero del contacto" << endl;
    cin >> numero;
    nuevo.setname(nombre);
    nuevo.setnumber(numero);
    contactos.insertarUltimo(nuevo);
    cout << "Contacto agregado" << endl;
}

void eliminarcontacto(CircList<contacto> &contactos)
{
    string nombre;
    cout << "Ingrese el nombre del contacto que desea eliminar" << endl;
    cin >> nombre;
    for (int i = 0; i < contactos.getTamanio(); i++)
    {
        if (nombre == contactos.getDato(i).getname())
        {
            contacto c=contactos.getDato(i);
            contactos.eliminarPorValor(c);
            cout << "Contacto eliminado" << endl;
        }
    }
}
void listarContacto(CircList<contacto> &contactos)
{
    cout << "***Contactos***" << endl;
    for (int i = 0; i < contactos.getTamanio(); i++)
    {
        cout<<"Nombre: "<<contactos.getDato(i).getname()<<endl;
        cout<<"Numero: "<<contactos.getDato(i).getnumber()<<endl;
        cout<<" "<<endl;
    }
    
}

void buscarContacto(CircList<contacto> &contactos)
{
    string nombre;
    for (int i = 0; i < contactos.getTamanio(); i++)
    {
        if (nombre == contactos.getDato(i).getname())
        {
            cout << "Nombre: " << contactos.getDato(i).getname() << endl;
            cout << "Numero: " << contactos.getDato(i).getnumber() << endl;
        }
    }
}
void cantidadContactos(CircList<contacto> &contactos)
{
    cout << "La cantidad de contactos es: " << contactos.getTamanio() << endl;
}

int main()
{
    CircList<contacto> contactos;
    int option;

    do
    {
        cout << "Ingrese una opcion" << endl;
        menu();
        switch (option)
        {
        case 1:
            agregarcontacto(contactos);
            break;
        case 2:
            eliminarcontacto(contactos);
            break;
        case 3:
            listarContacto(contactos);
            break;
        case 4:
            buscarContacto(contactos);
            break;
        case 5:
            cantidadContactos(contactos);
            break;
        case 6:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opcion invalida" << endl;
            break;
        }
    } while (option != 6);
}