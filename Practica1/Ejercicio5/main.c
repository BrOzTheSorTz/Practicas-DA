#include <stdio.h>
#include <stdlib.h>
#include "imatriz2d.h"

//Algoritmo clásico
int calcMatriz( imatriz2d m,int xinf,int yinf, int xsup, int ysup, int rangInf,int rangSup){

    int cont = 0;
    for(int i=xinf;i<=xsup;++i){
        for(int j=yinf;j<=ysup;++j){
            if(m[i][j] >= rangInf && m[i][j] <= rangSup){
                ++cont;
            }
        }
    }

    return cont;

}

int calcMatrizDyV(imatriz2d m, int xinf, int yinf, int xsup, int ysup, int rangInf,int rangSup){
    if(xsup - xinf +1 <= 2){
        return calcMatriz(m,xinf,yinf,xsup,ysup,rangInf,rangSup);
    }else{
        int mitad = (xinf + xsup)/2;
        //1º Parte

        int c1 = calcMatrizDyV(m,xinf,yinf,xinf+mitad,xinf+mitad,rangInf,rangSup);
        //2º Parte

        int c2 = calcMatrizDyV(m,xinf,yinf+mitad+1,xinf+mitad,ysup,rangInf,rangSup);
        //3º Parte

        int c3 = calcMatrizDyV(m,xinf+mitad+1,yinf,xsup,yinf+mitad,rangInf,rangSup);
        //4º Parte

        int c4 = calcMatrizDyV(m,xinf+mitad+1,yinf+mitad+1,xsup,ysup,rangInf,rangSup);


        return c1 + c2 + c3 + c4;

    }


}



int main(){
    imatriz2d m = icreamatriz2d(4,4);
    m[0][0] = 4;
    m[0][1] = 8;
    m[0][2] = 5;
    m[0][3] = 6;

    m[1][0] = 6;
    m[1][1] = 12;
    m[1][2] = 4;
    m[1][3] = 1;

    m[2][0] = 3;
    m[2][1] = 1;
    m[2][2] = 3;
    m[2][3] = 5,

    m[3][0] = 5;
    m[3][1] = 13;
    m[3][2] = 6;
    m[3][3] = 2;

    int c = calcMatrizDyV(m,0,0,3,3,5,8);
    printf("%d",c);

    ifreematriz2d(&m);




    return 0;
}