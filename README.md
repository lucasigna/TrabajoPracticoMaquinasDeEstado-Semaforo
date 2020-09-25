# Trabajo Práctico Máquinas de Estado - Semáforo
Alumno: Lucas I. González

# Memoria descriptiva
Mi sistema representa 2 semáforos en un cruce de 2 calles. Existen 4 estados, dos estados de espera (un semáforo en rojo y el otro en verde y viceversa) y 2 estados de amarillo (un semáforo en rojo y el otro en amarillo y viceversa). En el archivo de configuración se guardan 2 valores, el tiempo que se mantiene en los estados de espera y el tiempo que se mantiene en los estados de amarillo.
# Diagrama
![](https://github.com/lucasigna/TrabajoPracticoMaquinasDeEstado-Semaforo/blob/master/Recursos/Diagrama.jpeg)
# main.c
```c
#include <stdio.h>
#include "../lib/lib.h"
#include "../lib/funciones.c"


int main(void)
{
    tiempos_de_espera set;
    estados estado = verde1;
    estados (*selector[])(tiempos_de_espera) = {f_semaforo1_verde,f_semaforo1_amarillo,f_semaforo2_verde,f_semaforo2_amarillo};

    set = f_inicio();
    while(1){
      // Con puntero a funciones
      estado = (*selector[estado])(set);
      // Con switch case
      /*switch (estado) {
        case verde1: estado = f_semaforo1_verde(set);
                     break;
        case amarillo1: estado = f_semaforo1_amarillo(set);
                       break;
        case verde2: estado = f_semaforo2_verde(set);
                     break;
        case amarillo2: estado = f_semaforo2_amarillo(set);
                       break;
      }*/
    }
    return 0;
}
```
# lib.h
```h
#ifndef MY_LIB
#define MY_LIB
#include <stdio.h>

typedef enum {
  verde1 = 0,
  amarillo1 = 1,
  verde2 = 2,
  amarillo2 = 3
}estados;

typedef struct {
  char t_verde_rojo; // tiempo de semaforos en verde y rojo.
  char t_amarillo;   // tiempo de semaforos en transición.
}tiempos_de_espera;

tiempos_de_espera f_inicio(void); // Lee el archivo de configuración y carga las variables de tiempos.

estados f_semaforo1_verde(tiempos_de_espera);
estados f_semaforo2_verde(tiempos_de_espera);
estados f_semaforo1_amarillo(tiempos_de_espera);
estados f_semaforo2_amarillo(tiempos_de_espera);
void toggle_luz_amarilla(int,int);
void toggle_luz_roja(int,int);
void toggle_luz_verde(int,int);

#endif
```
# funciones.c
```c
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
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

char * getKey(char *key)
{
    char i = 0;
    while(*(key+i) != ' ')
    {
        i++;
    }
    *(key+i) = 0;
    return key+i+1;
}

tiempos_de_espera f_inicio(void)
{
    tiempos_de_espera t;
    char cadena[50], *key, *val;
    char variables[2][20] = {"t_verde_rojo","t_amarillo"}, i;
    FILE *p;
    if((p = fopen("../src/set.txt","rt")) == NULL)
    {
        printf("No se encontró el archivo\n");
    }
    do
    {
        fgets(cadena,40,p);
        key = cadena;
        if(strlen(key) > 0)
        {
            val = getKey(key);
            for(i = 0 ; i<2 ; i++)
            {
                if(!strcmp(key, variables[i]))
                {
                    switch(i)
                    {
                        case 0:
                            t.t_verde_rojo = atoi(val);
                            break;
                        case 1:
                            t.t_amarillo = atoi(val);
                            break;
                    }
                }
            }
        }
    } while(!feof(p));
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
```
# Archivo de configuración
```
t_verde_rojo 10
t_amarillo 5
```
