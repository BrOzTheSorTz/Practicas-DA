
#include <stdio.h>
#include "ivector.h"


/**
 * Busca el mayor subconjunto de notas
 * @param v
 * @param ini
 * @param fin
 * @param pos1
 * @param pos2
 * @return Devuelve las posiciones a partir de las cuales se realiza la suma
 */
int maximo (ivector v, int ini, int fin,int* pos1,int*pos2){

    int suma = 0;
    int max = 0;
    int k = ini;
    while(k <= fin){
        for (int i = k; i <= fin; ++i) {
            for (int j = k; j <= i; ++j) {
                suma += v[j];
            }
            if(suma >= max){
                max = suma;
                *pos1 =k;
                *pos2 =i;
            }
            suma = 0;
        }
        ++k;
    }

    return max;
}


int maximoDeCentroAIzq(ivector v, int ini,int fin,int *pos1){
    int suma = 0;
    int max = -9999;
    for(int i=fin;i<=ini;--i){
        suma+= v[i];
        if(suma> max){
            max = suma;
            //Guardo posiciones
            *pos1 = i;
        }
    }
    return max;

}


int maximoDeCentroADer(ivector v, int ini,int fin,int *pos2){
    int suma = 0;
    int max = -9999;
    for(int i=ini;i<=fin;++i){
        suma+= v[i];
        if(suma> max){
            max = suma;
            //Guardo posiciones
            *pos2 = i;
        }
    }
    return max;

}

int maxDyV(ivector v, int ini, int fin, int *pos1, int *pos2){
    int derPos1,derPos2;

    if(fin-ini+1 <=4){
        return maximo(v,ini,fin,pos1,pos2);
    } else{

        int medio =(fin +ini)/2;
        int mizq = maxDyV(v,ini,medio,pos1,pos2);
        int mder = maxDyV(v,medio+1,fin,&derPos1,&derPos2);

        int max=-9999,suma = 0;
        int medioPos1,medioPos2;
        //-----CÁLCULO PARA MÁXIMO EN MITAD----------------

        int m1 = maximoDeCentroAIzq(v,ini,medio,&medioPos1);
        int m2 = maximoDeCentroADer(v,medio+1,fin,&medioPos2);

        int maxInterm = m1 +m2;

        //--COMBINACIÓN DE CASOS------
        if(mizq >= mder && mizq >= maxInterm){

            return mizq;
        }else if( mder >= mizq && mder >= maxInterm){
            *pos1 = derPos1;
            *pos2 = derPos2;

            return mder;

        }else if( maxInterm >= mizq && maxInterm >= mder){

            *pos1 = medioPos1;
            *pos2 = medioPos2;

            return maxInterm;
        }

    }




}

int main(){

    ivector v = icreavector(28);
    v[0] = 29;
    v[1] = -7;
    v[2] = 14;
    v[3] = 21;
    v[4] = 30;
    v[5] = -47;
    v[6] = 10;

    v[7] = 7;
    v[8] = -39;
    v[9] = 23;
    v[10] = -20;
    v[11] = -36;
    v[12] = -41;
    v[13] = 27;

    v[14] = -34;
    v[15] = 7;
    v[16] = 48;
    v[17] = 35;
    v[18] = -46;
    v[19] = -16;
    v[20] = 32;

    v[21] = 18;
    v[22] = 5;
    v[23] = -33;
    v[24] = 27;
    v[25] = 28;
    v[26] = -22;
    v[27] = 1;

    int pos1;
    int pos2;
    int max = maximo(v,0,27,&pos1,&pos2);
    printf("NOTA MAX: %d desde %d hasta %d",max,pos1+1,pos2+1);


    return 0;
}