#pragma once
#include "CNodoLA.h"
#define CLSID_ListaAdyacencia 2
class CListaAdyacencia
{
private:
    CNodoLA Inicio;
    CNodoLA Final;
public:
    void CrearAdyacencia(string destino);
    void InsertarAlInicio(CEdgeInfo* nd);
    void InsertarAlFinal(CEdgeInfo* nd);
    void EliminarAdyacencia(string destino);
    CEdgeInfo* EliminarAlInicio();
    CEdgeInfo* EliminarAlFinal();
    void Imprimir();
    void Vaciar();
    int Size();
    bool IsEmpty();
    bool IsFull();
    void Salvar(fstream& out);
    void Cargar(fstream& in);
    int getCLSID();
    CListaAdyacencia();
    ~CListaAdyacencia();
};

