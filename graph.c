#include "graph.h"
#include "list.h"
#include "Map.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int contadorRutas=0, numUbi=0;

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

//funcion que copia nodos
node* copy(node* n){
    node* new=(node*) malloc(sizeof(node));
    *new = *n;
    return new;
}

//funcion para inicializar lugar
void* createLugar(){
  Lugar* l = (Lugar*)malloc(sizeof(Lugar));
  l->posicion[0]=0;
  l->posicion[1]=0;
  l->visited=0;
  l->id=0;
  return l;
}

//funcion para mostrar menu y realizar operaciones segun sea ingresado por el usuario
void menu(){
  Lugar *k;
  int x, y; //variables para almacenar input para buscar distancia entre lugares segun id
  float dist;
  int num = 0; //Variable para escoger en el menu
  Map* lugares_por_id = createMap(is_equal_int);
  Map* rutas = createMap(is_equal_int);
  setSortFunction(rutas,lower_than_int); //funcion para que rutas esten ordenadas por distancia en mapa
  ruta* R = (ruta*)malloc(sizeof(ruta)); //auxiliar para mostrar rutas
  Map* lugares_dist;
  Lugar *l2 = (Lugar *)malloc(sizeof(Lugar));
  while(num!=9){
    printf("1.- Importar archivo de coordenadas\n");
    printf("2.- Calcular distancia entre 2 entregas\n");
    printf("3.- Mostrar 3 entregas mas cercanas a las coordenadas ingresadas\n");
    printf("4.- Crear ruta\n");
    printf("5.- Generar ruta aleatoria\n");
    printf("6.- Mejorar ruta\n");
    printf("7.- Mostrar rutas\n");
    printf("8.- Mejor ruta\n");
    printf("9.- Salir\n");
    printf("~Ingrese el numero que corresponda a la operacion que desea realizar: ");
    scanf("%d", &num);
    printf("\n");
  switch (num){
//Caso 1: Lee el archivo 
    case 1:
      leer_archivo(lugares_por_id);
        break;
//Caso 2: Calcula la distancia entre dos puntos de entrega  
    case 2:
      printf("Ingrese las id de las entregas las cuales va a calcular la distancia: ");
      scanf("%d", &x);
      scanf("%d", &y);
      dist = distancia(lugares_por_id, x, y);
      printf("La distancia entre la entrega %d y la entrega %d es: ", x, y);
      printf("%.2f metros\n\n", dist);
        break;
//Caso 3: Muestra las 3 entregas más cercanas a un punto  
    case 3:
      printf("Ingrese las coordenadas (x e y): ");
      scanf("%d %d", &l2->posicion[0], &l2->posicion[1]);
      lugares_dist = puntos_cercanos(lugares_por_id, l2);
      k = firstMap(lugares_dist);
      printf("Posicion - distancia con el punto\n");
      int cont = 0;
      while (k&&cont<3){
        printf("%d,%d %d \n", k->posicion[0], k->posicion[1], k->dist);
        k = nextMap(lugares_dist);
        cont++;
      }
        break;
//Caso 4: El usuario crea una ruta con los puntos de entrega disponibles  
    case 4:
      crear_ruta(lugares_por_id, rutas);
      contadorRutas++;
        break;
//Caso 5: Genera una ruta aleatoria  
    case 5:
      /*crear_ruta_aleatoria (lugares_por_id, rutas);*/
      printf("No funciona :/\n");
        break;
//Caso 6: El usuario puede mejorar una ruta, en caso de que al finalizar la "mejora" se recorra más distancia la ruta queda como estaba inicialmente  
    case 6:
      printf("No se logro :/\n");
        break;
//Caso 7: Se muestran todas las rutas guardadas dentro del programa  
    case 7:
      printf("Mostrando rutas guardadas de mejor a peor:\n\n");
      R = firstMap(rutas);
      if(contadorRutas == 0){
        printf("No hay rutas guardadas actualmente\n");
        break;
      }
      
      for(int contR=0;contR<contadorRutas;contR++)
      {
        k = firstList(R->orden_lugares);
        printf("%s: \n", R->nombre);
        for(int z=0;z<numUbi;z++){  
          printf("%d ", k->id);
          k = nextList(R->orden_lugares);
        }
        printf("\nDistancia del recorrido:  %ld\n", R->dist);
        R = nextMap(rutas);
        printf("\n\n");
      }  
      
        break;
//Caso 8: Se crea la ruta más optima automaticamente  
    case 8:
     crear_rutaOptima(lugares_por_id, rutas);
      contadorRutas++;
        break;
//Caso 9: Se cierra el programa  
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
  numUbi=num_lineas+1;
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
    Lugar* lugar = createLugar();
    datos = strtok(linea, " ");
    lugar->posicion[0]=atoi(datos);
    datos = strtok(NULL, " ");
    lugar->posicion[1] = atoi(datos);
    
    printf("%d, ", lugar->posicion[0]);
    printf("%d \n",lugar->posicion[1]);
/* Se agrega en la lista los datos de la variable 'Lugar'. */
    lugar->visited = 0;
    lugar->id = cont+1;
    insertMap(lugares,&lugar->id,lugar);
    cont++;
  }
  if (fclose(archivoEntrada) == EOF){
/* Si hubo algun problema al cerrar el archivo se imprime el siguiente mensaje. */
    printf("El archivo no se pudo cerrar correctamente\n");
  }
  else{
    printf("El archivo se ha leido correctamente!\n");
  }
}

/* Funcion para calcular distancia entre dos lugares por su id*/
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

/* Funcion que genera mapa con lugares ordenados por cercania */
Map* puntos_cercanos(Map* lugares_id, Lugar* l2){
  Lugar *lug = createLugar();
  Lugar *l;
  Map* lugares_dist = createMap(is_equal_int);
  setSortFunction(lugares_dist,lower_than_int);
  l = firstMap(lugares_id);

  while(l!=NULL ){
    if(lug->visited != 1){
      lug = (Lugar *)malloc(sizeof(Lugar));
      lug->id = l->id;
      lug->posicion[0] = l->posicion[0];
      lug->posicion[1] = l->posicion[1];
      lug->dist = sqrt(pow( (l2->posicion[0] - l->posicion[0]) ,2) + pow((l2->posicion[1] - l->posicion[1]),2));
      if(lug->dist != 0){
        insertMap(lugares_dist, &lug->dist, lug);
      }
      l=nextMap(lugares_id);
    }
    
  }
  return lugares_dist;
}


void crear_ruta(Map* lugares_id, Map* rutas){
  Lugar* aux,*k, *inicio = (Lugar*)malloc(sizeof(Lugar)), *destino;
  ruta* Ruta = (ruta*)malloc(sizeof(ruta));
  Ruta->orden_lugares = createList();
  Ruta->dist = 0;
  Map* lugares_dist = createMap(is_equal_int);

  int id, dist, searchId;
  setSortFunction(lugares_dist,lower_than_int);
  printf("Ingrese las coordenadas iniciales (x e y): ");
  scanf("%d %d", &inicio->posicion[0], &inicio->posicion[1]);
  inicio->dist = 0;
  inicio->visited = 0;
  inicio->id = 0;
  pushBack(Ruta->orden_lugares,inicio);
  lugares_dist = puntos_cercanos(lugares_id, inicio);

  while(k){
    k = firstMap(lugares_dist);
    printf("id - posicion - distancia con el punto anterior ingresado\n");
    while(k){
      if(k->visited!=1){
        printf("%d - %d,%d - %d\n",k->id, k->posicion[0], k->posicion[1],k->dist);  
      }    
      k = nextMap(lugares_dist);
    }
    do {
      printf("ingrese id de posicion a la que desea continuar: ");
      scanf("%d", &searchId);
      destino = firstMap(lugares_dist); 
      while(destino->id!=searchId){
        destino = nextMap(lugares_dist);
      }
    }while(destino->visited==1);
    Ruta->dist+= destino->dist;
    eraseMap(lugares_dist, &destino->dist);
    
    destino->visited = 1;
    
    pushBack(Ruta->orden_lugares, destino);
    lugares_dist = puntos_cercanos(lugares_dist, destino);
    k = firstMap(lugares_dist);
  }
 
  printf("ingrese nombre para la ruta ingresada: \n");
  scanf("%s", &Ruta->nombre);
  insertMap(rutas, &Ruta->dist ,Ruta);
 
}


void crear_rutaOptima(Map* lugares_id, Map* rutas){
  Lugar* aux,*k, *inicio = (Lugar*)malloc(sizeof(Lugar)), *destino;
  ruta* Ruta = (ruta*)malloc(sizeof(ruta));
  Ruta->orden_lugares = createList();
  Ruta->dist = 0;
  Map* lugares_dist = createMap(is_equal_int);

  int id, dist, searchId;
  setSortFunction(lugares_dist,lower_than_int);
  printf("Ingrese las coordenadas iniciales (x e y): ");
  scanf("%d %d", &inicio->posicion[0], &inicio->posicion[1]);
  inicio->dist = 0;
  inicio->visited = 0;
  inicio->id = 0;
  pushBack(Ruta->orden_lugares,inicio);
  lugares_dist = puntos_cercanos(lugares_id, inicio);

  while(k){
    k = firstMap(lugares_dist);
    printf("id - posicion - distancia con el punto anterior ingresado\n");
    while(k){
      if(k->visited!=1){
        printf("%d - %d,%d - %d\n",k->id, k->posicion[0], k->posicion[1],k->dist);  
      }    
      k = nextMap(lugares_dist);
    }
    
    destino = firstMap(lugares_dist); 
      
    Ruta->dist+= destino->dist;
    eraseMap(lugares_dist, &destino->dist);
    
    destino->visited = 1;
    
    pushBack(Ruta->orden_lugares, destino);
    lugares_dist = puntos_cercanos(lugares_dist, destino);

    k = firstMap(lugares_dist);
  }
 
  printf("ingrese nombre para la ruta ingresada: \n");
  scanf("%s", &Ruta->nombre);
  insertMap(rutas, &Ruta->dist ,Ruta);
 
}

/*
void crear_ruta_aleatoria (Map* lugares_id, Map* rutas){
  Lugar* aux,*k, *inicio = (Lugar*)malloc(sizeof(Lugar)), *destino;
  ruta* Ruta = (ruta*)malloc(sizeof(ruta));
  Ruta->orden_lugares = createList();
  Ruta->dist = 0;
  Map* lugares_dist = createMap(is_equal_int);
  int id, dist, searchId, cont=0;
  setSortFunction(lugares_dist,lower_than_int);

  printf("Ingrese las coordenadas iniciales (x e y): ");
  scanf("%d %d", &inicio->posicion[0], &inicio->posicion[1]);

  inicio->dist = 0;
  inicio->visited = 0;
  inicio->id = 0;
  pushBack(Ruta->orden_lugares,inicio);
  lugares_dist = puntos_cercanos(lugares_id, inicio);

  while(k){
    k = firstMap(lugares_dist);
    printf("id - posicion - distancia con el punto anterior ingresado\n");
    while(k){
      if(k->visited!=1){
        printf("%d - %d,%d - %d\n",k->id, k->posicion[0], k->posicion[1],k->dist);  
      }    
      k = nextMap(lugares_dist);
    }
    do {
      searchId = rand()%numUbi;
      destino = firstMap(lugares_dist); 
      while(destino->id!=searchId){
        destino = nextMap(lugares_dist);
      }
    }while(destino->visited==1);

    Ruta->dist += destino->dist;
    eraseMap(lugares_dist, &destino->dist);
    
    destino->visited = 1;
    
    pushBack(Ruta->orden_lugares, destino);
    lugares_dist = puntos_cercanos(lugares_dist, destino);

    k = firstMap(lugares_dist);
  }
  printf("ingrese nombre para la ruta ingresada: ");
  scanf("%s", &Ruta->nombre);
  insertMap(rutas, &Ruta->dist ,Ruta);
}
*/