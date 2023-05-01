

#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "imatriz2d.h"


void trayectoria(int i,int j,imatriz2d casos){
    int k = casos[i][j];
    if( k != 0){
        trayectoria(i,k,casos);
        printf("%d  ",k);
        trayectoria(k,j,casos);
    }
}
void camino(int i,int j,imatriz2d casos){
    printf("%d  ",i);
    trayectoria(i,j,casos);
    printf("%d  ",j);
}
/**
 * Tenemos N islas, y estas están conectadas entre sí con puentes
 * de una anchura Ni.
 *
 * La anchura de un camino es la anchura mínima de todos los puentes que lo forman.
 *
 * Hallar el camino de anchura máxima entre todo par de islas.
 *
 * */




int puentesFloyd(imatriz2d adyacencia,int numIslas){

    imatriz2d tabla = icreamatriz2d(numIslas,numIslas);
    imatriz2d caminoSeguido = icreamatriz2d(numIslas,numIslas);
    int res;

    /*Caso trivial para cuando no hay ninguna isla de promedio
     * pues el camino es directo*/
    for(int i=0;i<numIslas;++i){
        for(int j=0;j<numIslas;++j){

            tabla[i][j] = adyacencia[i][j];
            caminoSeguido[i][j] = 0; //Inicializamos dicha matriz

        }
    }

    int max = INT_MIN;
    int islaInicial = 0;
    int islaFinal = numIslas-1;
    /*Demás casos*/
    for(int k = 0;k<numIslas;++k){
        for(int i = 0;i<numIslas;++i){
            for(int j=0;j<numIslas;++j){
                //todo ESTA MAL, no se suma, hay que coger el minimo
                if(tabla[i][k] + tabla[k][j] < tabla[i][j]){
                    tabla[i][j] = tabla[i][k] + tabla[k][j];
                    caminoSeguido[i][j] = k;
                }
            }
        }
        //Una vez que he calculado la anchura mínima para k nodos intermedios, voy buscando la de mayor anchura
        if(tabla[islaInicial][islaFinal] > max){
            max = tabla[islaInicial][islaFinal];
            //todo Como hago el camino de esto
        }
    }

    //todo CAMINOS OPTIMOS

    camino(0,3,caminoSeguido);
    ifreematriz2d(&tabla);
    return max;

}



int main(){

    /*VARIABLES*/

    imatriz2d adyacencia = icreamatriz2d(4,4);
    for(int i = 0;i<4;++i){
        for(int j = 0;j<4;++j){
            if(i!=j){
                int n = rand() % 4;
                if (n == 2) {
                    adyacencia[i][j] = INT_MAX; // un 25% de probabilidad
                } else {
                    adyacencia[i][j] = rand() % 11 +1;

                }
            }else{
                adyacencia[i][j] = 0;
            }

            printf(" %10d    ",adyacencia[i][j]);
        }
        printf("\n");
    }

    int resul = puentesFloyd(adyacencia,4);
    printf("Resultado: %d",resul);


    ifreematriz2d(&adyacencia);


    return 0;
}
