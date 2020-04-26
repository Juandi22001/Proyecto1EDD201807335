// Proyecto1EDD_JuanDiego_201807335.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//


#include <iostream>
#include <stdio.h>
#include<stdlib.h>
#include <conio.h>
#include<windows.h>
#include <fstream>
#include "Diccionarios.h"
#include "Score.h"
#include "Usuario.h"
#include "NodoMatriz.h"
#include "Fichas.h"
#include ".json.hpp";
#include <time.h>
using namespace std;

using json = nlohmann :: json;
json totalJSON;
json JSONDobles;
json JSONTriples;
json JSONPalabras;
json diccion;
int dimension = 0;
void EncontrarTriples(json j);
void EncontrarPalabras(json j);
void EncontrarDobles(json j);
Dobles dobles;
Triples triples;
void crear(string);
//Lista de mis usuarios actuales
Usuarios* Us = new Usuarios;
UsuariosJuego UsuarioJ;


ListaMatriz* M = new ListaMatriz;
int punteo1General = 0;
int punteo2General = 0;

void Menu();
void Juego();
void JuegoJugador2();
void AgregarPuntaje();
UsuariosJuego* UserGame = new UsuariosJuego;
char L = ' ';
char L1 = ' ';
char L2 = ' ';
void AgregarPalabras(); 	string jugador1 = "";
string jugador2 = " ";
Diccionarios Dc;
Fichas* F = new Fichas;
FichasAux* Faux = new FichasAux;
int punteoaux1 = 0; 	int punteoaux2 = 0;
void NuevoJuego();
void AgregarUsuarios();
Score score;
Usuarios users;
void VerPuntaje();
Usuario* user = new Usuario; void BuscarPuntaje();

void Buscar(string);

void Direecion();
void gotoxy(short x, short y) {
	COORD pos;
	pos.X = x;
	pos.Y = y;
	HANDLE H;
	H = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(H, pos);
}
int main()
{
	int cont = 0;
	system("color e");

	F->Loco();
	F->Grafo();
	M->Agregar('e', 1, 1);
	M->Agregar('x', 2, 1);

	M->Agregar('y', 3, 1);
	M->Agregar('J', 4, 1);

	M->Agregar('e', 5, 1);


	M->Agregar('r', 3, 2);

	M->Agregar('h', 3, 3);


	M->Agregar('e', 7, 7);


	M->Grafo();

	Dc.Agregar("es"); 	Dc.Agregar("xd");

	Menu();


	/*user->Agregar();
	user->Mostrar();*/
	/*
	M->Agregar('e', 6, 6);

	M->Agregar('e', 12, 10);
	M->Agregar('e', 12, 8);






	M->Agregar('e', 2, 2);






	Dc.Agregar("hola");
	Dc.Agregar("hola3");
	Dc.Agregar("hola4");
	Dc.Agregar("hola");
	Dc.Agregar("hola3");
	Dc.Agregar("hola4");
	Dc.Agregar("hola");
	Dc.Agregar("hola3");
	Dc.Agregar("hola4");
	Dc.Agregar("hola");
	Dc.Agregar("hola3");
	Dc.Agregar("hola4");
	Dc.Agregar("hola");
	Dc.Agregar("hola3");
	Dc.Agregar("hola4");
	Dc.Agregar("hola");
	Dc.Agregar("hola3");
	Dc.Agregar("hola4");
	Dc.Agregar("hola");
	Dc.Agregar("hola3");
	Dc.Agregar("hola4");
	Dc.Agregar("hola");
	Dc.Agregar("hola3");
	Dc.Agregar("hola4");
	Dc.Agregar("hola");
	Dc.Agregar("hola3");
	Dc.Agregar("hola4");
	Dc.Agregar("holar");
	Dc.Grafo();
		*/
	gotoxy(20, 2);
	Menu();

}
void Direccion() {

	string ruta;
	cout << "\n" << "ingrese ruta" << endl;
	cin >> ruta;
	crear(ruta);
	system("cls");
	Menu();
}
void crear(string ruta) {
	std::ifstream archivof(ruta);
	archivof >> totalJSON;
	dimension = totalJSON["dimension"];
	JSONDobles = totalJSON["casillas"]["dobles"];

	JSONTriples = totalJSON["casillas"]["triples"];

	JSONPalabras = totalJSON["diccionario"];
	EncontrarDobles(JSONDobles);
	EncontrarTriples(JSONTriples);
	EncontrarPalabras(JSONPalabras);
	//Obtengo la dimensión del juego

	//--------Obtengo las coordenada x y del doble----------
	cout << "la dimension de la matriz es =" << dimension;

}

void EncontrarDobles(json j) {
	cout << "PalabrasDobles" << "\n";
	for (const auto pos : j) {

		dobles.Agregar(pos["x"], pos["y"]);

	}

}


void EncontrarTriples(json j) {
	cout << "PalabrasTriples" << "\n";
	for (const auto pos : j) {



		triples.Agregar(pos["x"], pos["y"]);


	}

}

void EncontrarPalabras(json j) {

	cout << "Palabras" << "\n";
	for (const auto pos : j) {

		Dc.Agregar(pos["palabra"]);
		Dc.Grafo();

	}

}
void AgregarPuntaje() {
	system("cls");

	gotoxy(20, 2);
	printf("Ingrese Punteo");
	int punteo = 1;
	while (punteo != 0)
	{
		cin >> punteo;

	}
	score.Grafo();
	Menu();
}

void AgregarUsuarios() {
	system("cls");
	gotoxy(20, 5);
	printf("----Ingresar Nuevos Usuarios--\n");

	gotoxy(20, 15);
	printf("----si ya no desea Ingresar Presione 0--\n");

	gotoxy(20, 7);
	printf("Ingrese  Nombre \n");
	cout << "\n";
	string nombre = "";
	while (nombre != "0")
	{

		cin >> nombre;
		if (nombre != "0")
		{
			user->NuevoUser(nombre);

		}

	}
	user->Mostrar();
	system("cls");
	Menu();

}
void AgregarPalabras()
{

	string Palabras;
	gotoxy(20, 2);
	printf("Ingrese Palabras al Diccionario");

	cin >> Palabras;

}

void Menu() {





	gotoxy(20, 2);
	printf("Proyecto1\n");
	gotoxy(20, 3);
	printf("FACULTAD DE INGENIERIA \n");
	gotoxy(20, 4);
	printf("ESTRUCTURA DE DATOS \n");
	gotoxy(20, 5);
	printf("JUAN DIEGO ALVARADO SALGUERO \n");
	gotoxy(20, 6);
	printf("201807335 \n");

	gotoxy(25, 12);
	printf("-----Menu--- \n");
	gotoxy(25, 13);
	printf("1.Ingresar Jugadores  \n");
	gotoxy(25, 14);
	printf("2.NuevoJuego \n");
	gotoxy(25, 15);
	printf("3.Ver Puntaje \n");
	gotoxy(25, 16);
	printf("4. Buscar Puntaje \n");
	gotoxy(25, 17);
	printf("5. Ingresar Jugadores \n");
	gotoxy(25, 18);
	printf("6. Ingresar Jugadores \n");
	gotoxy(25, 19);
	printf("7. Ingresar Jugadores \n");
	gotoxy(25, 20);
	printf("Escoja Opcion \n");

	gotoxy(25, 22);
	int opcion;
	std::cin >> opcion;

	switch (opcion) {

	case 1:
		AgregarUsuarios();
		system("cls");


		break;

	case 2:
		system("cls");
		NuevoJuego();
		break;
	case 3:
		VerPuntaje();
		system("cls");
		break;
	case 4:
		BuscarPuntaje();
		system("cls");
		break;


	case 5:



		Direccion();
		break;

	}

}
void NuevoJuego() {

	int punteo1 = 0;

	int punteo2 = 0;

	gotoxy(20, 2);
	printf("-----------------------JUEGO NUEVOOO----------\n");
	gotoxy(20, 3);
	printf("Ingrese Nuevo Jugador\n");
	cin >> jugador1;

	cout << "jugador aceptado" << endl;


	printf("Ingrese Nuevo Jugador\n");
	cin >> jugador2;


	//Lista de mis usuarios actuales
	UsuarioJ.Agregar(jugador1);

	UsuarioJ.Agregar(jugador2);


	UsuarioJ.getPrimero()->ListaFichas.Agregar(F->getFirst()->Fichass, F->getFirst()->Valor);
	F->Borrar();

	UsuarioJ.getPrimero()->ListaFichas.Agregar(F->getFirst()->Fichass, F->getFirst()->Valor);
	F->Borrar();

	UsuarioJ.getPrimero()->ListaFichas.Agregar(F->getFirst()->Fichass, F->getFirst()->Valor);
	F->Borrar();

	UsuarioJ.getPrimero()->ListaFichas.Agregar(F->getFirst()->Fichass, F->getFirst()->Valor);
	F->Borrar();

	UsuarioJ.getPrimero()->ListaFichas.Agregar(F->getFirst()->Fichass, F->getFirst()->Valor);
	F->Borrar();

	UsuarioJ.getPrimero()->ListaFichas.Agregar(F->getFirst()->Fichass, F->getFirst()->Valor);
	F->Borrar();

	cout << "\n" << "Fichas Jugador1" << "\n";


	cout << UsuarioJ.getPrimero()->ListaFichas.Ver();
	system("pause");

	UsuarioJ.getPrimero()->siguiente->ListaFichas.Agregar(F->getFirst()->Fichass, F->getFirst()->Valor);
	F->Borrar();
	UsuarioJ.getPrimero()->siguiente->ListaFichas.Agregar(F->getFirst()->Fichass, F->getFirst()->Valor);
	F->Borrar();
	UsuarioJ.getPrimero()->siguiente->ListaFichas.Agregar(F->getFirst()->Fichass, F->getFirst()->Valor);
	F->Borrar();
	UsuarioJ.getPrimero()->siguiente->ListaFichas.Agregar(F->getFirst()->Fichass, F->getFirst()->Valor);
	F->Borrar();
	UsuarioJ.getPrimero()->siguiente->ListaFichas.Agregar(F->getFirst()->Fichass, F->getFirst()->Valor);
	F->Borrar();
	UsuarioJ.getPrimero()->siguiente->ListaFichas.Agregar(F->getFirst()->Fichass, F->getFirst()->Valor);
	F->Borrar();
	UsuarioJ.getPrimero()->siguiente->ListaFichas.Agregar(F->getFirst()->Fichass, F->getFirst()->Valor);
	F->Borrar();

	cout << "\n" << "Fichas Jugador2" << "\n";


	cout << UsuarioJ.getPrimero()->siguiente->ListaFichas.Ver();
	system("pause");

	cout << "\n";

	system("cls");


	int dato;
	dato = 1 + rand() % (2);
	if (dato == 1)
	{
		Juego();

	}
	else if (dato == 2)
	{
		JuegoJugador2();
	}



}
void Juego() {
	int escojer = 2;
	int opcion;
	string opcion2 = "";
	int punteoJugador1;

	printf("Escoja Opcion Jugador1 \n");
	printf("1.CambioFichas \n");
	printf("2.Ingresar Datos Matriz \n");
	std::cin >> opcion;

	if (opcion == 1)
	{



		do {
			printf("IngreseFichas \n");
			L = _getch();

			cout << L << endl;
			F->Agregar(L, 9);
			UsuarioJ.getPrimero()->ListaFichas.Eliminar(L);
			UsuarioJ.getPrimero()->ListaFichas.Agregar(F->getFirst()->Fichass, F->getFirst()->Valor);
			cout << "\n" << UsuarioJ.getPrimero()->ListaFichas.Ver();
		} while (L != '0');
		JuegoJugador2();
	}
	else if (opcion == 2)
	{
		int cordenadaxBuscar;
		int cordenadayBuscar;
		cout << "Ingrese cordenada en x donde  empezara a escribir" << endl;
		cin >> cordenadaxBuscar;

		cout << "Ingrese cordenada en y  donde quiere ingresar" << endl;
		cin >> cordenadayBuscar;


		cout << "\n";

		cout << "\n";

		cout << "\n";

		int contaux = 0;
		cout << "\n" << UsuarioJ.getPrimero()->ListaFichas.Ver();

		cout << "Ingrese Ficha" << endl;
		L1 = _getch();

		cout << L1 << endl;
		if (UsuarioJ.getPrimero()->ListaFichas.BuscarValidar(L1) == true)
		{
			int cx;
			int cy;
			cout << "Ingrese cordenada en x donde quiere ingresar" << endl;
			cin >> cx;

			cout << "Ingrese cordenada en y  donde quiere ingresar" << endl;
			cin >> cy;
			punteoaux1 = punteoaux1 + UsuarioJ.getPrimero()->ListaFichas.BuscarValor(L1);
			if (dobles.Buscar(cx, cy) == true)
			{
				punteoaux1 = punteoaux1 * 2;

			}
			if (triples.Buscar(cx, cy) == true)
			{
				punteoaux1 = punteoaux1 * 3;

			}
			M->Agregar(L1, cx, cy);
			M->Grafo();
			cout << "valor" << UsuarioJ.getPrimero()->ListaFichas.BuscarValor(L1);
			UsuarioJ.getPrimero()->ListaFichas.Eliminar(L1);
			cout << "\n" << UsuarioJ.getPrimero()->ListaFichas.Ver() << endl;


			Faux->Agregar(L1, UsuarioJ.getPrimero()->ListaFichas.BuscarValor(L1));


			//aqui va ir el if de las fichas dobles

			cout << "El punteo de esa ficha es" << punteoaux1 << endl;

			contaux++;
		}
		else
		{
			punteoaux1 = 0;
			cout << "no tiene la ficha";
			system("pause");
			system("cls");
			JuegoJugador2();
		}
		cout << " si ya no desea seguir presione 0" << endl;

		cin >> escojer;

		if (escojer == 0)
		{
			cout << "fin";
		}
		else {
			do
			{
				cout << "\n" << UsuarioJ.getPrimero()->ListaFichas.Ver();

				cout << "Ingrese Ficha" << endl;
				L = _getch();

				cout << L << endl;
				punteoaux1 = punteoaux1 + UsuarioJ.getPrimero()->ListaFichas.BuscarValor(L);
				if (UsuarioJ.getPrimero()->ListaFichas.BuscarValidar(L) == true)
				{
					int cx;
					int cy;
					cout << "Ingrese cordenada en x donde quiere ingresar" << endl;
					cin >> cx;

					cout << "Ingrese cordenada en y  donde quiere ingresar" << endl;
					cin >> cy;
					if (dobles.Buscar(cx, cy) == true)
					{
						punteoaux1 = punteoaux1 * 2;

					}
					if (triples.Buscar(cx, cy) == true)
					{
						punteoaux1 = punteoaux1 * 3;

					}
					M->Agregar(L, cx, cy);
					M->Grafo();
					cout << "valor" << UsuarioJ.getPrimero()->ListaFichas.BuscarValor(L);
					UsuarioJ.getPrimero()->ListaFichas.Eliminar(L);
					cout << "\n" << UsuarioJ.getPrimero()->ListaFichas.Ver() << endl;


					Faux->Agregar(L, UsuarioJ.getPrimero()->ListaFichas.BuscarValor(L));

					cout << "El punteo de esa ficha es" << punteoaux1 << endl;
					contaux++;
				}
				else
				{
					punteoaux1 = 0;
					cout << "no tiene la ficha";
					system("pause");
					system("cls");
					JuegoJugador2();
				}

				cout << "\n" << " si ya no desea seguir presione 0" << endl;

				cin >> escojer;


			} while (escojer != 0);
		}

		NodoMatriz* Aux = M->Buscar(cordenadaxBuscar, cordenadayBuscar);
		cout << "\n";
		cout << "letra encontrada" << M->Buscar(cordenadaxBuscar, cordenadayBuscar)->Prueba << endl;
		cout << "palabra encontrada" << M->BuscarNodo(Aux, L1) << endl;


		if (Dc.Buscar(M->BuscarNodo(Aux, L1)) == true)
		{
			cout << "Palabra Aceptada" << endl;
			punteo1General = punteo1General + punteoaux1;
			cout << "su punteo actual es" << punteo1General << endl;
			punteoaux1 = 0;
			contaux = 0;
		}
		else {
			cout << "las letras que ingreso no son correctas " << endl;
			M->EliminarNodo(Aux, L1);
			M->Grafo();
			punteoaux1 = 0;
			for (size_t i = 0; i < contaux; i++)
			{
				UsuarioJ.getPrimero()->ListaFichas.Agregar(Faux->getFirst()->FichasAuxs, Faux->getFirst()->Valor);

				Faux->Borrar();

			}
			cout << "Tiene estas fichas " << UsuarioJ.getPrimero()->ListaFichas.Ver();
			contaux = 0;
			punteoaux1 = 0;
		}
		system("pause");
		system("cls");
		JuegoJugador2();

	}



}
void JuegoJugador2() {
	int opcion2; int escojer = 2;
	printf("Escoja Opcion Jugador2 \n");
	printf("1.CambioFichas \n");
	printf("2.Ingresar Datos Matriz \n");

	std::cin >> opcion2;

	if (opcion2 == 1)
	{

		do {
			printf("IngreseFichas jugador2 \n");
			L = _getch();

			cout << L << endl;
			F->Agregar(L, 9);
			UsuarioJ.getPrimero()->siguiente->ListaFichas.Eliminar(L);
			UsuarioJ.getPrimero()->siguiente->ListaFichas.Agregar(F->getFirst()->Fichass, F->getFirst()->Valor);

			cout << UsuarioJ.getPrimero()->siguiente->ListaFichas.Ver();
		} while (L != '0');
		Juego();


	}

	else if (opcion2 == 2)
	{

		int cordenadaxBuscar;
		int cordenadayBuscar;
		cout << "Ingrese cordenada en x donde  empezara a escribir" << endl;
		cin >> cordenadaxBuscar;

		cout << "Ingrese cordenada en y  donde quiere ingresar" << endl;
		cin >> cordenadayBuscar;


		cout << "\n";



		int contaux = 0;
		cout << "\n" << UsuarioJ.getPrimero()->siguiente->ListaFichas.Ver();

		cout << "Ingrese Ficha" << endl;
		L2 = _getch();

		cout << L2 << endl;

		if (UsuarioJ.getPrimero()->siguiente->ListaFichas.BuscarValidar(L2) == true)
		{
			int cx;
			int cy;
			cout << "Ingrese cordenada en x donde quiere ingresar" << endl;
			cin >> cx;

			cout << "Ingrese cordenada en y  donde quiere ingresar" << endl;
			cin >> cy; punteoaux2 = punteoaux2 + UsuarioJ.getPrimero()->siguiente->ListaFichas.BuscarValor(L2);

			if (dobles.Buscar(cx, cy) == true)
			{
				punteoaux2 = punteoaux2 * 2;

			}
			if (triples.Buscar(cx, cy) == true)
			{
				punteoaux2 = punteoaux2 * 3;

			}
			M->Agregar(L2, cx, cy);
			M->Grafo();
			UsuarioJ.getPrimero()->siguiente->ListaFichas.Eliminar(L2);
			cout << "\n" << UsuarioJ.getPrimero()->siguiente->ListaFichas.Ver() << endl;
			Faux->Agregar(L2, UsuarioJ.getPrimero()->siguiente->ListaFichas.BuscarValor(L2));
			cout << " la ficha tiene ese punteo:" << punteoaux2 << endl;
			contaux++;
		}



		else
		{
			punteoaux2 = 0;
			cout << "no tiene la ficha";
			system("pause");
			system("cls");
			Juego();
		}
		cout << " si ya no desea seguir presione 0" << endl;

		cin >> escojer;
		if (escojer == 0)
		{
			cout << "fin";
		}
		else {
			do
			{
				cout << "\n" << UsuarioJ.getPrimero()->siguiente->ListaFichas.Ver();

				cout << "Ingrese Ficha" << endl;
				L = _getch();

				cout << L << endl;

				if (UsuarioJ.getPrimero()->siguiente->ListaFichas.BuscarValidar(L) == true)
				{
					int cx;
					int cy;
					cout << "Ingrese cordenada en x donde quiere ingresar" << endl;
					cin >> cx;

					cout << "Ingrese cordenada en y  donde quiere ingresar" << endl;
					cin >> cy; 	punteoaux2 = punteoaux2 + UsuarioJ.getPrimero()->siguiente->ListaFichas.BuscarValor(L);

					if (dobles.Buscar(cx, cy) == true)
					{
						punteoaux2 = punteoaux2 * 2;

					}
					if (triples.Buscar(cx, cy) == true)
					{
						punteoaux2 = punteoaux2 * 3;

					}

					M->Agregar(L, cx, cy);
					M->Grafo();
					UsuarioJ.getPrimero()->siguiente->ListaFichas.Eliminar(L);
					cout << "\n" << UsuarioJ.getPrimero()->siguiente->ListaFichas.Ver() << endl;
					Faux->Agregar(L, UsuarioJ.getPrimero()->siguiente->ListaFichas.BuscarValor(L));
					cout << " la ficha tiene ese punteo:" << punteoaux2 << endl;
					contaux++;
				}
				else
				{
					punteoaux2 = 0;
					cout << "no tiene la ficha";
					system("pause");
					system("cls");
					Juego();
				}

				cout << " si ya no desea seguir presione 0" << endl;

				cin >> escojer;


			} while (escojer != 0);

		}
		NodoMatriz* Aux = M->Buscar(cordenadaxBuscar, cordenadayBuscar);
		cout << "letra encontrada" << M->Buscar(cordenadaxBuscar, cordenadayBuscar)->Prueba << endl;
		cout << "palabra encontrada" << M->BuscarNodo(Aux, L2) << endl;


		if (Dc.Buscar(M->BuscarNodo(Aux, L2)) == true)
		{
			punteo2General = punteo2General + punteoaux2;
			cout << "su punteo hasta ahora es:" << punteo2General << endl;
			cout << "Palabra Aceptada" << endl;

			contaux = 0;

			punteoaux2 = 0;
		}
		else {
			cout << "no esta esa palabra  matriz en el diccionario" << endl;
			punteoaux2 = 0;
			M->EliminarNodo(Aux, L2);
			M->Grafo();
			for (size_t i = 0; i < contaux; i++)
			{
				UsuarioJ.getPrimero()->siguiente->ListaFichas.Agregar(Faux->getFirst()->FichasAuxs, Faux->getFirst()->Valor);

				Faux->Borrar();

			}
			cout << UsuarioJ.getPrimero()->siguiente->ListaFichas.Ver();
			contaux = 0;

		}
		cout << "desea salir ya?" << endl;
		int op = 3;
		cin >> op;
		if (op == 0)
		{
			system("cls");
			users.Agregar(jugador1);
			users.Agregar(jugador2);

			users.getPrimero()->Punteo.Agregar(punteo1General);
			users.getPrimero()->Punteo.Grafo();

			cout << "jugador1 su punteo es=" << punteo1General;
			system("pause");
			users.getPrimero()->sig->Punteo.Agregar(punteo2General);
			users.getPrimero()->sig->Punteo.Grafo();

			cout << "jugador2 su punteo es=" << punteo2General;
			system("pause");
			if (punteo1General > punteo2General)
			{
				cout << "gano jugador 1" << "---" << jugador1;
				score.AgregarInicio(punteo1General, jugador1);
				score.Grafo();
				system("pause");
				system("cls");
				Menu();
			}
			else if (punteo2General > punteo1General) {

				cout << "gano jugador 2" << "---" << jugador2;
				score.AgregarInicio(punteo2General, jugador2);
				score.Grafo();
				system("pause");
				system("cls");
				Menu();

			}


		}
		system("cls");

		Juego();

	}
}

void BuscarPuntaje() {
	string a;
	cout << "ingrese su nombre";
	cin >> a;
	score.Buscar(a);
}
void VerPuntaje() {
	score.Grafo();
	score.Ver();
	system("pause");
	Menu();
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
