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
