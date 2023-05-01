


#include <limits.h> ///INT_MAX
#include <stdio.h>
#include "ivector.h"
#include "imatriz2d.h"

/**
 * M = {1,5,12,20} Sistema Monetario
 * C = Cantidad a devolver
 *
 * devevolvemos el menor numero de monedos para devolver C
 * */

ivector cambioMonedas(ivector M, int tam, int C, int *numMonedas,int *tamCamino){
    int tamM = tam+1;
    imatriz2d monedas = icreamatriz2d(tamM + 1, C + 1);

    /*Casos triviales*/
    for(int i = 0;i<= C;++i){
        monedas[0][i] = INT_MAX;
    }
    for(int i = 0;i<=tamM;++i){
        monedas[i][0] = 0;
    }


    /*Rellenamos monedas*/
    for(int i=1;i<=tamM;++i){
        for(int j=1;j<=C;++j){

            if(M[i-1] > j){     //Si el valor de la moneda actual supera el coste
                monedas[i][j] = monedas[i-1][j];
            }else{              //Si el valor de la moneda no supera el coste actual
                monedas[i][j] = monedas[i-1][j];
                //Si el nº de monedas de usar la moneda es menor que no usarla
                if(monedas[i][j-M[i-1]]+1 < monedas[i][j]){
                    monedas[i][j] = monedas[i][j-M[i-1]]+1;
                }

            }

        }
    }

    /*Cogemos el número menor de la ultima columna*/
    int i,j;
    int min = monedas[0][C];
    j= C;
    for(int k=1;k<=tamM;++k){
        if( min > monedas[k][C]){
            min = monedas[k][C];
            i = k;

        }
    }
    printf("%d\n",monedas[tamM][C]);
    //La solución va a estar en monedas[tamM][C]
    *numMonedas = min;
    //------------------------------------------CAMINO ÓPTIMO--------------------------------------------

    ivector vMonedas = icreavector(min);
    int iMonedas = 0;
    while( min != 0){
        if(monedas[i-1][j] == min){ // Si hes igual que el de arriba quiere decir que no he cogido esa moneda
            --i;
        }else{
            vMonedas[iMonedas] = M[i-1]; //He usado dicha moneda
            ++iMonedas;

            min = monedas[i][j-M[i-1]]; //Me voy hacia la izq tantas veces como el valor de la moneda y veo que ocurre

            j = j-M[i-1];
        }

    }

    ifreematriz2d(&monedas);
    *tamCamino = iMonedas;
    return vMonedas;
}




int main(){

    //--------------------------------------------PRUEBA--------------------------------------------
    ivector M = icreavector(4);
    M[0] = 1;
    M[1] = 5;
    M[2] = 12;
    M[3] = 20;

    int tam = 4;
    int C = 24;
    int numMonedas,tamCamino;

    ivector monedas = cambioMonedas(M,tam,C,&numMonedas,&tamCamino);
    printf("Monedas usadas: \n");
    for(int i=0;i<tamCamino;++i){
        printf("%d   ",monedas[i]);

    }
    printf("\nNº de monedas: %d",numMonedas);


    return 0;

}