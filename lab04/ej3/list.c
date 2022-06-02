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

list addl(list_elem e,list l){
    list new_list = malloc(sizeof(list));
    new_list->elem=e;
    new_list->next=l;
    l=new_list;
    return l;
}

list destroy(list l){
    list l_temp = l;
    while (l !=NULL){
        l = l->next;
        free(l_temp);
        l_temp = l;
    }
    l=NULL;
    return l;
}

bool is_empty(list l){
    return l==NULL;
}

list_elem head(list l){
    return l->elem;
}

list tail(list l){
    list l_temp = l;
    l = l->next;
    free(l_temp);
    return l;
}

list addr(list_elem e, list l){
    list p = malloc(sizeof(list));
    list q = NULL;
    p->elem=e;
    p->next = NULL;
    if (!is_empty(l)){
        q=l;
        while (q->next != NULL){
            q = q->next;
        }
        q->next=p;
    } else{
        l = p;
    }
    return l;
}

int length(list l){
    list l_temp = l;
    int temp = 0;
    while (l_temp != NULL){
        l_temp = l_temp->next;
        temp++;
    }
    return temp;
}

list concat(list l, list l0){
    list p;
    if(l==NULL){
        p=l0;
    }
    else if(l0==NULL){
            p=l;   
    }else{
        p=l0;
        while (p->next){
            p=p->next;
        }
        p->next=l0;
    }
    return p;
}

list_elem index(list l, int n){
    list l_temp = l;
    list_elem elem;
    int i = 0;

    while (i<n && l_temp!=NULL){
        l_temp = l_temp->next;
        i++;
    }
    elem = l_temp->elem;
    return elem;
}

list take(list l,int n){
    list p;
    for (int i = 0; i < n; i++){
        p=addl(l->elem,p);
    }
    return p;
}

list drop(list l,int n){
     for (int i = 1; i < n; i++){
        l = tail(l);
    }
    return l;
}

list copy_list(list l){
    list copy=empty(),l_temp=l;
    while (l_temp){
        copy=addr(l_temp->elem,copy);
        l_temp=l_temp->next;
    }
    return copy;
}