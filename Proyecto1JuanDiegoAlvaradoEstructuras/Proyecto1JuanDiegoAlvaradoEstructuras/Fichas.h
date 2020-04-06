
#pragma once
#include <iostream>
#include <stdio.h>
#include<stdlib.h>
#include <conio.h>
#include<windows.h>
#include <fstream>
void gotoxy3(short x, short y) {
	COORD pos;
	pos.X = x;
	pos.Y = y;
	HANDLE H;
	H = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(H, pos);
}



using namespace std;
class Fichas
{
private:
	Fichas* First;
	Fichas* Last;

public:
	Fichas* siguiente;
	string Usuario;
	char Fichass;
	Fichas();
	void Eliminar(Fichas* First, Fichas* Last, int valor, char c);
	Fichas(char Fichass,int valor);
	void Loco();

	bool Vacia(Fichas*);
	void Agregar(char Fichass,int  valor);
	void Borrar();
	void Grafo();
	int Valor;
	inline Fichas* getLast() {
		return this->Last;

	}; 
	
	
	inline int getLValor() {
		return this->Valor;
		
	};
	inline Fichas* getFirst() {
		return First;
	};
};


Fichas::Fichas() {
	siguiente = NULL;
	Fichass = ' ';
	Usuario = "";
	Last = NULL;
	Valor = 0;
	First = NULL;
}
Fichas::Fichas(char F, int valor) {
	Fichass = F;
	Valor = valor;
	siguiente = NULL;
}

void Fichas::Agregar(char Fichass, int valor) {
	Fichas* nuevoNodo = new Fichas(Fichass, valor);
	if (Vacia(this->First)==true)
	{
		this->First = nuevoNodo;
	}
	else {
		this->Last->siguiente = nuevoNodo;
	}
	this->Last = nuevoNodo;
}
void Fichas::Borrar() {

	
	Eliminar(First, Last, Valor, Fichass);

	
}

void Fichas::Eliminar(Fichas* First , Fichas* Last,int valor ,char c) {
	
	valor = First->Valor;
	c = First->Fichass;
	Fichas* alv = this->First;
	if (this->First == this->Last)
	{
		this->First = NULL;
		this->Last = NULL;
	}
	else {
		this->First = this->First->siguiente;

	}
	delete alv;

}
bool Fichas::Vacia(Fichas* aux) {
	return(aux == NULL) ?
		true : false;
}void Fichas::Loco() {



	Agregar('s', 1);
	Agregar('c', 3);

	Agregar('x', 3);

	Agregar('h', 4);
	Agregar('a', 1); 



	Agregar('b', 3);

	Agregar('n', 1);






	Agregar('e', 1);
	Agregar('r', 1);
	Agregar('i', 1);

	Agregar('a', 1);


	Agregar('d', 2);

	Agregar('a', 1);
	Agregar('r', 1); Agregar('g', 2); Agregar('s', 1);
	Agregar('x', 8);

	Agregar('o', 1);
	Agregar('d', 2);

	Agregar('a', 1);	Agregar('o', 1);


	Agregar('r', 1);
	Agregar('a', 1); Agregar('r', 1);


	Agregar('a', 1);	Agregar('o', 1);
	Agregar('t', 1);

	Agregar('e', 1); Agregar('h', 4);

	Agregar('d', 2);
	Agregar('f', 4);

	Agregar('p', 3);

	Agregar('e', 1);	Agregar('o', 1);

	Agregar('c', 3);

	Agregar('i', 1); Agregar('s', 1);
	Agregar('t', 1); Agregar('r', 1);


	Agregar('l', 1);
	Agregar('c', 3);
	Agregar('e', 1); Agregar('y', 4); Agregar('f', 4);
	Agregar('n', 1);
	Agregar('u', 1);
	Agregar('e', 1);
	Agregar('e', 1);	Agregar('o', 1);
	Agregar('g', 2);
	Agregar('n', 1);
	Agregar('s', 1);


	Agregar('a', 1); Agregar('r', 1);
	Agregar('e', 1);



	Agregar('d', 2);

	Agregar('l', 1);
	Agregar('e', 1); Agregar('s', 1);


	Agregar('n', 1);

	Agregar('i', 1);	Agregar('q', 5);
	Agregar('e', 1);
	Agregar('a', 1);
	Agregar('d', 2);

	Agregar('m', 3);
	Agregar('v', 8); Agregar('g', 2);

	Agregar('b', 3);






	Agregar('o', 1);




	Agregar('t', 1); Agregar('z', 10);
	Agregar('i', 1);
	Agregar('u', 1);
	Agregar('j', 8);
	Agregar('n', 1);
	Agregar('l', 1);
	Agregar('u', 1);
	Agregar('b', 3);
	Agregar('u', 1);
	Agregar('b', 3);

	Agregar('a', 1); Agregar('g', 2);

	Agregar('i', 1);
	Agregar('e', 1); Agregar('r', 1);


	Agregar('l', 1);




	Agregar('t', 1); Agregar('r', 1);
	Agregar('i', 1);
	Agregar('l', 1);

	Agregar('a', 1);




	Agregar('r', 1);


	Agregar('a', 1);
	Agregar('e', 1);


	Agregar('l', 1);


	Agregar('n', 1);


	Agregar('c', 3);

	Agregar('r', 1);

	Agregar('o', 1); Agregar('s', 1);
	Agregar('e', 1);



	Agregar('a', 1);
}

void Fichas::Grafo() {
	Fichas* actual = this->First;
	Fichas* aux2 = new Fichas();
	int pos = 0;
	ofstream archivo;

	archivo.open("ReporteFichas.txt", ios::out);

	if (archivo.fail())
	{
		cout << "F";

	}

	archivo << "digraph Fichas{ \n"
		<< "  	rankdir = LR;  \n"
		<< "  subgraph cluster_0 { \n"
		<< "style = filled;\n"
		<< "		color = lightgrey;\n"
		<< "	node[style = filled,color = white];\n";
	do {
		archivo << "Nodo" << &*actual << "[ label = \"" << actual->Fichass << "\" ];\n";
		if (actual->siguiente) {
			archivo << "Nodo" << &*actual << "->";
			archivo << "Nodo" << &*actual->siguiente << ";";
		}
		actual = actual->siguiente;

	} while (actual != NULL);
	archivo << "\n" << "label = " << "Lista1 #1\n"
		<< "	;\n} \n }";


	archivo.close();
	char Dot[] = "dot -Tjpg ReporteFichas.txt -o graphicsFichass.jpg";
	system(Dot);


}

class FichasAux
{
private:
	FichasAux* First;
	FichasAux* Last;

public:
	FichasAux* siguiente;
	string Usuario;
	char FichasAuxs;
	FichasAux();
	void Eliminar(FichasAux* First, FichasAux* Last, int valor, char c);
	FichasAux(char FichasAuxs, int valor);


	bool Vacia(FichasAux*);
	void Agregar(char FichasAuxs, int  valor);
	void Borrar();
	int Valor;
	inline FichasAux* getLast() {
		return this->Last;

	};


	inline int getLValor() {
		return this->Valor;

	};
	inline FichasAux* getFirst() {
		return First;
	};
};


FichasAux::FichasAux() {
	siguiente = NULL;
	FichasAuxs = ' ';
	Usuario = "";
	Last = NULL;
	Valor = 0;
	First = NULL;
}
FichasAux::FichasAux(char F, int valor) {
	FichasAuxs = F;
	Valor = valor;
	siguiente = NULL;
}

void FichasAux::Agregar(char FichasAuxs, int valor) {
	FichasAux* nuevoNodo = new FichasAux(FichasAuxs, valor);
	if (Vacia(this->First) == true)
	{
		this->First = nuevoNodo;
	}
	else {
		this->Last->siguiente = nuevoNodo;
	}
	this->Last = nuevoNodo;
}
void FichasAux::Borrar() {


	Eliminar(First, Last, Valor, FichasAuxs);


}

void FichasAux::Eliminar(FichasAux* First, FichasAux* Last, int valor, char c) {

	valor = First->Valor;
	c = First->FichasAuxs;
	FichasAux* alv = this->First;
	if (this->First == this->Last)
	{
		this->First = NULL;
		this->Last = NULL;
	}
	else {
		this->First = this->First->siguiente;

	}
	delete alv;

}
bool FichasAux::Vacia(FichasAux* aux) {
	return(aux == NULL) ?
		true : false;
}
static class FichasUsuario
{
private:
	

public:
	FichasUsuario* siguiente;
	FichasUsuario* anterior;
	char Letra;

	FichasUsuario();
	FichasUsuario(char Letra,int valor);
	int Valor;
	Fichas* Ficha;

	inline Fichas* getFicha() {
		return Ficha;

	};
	inline char getLetra() {
		return Letra;

	};

	inline int getValor() {
		return Valor ;

	};
	
};



FichasUsuario::FichasUsuario() {
	anterior = NULL;
	siguiente = NULL;
	Letra = ' ' ;
	Valor = 0;
	
}
FichasUsuario::FichasUsuario( char L,int valor) {
	Valor = valor;
	Letra = L;
	anterior = NULL;
	siguiente = NULL;
}

class ListaFichasUsuario {
public:
	FichasUsuario* Primero;
	FichasUsuario* Ultimo;
	ListaFichasUsuario () {

		Primero = NULL;
		Ultimo = NULL;
	}
string Ver() {
		FichasUsuario* actual = this->Primero;

		string a=" ";
		int contador = 0;
		while (actual != NULL)
		{
	
		a += actual->Letra;
			actual = actual->siguiente;
		}
		return a;
	}
int Ver2() {
	FichasUsuario* actual = this->Primero;

	int a=0;
	int contador = 0;
	while (actual != NULL)
	{

		cout << actual->getValor();
		a++;
		actual = actual->siguiente;
	}
	return a;
}
	void Agregar(char L, int Valor) {
		FichasUsuario* nuevoNodo = new FichasUsuario(L, Valor);

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
	void Eliminar(char s) {
		FichasUsuario* alv = this->Primero;	
		FichasUsuario* alv2 = new FichasUsuario();

		while (alv!=NULL)
		{

	
			if (alv->Letra==s)
			{
				alv2 = alv;
				cout << "--econtrada" << endl;
				if (alv==this->Primero)
				{
					cout << "--principio" << endl;

					this->Primero = alv->siguiente;
					system("pause");
				}
				else if (alv->siguiente==NULL)
				{
					alv->anterior = this->Ultimo;

				}
				else {


					alv->siguiente->anterior = alv->anterior;
					alv->anterior->siguiente = alv->siguiente;
				}
			}
			alv = alv->siguiente;
		}

	}
	bool BuscarValidar(char s) {
		bool a = false;
		FichasUsuario* alv = this->Primero;
		FichasUsuario* aux = new FichasUsuario();
		FichasUsuario* aux2 = new FichasUsuario();


		while (alv!=NULL)
		{

			if (alv->Letra==s)
			{
				a = true;
			}

			alv = alv->siguiente;
		}
		return a;
	}

	int BuscarValor(char s) {
		int a2 = 1;
		FichasUsuario* alv = this->Primero;
		FichasUsuario* aux = new FichasUsuario();
		FichasUsuario* aux2 = new FichasUsuario();

	
		while (alv != NULL)
		{

			if (alv->Letra == s)
			{
				
				int a  =alv->Valor;
				return a;
			}

			alv = alv->siguiente;
		}
		return a2;
	}
	void Grafo() {
		FichasUsuario* actual = this->Primero;

		int pos = 0;
		ofstream archivo;

		archivo.open("ReporteFichasUsuario.txt", ios::out);

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
		char Dot[] = "dot -Tjpg ReporteFichasUsuario.txt -o graphFichasUsuario.jpg";
		system(Dot);


	}

};








static class UsuariosJuego
{
private:
	UsuariosJuego* Primero;
	UsuariosJuego* Ultimo;
	FichasUsuario Fichas;
	
public:
	ListaFichasUsuario ListaFichas;
	UsuariosJuego* siguiente;
	UsuariosJuego* anterior;
	char Letra;
FichasUsuario* F= new FichasUsuario;
	UsuariosJuego();
	UsuariosJuego(string Letra);

	string Nombre;

	void Ver();
	void Agregar(string Letra);
	void Grafo();
	
	void Buscar(char B[], char Remplazo[]);


	inline UsuariosJuego* getPrimero() {
		return this->Primero;
	};
	void serPrimero(FichasUsuario* F) {
		this->F=F;
	};

};



UsuariosJuego::UsuariosJuego() {
	anterior = NULL;
	siguiente = NULL;
	Nombre = "";
	Primero = NULL;
	Ultimo = NULL;
}
UsuariosJuego::UsuariosJuego(string L ) {
	Nombre = L;
	
	anterior = NULL;
	siguiente = NULL;
}

void UsuariosJuego::Agregar(string Nombre ) {
	UsuariosJuego* nuevoNodo = new UsuariosJuego(Nombre);

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
void UsuariosJuego::Ver() {
	UsuariosJuego* actual = this->Primero;


	int contador = 0;
	while (actual != NULL)
	{
		gotoxy2(4, 2);

		actual = actual->siguiente;
	}

}
void UsuariosJuego::Buscar(char  Busqueda[], char Remplazo[]) {

	UsuariosJuego* actual = this->Primero;
	UsuariosJuego* aux = new UsuariosJuego();
	UsuariosJuego* aux2 = new UsuariosJuego();


	//	UsuariosJuego* nuevoNodo = new UsuariosJuego(L);


	string PalabraBusqueda = Busqueda;
	string recol = "";

	int cont = 0;
	while (actual != NULL) {
		recol += actual->Letra;

		if (recol.compare(PalabraBusqueda) == 0) {
			aux = actual;

			for (int i = 0; i < recol.size(); i++)
			{

				if (actual->anterior == NULL)
				{
					cout << "primer nodo";
					this->Primero = aux->siguiente;


				}
				else if (aux->siguiente == NULL)
				{
					actual->anterior = this->Ultimo;
					this->Ultimo->siguiente = NULL;

				}
				else {
					actual->anterior->siguiente = aux->siguiente;
					aux->siguiente->anterior = aux->anterior;
				}



				actual = actual->anterior;
			}
		

			Grafo();

		}
		else	 if (actual->Letra == ' ')
		{

			recol = "";

		}

		if (actual != NULL)
		{
			actual = actual->siguiente;
		}
	}

}
/*
void UsuariosJuego::Buscar(char  Busqueda [],char Remplazar  []) {
	UsuariosJuego* actual = this->Primero;
	int cont=0 ;
	string PalabraBusqueda = Busqueda;
	UsuariosJuego* nuevoNodo = new UsuariosJuego(Remplazar);
	string recolectorLetras = "";
	do {

		recolectorLetras += actual->Letra;
		for (size_t i = 0; i < PalabraBusqueda.size(); i++)
		{
			recolectorLetras += actual->Letra;
			if (actual->Letra == PalabraBusqueda[i])
			{



				cont++;

				if (cont == PalabraBusqueda.size() )
				{
					cout << "		 PALABRA ENCONTRADA: " << palabraEncontrada<<endl;
					/*for (size_t i = 0; i <sizeof(actual->Letra); i++)
					{
						if (actual->anterior==NULL)
						{
							this->Primero = actual->siguiente;
						}
						else if (actual->siguiente == NULL) {
							this->Ultimo = actual->anterior;
						}else{
						actual->anterior->siguiente = actual->siguiente;
						actual->siguiente->anterior = actual->anterior;

						cont = 0;
						}

					}
					for (size_t i = 0; i < (sizeof(Remplazar) / 2); i++)
					{
						actual->siguiente->anterior = nuevoNodo;

						nuevoNodo->siguiente = actual->siguiente;
						nuevoNodo->anterior = actual;
					}
					cout << "\n";
					Ver();

				}
				actual = actual->siguiente;
			}
			else {



				cont = 0;
				actual = actual->siguiente;
				break;
			}


		}

		if (actual!=NULL)
		{
			actual = actual->siguiente;
		}
	} while (actual != NULL);


}
void UsuariosJuego::Remplazar(UsuariosJuego* Actual, UsuariosJuego* aux, char R[]) {
	UsuariosJuego Lista;
	for (size_t i = 0; i < sizeof(R); i++)
	{
		Lista.Agregar(R[i]);

		if (Actual == NULL)
		{
			this->Primero = Lista.getPrimero();
			Lista.getUltimo()->siguiente = aux->siguiente;

		}
		else if (aux->siguiente == NULL)
		{
			Actual->anterior = Lista.getPrimero();
			Lista.getPrimero()->anterior = Actual->anterior;

		}

		else {



			Actual->siguiente = Lista.getPrimero();
			Lista.getPrimero()->anterior = Actual;
			Lista.getUltimo()->siguiente = aux->siguiente;
			aux->siguiente->anterior = Lista.getUltimo();



		}
	}




}*/
void UsuariosJuego::Grafo() {
	UsuariosJuego* actual = this->Primero;
	UsuariosJuego* aux2 = new UsuariosJuego();
	int pos = 0;
	ofstream archivo;

	archivo.open("ReporteJugador.txt", ios::out);

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
		archivo << "Nodo" << &*actual << "[ label = \"" << actual->Nombre << "\" ];\n";
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
	char Dot[] = "dot -Tjpg ReporteJugador.txt -o graphJugador.jpg";
	system(Dot);


}



