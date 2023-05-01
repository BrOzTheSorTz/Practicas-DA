#include <imatriz2d.h>
#include <ivector.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/**
 * @author José Pablo Soriano Torres
 * */

void imprime(ivector v, int tam){
    for(int i=0;i<tam;++i){
        printf("%d  ",v[i]);
    }
    printf("\n");
}


bool factibleV2(ivector v, int puestas, int i);
// n va a valer igual que el número de destinos y que el número de transportistas

/**
 * Calculamos por que ciudades debe pasar cada T
 * sin que se repitan y con un coste mínimo
 * @param tabla
 * @param n
 * @param v
 * @param puestas
 * @param suma suma de litros que va teniendo nuestro camino
 * @param optimo Mínimo de litros
 * @param sol Guardaremos la solución
 */
void huelgaV2(imatriz2d tabla,int n,ivector v, int puestas,int suma,int *optimo,ivector sol){

    if(puestas == n ) {
        if (suma < *optimo) {
            *optimo = suma;
            //imprime(v, n);
            //Guardamos solución
            for(int i=0;i<n;++i){
                sol[i] = v[i];
            }
        }

    }else {
        //Recorremos los destinos
        for(int i=0;i<n;++i){

            //Aplicamos la poda de que si ya ha superado a lo mejor se podan
            //las siguientes soluciones
            if(suma < *optimo && factibleV2(v,puestas+1,i)){
                v[puestas] = i; //Ponemos ciudad
                huelgaV2(tabla,n,v,puestas+1,suma+tabla[puestas][i],optimo,sol);
            }


        }
    }
}

/**
 * Comprueba si no hay un transportista que ya esté visitando dicha ciudad
 * @param v
 * @param puestas
 * @param i
 * @return
 */
bool factibleV2(ivector v, int puestas, int i) {
    for(int j=0;j<puestas;++j){
        if(v[j] == i){
            return 0;
        }
    }
    return 1;
}



int main(){

    //Creamos las variables
    int nTransportistas = 4;
    int nDestinos = 4;
    imatriz2d tabla = icreamatriz2d(nTransportistas,nDestinos);
    for(int i=0;i<nTransportistas;++i){
        for(int j=0;j<nDestinos;++j){
            tabla[i][j] = rand() %80 +1;
            printf("%d  ",tabla[i][j]);
        }
        printf("\n");
    }
    ivector v = icreavector(nTransportistas);
    ivector sol = icreavector(nTransportistas);
    for(int i=0;i<nTransportistas;++i){
        v[i] = -1;
    }
    printf("\nSolución: \n");

    //Aplicamos el algoritmo de vuelta atrás.
    int optimo = 99999999;
    huelgaV2(tabla,nTransportistas,v,0,0,&optimo,sol);

    for(int i=0;i<nTransportistas;++i){
        printf("El transportista %d va a %d con una distancia de %d.\n",i+1,sol[i]+1,tabla[i][sol[i]]);
    }

    ifreevector(&v);
    ifreevector(&sol);
    ifreematriz2d(&tabla);

    return 0;
}


