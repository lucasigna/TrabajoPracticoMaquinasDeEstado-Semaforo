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