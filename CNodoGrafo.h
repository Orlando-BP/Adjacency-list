#pragma once
#include <iostream>
#include <fstream>
#define CLSID_NodoGrafo 1
using namespace std;
class CNodoGrafo
{
public:
	string Nombre;

	CNodoGrafo();
	void Imprimir();
	void crear();
	void Salvar(fstream& out);
	void Cargar(fstream& in);
};

