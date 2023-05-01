#include <ivector.h>
#include <stdio.h>
#include <stdbool.h>

/**
* @author José Pablo Soriano Torres
**/

bool factible(ivector v, int n, int i, int sumaPar, int sumaImpar, int puestas);

void imprime(ivector v, int tam){
    for(int i=0;i<tam;++i){
        printf("%d  ",v[i]);
    }
    printf("\n");
}

void sumaDigitos(ivector v, int n,int sumaPar,int sumaImpar,int puestas){
    int aSumarPar,aSumarImpar;
    if(puestas == n){
        //imprime solucion
        imprime(v,n);
    }else{
        for(int i=1;i<=5;++i){
            if(puestas %2 == 0){
                /*
                 * Si la posición es par entonces lo que tengo que sumar es
                 * a la suma par y no a la suma impar y viceversa.
                 */

                aSumarPar = i;
                aSumarImpar = 0;
            }else{
                aSumarImpar = i;
                aSumarPar = 0;
            }

            if(factible(v,n,i,sumaPar+aSumarPar,sumaImpar+aSumarImpar,puestas+1)){
                v[puestas] = i;
                sumaDigitos(v,n,sumaPar+aSumarPar,sumaImpar+aSumarImpar,puestas+1);
            }
        }
    }
}

/**
 * Función de factibilidad.
 * Calcula si a partir de los números elegidos y los que quedan
 * es posible igualar las sumas pares e impares.
 * Si la sumaPar es menor que la impar
 *  Vemos si la diferencia es mayor que lo que me queda por sumar si lo sumo por el valor máximo
 *  Si es así no puedo llegar a esa suma luego no sería factible esa solución.
 * @param v
 * @param n
 * @param i
 * @param sumaPar
 * @param sumaImpar
 * @param puestas
 * @return true or false
 */
bool factible(ivector v, int n,int i, int sumaPar, int sumaImpar, int puestas) {

    /*
     * Si la sumaPar es menor que la Impar vemos
     * si podemos alcanzar con las posiciones que nos queda a la sumaImpar
     * Para ello sumamos tantas veces el mayor valor como sea posible
     * y comparamos con la diferencia.
     *
     * E igual con el otro caso
     */
    if( sumaPar < sumaImpar){
        //Diferencia mayor que lo que me queda de pares pues false
        int diff = sumaImpar-sumaPar;
        int porSumar = 0;
        for(int i = puestas;i<n;++i){
            if(i %2 == 0){
                porSumar +=5; // El máximo valor
            }
        }
        //Si la diferencia que nos queda por sumar
        //es mayor que el máximo de lo que podemos sumar
        //no es factible
        if( diff > porSumar){
            return false;
        }

        return true;
    }else if (sumaPar > sumaImpar){
        //Diferencia mayor que lo que me queda de pares pues false
        int diff = sumaPar-sumaImpar;
        int porSumar = 0;
        for(int i = puestas;i<n;++i){
            if(i %2 != 0){
                porSumar +=5; // El máximo valor
            }
        }
        if( diff > porSumar){
            return false;
        }

        return true;
    }

    return true;

}


int main(){
    int n = 4;
    ivector v = icreavector(n);

    sumaDigitos(v,n,0,0,0);

    ifreevector(&v);




    return 0;
}
