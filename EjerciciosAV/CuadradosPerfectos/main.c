


#include <stdio.h>

void cuadradosPerfectos(int filas, int columnas){
    int cuadros = filas*columnas;
    int cuadrado ;

    if(filas >= columnas){
        cuadrado  = columnas;

    }else{
        cuadrado  = filas;

    }

    while(cuadros != 0){

        if(cuadrado *cuadrado  <= cuadros && (filas >= cuadrado && columnas >=cuadrado) ){
            if(filas>= columnas){
                filas -= cuadrado;
            }else{
                columnas -= cuadrado;
            }
            printf("%d x %d \n", cuadrado , cuadrado );
            cuadros -= cuadrado  * cuadrado ;
        }else{
            cuadrado -=1;
        }

    }


}



int main(){
    int filas = 9;
    int columnas = 5;
    printf("Tamanio de los cuadrados perfectos que podemos hacer con una matriz de %d x %d\n",filas,columnas);
    cuadradosPerfectos(filas,columnas);

    return 0;
}