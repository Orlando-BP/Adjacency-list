#include <iostream>
#include "CLista.h"

void SalvarGrafo(CLista* Grafo) 
{
    fstream out;
    out.open("Archivo.txt", ios::out);
    if (out.is_open()) {
        Grafo->Salvar(out);
        out.close();
    }
    else
        cout << "No se pudo abrir el archivo." << endl;
}
void CargarGrafo(CLista* Grafo) 
{
    fstream in;
    in.open("Archivo.txt", ios::in);
    if (in.is_open()) {
        int i;
        in >> i;
        if (i == 0) {
            Grafo->Cargar(in);
        }
        in.close();
    }
    else
        cout << "No se pudo abrir el archivo." << endl;
}
int main()
{
    CLista* Grafo = new CLista;
    CargarGrafo(Grafo);
    bool Continuar = true;
    int opcion;
    do 
    {
        cout << "Grafo de Ciudades y sus Carreteras" << endl;
        cout << "1.-Crear una ciudad" << endl;
        cout << "2.-Crear Carretera" << endl;
        cout << "3.-Eliminar Carretera" << endl;
        cout << "4.-Mostrar Grafo" << endl;
        cout << "5.-Guardar Cambios" << endl;
        cout << "6.-Salir del programa" << endl;
        cout << "Ingresa una opcion: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
        {
            system("cls");
            Grafo->CrearNodoGrafo();
            system("Pause");
            system("cls");
            break;
        }
        case 2:
        {
            system("cls");
            Grafo->CrearAdyacencia();
            system("Pause");
            system("cls");
            break;
        }
        case 3:
        {
            system("cls");
            Grafo->EliminarAdyacencia();
            system("Pause");
            system("cls");
            break;
        }
        case 4:
        {
            system("cls");
            Grafo->Imprimir();
            system("Pause");
            system("cls");
            break;
        }
        case 5:
        {
            system("cls");
            SalvarGrafo(Grafo);
            system("Pause");
            system("cls");
            break;
        }
        case 6:
        {
            system("cls");
            cout << "Nos vemos..." << endl;
            Continuar = false;
            system("Pause");
            system("cls");
            break;
        }
        default:
            cout << "Esa opcion no esta disponible" << endl;
            system("Pause");
            system("cls");
            break;
        }
    }while(Continuar);
}
