#include <stdio.h>
#include <stdlib.h>
#include "ivector.h"

void swap(int *a,int *b){
    int aux = *b;
    *b=*a;
    *a = aux;
}

/**
 * -> 8|9|5|2
 * -> 8|9|5|2
 * -> 8|5|9|2 -> 5|8|9|2
 * -> 5|8|2|9 -> 5|2|8|9 -> 2|5|8|9
*/
void insercion(ivector v, int ini, int fin){

    int i = ini;

    while(i < fin){
        for(int j=i+1;j>ini;--j){
            if(v[j-1] > v[j]){
                swap(&v[j-1],&v[j]);
            }
        }
        ++i;
    }    

}

void merge(ivector v, int ini, int med,int fin){
    int izq = ini;
    int der = med+1;
    ivector aux = icreavector(fin-ini+1);
    int i = 0;
    while(izq <= med && der <= fin){
        if(v[izq] < v[der]){
            aux[i] = v[izq];
            ++i;
            ++izq;
        }else {
            aux[i] = v[der];
            ++i;
            ++der;
        }
    }

    if( izq > med && der <= fin){
        //PARTE DERECHA COPIAR
        while(der <= fin){
            aux[i] = v[der];
            ++i;++der;
        }
    }
    if( izq <= med && der > fin){
        //PARTE IZQ COPIAR
        while(izq <= med){
            aux[i] = v[izq];
            ++i;
            ++izq;
        }
    }


    //COPIAMOS AL ORIGINAL
    for(int j=ini;j<=fin;++j){
        v[j] = aux[j-ini];
    }
    ifreevector(&aux);
}

void mergeSort(ivector v, int ini, int fin){
    if(fin -ini <4){
        //printf("\nPARTE\n");

        insercion(v,ini,fin);

    }else{

        int mitad = (ini+fin)/2;

        mergeSort(v,ini,mitad);
        mergeSort(v,mitad+1,fin);
        merge(v,ini,mitad,fin);

    }
}


int main(){
    int tam = 8;
    ivector v = icreavector(tam) ;

    //Generacion de semilla para numeros aleatorios
    srand(42);
    for(int i=0;i<tam;++i){
        int n= rand() % tam;
        v[i] = n;
    }

    /**for(int ir =0;i<tam;++i){
        printf("%d -- ",v[i]);
    }*/

    for(int i =0;i<tam;++i){
        printf("%d -- ",v[i]);
    }
    mergeSort(v,0,tam-1);

    printf("\n");
    for(int i =0;i<tam;++i){
        printf("%d -- ",v[i]);
    }
    /*
    for(int i=0;i<tam;++i){
        printf("%d -- ",v[i]);
    }*/


    ifreevector(&v);


    return 0;

}