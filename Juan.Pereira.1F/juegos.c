#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libreria.h"
#include "juegos.h"

#define OCUPADO 0
#define VACIO 1

int iniciarJuegos(eJuego* lista, int TAM_JUEGOS){
    int retorno = -1;
    if(TAM_JUEGOS > 0 && lista != NULL){
        retorno = 0;
        for(int contador=0; contador < TAM_JUEGOS; contador++){
            (lista+contador)->isEmpty = VACIO;
        }
    }
    return retorno;
}

int buscarLibreJuegos(eJuego* lista, int TAM_JUEGOS){
    int indice = -1;
    if(TAM_JUEGOS > 0 && lista != NULL){
        indice = -2;
        for(int contador=0; contador < TAM_JUEGOS; contador++){
            if((lista+contador)->isEmpty == VACIO){
                indice = contador;
                break;
            }
        }
    }
    return indice;
}

int buscarJuego(eJuego* lista, int TAM_JUEGOS, int codigo){
    int indice = -1;
    if(TAM_JUEGOS > 0 && lista != NULL){
        indice = -2;
        for(int contador=0; contador < TAM_JUEGOS; contador++){
            if((lista+contador)->idJuego == codigo && (lista+contador)->isEmpty == OCUPADO){
                indice = contador;
                break;
            }
        }
    }
    return indice;
}

int comprobarRegistroJuegos(eJuego* lista, int TAM_JUEGOS){
    int bandera = -1;
    if(TAM_JUEGOS > 0 && lista != NULL){
        for(int contador=0; contador < TAM_JUEGOS; contador++){
            if((lista+contador)->isEmpty == OCUPADO){
                bandera = contador;
                break;
            }
        }
    }
    return bandera;
}

void mostrarJuego(eJuego* juego){
    printf("%3d   %22s  %9.2f\n", juego->idJuego, juego->descripcion, juego->importe);
}

int mostrarListadoDeJuegos(eJuego* lista, int TAM_JUEGOS){
    int retorno = -1;
    printf("   ****  Listado de Juegos  **** \n\n");
    printf("Codigo         Descripcion      Importe\n\n");
    if(TAM_JUEGOS > 0 && lista != NULL){
        retorno = 0;
        for(int contador=0; contador < TAM_JUEGOS; contador++){
            if((lista+contador)->isEmpty == 0){
                mostrarJuego(lista+contador);
            }
        }
    }
    printf("\n");
    return retorno;
}

int menuSeleccionarJuego(eJuego* lista, int TAM_JUEGOS){
    int opcion;
    int* control = (int*) malloc(sizeof(int));
    if(lista != NULL && TAM_JUEGOS > 0){
        system("cls");
        mostrarListadoDeJuegos(lista, TAM_JUEGOS);
        *control = getInt(&opcion, "\nSeleccione Juego: ", "Error, ingrese un juego de la lista: ", 1, TAM_JUEGOS, 3);
        if(*control == 0){
            opcion = 0;
        }
    }
    free(control);
    return opcion;
}

int ingresarJuego(eJuego* lista, int TAM_JUEGOS){
    int* indice = (int*) malloc(sizeof(int));
    int control;
    eJuego* nuevoJuego = (eJuego*) malloc(sizeof(eJuego));

    *indice = buscarLibreJuegos(lista, TAM_JUEGOS);
    system("cls");
    printf("*** Alta Juegos ***\n\n");
    if(*indice == -1){
        control = -1;
    }else{
        nuevoJuego->idJuego = (*indice) + 1;
        control = getDomicilio(nuevoJuego->descripcion, "Ingrese descripcion: ", "Error, ingrese solo letras respetando el rango (3 - 30): ", 3, 30, 3);
        if(control == 0){
            printf("\nSe agotaron las chances y no se pudo ingresar la descripcion.\n\n");
        }else{
            control = getFloat(&nuevoJuego->importe, "Ingrese importe: ", "Error, ingrese solo numeros respetando el rango (100.00 - 500.00): ", 100, 500, 3);
            if(control == 0){
                printf("\nSe agotaron las chances y no se pudo ingresar el importe.\n\n");
            }else{
                (lista+(*indice))->idJuego = nuevoJuego->idJuego;
                strcpy((lista+(*indice))->descripcion, nuevoJuego->descripcion);
                (lista+(*indice))->importe = nuevoJuego->importe;
                (lista+(*indice))->isEmpty = 0;
            }
        }
    }
    free(indice);
    free(nuevoJuego);
    return control;
}

int modificarJuego(eJuego* lista, int TAM_JUEGOS, int *codigo){
    int* indice = (int*) malloc(sizeof(int));
    int* control = (int*) malloc(sizeof(int));
    int bandera = 0;
    char* seguir = (char*) malloc(sizeof(char));

    system("cls");
    printf("  *** Modificar juego ***\n\n");
    *control = getInt(codigo, "Ingrese codigo de juego: ", "Error, ingrese solo numeros respetando el rango (1 - 10): ", 1, TAM_JUEGOS, 3);
    if(*control != 1){
        bandera = 0;
        printf("\nNo se obtuvo el codigo de juego.");
    }else{
        *indice = buscarJuego(lista, TAM_JUEGOS, *codigo);
        if(*indice == -1){
            bandera = -1;
        }else{
            printf("Codigo   Descripcion   Importe\n\n");
            mostrarJuego((lista+(*indice)));
            *control = getCharResp(seguir, "\nDesea modificar algun campo? s/n: ", "Error, solo debe ingresar 's' o 'n', reingrese: ", 3);
            if(*control == 0){
                printf("\nSe agotaron las chances y no se pudo obtener la respuesta.");
            }else{
                if(*seguir == 'n' || *seguir == 'N'){
                    bandera = 0;
                }else{
                    bandera = menuModificarJuego(lista, *indice, TAM_JUEGOS);
                }
            }
        }
    }
    free(indice);
    free(control);
    free(seguir);
    return bandera;
}

int menuModificarJuego(eJuego* lista, int indice, int TAM_JUEGOS){ // bien!
    int* opcion = (int*) malloc(sizeof(int));
    int control;
    char* nuevaDesc = (char*) malloc(sizeof(char)*51);
    float* nuevoImporte = (float*) malloc(sizeof(float));

    system("cls");
    printf("\nSeleccione el campo que desea modificar: \n\n");
    printf(" 1- Descripcion\n");
    printf(" 2- Importe\n");
    control = getInt(opcion, "Ingrese opcion: ", "Error, opcion invalida. Reingrese: ", 1, 2, 3);
    switch(*opcion){
        case 1:
            control = getString(nuevaDesc, "\n\nIngrese nueva descripcion: ", "Error, ingrese solo letras respetando el rango (3 a 50): ", 3, 50, 3);
            if(control == 0){
                printf("\nNo se pudo registrar la descripcion!");
            }else{
                strcpy((lista+indice)->descripcion, nuevaDesc);
            }
            break;
        case 2:
            control = getFloat(nuevoImporte, "\n\nIngrese nuevo importe: ", "\nError, ingrese solo numeros respetando el rango (100 - 500): ", 100, 500, 3);
            if(control == 0){
                printf("\nNo se pudo registrar el importe!\n");
            }else{
                (lista+indice)->importe = *nuevoImporte;
            }
            break;
        default:
            break;
    }
    free(opcion);
    free(nuevaDesc);
    free(nuevoImporte);
    return control;
}

int bajaJuego(eJuego* lista, int TAM_JUEGOS, int *codigo){
    int* indice = (int*) malloc(sizeof(int));
    int* control = (int*) malloc(sizeof(int));
    int bandera;
    char* seguir = (char*) malloc(sizeof(char));

    system("cls");
    printf("  *** Baja Juego ***\n\n");
    *control = getInt(codigo, "Ingrese codigo de Juego: ", "Error, ingrese solo numeros respetando el rango (1 - 10): ", 1, TAM_JUEGOS, 3);
    if(*control != 1){
        bandera = 0;
        printf("\nNo se obtuvo el codigo de Juego.");
    }else{
        *indice = buscarJuego(lista, TAM_JUEGOS, *codigo);
        if(*indice == -1){
            bandera = -1;
        }else{
            printf("\nCodigo   Descripcion  Importe\n\n");
            mostrarJuego((lista+(*indice)));
            *control = getCharResp(seguir, "\nConfirma baja? s/n: ", "Error, solo debe ingresar 's' o 'n', reingrese: ", 3);
            if(*seguir == 'n' || *seguir == 'N'){
                bandera = 0;
            }else{
                (lista+(*indice))->isEmpty = 1;
                bandera = 1;
            }
        }
    }
    free(indice);
    free(control);
    free(seguir);
    return bandera;
}

void hardcodearJuegos(eJuego* lista, int TAM_JUEGOS){
    int* contador = (int*) malloc(sizeof(int));
    eJuego nuevaLista[10] ={
        { 1, "bodoo", 150, 0},
        { 2, "bingo", 120, 0},
        { 3, "pictionary", 160, 0},
        { 4, "ajedrez", 120, 0},
        { 5, "ludo", 150, 0},
        { 6, "chin-chon", 140, 0},
        { 7, "billar", 180, 0},
        { 8, "generala", 140, 0},
        { 9, "TEG", 170, 0},
        { 10, "cadabra", 130, 0}
    };
    for(*contador = 0; *contador < TAM_JUEGOS; (*contador)++){
        *(lista+(*contador)) = *(nuevaLista+(*contador));
    }
    free(contador);
}
