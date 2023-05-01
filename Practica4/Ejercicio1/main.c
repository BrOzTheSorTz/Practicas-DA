#include <ivector.h>
#include <stdio.h>
#include <stdbool.h>


bool factible(ivector pInt,int n, int valor, int puestas, int suma);

void imprime(ivector v, int tam){
    for(int i=0;i<tam;++i){
        printf("%d  ",v[i]);
    }
    printf("\n");
}

/**
 *
 * @param v vector de tamaño n
 * @param n
 * @param valor
 * @param suma Suma que lleva hasta ahora el vector Inicializado a 0
 * @param puestas Número de valores puestos en el vector
 */
void combinacionesDados(ivector v,int n,int valor,int puestas,int suma){
    if(puestas == n){
        imprime(v,n);
    }else{
        //NO hay prefijos, la solución es de longitud fija
        for(int i=1;i<=6;++i){
            v[puestas] = i;
            if(factible(v,n,valor,puestas+1,suma+i)){ //Ver si es factible con ese dado de ahí que pongamos puetas+1 y sumas +i
                combinacionesDados(v,n,valor,puestas+1,suma+i);
            }
        }

    }
}

bool factible(ivector pInt,int n,int valor, int puestas, int suma) {
    int sumaPuestas = 0;
    for(int i=0;i<puestas;++i){
        sumaPuestas += pInt[i];
    }
    if(sumaPuestas > valor){
        //No es factible
        return 0;
    }else{

        //Si con los valores mínimos que me quedan supero el valor -> PODA
        if(sumaPuestas + 1*(n-puestas) > valor){
            return 0;
        }

        //Si con los valores máximos que me quedan no llego al valor -> PODA
        /*
         * el valor máximo es el valor máximo que puedo tener con los dados = 6
         * por el número de dados que me quedan = n-puestas
         * */
        if(sumaPuestas + 6*(n-puestas) < valor){
            return 0;
        }

    }
    return 1;
}


int main(){

    ivector v = icreavector(5);
    int n = 5; //Número de dados
    int valor = 6;

    combinacionesDados(v,n,valor,0,0);

    ifreevector(&v);

    return 0;
}