#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "Map.h"

typedef struct{
  List* orden_lugares;
  char nombre[50];
  long dist;
}ruta;

typedef struct{
  void* data;
  int dist_rec;
}node;

typedef struct{
  int posicion[2];
  int dist;
  int visited;
  int id;
}Lugar;

void crear_rutaOptima(Map* , Map*);

void crear_ruta(Map*, Map*);

Map* puntos_cercanos(Map* lugares_id, Lugar* l2);

float distancia(Map*, int, int);

void leer_archivo(Map*);

node* createNode();

node* copy(node* n);

void crear_ruta();

void menu();

