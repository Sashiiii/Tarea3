#include "graph.h"
#include "list.h"
#include "Map.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

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

void color () {
  printf("\033[1;32m");
}

void menu(){
  int x, y;
  float dist;
  int num = 0; //Variable para escoger en el menu
  Map* lugares_por_id = createMap(is_equal_int);
  while(num!=9){
    color();
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
  switch (num){
    case 1:
      leer_archivo(lugares_por_id);
        break;
    case 2:
      printf("Ingrese las id de las entregas las cuales va a calcular la distancia: ");
      scanf("%d", &x);
      scanf("%d", &y);
      dist = distancia(lugares_por_id, x, y);
      printf("La distancia entre la entrega %d y la entrega %d es: ", x, y);
      printf("%.2f metros\n\n", dist);
        break;
    case 3:
      puntos_cercanos(lugares_por_id);
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

void leer_archivo(Map*lugares){
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
    lugar->posicion[0]=atoi(datos);
    datos = strtok(NULL, " ");
    lugar->posicion[1] = atoi(datos);
    
    printf("%d, ", lugar->posicion[0]);
    printf("%d \n",lugar->posicion[1]);
/* Se agrega en la lista los datos de la variable 'Lugar'. */
    lugar->visited = 0;
    lugar->id=cont+1;
    insertMap(lugares,&lugar->id,lugar);
    cont++;
  }
  if (fclose(archivoEntrada) == EOF){
/* Si hubo algun problema al cerrar el archivo se imprime el siguiente mensaje. */
    printf("El archivo no se pudo cerrar correctamente");
  }
  else{
    printf("El archivo se ha leido correctamente!\n");
  }
}

float distancia(Map* lugares, int x, int y){
  Lugar* auxl1, *auxl2;
  auxl1=searchMap(lugares,&x);
  auxl2=searchMap(lugares,&y);
  float distancia;
  float aux;
  aux=pow( (auxl2->posicion[0] - auxl1->posicion[0]) ,2) + pow((auxl2->posicion[1] - auxl1->posicion[1]),2);
  distancia=sqrt(aux);
  return distancia;
}

void puntos_cercanos(Map* lugares_id){
  lugar_d *k;
  lugar_d *lug = (lugar_d *)malloc(sizeof(lugar_d));
  lugar_d *l2 = (lugar_d *)malloc(sizeof(lugar_d));
  Lugar *l;
  Map* lugares_dist = createMap(is_equal_int);
  printf("Ingrese las coordenadas (x e y): ");
  scanf("%d %d", &l2->posicion[0], &l2->posicion[1]);
//  printf("A");  
  l = firstMap(lugares_id);

  while(l!=NULL){
    lug = (lugar_d *)malloc(sizeof(lugar_d));
    lug->posicion[0] = l->posicion[0];
    lug->posicion[1] = l->posicion[1];
    lug->dist = sqrt(pow( (l2->posicion[0] - l->posicion[0]) ,2) + pow((l2->posicion[1] - l->posicion[1]),2));
    insertMap(lugares_dist, &lug->dist, lug);
//    printf("a");          
    l=nextMap(lugares_id);
  }
//  printf("A");
  k = firstMap(lugares_dist);
  printf("Posicion - distancia con el punto\n");
  int cont = 0;
  while (k&&cont<3){
    printf("%d,%d %d ", k->posicion[0], k->posicion[1], k->dist);
    printf("\n");
    k=nextMap(lugares_dist);
    cont++;
  }
/*
  lug = firstMap(lugares_dist);
  printf("posicion: %d,%d distancia: %d\n", lug->posicion[0], lug->posicion[1], lug->dist);
  for(int z = 0; z<2;z++){
    lug = nextMap(lugares_dist);
    printf("posicion: %d%d distancia: %d\n", lug->posicion[0], lug->posicion[1], lug->dist);
  }*/
}