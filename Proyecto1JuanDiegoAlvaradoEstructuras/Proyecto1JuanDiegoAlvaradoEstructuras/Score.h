#include <iostream>
#include <stdio.h>
#include<stdlib.h>
#include <conio.h>
#include<windows.h>
#include <fstream>
#include <string>
#include <msxml.h>

using namespace std;

void gotoxy6(short x, short y) {
	COORD pos;
	pos.X = x;
	pos.Y = y;
	HANDLE H;
	H = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(H, pos);
}



class Score
{
private:
	Score* Pri;
	Score* Ult;
public:
	Score();
	Score(int Puntaje,string a);
	void Grafo();
	string Nombre;
	void AgregarInicio(int Puntaje,string a);
	void AgregarFinal(Score* NuevoNodo, int Puntaje);
	Score* sig;


	int Puntaje;
	void Buscar(string a);
	void Ver();
	void Agregar(int Puntaje);

};


Score::Score() {
	sig = NULL;
	Puntaje = 0;
	Pri = NULL;
	Ult = NULL;

}
Score::Score(int Puntos, string a) {
	Nombre = a;
	Puntaje = Puntos;
	sig = NULL;
}
void Score::AgregarFinal(Score* NuevoNodo, int Puntaje) {
	if (this->Pri == NULL)
	{

		this->Pri = NuevoNodo;
		this->Pri = Ult;

	}
	else {

		this->Ult->sig = NuevoNodo;
		this->Ult = NuevoNodo;
		this->Ult = NuevoNodo;
		NuevoNodo->sig = NULL;

	}

}

void Score::AgregarInicio(int Puntaje ,string a) {
	Score* NuevoNodo = new Score(Puntaje,a);
	if (this->Pri == NULL || Puntaje >= this->Pri->Puntaje)
	{
		NuevoNodo->sig = this->Pri;
		this->Pri = NuevoNodo;
	}
	else {
		Score* aux = this->Pri;
		while (aux->sig != NULL && aux->sig->Puntaje >= Puntaje)
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
void Score::Agregar(int Puntaje) {
	Score* act = this->Pri;
	boolean a = FALSE;
	Score*
		Nuevo = this->Pri;
	while (a == FALSE && Nuevo != NULL)
	{
		if (Puntaje >= Nuevo->Puntaje)
		{
			cout << "si";
			a = TRUE;

		}
		else {
			act = Nuevo;
			Nuevo = Nuevo->sig;

		}




	}
	if (act != NULL) {




	}
	else
	{
		AgregarFinal(Nuevo, Puntaje);
	}
}
void Score::Ver() {
	Score* actual = this->Pri;


	int contador = 0;
	while (actual != NULL)
	{
		cout<<"nombre:--"<<actual->Nombre<<"----" << "punt" << actual->Puntaje<<endl;
		actual = actual->sig;
	}

}
void Score::Grafo() {
	Score* actual = this->Pri;

	int pos = 0;
	ofstream archivo;

	archivo.open("ReporteScore.txt", ios::out);

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
		archivo << "Nodo" << &*actual << "[ label = \"" << actual->Puntaje << "\n"<<actual->Nombre<<"\" ];\n";

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
	char Dot[] = "dot -Tjpg ReporteScore.txt -o graphicsScore.jpg";
	system(Dot);

}
void Score::Buscar(string a) {

	Score* actual = this->Pri;
while(actual!=NULL){
	if (actual->Nombre==a)
	{

	
	int pos = 0;
	ofstream archivo;

	archivo.open("ReporteScorePorJugador.txt", ios::out);

	if (archivo.fail())
	{
		cout << "F";

	}

	archivo << "digraph G{ \n"

		<< "  subgraph cluster_0 { \n"
		<< "style = filled;\n"
		<< "		color = lightgrey;\n"
		<< "	node[style = filled,color = white];\n";

		archivo << "Nodo" << &*actual << "[ label = \"" << actual->Puntaje << "\n" << actual->Nombre << "\" ];\n";

		if (actual->sig)
		{
			archivo << "Nodo" << &*actual << "->";
			archivo << "Nodo" << &*actual->sig << ";";
		}
		

	
	archivo << "\n" << "label = " << "Lista1 #1\n"
		<< "	;\n} \n }";


	archivo.close();
	char Dot[] = "dot -Tjpg ReporteScorePorJugador.txt -o graphicsScorePlayer.jpg";
	system(Dot);
	
	actual = actual->sig;
}
	}