#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "fecha.h"
#include "tipo.h"
#include "bicicleta.h"
#include "servicio.h"
#include "color.h"
#include "trabajo.h"

#define TAM_T 4
#define TAM_C 5
#define TAM_S 4
#define TAMB 20

int menu();
int confirmarSalir(char* pVariable);

int main()
{
    int idBicicleta = 1000;
    char salir = 'n';

    eTipo tipos[TAM_T] =   {{1000, "Rutera"},
                            {1001, "Carrera"},
                            {1002, "Mountain"},
                            {1003, "BMX"}};

    eColor colores[TAM_C] = {{5000, "Gris"},
                            {5001, "Blanco"},
                            {5002, "Azul"},
                            {5003, "Negro"},
                            {5004, "Rojo"}};

    eServicio servicios[TAM_S] = {{20000, "Limpieza", 30},
                                 {20001, "Parche", 400},
                                 {20002, "Centrado", 500},
                                 {20003, "Cadena", 450}};

    eBicicleta bicicletas[TAMB];
    inicializarBicicletas(bicicletas, TAMB);
    hardcodearBicicletas(bicicletas, TAMB, 4, &idBicicleta);
    do
    {
        switch(menu())
        {
        case 'A':
            if(altaBicicleta(bicicletas, TAMB, colores, TAM_C, tipos, TAM_T, &idBicicleta))
            {
                printf("Alta de bicicleta de manera exitosa \n\n");
                system("pause");
            }
            else
            {
                printf("No se pudo realizar el alta de la bicicleta \n\n");
                system("pause");
            }
            break;
        case 'B':
            if(modificarBicicleta(bicicletas, TAMB, colores, TAM_C, tipos, TAM_T))
            {
                printf("Se modifico la bicicleta de manera exitosa \n");
            }
            else
            {
                printf("No se pudo modificar el la bicicleta \n");
            }
            break;
        case 'C':
            if(bajaBicicleta(bicicletas, TAMB, colores, TAM_C, tipos, TAM_T))
            {
                printf("La baja se realizo de manera exitosa \n");
            }
            else
            {
                printf("No se pudo la baja de la bicicleta \n");
            }
            break;
        case 'D':
            listarBicicletas(bicicletas, TAMB, colores, TAM_C, tipos, TAM_T);
            system("\npause");
            break;
        case 'E':
            listarTipos(tipos, TAM_T);
            system("\npause");
            break;
        case 'F':
            listarColores(colores, TAM_C);
            system("\npause");
            break;
        case 'G':
            listarServicios(servicios, TAM_S);
            system("\npause");
            break;
        case 'H':

            break;
        case 'I':

            break;
        case 'J':
            confirmarSalir(&salir);
            break;
        }
    }
    while(salir == 'n');

    return 0;
}


