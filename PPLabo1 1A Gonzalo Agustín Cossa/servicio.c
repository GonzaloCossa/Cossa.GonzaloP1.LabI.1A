#include "servicio.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int listarServicios(eServicio servicios[], int tamS)
{
    int todoOk = 0;

    if(servicios && tamS > 0)
    {
        system("cls");
        printf("  ***LISTADO DE SEVICIOS***\n");
        printf("-------------------------------\n");
        printf("ID\tDescripcion\tPrecio\n");
        printf("-------------------------------\n");
        for(int i = 0; i < tamS; i++)
        {
            printf("%d\t%-10s\t$%d\n",servicios[i].id, servicios[i].descripcion, servicios[i].precio);
        }
        printf("-------------------------------\n\n");
        todoOk= 1;
    }

    return todoOk;
}
