
#include "imatriz2d.h"

/**
 *
 * @param lab
 * @param filas
 * @param columnas
 * @param i fila inicial de la salida
 * @param j columna inicial de la salida
 * @param coste
 * @param sol
 * @param costeMin
 */
void laberinto(imatriz2d lab,int filas,int columnas,int i,int j,int coste,imatriz2d sol,int *costeMin){
    if(lab[i][j] == 4){
        if(*costeMin > coste){
            *costeMin = coste;
            //Copiar lab en sol
            for(int iC =0;iC<filas;++iC){
                for(int jC = 0;jC<columnas;++jC){
                    sol[iC][jC] = lab[iC][jC];

                }
            }
        }
        //Si no nos salimos
    }else if((i>= 0 && i <filas) && (j >=0 && j < columnas)){
        if(lab[i][j] != 1 && lab[i][j] != 2){
            lab[i][j] = 2;

            laberinto(lab,filas,columnas,i+1,j,coste+1,sol,costeMin);//Hacia arriba
            laberinto(lab,filas,columnas,i-1,j,coste+1,sol,costeMin);//Hacia abajo
            laberinto(lab,filas,columnas,i,j+1,coste+1,sol,costeMin);//Hacia derecha
            laberinto(lab,filas,columnas,i,j-1,coste+1,sol,costeMin);//Hacia izquierda
            lab[i][j] = 0;
        }
    }
}


int main(){





    return 0;
}