const char nombreArchi[] = {"usuarios.dat"};

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <wchar.h>
#include <locale.h>
#include "menuAdministrador.h"
#include "menuUsuario.h"
#include "login.h"
#include "menuPrincipal.h"
#include "gotoxy.h"

int idUsuarioConectado;



int main()
{

    setlocale(LC_ALL, "");

    //system("C:/Users/apunt/Downloads/theGuilty.jpg");

    //int menuUsers[30];
    //iniciar_programaUser();

  //menuPpal();
   //cargarArchivoUsuarios();

   //mostrarUsuariosArchivo();

   //iniciar_programaUser();


    //system("mode con: cols=80 lines=25");
    system("COLOR C0"); // ZZ para ver todos los colores, primer color fondo, ssegundo letra


    //menuPpal();
    mostrarUsuariosArchivo();


    return 0;
}
