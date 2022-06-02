#include <stdlib.h>
#include <assert.h>
#include "stack.h"
 
struct _s_stack{
    stack_elem elem;
    struct _s_stack* next;
};

stack stack_empty(){
    return NULL;
}

stack stack_push(stack s, stack_elem e){
    stack p = malloc(sizeof(struct _s_stack));
    p->elem = e;
    p->next = s;
    s = p;
    return s;
}

stack stack_pop(stack s){
    stack p = s;
    s=s->next;
    free(p);
    return s;
}

unsigned int stack_size(stack s){
    stack p = s;
    unsigned int cont = 0u;
    while (p!=NULL){
        cont++;
        p=p->next;
    }
    return cont;
    
}

stack_elem stack_top(stack s){
    assert(!stack_is_empty(s));
    return s->elem;
}

bool stack_is_empty(stack s){
    return s == NULL;
}

stack_elem *stack_to_array(stack s){
    stack p = s;
    unsigned int length = stack_size(s);
    stack_elem *array = NULL;
    stack_elem elem;
    if (!stack_is_empty(s)){
        array = calloc(length,sizeof(stack_elem));
        for(unsigned int i = length;i>0;i--){
            elem = stack_top(s);
            array[i-1] = elem;
            s = s->next;
        }
        s = p;
    }
    return array; 
}

stack stack_destroy(stack s){
    stack p = s;
    while (s !=NULL){
        s = s->next;
        free(p);
        p = s;
    }
    p=NULL;
    return p;

}