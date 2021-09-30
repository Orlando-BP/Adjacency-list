#include "CNodoGrafo.h"

CNodoGrafo::CNodoGrafo()
{
	Nombre = "Ciudad Deesconocida";
}

void CNodoGrafo::Imprimir()
{
	cout << "Ciudad de: " << Nombre << endl;
}

void CNodoGrafo::crear()
{
	string nombre;
	cout << "Ingresa el nombre de la ciudad: ";
	cin >> nombre;
	Nombre = nombre;
}

void CNodoGrafo::Salvar(fstream& out)
{
	out << CLSID_NodoGrafo << endl;
	out << Nombre << endl;
}

void CNodoGrafo::Cargar(fstream& in)
{
	in >> Nombre;
}
