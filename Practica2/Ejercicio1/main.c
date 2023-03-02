//
// Created by administrador on 2/03/23.
//
#include <stdio.h>
#include <stdlib.h>
#include "ivector.h"
int compare(const void * _a, const void* _b){

    struct Pedido *a,*b;
    a = (struct Pedido *) _a;
    b = (struct Pedido *) _b;

    if( a->tiempoLimite == b->tiempoLimite){
        return b->aCobrar - a->aCobrar;
    }

    return (a->tiempoLimite - b->tiempoLimite);

}

void restarUnidad(ivector v,int tam){

    for(int i=0;i<tam;++i){
        //Para que no reste aquellos que le guardamos un -1
        if(v[i].tiempoLimite >=1) {
            v[i].tiempoLimite = v[i].tiempoLimite - 1;
        }
    }
}

void funcionVoraz(ivector candidatos, int tam,ivector solucion){


    int indiceSol = 0;
    int finSol = tam-1;
    int indice = 0;


    while(indice < tam) {

        while(candidatos[indice].tiempoLimite <= 0){

            if(candidatos[indice].tiempoLimite == 0) candidatos[indice].aCobrar = 0;
            solucion[finSol] = candidatos[indice];
            ++indice;
            --finSol;
        }
        struct Pedido candidato = candidatos[indice];

        candidato.tiempoLimite =-1;
        solucion[indiceSol] = candidato;



        //Restar una unidad a todos
        restarUnidad(candidatos, tam);
        ++indice;
        ++indiceSol;
    }



}


int main(){

    ivector v = icreavector(9);

    v[0].numPedido = 1;
    v[0].tiempoLimite = 1;
    v[0].aCobrar = 60;

    v[1].numPedido = 2;
    v[1].tiempoLimite =5 ;
    v[1].aCobrar = 70;

    v[2].numPedido = 3;
    v[2].tiempoLimite =5 ;
    v[2].aCobrar = 80;

    v[3].numPedido = 4;
    v[3].tiempoLimite =6 ;
    v[3].aCobrar = 20;

    v[4].numPedido = 5;
    v[4].tiempoLimite =6 ;
    v[4].aCobrar = 20;

    v[5].numPedido = 6;
    v[5].tiempoLimite =4 ;
    v[5].aCobrar = 30;

    v[6].numPedido = 7;
    v[6].tiempoLimite =4 ;
    v[6].aCobrar = 50;

    v[7].numPedido = 8;
    v[7].tiempoLimite =2 ;
    v[7].aCobrar = 50;

    v[8].numPedido = 9;
    v[8].tiempoLimite = 2;
    v[8].aCobrar = 90;

    qsort(v,9,sizeof(struct Pedido), &compare);

    ivector sol = icreavector(9);
    funcionVoraz(v,9,sol);


    for(int i=0;i<9;++i){
        printf("Pedido: %d\n",sol[i].numPedido);
    }


    ifreevector(&v);
    ifreevector(&sol);


    return 0;
}