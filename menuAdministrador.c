#include "menuAdministrador.h"

void configurarMenuAdministrador (Menu menus[])
{

    /// Menu Administrador de usuario [0].

    strcpy(menus[0].titulo, "Administrador");
    menus[0].cantidadDeOpciones = 3;

    strcpy( menus[0].opciones[0].titulo, "Administrar Usuarios");
    menus[0].opciones[0].id = 1;
    menus[0].opciones[0].redireccion = 1;

    strcpy( menus[0].opciones[1].titulo, "Administrar Películas");
    menus[0].opciones[1].id = 2;
    menus[0].opciones[1].redireccion = 6;

    strcpy( menus[0].opciones[2].titulo, "Salir");
    menus[0].opciones[2].id = 0;
    menus[0].opciones[2].redireccion = -1;

    /// Sub-menú Administrar Usuarios [1].

    strcpy(menus[1].titulo, "Sub-Menú Administrar Usuarios ");
    menus[1].cantidadDeOpciones = 5;

    strcpy( menus[1].opciones[0].titulo, "Alta de Usuario");
    menus[1].opciones[0].id = 1;
    menus[1].opciones[0].redireccion = 2;

    strcpy( menus[1].opciones[1].titulo, "Ver listados de Usuarios");
    menus[1].opciones[1].id = 2;
    menus[1].opciones[1].redireccion = 3;

    strcpy( menus[1].opciones[2].titulo, "Modificar usuario");
    menus[1].opciones[2].id = 3;
    menus[1].opciones[2].redireccion = 4;

    strcpy( menus[1].opciones[3].titulo, "Baja de usuario");
    menus[1].opciones[3].id = 4;
    menus[1].opciones[3].redireccion = 5;

    strcpy( menus[1].opciones[4].titulo, "Volver al Menú Principal");
    menus[1].opciones[4].id = 0;
    menus[1].opciones[4].redireccion = 0;

    /// SubMenu Alta de Usuario  [2]

    strcpy(menus[2].titulo, " Sub-menú Alta de Usuario ");
    menus[2].cantidadDeOpciones = 3;

    strcpy( menus[2].opciones[0].titulo, "Dar de alta un Administrador");
    menus[2].opciones[0].id = 1;
    menus[2].opciones[0].redireccion = 1001;

    strcpy( menus[2].opciones[1].titulo, "Dar de alta un Usuario");
    menus[2].opciones[1].id = 2;
    menus[2].opciones[1].redireccion = 1002;

    strcpy( menus[2].opciones[2].titulo, "Volver");
    menus[2].opciones[2].id = 0;
    menus[2].opciones[2].redireccion = 1;

    ///SubMenu Listados de Usuarios[3]

    strcpy(menus[3].titulo, "Sub-menú ver listados de Usuarios");
    menus[3].cantidadDeOpciones = 3;

    strcpy( menus[3].opciones[0].titulo, "Ordenado por id");
    menus[3].opciones[0].id = 1;
    menus[3].opciones[0].redireccion = 1003;

    strcpy( menus[3].opciones[1].titulo, "Ordenado por Nombre y Apellido");
    menus[3].opciones[1].id = 2;
    menus[3].opciones[1].redireccion = 1004;

    strcpy( menus[3].opciones[2].titulo, "Volver");
    menus[3].opciones[2].id = 0;
    menus[3].opciones[2].redireccion = 1;

/// Sub-menú Modificar datos de un Usuario [4]

    strcpy(menus[4].titulo, "Sub-menú Modificar datos de un Usuario");
    menus[4].cantidadDeOpciones = 3;

    strcpy( menus[4].opciones[0].titulo, "Buscar usuario por id ");
    menus[4].opciones[0].id = 1;
    menus[4].opciones[0].redireccion = 1005;

    strcpy( menus[4].opciones[1].titulo, "Modificar información");
    menus[4].opciones[1].id = 1;
    menus[4].opciones[1].redireccion = 1006;

    strcpy( menus[4].opciones[2].titulo, "Volver ");
    menus[4].opciones[2].id = 0;
    menus[4].opciones[2].redireccion = 1;

/// Submenú Baja de Usuario [5]

    strcpy(menus[5].titulo, "Baja de usuario ");
    menus[5].cantidadDeOpciones = 3;

    strcpy( menus[5].opciones[0].titulo, "Buscar usuario por id");
    menus[5].opciones[0].id = 1;
    menus[5].opciones[0].redireccion = 1007;
     strcpy( menus[5].opciones[1].titulo, "Dar de baja");
    menus[5].opciones[1].id = 2;
    menus[5].opciones[1].redireccion = 1007;
    strcpy( menus[5].opciones[2].titulo, "Volver");
    menus[5].opciones[2].id = 0;
    menus[5].opciones[2].redireccion = 1;

    ///SubMenu Administrar Peliculas [6]

    strcpy(menus[6].titulo, "Sub-menú Administrar Películas");
    menus[6].cantidadDeOpciones = 5;

    strcpy( menus[6].opciones[0].titulo, "Dar de alta una película");
    menus[6].opciones[0].id = 1;
    menus[6].opciones[0].redireccion = 1009;

    strcpy( menus[6].opciones[1].titulo, "Ver listado de películas...");
    menus[6].opciones[1].id = 2;
    menus[6].opciones[1].redireccion = 7;

    strcpy( menus[6].opciones[2].titulo, "Modificar datos de una película");
    menus[6].opciones[2].id = 3;
    menus[6].opciones[2].redireccion = 8;

     strcpy( menus[6].opciones[3].titulo, "Baja de película");
    menus[6].opciones[3].id = 4;
    menus[6].opciones[3].redireccion = 9;

    strcpy( menus[6].opciones[4].titulo, "Volver");
    menus[6].opciones[4].id = 0;
    menus[6].opciones[4].redireccion = 0;

///SubMenu ver listados de peliculas  [7]

    strcpy(menus[7].titulo, "Ver listados de películas ");
    menus[7].cantidadDeOpciones = 4;

    strcpy( menus[7].opciones[0].titulo, "Por id");
    menus[7].opciones[0].id = 1;
    menus[7].opciones[0].redireccion = 1010;

    strcpy( menus[7].opciones[1].titulo, "Por título");
    menus[7].opciones[1].id = 2;
    menus[7].opciones[1].redireccion = 1011;

    strcpy( menus[7].opciones[2].titulo, "Por genero");
    menus[7].opciones[2].id = 3;
    menus[7].opciones[2].redireccion = 10;

    strcpy( menus[7].opciones[3].titulo, "Volver ");
    menus[7].opciones[3].id = 0;
    menus[7].opciones[3].redireccion = 6;

///SubMenu Modificar datos de una pelicula [8]

    strcpy(menus[8].titulo, "Sub-menú Modificar datos de una Película");
    menus[8].cantidadDeOpciones = 3;

    strcpy( menus[8].opciones[0].titulo, "Buscar película por id");
    menus[8].opciones[0].id = 1;
    menus[8].opciones[0].redireccion = 1017;

    strcpy( menus[8].opciones[1].titulo, "Modificar información");
    menus[8].opciones[1].id = 2;
    menus[8].opciones[1].redireccion = 1018;

    strcpy( menus[8].opciones[2].titulo, "Volver ");
    menus[8].opciones[2].id = 0;
    menus[8].opciones[2].redireccion = 6;

///SubMenu Dar de baja una pelicula [9]

    strcpy(menus[9].titulo, "Baja de Película ");
    menus[9].cantidadDeOpciones = 3;

    strcpy( menus[9].opciones[0].titulo, "Buscar película por id");
    menus[9].opciones[0].id = 1;
    menus[9].opciones[0].redireccion = 1019;

    strcpy( menus[9].opciones[1].titulo, "Eliminar película");
    menus[9].opciones[1].id = 2;
    menus[9].opciones[1].redireccion = 1020;

    strcpy( menus[9].opciones[2].titulo, "Volver");
    menus[9].opciones[2].id = 0;
    menus[9].opciones[2].redireccion = 6;

///SubMenu Mostrar pelicular por genero[10]

    strcpy(menus[10].titulo, "Mostrar películas por genero");
    menus[10].cantidadDeOpciones = 6;

    strcpy( menus[10].opciones[0].titulo, "Comedia");
    menus[10].opciones[0].id = 1;
    menus[10].opciones[0].redireccion = 1012;

    strcpy( menus[10].opciones[1].titulo, "Drama");
    menus[10].opciones[1].id = 2;
    menus[10].opciones[1].redireccion = 1013;

    strcpy( menus[10].opciones[2].titulo, "Acción");
    menus[10].opciones[2].id = 3;
    menus[10].opciones[2].redireccion = 1014;

     strcpy( menus[10].opciones[3].titulo, "Suspenso");
    menus[10].opciones[3].id = 4;
    menus[10].opciones[3].redireccion = 1015;

    strcpy( menus[10].opciones[4].titulo, "Ciencia Ficción");
    menus[10].opciones[4].id = 5;
    menus[10].opciones[4].redireccion = 1016;

    strcpy( menus[10].opciones[5].titulo, "Volver ");
    menus[10].opciones[5].id = 0;
    menus[10].opciones[5].redireccion = 7;

}
/// Cada menu tiene id de 1 a x. Hace esta logica para buscar la redireccion de este elemento. Y me permite que el usuario pueda apretar 1
/// en el menu principal, y en los siguientes submenues.

int buscarRedireccionPorId(Menu *menuActual, int id)
{
    for(int i = 0; i < menuActual->cantidadDeOpciones; i++)
    {
        if(menuActual->opciones[i].id == id)
        {
            return menuActual->opciones[i].redireccion;
        }
    }
}

void iniciar_programaAdmin()
{
    int menuActual = 0;
    int redirMenu;
    Menu menus[20];

    configurarMenuAdministrador(menus);


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

            /// Dar de Alta a un administrador
            /// función que pide los datos del usuario
            /// función que cambia el estado de isAdmin de 0 a 1

                break;

            case 1002 :
            /// Dar de alta un usuario
            /// función que pide los datos del usuario
            /// Todos los que se registren por primera vez son usuarios
            /// Un usuario con rol de admin puede dar de alta a un usuario x

                break;

            case 1003 :

            /// Mostrar lista de usuarios ordenados por id


                break;

            case 1004 :
                /// Mostrar lista de usuarios ordenados por Apellido y nombre

                break;

            case 1005 :

                ///  buscar usuario por id
                 /// mostrar información del usuario encontrado o lanzar mensaje indicando que no existe ese usuario en el sistema
                break;

            case 1006 :
                /// mostrar campos que puede modificar
                /// modificar información
                /// mostrar data modificada

                break;

            case 1007 :

                /// Buscar usuario por id
                /// mostrar información del usuario encontrado o lanzar mensaje indicando que no existe ese usuario en el sistema

                break;

            case 1008 :
                ///Pedir id del usuario que se desea dar de baja
                /// función que cambia el estado eliminado a 0
                /// msj -> el usuario ha sido dado de baja

                break;

            case 1009 :
                /// Pedir información para cargar la pelicula
                /// mostrar la información cargada

                break;

            case 1010 :
                /// mostrar listado de peliculas cargadas ordenadas por id

                break;

            case 1011 :
                /// mostrar listado de peliculas cargadas ordenadas por titulo

                break;

            case 1012 :
                /// mostrar lista de peliculas de Comedia


                break;

            case 1013 :
                /// mostrar lista de peliculas de Drama


                break;

            case 1014 :
                /// mostrar lista de peliculas de Acción


                break;

            case 1015 :
                /// mostrar lista de peliculas de Suspenso

                break;

            case 1016 :
                /// mostrar lista de peliculas de Ciencia Ficción


                break;

            case 1017 :
                ///  buscar pelicula por id
                 /// mostrar información de la peliula encontrado o lanzar mensaje indicando que no existe esa pelicula en el sistema


                break;

            case 1018 :

                /// mostrar campos que puede modificar
                /// modificar información
                /// mostrar data modificada

                break;

            case 1019 :
                ///  buscar pelicula por id
                 /// mostrar información de la peliula encontrado o lanzar mensaje indicando que no existe esa pelicula en el sistema
                break;

            case 1020 :
                ///Pedir id de la pelicula que se desea dar de baja
                /// función que cambia el estado eliminado a 0
                /// msj -> la pelicula ha sido dada de baja
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
