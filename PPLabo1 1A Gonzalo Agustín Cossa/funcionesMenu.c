#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funcionesMenu.h"

int menu()
{
    char opcion;

    system("cls");
    printf("***     ABM Bicicletas     ***\n\n");
    printf("A- Alta Bicicleta\n");
    printf("B- Modificar Bicicleta\n");
    printf("C- Baja Bicicleta\n");
    printf("D- Listar Bicicletas\n");
    printf("E- Listar Tipos\n");
    printf("F- Listar Colores\n");
    printf("G- Listar Servicios\n");
    printf("H- Alta Trabajo\n");
    printf("I- Listar Trabajo\n");
    printf("J- Salir\n\n");
    printf("Ingrese una opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);
    opcion = toupper(opcion);

    return opcion;
}

int confirmarSalir(char* pVariable)
{
    int todoOk = 0;
    char rta;

    if(pVariable != NULL)
    {
        printf("Confirma salir? (s/n): ");
        fflush(stdin);
        rta = tolower(getchar());
        if(rta == 's')
        {
            *pVariable = 's';
        }
        else
        {
            *pVariable = 'n';
        }

        todoOk = 1;
    }

    return todoOk;
}

char menuModificar()
{
    char respuesta;

    printf("\nA) Tipo \n");
    printf("B) Material \n");
    printf("S) Salir \n");
    fflush(stdin);
    printf("Ingrese una opcion: ");
    scanf("%c",&respuesta);

    respuesta = toupper(respuesta);

    return respuesta;
}
