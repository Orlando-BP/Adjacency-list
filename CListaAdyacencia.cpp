#include "CListaAdyacencia.h"

void CListaAdyacencia::CrearAdyacencia(string destino)
{
	CEdgeInfo* nd = new CEdgeInfo;
	nd->crear(destino);
	InsertarAlInicio(nd);
}

void CListaAdyacencia::InsertarAlInicio(CEdgeInfo* nd)
{
	Inicio.InsertarAdelante(nd,&Inicio);
}

void CListaAdyacencia::InsertarAlFinal(CEdgeInfo* nd)
{
	Final.Pant->InsertarAdelante(nd,Final.Pant);
}

void CListaAdyacencia::EliminarAdyacencia(string destino)
{
	CNodoLA* AUX = Inicio.Psig;
	while (AUX != &Final) {
		if (AUX->Dato->Destino == destino){
			AUX = AUX->Pant;
			AUX->EliminarSiguiente();
		}
		AUX = AUX->Psig;
	}
}

CEdgeInfo* CListaAdyacencia::EliminarAlInicio()
{
	return Inicio.EliminarSiguiente();
}

CEdgeInfo* CListaAdyacencia::EliminarAlFinal()
{
	return Final.Pant->Pant->EliminarSiguiente();
}

void CListaAdyacencia::Imprimir()
{
	cout << "Estas son las carreteras y las ciudades con las que conecta: " << endl<<endl;
	CNodoLA* AUX = Inicio.Psig;
	while (AUX != &Final) {
		AUX->Dato->Imprimir();
		cout << endl;
		AUX = AUX->Psig;
	}
	
}

void CListaAdyacencia::Vaciar()
{
	while (Inicio.Psig != &Final) {
		Inicio.EliminarSiguiente();
	}
}

int CListaAdyacencia::Size()
{
	CNodoLA* AUX = Inicio.Psig;
	int N = 0;
	while (AUX != &Final) {
		N++;
		AUX = AUX->Psig;
	}
	return N;
}

bool CListaAdyacencia::IsEmpty()
{
	return (Inicio.Psig == &Final);
}

bool CListaAdyacencia::IsFull()
{
	return false;
}

void CListaAdyacencia::Salvar(fstream& out)
{
	out << CLSID_ListaAdyacencia << endl;
	out << Size() << endl;
	CNodoLA* AUX = Inicio.Psig;
	while (AUX != &Final) {
		(AUX->Dato)->Salvar(out);
		AUX = AUX->Psig;
	}
}

void CListaAdyacencia::Cargar(fstream& in)
{
	int cont,caso;
	in >> cont;
	for (int i = 0; i < cont; i++) {
		in >> caso;
		switch (caso) {
		case CLSID_EdgeInfo:
		{
			CEdgeInfo* E = new CEdgeInfo;
			E->Cargar(in);
			InsertarAlFinal(E);
		}
		break;
		default:
			cout << "Error desconocido" << endl;
			break;
		}
	}
}

int CListaAdyacencia::getCLSID()
{
	return CLSID_ListaAdyacencia;
}

CListaAdyacencia::CListaAdyacencia()
{
	Inicio.Dato = 0;
	Final.Dato = 0;
	Inicio.Psig = &Final;
	Final.Pant = &Inicio;
}

CListaAdyacencia::~CListaAdyacencia()
{
	Vaciar();
}

