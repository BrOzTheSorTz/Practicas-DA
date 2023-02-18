#include <stdlib.h>
#include <stdio.h>
#include "ivector.h"


int calcularPivote(ivector v, int ini, int fin){

    int i= ini+1;
    while(i <= fin){
        if(v [ini].litros > v[i].litros) {
            return ini;
        }else if( v[ini].litros < v[i].litros){
            return i;
        }
        ++i;
    }
    return -1;
}

void swap(struct carrera *c1,struct carrera *c2){
    struct carrera aux = *c1;
    *c1 = *c2;
    *c2 = aux;
}
/**
 * Me coloca en el vector los valores mayores a la izquierda del pivote
 * y los elemetnos menores a la derecha del pivote
 * @param v
 * @param ini
 * @param fin
 * @param pivote
 * @return posicion del pivote
 */
int reordena(ivector v, int ini, int fin, struct carrera pivote){

    while(ini <= fin){
        swap(&v[ini],&v[fin]);
        while(v[ini].litros >= pivote.litros){
            ++ini;
        }

        while(v[fin].litros < pivote.litros){
            --fin;
        }

    }

    return ini;
}

/**
 *
 * @return El dorsal del corredor que ocupa la posicion k
 */
int elMejor( ivector v, int ini, int fin,int k){
    if( ini == fin){
        return v[ini].dorsal;
    }else{
        int pivote = calcularPivote(v,ini,fin);
        if(pivote == -1) return v[ini].dorsal; //Quiere decir que todos los corredores tienen los mismos litros
        int pos = reordena(v,ini, fin, v[pivote]);
        if( k-1 < pos){ //La posicion en el vector respecto k es k-1
            return elMejor(v,ini,pos-1,k);
        }else{
            return elMejor(v,pos,fin,k);
        }

    }
}


int main(){
    ivector v = icreavector(10);
    v[0].dorsal = 7;
    v[1].dorsal =3;
    v[2].dorsal =10;
    v[3].dorsal =1;
    v[4].dorsal =4;

    v[0].litros =575;
    v[1].litros =842;
    v[2].litros =27;
    v[3].litros =135;
    v[4].litros =970;
//-------------------------------------------------------
    v[5].dorsal =6;
    v[6].dorsal =8;
    v[7].dorsal =2;
    v[8].dorsal =5;
    v[9].dorsal =9;


    v[5].litros =10;
    v[6].litros =1000;
    v[7].litros =624;
    v[8].litros =468;
    v[9].litros =580;

    int k = 3;
    int mejor = elMejor(v,0,9,k);
    printf("El dorsal que quedo en la posicion %d fue %d",k,mejor);


    ifreevector(&v);

    return 0;
}