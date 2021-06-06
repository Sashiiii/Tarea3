Tarea 3 
--------------------------------------------------
el objetivo de nuestra tarea es programar una solucion al problema del vendedor viajero o TSP, que consiste en que se busca recorrer una serie de localizaciones desde un punto de origen, pasando por cada uno solo una vez y finalmente devolviendose al punto de origen en la menor distancia posible.
--------------------------------------------------
 - ninguna funcion muestra al final el punto de inicio al final, ni la distancia entre el ultimo punto ingresado y este.

 - Funcion de opcion 5 genera numeros aleatorios pero al cambiar visited a 0, se pueden repetir, pero si no se cambia de vuelta el programa crashea, y si se iguala a un nuevo Lugar*, igualmente, el programa deja de funcionar

 - Para la funcion 6 se le deberia pedir al usuario que ingrese el nombre de la ruta que quiere mejorar, para despues pedirle que ingrese un numero para entrar a un switch en que se hace el cambio automatico o manual. se usaria un ciclo y auxiliares para cambiar el orden de la lista, calculando la distancia en el proceso y sumandola en la esttructura ruta*, una vez lista, se compara la distancia final con la inicial, si la nueva es mas rapida, esta reemplazara a la antigua, de lo contrario, la lista nueva es descartada

 - Para la ultima funcion se le pide al usuario que ingrese sus coordenadas para aplicar la funcion puntos_cercanos, para despues hacer una ruta por cada combinacion, con el objetivo de comparar las distancias finales de cada ruta, quedandonos con la que tiene menor distancia recorrida, guardandola con el nombre de "ruta optima", en lugar de usar grafos

--------------------------------------------------
Caracteristicas positivas y a mejorar:
 - Camila Barrera: No se rinde facil, intenta programar ordenadamente, cierra archivos por accidente sin guardar y olvida lo que programa mientras lo hace y se confunde facil
 - Marcelo Galvez: Falta modularizar para ahorrar tiempo y lineas de codigo
