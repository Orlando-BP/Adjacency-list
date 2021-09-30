#pragma once
#include "CNodoGrafo.h"
#include "CListaAdyacencia.h"
class CNodo
{
    friend class CLista;
private:

    CNodo* Psig;
    CNodo* Pant;
    CNodoGrafo* Dato;
    CListaAdyacencia* ListaAd;
    
public:
    CNodo();
    void InsertarAdelante(CNodoGrafo* nd);
    CNodoGrafo* EliminarSiguiente();
};

