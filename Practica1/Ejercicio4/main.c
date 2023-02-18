#include <stdlib.h>
#include <stdio.h>
#include "ivector.h"

int sumaElementos(ivector v,int ini, int fin,int *max, int *min){

    //Lo tengo que hacer así y no max = &v[ini] porque entonces no devuelvo lo que es por referencia y se esta
    //actualizando el valor en otro sitio distinto al de la variable
    *max = v[ini];
    *min = v[ini];

    int suma = v[ini];


    for(int i=ini+1;i<=fin;++i){

        if( v[i] > *max){
            *max = v[i];
        }
        if( v[i] < *min){
            *min = v[i];
        }

        suma += v[i];

    }


    return suma -*max -*min;


}

int sumaElementosDyV(ivector v,int ini, int fin,int *max,int *min){
    int izqmax =0;
    int izqmin = 0;
    if((fin-ini +1) <= 4){
        return sumaElementos(v,ini,fin,max,min);
    }else {
        int tam = (fin - ini + 1) ;

        int suma1 = sumaElementosDyV(v, ini, ini + tam / 2 - 1, &izqmax, &izqmin);
        int suma2 = sumaElementosDyV(v, ini + tam / 2, fin, max, min);
        int suma = suma1 + suma2;
        //Tengo que saber cuales son los maximos y minimos verdaderos
        if (izqmax > *max){
            suma += *max;
            *max = izqmax;
        }else{
            suma += izqmax;
        }

        if (izqmin < *min){
            suma += *min;
            *min = izqmin;
        }else{
            suma += izqmin;
        }

        return suma;

    }
}
int main(){

    ivector v = icreavector(8);
    v[0] = 4;
    v[1] = 1;
    v[2] = 8;
    v[3] = 7;

    v[4] = 2;
    v[5] = 6;
    v[6] = 9;
    v[7] = 3;
    int *max,*min;
    max = malloc(1);
    min = malloc(1);

    int suma = sumaElementosDyV(v,0,7,max,min);
    printf("Suma: %d", suma);

    free(max);
    free(min);




    return 0;
}