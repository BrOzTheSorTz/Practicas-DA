//
// Created by jpablo on 14/02/23.
//
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "ivector.h"

/**
 * Elemento mayoritario de un conjunto
 * @param v
 * @param tam
 * @return posicion del elemento mayoritario
 */
int mayoritario(ivector v,int ini,int fin){
    int cont = 0;
    for(int i=ini;i<=fin;++i) {

        for (int j = ini; j <= fin; ++j){
            if (v[i] == v[j]) {
                ++cont;
            }
        }
        if(cont > (fin-ini+1)/2){

            return i;
        }
        cont = 0;
    }
    return -1;
}

/**
 *
 * @param v
 * @param ini
 * @param fin
 * @param m
 * @return Devuelve true -> 1 o false -> 0
 */
int mayoritarioDyV(ivector v,int ini,int fin){

    if((fin-ini+1) <=4){
        return mayoritario(v,ini,fin);
    }else{

        int tam = (fin-ini +1);
        int posIzq = mayoritarioDyV(v,ini,ini+(tam/2)-1);
        int posDer = mayoritarioDyV(v,ini + tam/2,fin);

        int cont = 0;
        if(posIzq == -1 && posDer == -1){
            return -1;
        }else if(posIzq != -1 && posDer == -1){
            for(int i=ini;i<=fin;++i){
                if(v[i] == v[posIzq]){
                    ++cont;
                }
            }
            if(cont > (fin-ini+1)/2){
                return posIzq;
            }
        }else if(posIzq == -1 && posDer != -1){
            for(int i=ini;i<=fin;++i){
                if(v[i] == v[posDer]){
                    ++cont;
                }
            }
            if(cont > (fin-ini+1)/2){
                return posDer;
            }
        }else if(posIzq != -1 && posDer != -1){
            int sum1 = 0;
            int sum2 = 0;
            for(int i=ini;i<=fin;++i){
                if(v[i] == v[posIzq]){
                    ++sum1;
                }
                if(v[i] == v[posDer]){
                    ++sum2;
                }
            }
            if(suma1 > (fin-ini+1)/2){
                return posIzq;
            }else if(suma2 > (fin-ini+1)/2){
                return posDer;
            }
            return -1;
        }

    }

}



int main(){
    ivector v = icreavector(8);
    v[0] = 1;
    v[1] = 2;
    v[2] = 2;
    v[3] = 2;
    v[4] = 3;
    v[5] = 4;
    v[6] = 2;
    v[7] = 2;

    int * valor;
    int true = mayoritarioDyV(v,0,7);

    if(true != -1){
        printf("%d",v[true]);
    }

    ifreevector(&v);
    return 0;
}
