#include <stdlib.h>
#include <stdio.h>
#include "heap_aristas.h"
#include "ivector.h"

int fcomp(heap_aristas_tbase *a,heap_aristas_tbase *b){

    return (b->ganancia) -(a->ganancia);
}
int compare(const void* a, const void* b){
    struct Mochila* a1 = (struct Mochila*)a;
    struct Mochila* b1 = (struct Mochila*)b;

    return (b1->ganancia/b1->peso) -(a1->ganancia/a1->peso);

}

//Meterlo en un vector la relacion lo multiplicas por cien y te quedas con la parte entera
/**
 * Devuelvo el tamaño del vector sol que tendrá las mochilas que tenemos que coger
 * @param mochilas
 * @param tamM
 * @param sol
 * @return
 */
ivector mochila(heap_aristas mochilas,int tamM, int capacidad,int *tam){
    ivector sol = icreavector(tamM);
    int iMochilas = 0;
    int iSol = 0;
    int capacidadTotal = capacidad;
    while(capacidad > 0 && iMochilas < tamM ){

        heap_aristas_tbase seleccion = heap_aristas_saca(mochilas,fcomp);
        ++iMochilas;
        struct Mochila elegido;
        elegido.mochila = seleccion.mochila;
        elegido.peso = seleccion.peso;
        elegido.ganancia = seleccion.ganancia;

        if(capacidad - seleccion.peso >=0){
            capacidad -= seleccion.peso;


            sol[iSol] = elegido;
            ++iSol;
        }else{
            //Cogo lo que sobra
            int variacion = elegido.peso-capacidad;
            if(variacion >0 ){
                float r = ((float)capacidad/(float)(elegido.peso));
                elegido.ganancia =elegido.ganancia *r; //No sería la total
                capacidad -= capacidad;
                sol[iSol] = elegido;
                ++iSol;
            }
        }


    }
    *tam = iSol;
    return sol;

}
int main(){

    heap_aristas heapMochilas;
    int numObjetos = 5;
    heap_aristas_tbase vector[numObjetos];
    //ivector vector= icreavector(numObjetos);


    vector[0].mochila = 1;
    vector[0].ganancia = 20;
    vector[0].peso = 10;

    vector[1].mochila =2 ;
    vector[1].ganancia =30 ;
    vector[1].peso = 20;

    vector[2].mochila =3 ;
    vector[2].ganancia = 66;
    vector[2].peso =30 ;

    vector[3].mochila = 4;
    vector[3].ganancia = 40;
    vector[3].peso = 40;

    vector[4].mochila = 5;
    vector[4].ganancia =60 ;
    vector[4].peso = 50;

    heapMochilas = heap_aristas_crea(vector,numObjetos,fcomp);

    int tam ;
    ivector sol = mochila(heapMochilas,numObjetos,100,&tam);
    int suma = 0;
    for(int i=0;i<tam;++i){
        //printf("Mochila: %d   ",sol[i].mochila);
        suma += sol[i].ganancia;
    }
    printf("Ganancia %d",suma);
    ifreevector(&sol);
    heap_aristas_destruye(&heapMochilas);
    return 0;
}