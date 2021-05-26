#include "graph.h"
#include "list.h"
#include "Map.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int is_equal_string(void * key1, void * key2) {
    if(strcmp((char*)key1, (char*)key2)==0) return 1;
    return 0;
}

//  función para comparar claves de tipo string
//  retorna 1 si son key1<key2

int lower_than_string(void * key1, void * key2) {
    if(strcmp((char*)key1, (char*)key2) < 0) return 1;
    return 0;
}

//  función para comparar claves de tipo int
//  retorna 1 si son iguales

int is_equal_int(void * key1, void * key2) {
    if(*(int*)key1 == *(int*)key2) return 1;
    return 0;
}

//  función para comparar claves de tipo int
//  retorna 1 si son key1<key2

int lower_than_int(void * key1, void * key2) {
    if(*(int*)key1 < *(int*)key2) return 1;
    return 0;
}

int higher_than_int(void * key1, void * key2) {
    if(*(int*)key1 > *(int*)key2) return 1;
    return 0;
}

node* createNode(){
  node* n=(node*) malloc(sizeof(node));
  return n;
}

node* copy(node* n){
    node* new=(node*) malloc(sizeof(node));
    *new = *n;
    return new;
}

void reset () {
  printf("\033[0;37m");
}

void yellow () {
  printf("\033[0;33m");
}

void menu(){
    int num = 0;
    List* lugares = create_list();
    while(num!=9){
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
          leer_archivo(lugares);
          printf("Archivo leido correctamente!\n");
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
          menu();
            break;
        }
    }
}

void leer_archivo(List* lugares){
  char archivo[20];
  int num_lineas, cont = 0;
  printf("~Por favor ingrese el archivo que se desea leer: ");
  scanf("%s", archivo);
  printf("~Por favor ingrese el numero de lineas a leer: ");
  scanf("%d", &num_lineas);

  FILE *archivoEntrada = fopen(archivo, "r");
/* Si hubo algun problema con abrir el archivo imprime el siguiente mensaje. */
  if (archivoEntrada == NULL){
    printf("El archivo no se pudo abrir en modo lectura");
    return;
  }
/* Aqui se almacenaran el archivo por linea. */
  char linea[1024];
  char *datos;
  while ((fscanf(archivoEntrada, "%[^\n]s", linea) != EOF) && cont<num_lineas){
    fgetc(archivoEntrada);
    Lugar* lugar = (Lugar *)malloc(sizeof(Lugar));
    datos = strtok(linea, " ");
    strcpy(lugar->identificador, datos);
    strcat(lugar->identificador, ",");
    lugar->posicion[0]=atoi(datos);
    datos = strtok(NULL, " ");
    strcat(lugar->identificador, datos);
    printf("%s\n", lugar->identificador);
    lugar->posicion[1] = atoi(datos);
/* Se agrega en la lista los datos de la variable 'Lugar'. */
    lugar->visited = 0;
    push_back(lugares, lugar);
    cont++;
  }
  if (fclose(archivoEntrada) == EOF){
/* Si hubo algun problema al cerrar el archivo se imprime el siguiente mensaje. */
    printf("El archivo no se pudo cerrar correctamente");
  }
}
