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
void insercion(ivector v, int ini, int fin){

    int i = ini;
    printf("Insercion\n");
    while(i < fin){
        for(int j=i+1;j>ini;--j){
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
    while((izq <= (med-1)) && (med <= der)){

        if (u[izq] >= v[med])
        {
            aux[i] = v[med];
            ++med;
            ++i;
        }
        if(u[izq] <= v[med] ){
            aux[i] = u[izq];
            ++izq;
            ++i;
        }




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
    //Modificamos el vector original
    int indice=0;
    for(int i=ini;i<=fin;++i){
        t[i] = aux[indice];
        ++indice;
    }

    //Liberamos el vector usado
    ifreevector(&aux);

}
void mergeSort(ivector t,int ini,int fin){

    if((fin-ini+1) <= 4){
        insercion(t,ini,fin);
    }else{
        int tam =fin-ini+1;
        int med = tam/2;

        ivector u = icreavector(med);
        ivector v = icreavector(tam -med);

        for(int i = ini;i<ini+med;++i){
            u[i-ini] = t[i];
        }

        for(int i = ini+med;i<=fin;++i){
            v[i-ini-med] = t[i];
        }

        mergeSort(u,ini,ini+med-1);
        mergeSort(v,ini+med,fin);
        merge(t,u,v,ini,med,fin);

        ifreevector(&u);
        ifreevector(&v);

    }



}



int main(){
    int tam = 8;
    ivector v = icreavector(tam) ;

    //Generacion de semilla para numeros aleatorios
    srand(time(NULL));
    for(int i=0;i<tam;++i){
        int n= rand() % tam;
        v[i] = n;
    }

    for(int i=0;i<tam;++i){
        printf("%d -- ",v[i]);
    }

    mergeSort(v,0,tam-1);
    
    for(int i=0;i<tam;++i){
        printf("%d -- ",v[i]);
    }
    

    


    return 0;
}