#pragma once
#include "CNodo.h"
#define CLSID_Lista 0
class CLista
{
private:

    CNodo Inicio;
    CNodo Final;
public:
    void CrearAdyacencia();
    void EliminarAdyacencia();
    void CrearNodoGrafo();
    void InsertarAlInicio(CNodoGrafo* nd);
    void InsertarAlFinal(CNodoGrafo* nd);
    CNodoGrafo* EliminarAlInicio();
    CNodoGrafo* EliminarAlFinal();
    void Imprimir();
    void Vaciar();
    int Size();
    bool IsEmpty();
    bool IsFull();
    void Salvar(fstream& out);
    void Cargar(fstream& in);
    int getCLSID();
    CLista();
    ~CLista();
};


