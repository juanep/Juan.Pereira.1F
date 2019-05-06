#include <stdio.h>
#include <stdlib.h>
#include "fechas.h"
#include "juegos.h"
#include "libreria.h"
#include "clientes.h"
#include "alquileres.h"

#define VACIO 1
#define OCUPADO 0
#define TAM_FECHAS 10
#define TAM_JUEGOS 10
#define TAM_FECHAS 10
#define TAM_CLIENTES 12
#define TAM_ALQUILERES 10

int main()
{
    // Reserva Dinámica
    int* ok = (int*) malloc(sizeof(int));
    int* flagClientes = (int*) malloc(sizeof(int));
    int* flagJuegos = (int*) malloc(sizeof(int));
    int* flagAlquileres = (int*) malloc(sizeof(int));
    int* codigo = (int*) malloc(sizeof(int));
    char* resp = (char*) malloc(sizeof(char));
    char* bandera = (char*) malloc(sizeof(char));
    eCliente* clientes = (eCliente*) malloc(sizeof(eCliente)*TAM_CLIENTES);
    eJuego* juegos = (eJuego*) malloc(sizeof(eJuego)*TAM_JUEGOS);
    eAlquiler* alquileres = (eAlquiler*) malloc(sizeof(eAlquiler)*TAM_ALQUILERES);
    eFecha* fechas = (eFecha*) malloc(sizeof(eFecha)*TAM_FECHAS);

    // Inicializar
    iniciarClientes(clientes, TAM_CLIENTES);
    iniciarJuegos(juegos, TAM_JUEGOS);
    iniciarFechas(fechas, TAM_FECHAS);
    iniciarAlquileres(alquileres, TAM_ALQUILERES);
    hardcodearJuegos(juegos, TAM_JUEGOS);
    hardcodearClientes(clientes, TAM_CLIENTES);

    do{
        switch(menu()){
            case 1: *flagClientes = ingresarCliente(clientes, TAM_CLIENTES);
                if(*flagClientes == -1){
                    printf("\nNo se encontro espacio para el registro.\n\n");
                }else{
                    if(*flagClientes == 0){
                        printf("\nAlta cancelada.\n\n");
                    }else{
                        printf("\nAlta exitosa.\n\n");
                    }
                }
                break;
            case 2: *flagClientes = comprobarRegistroClientes(clientes, TAM_CLIENTES);
                if(*flagClientes == -1){
                    printf("\nHasta el momento no se ha registrado ningun cliente.\n\n");
                }else{
                    *ok = modificarCliente(clientes, TAM_CLIENTES, codigo);
                    if(*ok == -1){
                        printf("\nNo se encontro cliente correspondiente al codigo %i.\n\n", codigo);
                    }else{
                        if(*ok == 0){
                            printf("\nModificacion cancelada.\n\n");
                        }else{
                            printf("\nModificacion exitosa.\n\n");
                        }
                    }
                }
                break;
            case 3: *flagClientes = comprobarRegistroClientes(clientes, TAM_CLIENTES);
                if(*flagClientes == -1){
                    printf("\nHasta el momento no se ha registrado ningun cliente.\n\n");
                }else{
                    *ok = bajaCliente(clientes, TAM_CLIENTES, codigo);
                    if(*ok == -1){
                        printf("\nNo se encontro cliente correspondiente al codigo %i.\n\n", codigo);
                    }else{
                        if(*ok == 0){
                            printf("\nBaja cancelada.\n\n");
                        }else{
                            printf("\nBaja exitosa.\n\n");
                        }
                    }
                }
                break;
            case 4: *flagClientes = comprobarRegistroClientes(clientes, TAM_CLIENTES);
                if(*flagClientes == -1){
                    printf("\nHasta el momento no se ha registrado ningun cliente.\n\n");
                }else{
                    system("cls");
                    mostrarListadoDeClientes(clientes, TAM_CLIENTES);
                }
                break;
            case 5: *flagJuegos = ingresarJuego(juegos, TAM_JUEGOS);
                if(*flagJuegos == -1){
                    printf("\nNo se encontro espacio para el registro.\n\n");
                }else{
                    if(*flagJuegos == 0){
                        printf("\nAlta cancelada.\n\n");
                    }else{
                        printf("\nAlta exitosa.\n\n");
                    }
                }
                break;
            case 6: *flagJuegos = comprobarRegistroJuegos(juegos, TAM_JUEGOS);
                if(*flagJuegos == -1){
                    printf("\nHasta el momento no se ha registrado ningun juego.\n\n");
                }else{
                    *ok = modificarJuego(juegos, TAM_JUEGOS, codigo); //modificar juego !
                    if(*ok == -1){
                        printf("\nNo se encontro alquiler correspondiente al codigo %i.\n\n", *codigo);
                    }else{
                        if(*ok == 0){
                            printf("\nModificacion cancelada.\n");
                        }else{
                            printf("\nModificacion exitosa!\n");
                        }
                    }
                }
                break;
            case 7: *flagJuegos = comprobarRegistroJuegos(juegos, TAM_JUEGOS);
                if(*flagJuegos == -1){
                    printf("\nHasta el momento no se ha registrado ningun Juego.\n\n");
                }else{
                    *ok = bajaJuego(juegos, TAM_JUEGOS, codigo);
                    if(*ok == -1){
                        printf("\nNo se encontro juego correspondiente al codigo %i.\n\n", *codigo);
                    }else{
                        if(*ok == 0){
                            printf("\nBaja cancelada.\n");
                        }else{
                            printf("\nBaja exitosa.\n");
                        }
                    }
                }
                break;
            case 8: *flagJuegos = comprobarRegistroJuegos(juegos, TAM_JUEGOS);
                if(*flagJuegos == -1){
                    printf("\nHasta el momento no se ha registrado ningun juego.\n\n");
                }else{
                    system("cls");
                    mostrarListadoDeJuegos(juegos, TAM_JUEGOS);
                }
                break;
            case 9:
                if(*flagClientes == -1){
                    printf("\nNo se ha registrado ningun cliente\n");
                    *flagAlquileres = -1;
                }
                else if(*flagJuegos == -1){
                    printf("\nNo se ha registrado ningun juego\n");
                    *flagAlquileres = -1;
                }
                else{
                    *flagAlquileres = ingresarAlquiler(alquileres, TAM_ALQUILERES, clientes, TAM_CLIENTES, juegos, TAM_JUEGOS);
                }
                if(*flagAlquileres == -1){
                    printf("\nNo se encontro espacio para el registro.\n\n");
                }else{
                    if(*flagAlquileres == 0){
                        printf("\nAlta cancelada.\n\n");
                    }else{
                        printf("\nAlta exitosa.\n\n");
                    }
                }
                break;
            case 10: *flagAlquileres = comprobarRegistroAlquiler(alquileres, TAM_ALQUILERES);
                if(*flagAlquileres == -1){
                    printf("\nHasta el momento no se ha registrado ningun Alquiler.\n\n");
                }else{
                    *ok = ModificarAlquiler(alquileres, TAM_ALQUILERES, codigo);
                    if(*ok == -1){
                        printf("\nNo se encontro alquiler correspondiente al codigo %i.\n\n", *codigo);
                    }else{
                        if(*ok == 0){
                            printf("\nModificacion cancelada.\n");
                        }else{
                            printf("\nModificacion exitosa!\n");
                        }
                    }
                }
                break;
            case 11: *flagAlquileres = comprobarRegistroAlquiler(alquileres, TAM_ALQUILERES);
                if(*flagAlquileres == -1){
                    printf("\nHasta el momento no se ha registrado ningun Alquiler.\n\n");
                }else{
                    *ok = bajaAlquiler(alquileres, TAM_ALQUILERES, codigo);
                    if(*ok == -1){
                        printf("\nNo se encontro alquiler correspondiente al codigo %i.\n\n", codigo);
                    }else{
                        if(*ok == 0){
                            printf("\nBaja cancelada.\n");
                        }else{
                            printf("\nBaja exitosa.\n");
                        }
                    }
                }
                break;
            case 12: *flagAlquileres = comprobarRegistroAlquiler(alquileres, TAM_ALQUILERES);
                if(*flagAlquileres == -1){
                    printf("\nHasta el momento no se ha registrado ningun alquiler.\n\n");
                }else{
                    system("cls");
                    mostrarListadoDeAlquileres(alquileres, TAM_ALQUILERES);
                }
                break;
            case 20:
                printf("\nSalir.\n");
                *bandera = 1;
                break;
            default: printf("\nopcion invalida!\n\n");

        }
        if(*bandera == 1){
            *resp = 'n';
        }else{
            getCharResp(resp, "\nDesea continuar?.. s/n: ", "Error, ingrese solo 's' o 'n': ", 3);
        }
        system("pause");
    }while(*resp == 's' || *resp == 'S');

    free(ok);
    free(flagJuegos);
    free(flagClientes);
    free(flagAlquileres);
    free(resp);
    free(fechas);
    free(codigo);
    free(bandera);
    free(juegos);
    free(clientes);
    free(alquileres);
    return 0;
}
