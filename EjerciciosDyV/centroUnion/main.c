#include <stdio.h>
#include <stdlib.h>
#include "ivector.h"

int centroDyV(ivector x, int infx, int supx,ivector y, int infy, int supy){
    if( supx - infx+1 <=2){
        //CASO BASE

        if(x[supx] < y[infy]){
            // 3|5 <--> 6|9 :5
            return x[supx];
        }else if (x[infx]> y[supy]){
            // 3|4 <--> 1|2 :2
            return y[supy];
        }else if(x[infx] < y[infy]){
            //En caso contrario devolvemos el mayor de los dos primeros
            return y[infy];
        }else if(x[infx] > y [infy]){
            return x[infx];
        }
    }else{
        //CASO GENERAL
        int tam = supx -infx +1;
        int elem1 = x[tam/2 -1];
        int elem2 = y[tam/2 -1];

        if( elem1 == elem2){
            return elem1;
        }else{
            if(elem1 < elem2){
                return centroDyV(x,tam/2,supx,y,infy,tam/2 -1);
            }else{
                return centroDyV(x,infx,tam/2 -1,y,tam/2,supy);
            }

        }



    }
}



int main(){
    ivector v = icreavector(4);
    ivector w = icreavector(4);
    v[0] = 2;
    v[1] = 3;
    v[2] = 4;
    v[3] = 8;

    w[0] = 1;
    w[1] = 2;
    w[2] = 6;
    w[3] = 9;

    int num = centroDyV(v,0,3,w,0,3);
    printf("Elemento: %d",num);

    ifreevector(&v);
    ifreevector(&w);

    return 0;
}