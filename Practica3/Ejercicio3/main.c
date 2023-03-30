
#include <stdio.h>
#include <stdlib.h>
#include "ivector.h"
#include "imatriz2d.h"

/*Función recursiva*/
int funcion(int m, int n, ivector v){
    if( m == 0){
        return 1;
    }else if ( n == 0){
        return 1;
    }else{
        int suma = 0;
        if(n < v[m]){
            return funcion(m-1,n,v);
        }else{

            for(int i=1;i<=v[m]-1;++i){
                suma += funcion(m,n-i,v);
            }
            return suma;
        }
    }
}
int sumatoria ( int m, int n, int valor, imatriz2d matriz){
    int suma = 0;
    for(int i = 1; i<= valor;++i){
        suma += matriz[m][n-i]; //Valores de la izquierda
    }
    return suma;
}
/*Programación Dinamíca*/
int funcionPD(int m, int n, ivector v){
    imatriz2d matriz = icreamatriz2d(m+1,n+1);

    /*Casos triviales*/
    for(int i = 0;i<=m;++i){
        matriz[i][0] = 1; // Primera columna
    }
    for(int i = 0;i<=n;++i){
        matriz[0][i] = 1; // Primera fila
    }

    /*Completar estructura*/
    for(int i=1;i<= m;++i){
        for(int j=1;j<= n;++j){
            if(j < v[i]){
                matriz[i][j] = matriz[i-1][j]; // Valor de arriba
            }else{
                matriz[i][j] = sumatoria(i,j,v[i]-1,matriz);
            }
        }
    }
    int res = matriz[m][n];
    ifreematriz2d(&matriz);
    return res;

}
int main(){
    int m = 13;
    int n = 23;
    ivector v = icreavector(m+1); // tam m+1
    for(int i=0;i<m+1;++i){
        v[i] = rand() % 100;

    }

    printf("Funcion recursiva\n");
    int num = funcion(m,n,v);
    printf("Valor: %d\n",num);

    printf("Funcion PD\n");
    int num2 = funcionPD(m,n,v);
    printf("Valor: %d\n",num2);

    ifreevector(&v);

    return 0;
}