#ifndef FECHAS_H_INCLUDED
#define FECHAS_H_INCLUDED

typedef struct{
    int anio;
    int mes;
    int dia;
    int isEmpty;
}eFecha;


/** \brief
 * \param
 * \param
 * \return
 */
int iniciarFechas(eFecha* lista, int TAM_FECHAS);

/** \brief
 * \param
 * \return
 */
int ingresarFecha(eFecha fecha);

/** \brief
 * \param
 * \param
 * \return
 */
int compararFecha(eFecha fecha1, eFecha fecha2);

void getFecha(eFecha* fecha);

#endif // FECHAS_H_INCLUDED
