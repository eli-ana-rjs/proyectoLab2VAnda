#ifndef STUSUARIO_H_INCLUDED
#define STUSUARIO_H_INCLUDED



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include "gotoxy.h"




///-------------------------- Estructura con datos del USUARIO-----------------
typedef struct
{
    int idUsuario;
    char nombre[20];
    char apellido[20];
    char dni[15];
    char nombreUsuario[30];
	char password[8];
	int isAdmin; // 1: es administrador del sistema || 0: es usuario del sistema
    int baja; // 1: usuario dado de baja

}stUsuario;

typedef struct
{
    stUsuario dato;
    struct lista2Usuario* ante;
    struct lista2Usuario* ste;

}lista2Usuario;


///--------------------- Funciones para la carga de Datos e Ingreso del USUARIO-------------------

void mostrarFormulUsuario();


stUsuario cargarDatosUsuario ();


///---------------------- Muestra 1 usuario------------------------

void mostrarDatos1Usuario(stUsuario aux);

///-----------Muestra datos de login--------
void mostrarDatosIngresoUs (stUsuario aux);


///__________________________________ FUNCIONES PARA LISTAS__________________________________________
///----------- inicializar lista------
lista2Usuario* iniclista2U();

///----------- Crear nodo doble--------
lista2Usuario * crearNodolis2Us (stUsuario dato);

///---------Agregar al principio-----------
lista2Usuario* agregarAlppioL2U (lista2Usuario* listaU, lista2Usuario* nvoUs);

///----- Agregar en orden-------------------
lista2Usuario* agregarEnOrdenL2UporID (lista2Usuario* listaU, lista2Usuario* nvoUs);

///-----------Cargar LISTA2 con estructuras-----------------
lista2Usuario* cargarListaUsuarios ();

/// --------- Cargar archivo con las estructuras de la lista---------

//void cargarArchivoUsuarios(archivoUser, lista2Usuario* lista);


///-------------Pasar los datos del archivo a la Lista de USUARIOS----------------------------

///----------------Ordenados por ID----------------------


///------------- Mostrar lista Usuarios-------------

void mostrarLista2Us (lista2Usuario* listaU);


///----------- Buscar Usuario por ID------------
//void pasarDeArchivoALista2 (ARCHIUSERS, lista2Usuario* lista);
///Buscar nodo por ID

lista2Usuario* buscarNodoXid (lista2Usuario* lista, int id);

/// Mostar nodo buscado
void mostarUsBuscadoXid (lista2Usuario* aux);

///------------------ Dar de baja Usuario-------------------
lista2Usuario* bajaXelUsuario (lista2Usuario* lista);  /// Busca por el ID ya cargado???






#endif // STUSUARIO_H_INCLUDED
