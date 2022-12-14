#include "tipo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int listarTipos (eTipo tipos[],int tamT)
{
    int todoOk = 0;

    if(tipos && tamT > 0)
    {
        system("cls");
        printf("  ***LISTADO DE TIPOS***\n");
        printf("-------------------------------\n");
        printf("ID\tTipo\n");
        printf("-------------------------------\n");
        for(int i=0;i<tamT;i++){
            printf("%d\t%-10s\n",tipos[i].id,tipos[i].descripcion);
        }
        printf("-------------------------------\n\n");
        todoOk= 1;
    }

    return todoOk;
}

int buscarTipo (eTipo tipos[],int tamT,int id,int* pIndice)
{
    int todoOk = 0;
    if(tipos && tamT > 0 && pIndice)
    {
        *pIndice = -1;
        for(int i = 0; i < tamT; i++)
        {
            if(tipos[i].id == id)
            {
                *pIndice = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int validarTipo(eTipo tipos[], int tamT, int id)
{
    int todoOk = 0;
    int indice;
    if(tipos && tamT > 0)
    {
        buscarTipo(tipos,tamT,id,&indice);
        if(indice != -1)
            todoOk = 1;
    }
    return todoOk;
}

int cargarDescripcionTipo(eTipo tipos[],int tamT,int id,char descripcion[])
{
    int todoOk = 0;
    int indice;
    if(tipos && tamT > 0 && descripcion && buscarTipo(tipos,tamT,id,&indice))
    {
        strcpy(descripcion, tipos[indice].descripcion);
        todoOk = 1;
    }
    return todoOk;
}
