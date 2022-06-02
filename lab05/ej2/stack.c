#include <stdlib.h>
#include <assert.h>
#include "stack.h"

struct _s_stack {
    stack_elem *elems;      // Arreglo de elementos
    unsigned int size;      // Cantidad de elementos en la pila
    unsigned int capacity;  // Capacidad actual del arreglo elems
};

stack stack_empty(){
    return NULL;
}

stack stack_push(stack s, stack_elem e){
    if(s==NULL){
        s = malloc(sizeof(struct _s_stack));
        s->capacity=1u;
        s->size=0u;
        s->elems=calloc(s->capacity,sizeof(stack_elem));
    }else if(s->capacity==s->size){
        s->capacity *=2;
        s->elems= realloc(s->elems,(s->capacity)*sizeof(struct _s_stack));
    }
    s->elems[s->size]=e;
    s->size++;
    return s;
}

stack stack_pop(stack s){
    s->size--;
    return s;
}

unsigned int stack_size(stack s){
    return s==NULL?0:s->size;
}

stack_elem stack_top(stack s){
    return s->elems[s->size-1];
}

bool stack_is_empty(stack s){
    return s==NULL;
}

stack_elem *stack_to_array(stack s){
    stack_elem *array = NULL;
    if(s!=NULL){
        array = s->elems;
    }
    return array;
}

stack stack_destroy(stack s){
    free(s);
    return s;
}