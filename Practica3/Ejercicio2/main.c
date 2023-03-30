
#include <stdio.h>
#include "ivector.h"

int floor(double m){
    int n = m/2;
    do{
        n++;
    }while( n +1 < m);

    return n;
}

int ceil(double m){
    int n = m/2;
    do{
        n++;
    }while(n < m);

    return n;
}

/*Algoritmo recursivo*/
int calculoNporIndice(int n,int m){
    if(m == 0){
        return 0;
    }else if ( m == 1){
        return n;
    }else{

        return calculoNporIndice(n,floor(m/2.0))+ calculoNporIndice(n,ceil(m/2.0));
    }
}

/*Algoritmo PD*/

int calculoNporIndicePD(int n, int m){
    ivector v = icreavector(m+1);
    v[0] = 0;
    v[1] = n;

    for(int i=2 ;i<=m;++i){
        v[i] = v[floor(i/2.0)]+ v[ceil(i/2.0)];

    }
    int res = v[m];
    ifreevector(&v);
    return res;
}

int main(){

    printf("Usando recursividad\n");
    int valor = calculoNporIndice(2,5);
    printf("Valor: %d\n",valor);

    printf("Usando PD: \n");
    valor = calculoNporIndicePD(2,5);
    printf("Valor: %d\n",valor);




    return 0;
}