#include "CEdgeInfo.h"

CEdgeInfo::CEdgeInfo()
{
	Nombre = "Desconocido";
	Destino = "No encontrado";
	Distancia = 0;
}

void CEdgeInfo::Imprimir()
{
	cout << "Nombre de la carretera: " << Nombre << endl;
	cout << "Nombre del destino: " << Destino << endl;
	cout << "Distancia de una ciudad a otra: "<< Distancia << endl;
}

void CEdgeInfo::crear(string destino)
{
	string nombre;
	int distancia;
	cout << "Ingresa Nombre de la carretera: ";
	cin >> nombre;
	cout << "Ingresa Distancia de una ciudad a otra: ";
	cin >> distancia;
	Nombre = nombre;
	Destino = destino;
	Distancia = distancia;
}

void CEdgeInfo::Salvar(fstream& out)
{
	out << CLSID_EdgeInfo << endl;
	out << Nombre << endl;
	out << Destino << endl;
	out << Distancia << endl;
}

void CEdgeInfo::Cargar(fstream& in)
{
	in >> Nombre;
	in >> Destino;
	in >> Distancia;
}
