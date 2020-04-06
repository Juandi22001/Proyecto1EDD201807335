#include <iostream>
#include <stdio.h>
#include<stdlib.h>
#include <conio.h>
#include<windows.h>
#include <fstream>
#include <string>
#include <msxml.h>

using namespace std;

void gotoxy12(short x, short y) {
	COORD pos;
	pos.X = x;
	pos.Y = y;
	HANDLE H;
	H = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(H, pos);
}



class EnOrden
{
private:
	EnOrden* Pri;
	EnOrden* Ult;
public:
	EnOrden();
	EnOrden(int Puntaje);	EnOrden(string Nombre);
	void Grafo();

	

	void Agregar( string Nombre);
	EnOrden* sig;

	string Nombre;
	int Puntaje;

	void Ver();


};


EnOrden::EnOrden() {
	sig = NULL;
	Puntaje = 0;
	Pri = NULL;
	Ult = NULL;

}
EnOrden::EnOrden(int Puntos) {

	Puntaje = Puntos;
	sig = NULL;
}
EnOrden::EnOrden(string Nombre) {

	this->Nombre = Nombre;
	sig = NULL;
}


void EnOrden::Agregar( string Nombre) {
	EnOrden* NuevoNodo = new EnOrden(Nombre);
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

void EnOrden::Ver() {
	EnOrden* actual = this->Pri;


	int contador = 0;
	while (actual != NULL)
	{
		cout << "punt" << actual->Puntaje;
		actual = actual->sig;
	}

}
void EnOrden::Grafo() {
	EnOrden* actual = this->Pri;

	int pos = 0;
	ofstream archivo;

	archivo.open("ReporteEnOrden.txt", ios::out);

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
	archivo << "\n" << "label = " << "ListaEnOrden #1\n"
		<< "	;\n} \n }";


	archivo.close();
	char Dot[] = "dot -Tjpg ReporteEnOrden.txt -o graphicsEnOrden.jpg";
	system(Dot);

}


class PosOrden
{
private:
	PosOrden* Pri;
	PosOrden* Ult;
public:
	PosOrden();
	PosOrden(int Puntaje);	PosOrden(string Nombre);
	void Grafo();

	void AgregarInicio(int Puntaje);

	void Agregar(string Nombre);
	PosOrden* sig;

	string Nombre;
	int Puntaje;

	void Ver();


};


PosOrden::PosOrden() {
	sig = NULL;
	Puntaje = 0;
	Pri = NULL;
	Ult = NULL;

}
PosOrden::PosOrden(int Puntos) {

	Puntaje = Puntos;
	sig = NULL;
}
PosOrden::PosOrden(string Nombre) {

	this->Nombre = Nombre;
	sig = NULL;
}


void PosOrden::Agregar(string Nombre) {
	PosOrden* NuevoNodo = new PosOrden(Nombre);
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

void PosOrden::Ver() {
	PosOrden* actual = this->Pri;


	int contador = 0;
	while (actual != NULL)
	{
		cout << "punt" << actual->Puntaje;
		actual = actual->sig;
	}

}
void PosOrden::Grafo() {
	PosOrden* actual = this->Pri;

	int pos = 0;
	ofstream archivo;

	archivo.open("ReportePosOrden.txt", ios::out);

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
	archivo << "\n" << "label = " << "ListaPosOrden #1\n"
		<< "	;\n} \n }";


	archivo.close();
	char Dot[] = "dot -Tjpg ReportePosOrden.txt -o graphicsPosOrden.jpg";
	system(Dot);

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


void Dobles::Agregar(int x , int y) {
	Dobles* NuevoNodo = new Dobles(x,y);
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

	while (alv!=NULL)
	{
		if (alv->x==x && alv->y==y)
		{
			a = true;
		}
	}
	a = true;
}
void Dobles::Ver() {
	Dobles* actual = this->Pri;


	int contador = 0;
	while (actual != NULL)
	{
		cout << "punt" << actual->Puntaje;
		actual = actual->sig;
	}

}
void Dobles::Grafo() {
	Dobles* actual = this->Pri;

	int pos = 0;
	ofstream archivo;

	archivo.open("ReporteDobles.txt", ios::out);

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
	archivo << "\n" << "label = " << "ListaDobles #1\n"
		<< "	;\n} \n }";


	archivo.close();
	char Dot[] = "dot -Tjpg ReporteDobles.txt -o graphicsDobles.jpg";
	system(Dot);

}


void Dobles::Ver() {
	Dobles* actual = this->Pri;


	int contador = 0;
	while (actual != NULL)
	{
		cout << "punt" << actual->Puntaje;
		actual = actual->sig;
	}

}
void Dobles::Grafo() {
	Dobles* actual = this->Pri;

	int pos = 0;
	ofstream archivo;

	archivo.open("ReporteDobles.txt", ios::out);

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
	archivo << "\n" << "label = " << "ListaDobles #1\n"
		<< "	;\n} \n }";


	archivo.close();
	char Dot[] = "dot -Tjpg ReporteDobles.txt -o graphicsDobles.jpg";
	system(Dot);

}


















class Triples {

private:
	Triples* Pri;
Triples* Ult;
public:
Triples();
Triples(int Puntaje);Triples(string Nombre);
	void Grafo();

	void AgregarInicio(int Puntaje);

	void Agregar(string Nombre);
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
Triples::Triples(int Puntos) {

	Puntaje = Puntos;
	sig = NULL;
}
Triples::Triples(string Nombre) {

	this->Nombre = Nombre;
	sig = NULL;
}


void Triples::Agregar(string Nombre) {
Triples* NuevoNodo = new Triples(Nombre);
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

void Triples::Ver() {
Triples* actual = this->Pri;


	int contador = 0;
	while (actual != NULL)
	{
		cout << "punt" << actual->Puntaje;
		actual = actual->sig;
	}

}
void Triples::Grafo() {
Triples* actual = this->Pri;

	int pos = 0;
	ofstream archivo;

	archivo.open("ReporteTriples.txt", ios::out);

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
	archivo << "\n" << "label = " << "ListaTriples #1\n"
		<< "	;\n} \n }";


	archivo.close();
	char Dot[] = "dot -Tjpg ReporteTriples.txt -o graphicsTriples.jpg";
	system(Dot);

}


void Triples::Ver() {
	Triples* actual = this->Pri;


	int contador = 0;
	while (actual != NULL)
	{
		cout << "punt" << actual->Puntaje;
		actual = actual->sig;
	}

}
void Triples::Grafo() {
	Triples* actual = this->Pri;

	int pos = 0;
	ofstream archivo;

	archivo.open("ReporteTriples.txt", ios::out);

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
	archivo << "\n" << "label = " << "ListaTriples #1\n"
		<< "	;\n} \n }";


	archivo.close();
	char Dot[] = "dot -Tjpg ReporteTriples.txt -o graphicsTriples.jpg";
	system(Dot);

}








class PreOrden
{
private:
	PreOrden* Pri;
	PreOrden* Ult;
public:
	PreOrden();
	PreOrden(int Puntaje);	PreOrden(string Nombre);
	void Grafo();

	void AgregarInicio(int Puntaje);

	void Agregar(string Nombre);
	PreOrden* sig;

	string Nombre;
	int Puntaje;

	void Ver();


};


PreOrden::PreOrden() {
	sig = NULL;
	Puntaje = 0;
	Pri = NULL;
	Ult = NULL;

}
PreOrden::PreOrden(int Puntos) {

	Puntaje = Puntos;
	sig = NULL;
}
PreOrden::PreOrden(string Nombre) {

	this->Nombre = Nombre;
	sig = NULL;
}


void PreOrden::Agregar(string Nombre) {
	PreOrden* NuevoNodo = new PreOrden(Nombre);
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

void PreOrden::Ver() {
	PreOrden* actual = this->Pri;


	int contador = 0;
	while (actual != NULL)
	{
		cout << "punt" << actual->Puntaje;
		actual = actual->sig;
	}

}
void PreOrden::Grafo() {
	PreOrden* actual = this->Pri;

	int pos = 0;
	ofstream archivo;

	archivo.open("ReportePreOrden.txt", ios::out);

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
	char Dot[] = "dot -Tjpg ReportePreOrden.txt -o graphicsPreOrden.jpg";
	system(Dot);

}









