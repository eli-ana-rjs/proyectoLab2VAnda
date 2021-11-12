#include "menuPrincipal.h"

void menuPpal()
{
    ///por aca iria el recuadro -> ver

    int opcion;

    printf("Menú Principal");

    printf("\n\n ----------------");

    printf("\n\n 1. Ingresar al sistema\n\n 2. Registrarse\n\n  Ingrese una opción\n\n");
    fflush(stdin);
    scanf("%d", &opcion);

    switch(opcion)
    {
    case 1:

        inicioSesion();
        break;

    case 2:

        printf("\nRegistro de usuario\n");

        printf("\n");
        system("pause");
        system("cls");
        cargarUnUsario2Archivo();

        break;

    default:

        printf("\nHa ingresado una opción incorrecta\n");
    }

}

