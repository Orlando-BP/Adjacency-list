#include "CNodo.h"

CNodo::CNodo()
{
    ListaAd = new CListaAdyacencia;
}

void CNodo::InsertarAdelante(CNodoGrafo* nd)
{
    CNodo* PNuevo = nullptr;
    PNuevo = new CNodo;
    PNuevo->Pant = this;
    PNuevo->Psig = this->Psig;
    this->Psig->Pant = PNuevo;
    this->Psig = PNuevo;
    PNuevo->Dato = nd;
}

CNodoGrafo* CNodo::EliminarSiguiente()
{
    CNodo* PEliminar = nullptr;
    PEliminar = this->Psig;
    CNodoGrafo* dato = this->Psig->Dato;
    PEliminar->Psig->Pant = this;
    this->Psig = PEliminar->Psig;
    delete PEliminar;
    return dato;
}
