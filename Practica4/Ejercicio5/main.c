#include <ivector.h>
#include <stdio.h>
#include <stdbool.h>

bool factible(int cambiar, int valor, ivector monedas,int tam, int numMonedas, int min);

void imprime(ivector v, int tam){
    for(int i=0;i<tam;++i){
        printf("Con moneda %d, se necesitan %d  \n",v[i].valor,v[i].cantidad);
    }
    printf("\n");
}
void cambioMonedasV2(int aCambiar,ivector monedas,ivector sol,int tam,int numMonedas,int *min,ivector optimo){
    if (aCambiar == 0){
        if(numMonedas < *min){
            *min = numMonedas;
            for(int i=0;i<tam;++i){
                optimo[i].cantidad = sol[i].cantidad;
                optimo[i].valor = sol[i].valor;
            }
        }

    }else{
        for(int i=0;i<5;++i){
            if(factible(aCambiar,monedas[i].valor,monedas,tam,numMonedas,*min))
            {
                sol[i].cantidad ++;
                cambioMonedasV2(aCambiar-monedas[i].valor,monedas,sol,tam,numMonedas+1,min,optimo);
                sol[i].cantidad --;
            }
        }
    }
}

bool factible(int cambiar, int valor, ivector monedas,int tam, int numMonedas, int min) {
    //Si la cantidad a devolver es impar
    //y no nos queda monedas impares no es factible, luego no seguir explorando
    // tambien comprobamos si se supera el valor a devolver y el número de monedas minimas
    if(cambiar %2 != 0 && cambiar - valor >= 0 && numMonedas < min){
        for(int i=0;i<tam;++i){
            if(monedas[i].valor %2 != 0 && monedas[i].cantidad != 0){
                return 1;
            }
        }
        return 0; //No quedan monedas impares
    }else if(cambiar - valor >= 0 && numMonedas < min){
        return 1;
    }

    return 0;
}



int main()
{
    ivector monedas = icreavector(8);
    monedas[0].cantidad =5 ;
    monedas[0].valor = 1;
    monedas[1].cantidad =5 ;
    monedas[1].valor = 2;
    monedas[2].cantidad = 5;
    monedas[2].valor = 5;
    monedas[3].cantidad =5 ;
    monedas[3].valor =10 ;

    monedas[4].cantidad = 5;
    monedas[4].valor = 20;
    monedas[5].cantidad = 5;
    monedas[5].valor = 50;
    monedas[6].cantidad = 5;
    monedas[6].valor = 100;
    monedas[7].cantidad = 5;
    monedas[7].valor = 200;

    ivector sol = icreavector(8);

    sol[0].cantidad = 0;
    sol[1].cantidad = 0;
    sol[2].cantidad = 0;
    sol[3].cantidad = 0;
    sol[4].cantidad = 0;
    sol[5].cantidad = 0;
    sol[6].cantidad = 0;
    sol[7].cantidad = 0;

    sol[0].valor = 1;
    sol[1].valor = 2;
    sol[2].valor = 5;
    sol[3].valor = 10;
    sol[4].valor = 20;
    sol[5].valor = 50;
    sol[6].valor = 100;
    sol[7].valor = 200;


    ivector optimo = icreavector(8);
    int min = 99999999;
    cambioMonedasV2(35,monedas,sol,8,0,&min,optimo);
    imprime(optimo,8);


    ifreevector(&optimo);
    ifreevector(&monedas);
    ifreevector(&sol);


    return 0;
}