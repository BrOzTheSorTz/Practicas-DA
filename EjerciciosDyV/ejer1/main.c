#include <stdio.h>
#include <stdlib.h>
#include "ivector.h"

int coincideDyV(ivector v, int ini, int fin){
    if(ini > fin){
        return -1;
    }else{
        int medio =(ini + fin) /2;
        if(medio < v[medio]){
            return coincideDyV(v,ini,medio -1);
        }else if(medio > v[medio]){
            return coincideDyV(v,medio,fin);
        }
        return medio;

    }

}
void swap(int *c1,int *c2){
    int aux = *c1;
    *c1 = *c2;
    *c2 = aux;
}
void transponerIguales(ivector v, int ini1,int ini2, int tam){
    int i=0;
    while(i < tam){
        swap(&v[ini1+i],&v[ini2+i]);
        ++i;
    }
}



void transponer(ivector v,int ini, int k, int fin){
    int tam = fin+ini +1;
    if( k == tam -k){
        transponerIguales(v,ini,ini+k,k);
    }else{
        if(k < tam-k){
            transponerIguales(v,ini,tam-k,k); //Se intercambian los k ultimos elemento spor los primeros
            //Los k ultimos elementos ya estan correctos
            transponer(v,ini,k,fin-k); // Se quitan los ultimos k elementos
                                            //Se transponen los otros
        }else{
            // k > tam-k
            transponerIguales(v,ini,ini+k,tam-k); //Transpones la parte derecha "la mas chica" del vector
            //los tam-k primeros elementos están colocados correctamente
            transponer(v,ini+tam-k,k,fin);
        }

    }
}




int main(){

    ivector v = icreavector(10);
    v[0] =1;
    v[1] =2;
    v[2] =3;

    v[3] =4;
    v[4] =5;
    v[5] =6;

    v[6] =7;
    v[7] =8;
    v[8] =9;
    v[9] =10;

    int m = coincideDyV(v,0,5);
    transponer(v,0,3,9);

    for(int i= 0;i<10;++i){
        printf("%d ",v[i]);
    }

    ifreevector(&v);
    return 0;
}