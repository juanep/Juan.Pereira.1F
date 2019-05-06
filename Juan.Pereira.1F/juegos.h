#ifndef JUEGOS_H_INCLUDED
#define JUEGOS_H_INCLUDED

typedef struct{
    int idJuego;
    char descripcion[31];
    float importe;
    int isEmpty;
}eJuego;

/** \brief
 * \param
 * \param
 * \return
 */
int iniciarJuegos(eJuego* lista, int TAM_JUEGOS);

/** \brief
 * \param
 * \param
 * \param
 * \return
 */
int buscarJuego(eJuego* lista, int TAM_JUEGOS, int codigo);

/** \brief
 * \param
 * \param
 * \return
 */
int buscarLibreJuegos(eJuego* lista, int TAM_JUEGOS);

/** \brief
 * \param
 * \param
 * \return
 */
int comprobarRegistroJuegos(eJuego* lista, int TAM_JUEGOS);

/** \brief
 * \param
 * \return
 */
void mostrarJuego(eJuego* juego);

/** \brief
 * \param
 * \param
 * \return
 */
int mostrarListadoDeJuegos(eJuego* lista, int TAM_JUEGOS);

/** \brief
 * \param
 * \param
 * \return
 */
int menuSeleccionarJuego(eJuego* lista, int TAM_JUEGOS);

/** \brief
 * \param
 * \param
 * \return
 */
int ingresarJuego(eJuego* lista, int TAM_JUEGOS);

/** \brief
 * \param
 * \param
 * \param
 * \return
 */
int modificarJuego(eJuego* lista, int TAM_JUEGOS, int *codigo);

/** \brief
 * \param
 * \param
 * \param
 * \return
 */
int menuModificarJuego(eJuego* lista, int indice, int TAM_JUEGOS);

/** \brief
 * \param
 * \param
 * \param
 * \return
 */
int bajaJuego(eJuego* lista, int TAM_JUEGOS, int *codigo);

void hardcodearJuegos(eJuego* lista, int TAM_JUEGOS);

#endif // JUEGOS_H_INCLUDED
