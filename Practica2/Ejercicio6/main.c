
#include "ivector.h"

/*Se quieren colocar n libros en una estantería con m baldas
 *Los libros son muy dispares y sus peros difieren mucho.Se quiere repartir el peso uniformemente
 *
 * Objetivo:Peso uniforme en cada balda
 * Heurítica voraz:Ordenar el peso de los libros de mayor a menor e ir añadiéndolos a la balda
 * que menos peso esté soportando*/

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

struct Balda{
    int id;
    int peso;
};

typedef struct Balda Balda;

int compare(const void *a,const void *b){

    struct Libros* a1 = (struct Libros *) a;
    struct Libros* b1 = (struct Libros *) b;

    //Ordenamos de mayor a menor según el peso
    return (b1->peso - a1->peso);

}
Balda* obtenerMenorPeso(Balda* baldas,int tamB){
    Balda* menor = 0;
    int menorPeso = 9999;
    for(int i=0;i<tamB;++i){
        if(baldas[i].peso<menorPeso){
            menorPeso = baldas[i].peso;
            menor = &baldas[i];
        }
    }

    return menor;

}
void distribucionLibros(ivector libros,int tam,Balda* baldas,int tamB){

    //Ordenamos el vector de libros
    qsort(libros,tam,sizeof (struct Libros),&compare);
    for(int i=0;i<tam;++i){
        struct Libros *libro = &libros[i];
        Balda* conMenorPeso = obtenerMenorPeso(baldas,tamB);
        conMenorPeso->peso +=libros[i].peso;
        libros[i].balda = conMenorPeso->id;
    }


}
void distribucionLibrosConHeap(ivector libros, int tam){

}

int main(){
    //Inicializamos la baldas
    Balda* baldas = malloc(3*sizeof (Balda));
    baldas[0].id =1 ;
    baldas[0].peso =0 ;
    baldas[1].id = 2;
    baldas[1].peso = 0;
    baldas[2].id = 3;
    baldas[2].peso = 0;



    srand(time(NULL));
    //Inicializamos los libros
    ivector libros = icreavector(10);
    for(int i=0;i<10;++i){
        libros[i].id = i+1;
        libros[i].balda = -1;
        libros[i].peso = rand() % 25;
    }


    distribucionLibros(libros,10,baldas,3);

    for(int j=0;j<3;++j){
        printf("BALDA %d\n",j+1);
        for(int i=0;i<10;++i){
            if(libros[i].balda == j+1){
                printf("Libro %d    ",libros[i].id);
            }
        }
        printf("\nPeso Total: %d\n",baldas[j].peso);
    }

    return 0;
}