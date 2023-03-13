/*************************ivector.h***************************/
/*         Módulo de cabeceras para uso de objetos           */
/*                   VECTORES DE ENTEROS                     */
/*************************************************************/

#ifndef IVECTOR

#define IVECTOR


typedef struct Mochila *ivector;
struct Mochila{
    int mochila;
    int ganancia;
    int peso;
};
ivector icreavector(int tam);
void ifreevector(ivector *v);

#endif
