#include "stPelicula.h"

///-------------------- Funciones de carga de PELICULA-------------------------------

void mostrarForPelicula ()
{
    gotoxy(10,3);
    printf("Id de pel%Ccula:...........:",161);

    gotoxy(10,4);
    printf("T%Ctulo:...................:",161);

    gotoxy(10,5);
    printf("Informaci%Cn...............:",162);

    gotoxy(10,6);
    printf("G%Cnero:...................:",130);

    gotoxy(10,7);
    printf("Actores principales:......:");



}

stPelicula cargarDatosPelicula ()
{
    stPelicula aux;
    hidecursor(1);
    mostrarForPelicula();

    //Id de película
    gotoxy(37,3);
    scanf("%d",&aux.idPelicula );

    //Título
    gotoxy(37,4);
    fflush(stdin);
    scanf("%s", &aux.titulo);

    //Información
    gotoxy(37,5);
    scanf("%s", &aux.informacion);

    //Genero
    gotoxy(37,6);
    scanf("%s", &aux.genero);

    //Actores Principales
    gotoxy(37,7);
    fflush(stdin);
    scanf("%s", &aux.actoresPrincipales);

    //Calificación
    aux.calificacion=0.2f;

    //Mis favoritos
    aux.mis_favoritos=0;

    hidecursor(0);

    return aux;

}

void mostrar1Pelicula (stPelicula peli)
{
    printf("Id de película:%d",peli.idPelicula);
    printf("\nTítulo:%s", peli.titulo);
    printf("\nInformación: %s",peli.informacion);
    printf("\nGénero:%s",peli.genero);
    printf("\nActores principales:%s",peli.actoresPrincipales);
    printf("\n\n-------------------------------\n\n");
}


