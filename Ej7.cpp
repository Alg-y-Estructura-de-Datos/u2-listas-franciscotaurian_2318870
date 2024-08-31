#include <iostream>
#include "Lista/ListaDoble.h"
#include <string>
using namespace std;

class estudiante
{
private:
    string nombre;
    int edad;
public:
    estudiante();
    void setnombre(string);
    void setedad(int);
    string getnombre();
    int getedad();
};

estudiante::estudiante()
{
}
void estudiante::setnombre(string _nombre)
{
    nombre = _nombre;
}
void estudiante::setedad(int _edad)
{
    edad = _edad;
}
string estudiante::getnombre()
{
    return nombre;
}
int estudiante::getedad()
{
    return edad;
}

void menu()
{
    cout << "***MENU***" << endl;
    cout << "1-Agregar estudiante" << endl;
    cout << "2-Eliminar estudiante" << endl;
    cout << "3-Listar estudiantes" << endl;
    cout << "4 Buscar estudiante" << endl;
    cout << "5-Cantidad de estudiantes" << endl;
    cout << "6-Salir" << endl;
}

void agregarestudiante(ListaDoble<estudiante> &estudiantes)
{
    estudiante nuevo;
    string nombre; 
    int edad;
    cout << "Ingrese el nombre del estudiante" << endl;
    cin.ignore();
    getline(cin,nombre);
    cout << "Ingrese la edad del estudiante" << endl;
    cin >> edad;
    nuevo.setnombre(nombre);
    nuevo.setedad(edad);
    estudiantes.insertarUltimo(nuevo);
}

void eliminarEstudiante(ListaDoble<estudiante> &estudiantes){
    string name;
    cout<<"Ingrese el nombre del estudiante que desea eliminar"<<endl;
    cin.ignore();
    getline(cin,name);

    for (int i = 0; i < estudiantes.getTamanio(); i++)
    {
        if (name==estudiantes.getDato(i).getnombre())
        {
            estudiantes.remover(i);
            cout<<"Estudiante eliminado"<<endl;
        }
        else
        {
            cout<<"No se encontro al estudiante"<<endl;
        }
        
        
    }
    
}
void listarEstudiantes(ListaDoble<estudiante> &estudiantes){
    for (int i = 0; i < estudiantes.getTamanio(); i++)
    {
        cout<<"Nombre: "<<estudiantes.getDato(i).getnombre()<<endl;
        cout<<"Edad: "<<estudiantes.getDato(i).getedad()<<endl;
        cout<<" "<<endl;
    }
    
}

void buscarEstudiante(ListaDoble<estudiante> &estudiantes){
     string name;
    cout<<"Ingrese el nombre del estudiante que desea buscar"<<endl;
    cin.ignore();
    getline(cin,name);

    for (int i = 0; i < estudiantes.getTamanio(); i++)
    {
        if (name==estudiantes.getDato(i).getnombre())
        {
            cout<<"Nombre: "<<estudiantes.getDato(i).getnombre()<<endl;
            cout<<"Edad: "<<estudiantes.getDato(i).getedad()<<endl;
        }
        
    }
}
void cantEstudiantes(ListaDoble<estudiante> &estudiantes){
    cout<<"La cantidad de estudiantes es: "<<estudiantes.getTamanio()<<endl;
}


int main(){

    int option;
    ListaDoble<estudiante> Listado1;

    do
    {
        menu();
        cout<<"Ingrese una opcion"<<endl;
        cin>>option;
        switch (option)
        {
        case 1:
            agregarestudiante(Listado1);
            break;
        case 2:
            eliminarEstudiante(Listado1);
            break;
        case 3:
            listarEstudiantes(Listado1);
            break;
        case 4:
            buscarEstudiante(Listado1);
            break;
        case 5:
            cantEstudiantes(Listado1);
            break;
        
        default:
            cout<<"Opcion invalida"<<endl;
            break;
        }
} while (option!=6);
    


}