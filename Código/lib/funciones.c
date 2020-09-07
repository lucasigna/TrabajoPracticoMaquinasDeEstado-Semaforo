#include <stdio.h>
#include <time.h>

//Voy a usar esta función para manejar los tiempos en las otras funciones.
void delay(int segundos)
{
    // Convierto los segundos a milisegundos
    int mili_seg = 1000 * segundos;

    // Guardo el tiempo de inicio
    clock_t inicio = clock();

    // Creo un bucle hasta que se cumpla el tiempo
    while (clock() < inicio + mili_seg);
}