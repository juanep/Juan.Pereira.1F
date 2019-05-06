#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

typedef struct{
    int idCliente;
    char apellido[31];
    char nombre[31];
    char sexo;
    char domicilio[51];
    int isEmpty;
}eCliente;

/** \brief
 * \param
 * \param
 * \return
 */
int iniciarClientes(eCliente* lista, int TAM_CLIENTES);

/** \brief
 * \param
 * \param
 * \return
 */
int buscarLibreClientes(eCliente* lista, int TAM_CLIENTES);

/** \brief
 * \param
 * \param
 * \param
 * \return
 */
int buscarCliente(eCliente* lista, int TAM_CLIENTES, int codigo);

/** \brief
 * \param
 * \param
 * \return
 */
int comprobarRegistroClientes(eCliente* lista, int TAM_CLIENTES);

/** \brief
 * \param
 * \param
 * \return
 */
int ingresarCliente(eCliente* lista, int TAM_CLIENTES);

/** \brief
 * \param
 * \param
 * \param
 * \return
 */
int menuModificarCliente(eCliente* lista, int indice, int TAM_CLIENTES);

/** \brief
 * \param
 * \param
 * \param
 * \return
 *
 */
int modificarCliente(eCliente* lista, int TAM_CLIENTES, int *codigo);

/** \brief
 * \param
 * \param
 * \param
 * \return
 */
int bajaCliente(eCliente* lista, int TAM_CLIENTES, int *codigo);

/** \brief
 * \param
 * \return
 */
void mostrarCliente(eCliente* cliente);

/** \brief
 * \param
 * \param
 * \return
 */
int mostrarListadoDeClientes(eCliente* lista, int TAM_CLIENTES);

/** \brief
 * \param
 * \param
 * \return
 */
int menuSeleccionarCliente(eCliente* lista, int TAM_CLIENTES);

/** \brief
 * \param
 * \param
 * \return
 */
void hardcodearClientes(eCliente* lista, int TAM_CLIENTES);

#endif // CLIENTES_H_INCLUDED
