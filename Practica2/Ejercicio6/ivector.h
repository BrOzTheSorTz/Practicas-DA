/*************************ivector.h***************************/
/*         Módulo de cabeceras para uso de objetos           */
/*                   VECTORES DE ENTEROS                     */
/*************************************************************/

#ifndef IVECTOR

#define IVECTOR

struct Libros{
    int id;
    int peso;
    int balda;
};
typedef struct Libros *ivector;

ivector icreavector(int tam);
void ifreevector(ivector *v);

#endif
