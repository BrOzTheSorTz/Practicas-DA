

#include <stdio.h>
#include "ivector.h"
#include "imatriz2d.h"

/*
 * Dos amigos, Agonioso y Listillo, salen de botellón. La nueva moda es poner una fila con n
vasos (n es par). Cada vaso i, entre 1 y n contiene una cantidad de líquido ci distinta. Los
amigos beben por turnos. Cada uno, en su turno debe elegir el vaso de uno de los extremos
y beberse su contenido. El vaso se retira y el turno pasa al otro amigo. La persona que
comienza bebiendo se determina a priori por un procedimiento cualquiera. El objetivo de
ambos amigos es beber la mayor cantidad posible de líquido.
La estrategia de Agonioso consiste en pensar poco y coger el vaso de los extremos
que esté más lleno. En cambio Listillo prefiere pensárselo un poco más.
a) Demostrar, con un contraejemplo que la estrategia de Agonioso no es óptima,
incluso cuando le toca escoger primero.
b) Listillo tiene unos amigos que cursan la asignatura de Diseño de Algoritmos y les
pide que le diseñen un algoritmo, basado en Programación Dinámica, para que le
ayude a conseguir su objetivo, suponiendo que es él quien empieza a escoger.

 */

/**
 * Calculamos el número mayor de litros que se puede beber y además el camino óptimo
 * @param vasos Vector en el cual la posición i , indica los litros del vaso i
 * @param n
 * @param litros
 * @return vector con el camino óptimo.
 */
ivector botellonMax(ivector vasos,int n,int * litros){

    imatriz2d tabla = icreamatriz2d(n,n);
    imatriz2d vasosCogidos = icreamatriz2d(n,n);

    /*Casos triviales*/
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(j <n && j == i+1){
                tabla[i][j] = vasos[i];
                vasosCogidos[i][j] = i; //Vaso cogido
                if(vasos[j] > vasos[i]){
                    tabla[i][j] = vasos[j];
                    vasosCogidos[i][j] = j; //Vaso cogido
                }
            }else{
                tabla[i][j] = -1;
            }
        }
    }


    /*Demás casos*/

    for(int i=0;i<n;++i){
        // Partimos de la diagonal principal
        for(int j= i+1;j<n;++j){
            if((j-i+1)%2 == 0 && tabla[i][j] == -1){ //SI el número de vasos es par y no lo hemos calculado previamente
                //Calculamos el valor1
                int valor1 = vasos[i];
                if(vasos[i+1] >= vasos[j]){
                    valor1 += tabla[i+2][j];
                }else{
                    valor1 += tabla[i+1][j-1];
                }

                //Calculamos el valor2
                int valor2 = vasos[j];
                if(vasos[i] >= vasos[j-1]){
                    valor2 += tabla[i+1][j-1];
                }else{
                    valor2 += tabla[i][j-2];
                }

                if(valor1 >= valor2){
                    tabla[i][j] = valor1;
                    vasosCogidos[i][j] = i;
                }else{
                    tabla[i][j] = valor2;
                    vasosCogidos[i][j] = j;
                }

            }


        }
    }
    *litros = tabla[0][n-1];
    ifreematriz2d(&tabla);



    /*CAMINO ÓPTIMO*/
    ivector vasosElegidosPorL= icreavector(n);
    int vaso = vasosCogidos[0][n-1];
    vasosElegidosPorL[vaso] = 1;
    int i;
    int j;

    if(vaso == n-1){
        i = 0;
        j = vaso-1;
    }else{
        i= vaso+1;
        j = n-1;
    }

    while( i != j){
        //Turno de Angonioso
        if(vasos[i] >= vasos[j]){
            i++;     //Se ha cogido el vaso de la izquierda
        }else{
            --j; //Se ha cogido el vaso de la derecha
        }
        vaso = vasosCogidos[i][j];
        vasosElegidosPorL[vaso] = 1;

        //Acotamos el siguiente intervalo
        if(vaso == j){
            j --;
        }else{
            i++;
        }

    }

    ifreematriz2d(&vasosCogidos);
    return vasosElegidosPorL; // Solucion maxima de litros bebidos por Listillo

}



int main(){

    ivector vasos = icreavector(6);
    vasos[0] = 4;
    vasos[1] = 7;
    vasos[2] = 2;
    vasos[3] = 2;
    vasos[4] = 5;
    vasos[5] = 3;

    int litros;
    ivector res = botellonMax(vasos,6,&litros);
    printf("Cantidad maxima %d\n",litros);
    printf("Vasos cogidos por Listillo: \n");
    for(int i=5;i>=0;--i){
        if(res[i] == 1){
            printf("Vaso %d ha sido cogido\n",i);
        }
    }



    return 0;
}