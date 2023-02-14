#include <stdlib.h>
#include <stdio.h>
#include "ivector.h"


/**
 * @brief Busqueda secuencial
 * @param v
 * @param ini
 * @param fin
 * @param valor Valor a buscar
 * @return Posición del valor encontrado o -1 si no lo encuentra
 */
int busqSecuencial (ivector v, int ini,int fin,int valor){
    for(int i=ini;i<=fin;++i){
        if (v[i] == valor)
            return i;
    }
    return -1;

}

int busqTernaria (ivector v, int ini,int fin, int valor){

    if((fin-ini+1) <= 3){
        return busqSecuencial(v,ini,fin,valor);
    }else{

        int parte1 = (fin-ini)/3 +ini;
        int parte2 = (fin)-(fin-ini)/3;
        if(valor <= v[parte1]){
            busqTernaria(v,ini,parte1,valor);
        }else if( v[parte1] < valor && valor <= v[parte2]){
            busqTernaria(v,parte1,parte2,valor);
        }else{
            busqTernaria(v,parte2,fin,valor);
        }

    }



}

int main(){
    ivector v = icreavector(9);
    v[0] = 2;
    v[1] = 4;
    v[2] = 6;
    v[3] = 7;
    v[4] = 9;
    v[5] = 10;
    v[6] = 11;
    v[7] = 12;
    v[8] = 13;

    printf("%d", busqTernaria(v,0,8,12));






    return 0;
}