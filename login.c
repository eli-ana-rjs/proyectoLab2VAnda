#include "login.h"
const char nombreArchi[] = {"usuarios.dat"};

void inicioSesion()
{

    char usuario[LONGITUD + 1] ;
    char clave[LONGITUD + 1];
    lista2Usuario * listaUsuario = iniclista2U();
    cargarListaDesdeArchivos(nombreArchi,listaUsuario);
    int intento = 0;
    int ingreso = 0; // F, no puedo ingresar
    int isAdmin = 0; /// cambiar por el acceso a isAdmin correspondiente
    stUsuario user;
    char caracter;
    int i = 0;

    lista2Usuario* usuarioEncontrado = buscarUsuarioPorNombre(listaUsuario,usuario);

    do
    {
        system("cls");
        printf("\n\t\t INICIO DE SESIÓN\n");
        printf("\n\t\t-----------------\n");
        printf("\n\t\tUSUARIO: ");
        fflush(stdin);
        scanf("%s", &usuario);
        printf("\n\n\t\tCONTRASEÑA: ");


        while(caracter = getch())
        {
            if(caracter == TECLA_ENTER)
            {
                clave[i]= '\0';
                break;
            }
            else if( caracter == TECLA_BACKSPACE )
            {
                if(i > 0)
                {
                    i--;
                    printf("\b\b");
                }
            }
            else
            {
                if( i < LONGITUD )
                {
                    printf("*");
                    clave[i] = caracter;
                    i++;
                }
            }
        }

        /// printf("\nClave leida: %s\n", clave)


            if(strcmpi(clave,usuarioEncontrado->dato.password) == 0 )
            {
                ingreso = 1;
               // idUsuarioConectado = usuarioEncontrado->dato.idUsuario;

                break;
            }

        if( ingreso == 0)
        {
            printf("\n\tUsuario y/o contraseña incorrectas\n");
            intento++;
            system("pause");
        }
    } while(intento < 3 && ingreso == 0 );

    if(ingreso == 1)
    {
        printf("\n\tBienvenida/o al Sistema\n");

        user = usuarioEncontrado -> dato; // le paso la estructura con la info del user en linea

        /// opciones para cada tipo de usuario
        if( isAdmin == 1) // isAdmin == 1 ---> muestra el menu para las acciones que puede realizar un administrador del sistema
        {

            int menuAdmin[30];
            iniciar_programaAdmin();

        }
        else if( isAdmin == 0) /// menu para el usuario
        {

            int menuUsers[30];
            iniciar_programaUser();

        }
        else
        {

            printf("La opción ingresada no es correcta. Debe indicar: 1. Administrador de Usuarios ...\n");

        }
    }
    else
    {
        printf("\n\tHa sobrepasado el número de intentos permitidos\n");
        system("cls");
        printf("\n\tEn caso de no estar registrado en nuestro sistema, lo redireccionaremos a la sección de registro \n");
        /// llamar a la función de registro de un nuevo usuario
    }
}

