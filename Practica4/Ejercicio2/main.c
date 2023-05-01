#include <ivector.h>
#include <stdio.h>
#include <stdbool.h>

bool factible(int i, int m);

void imprime(ivector v, int tam){
    for(int i=0;i<tam;++i){
        printf("%d  ",v[i]);
    }
    printf("\n");
}

/**
 *
 * @param v
 * @param n
 * @param M Valor cuya suma queremos obtener
 * @param sol Vector binario que indica si se ha cogido dicho número o no
 * @param suma
 * @param k K son los valores que ya hemos puesto
 */
void conjuntosSuma(ivector v,int n,int M,ivector sol,int suma,int k){
    if( suma == M){
        imprime(sol,n);

    }else{
        for(;k<n;++k){

            sol[k] = 1;
            if(factible(suma+v[k],M)){

                conjuntosSuma(v,n,M,sol,suma+v[k],k+1);
            }
            sol[k] = 0;
        }

    }
}

bool factible(int i, int m) {
    if(i <= m){
        return 1;
    }

    return 0;
}

int main(){
    ivector v = icreavector(5);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;
    v[3] = 4;
    v[4] = 5;
    int n = 5;
    int M = 6;
    ivector sol = icreavector(n);
    for(int i=0;i<n;++i){
        sol[i] = 0; //Inicializamos
    }
    conjuntosSuma(v,n,M,sol,0,0);

    return 0;
}


