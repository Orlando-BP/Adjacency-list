#include "CLista.h"

void CLista::CrearAdyacencia()
{
	string origen, destino;
	cout << "Ingresa la ciudad de origen: ";
	cin >> origen;
	CNodo* AUX = Inicio.Psig;
	while (AUX != &Final)
	{
		if (AUX->Dato->Nombre == origen) 
		{
			cout << "Ingresa la ciudad de destino: ";
			cin >> destino;
			CNodo* AUX2 = Inicio.Psig;
			while (AUX2 != &Final)
			{
				if (AUX2->Dato->Nombre == destino)
				{
					AUX->ListaAd->CrearAdyacencia(destino);
				}
				
				AUX2 = AUX2->Psig;
			}
		}
		
		AUX = AUX->Psig;
	}
}

void CLista::EliminarAdyacencia()
{
	string origen, destino;
	cout << "Para quitar una carretera debera ingresar los datos de las calles relacionadas" << endl;
	cout << "Ingresa la ciudad de origen: ";
	cin >> origen;
	CNodo* AUX = Inicio.Psig;
	while (AUX != &Final)
	{
		if (AUX->Dato->Nombre == origen)
		{
			cout << "Ingresa la ciudad de destino: ";
			cin >> destino;
			CNodo* AUX2 = Inicio.Psig;
			while (AUX2 != &Final)
			{
				if (AUX2->Dato->Nombre == destino)
				{
					AUX->ListaAd->EliminarAdyacencia(destino);
				}

				AUX2 = AUX2->Psig;
			}
		}

		AUX = AUX->Psig;
	}
}

void CLista::CrearNodoGrafo()
{
	CNodoGrafo* nd = new CNodoGrafo;
	nd->crear();
	InsertarAlInicio(nd);
}

void CLista::InsertarAlInicio(CNodoGrafo* nd)
{
	Inicio.InsertarAdelante(nd);
}

void CLista::InsertarAlFinal(CNodoGrafo* nd)
{
	Final.Pant->InsertarAdelante(nd);
}

CNodoGrafo* CLista::EliminarAlInicio()
{
	return Inicio.EliminarSiguiente();
}

CNodoGrafo* CLista::EliminarAlFinal()
{
	return Final.Pant->Pant->EliminarSiguiente();
}

void CLista::Imprimir()
{
	CNodo* AUX = Inicio.Psig;
	while (AUX != &Final)
	{
		AUX->Dato->Imprimir();
		AUX->ListaAd->Imprimir();
		cout <<"___________________________"<< endl;
		AUX = AUX->Psig;
	}
}

void CLista::Vaciar()
{
	while (Inicio.Psig != &Final) {
		Inicio.EliminarSiguiente();
	}
}

int CLista::Size()
{
	CNodo* AUX = Inicio.Psig;
	int N = 0;
	while (AUX != &Final) {
		N++;
		AUX = AUX->Psig;
	}
	return N;
}

bool CLista::IsEmpty()
{
	return (Inicio.Psig == &Final);
}

bool CLista::IsFull()
{
	return false;
}

void CLista::Salvar(fstream& out)
{
	out << CLSID_Lista << endl;
	out << Size() << endl;
	CNodo* AUX = Inicio.Psig;
	while (AUX != &Final) {
		(AUX->Dato)->Salvar(out);
		(AUX->ListaAd)->Salvar(out);
		AUX = AUX->Psig;
	}
}

void CLista::Cargar(fstream& in)
{
	int cont, caso, lista;
	in >> cont;
	for (int i = 0; i < cont; i++) {
		in >> caso;
		switch (caso) {
		case CLSID_NodoGrafo: 
		{
			CNodoGrafo* NG = new CNodoGrafo;
			NG->Cargar(in);
			InsertarAlFinal(NG);
			in >> lista;
			Final.Pant->ListaAd->Cargar(in);
		}
		
		break;
		default:
			cout << "Error desconocido" << endl;
			break;
		}
	}
}

int CLista::getCLSID()
{
	return CLSID_Lista;
}

CLista::CLista()
{
	Inicio.Dato = 0;
	Final.Dato = 0;
	Inicio.Psig = &Final;
	Final.Pant = &Inicio;
}

CLista::~CLista()
{
	Vaciar();
}
