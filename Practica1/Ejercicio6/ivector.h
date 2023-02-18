/*************************ivector.h***************************/
/*         Módulo de cabeceras para uso de objetos           */
/*                   VECTORES DE ENTEROS                     */
/*************************************************************/

#ifndef IVECTOR

#define IVECTOR


struct carrera{
    int dorsal;
    int litros;
};

typedef struct carrera* ivector;

ivector icreavector(int tam);
void ifreevector(ivector *v);

#endif
