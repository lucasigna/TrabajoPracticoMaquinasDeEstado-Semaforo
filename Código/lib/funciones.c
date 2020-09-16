#include <stdio.h>
#include <time.h>
#include "../lib/lib.h"

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

tiempos_de_espera f_inicio(void)
{
    tiempos_de_espera t;
    FILE *p;
    p = fopen("set.txt","r");
    fread(&t,sizeof(t),1,p);
    fclose(p);
    return t;
}

estados f_semaforo1_verde(tiempos_de_espera t)
{
    //Pongo en verde al semaforo 1
    toggle_luz_amarilla(1,0);
    toggle_luz_roja(0,0);
    toggle_luz_verde(0,1);
    toggle_luz_roja(1,1);
    printf("\n");
    delay(t.t_verde_rojo);
    return amarillo1;
}

estados f_semaforo1_amarillo(tiempos_de_espera t)
{
    //Pongo en amarillo en semaforo 1
    toggle_luz_verde(0,0);
    toggle_luz_amarilla(0,1);
    printf("\n");
    delay(t.t_amarillo);
    return verde2;
}

estados f_semaforo2_verde(tiempos_de_espera t)
{
    //Pongo en verde el semaforo 2 y en rojo el semaforo 1
    toggle_luz_amarilla(0,0);
    toggle_luz_roja(1,0);
    toggle_luz_verde(1,1);
    toggle_luz_roja(0,1);
    printf("\n");
    delay(t.t_verde_rojo);
    return amarillo2;
}

estados f_semaforo2_amarillo(tiempos_de_espera t)
{
    //Pongo en amarillo el semaforo 2
    toggle_luz_verde(1,0);
    toggle_luz_amarilla(1,1);
    printf("\n");
    delay(t.t_amarillo);
    return verde1;
}

void toggle_luz_verde(int semaforo, int toggle)
{
    if(semaforo == 0)
    {
        if(toggle)
        {
            printf("Semaforo 1: Luz VERDE ON\n");
        } else {
            printf("Semaforo 1: Luz VERDE OFF\n");
        }
    } else {
        if(toggle)
        {
            printf("Semaforo 2: Luz VERDE ON\n");
        } else {
            printf("Semaforo 2: Luz VERDE OFF\n");
        }
    }
}

void toggle_luz_amarilla(int semaforo, int toggle)
{
    if(semaforo == 0)
    {
        if(toggle)
        {
            printf("Semaforo 1: Luz AMARILLO ON\n");
        } else {
            printf("Semaforo 1: Luz AMARILLO OFF\n");
        }
    } else {
        if(toggle)
        {
            printf("Semaforo 2: Luz AMARILLO ON\n");
        } else {
            printf("Semaforo 2: Luz AMARILLO OFF\n");
        }
    }
}

void toggle_luz_roja(int semaforo, int toggle)
{
    if(semaforo == 0)
    {
        if(toggle)
        {
            printf("Semaforo 1: Luz ROJO ON\n");
        } else {
            printf("Semaforo 1: Luz ROJO OFF\n");
        }
    } else {
        if(toggle)
        {
            printf("Semaforo 2: Luz ROJO ON\n");
        } else {
            printf("Semaforo 2: Luz ROJO OFF\n");
        }
    }
}
