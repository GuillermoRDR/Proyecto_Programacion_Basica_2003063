#include <iostream>
#include <math.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <wchar.h>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <windows.h>

using namespace std;

//Funciones

void ALTA();
void LISTA();
void ARCHIVO();
void ELIMINAR();
void MODIFICAR();

//Declaracion de variables y punteros(La mayoria punteros)

int nr, *numitem, *año;
float *precio, *iva, *total;
string *nombre, *status, *genero, *clasificacion, *consola, *caracteristicas, *descripcion;

//Funcion Principal

int main()
{
	int opcion;

	system("COLOR BF"); //Asigna un color al fondo y a la fuente(letra) B = Aguamarina Claro y F = Blanco Brillante

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	printf("\t %c%c%c%c MENU DE OPCIONES %c%c%c%c \n", 201, 205, 205, 205, 205, 205, 205, 187);
	printf("\t %c 1.- Alta               %c \n", 186, 186);
	printf("\t %c 2.- Mostrar lista      %c \n", 186, 186);
	printf("\t %c 3.- Limpiar pantalla   %c \n", 186, 186);
	printf("\t %c 4.- Modificar          %c \n", 186, 186);
	printf("\t %c 5.- Eliminar           %c \n", 186, 186);
	printf("\t %c 6.- Salir              %c \n", 186, 186);
	printf("\t %c%c%c%c                  %c%c%c%c \n", 200, 205, 205, 205, 205, 205, 205, 188);
	scanf_s("%d", &opcion);

	switch (opcion)
	{
	case 1:
		ALTA();
		return main();
		break;

	case 2:
		LISTA();
		return main();
		break;

	case 3:
		system("cls");
		return main();
		break;

	case 4:
		MODIFICAR();
		return main();
		break;

	case 5:
		ELIMINAR();
		return main();
		break;

	case 6:
		ARCHIVO();
		break;

	default:
		printf("Ingrese una opcion valida: \n");
		return main();
		break;
	}
}

void ALTA()
{

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	printf("Ingrese el numero de registros que desea dar de alta: \n");
	scanf_s("%d", &nr);
	numitem = new int[nr];
	año = new int[nr];
	precio = new float[nr];
	iva = new float[nr];
	total = new float[nr];
	nombre = new string[nr];
	genero = new string[nr];
	clasificacion = new string[nr];
	consola = new string[nr];
	caracteristicas = new string[nr];
	descripcion = new string[nr];
	status = new string[nr];

	for (int i = 0; i < nr; i++)
	{
		printf("Ingrese el numero de item: \n");
		scanf_s("%d", &numitem[i]);

		for (int j = -1; j < i; j++)
		{
			if (numitem[i] == numitem[j])
			{
				do
				{
					printf("Este numero de Item ya ha sido ingresado, por favor ingrese uno diferente \n");
					scanf_s("%d", &numitem[i]);
				} while (numitem[i] == numitem[j]);
			}
		}
		while (getchar() != '\n');
		printf("Ingrese el nombre: \n");
		getline(cin, nombre[i]);
		printf("Ingrese el a%co de lanzamiento: \n", 164);
		scanf_s("%d", &año[i]);
		while (getchar() != '\n');
		printf("Ingrese el genero: \n");
		getline(cin, genero[i]);
		printf("Ingrese la clasificacion: \n");
		getline(cin, clasificacion[i]);
		printf("Ingrese la consola: \n");
		getline(cin, consola[i]);
		printf("Ingrese las caracteristicas: \n");
		getline(cin, caracteristicas[i]);
		printf("Ingrese la descripcion: \n");
		getline(cin, descripcion[i]);
		printf("Ingrese el precio unitario: \n");
		scanf_s("%f", &precio[i]);
		iva[i] = precio[i] * .16;
		total[i] = precio[i] + iva[i];
	}
}

void LISTA()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	for (int i = 0; i < nr; i++)
	{
		if (status[i] == "ELIMINADO")
		{
			printf("REGISTRO %d ELIMINADO \n", i + 1);
		}
		else
		{
			printf("\t %c%c%c%c                         Registro %d                       %c%c%c%c \n", 201, 205, 205, 205, i + 1, 205, 205, 205, 187);
			printf("\t %c Item: %d \n", 07, numitem[i]);
			printf("\t %c Nombre: %s \n", 07, nombre[i].c_str());
			printf("\t %c A%co de Lanzamiento: %d \n", 07, 164, año[i]);
			printf("\t %c Genero: %s \n", 07, genero[i].c_str());
			printf("\t %c Clasificacion: %s \n", 07, clasificacion[i].c_str());
			printf("\t %c Consola: %s \n", 07, consola[i].c_str());
			printf("\t %c Caracteristicas: %s \n", 07, caracteristicas[i].c_str());
			printf("\t %c Descripcion: %s \n", 07, descripcion[i].c_str());
			printf("\t %c Precio: $ %f \n", 07, precio[i]);
			printf("\t %c IVA: %f \n", 07, iva[i]);
			printf("\t %c TOTAL: $ %f \n", 07, total[i]);

		}
	}
}

void ARCHIVO()
{
	ofstream archivo;
	string nombrearchivo;
	int texto;
	string texto2;
	float texto3;

	nombrearchivo = "Registro de articulos.txt";
	archivo.open(nombrearchivo.c_str(), ios::out);
	if (archivo.fail())
	{
		printf("ERROR: NO SE PUDO CREAR EL ARCHIVO");
		exit(1);
	}

	for (int i = 0; i < nr; i++)
	{
		if (status[i] == "ELIMINADO")
		{
			texto2 = "REGISTRO ELIMINADO";
			texto = i + 1;
			archivo << texto2 << texto << "\n";
		}
		else
		{
			archivo << "Numero de Item: " << "\n";
			texto = numitem[i];
			archivo << texto << "\t" << "\n";
			archivo << "Nombre: " << "\n";
			texto2 = nombre[i];
			archivo << texto2 << "\t" << "\n";
			archivo << "Año de lanzamiento: " << "\n";
			texto = año[i];
			archivo << texto << "\t" << "\n";
			archivo << "Genero: " << "\n";
			texto2 = genero[i];
			archivo << texto2 << "\t" << "\n";
			archivo << "Clasificacion: " << "\n";
			texto2 = clasificacion[i];
			archivo << texto2 << "\t" << "\n";
			archivo << "Consola: " << "\n";
			texto2 = consola[i];
			archivo << texto2 << "\t" << "\n";
			archivo << "Caracteristicas: " << "\n";
			texto2 = caracteristicas[i];
			archivo << texto2 << "\t" << "\n";
			archivo << "Descripcion: " << "\n";
			texto2 = descripcion[i];
			archivo << texto2 << "\t" << "\n";
			archivo << "Precio unitario: " << "\n";
			texto3 = precio[i];
			archivo << texto3 << "\t" << "\n";
			archivo << "IVA: " << "\n";
			texto3 = iva[i];
			archivo << texto3 << "\t" << "\n";
			archivo << "Total: " << "\n";
			texto3 = total[i];
			archivo << texto3 << "\t" << "\n";
		}
	}
	archivo.close();
}

void ELIMINAR()
{
	int registro;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	printf("Ingrese el registro que desea eliminar: \n");
	scanf_s("%d", &registro);
	registro = registro - 1;
	for (int i = registro; i == registro; i++)
	{
		printf("REGISTRO %d ELIMINADO \n", registro + 1);
		printf("\n");
		status[i] = "ELIMINADO";
	}
}

void MODIFICAR()
{
	int regam, opcion, opcion2;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	do
	{
		printf("Ingrese el numero de registro a modificar: \n");
		scanf_s("%d", &regam);
		regam = regam - 1;
		for (int i = regam; i == regam; i++)
		{
			if (status[i] == "ELIMINADO")
			{
				printf("REGISTRO ELIMINADO \n");
				printf("Ingrese un registro valido \n");
				opcion2 = 1;
			}
			else
			{
				opcion2 = 2;
			}
		}
	} while (opcion2 == 1);
	printf("Ingrese que dato desea modificar: \n");
	printf("1.- Numero de item \n");
	printf("2.- Nombre \n");
	printf("3.- A%co de lanzamiento \n", 164);
	printf("4.- Genero \n");
	printf("5.- Clasificacion \n");
	printf("6.- Consola \n");
	printf("7.- Caracteristicas \n");
	printf("8.- Descripcion \n");
	printf("9.- Precio \n");
	scanf_s("%d", &opcion);

	switch (opcion)
	{
	case 1:
		for (int i = regam; i == regam; i++)
		{
			printf("Ingrese el numero de item: \n");
			scanf_s("%d", &numitem[i]);
		}
		break;

	case 2:
		for (int i = regam; i == regam; i++)
		{
			while (getchar() != '\n');
			printf("Ingrese el nombre: \n");
			getline(cin, nombre[i]);
		}
		break;

	case 3:
		for (int i = regam; i == regam; i++)
		{
			printf("Ingrese el a%co de lanzamiento: \n", 164);
			scanf_s("%d", &año[i]);
		}
		break;

	case 4:
		for (int i = regam; i == regam; i++)
		{
			while (getchar() != '\n');
			printf("Ingrese el genero: \n");
			getline(cin, genero[i]);
		}
		break;

	case 5:
		for (int i = regam; i == regam; i++)
		{
			while (getchar() != '\n');
			printf("Ingrese la clasificacion: \n");
			getline(cin, clasificacion[i]);
		}
		break;

	case 6:
		for (int i = regam; i == regam; i++)
		{
			while (getchar() != '\n');
			printf("Ingrese la consola: \n");
			getline(cin, consola[i]);
		}
		break;

	case 7:
		for (int i = regam; i == regam; i++)
		{
			while (getchar() != '\n');
			printf("Ingrese las caracteristicas: \n");
			getline(cin, caracteristicas[i]);
		}
		break;

	case 8:
		for (int i = regam; i == regam; i++)
		{
			while (getchar() != '\n');
			printf("Ingrese la descripcion: \n");
			getline(cin, descripcion[i]);
		}
		break;

	case 9:
		for (int i = regam; i == regam; i++)
		{
			printf("Ingrese el precio: \n");
			scanf_s("%f", &precio[i]);
			iva[i] = precio[i] * 0.16;
			total[i] = precio[i] + iva[i];
		}
		break;

	default:
		printf("Se ingreso una opcion no valida \n");
		break;
	}
}