#pragma once
#include <iostream>
#include <fstream>
#define CLSID_EdgeInfo 3
using namespace std;
class CEdgeInfo
{
private:
	string Nombre;
	int Distancia;
public:
	string Destino;
	CEdgeInfo();
	void Imprimir();
	void crear(string destino);
	void Salvar(fstream& out);
	void Cargar(fstream& in);
};

