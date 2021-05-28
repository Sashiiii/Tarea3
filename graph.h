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

void distancia_2_pts(Map*);

void leer_archivo(Map*);

node* createNode();

node* copy(node* n);

void crear_ruta();

void menu();