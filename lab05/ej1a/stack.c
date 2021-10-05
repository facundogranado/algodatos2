#include <stdlib.h>
#include <assert.h>
#include "stack.h"
 
struct  _s_stack
{
    stack_elem elem;
    struct _s_stack* next;
};
bool invrep(stack s){
    s=s;
    return true;
}
stack stack_empty(void){
    return NULL;    
}

stack stack_push(stack s, stack_elem e){
    assert(invrep(s));
    stack p = malloc(sizeof(struct _s_stack));
    p->elem=e;
    p->next=s;
    s=p;
    assert(invrep(s));
    return s;
}

stack stack_pop(stack s){
    assert(invrep(s) && s!=NULL);
    stack p = malloc(sizeof(struct _s_stack));
    p=s;
    s=s->next;
    free(p);
    assert(invrep(s));    
    return s;
}


unsigned int stack_size(stack s){
    unsigned int n=0u;

    while (s!=NULL)
    {
        n++;
        s=s->next;
    }
    return n;
}


stack_elem stack_top(stack s){
    assert(invrep(s) && s!=NULL);
    return s->elem;
}



bool stack_is_empty(stack s){
    assert(invrep(s));
    return s==NULL;
}


stack_elem *stack_to_array(stack s){
    assert(invrep(s));
    stack_elem *array =NULL;
    stack_elem *pointer=NULL;
    unsigned int length = stack_size(s);
    array=calloc(length,sizeof(stack_elem));
    for (unsigned int i = length; i > 0u ; --i)
    {
        pointer=&(s->elem);
        array[i-1u]=*pointer;
        s=s->next;

    }
    assert(invrep(s));
    return array;
}

stack stack_destroy(stack s){
    stack s_temp = s;
    while(s)
    {
        s = s -> next;
        free(s_temp);
        s_temp = s;
    }
    s=NULL;
    return s;
}
