#include "imatriz2d.h"
#include "ivector.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * Devolvemos el nodo que tiene el camino mas corto
 * @param v
 * @param tam
 * @return
 */
int minDist(ivector v, int tam){
    int min = v[0];
    int k = 0;
    for(int i=1;i<tam;++i){
        if((v[i]< min && v[i] != -1) || min ==-1){
            min = v[i];
            k= i;
        }
    }
    return k;
}
ivector caminosDijkstra(imatriz2d maAdyacencia,int filas,ivector D,int tamD,ivector P,int tamP){
    ivector sol = icreavector(filas);
    int iSol = 0;
    sol[iSol] = 0;
    ++iSol;
    D[0] = -1;
    for(int i=1;i<filas;++i){
        D[i] = maAdyacencia[0][i];
        P[i] = 0; ///> Contiene el nodo que precede a i en el camino más corto.En este caso 0

    }

    //Bucle voraz
    int j = 0;
    do{
        int nodo = minDist(D,tamD);
        sol[iSol] = nodo;
        ++iSol;

        for(int i=0;i<tamD;++i){
            if(D[i]>0 && D[i] > D[nodo]+ maAdyacencia[nodo][i]){
                D[i] = D[nodo] + maAdyacencia[nodo][i];
                P[i] = nodo;
            }
        }
        D[nodo] = -1; //Así indicamos que ya lo hemos cogido



        ++j; // Se cuentan las veces que se ejecutan
    }while(j <= filas -2);


    return sol;


}



int main(){

    imatriz2d m = icreamatriz2d(3,3);
    int i, size = 0;

    m[0][0] = 999;
    m[0][1] = 2;
    m[0][2] = 1;

    m[1][0] = 2;
    m[1][1] = 999;
    m[1][2] = 3;

    m[2][0] = 1;
    m[2][1] = 3;
    m[2][2] = 999;





    ivector D = icreavector(3);
    ivector P = icreavector(3);
    ivector sol = caminosDijkstra(m,3,D,3,P,3);

    for(int i=0;i<3;++i){
        printf("%d ",sol[i]+1);
    }

    return 0;
}