#include "stUsuario.h"



///--------------------- Funciones para la carga de Datos e Ingreso del USUARIO-------------------

void mostrarFormulUsuario()
{
    gotoxy(8,2);
    printf("INGRESE SUS DATOS PERSONALES:");
    //nombre
    gotoxy(15,4);
    printf("Nombre................:");

    //apellido
    gotoxy(15,5);
    printf("Apellido..............:");

    //dni
    gotoxy(15,6);
    printf("DNI...................:");

    gotoxy(8,12);
    printf("DATOS DE INGRESO:");

    //nombreUsuario
    gotoxy(15,14);
    printf("Ingrese nombre de usuario:");

    //password
    gotoxy(15,15);
    printf("Ingrese contraseña:");
    gotoxy(55,15);
    printf("(Debe contener 8 caracteres)");

}


stUsuario cargarDatosUsuario ()
{
    stUsuario aux;
    aux.baja=0;
    aux.idUsuario = 0;
    aux.isAdmin = 0;

    hidecursor(1);
    mostrarFormulUsuario();
    //Nombre
    gotoxy(38,4);
    fflush(stdin);
    scanf("%s", &aux.nombre);
    //Apellido
    gotoxy(38,5);
    fflush(stdin);
    scanf("%s", &aux.apellido);
    //DNI
    gotoxy(38,6);
    fflush(stdin);
    scanf("%s", &aux.dni);
    //Usuario
    gotoxy(41,14);
    fflush(stdin);
    scanf("%s", &aux.nombreUsuario);
    //Contraseña
    gotoxy(34,15);
    fflush(stdin);
    scanf("%s", &aux.password);


    hidecursor(0);

    return aux;
}


///---------------------- Muestra 1 usuario------------------------

void mostrarDatos1Usuario(stUsuario aux)
{
    printf("Nombre: %s\n", aux.nombre);
    printf("Apellido: %s\n", aux.apellido);
    printf("DNI: %s\n", aux.dni);
    printf("es usuario %d\n", aux.isAdmin );

    if(aux.isAdmin == 1)
    {

        printf("Adminsitrador\n");
    }
    else
    {
        printf("Usuario\n");
    }

    if(aux.baja!= 0)
        printf("Usuario dado de baja");
    else
        printf("Usuario registrado");
    printf("\n\n");


}

///-----------Muestra datos de login--------
void mostrarDatosIngresoUs (stUsuario aux)
{
    printf("Id usuario: %d\n", aux.idUsuario);
    printf("Nombre de usuario: %s\n", aux.nombreUsuario);
    printf("Contraseña: %s", aux.password);
}


///--------------- Cargar archivo con las estructuras----------------
void cargarArchivoUsuarios() /// arreglar, porque no cambia administrador ni id
{
    FILE* user = fopen("usuarios.dat","ab");
    stUsuario persona;
    int opcion=0;

    if(user !=NULL)
    {
        while (opcion!=27)
        {
            persona= cargarDatosUsuario();
            fwrite(&persona,sizeof(stUsuario),1,user);
            gotoxy(12,20);
            printf("Si desea salir presione ESC");
            opcion=getch();
            if(opcion ==27)
            {
                gotoxy(12,22);
                printf("Gracias por registrarse");
            }
            system("cls");
        }
    }
    fclose(user);
}

/// primer usuario es administrador


/// Contar registros del archivo
int cantidadRegistrosArchivo(FILE * user)
{
    int cantidadRegistros;

    fseek(user,0,SEEK_END);
    cantidadRegistros = ftell(user)/sizeof(stUsuario);

    return cantidadRegistros;
}

/// Cargar al archivo un usuario que se registra
void cargarUnUsario2Archivo()
{
    FILE* user = fopen("usuarios.dat","ab");

    if(user !=NULL)
    {
        stUsuario persona;

        int cantidadDeRegistros = cantidadRegistrosArchivo(user);
        persona= cargarDatosUsuario();
        persona.idUsuario = cantidadDeRegistros + 1;
        if(cantidadDeRegistros == 0){
            persona.isAdmin = 1;
        }

        fwrite(&persona,sizeof(stUsuario),1,user);

        gotoxy(12,22);
        printf("Gracias por registrarse");


        system("pause");
        system("cls");

        fclose(user);

    }

}

/// ----------------------- Mostrar USUARIOS de un archivo --------------------

void mostrarUsuariosArchivo ()
{
    FILE* usuario = fopen("usuarios.dat","rb");
    stUsuario persona;

    if(usuario!=NULL)
    {
        while(fread(&persona,sizeof(stUsuario),1,usuario)>0)
        {
            printf("\nDATOS DEL USUARIO:\n");
            mostrarDatos1Usuario(persona);
            printf("\nDATOS DE INGRESO DE USUARIO:\n");
            mostrarDatosIngresoUs(persona);

            printf("\n---------------------------------\n");

        }
    }
    fclose(usuario);
}


///-------------Pasar los datos del archivo a la Lista de USUARIOS----------------------------
/*void pasarDeArchivoALista2 (ARCHIUSERS, lista2Usuario* lista)
{
    stUsuario aux;

    FILE* usuario= fopen(ARCHIUSERS, "rb");

    if (usuario != NULL)
    {
        while (fread(&aux,sizeof(stUsuario),1,usuario) > 0)
        {
            agregarEnOrdenL2UporID(lista, crearNodolis2Us(aux));
        }

        fclose(usuario);
    }
}*/


///__________________________________ FUNCIONES PARA LISTAS__________________________________________
///----------- inicializar lista------
lista2Usuario* iniclista2U()
{
    return NULL;
}

///----------- Crear nodo doble--------
lista2Usuario * crearNodolis2Us (stUsuario dato)
{
    lista2Usuario* aux= (lista2Usuario*) malloc (sizeof(lista2Usuario));
    aux->dato= dato;
    aux->ante= NULL;
    aux->ste=NULL;

    return aux;
}

///---------Agregar al principio-----------
lista2Usuario* agregarAlppioL2U (lista2Usuario* listaU, lista2Usuario* nvoUs)
{
    nvoUs->ste=listaU;

    if(listaU!=NULL)
    {
        listaU->ante= nvoUs;
    }
    return nvoUs;
}

///----- Agregar en orden-------------------
lista2Usuario* agregarEnOrdenL2UporID (lista2Usuario* listaU, lista2Usuario* nvoUs)
{
    if (listaU==NULL)
    {
        listaU= nvoUs;
    }
    else if(nvoUs->dato.idUsuario < listaU->dato.idUsuario)
    {
        listaU=agregarAlppioL2U(listaU,nvoUs);
    }
    else
    {
        lista2Usuario* seg= listaU->ste;
        lista2Usuario* ante= listaU;
        while((seg!=NULL)&&(nvoUs->dato.idUsuario>seg->dato.idUsuario))
        {
            ante=seg;
            seg=seg->ste;
        }

        ante->ste= nvoUs;
        nvoUs->ante=ante;
        nvoUs->ste=seg;

        if(seg!=NULL)
        {
            seg->ante=nvoUs;
        }
    }

    return listaU;
}

///-----------Cargar LISTA2 con estructuras-----------------
lista2Usuario* cargarListaUsuarios ()
{
    lista2Usuario* lista=NULL;
    lista2Usuario* nvoNodo;
    stUsuario persona;
    int opcion=0;

    while (opcion!=27)
    {
        persona= cargarDatosUsuario();
        nvoNodo= crearNodolis2Us(persona);
        lista= agregarEnOrdenL2UporID(lista,nvoNodo);
        gotoxy(12,20);
        printf("Si desea salir presione ESC");
        opcion=getch();
        system("cls");
    }

    return lista;
}

/// --------- Cargar archivo con las estructuras de la lista---------

/*void cargarArchivoUsuarios(archivoUser, lista2Usuario* lista)
{
    stUsuario persona;
    FILE* user = fopen(archivo_Users,"ab");


    if (user!=NULL && lista!=NULL)
    {
        while (lista!=NULL)
        {
            persona= lista->dato
            fwrite(&persona,sizeof(stUsuario),1,user);
            lista= lista->ste;
        }
    }
    fclose(user);
}*/





///-------------Pasar los datos del archivo a la Lista de USUARIOS----------------------------

///----------------Ordenados por ID----------------------
void cargarListaDesdeArchivos (char nombreArchi[], lista2Usuario* lista)
{
    stUsuario aux;

    FILE* usuario= fopen("usuarios.dat", "rb");

    if (usuario !=NULL)
    {
        while (fread(&aux, sizeof(stUsuario), 1, usuario)> 0)
        {
           agregarEnOrdenL2UporID(lista, crearNodolis2Us(aux));
        }

        fclose(usuario);
    }
}

///------------- Mostrar lista Usuarios-------------

///
void mostrarLista2Us (lista2Usuario* listaU)
{
    lista2Usuario* seg= listaU;
    while(seg!=NULL) //&& (lista->dato.baja==0)
    {
        mostrarDatos1Usuario(listaU->dato);
        seg= seg->ste;
    }
}



///Mostrar ordenados por apellido---------------------------------------------------------------------- s/h


///----------- Buscar Usuario por ID------------

///Buscar nodo por ID

lista2Usuario* buscarNodoXid (lista2Usuario* lista, int id)
{
    lista2Usuario* seg= lista;

    while((seg!=NULL)&&(lista->dato.idUsuario!= id))//&& (lista->dato.baja==0)
    {
        seg= seg->ste;
    }

    return seg;
}

/// Mostar nodo buscado
void mostarUsBuscadoXid (lista2Usuario* aux)
{
    if(aux!=NULL)
    {
        mostrarDatos1Usuario(aux->dato);
    }

    else
    {
        printf("\nEl usuario no se encuentra en el registro");
    }
}

/// Buscar usuario por nombre y contraseña. Retorna el id

lista2Usuario* buscarUsuarioPorNombre(lista2Usuario* lista, char nombreUsuario[30])
{
    lista2Usuario* seg = lista;

    while((seg != NULL) && (strcmpi(seg->dato.nombreUsuario, nombreUsuario) != 0))
    {
        seg = seg -> ste;
    }
    if( seg == NULL)
    {
        printf("El usuario ingresado no existe\n");
    }
    return seg;

}

///------------------ Dar de baja Usuario-------------------

/*lista2Usuario* bajaXelUsuario (lista2Usuario* lista)  /// Busca por el ID ya cargado???
{
    char control= 's';
    int identif=0;

    printf("\n\t\tIngrese ID del usario que desea ver");
    fflush(stdin);
    scanf("%d", &identif);

    lista2Usuario* aux=buscarNodoXid(lista,identif);
    mostarUsBuscadoXid(aux);

    printf("\n\t\t¿Desea realizar la BAJA del usuario?");
    fflush(stdin);
    scanf("%d",&control);
    if(control=='s')
    {
        aux->dato.eliminado=1;
    }

    printf("\n\t\t BAJA EXITOSA");

    return lista;
}*/



