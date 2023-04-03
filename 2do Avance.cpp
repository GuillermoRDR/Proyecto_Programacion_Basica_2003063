#include <iostream>
#include <math.h>
#include <conio.h> 
#include <stdio.h>
#include <string.h>
#include <string>
#include <wchar.h>

using  namespace std;

struct registro
{
    char nart[20], gen[40], con[40]; //nart es: Nombre del articulo, gen es: Genero del articulo, con es: Consola a la que pertenece el articulo
    string des; //Descripcion del articulo
    int numart; //Numero del articulo

};

int main()
{
    registro art[3]; //Le llame asi porque literalmente es un registro de articulos
    int opcion;

    //Alta de un articulo
    //Modificacion del articulo 
    //Baja de articulo
    //Lista de articulos
    //Limpiar pantalla
    //Salir;

    do
    {
        printf("\t MENU DE OPCIONES \n"); // \t es tabulador
        printf("1. Alta \n");
        printf("2. Modificacion \n");
        printf("3. Baja \n");
        printf("4. Lista \n");
        printf("5. Limpiar Pantalla \n");
        printf("6. Salir \n");
        scanf_s("%d", &opcion);

        switch (opcion)
        {
        case 1: //ALTA
            for (int i = 0; i < 3; i++)
            {
                printf("Ingrese el numero del articulo \n");
                scanf_s("%d", &art[i].numart);
                cin.ignore();
                printf("Ingrese el nombre del articulo \n");
                gets_s(art[i].nart);
                printf("Ingrese la descripcion del articulo \n");
                getline(cin, art[i].des);
                printf("Ingrese genero de item \n");
                gets_s(art[i].gen);
                printf("Ingrese plataforma(s) en la(s) que se encuentra disponible \n");
                gets_s(art[i].con);
            }
            break;
        case 2: //Modificacion de un articulo
            break;

        case 3: //Baja de un articulo
            break;

        case 4: //Lista de articulos
            for (int i = 0; i < 3; i++)
            {
                printf("Numero de articulo: %d \n", art[i].numart);
                printf("Nombre del articulo: %s \n", art[i].nart);
                printf("Descripcion: %s \n", art[i].des.c_str());
                printf("Genero: %s \n", art[i].gen);
                printf("Plataforma(s): %s \n", art[i].con);
            }
            break;

        case 5: // limpiar pantalla
            system("cls");
            break;
        case 6: // cierra la pantalla
            exit(1);
            break;

        }
    } while (opcion != 6);
}