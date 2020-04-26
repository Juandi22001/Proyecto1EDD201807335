#include <iostream>
#include <stdio.h>
#include<stdlib.h>
#include <conio.h>
#include<windows.h>
#include <fstream>
#include <string>
#include <msxml.h>

using namespace std;

void gotoxy15(short x, short y) {
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



	void Agregar(string Nombre);
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


void EnOrden::Agregar(string Nombre) {
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









