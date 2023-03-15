/*************************ivector.h***************************/
/*         Módulo de cabeceras para uso de objetos           */
/*                   VECTORES DE ENTEROS                     */
/*************************************************************/

#ifndef IVECTOR

#define IVECTOR

struct Archivos{
    int numero;
    int tama;
};
typedef struct Archivos *ivector;

ivector icreavector(int tam);
void ifreevector(ivector *v);

#endif
