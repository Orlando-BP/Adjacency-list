#pragma once
#include "CEdgeInfo.h"
class CNodoLA
{
    friend class CListaAdyacencia;
private:
    CNodoLA* Psig;
    CNodoLA* Pant;
    CEdgeInfo* Dato;

    void InsertarAdelante(CEdgeInfo* nd,CNodoLA* nodo);
    CEdgeInfo* EliminarSiguiente();
};

