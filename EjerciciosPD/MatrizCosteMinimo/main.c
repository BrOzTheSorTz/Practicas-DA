#include <stdlib.h>
#include <stdio.h>
#include "imatriz2d.h"
int min(int n1,int n2){
    if ( n1 <= n2){
        return n1;
    }
    return n2;
}
int camino_en_matriz(imatriz2d datos,int filas,int columnas){
    int i,j;
    imatriz2d longCaminos = icreamatriz2d(filas,columnas);

    longCaminos[0][1] = datos[0][1] +datos[0][0]; //Para que cuente el coste del origen
    longCaminos[1][0] = datos[1][0] + datos[0][0];

    // Completar filas y columnas -> es trivial
    for(j=2;j<filas;++j){   //Valores de la primera fila
        longCaminos[j][0] = longCaminos[j-1][0] + datos[j][0];
    }

    for(i=2;i<columnas;++i){ //Valores de la primera columna
        longCaminos[0][i] = longCaminos[0][i-1] + datos[0][i];
    }

    //AL empezar en 0 no se tiene en cuenta el coste
    //del origen;pero sí del fin pues se llega a este
    for(i=1;i<filas;++i){
        for(j=1;j<columnas;++j){

            longCaminos[i][j] = min(longCaminos[i-1][j],longCaminos[i][j-1]) + datos[i][j];
        }
    }


    int res= longCaminos[filas-1][columnas-1];
    ifreematriz2d(&longCaminos);


    return res;
}

int main(){

    imatriz2d datos = icreamatriz2d(4,5);
    for(int i=0;i<4;++i){
        for(int j=0;j<5;++j){
            datos[i][j] = rand() % 10;
            printf("%d  ",datos[i][j]);
        }
        printf("\n");
    }

    int res = camino_en_matriz(datos,4,5);
    printf("Longitud del camino mínimo %d",res);

    ifreematriz2d(&datos);

    return 0;
}