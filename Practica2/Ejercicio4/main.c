
//Tenemos n bombillas y se necesitan m para iluminar una habitación.
//Maximizar el número de días que la sala esté iluminada

/*
 * Heuristica voraz: Ir quedándonos
 * con las bombillas de mayor duración*/


#include <malloc.h>
#include <stdlib.h>
#include "ivector.h"
#include "vdin.h"

int compare(const void * a,const void *b){

    struct Bombilla *a1 = (struct Bombilla*)a;
    struct Bombilla *b1 = (struct Bombilla*)b;
    //De mayor a menor por la duracion

    return (b1->duracion - a1->duracion);

}

ivector iluminacionContinua(ivector bombillas,int tam, int m){
    ivector conjSol = icreavector(tam); // Guardaremos el id de las bombillas prometedoras
    int iSol = 0;
    qsort(bombillas,tam,sizeof (struct Bombilla),&compare);
    ivector conjuntoDeM = icreavector(m);
    int iConjunto = 0;

    for(int i=0;i<m;++i){
        // Cojo los primeros m candidatos
        conjSol[iSol].id = bombillas[i].id;
        conjSol[iSol].duracion = bombillas[i].duracion;

        ++iSol;

        conjuntoDeM[iConjunto].id = bombillas[i].id;
        conjuntoDeM[iConjunto].duracion = bombillas[i].duracion;

        ++iConjunto;

    }
    int bomCogidas = m;
    int hayLuz = 1;
    int dias = 0;
    while(hayLuz){

        for(int i=0;i<m;++i){
            printf("ID: %d ",conjuntoDeM[i].id);
        }
        printf("\n");
        //Cada iteracion es un dia

        for (int i=0;i<m;++i){
            conjuntoDeM[i].duracion -=1;
            if(conjuntoDeM[i].duracion == 0 ){
                if(bomCogidas < tam){
                    //Seleccion
                    conjuntoDeM[i].id = bombillas[iSol].id;
                    conjuntoDeM[i].duracion = bombillas[iSol].duracion;

                    conjSol[iSol].id= bombillas[iSol].id;
                    conjSol[iSol].duracion = bombillas[iSol].duracion;

                    ++iSol;
                    ++bomCogidas;
                }else{
                    hayLuz = 0;
                }

            }

        }
        ++dias;

    }

    printf("Dias con luz: %d\n",dias);
    ifreevector(&conjuntoDeM);


    return conjSol;
}


int main(){
    ivector bombillas = icreavector(10);

    bombillas[0].id =1 ;
    bombillas[0].duracion = 1;
    bombillas[1].id = 2;
    bombillas[1].duracion = 4;
    bombillas[2].id = 3;
    bombillas[2].duracion = 2;
    bombillas[3].id = 4;
    bombillas[3].duracion = 3;
    bombillas[4].id = 5;
    bombillas[4].duracion = 1;

    bombillas[5].id = 6;
    bombillas[5].duracion = 1;
    bombillas[6].id = 7;
    bombillas[6].duracion = 3;
    bombillas[7].id = 8;
    bombillas[7].duracion = 1;
    bombillas[8].id = 9;
    bombillas[8].duracion = 5;
    bombillas[9].id = 10;
    bombillas[9].duracion = 2;

    ivector sol = iluminacionContinua(bombillas,10,3);
    for(int i=0;i<10;++i){
        printf("%d ",sol[i]);
    }


    return 0;
}