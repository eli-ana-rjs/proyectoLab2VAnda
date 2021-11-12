#ifndef MENUUSUARIO_H_INCLUDED
#define MENUUSUARIO_H_INCLUDED



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stUsuario.h"
#include "login.h"

#define dimension 100

typedef struct
{
    char  titulo[50];
    int id;
    int redireccion;

} itemMenuUser;

typedef struct
{
    char titulo[50];
    itemMenuUser opciones[10];
    int cantidadDeOpciones;
} MenuUser;

void configurarMenuUsuario (MenuUser menus[]);
int buscarRedireccionPorIdUser(MenuUser *menuActual, int id);
void iniciar_programaUser();

#endif // MENUUSUARIO_H_INCLUDED
