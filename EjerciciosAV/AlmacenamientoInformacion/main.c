

#include <stdio.h>
#include "ivector.h"
#include "vdin.h"
#include "stdlib.h"

int compare (const void *a,const void *b){
    struct Archivos* a1 = (struct Archivos*) a;
    struct Archivos* b1 = (struct Archivos*) b;


    //de menor a mayor
    //Intercambia si es positivo
    //Si a=3 y b=1 a-b>0 entonces intercambia luego
    //estamos ordenando de menor a mayor

    return a1->tama - b1->tama;
}

int compareMayor(const void* a, const void* b){
    struct Archivos* a1 = (struct Archivos*) a;
    struct Archivos* b1 = (struct Archivos*) b;


    return b1->tama - a1->tama;
}

/*Queremos maximizar el número de archivos almacenados en disco*/
/*
 * Algoritmo:
 * Ordenamos de menor a mayor el vector y vamos eligiendo el menor hasta que no haya más espacio
 *
 *
 * DEMOSTRACIÓN : No existe una mejor solución que la que nos da este algoritmo
 * =============
 * Imaginemos que tenemos la solución del algoritmo y la llamaremos S, y tenemos otra que consideramos como óptima, S'
 * Por tanto significa que habrá uno o más archivos en S' que en S.
 * Si se diferencian en archivo llamado A , ese archivo será mayor que todos los de S', por tanto si es mayor es imposible
 * que tenga más archivos que S puesto que están ordenados de menor a mayor.
 * Luego hemos llegado a una contradicción y podemos afirmar que este algoritmo da la solución óptima
 *
 * */
ivector almacenamiento1(ivector archivos,int tam,int espacioDisco,int *tamSol){

    //------------------------------------

    ivector sol = icreavector(tam);
    int iSol=0;
    //---Aplicamos heuristica
    qsort(archivos,tam,sizeof(struct Archivos),&compare);
    int ocupado = 0;
    int i =0;
    while(ocupado < espacioDisco && i < tam){
        struct Archivos *candidato= &archivos[i];

        if(ocupado +candidato->tama <= espacioDisco){
             sol[iSol]= *candidato;
             ++iSol;
             ocupado += candidato->tama;

        }

        ++i;

    }


    *tamSol = iSol;
    return sol;
}


/*Queremos maximizar el espacio utilizado del disco
 *
 * No existe ningún algoritmo, una posible solución es usando programación dinámica*/
//Heurística: Seleccionar los dos menores y a partir de ellos ir cogiendo los mayores

ivector almacenamiento2(ivector archivos,int tam,int espacioDisco,int *tamSol){
    //Seleccionamos los dos menores
    /*
     * Ordenamos el vector de mayor a menor y cogemos los dos ultimos
     * luego lo recorremos desde el principio
     * */
    ivector sol = icreavector(tam);
    int iSol = 0;
    qsort(archivos,tam,sizeof (struct Archivos),&compareMayor);
    struct Archivos *menor1, *menor2;
    int fin = tam;
    menor1 = &archivos[tam-1];
    if(espacioDisco - menor1->tama >=0){
        sol[iSol] = *menor1;
        ++iSol;
        --fin;

        menor2 = &archivos[tam-2];
        --fin;
        espacioDisco -= menor1->tama;
        if(espacioDisco -  menor2->tama >=0){
            sol[iSol] = *menor2;
            ++iSol;
            espacioDisco -= menor2->tama;

        }
        int i=0;
        while(espacioDisco > 0 && i<fin){
            struct Archivos *candidato= &archivos[i];
            if(espacioDisco -candidato->tama >= 0){
                sol[iSol] = *candidato;
                ++iSol;
                espacioDisco-=candidato->tama;
            }
            ++i;
        }

    }


    *tamSol = iSol;
    return sol;

}

int main(){

    ivector archivos = icreavector(6);

    archivos[0].numero =1 ;
    archivos[0].tama = 2;

    archivos[1].numero = 2;
    archivos[1].tama = 4;

    archivos[2].numero = 3;
    archivos[2].tama = 1;

    archivos[3].numero = 4;
    archivos[3].tama = 2;

    archivos[4].numero = 5;
    archivos[4].tama = 7;

    archivos[5].numero = 6;
    archivos[5].tama = 1;

    int tam = 0;
    ivector sol = almacenamiento1(archivos,6,8,&tam);

    printf("\nProblema 1\n\n");
    for(int i=0;i<tam;++i){
        printf("Archivo nº %d, tama: %d\n",sol[i].numero,sol[i].tama);
    }

    int tam1 = 0;
    ivector sol1 = almacenamiento2(archivos,6,8,&tam1);
    printf("\nProblema 2\n\n");
    for(int i=0;i<tam1;++i){
        printf("Archivo nº %d, tama: %d\n",sol1[i].numero,sol1[i].tama);
    }
    ifreevector(&sol);
    ifreevector(&sol1);


    return 0;
}