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
