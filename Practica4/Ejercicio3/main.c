
#include <ivector.h>
#include <stdio.h>

void imprime(ivector v, int tam){
    for(int i=0;i<tam;++i){
        printf("%c  ",v[i]);
    }
    printf("\n");
}
int esVocal(char letra){
    if( letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U' ){
        return 1;
    }
    return 0;
}

int factible2(ivector palabra,int tam){
    char vocales[] = {'A','E','I','O','U'};
    if(tam > 5){
        return 0;
    }else{
        int contadorVocales =0;
        int tamVocales = 5;
        for(int i=0;i<tam && contadorVocales <2 ;++i){
            for(int j=0;j<tamVocales && contadorVocales <2;++j){
                if(palabra[i] == vocales[j]){
                    ++contadorVocales;
                }
            }
        }
        if(contadorVocales > 2){
            return 0;
        }
        return 1;
    }
}

/**
 * Devuelve si la palabra tiene más de longitud 5.
 * Si metemos una letra que haya espacio para el número de vocales restantes
 * @param palabra
 * @param tam
 * @param tamMax
 * @param letra
 * @return
 */
int factible(ivector palabra,int tam,int tamMax, char letra){
    if((tam+1) > tamMax){
        return 0;
    }
    int numVocales = 0;
    for(int i=0;i<tam;++i){
        if(esVocal(palabra[i])){
            ++numVocales;
        }
    }
    if(numVocales == 0 && esVocal(letra)){
        //Hay sitio para otra vocal
        if((tamMax - (tam+1)) ==  0){
            return 0;
        }else{
            return 1;
        }

    }else if(numVocales == 0 && !esVocal(letra)){
        //Hay sitio para otras 2 vocales
        if((tamMax - (tam+1)) >= 2){
            return 1;
        }else{
            return 0;
        }

    }else if(numVocales == 1 && esVocal(letra)){
        return 1;
    }else if(numVocales == 1 && !esVocal(letra)){
        //Hay sitio para otra vocal
        if((tamMax - (tam+1)) >= 1){
            return 1;
        }else{
            return 0;
        }

    }else if(numVocales == 2 && !esVocal(letra)){
        return 1;

    }else if(numVocales == 2 && esVocal(letra)){
        return 0;
    }
}
void palabrasTodas(ivector letras,int tam,ivector palabra,int tamP ,int numVocales){
    if(numVocales == 2){
        imprime(palabra,tamP);
    }
    //Como aqui una solución puede tener el prefijo de otra
    //no ponemos el else
    for(int i=0;i<tam;++i){

        if(factible(palabra,tamP,5,letras[i])){
            int aSumar = 0;
            palabra[tamP] = letras[i];
            if(esVocal(letras[i])){
                aSumar = 1;
            }
            palabrasTodas(letras,tam,palabra,tamP +1,numVocales+aSumar);
        }
    }
}



int main(){
    ivector letras = icreavector(8);
    letras[0] = '1';
    letras[1] = '2';
    letras[2] = '3';
    letras[3] = 'A';

    letras[4] = 'E';
    letras[5] = 'I';
    letras[6] = 'O';
    letras[7] = 'U';

    int longPalabra = 5;
    ivector palabra = icreavector(longPalabra);
    palabrasTodas(letras,8,palabra,0,0);


    return 0;
}