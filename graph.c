#include "graph.h"
#include <stdlib.h>
#include <stdio.h>

void reset () {
  printf("\033[0;37m");
}

void yellow () {
  printf("\033[0;33m");
}

void menu(){
    int num = 0;
    while(num<1 || num>8){
        yellow();
        printf("1.- Importar archivo de coordenadas\n");
        printf("2.- Calcular distancia entre 2 entregas\n");
        printf("3.- Mostrar 3 entregas mas cercanas a las coordenadas ingresadas\n");
        printf("4.- Crear ruta\n");
        printf("5.- Generar ruta aleatoria\n");
        printf("6.- Mejorar ruta\n");
        printf("7.- Mostrar rutas\n");
        printf("8.- Mejor ruta\n");
        printf("9.- Salir\n");
        reset();
        printf("~Ingrese el numero que corresponda a la operacion que desea realizar: ");
        scanf("%d", &num);
        printf("\n");
        reset();
        switch (num){
        case 1:
          printf("Estamos trabajando para usted!\n");
            break;
        case 2:
          printf("Estamos trabajando para usted!\n");
            break;
        case 3:
          printf("Estamos trabajando para usted!\n");
            break;
        case 4:
          printf("Estamos trabajando para usted!\n");
            break;
        case 5:
          printf("Estamos trabajando para usted!\n");
            break;
        case 6:
          printf("Estamos trabajando para usted!\n");
            break;
        case 7:
          printf("Estamos trabajando para usted!\n");
            break;
        case 8:
          printf("Estamos trabajando para usted!\n");
            break;
        case 9:
          printf("Adios!\n");
          return;
            break;
        default:
          printf("La opcion ingresada no es valida, elija nuevamente\n\n");
            break;
        }
    }
}

