//
// Created by administrador on 2/03/23.
//
#include <stdio.h>
#include <stdlib.h>
#include "ivector.h"


/**
 * Busca en el vector B los números mayores a B
 * @param B  vector donde buscar numeros mayores a num
 * @param num
 * @param tam Tamaño del vector devuelto
 * @param min El mínimo valor
 * @return vector con dichos elementos
 */

ivector buscar (ivector B, int tamB,int num, int *tam,int *min){

    ivector sol = icreavector(tamB);
    int iSol = -1;
    *min = 9999999;
    for(int i=0;i<tamB;++i){
        if(B[i] >= num){
            iSol++;
            sol[iSol] = B[i];

        }
        if(B[i] < *min){
            *min = B[i];
        }


    }

    *tam = iSol+1;
    return sol;
}

/**
 *
 * @param A Vector ordenado de menor a mayor
 * @param B Vector de candidatos y que debemos reordenar para obtener la mayor suma
 * @param tam tam de ambos vectores
 *  @return sol que es el vector solucion
 * */
ivector funcionVoraz (ivector A, ivector B, int tam){

    ivector sol = icreavector(tam);
    int tamAux = tam;
    for(int i=tam-1;i>=0;--i){
        // funcion buscarMayor(ivectorB,A[i]) devuelve V:ivector
        /*
         * if( v tam == 0) ---> coger el menor de A
         * if( v tam != 0) ---> coger el menor de v
         * */
        int tamC,min;
        ivector candidatos = buscar(B,tamAux,A[i],&tamC,&min);
        if(tamC == 0){
            sol[i] = min;
        }else{

            min = 99999;
            for(int j=0;j<tamC;++j){
                if(candidatos[j]< min ){
                    min = candidatos[j];
                }
            }
            sol[i] = min;
        }
        //C <- C - {x} , quitar de los candidatos el seleccionado
        int desplazar = 0;
        for(int k = 0;k<tam-1;++k){
            if(B[k] == sol[i] || desplazar){
                //Una vez que encuentra el elemento a eliminar, lo va desplazando hacia el fina
                //y restamos el tamaño
                //Quitarlo
                desplazar = 1;
                B[k] = B[k+1];
            }
        }
        --tamAux;

    }

    return sol;



}


int main(){


    ivector A = icreavector(5);
    A[0] = 1;
    A[1] = 4;
    A[2] = 6;
    A[3] = 7;
    A[4] = 9;

    ivector B = icreavector(5);
    B[0] = 3;
    B[1] = 2;
    B[2] = 4;
    B[3] = 6;
    B[4] = 5;


    ivector sol = funcionVoraz(A,B,5);
    for(int i=0;i<5;++i){
        printf("%d\n",sol[i]);
    }


    return 0;
}