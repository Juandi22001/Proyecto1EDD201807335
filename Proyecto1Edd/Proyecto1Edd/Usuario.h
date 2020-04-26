#pragma once

#include <iostream>
#include <stdio.h>
#include<stdlib.h>
#include <conio.h>
#include<windows.h>
#include <fstream>
#include <string>
#include <msxml.h>
#include <string.h>


#include "EnOrden.h"
#include "EnOrden.h"
using namespace std;
EnOrden* Orden = new EnOrden;
PreOrden* preOrden = new PreOrden;
PosOrden* posOrden = new PosOrden;

void gotoxy7(short x, short y) {
	COORD pos;
	pos.X = x;
	pos.Y = y;
	HANDLE H;
	H = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(H, pos);
}

class NodoPunteo {
public:
	NodoPunteo* sig;
	int punteo;
	NodoPunteo();
	NodoPunteo(int p);


};

NodoPunteo::NodoPunteo() {
	this->sig = NULL;
	this->punteo = 0;
}
NodoPunteo::NodoPunteo(int a) {


	this->sig = NULL;
	this->punteo = a;
}
static class ListaPunteo {

public: NodoPunteo* first;

		NodoPunteo* last;
		ListaPunteo() {

			first = NULL;
			last = NULL;
		}


		void Agregar(int Puntaje) {
			NodoPunteo* NuevoNodo = new NodoPunteo(Puntaje);
			if (this->first == NULL || Puntaje >= this->first->punteo)
			{
				NuevoNodo->sig = this->first;
				this->first = NuevoNodo;
			}
			else {
				NodoPunteo* aux = this->first;
				while (aux->sig != NULL && aux->sig->punteo >= Puntaje)
				{
					aux = aux->sig;
				}
				if (aux->sig == NULL)
				{
					NuevoNodo->sig = aux->sig;
				}
				aux->sig = NuevoNodo;

			}
		}


		void Grafo() {
			NodoPunteo* actual = first;
			int pos = 0;
			ofstream archivo;

			archivo.open("ReportePunteoJugador.txt", ios::out);

			if (archivo.fail())
			{
				cout << "F";

			}

			archivo << "digraph G{ \n"

				<< "  subgraph cluster_0 { \n"
				<< "style = filled;\n"
				<< "		color = lightgrey;\n"
				<< "	node[style = filled,color = white];\n";
			while (actual != NULL) {
				archivo << "Nodo" << &*actual << "[ label = \"" << actual->punteo << "\" ];\n";

				if (actual->sig)
				{
					archivo << "Nodo" << &*actual << "->";
					archivo << "Nodo" << &*actual->sig << ";";
				}
				actual = actual->sig;

			}
			archivo << "\n" << "label = " << "Lista1 #1\n"
				<< "	;\n} \n }";


			archivo.close();
			char Dot[] = "dot -Tjpg ReportePunteoJugador.txt -o graphicsPunteo.jpg";
			system(Dot);




		}
};
class Usuarios
{
private:
	Usuarios* Pri;
	Usuarios* Ult;
public:
	Usuarios();
	Usuarios(int Puntaje);	Usuarios(string Nombre);
	void Grafo();
	bool Buscar(string Nombre);

	void Agregar(string Nombre);
	Usuarios* sig;
	ListaPunteo Punteo;
	inline Usuarios* getPrimero() {
		return this->Pri;
	};
	string Nombre;
	int Puntaje;

	void Ver();


};


Usuarios::Usuarios() {
	sig = NULL;
	Puntaje = 0;
	Pri = NULL;
	Ult = NULL;

}
Usuarios::Usuarios(int Puntos) {

	Puntaje = Puntos;
	sig = NULL;
}
Usuarios::Usuarios(string Nombre) {

	this->Nombre = Nombre;
	sig = NULL;
}
bool Usuarios::Buscar(string Nombre) {
	bool a = false;

	Usuarios* alv = this->Pri;
	cout << alv->Nombre;
	while (alv != NULL)
	{
		cout << "adentro";

		if (alv->Nombre == Nombre)
		{
			return true;
		}

		alv = alv->sig;
	}



	return a;

}

void Usuarios::Agregar(string Nombre) {
	Usuarios* NuevoNodo = new Usuarios(Nombre);
	if (this->Pri == NULL)
	{
		this->Pri = NuevoNodo;
		this->Ult = NuevoNodo;

	}
	else {

		this->Ult->sig = NuevoNodo;
		this->Ult = NuevoNodo;
		NuevoNodo->sig = NULL;

	}

}

void Usuarios::Ver() {
	Usuarios* actual = this->Pri;


	int contador = 0;
	while (actual != NULL)
	{
		cout << "punt" << actual->Puntaje;
		actual = actual->sig;
	}

}
void Usuarios::Grafo() {
	Usuarios* actual = this->Pri;

	int pos = 0;
	ofstream archivo;

	archivo.open("ListaJugadores.txt", ios::out);

	if (archivo.fail())
	{
		cout << "F";

	}

	archivo << "digraph G{ \n"

		<< "  subgraph cluster_0 { \n"
		<< "style = filled;\n"
		<< "		color = lightgrey;\n"
		<< "	node[style = filled,color = white];\n";
	while (actual != NULL) {
		archivo << "Nodo" << &*actual << "[ label = \"" << actual->Nombre << "\" ];\n";
		if (actual->sig)
		{
			archivo << "Nodo" << &*actual << "->";
			archivo << "Nodo" << &*actual->sig << ";";

		}
		actual = actual->sig;

	}
	archivo << "\n" << "label = " << "ListaPreOrden #1\n"
		<< "	;\n} \n }";


	archivo.close();
	char Dot[] = "dot -Tjpg ListaJugadores.txt -o ListaJugadores.jpg";
	system(Dot);

}
class Usuario

{
private:
	string a;

public:


	Usuarios* k = new Usuarios;
	Usuario* Raiz;
	string j;


	bool Buscar(string a);

	Usuario* der;
	Usuario* izq;
	string Nombre;
	Usuario* Nuevo = NULL;
	void Agregar();
	Usuario();
	Usuario(string Nombre)
		;

	int cont = 0;
	void GetGrafo(Usuario* alv);
	void Ordenado(Usuario* Nodo);

	void PreOrden(Usuario* Nodo);

	void PostOrden(Usuario* Nodo);
	void NuevoUser(string Nombre);
	void Mostrar();

	Usuario* Insertar(Usuario*&, string Nombre);
	inline string getUNombre() {
		return Nombre;

	}

};
Usuario::Usuario(string Nombre) {
	this->Nombre = Nombre;


	izq = NULL;
	der = NULL;
}

Usuario::Usuario() {
	izq = NULL;
	Nombre = "";
	der = NULL;

}

void Usuario::NuevoUser(string Nombre) {


	Raiz = Insertar(Raiz, Nombre);



}
Usuario* Usuario::Insertar(Usuario*& NuevoNoodo, string Nombre) {




	if (NuevoNoodo == NULL)
	{

		NuevoNoodo = new Usuario(Nombre);


		;
	}
	else if (NuevoNoodo != NULL) {
		string Raiz = NuevoNoodo->getUNombre();
		if (strcmp(Nombre.c_str(), Raiz.c_str()) > 0) {

			NuevoNoodo->der = Insertar(NuevoNoodo->der, Nombre);

		}
		else  if (strcmp(Raiz.c_str(), Nombre.c_str()) > 0) {
			NuevoNoodo->izq = Insertar(NuevoNoodo->izq, Nombre);

		}
	}
	return NuevoNoodo;

}
void Usuario::Agregar() {


	NuevoUser("hugo");
	NuevoUser("beto");
	NuevoUser("arbol");
	NuevoUser("carlos");

	NuevoUser("lily");

	NuevoUser("monica");
	NuevoUser("nora");
	NuevoUser("juan");

	NuevoUser("lucy	");
	NuevoUser("denis");

}void Usuario::Mostrar() {
	int alv2 = 0;
	int cont = 0;
	cont++;
	Usuario* Nuevo = this->Raiz;
	GetGrafo(Nuevo);
	Ordenado(Nuevo);
	Orden->Grafo();
	PostOrden(Nuevo);
	posOrden->Grafo();
	PreOrden(Nuevo);
	preOrden->Grafo();
	k->Grafo();

}
bool Usuario::Buscar(string a) {
	bool bo;
	if (k->Buscar(a) == true)
	{
		bo = true;
	}
	else {
		bo = false;
	}


	return bo;
}
void Usuario::GetGrafo(Usuario* alv) {
	Usuario* alv2;
	Usuario* alv3;
	Usuario* alv4;
	Usuario* alv5;
	ofstream archivo;

	archivo.open("Arbol.txt", ios::out);

	if (archivo.fail())
	{
		cout << "F";

	}
	//Recorriendo por la derecha
	else if (alv == NULL)
	{

		return;

	}


	else {
		archivo << "digraph Arbol{ \n"

			<< "  subgraph cluster_0 { \n"
			<< "style = filled;\n"
			<< "		color = lightgrey;\n"
			<< "	node[style = filled,color = white];\n";

		while (alv->izq != NULL)

		{

			archivo << alv->getUNombre() << "->" << alv->izq->Nombre << endl;
			alv = alv->izq;
		}
		alv = Raiz;


		while (alv->der != NULL)

		{
			if (alv->izq != NULL && alv != Raiz)
			{

				alv2 = alv;

				cout << alv2->izq->Nombre;

				while (alv2->izq != NULL)
				{
					archivo << alv2->Nombre << "->" << alv2->izq->Nombre << endl;


					alv2 = alv2->izq;
				}
			}

			alv = alv->der;
		}alv = Raiz;

		while (alv->der != NULL)

		{
			archivo << alv->getUNombre() << "->" << alv->der->Nombre << endl;;
			alv = alv->der;
		}











		alv = Raiz;
		while (alv->izq != NULL)

		{
			if (alv->der != NULL && alv != Raiz)
			{

				alv3 = alv;

				while (alv3->der != NULL)
				{
					archivo << alv3->Nombre << "->" << alv3->der->Nombre << endl;


					alv3 = alv3->der;
				}
			}

			alv = alv->izq;
		}
	}

	archivo << "\n" << "label = " << "Arbol\n"
		<< "	;\n} \n }";
	archivo.close();
	char Dot[] = "dot -Tjpg Arbol.txt -o ArbolBinario.jpg";
	system(Dot);
}void Usuario::Ordenado(Usuario* alv) {


	if (alv != NULL)
	{

		Ordenado(alv->izq);

		Orden->Agregar(alv->Nombre);
		k->Agregar(alv->Nombre);
		Ordenado(alv->der);
	}





}
void Usuario::PreOrden(Usuario* alv) {


	if (alv != NULL)
	{
		preOrden->Agregar(alv->Nombre);
		PreOrden(alv->izq);
		PreOrden(alv->der);

	}





}
void Usuario::PostOrden(Usuario* alv) {


	if (alv != NULL)
	{
		PostOrden(alv->izq);
		PostOrden(alv->der);
		posOrden->Agregar(alv->Nombre);

	}





}

class Triples {

private:
	Triples* Pri;
	Triples* Ult;
public:
	Triples();
	Triples(int x, int y); Triples(string Nombre);
	void Grafo();
	bool Buscar(int a, int b);
	int x;
	int y;
	void Agregar(int x, int y);
	Triples* sig;

	string Nombre;
	int Puntaje;

	void Ver();

};


Triples::Triples() {
	sig = NULL;
	Puntaje = 0;
	Pri = NULL;
	Ult = NULL;

}
Triples::Triples(int x, int y) {
	x = x;
	y = y;
	sig = NULL;
}
Triples::Triples(string Nombre) {

	this->Nombre = Nombre;
	sig = NULL;
}


void Triples::Agregar(int x, int y) {
	Triples* NuevoNodo = new Triples(x, y);
	if (this->Pri == NULL)
	{
		this->Pri = NuevoNodo;
		this->Ult = NuevoNodo;

	}
	else {
		cout << "agregando";

		this->Ult->sig = NuevoNodo;
		this->Ult = NuevoNodo;
		NuevoNodo->sig = NULL;

	}

}
bool Triples::Buscar(int x, int y) {
	bool a = false;
	Triples* alv = this->Pri;

	while (alv != NULL)
	{
		if (alv->x == x && alv->y == y)
		{
			a = true;
		}
	}
	a = true;
}

class Dobles {

private:
	Dobles* Pri;
	Dobles* Ult;
public:
	Dobles();
	Dobles(int x, int y); Dobles(string Nombre);
	void Grafo();
	bool Buscar(int a, int b);
	void AgregarInicio(int Puntaje);
	int x;
	int y;
	void Agregar(int x, int y);
	Dobles* sig;

	string Nombre;
	int Puntaje;

	void Ver();

};


Dobles::Dobles() {
	sig = NULL;
	Puntaje = 0;
	Pri = NULL;
	Ult = NULL;

}
Dobles::Dobles(int x, int y) {
	x = x;
	y = y;
	sig = NULL;
}
Dobles::Dobles(string Nombre) {

	this->Nombre = Nombre;
	sig = NULL;
}


void Dobles::Agregar(int x, int y) {
	Dobles* NuevoNodo = new Dobles(x, y);
	if (this->Pri == NULL)
	{
		this->Pri = NuevoNodo;
		this->Ult = NuevoNodo;

	}
	else {
		cout << "agregando";

		this->Ult->sig = NuevoNodo;
		this->Ult = NuevoNodo;
		NuevoNodo->sig = NULL;

	}

}
bool Dobles::Buscar(int x, int y) {
	bool a = false;
	Dobles* alv = this->Pri;

	while (alv != NULL)
	{
		if (alv->x == x && alv->y == y)
		{
			a = true;
		}
	}
	a = true;
}






