#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libreria.h"
#include "clientes.h"

#define OCUPADO 0
#define VACIO 1

int iniciarClientes(eCliente* lista, int TAM_CLIENTES){
    int retorno = -1;
    if(TAM_CLIENTES > 0 && lista != NULL){
        retorno = 0;
        for(int contador=0; contador < TAM_CLIENTES; contador++){
            (lista+contador)->isEmpty = VACIO;
        }
    }
    return retorno;
}

int buscarLibreClientes(eCliente* lista, int TAM_CLIENTES){
    int indice = -1;
    if(TAM_CLIENTES > 0 && lista != NULL){
        indice = -2;
        for(int contador=0; contador < TAM_CLIENTES; contador++){
            if((lista+contador)->isEmpty == VACIO){
                indice = contador;
                break;
            }
        }
    }
    return indice;
}

int buscarCliente(eCliente* lista, int TAM_CLIENTES, int codigo){
    int indice = -1;
    if(TAM_CLIENTES > 0 && lista != NULL){
        indice = -2;
        for(int contador=0; contador < TAM_CLIENTES; contador++){
            if((lista+contador)->idCliente == codigo && (lista+contador)->isEmpty == OCUPADO){
                indice = contador;
                break;
            }
        }
    }
    return indice;
}

int comprobarRegistroClientes(eCliente* lista, int TAM_CLIENTES){
    int bandera = -1;
    if(TAM_CLIENTES > 0 && lista != NULL){
        for(int contador=0; contador < TAM_CLIENTES; contador++){
            if((lista+contador)->isEmpty == OCUPADO){
                bandera = contador;
                break;
            }
        }
    }
    return bandera;
}

int ingresarCliente(eCliente* lista, int TAM_CLIENTES){
    int* indice = (int*) malloc(sizeof(int));
    int control;
    eCliente* nuevoCliente = (eCliente*) malloc(sizeof(eCliente));

    if(nuevoCliente == NULL || lista == NULL){
        printf("No se consiguio memoria.\n");
        exit(1);
    }else{
        *indice = buscarLibreClientes(lista, TAM_CLIENTES);
        system("cls");
        printf("*** Alta cliente ***\n\n");
        if(*indice == -1){
            control = -1;
        }else{
            nuevoCliente->idCliente = *indice + 1;
            control = getNombre(nuevoCliente->apellido, "Ingrese apellido: ", "Error, ingrese solo letras respetando el rango (3 - 51): ", 30, 3);
            if(control == 0){
                printf("\nSe agotaron las chances y no se pudo ingresar el apellido.\n\n");
            }else{
                control = getNombre(nuevoCliente->nombre, "Ingrese nombre: ", "Error, ingrese solo letras respetando el rango (3 - 51): ", 30, 3);
                if(control == 0){
                    printf("\nSe agotaron las chances y no se pudo ingresar el nombre.\n\n");
                }else{
                    control = getCharSexo(&nuevoCliente->sexo, "Ingrese sexo: ", "Error, ingrese solo f o m: ", 3);
                    if(control == 0){
                        printf("\nSe agotaron las chances y no se pudo ingresar el sexo.\n\n");
                    }else{
                        control = getDomicilio(nuevoCliente->domicilio, "Ingrese domicilio: ", "Error, ingrese letras o numeros respetando el rango (3 - 50): ", 3, 50, 3);
                        if(control == 0){
                            printf("\nSe agotaron las chances y no se pudo ingresar el domicilio.\n\n");
                        }else{
                            nuevoCliente->isEmpty = OCUPADO;
                            *(lista+(*indice)) = *nuevoCliente;
                        }
                    }
                }
            }
        }
    }
    free(indice);
    free(nuevoCliente);
    return control;
}

void mostrarCliente(eCliente* cliente){
    printf("%4d %10s  %10s  %5c   %10s\n", cliente->idCliente, cliente->apellido, cliente->nombre, cliente->sexo, cliente->domicilio);
}

int mostrarListadoDeClientes(eCliente* lista, int TAM_CLIENTES){
    int retorno = -1;
    printf("   ****  Listado de Clientes  **** \n\n");
    printf("Codigo    Apellido   Nombre   Sexo    Domicilio\n\n");
    if(TAM_CLIENTES > 0 && lista != NULL){
        retorno = 0;
        for(int contador=0; contador < TAM_CLIENTES; contador++){
            if((lista+contador)->isEmpty == 0){
                mostrarCliente(lista+contador);
            }
        }
    }
    printf("\n");
    return retorno;
}

int menuModificarCliente(eCliente* lista, int indice, int TAM_CLIENTES){ // bien!
    int* opcion = (int*) malloc(sizeof(int));
    int control;
    char* nuevoApellido = (char*) malloc(sizeof(char)*52);
    char* nuevoNombre = (char*) malloc(sizeof(char)*52);
    char* nuevoSexo = (char*) malloc(sizeof(char));
    char* nuevoDomicilio = (char*) malloc(sizeof(char)*52);
    if(lista != NULL && TAM_CLIENTES > 0){
        system("cls");
        printf("\nSeleccione el campo que desea modificar: \n\n");
        printf(" 1- Apellido\n");
        printf(" 1- Nombre\n");
        printf(" 2- Sexo\n");
        printf(" 3- Domicilio\n\n");
        control = getInt(opcion, "Ingrese opcion: ", "Error, opcion invalida. Reingrese: ", 1, 3, 3);
        switch(*opcion){
        case 1:
            if(nuevoApellido == NULL){
                printf("No se encontro memoria para el apellido.\n");
                exit(1);
            }else{
                control = getString(nuevoApellido, "\n\nIngrese nuevo apellido: ", "Error, ingrese solo letras respetando el rango (3 a 51): ", 3, 51, 3);
                if(control == 0){
                    printf("\nNo se pudo registrar el apellido!\n");
                }else{
                    strcpy((lista+indice)->apellido, nuevoApellido);
                }
            }
            break;
        case 2: if(nuevoNombre == NULL){
                printf("No se encontro memoria para el apellido.\n");
                exit(1);
            }else{
                control = getString(nuevoNombre, "\n\nIngrese nuevo nombre: ", "Error, ingrese solo letras respetando el rango (3 a 51): ", 3, 51, 3);
                if(control == 0){
                    printf("\nNo se pudo registrar el nombre!\n");
                }else{
                    strcpy((lista+indice)->nombre, nuevoNombre);
                }
            }
            break;
        case 3:
            control = getCharSexo(nuevoSexo, "\n\nIngrese nuevo sexo: ", "\nError, ingrese solo 'f' o 'm'. Reingrese: ", 3);
            if(control == 0){
                printf("\nNo se pudo registrar el sexo!\n");
            }else{
                (lista+indice)->sexo = *nuevoSexo;
            }
            break;
        case 4:
            if(nuevoDomicilio == NULL){
                printf("No se encontro memoria para el domicilio.\n");
            }else{
                control = getDomicilio(nuevoDomicilio, "\nIngrese nuevo domicilio: ", "Error, ingrese solo numeros respetando el rango (hasta 51 digitos). Reingrese: ", 3, 51, 3);
                if(control == 0){
                    printf("\nNo se pudo registrar el domicilio!\n");
                }else{
                    strcpy((lista+indice)->domicilio, nuevoDomicilio);
                }
            }
            break;
        }
    }
    free(opcion);
    free(nuevoApellido);
    free(nuevoNombre);
    free(nuevoSexo);
    free(nuevoDomicilio);
    return control;
}

int modificarCliente(eCliente* lista, int TAM_CLIENTES, int *codigo){
    int* indice = (int*) malloc(sizeof(int));
    int* control = (int*) malloc(sizeof(int));
    int bandera;
    char* seguir = (char*) malloc(sizeof(char));

    if(lista != NULL && TAM_CLIENTES > 0){
        system("cls");
        printf("  *** Modificar cliente ***\n\n");
        *control = getInt(codigo, "Ingrese codigo de cliente: ", "Error, ingrese solo numeros respetando el rango (1 - 10): ", 1, 10, 3);
        if(*control != 1){
            bandera = 0;
            printf("\nNo se obtuvo el codigo de cliente.");
        }else{
            *indice = buscarCliente(lista, TAM_CLIENTES, *codigo);
            if(*indice == -1){
                bandera = -1;
            }else{
                printf("Legajo   Apellido   Nombre   Sexo   Domicilio\n");
                mostrarCliente(lista+(*indice)); // d
                printf("\nDesea modificar algun campo? s/n: ");
                fflush(stdin);
                scanf("%c", seguir);
                *control = validarRespuesta(seguir);
                while(*control != 1){
                    printf("Error, solo debe ingresar 's' o 'n', reingrese: ");
                    fflush(stdin);
                    scanf("%c", seguir);
                }
                if(*seguir == 'n' || *seguir == 'N'){
                    bandera = 0;
                }else{
                    bandera = menuModificarCliente(lista, *indice, TAM_CLIENTES);
                }
            }
        }
    }
    free(indice);
    free(control);
    free(seguir);
    return bandera;
}

int bajaCliente(eCliente* lista, int TAM_CLIENTES, int *codigo){
    int* indice = (int*) malloc(sizeof(int));
    int bandera, *control = (int*) malloc(sizeof(int));
    char* seguir = (char*) malloc(sizeof(char));

    if(lista != NULL && TAM_CLIENTES > 0){
        system("cls");
        printf("  *** Baja de cliente ***\n\n");
        *control = getInt(codigo, "Ingrese codigo de cliente: ", "Error, ingrese solo numeros respetando el rango (1 - 10): ", 1, 10, 3);
        if(*control != 1){
            bandera = 0;
            printf("\nNo se obtuvo el codigo de cliente.");
        }else{
            *indice = buscarCliente(lista, TAM_CLIENTES, *codigo);
            if(*indice == -1){
                bandera = -1;
            }else{
                printf("Legajo  Apellido    Nombre   Sexo    Domicilio\n");
                mostrarCliente(lista+(*indice)); // d
                printf("\nDesea dar de baja este cliente?.. s/n: ");
                fflush(stdin);
                scanf("%c", seguir);
                *control = validarRespuesta(seguir);
                while(*control != 1){
                    printf("Error, solo debe ingresar 's' o 'n', reingrese: ");
                    fflush(stdin);
                    scanf("%c", seguir);
                }
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

int menuSeleccionarCliente(eCliente* lista, int TAM_CLIENTES){
    int opcion;
    int* control = (int*) malloc(sizeof(int));
    if(lista != NULL){
        system("cls");
        mostrarListadoDeClientes(lista, TAM_CLIENTES);
        *control = getInt(&opcion, "\nSeleccione Cliente: ", "Error, ingrese un cliente de la lista: ", 1, 7, 3);
        if(*control == 0){
            opcion = 0;
        }
    }
    free(control);
    return opcion;
}

void hardcodearClientes(eCliente* lista, int TAM_CLIENTES){
    eCliente nuevaLista[7]={
        { 1, "Dominguez", "Jacinto", 'm', "Cabildo 234 - Lanus", 0},
        { 2, "Perez", "Pablo", 'm', "Ayacucha 514 - Don Torcuato", 0},
        { 3, "Hernandez", "Epifania", 'f', "Parana 321 - Gerli", 0},  ////  seguir cargando !!!
        { 4, "Juarez", "Facundo", 'm', "Amenabar 1457 - Versalles", 0},
        { 5, "Paniagua", "Josefina", 'f', "Cristobal Colon 321 - Munro", 0},
        { 6, "Vitale", "Jacobo", 'm', "Nicaragua 654 - Nuñez", 0},
        { 7, "Diaz", "Lorena", 'f', "Islas Malvinas 159 - Moreno", 0},
    };
    for(int contador=0; contador< 7; contador++){
        *(lista+contador) = *(nuevaLista+contador);
    }
}

