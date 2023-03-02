/*************************ivector.h***************************/
/*         Módulo de cabeceras para uso de objetos           */
/*                   VECTORES DE ENTEROS                     */
/*************************************************************/

#ifndef IVECTOR

#define IVECTOR
struct Pedido{
    int numPedido;
    int tiempoLimite;
    int aCobrar;

};

typedef struct Pedido *ivector;

ivector icreavector(int tam);
void ifreevector(ivector *v);

#endif
