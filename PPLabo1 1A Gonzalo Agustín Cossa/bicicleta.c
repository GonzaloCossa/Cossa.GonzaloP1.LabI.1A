#include "bicicleta.h"
#include "funcionesMenu.h"
#include "color.h"
#include "tipo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int inicializarBicicletas(eBicicleta bicicletas[], int tamB)
{
    int todoOk = 0;
    if(bicicletas != NULL && tamB > 0)
    {
        for(int i = 0; i < tamB; i++)
        {
            bicicletas[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int hardcodearBicicletas(eBicicleta bicicletas[], int tamB, int cantidad, int* pId)
{
    int todoOk = 0;
    eBicicleta auxBicicletas[] = {{10000, "CANYON", 1000, 5000, 'c', 0},
                              {10001, "SCOTT", 1001, 5001, 'a', 0},
                              {10002, "SPECIALIZED", 1002, 5002, 'c', 0},
                              {10003, "GIANT", 1003, 5003, 'a', 0},
                              {10004, "CANNONDALE", 1000, 5004, 'c', 0}};

    if(bicicletas != NULL && tamB && pId != NULL && cantidad > 0 && cantidad <= tamB)
    {
        for(int i = 0; i < cantidad; i++)
        {
            bicicletas[i] = auxBicicletas[i];
            bicicletas[i].id = (*pId);
            (*pId)++;
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarBicicletaLibre(eBicicleta bicicletas[], int tamB, int* pIndice)
{
    int todoOk = 0;
    if(bicicletas != NULL && tamB > 0 && pIndice != NULL)
    {
        *pIndice = -1;
        for(int i = 0; i < tamB; i++)
        {
            if(bicicletas[i].isEmpty){
                *pIndice = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int altaBicicleta(eBicicleta bicicletas[], int tamB, eColor colores[], int tamC, eTipo tipos[],int tamT, int* pId)
{
    int todoOk = 0;
    int indice;
    eBicicleta bicicletaNueva;

    if(bicicletas && colores && tipos && tamB > 0 && tamC > 0 && tamT > 0 && pId)
    {
        buscarBicicletaLibre(bicicletas, tamB, &indice);
        if(indice != -1){
            //INGRESO DE DATOS

            printf("Ingrese la marca de la bicicleta: ");
            fflush(stdin);
            gets(bicicletaNueva.marca);

            while(strlen(bicicletaNueva.marca) > 20)
            {
                printf("Error en la marca. Vuelva a ingresar: ");
                fflush(stdin);
                gets(bicicletaNueva.marca);
            }

            listarTipos(tipos,tamT);
            printf("Ingrese el ID del tipo: ");
            fflush(stdin);
            scanf("%d",&bicicletaNueva.idTipo);

            while(!validarTipo(tipos, tamT, bicicletaNueva.idTipo))
            {
                printf("Error en la ID del tipo. Vuelva a ingresar: ");
                fflush(stdin);
                scanf("%d",&bicicletaNueva.idTipo);
            }

            listarColores(colores, tamC);
            printf("Ingrese el ID del color: ");
            fflush(stdin);
            scanf("%d",&bicicletaNueva.idColor);

            while(!validarColor(colores, tamC, bicicletaNueva.idColor))
            {
                printf("Error en la ID del color. Vuelva a ingresar: ");
                fflush(stdin);
                scanf("%d",&bicicletaNueva.idColor);
            }

            system("cls");

            printf("Ingrese el material de la bicicleta (c/a): ");
            fflush(stdin);
            scanf("%c", &bicicletaNueva.material);

            while(bicicletaNueva.material != 'c' && bicicletaNueva.material != 'a')
            {
                printf("Error, Ingrese un material valido de la bicicleta (c/a): ");
                fflush(stdin);
                scanf("%c", &bicicletaNueva.material);
            }

            system("cls");

            bicicletaNueva.isEmpty = 0;
            bicicletaNueva.id = *pId;
            bicicletas[indice] = bicicletaNueva;
            (*pId)++;
            todoOk = 1;
        }else{
            printf("No hay espacio disponible para el alta de bicicletas\n");
        }
    }else{
        printf("Error en los parametros del alta de bicicletas\n");
    }

    return todoOk = 1;
}

int modificarBicicleta(eBicicleta bicicletas[], int tamB, eColor colores[], int tamC, eTipo tipos[], int tamT)
{
    int todoOk = 0;
    int indice;
    int idIngresado;
    char respuestaModificar= 'n';

    if(bicicletas && colores && tipos && tamB >0 && tamC >0 && tamT >0 )
    {
        listarBicicletas(bicicletas, tamB, colores, tamC, tipos, tamT);
        printf("Ingrese el ID de la bicicleta a modificar ");
        fflush(stdin);
        scanf("%d",&idIngresado);

        if(buscarBicicleta(bicicletas, tamB, idIngresado, &indice))
        {
            if(indice != -1){
                printf("-------------------------------------------------------\n");
                printf("ID\t   Marca\tColor\t     Tipo\tMaterial\n");
                printf("-------------------------------------------------------\n");
                mostrarBicicleta(bicicletas[indice],colores,tamC,tipos,tamT);

                do{
                    switch(menuModificar())
                    {
                        case 'A':
                            listarTipos(tipos, tamT);

                            printf("Ingrese el id del nuevo tipo de bicicleta: ");
                            fflush(stdin);
                            scanf("%d",&bicicletas[indice].idTipo);

                            while(!validarTipo(tipos, tamT, bicicletas[indice].idTipo))
                            {
                                printf("Error en el id ingresado.Vuelva a ingresar \n");
                                fflush(stdin);
                                scanf("%d",&bicicletas[indice].idTipo);
                            }
                            printf("Tipo modificado de manera exitosa \n");
                            break;
                        case 'B':
                            if(bicicletas[indice].material == 'a')
                            {
                                bicicletas[indice].material = 'c';
                            }
                            else
                            {
                                bicicletas[indice].material = 'a';
                            }
                            printf("Material modificado de manera exitosa \n");
                            break;
                        case 'S':
                            respuestaModificar = 'S';
                        break;
                    }

                }while(respuestaModificar != 'S');
                todoOk = 1;

            }else
                printf("\nNo exite la bicicleta con el id: %d \n", idIngresado);
        }else{
            printf("\nProblema al buscar la bicicleta\n");
        }

    }else{
        printf("\nError en los parametros de la modificacion de la bicicleta\n");
    }

    return todoOk;
}

int bajaBicicleta(eBicicleta bicicletas[], int tamB, eColor colores[], int tamC, eTipo tipos[], int tamT)
{
    int todoOk = 0;
    int indice;
    int idIngresado;
    char respuestaBorrado='n';

    if(bicicletas && colores && tipos && tamB >0 && tamC >0 && tamT >0)
    {
        listarBicicletas(bicicletas, tamB, colores, tamC, tipos, tamT);
        printf("Ingrese la ID a dar de baja: ");
        fflush(stdin);
        scanf("%d",&idIngresado);
        if(buscarBicicleta(bicicletas,tamB,idIngresado,&indice))
        {
            if(indice != -1){
                printf("-------------------------------------------------------\n");
                printf("ID\t   Marca\tColor\t     Tipo\tMaterial\n");
                printf("-------------------------------------------------------\n");
                mostrarBicicleta(bicicletas[indice],colores,tamC,tipos,tamT);
                printf("\nConfirma baja? s-SI \n");
                fflush(stdin);
                scanf("%c",&respuestaBorrado);
                respuestaBorrado = tolower(respuestaBorrado);

                if(respuestaBorrado == 's')
                {
                    bicicletas[indice].isEmpty = 1;
                    todoOk = 1;
                }else
                {
                    printf("\nBaja cancelada \n");
                }

            }else
                printf("\nNo exite la bicicleta con el id: %d \n",idIngresado);
        }else{
            printf("\nProblema al buscar la bicicleta \n");
        }

    }else{
        printf("\nError en los parametros de la baja \n");
    }

    return todoOk;
}

int buscarBicicleta(eBicicleta bicicletas[],int tamB,int id,int* pIndice)
{
    int todoOk = 0;
    if(bicicletas && tamB >0 && pIndice)
    {
        *pIndice = -1;
        for(int i = 0; i < tamB; i++)
        {
            if(bicicletas[i].id == id && !bicicletas[i].isEmpty)
            {
                *pIndice = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int ordenarBiciletasPorTipoYMaterial(eBicicleta bicicletas[], int tamB, eTipo tipos[], int tamT)
{
    int todoOk = 0;
    char descripcionTipoActual[20];
    char descripcionTipoSiguiente[20];
    eBicicleta bicicletaAux;

    if(bicicletas && tipos && tamB >0 && tamT > 0)
    {
        for(int i = 0; i < tamB - 1; i++)
        {
            for(int j = i + 1; j < tamB; j++)
            {
                if(!bicicletas[i].isEmpty)
                {
                    cargarDescripcionTipo(tipos, tamT, bicicletas[i].idTipo, descripcionTipoActual);
                    cargarDescripcionTipo(tipos, tamT, bicicletas[j].idTipo, descripcionTipoSiguiente);
                    if((strcmp(descripcionTipoActual,descripcionTipoSiguiente) > 0)  ||
                        ((strcmp(descripcionTipoActual,descripcionTipoSiguiente) == 0) && bicicletas[i].material > bicicletas[j].material)){
                        bicicletaAux = bicicletas[i];
                        bicicletas[i] = bicicletas[j];
                        bicicletas[j] = bicicletaAux;
                    }
                }
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int listarBicicletas(eBicicleta bicicletas[], int tamB, eColor colores[], int tamC, eTipo tipos[], int tamT)
{
    int todoOk = 0;
    int hayBicicletas = 0;

    if(bicicletas && colores && tipos && tamB >0 && tamC >0 && tamT >0 )
    {
        eBicicleta bicicletasAux[tamB];
        for(int i = 0; i < tamB; i++)
        {
            bicicletasAux[i] = bicicletas[i];
        }
        ordenarBiciletasPorTipoYMaterial(bicicletasAux,tamB, tipos, tamT);
        system("cls");
        printf("\t     ***LISTADO DE BICIS***\n");
        printf("-------------------------------------------------------\n");
        printf("ID\t   Marca\tColor\t     Tipo\tMaterial\n");
        printf("-------------------------------------------------------\n");
        for(int i = 0; i < tamB; i++)
        {
            if(!bicicletasAux[i].isEmpty)
            {
                mostrarBicicleta(bicicletasAux[i], colores, tamC, tipos, tamT);
                hayBicicletas = 1;
            }

        }
        if(!hayBicicletas){
            printf("\t     No hay micros cargados \n");
        }
        printf("-------------------------------------------------------\n\n");
        todoOk= 1;
    }
    return todoOk;
}

int mostrarBicicleta(eBicicleta bicicleta, eColor colores[], int tamC, eTipo tipos[], int tamT)
{
    int todoOk = 0;
    char descripcionColor[20];
    char descripcionTipo[20];

    if(colores && tipos && tamC >0 && tamT >0)
    {
        cargarDescripcionColor(colores, tamC, bicicleta.idColor, descripcionColor);
        cargarDescripcionTipo(tipos, tamT, bicicleta.idTipo, descripcionTipo);

        printf("%d\t   %-11s\t%-12s %-10s %c\n",bicicleta.id, bicicleta.marca, descripcionColor, descripcionTipo, bicicleta.material);
        todoOk = 1;
    }
    return todoOk;
}
