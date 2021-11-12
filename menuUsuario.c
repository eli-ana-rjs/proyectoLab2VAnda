#include "menuUsuario.h"

void configurarMenuUsuario (MenuUser menus[])
{

    /// Menu de Usuario [0].

    strcpy(menus[0].titulo, "Usuario");
    menus[0].cantidadDeOpciones = 5;

    strcpy( menus[0].opciones[0].titulo, "Ver mi perfil");
    menus[0].opciones[0].id = 1;
    menus[0].opciones[0].redireccion = 1;

    strcpy( menus[0].opciones[1].titulo, "Mostrar listado de películas..."); // mañana
    menus[0].opciones[1].id = 2;
    menus[0].opciones[1].redireccion = 2; //ver

    strcpy( menus[0].opciones[2].titulo, "Buscar película");
    menus[0].opciones[2].id = 3;
    menus[0].opciones[2].redireccion = 3; //ver

     strcpy( menus[0].opciones[3].titulo, "Cancelar el servicio");
    menus[0].opciones[3].id = 4;
    menus[0].opciones[3].redireccion = 1001; //ver


    strcpy( menus[0].opciones[4].titulo, "Salir");
    menus[0].opciones[4].id = 0;
    menus[0].opciones[4].redireccion = -1;

    /// Sub-menú ver pefil [1].

    strcpy(menus[1].titulo, "Sub-Menú Ver perfil ");
    menus[1].cantidadDeOpciones = 3;

    strcpy( menus[1].opciones[0].titulo, "Mis datos");
    menus[1].opciones[0].id = 1;
    menus[1].opciones[0].redireccion = 1002;

    strcpy( menus[1].opciones[1].titulo, "Modificar mi información ");
    menus[1].opciones[1].id = 2;
    menus[1].opciones[1].redireccion = 1003;

    strcpy( menus[1].opciones[2].titulo, "Volver al Menú Principal");
    menus[1].opciones[2].id = 0;
    menus[1].opciones[2].redireccion = 0;

    /// SubMenu Mostrar listados de peliculas  [2]

    strcpy(menus[2].titulo, " Sub-menú Mostrar listados de películas ");
    menus[2].cantidadDeOpciones = 4;

    strcpy( menus[2].opciones[0].titulo, "Películas por genero");
    menus[2].opciones[0].id = 1;
    menus[2].opciones[0].redireccion = 4;

    strcpy( menus[2].opciones[1].titulo, "Mis películas favoritas");
    menus[2].opciones[1].id = 2;
    menus[2].opciones[1].redireccion = 1004;

    strcpy( menus[2].opciones[2].titulo, "Películas vistas");
    menus[2].opciones[2].id = 3;
    menus[2].opciones[2].redireccion = 1005;

    strcpy( menus[2].opciones[3].titulo, "Volver");
    menus[2].opciones[3].id = 0;
    menus[2].opciones[3].redireccion = 0;

    ///SubMenu Buscar pelicula [3]

    strcpy(menus[3].titulo, "Submenú Buscar película");
    menus[3].cantidadDeOpciones = 3;

    strcpy( menus[3].opciones[0].titulo, "Por año de estreno");
    menus[3].opciones[0].id = 1;
    menus[3].opciones[0].redireccion = 1012;

    strcpy( menus[3].opciones[1].titulo, "Por título");
    menus[3].opciones[1].id = 2;
    menus[3].opciones[1].redireccion = 1006;

    strcpy( menus[3].opciones[2].titulo, "Volver");
    menus[3].opciones[2].id = 0;
    menus[3].opciones[2].redireccion = 0;

/// Sub-menú Mostrar listado de peliculas por genero [4]

    strcpy(menus[4].titulo, "Sub-menú Mostrar listado de películas por genero");
    menus[4].cantidadDeOpciones = 6;

    strcpy( menus[4].opciones[0].titulo, "Comedia ");
    menus[4].opciones[0].id = 1;
    menus[4].opciones[0].redireccion = 1007;

    strcpy( menus[4].opciones[1].titulo, "Drama");
    menus[4].opciones[1].id = 1;
    menus[4].opciones[1].redireccion = 1008;

    strcpy( menus[4].opciones[2].titulo, "Acción");
    menus[4].opciones[2].id = 1;
    menus[4].opciones[2].redireccion = 1009;

    strcpy( menus[4].opciones[3].titulo, "Suspenso");
    menus[4].opciones[3].id = 1;
    menus[4].opciones[3].redireccion = 1010;

    strcpy( menus[4].opciones[4].titulo, "Ciencia Ficción");
    menus[4].opciones[4].id = 1;
    menus[4].opciones[4].redireccion = 1011;

    strcpy( menus[4].opciones[5].titulo, "Volver ");
    menus[4].opciones[5].id = 0;
    menus[4].opciones[5].redireccion = 2;

}

/// Cada menu tiene id de 1 a x. Hace esta logica para buscar la redireccion de este elemento. Y me permite que el usuario pueda apretar 1
/// en el menu principal, y en los siguientes submenues.

int buscarRedireccionPorIdUser(MenuUser *menuActual, int id)
{
    for(int i = 0; i < menuActual->cantidadDeOpciones; i++)
    {
        if(menuActual->opciones[i].id == id)
        {
            return menuActual->opciones[i].redireccion;
        }
    }
}

void iniciar_programaUser()
{
    int menuActual = 0;
    int redirMenu;
    MenuUser menus[20];
    stUsuario usuario;
    lista2Usuario* lista = iniclista2U();
  //  lista = pasarDeArchivoALista2(ARCHIUSERS,lista);

    configurarMenuUsuario(menus);


    while( menuActual != -1) /// -1 salir del programa
    {
        /// imprime el titulo del menu actual
        printf("%s\n", menus[menuActual].titulo);

        /// subraya el titulo
        for (int i = 0; i < strlen(menus[menuActual].titulo); i++)
        {
            printf("=");
        }
        printf("\n");

        /// Imprimo el menu actual.

        for ( int i = 0; i < menus[menuActual].cantidadDeOpciones; i++)
        {
            printf("[%i] %s\n", menus[menuActual].opciones[i].id, menus[menuActual].opciones[i].titulo);
        }

        printf("\nSeleccione el menu al que desea acceder\n");
        fflush(stdin);
        scanf("%i", &redirMenu);
        int redireccion = buscarRedireccionPorId(&menus[menuActual], redirMenu);

        /// En los casos en que redireccion sea menor a 1000 me va a redirigir a la siguiente lista de opciones segun corresponda
        ///En los casos donde redireccion sea mayor a 1000 se ha asignado dentro un switch, en cada caso, el llamado a la funcion que
        ///se deba ejecutar en cada caso

        if( redireccion < 1000)
        {
            menuActual = redireccion;
            system("cls");
        }
        else
        {
            switch ( redireccion )
            {

            case 1001 :

            /// Desea dar de baja el servicio?
            /// función que cambia el estado eliminado a 0

                break;

            case 1002 :

         //   lista2Usuario* usuarioConectado = buscarNodoXid(lista,idUsuarioConectado);
         //   mostrarDatos1Usuario(usuarioConectado->dato);

                break;

            case 1003 :

            /// Mostrar datos otra vez
            /// mostrar datos que se pueden modificar
            /// ingresar dato a modificar
            /// mostrar data modificada


                break;

            case 1004 :
                /// Mostrar lista de peliculas favoritas

                break;

            case 1005 :

                /// mostrar lista de peliculas vistas
                break;

            case 1006 :
                /// buscar pelicula por titulo ??? o conviene por id?? ---> ver!!!
                /// mostrar informacion de la pelicula
                /// preguntar si quiere ver

                break;

            case 1007 :

                /// Lista de peliculas de Comedia

                break;

            case 1008 :
                /// Lista de peliculas de Drama

                break;

            case 1009 :
               /// Lista de peliculas de Acción

                break;

            case 1010 :
               /// Lista de peliculas de Suspenso

                break;

            case 1011 :
                /// Lista de peliculas de Ciencia Ficción

                break;

            case 1012 :
                /// Buscar peliculas por año de estreno


                break;


            default:
                printf("Opcion no implementada\n");
                break;
            }
            system ("pause");
            system("cls");

        }
    }

    printf("\nFin programa\n");
}
