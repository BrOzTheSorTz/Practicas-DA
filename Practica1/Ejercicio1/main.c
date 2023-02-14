#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
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
void insercion(ivector v, int tam){

    int i = 0;
    printf("Insercion\n");
    while(i < tam-1){
        for(int j=i+1;j>0;--j){
            if(v[j-1] > v[j]){
                swap(&v[j-1],&v[j]);
            }
        }
        ++i;
    }    

}

void merge(ivector t,ivector u,ivector v,int ini,int med, int fin){

    int izq = ini;
    int der = fin;

    ivector aux = icreavector(der-izq+1);
    int i = 0;
    while((izq <= (med-1)) || (med <= der)){

        if (u[izq] >= v[med] && med <= der)
        {
            aux[i] = v[med];
            ++med;
            ++i;
        }
        if(u[izq] <= v[med] && izq <= med-1){
            aux[i] = u[izq];
            ++izq;
            ++i;
        }
        
        //-------COMPLETAR CASOS QUE UN VECTOR ESTE VISITADO ENTERO---------
        if(izq >= med){
            //Parte izquierda completada
            while(med <=der){
                aux[i] = v[med];
                ++i;
                ++med;
            }
        }

        if(med > der){
            //Parte derecha completada
            while(izq <= med-1){
                aux[i] = u[izq];
                ++i;
                ++izq;
            }
        }



    }

    //Modificamos el vector original
    for(int i=ini;i<=fin;++i){
        t[i] = aux[i];
    }

    //Liberamos el vector usado
    ifreevector(&aux);

}
void mergeSort(ivector t,int ini,int fin){
    ivector u = NULL;
    ivector v = NULL;
    if((fin-ini+1) <= 4){
        insercion(t,(fin-ini+1));
    }else{
        int tam =ini+fin+1;
        int med = (ini +fin)/2;
        u = icreavector(med);
        v = icreavector(tam -med);
        mergeSort(t,ini,med);
        mergeSort(t,med+1,fin);


    }

}



int main(){
    int tam = 100;
    ivector v = icreavector(tam) ;
    printf("HOLA\n");
    //Generacion de semilla para numeros aleatorios
    srand(time(NULL));
    for(int i=0;i<tam;++i){
        v[i] = rand() % tam;
    }
    printf("hola1\n");
    mergeSort(v,0,tam-1);
    
    for(int i=0;i<tam;++i){
        printf("%d -- ",v[i]);
    }
    

    


    return 0;
}