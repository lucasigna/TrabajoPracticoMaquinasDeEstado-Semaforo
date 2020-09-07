#include <stdio.h>
#include <time.h>

//Voy a usar esta función para manejar los tiempos en las otras funciones.
void delay(int number_of_seconds)
{
    // Convierto los segundos a milisegundos
    int milli_seconds = 1000 * number_of_seconds;

    // Guardo el tiempo de inicio
    clock_t start_time = clock();

    // Creo un bucle hasta que se cumpla el tiempo
    while (clock() < start_time + milli_seconds);
}