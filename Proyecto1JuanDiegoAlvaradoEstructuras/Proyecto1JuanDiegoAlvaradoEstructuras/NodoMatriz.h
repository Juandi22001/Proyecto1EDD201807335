#pragma once


#include <iostream>
#include <stdio.h>
#include<stdlib.h>
#include <conio.h>
#include<windows.h>
#include <fstream>


using namespace std;
class NodoMatriz
{




public:

	NodoMatriz* der;
	NodoMatriz* izq;
	NodoMatriz* down;
	NodoMatriz* up;
	int dato;
	char Prueba;
	int vx;
	int vy;

	NodoMatriz(int x) {
		this->dato = x;
		this->vx = 1;
		this->vy = 1;
		this->Prueba='-';
		der = NULL;
		izq = NULL;
		down = NULL;
		up = NULL;
	}

	NodoMatriz(char x ,int vx, int vy) {
		this->Prueba = x;
		this->vx = vx;
		this->vy = vy;
		this->dato = 0;
		der = NULL;
		izq = NULL;
		down = NULL;
		up = NULL;
	}
};



class ListaMatriz {
public:
	NodoMatriz* Raiz;



	ListaMatriz() {


		NodoMatriz* temp = new NodoMatriz(0);
		Raiz = temp;

	
	}

	void Agregar(char dato, int x, int y) {

		NodoMatriz* Nuevo = new NodoMatriz(dato,x,y);

		Add_X(x);
		Add_y(y); AgregarNodoY(Nuevo, x, y);
	AgregarNodoX(Nuevo, x, y);

	
	}  
	void AgregarNodoX(NodoMatriz* Nuevo, int x ,int y ) {

		NodoMatriz* alv = Raiz;
		while (alv->dato != x)
		{
			alv = alv->der;
		}if (alv->down == NULL)
		{
			alv->down = Nuevo;
			Nuevo->up = alv;

		}

		else {

			while (alv->down != NULL && alv->down->vy<y )
			{
			
				alv = alv->down;
				

			} if (alv->down == NULL)
			{

				alv->down = Nuevo;
				Nuevo->up = alv;

			}
			else if (alv->down != NULL )
			{

		
				NodoMatriz* auxdown = alv->down;
				alv->down = Nuevo;
				Nuevo->up = alv;
				Nuevo->down = auxdown;
				auxdown->up = Nuevo;


			}



	

		}

	}


	void AgregarNodoY(NodoMatriz* Nuevo, int x,int y) {

		NodoMatriz* alv = Raiz;
		while (alv->dato != y)
		{
			alv = alv->down;
		}
		if (alv->der == NULL)
		{
			alv->der = Nuevo;
			Nuevo->izq = alv;

		}
		else {

			while (alv->der != NULL && alv->der->vx < x)
			{
				alv = alv->der;

			} if (alv->der == NULL)
			{

				alv->der = Nuevo;
				Nuevo->izq = alv;

			}
			else if (alv->der!= NULL )
			{

				NodoMatriz* auxder = alv->der;
				alv->der = Nuevo;
				Nuevo->izq = alv;
				Nuevo->der = auxder;
				auxder->izq = Nuevo;


			}



		}


	}
	void Add_X(int x) {
		if (Raiz->der == NULL)
		{
			NodoMatriz* aux = new NodoMatriz(x);

			Raiz->der = aux;

			aux->izq = Raiz;
		}
		else {


			NodoMatriz* aux = Raiz;


			while (aux->der != NULL && aux->der->dato < x)
			{
				aux = aux->der;
			}
			if (aux->der == NULL)
			{
				NodoMatriz* aux2 = new NodoMatriz(x);
				aux->der = aux2;
				aux2->izq = aux;


			}
			else if (aux->der != NULL && aux->der->dato != x)
			{

				NodoMatriz* aux2 = new NodoMatriz(x);
				NodoMatriz* auxder = aux->der;
				aux->der = aux2;
				aux2->izq = aux;
				aux2->der = auxder;
				auxder->izq = aux2;


			}



		}
	}


	void Add_y(int y) {
		if (Raiz->down == NULL)
		{
			NodoMatriz* aux = new NodoMatriz(y);

			Raiz->down = aux;

			aux->up = Raiz;

		}
		else {

			NodoMatriz* aux = Raiz;
			while (aux->down != NULL && aux->down->dato < y)

			{
				aux = aux->down;
			}

			if (aux->down == NULL)
			{
				NodoMatriz* aux2 = new NodoMatriz(y);

				aux->down = aux2;
				aux2->up = aux;

			}
			else if (aux->down != NULL && aux->down->dato != y)
			{

				NodoMatriz* aux2 = new NodoMatriz(y);

				NodoMatriz* auxdown = aux->down;
				aux->down = aux2;
				aux2->up = aux;
				aux2->down = auxdown;
				auxdown->up = aux2;

			}



		}



	}
	void PrintNodos() {

		NodoMatriz* Nuevo = Raiz;
		while (Nuevo->der != NULL)
		{
			cout << Nuevo->dato;
			Nuevo = Nuevo->der;
		}


		cout << Nuevo->dato;
		cout << "\n";



	}
	void PrintRaiz() {

		PrintXRaizx();
		PrintXRaizY();
	}
	void PrintXRaizx() {
		NodoMatriz* Nuevo = Raiz;
		while (Nuevo->der != NULL)
		{
			cout << Nuevo->dato;
			Nuevo = Nuevo->der;
		}


		cout << Nuevo->dato;
		cout << "\n";


	}
	void PrintXRaizY() {
		NodoMatriz* Nuevo = Raiz->down;
		while (Nuevo->down != NULL)
		{
			cout << Nuevo->dato;
			cout << "\n";
			Nuevo = Nuevo->down;

		}

		cout << Nuevo->dato;
		cout << "\n";


	}
	void Grafo() {
		NodoMatriz* actual = Raiz;
		NodoMatriz* actual2;
		NodoMatriz* actual3;
		int pos = 0;
		ofstream archivo;

		archivo.open("ReporteMatriz.txt", ios::out);

		if (archivo.fail())
		{
			cout << "F";

		}

		archivo << "digraph G{ \n"

			<< "  subgraph cluster_0 { \n"
			<< "style = filled;\n"
			<< "		color = lightgrey;\n"
			<< "	node[style = filled,color = white];\n";
		//Recorriendo por la derecha
		archivo << "{rank = same;";
		while (actual->der != NULL)
		{



			archivo << "Nodo" << &*actual << "[ label = \"" << actual->dato <<"\"];" << "\n";
			if (actual->der) {
				archivo << "Nodo" << &*actual << "->";
				archivo << "Nodo" << &*actual->der << "[dir = both]" << ";";
				
			}
		
			actual = actual->der;
		}		archivo << "Nodo" << &*actual << "[ label = \"" << actual->dato << "\"];" << "\n";

		archivo << "}";
		actual = Raiz;
		//Recorriendo por abajo
		while (actual->down != NULL)
		{
			archivo << "Nodo" << &*actual << "[ label = \"" << actual->dato << "\"];" << "\n";
			if (actual->down) {
				archivo << "Nodo" << &*actual << "->";
				archivo << "Nodo" << &*actual->down << "[dir = both]" << ";";
				
			}


			actual = actual->down;
		}		archivo << "Nodo" << &*actual << "[ label = \"" << actual->dato << "\"];" << "\n";





		actual = Raiz;
		while (actual->down != NULL) {
			if (actual->der != NULL && actual != Raiz)
			{
				actual3 = actual;
				archivo << "{rank = same;";
				archivo << "Nodo" << &*actual3 << "[ label = \"" << actual3->dato << "\"];" << "\n";
				while (actual3->der != NULL)
				{


					archivo << "Nodo" << actual3->der << "[ label = \"" << actual3->Prueba << "\"];" << "\n";


					if (actual3->der) {
						archivo << "Nodo" << &*actual3 << "->";
						archivo << "Nodo" << &*actual3->der << "[dir = both]"<<";";

					} actual3 = actual3->der;

					
				} archivo << "}";  archivo << "Nodo" << &*actual3 << "[ label = \"" << actual3->Prueba << "\"];" << "\n";
			}
			actual = actual->down;
		}

		actual = Raiz;
		while (actual->der != NULL) {

			if (actual->down != NULL && actual != Raiz)
			{
				actual2 = actual;
			
				archivo << "Nodo" << &*actual2 << "[ label = \"" << actual2->dato << "\"];" << "\n";
				while (actual2->down != NULL)
				{


					archivo << "Nodo" << actual2->down << "[ label = \"" << actual2->Prueba << "\"];" << "\n";


					if (actual2->down) {
						archivo << "Nodo" << &*actual2 << "->";
						archivo << "Nodo" << &*actual2->down << "[dir = both]" << ";";

					}
					actual2 = actual2->down;


				} archivo << "Nodo" << &*actual2 << "[ label = \"" << actual2->Prueba << "\"  ];" << "\n";
			}
			actual = actual->der;
		}


		archivo << "\n" << "label = " << "MATRIZ\n"
			<< "	;\n} \n }";
		archivo.close();
		char Dot[] = "dot -Tjpg ReporteMatriz.txt -o graphicsMatriz.jpg";
		system(Dot);


	}



















	NodoMatriz* Buscar(int x, int y) {
		NodoMatriz* actual = Raiz;
		NodoMatriz* actual2;
		NodoMatriz* actual3;
		int pos = 0;

		
		


		while (actual->der != NULL) {

			if (actual->down != NULL && actual != Raiz)
			{
				actual2 = actual;
				while (actual2->down != NULL)
				{

					if (x == actual2->vx &&y== actual2->vy )
					{
						cout <<"1"<< actual2->Prueba << "**" << endl;
						return actual2;
					}

					
					actual2 = actual2->down;


				}
			}
			actual = actual->der;
		}
		actual = Raiz;

		while (actual->down != NULL) {

			if (actual->der != NULL && actual != Raiz)
			{
				actual2 = actual;
				while (actual->der != NULL)
				{

					if (x == actual->vx && y == actual->vy)
					{
						cout << "1" << actual->Prueba << "**" << endl;
						return actual;
					}


					actual = actual->der;


				}
			}
			actual = actual->down;
		}




		return actual;


	}

	string BuscarNodo(NodoMatriz* alv , char L) {
		NodoMatriz* actual = Raiz;

		NodoMatriz* actual3;
		int pos = 0;
		string Palabra;
		if (alv->der != NULL && alv->der->Prueba ==L)
		{
			if (alv->izq != NULL)
			{
				Palabra += alv->Prueba;
			}
			while (alv->der != NULL)
			{
				Palabra += alv->der->Prueba;
				alv = alv->der;
			}

		}
		else if (alv->down != NULL && alv->down->Prueba == L)
		{
			cout << "siuu";
			if (alv->up != NULL)
			{
				Palabra += alv->Prueba;
			}
			while (alv->down != NULL)
			{

				Palabra += alv->down->Prueba;
				alv = alv->down;
			}
		}
		
return Palabra;	}

	char BuscarNodoSiguiente(NodoMatriz* alv) {
		NodoMatriz* actual = Raiz;

		NodoMatriz* actual3;
		int pos = 0;
		char Palabra=' ';
		if (alv->der != NULL)
		{
			
			while (alv->der != NULL)
			{
				Palabra = alv->der->Prueba;
				alv = alv->der;
			}

		}
		else if (alv->down != NULL)
		{
			
			while (alv->down != NULL)
			{

				Palabra = alv->down->Prueba;
				alv = alv->down;
			}
		}

		return Palabra;
	}


void  EliminarNodo(NodoMatriz* alv, char PalabraAux) {
	
		if (alv->der!=NULL && alv->der->Prueba==PalabraAux)
		{
			alv->der = NULL;


		}
		if (alv->down != NULL && alv->down->Prueba == PalabraAux)
		{
			alv->down = NULL;


		}
	}
};
	