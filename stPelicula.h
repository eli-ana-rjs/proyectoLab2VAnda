#ifndef STPELICULA_H_INCLUDED
#define STPELICULA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include "gotoxy.h"

///----------------------------------- Estructura con la informacion de las PELICULAS -------------------------
typedef struct
{
    int idPelicula;
    char titulo[30];
    char informacion[50];//link que accede a la imagen, resumen, director año, duración,
    char genero[20];
    char actoresPrincipales[50];
    float calificacion; // promedio entre las calificaciones dadas por los usuarios
    int mis_favoritos; // 1: se agrega a la lista de favoritos del usuario
} stPelicula;


typedef struct
{
    stPelicula dato;
    struct nodoArbolPelicula* izq;
    struct nodoArbolPelicula* der;
} nodoArbolPelicula;

/// Funciones que manejan la estructura Peliculas
void mostrarForPelicula ();
stPelicula cargarDatosPelicula ();
void mostrar1Pelicula (stPelicula peli);

#endif // STPELICULA_H_INCLUDED
