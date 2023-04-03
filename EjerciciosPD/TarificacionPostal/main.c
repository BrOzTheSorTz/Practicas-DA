#include <stdio.h>
#include "ivector.h"
#include "imatriz2d.h"

/**
 * Se emiten n sellos diferentes
 * Con valores de s1 a sn.
 * Se quiere enviar una carta y se sabe que la tarifa es T
 *
 * ¿De cuantas formas diferentes se puede franquear?
 * @return número de formas
 */
 int tarificacionPostal(int nSellos, ivector valor,int T){

    imatriz2d tabla = icreamatriz2d(nSellos+1,T+1);
    /*Casos triviales*/
    for (int i = 0; i < nSellos; ++i) {
        tabla[i][0] = 1; //Una forma de franquear una carta con T = 0
    }
    for (int i = 0; i < T; ++i) {
        tabla[0][i] = 0; //Si no tienes sellos no puedes franquearla de ninguna manera
    }


    /*Enfoque ascendente*/
    for (int i = 1; i <= nSellos; ++i) {
        for (int j = 1; j <= T; ++j) {
            if(valor[i-1] > j){
                tabla[i][j] = tabla[i-1][j];

            }else{
                tabla[i][j] = tabla[i-1][j] + tabla[i][j-valor[i-1]];

            }

        }

    }


    int res = tabla[nSellos][T];
    ifreematriz2d(&tabla);
    return res;

 }



int main(){
    int nSellos = 4;
    int T = 12;
    ivector valor = icreavector(nSellos);
    valor[0] = 1;
    valor[1] = 5;
    valor[2] = 10;
    valor[3] = 20;

    int res = tarificacionPostal(nSellos,valor,T);
    printf("\nFormas:  %d",res);


    return  0;
}