//
// Created by jpablo on 2/03/23.
//
#include <malloc.h>
#include <stdlib.h>
#include "ivector.h"
#include "imatriz2d.h"
#include "disjoint.h"

#define INFINITY 9999999
/*
 * funcion Prim(G:Grafo) :Set
 *  T<--Vacio
 *  B<--Miembro arbitrario de N
 *
 *  while B != N do
 *      encontrar {u,v} de longitud mínima con
 *      u en B y v en N/B
 *
 *      T<- T U {u,v}
 *      B<- B U v
 *
 *  return T
 *
 * */
/**
 * Devolvemos las aristas solución
 * @param filas que es igual al número de columnas
 * @return aristas solución
 */
ivector obtenerCamino(imatriz2d distancias, int filas){
    int* mascerca = (int*)malloc((filas)*sizeof(int)); //todo trabajar con ivector, declarlo con el tam = numnodos
    int* mindist  = (int*)malloc((filas)*sizeof (int));
    ivector sol = icreavector(filas-1);//numero de aristas nodos-1
    int iSol = 0;
    for(int i=1;i<filas;++i){
        mascerca[i] = 0; //Supongo que todos los nodos tienen como al mas cerca al 1(que en la matriz es el 0)
        mindist[i] = distancias[0][i]; // Y la minima distancia es del nodo 1 a dichos nodos

    }



    //Bucle voraz
    int i=1;
    while(i<filas){
        int min = INFINITY;
        int k = -1;
        for(int j=1;j<filas;++j){
            if( mindist[j] >=0 && mindist[j] <min ){
                min = mindist[j]; //si hago mascerca[j] = 1; Significa la distancia de j a mascerca[j]
                k = j;
            }
        }

        sol[iSol].u =k;
        sol[iSol].v = mascerca[k];
        ++iSol;
        mindist[k] = -1;

        for(int j=1;j<filas;++j){
            if(distancias[k][j] < mindist[j]){
                mindist[j] = distancias[k][j]; //Distancia mas corta desde el nodo nuevo a j, no la que había antes
                mascerca[j] = k; //mascerca de j no era el de antes sino k
            }
        }
        ++i;
    }






    free(mascerca);
    free(mindist);

    return sol;
}

/**
 * Ordenamos el vector de mayor a menor por el peso
 * @param _a
 * @param _b
 * @return
 */
int compare(const void *_a, const void *_b) {

    struct Aristas *a, *b;

    a = (struct Aristas *) _a;
    b = (struct Aristas *) _b;

    return ( a->peso - b->peso);
}
ivector algKruskal(ivector aristasYpesos, int tam,int numNodos){
    //ordenar aristasYpesos
    qsort(aristasYpesos,tam,sizeof (struct Aristas),&compare);
    ivector sol = icreavector(numNodos-1);
    int iSol = 0;

    //Inicializar n conjuntos
    disjoint conjuntos = disjoint_nuev(numNodos);

    //Bucle voraz
    int i = 0;
    do{
        int u1 = aristasYpesos[i].u;
        int v1 = aristasYpesos[i].v;
        ++i; //Indice de aristas y pesos

        int ucomp = disjoint_find(conjuntos,u1);
        int vcomp = disjoint_find(conjuntos,v1);
        if(ucomp != vcomp){
            disjoint_merge(conjuntos,ucomp,vcomp);
            sol[iSol].u = u1;
            sol[iSol].v = v1;
            ++iSol;
        }



    }while(iSol != numNodos-1);

    disjoint_dest(&conjuntos);

    return sol;
}


int main (){

    imatriz2d red = icreamatriz2d(10,10);
    for(int i=0;i<10;++i){
        for(int j=0;j<10;++j){
            red[i][j] = (i+j+2) % 8; // i<-i+1 y j<-j+1 ya que contamos desde el cero

        }
    }

    ivector sol = obtenerCamino(red,10);
    //----------------------CALCULO DEL VECTOR DE ARISTAS Y SUS PESOS---------
    //Como la matriz de distancias es simetrica solo recorro la mitad
    int tam = 0;
    //Para calcular el tamaño de la mitad de la matriz es:
    //Sumatoria{desde i=0 hasta i = n-1} de i;
    for(int i=0;i<10;++i){
        tam+=i;
    }
    ivector aristasYpesos = icreavector(tam);
    int iAristasYpesos = 0;
    for(int i=0;i<10;++i){
        for(int j=i+1;j<10;++j){
            aristasYpesos[iAristasYpesos].u = i;
            aristasYpesos[iAristasYpesos].v = j;
            aristasYpesos[iAristasYpesos].peso =red[i][j];
            ++iAristasYpesos;
        }
    }
    ivector sol1 = algKruskal(aristasYpesos,tam,10);


    for(int i=0;i<9;++i){
        printf("{%d-%d}  ",sol[i].u+1,sol[i].v+1 );
    }
    printf("\n");
    for(int i=0;i<9;++i){
        printf("{%d-%d}:Peso: %d  ",sol1[i].u+1,sol1[i].v+1,sol1->peso  );
    }






    return 0;
}