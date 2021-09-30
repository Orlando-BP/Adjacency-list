#include "CNodoLA.h"

void CNodoLA::InsertarAdelante(CEdgeInfo* nd, CNodoLA* nodo)
{
    CNodoLA* PNuevo = nullptr;
    PNuevo = new CNodoLA;
    PNuevo->Pant = nodo;
    PNuevo->Psig = nodo->Psig;
    nodo->Psig->Pant = PNuevo;
    nodo->Psig = PNuevo;
    PNuevo->Dato = nd;
}

CEdgeInfo* CNodoLA::EliminarSiguiente()
{
    CNodoLA* PEliminar = nullptr;
    PEliminar = this->Psig;
    CEdgeInfo* dato = this->Psig->Dato;
    PEliminar->Psig->Pant = this;
    this->Psig = PEliminar->Psig;
    delete PEliminar;
    return dato;
}
