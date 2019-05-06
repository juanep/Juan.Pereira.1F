#ifndef ALQUILERES_H_INCLUDED
#define ALQUILERES_H_INCLUDED
#include "fechas.h"
#include "clientes.h"

typedef struct{
    int idAlquiler;
    int codigoJuego;
    int codigoCliente;
    eFecha fecha;
    int isEmpty;
}eAlquiler;

/** \brief
 * \param
 * \param
 * \return
 */
int iniciarAlquileres(eAlquiler* lista, int TAM_ALQUILERES);

/** \brief
 * \param
 * \param
 * \return
 */
int buscarLibreAlquileres(eAlquiler* lista, int TAM_ALQUILERES);

/** \brief
 * \param
 * \param
 * \param
 * \return
 */
int buscarAlquiler(eAlquiler* lista, int TAM_ALQUILERES, int codigo);

/** \brief
 * \param
 * \param
 * \return
 */
int comprobarRegistroAlquiler(eAlquiler* lista, int TAM_ALQUILERES);

/** \brief
 * \param
 * \return
 */
void mostrarAlquiler(eAlquiler* alquiler);

/** \brief
 * \param
 * \param
 * \return
 */
void mostrarListadoDeAlquileres(eAlquiler* lista, int TAM_ALQUILERES);

/** \brief
 * \param
 * \param
 * \param
 * \param
 * \param
 * \param
 * \return
 */
int ingresarAlquiler(eAlquiler* lista, int TAM_ALQUILERES, eCliente* clientes, int TAM_CLIENTES, eJuego* juegos, int TAM_JUEGOS);

/** \brief
 * \param
 * \param
 * \param
 * \return
 */
int ModificarAlquiler(eAlquiler* lista, int TAM_ALQUILERES, int *codigo);

/** \brief
 * \param
 * \param
 * \return
 */
int menuModificarAlquiler(eAlquiler* lista, int indice);

/** \brief
 * \param
 * \param
 * \param
 * \return
 */
int bajaAlquiler(eAlquiler* lista, int TAM_ALQUILERES, int *codigo);

void hardcodearAlquileres(eAlquiler* lista, int TAM_ALQUILERES);

float total_y_promedio_importes_de_juegos_alquilados(eAlquiler *lista, int TAM_ALQUILERES, eJuego* juegos, int TAM_JUEGOS);

#endif // ALQUILERES_H_INCLUDED
