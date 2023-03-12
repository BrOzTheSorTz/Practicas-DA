/*************************ivector.h***************************/
/*         Módulo de cabeceras para uso de objetos           */
/*                   VECTORES DE ENTEROS                     */
/*************************************************************/

#ifndef IVECTOR

#define IVECTOR
struct Bombilla{
    int id;
    int duracion;
};

typedef struct Bombilla*ivector;

ivector icreavector(int tam);
void ifreevector(ivector *v);

#endif
