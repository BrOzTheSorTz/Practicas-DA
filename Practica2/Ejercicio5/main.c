#include <stdio.h>

int main() {
    int n; // número de gasolineras en la ruta
    int km; // distancia que se puede recorrer con el tanque lleno
    int gas[n]; // distancias de cada gasolinera desde el origen
    int num_paradas = 0; // número de paradas necesarias
    int pos_actual = 0; // posición actual del camión en la ruta

    // leer los datos de entrada
    scanf("%d %d", &n, &km);
    for (int i = 0; i < n; i++) {
        scanf("%d", &gas[i]);
    }

    // recorrer la ruta y parar en la gasolinera más cercana antes de quedarse sin gasolina
    while (pos_actual < n) {
        int pos_parada = pos_actual;
        while (pos_parada < n - 1 && gas[pos_parada + 1] - gas[pos_actual] <= km) {
            pos_parada++;
        }
        if (pos_parada == pos_actual) {
            printf("No se puede llegar a la gasolinera de destino.\n");
            return 0;
        }
        if (pos_parada < n - 1) {
            num_paradas++;
        }
        pos_actual = pos_parada;
    }

    // imprimir el resultado
    printf("%d\n", num_paradas);

    return 0;
}
