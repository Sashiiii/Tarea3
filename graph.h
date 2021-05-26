#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

typedef struct{
  void* data;
  int dist_rec;
}node;

typedef struct{
  List* orden_lugares;
  char nombre[50];
}ruta;

typedef struct{
  char identificador[50];
  int posicion[2];
  int visited;
}Lugar;

void leer_archivo(List*);

node* createNode();

node* copy(node* n);

void crear_ruta();

void menu();