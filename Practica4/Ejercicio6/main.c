#include <ivector.h>
#include <imatriz2d.h>
#include <stdio.h>
#include <stdbool.h>

bool factible(ivector sol, int ciudad,int puestas, imatriz2d ady,int suma,int optimo);

void imprime(ivector v, int tam,imatriz2d ady){
    int suma = 0;
    for(int i=0;i<tam;++i){
        printf("%d  ",v[i]+1);
        suma += ady[v[i%tam]][v[(i+1)%tam]];
    }

    printf("\nCon una distancia recorrdida de %d.\n",suma);
}

void viajante(imatriz2d ady,int numCiudades,int puestas,ivector sol,int camino,int *optimo,ivector cOptimo){
    if(puestas == numCiudades){
        if(camino + ady[sol[puestas-1]][sol[0]] < *optimo){
            *optimo = camino+ady[sol[puestas-1]][sol[0]]; //Sumamos la vuelta también cuando llega al final
            for(int i=0;i<numCiudades;++i){
                cOptimo[i] = sol[i];
            }
        }
    }else{
        for(int i=0;i<numCiudades;++i){
            if(factible(sol,i,puestas,ady,camino,*optimo)){
                sol[puestas] = i;
                int aSumar = 0;
                if(puestas != 0){
                    aSumar =ady[sol[puestas-1]][sol[puestas]];
                }

                viajante(ady,numCiudades,puestas+1,sol,camino+aSumar,optimo,cOptimo);


            }
        }
    }
}

bool factible(ivector sol,int ciudad, int puestas, imatriz2d ady,int suma,int optimo) {

    for(int i=0;i<puestas;++i){
        //Si la ciudad ya la hemos puesto no es factible
        if(sol[i] == ciudad){
            return 0;
        }
    }

    if(puestas == 0 ){
        return 1; //Es la primera ciudad luego no hay que verificar conexiones

    }
    int filas = puestas-1;
    int colum = puestas;


    if(ady[filas][colum] != -1 && suma + ady[filas][colum] < optimo){
        //Si hay conexión entre la anterior y la nueva , es factible
        return 1;
    }


    return 0;
}

int main(){

    imatriz2d ady = icreamatriz2d(6,6);

    ady[0][0] =-1 ;
    ady[0][1] = 3;
    ady[0][2] = 10;
    ady[0][3] = 11;
    ady[0][4] = 7;
    ady[0][5] = 25;

    ady[1][0] = 3;
    ady[1][1] = -1;
    ady[1][2] = 6;
    ady[1][3] = 12;
    ady[1][4] = 8;
    ady[1][5] = 26;

    ady[2][0] = 10;
    ady[2][1] = 6;
    ady[2][2] =-1 ;
    ady[2][3] = 9;
    ady[2][4] = 4;
    ady[2][5] = 20;

    ady[3][0] = 11;
    ady[3][1] = 12;
    ady[3][2] = 9;
    ady[3][3] = -1;
    ady[3][4] = 5;
    ady[3][5] = 15;

    ady[4][0] =7;
    ady[4][1] =8;
    ady[4][2] = 4;
    ady[4][3] = 5;
    ady[4][4] = -1;
    ady[4][5] = 18;


    ady[5][0] =25;
    ady[5][1] =26;
    ady[5][2] = 20;
    ady[5][3] = 15;
    ady[5][4] = 18;
    ady[5][5] = -1;




    ivector sol = icreavector(6);
    ivector vOptimo = icreavector(6);
    int optimo = 999999;//Queremos minimizar pues cogemos un valor grande
    viajante(ady,6,0,sol,0,&optimo,vOptimo);

    imprime(vOptimo,6,ady);


    ifreevector(&sol);
    ifreevector(&vOptimo);
    ifreematriz2d(&ady);



    return 0;
}