/*************************ivector.h***************************/
/*         Módulo de cabeceras para uso de objetos           */
/*                   VECTORES DE ENTEROS                     */
/*************************************************************/

#ifndef IVECTOR

#define IVECTOR

struct Aristas{
    int u;
    int v;
    int peso;
};

typedef struct Aristas *ivector;

ivector icreavector(int tam);
void ifreevector(ivector *v);

#endif
