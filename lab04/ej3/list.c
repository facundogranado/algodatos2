#include <stdlib.h>
#include <assert.h>
#include "list.h"


struct _list
{
    list_elem elem;
    struct _list* next;
};


list empty(void){  
    return NULL;
}


list addl(list c,list_elem e){
    list p = (list)malloc(sizeof(struct _list));
    p->elem=e;
    p->next=c;
    c=p;
    return c;
}


list addr(list c, list_elem e){
   list l_temp = (list)malloc(sizeof(struct _list)),l_aux = c;
    l_temp ->elem = e;
    l_temp ->next = NULL;

    if (c == NULL){
        c = l_temp;
    }
    else{
        while (l_aux ->next){ //equivalent to saying (l_aux->next != NULL)
        l_aux = l_aux->next;
        }
    l_aux -> next = l_temp;
    }

    return c;
}


bool is_empy(list c){
    return c==NULL;
}


list_elem head(list c){
    assert(!is_empy(c));
    return c->elem;
}


list tail(list c){
    assert(!is_empy(c));
    list p;
    p=c;
    c=c->next;
    free(p);
    return c;


}


list_elem length(list c){
    list p;
    list_elem n=0u;
    p=c;
    while (p!=NULL)
    {
        n++;
        p=p->next;
    }
    return n;
}


list concat(list c,list e){

    list p;

    if (c==NULL)
    {
        p=e;
    }
    else if(e==NULL){
            p=c;   
    }

    else
    {
        p=c;
        while (p->next)
        {
            p=p->next;
        }

        p->next=e;
        
    }
    
    return p;
}


list_elem index(list c, list_elem e){
    assert(length(c)>e);
    list p=c;
    for (int i = 0; i < e; i++)
    {
        p=p->next;
    }
    return p->elem;
}


list take (list c,list_elem e){
    list p;
    for (int i = 0; i < e; i++)
    {
        p=addl(p,c->elem);
    }

    return p;
}


list drop(list c, list_elem e){
    for (int i = 1; i < e; i++)
    {
        c = tail(c);
    }
    return c;
}


list copy_list(list c){
    list copy=empty(),c_temp=c;
    while (c_temp)
    {
        copy=addr(copy,c_temp->elem);
        c_temp=c_temp->next;
    }
    
    return copy;
}


list list_destroy(list c){
    list l_temp = c;
    while(c){
        c = c -> next;
        free(l_temp);
        l_temp = c;
    }
    c=NULL;
    return c;
}
