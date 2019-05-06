#include <stdio.h>
#include <stdlib.h>
#include "libreria.h"
#include "juegos.h"
#include "fechas.h"
#include "alquileres.h"

#define OCUPADO 0
#define VACIO 1

int iniciarAlquileres(eAlquiler* lista, int TAM_ALQUILERES){ // bien!
    int retorno = -1;
    if(TAM_ALQUILERES > 0 && lista != NULL){
        retorno = 0;
        for(int contador=0; contador < TAM_ALQUILERES; contador++){
            (lista+contador)->isEmpty = 1;
        }
    }
    return retorno;
}

int buscarLibreAlquileres(eAlquiler* lista, int TAM_ALQUILERES){
    int indice = -1;
    if(TAM_ALQUILERES > 0 && lista != NULL){
        indice = -2;
        for(int contador=0; contador < TAM_ALQUILERES; contador++){
            if((lista+contador)->isEmpty == 1){
                indice = contador;
                break;
            }
        }
    }
    return indice;
}

int buscarAlquiler(eAlquiler* lista, int TAM_ALQUILERES, int codigo){
    int indice = -1;
    if(TAM_ALQUILERES > 0 && lista != NULL){
        indice = -2;
        for(int contador=0; contador < TAM_ALQUILERES; contador++){
            if((lista+contador)->idAlquiler == codigo && (lista+contador)->isEmpty == OCUPADO){
                indice = contador;
                break;
            }
        }
    }
    return indice;
}

int comprobarRegistroAlquiler(eAlquiler* lista, int TAM_ALQUILERES){
    int bandera = -1;
    if(TAM_ALQUILERES > 0 && lista != NULL){
        for(int contador=0; contador < TAM_ALQUILERES; contador++){
            if((lista+contador)->isEmpty == OCUPADO){
                bandera = contador;
                break;
            }
        }
    }
    return bandera;
}

void mostrarAlquiler(eAlquiler* alquiler){
    if(alquiler != NULL){
        printf("%6d %14d %14d   %8d/%d/%d\n", alquiler->idAlquiler, alquiler->codigoJuego, alquiler->codigoCliente, alquiler->fecha.dia, alquiler->fecha.mes, alquiler->fecha.anio);
    }
}

void mostrarListadoDeAlquileres(eAlquiler* lista, int TAM_ALQUILERES){
    if(TAM_ALQUILERES > 0 && lista != NULL){
        printf("   ****  Listado de Alquileres  **** \n\n");
        printf("Cod. Alquiler   Cod. Juego   Cod. Cliente      Fecha\n\n");
        for(int contador=0; contador < TAM_ALQUILERES; contador++){
            if((lista+contador)->isEmpty == 0){
                mostrarAlquiler(lista+contador);
            }
        }
        printf("\n");
    }
}

int ingresarAlquiler(eAlquiler* lista, int TAM_ALQUILERES, eCliente* clientes, int TAM_CLIENTES, eJuego* juegos, int TAM_JUEGOS){
    int* indice = (int*) malloc(sizeof(int));
    int control;
    int* auxCodCliente = (int*) malloc(sizeof(int));
    char* answer = (char*) malloc(sizeof(char));
    eAlquiler* nuevoAlquiler = (eAlquiler*) malloc(sizeof(eAlquiler));
    eFecha* nuevaFecha = (eFecha*) malloc(sizeof(eFecha));;

    if(lista != NULL && clientes != NULL && juegos != NULL){
        *indice = buscarLibreAlquileres(lista, TAM_ALQUILERES);
        system("cls");
        printf("*** Alta Alquiler ***\n\n");
        if(*indice == -1){
            control = -1;
        }else{
            nuevoAlquiler->idAlquiler = *indice + 1;
            control = menuSeleccionarJuego(juegos, TAM_JUEGOS);
            if(control == 0){
                printf("\nSe agotaron las chances y no se pudo ingresar el codigo de juego.\n");
            }else{
                nuevoAlquiler->codigoJuego = control;
                control = getInt(auxCodCliente, "Ingrese codigo de cliente: ", "Error, ingrese solo numeros respetando el rango (1 - 10): ", 1, 10, 3);
                *indice = buscarCliente(clientes, TAM_CLIENTES, *auxCodCliente);
                if(*indice == -1){
                    printf("\nNo se encontro el cliente correspondiente al codigo %i", *auxCodCliente);
                }else{
                    nuevoAlquiler->codigoCliente = *auxCodCliente;
                    printf("Codigo    Apellido   Nombre   Sexo    Domicilio\n");
                    mostrarCliente(clientes+(*indice));
                    control = getCharResp(answer, "\nConfirmar cliente?.. s/n: ", "Error, ingrese 's' o 'n': ", 3);
                    if(*answer == 'n' || *answer == 'N'){
                        control = 0;
                        printf("\nNo confirmo el cliente.\n");
                    }else{
                        getFecha(nuevaFecha);
                        if(control == 0){
                            printf("\nLa fecha no se cargo correctamente.\n");
                        }else{
                            nuevoAlquiler->fecha = *nuevaFecha;
                            nuevoAlquiler->isEmpty = OCUPADO;
                            *(lista+(*indice)) = *nuevoAlquiler;
                        }
                    }
                }
            }
        }
    }
    free(indice);
    free(nuevaFecha);
    free(auxCodCliente);
    free(answer);
    free(nuevoAlquiler);
    return control;
}

int ModificarAlquiler(eAlquiler* lista, int TAM_ALQUILERES, int *codigo){
    int* indice = (int*) malloc(sizeof(int));
    int* control = (int*) malloc(sizeof(int));
    int bandera;
    char* seguir = (char*) malloc(sizeof(char));

    if(TAM_ALQUILERES > 0 && lista != NULL){
        system("cls");
        printf("  *** Modificar Alquiler ***\n\n");
        *control = getInt(codigo, "Ingrese codigo de Alquiler: ", "Error, ingrese solo numeros respetando el rango (1 - 10): ", 1, TAM_ALQUILERES, 3);
        if(*control != 1){
            bandera = 0;
            printf("\nNo se obtuvo el codigo de Alquiler.");
        }else{
            *indice = buscarAlquiler(lista, TAM_ALQUILERES, *codigo);
            if(*indice == -1){
                bandera = -1;
            }else{
                printf("Cod. Alquiler   Cod. Juego   Cod. Cliente     Fecha\n");
                mostrarAlquiler(lista+(*indice));
                *control = getCharResp(seguir, "\nDesea modificar algun campo? s/n: ", "Error, solo debe ingresar 's' o 'n', reingrese: ", 3);
                if(*control == 0){
                    bandera = 0;
                }else{
                    if(*seguir == 'n' || *seguir == 'N'){
                        bandera = 0;
                    }else{
                        bandera = menuModificarAlquiler(lista, *indice);
                    }
                }
            }
        }
    }
    free(indice);
    free(control);
    free(seguir);
    return bandera;
}

int menuModificarAlquiler(eAlquiler* lista, int indice){
    int* opcion = (int*) malloc(sizeof(int));
    int control;
    int* nuevoCodigoJuego = (int*) malloc(sizeof(int));
    int* nuevoCodigoCliente = (int*) malloc(sizeof(int));

    if(lista != NULL){
        system("cls");
        printf("\nSeleccione el campo que desea modificar: \n\n");
        printf(" 1- Codigo de Juego\n");
        printf(" 2- Codigo de Cliente\n");
        printf(" 3- Fecha\n\n");
        control = getInt(opcion, "Ingrese opcion: ", "Error, opcion invalida. Reingrese: ", 1, 3, 3);
        switch(*opcion){
            case 1:
                control = getInt(nuevoCodigoJuego, "\n\nIngrese nuevo codigo de juego: ", "Error, ingrese solo numeros respetando el rango (1 a 10): ", 1, 10, 3);
                if(control == 0){
                    printf("\nNo se pudo registrar el codigo de juego!");
                }else{
                    (lista+indice)->codigoJuego = *nuevoCodigoJuego;
                }
                break;
            case 2:
                control = getInt(nuevoCodigoCliente, "\n\nIngrese nuevo codigo de cliente: ", "Error, ingrese solo numeros respetando el rango (1 a 10): ", 1, 10, 3);
                if(control == 0){
                    printf("\nNo se pudo registrar el codigo de cliente!\n");
                }else{
                    (lista+indice)->codigoCliente = *nuevoCodigoCliente;
                }
                break;
            case 3:
                control = ingresarFecha((lista+indice)->fecha);
                if(control == 0){
                    printf("\nNo se registro la fecha.\n\n");
                }else{
                    printf("\nFecha modificada con exito!");
                }
                break;
        }
    }
    free(nuevoCodigoCliente);
    free(nuevoCodigoJuego);
    free(opcion);
    return control;
}

int bajaAlquiler(eAlquiler* lista, int TAM_ALQUILERES, int *codigo){
    int* indice = (int*) malloc(sizeof(int));
    int* control = (int*) malloc(sizeof(int));
    int bandera;
    char* seguir = (char*) malloc(sizeof(char));

    if(TAM_ALQUILERES > 0 && lista != NULL){
        system("cls");
        printf("  *** Baja Alquiler ***\n\n");
        *control = getInt(codigo, "Ingrese codigo de Alquiler: ", "Error, ingrese solo numeros respetando el rango (1 - 10): ", 1, TAM_ALQUILERES, 3);
        if(*control != 1){
            bandera = 0;
            printf("\nNo se obtuvo el codigo de Alquiler.");
        }else{
            *indice = buscarAlquiler(lista, TAM_ALQUILERES, *codigo);
            if(*indice == -1){
                bandera = -1;
            }else{
                printf("Cod. Alquiler   Cod. Juego   Cod. Cliente     Fecha\n");
                mostrarAlquiler(lista+(*indice));
                *control = getCharResp(seguir, "\nConfirma baja? s/n: ", "Error, solo debe ingresar 's' o 'n', reingrese: ", 3);
                if(*seguir == 'n' || *seguir == 'N'){
                    bandera = 0;
                }else{
                    (lista+(*indice))->isEmpty = VACIO;
                    bandera = 1;
                }
            }
        }
    }
    free(indice);
    free(control);
    free(seguir);
    return bandera;
}

void hardcodearAlquileres(eAlquiler* lista, int TAM_ALQUILERES){
    int* contador = (int*) malloc(sizeof(int));
    eAlquiler nuevaLista[12] ={
        { 1, 3, 2, {12, 1, 2018}, 0},
        { 2, 6, 6, {17, 2, 2018}, 0},
        { 3, 1, 1, {23, 2, 2018}, 0},
        { 4, 4, 4, {7, 3, 2018}, 0},
        { 5, 7, 3, {3, 4, 2018}, 0},
        { 6, 5, 7, {12, 4, 2018}, 0},
        { 7, 10, 2, {21, 5, 2018}, 0},
        { 8, 1, 5, {29, 5, 2018}, 0},
        { 9, 9, 1, {10, 6, 2018}, 0},
        { 10, 5, 3, {15, 7, 2018}, 0},
        { 11, 3, 3, {15, 7, 2018}, 0},
        { 12, 5, 3, {21, 7, 2018}, 0}
    };
    for(*contador = 0; *contador < TAM_ALQUILERES; (*contador)++){
        *(lista+(*contador)) = *(nuevaLista+(*contador));
    }
    free(contador);
}

float total_y_promedio_importes_de_juegos_alquilados(eAlquiler *lista, int TAM_ALQUILERES, eJuego* juegos, int TAM_JUEGOS){
    float* acumImporte = (float*) malloc(sizeof(float));
    int* cantJuegos = (int*) malloc(sizeof(int));
    int* contador = (int*) malloc(sizeof(int));
    int* count = (int*) malloc(sizeof(int));
    float promedio;
    *acumImporte = 0;
    *cantJuegos = 0;
    if(lista != NULL && juegos != NULL){
        for(*contador=0; *contador < TAM_ALQUILERES; (*contador)++){
            if((lista+(*contador))->isEmpty == OCUPADO){
                for(*count = 0; *count < TAM_JUEGOS; (*count)++){
                    *acumImporte = *acumImporte + (juegos+(*count))->importe;
                    (*cantJuegos)++;
                }
            }
        }
    }
    promedio = *acumImporte / (float) (*cantJuegos);
    printf("El total de importes por juegos alquilados es: %.2f\nEl promedio de importes por juegos alquilados es: %.2f\n\n", *acumImporte, promedio);
    free(acumImporte);
    free(cantJuegos);
    free(contador);
    free(count);
    return promedio;
}
