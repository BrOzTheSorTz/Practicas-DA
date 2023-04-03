

#include <stdio.h>
#include "ivector.h"

/**
 * Calculamos el valor n-ésimo de la sucesión
 * @param n
 * @return Valor de la sucesión de Stern
 */
int serieDeStern(int n){
    ivector tabla = icreavector(n+1);
    //Soluciones triviales
    tabla[0] = 0;
    tabla[1] = 1;

    for(int i = 2;i<=n;++i){
        if(i%2 == 0){
            tabla[i] = tabla[i/2];
        }else{
            tabla[i] = tabla[(i-1)/2]+tabla[(i-1)/2 +1];
        }
    }

    int res = tabla[n];
    ifreevector(&tabla);
    return res;
}



int main(){

    //Calcularemos algunos valores
    for(int i=0;i<100;++i){
        int valor = serieDeStern(i);
        printf(" %d  ",valor);
    }


    return 0;
}