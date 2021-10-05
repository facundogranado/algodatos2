#ifndef _LIST_H
#define _LIST_H
#include <stdbool.h>

typedef struct _list * list;
typedef int list_elem;


//crea una lista vacía.
list empty(void);

//agrega el elemento e al comienzo de la lista.
list addl(list c,list_elem e);

//agrega el elemento e al final de la lista.
list addr(list c, list_elem e);

//Devuelve True si c es vacía
bool is_empy(list c);

//Devuelve el primer elemento de la lista
list_elem head(list c);

//Elimina el primer elemento de la lista
list tail(list c);

//Devuelve la cantidad de elementos de la lista
list_elem length(list c);

//- Agrega al final de c todos los elementos de e en el mismo orden.
list concat(list c,list e);

//Devuelve el n-ésimo elemento de la lista
list_elem index(list c, list_elem e);

//Deja en c sólo los primeros n elementos, eliminando el resto 
list take (list c,list_elem e);

//Elimina los primeros n elementos de c
list drop(list c, list_elem e);

//Copia todos los elementos de c en la nueva lista e
list copy_list(list c);

//Libera memoria en caso que sea necesario.
list list_destroy(list c);



#endif
