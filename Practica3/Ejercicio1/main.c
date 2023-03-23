

#include <stdio.h>
#include "ivector.h"

/*
 * Primero voy a implementar la función recursiva
 * *
 *
 */

float calculof1Recursivo(int n){
    if(n == 0){
        return 0;
    }else{
        float suma =0;

        for(int i=0;i<n;++i){
            suma += calculof1Recursivo(i);
        }

        return (float )n + (float)(2.0/n)*(suma);

    }
}



/*Usamos programación dinámica
 * */
float valorPD(int n){
    ivector numeros = icreavector(n+1);
    if( n == 0){
        return 0;
    }
    numeros[0] = 0;
    float suma = numeros[0] ;


    for(int i=1;i<= n;++i){
        numeros[i] = (float)i + (2.0/i)*suma;
        suma += numeros[i];
    }
    float res = numeros[n];
    ifreevector(&numeros);


    return res;
}
int main(){

    printf("Recursivo\n");
    float suma = calculof1Recursivo(20);
    printf("%f\n",suma);

    printf("Con programación dinámica\n");
    suma = valorPD(20);
    printf("%f\n",suma);


    return 0;
}