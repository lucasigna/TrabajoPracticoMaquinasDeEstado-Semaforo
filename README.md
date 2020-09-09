# Trabajo Práctico Máquinas de Estado - Semáforo
Alumno: Lucas I. González

# Memoria descriptiva
Mi sistema representa 2 semáforos en un cruce de 2 calles. Existen 4 estados, dos estados de espera (un semáforo en rojo y el otro en verde y viceversa) y 2 estados de amarillo (un semáforo en rojo y el otro en amarillo y viceversa). En el archivo de configuración se guardan 2 valores, el tiempo que se mantiene en los estados de espera y el tiempo que se mantiene en los estados de amarillo.
# Diagrama
![](https://github.com/lucasigna/TrabajoPracticoMaquinasDeEstado-Semaforo/blob/master/Recursos/Diagrama.jpeg)
# main.c
```c
#include <stdio.h>
#include "lib.h"

int main(void)
{
    tiempos_de_espera set;
    estados estado = verde1;

    set = f_inicio();
    while(1){
      switch (estado) {
        case verde1: estado = f_semaforo1_verde(set);
                     break;
        case amarillo1: estado = f_semaforo1_amarillo(set);
                       break;
        case verde2: estado = f_semaforo2_verde(set);
                     break;
        case amarillo2: estado = f_semaforo2_amarillo(set);
                       break;
      }
    }
    return 0;
}
```
# lib.h
![](https://github.com/lucasigna/TrabajoPracticoMaquinasDeEstado-Semaforo/blob/master/Código/lib/lib.h)

