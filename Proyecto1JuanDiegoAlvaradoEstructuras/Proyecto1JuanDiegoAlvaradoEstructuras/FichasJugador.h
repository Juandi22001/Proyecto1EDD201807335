#pragma once

#include <iostream>
#include <stdio.h>
#include<stdlib.h>
#include <conio.h>
#include<windows.h>
#include <fstream>
#include <string>
#include <msxml.h>


using namespace std;

void gotoxy4(short x, short y) {
	COORD pos;
	pos.X = x;
	pos.Y = y;
	HANDLE H;
	H = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(H, pos);
}



class FichasJugador
{
private:
	FichasJugador* Primero;
	FichasJugador* Ultimo;

public:
	FichasJugador* siguiente;
	FichasJugador* anterior;
	char Letra;

	FichasJugador();
	FichasJugador(char Letra);
	FichasJugador(char Letra[]);

	void Ver();
	void Agregar(char Letra);
	void Grafo();

	inline FichasJugador* getUltimo() {
		return this->Ultimo;

	};
	inline FichasJugador* getPrimero() {
		return this->Primero;
	};
};



FichasJugador::FichasJugador() {
	anterior = NULL;
	siguiente = NULL;
	Letra = ' ';
	Primero = NULL;
	Ultimo = NULL;
}
FichasJugador::FichasJugador(char L) {
	Letra = L;
	anterior = NULL;
	siguiente = NULL;
}
FichasJugador::FichasJugador(char L[]) {
	anterior = NULL;
	siguiente = NULL;
}
void FichasJugador::Agregar(char L) {
	FichasJugador* nuevoNodo = new FichasJugador(L);
	if (this->Primero != NULL) {

		this->Ultimo->siguiente = nuevoNodo;
		nuevoNodo->anterior = this->Ultimo;
		nuevoNodo->siguiente = NULL;
		this->Ultimo = nuevoNodo;


	}
	else if (this->Primero == NULL) {

		this->Primero = nuevoNodo;
		this->Primero->siguiente = NULL;
		this->Primero->anterior = NULL;
		this->Ultimo = Primero;
	}



}
void FichasJugador::Ver() {
	FichasJugador* actual = this->Primero;


	int contador = 0;
	while (actual != NULL)
	{
		gotoxy4(4, 2);
		cout << actual->Letra;
		actual = actual->siguiente;
	}

}
void FichasJugador::Grafo() {
	FichasJugador* actual = this->Primero;
	FichasJugador* aux2 = new FichasJugador();
	int pos = 0;
	ofstream archivo;

	archivo.open("ReporteFichasJugador.txt", ios::out);

	if (archivo.fail())
	{
		cout << "F";

	}

	archivo << "digraph G{ \n"

		<< "  subgraph cluster_0 { \n"
		<< "style = filled;\n"
		<< "		color = lightgrey;\n"
		<< "	node[style = filled,color = white];\n";
	do {
		archivo << "Nodo" << &*actual << "[ label = \"" << actual->Letra << "\" ];\n";
		if (actual->siguiente) {
			archivo << "Nodo" << &*actual << "->";
			archivo << "Nodo" << &*actual->siguiente << ";";
			archivo << "Nodo" << &*actual->siguiente << "->";
			archivo << "Nodo" << &*actual << ";";
		}
		actual = actual->siguiente;

	} while (actual != NULL);
	archivo << "\n" << "label = " << "Lista1 #1\n"
		<< "	;\n} \n }";


	archivo.close();
	char Dot[] = "dot -Tjpg ReporteFichasJugador.txt -o graphFichasJugador.jpg";
	system(Dot);


}
