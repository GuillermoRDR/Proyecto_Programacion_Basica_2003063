#include <iostream>
#include <math.h> // calculos matematicos
#include <conio.h> 
#include <stdio.h>
using  namespace std;

int main()
{
    char nombre[40], des[80]{}, gen[40]{}, consola[40]{};
    int nitem = 0, opcion, desicion;

    //alta de calificacion
    //modificacion calificacion 
    //baja de alumno
    //lista
    //limpiar pantalla
    //salir

    cout << "\t ---MENU DE OPCIONES---" << endl;
    cout << "1.-Alta" << endl;
    cout << "2.-Modificacion de ítem" << endl;
    cout << "3.-Baja" << endl;
    cout << "4.-Lista" << endl;
    cout << "5.-Limpiar Pantalla" << endl;
    cout << "6.-Salir" << endl;
    cin >> opcion;

    switch (opcion)
    {
    case 1: //Alta
        cout << "Ingrese numero de item" << endl;
        cin >> nitem;
        cout << "Ingrese nombre de item" << endl;
        cin >> nombre;
        cout << "Descripcion de item" << endl;
        cin >> des;
        cout << "Ingrese genero de item" << endl;
        cin >> gen;
        cout << "Ingrese plataforma(s) en la(s) que se encuentra disponible" << endl;
        cin >> consola;

        //Regresar al menú
        cout << "¿Desea regresar al menu? \n-Ingrese 1 para volver \n-Ingrese 2 para salir" << endl;
        cin >> desicion;
        if (desicion == 1)
        {
            //system("pause");
            return main();
        }
        break;
    case 2: //Modificación de ítem 
        break;

    case 3: //Baja
        break;

    case 4: //Lista
        break;

    case 5: //Limpiar pantalla
        system("cls");
        return main();
        break;
    case 6:
        exit(1); // Cierra la pantalla
        break;

    }
}