#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "Map.h"

typedef struct{
  void* data;
  int dist_rec;
}node;

typedef struct{
  List* orden_lugares;
  char nombre[50];
}ruta;

typedef struct{
  int id;
  int posicion[2];
  int visited;
}Lugar;

typedef struct{
  int posicion[2];
  int dist;
  int visited;
}lugar_d;

void puntos_cercanos(Map*);

float distancia(Map*, int, int);

void leer_archivo(Map*);

node* createNode();

node* copy(node* n);

void crear_ruta();

void menu();