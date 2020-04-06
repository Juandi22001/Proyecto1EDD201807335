
#pragma once
#include <iostream>
#include <stdio.h>
#include<stdlib.h>
#include <conio.h>
#include<windows.h>
#include <fstream>

void gotoxy2(short x, short y) {
	COORD pos;
	pos.X = x;
	pos.Y = y;
	HANDLE H;
	H = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(H, pos);
}



using namespace std;
class Diccionarios
{
private:
	Diccionarios* Primero;
	Diccionarios* Ultimo;

public:
	Diccionarios* siguiente;
	Diccionarios* anterior;

	string Palabra;
	Diccionarios();
	Diccionarios(string Palabra);

	bool Buscar(string a);
	void Agregar(string Palabra);
	void Grafo();
	inline Diccionarios* getUltimo() {
		return this->Ultimo;

	};
	inline Diccionarios* getPrimero() {
		return this->Primero;
	};
};


Diccionarios::Diccionarios() {
	siguiente = NULL;
	Palabra = ' ';
	anterior = NULL;
	Primero = NULL;
	Ultimo = NULL;
}
Diccionarios::Diccionarios(string Palabras) {
	Palabra = Palabras;
	anterior = NULL;
	siguiente = NULL;
}

void Diccionarios::Agregar(string L) {
	Diccionarios* nuevoNodo = new Diccionarios(L);
	if (this->Primero != NULL) {

		this->Ultimo->siguiente = nuevoNodo;
		nuevoNodo->anterior = this->Ultimo->anterior;
		nuevoNodo->siguiente = this->Primero;
		this->Primero->anterior = nuevoNodo;
		this->Ultimo = nuevoNodo;

	}
	else if (this->Primero == NULL) {

		this->Primero = nuevoNodo;
		this->Primero->siguiente = this->Primero;
		this->Primero->anterior = Primero;
		this->Ultimo = nuevoNodo;

	}



}
bool Diccionarios::Buscar(string a) {
	bool alv =false;
	Diccionarios* actual = this->Primero;


	while (actual->siguiente != this->Primero) {
		if (actual->Palabra==a)
		{

			alv = true;
		}

		actual = actual->siguiente;
	}
	return alv;
}
void Diccionarios::Grafo() {
	Diccionarios* actual = this->Primero;

	int pos = 0;
	ofstream archivo;

	archivo.open("Diccionario.txt", ios::out);

	if (archivo.fail())
	{
		cout << "F";

	}

	archivo << "digraph G{ \n"
		<< "  	rankdir = LR;  \n"
		<< "  subgraph cluster_0 { \n"	
		<< "style = filled;\n"
		<< "		color = 	azure2;\n"
		<< "	node[shape=Msquare style = filled, color = darkslategray text=white gradientangle=90];\n";
	do {
		archivo << "Nodo" << &*actual << "[ label = \"" << actual->Palabra << "\" ];\n";
		if (actual->siguiente) {
			archivo << "Nodo" << &*actual << "->";
			archivo << "Nodo" << &*actual->siguiente << ";";
			archivo << "Nodo" << &*actual->siguiente << "->";
			archivo << "Nodo" << &*actual << ";";
		}
		actual = actual->siguiente;

	} while (actual != this->Primero);
	archivo << "\n" << "label = " << "DiccionariodePalabras #1\n"
		<< "	;\n} \n }";


	archivo.close();
	char Dot[] = "dot -Tjpg Diccionario.txt -o graphicsDiccionario.jpg";
	system(Dot);


}

