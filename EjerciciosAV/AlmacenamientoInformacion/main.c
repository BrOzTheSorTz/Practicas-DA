

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

/*Queremos maximizar el número de archivos almacenados en disco*/
ivector almacenamiento1(ivector archivos,int tam,int espacioDisco){
    //----Crear vector dinámico-----------
    //todo niIdea
    vdin sol1;
    int MAX=tam;
    sol1 = vdin_nuev(sizeof(struct Archivos));

    for(int i=0;i<MAX;++i){
        vdin_aumd(sol1,&i);
    }
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



    return sol;
}


/*Queremos maximizar el espacio utilizado del disco*/
//Heurística: Seleccionar uno al azar y de ese uno ir eligiendo

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


    ivector sol = almacenamiento1(archivos,6,5);

    for(int i=0;i<6;++i){
        printf("Archivos: %d\n",sol[i].numero);
    }

    ifreevector(&sol);

    return 0;
}