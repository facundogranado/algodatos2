#include <assert.h>
#include "dict.h"
#include "key_value.h"
#include <stdlib.h>

struct _node_t {
    dict_t left;
    dict_t right;
    key_t key;
    value_t value;
};

static bool invrep(dict_t d) {
    /* needs implementation */
    return true;
}

dict_t dict_empty(void) {
    dict_t dict = NULL;
    /* needs implementation */
    return dict;
}

dict_t dict_add(dict_t dict, key_t word, value_t def) {
    
    
    if (dict==NULL)
    {
       dict=malloc(sizeof(struct _node_t));
       dict->key=word;
       dict->value=def;
       dict->left=NULL;
       dict->right=NULL;

    }
    else if(key_less(word,dict->key)){
        dict->left=dict_add(dict->left,word,def);
    }   
    else if(key_less(dict->key,word)){
        dict->right=dict_add(dict->right,word,def);
    }
    else{
        dict->value=value_destroy(dict->value);
        dict->value=def;
    }
    return dict;
}

value_t dict_search(dict_t dict, key_t word) {
    key_t def=NULL;
    if (dict!=NULL)
    {
        if(key_eq(dict->key,word)){
            def=dict->value;
        }
        else if(key_less(word,dict->key)){
            def=dict_search(dict->left,word);
        }
        else if(key_less(word,dict->key)){
            def=dict_search(dict->right,word);
        }
    }
    
    return def;
}

bool dict_exists(dict_t dict, key_t word) {
    bool exists=false;
    if(dict!=NULL){
        exists = key_eq(dict->key,word) || dict_exists(dict->left,word) || dict_exists(dict->right,word);
    }
    return exists;
}

unsigned int dict_length(dict_t dict) {
    unsigned int length=0;
    if (dict !=NULL)
    {
        length++;
        length+=dict_length(dict->left);
        length+=dict_length(dict->right);
    }
    return length;
}

static dict_t dict_min(dict_t dict){
    dict_t min = NULL;
    if(dict->left!=NULL){
        min = dict_min(dict->left);
    }
    else{
        min = dict;
    }
    return min;
} 

dict_t dict_remove(dict_t dict, key_t word) {
    if(key_eq(dict->key,word)){
         if ((dict->left==NULL) && (dict->right==NULL)) {
            dict->key=key_destroy(dict->key);
            dict->value=value_destroy(dict->value);
            free(dict);
            dict=NULL;
        }
        else if(dict->left==NULL){
            dict_t aux=dict;
            dict=dict->right;
            aux->key=key_destroy(aux->key);
            aux->value=value_destroy(aux->value);
            free(aux);
        }
        else if(dict->right==NULL){
            dict_t aux=dict;
            dict=dict->left;
            aux->key=key_destroy(aux->key);
            aux->value=value_destroy(aux->value);
            free(aux);
        }
        else{
           dict_t aux= dict_min(dict->right);
           dict->key=key_destroy(dict->key);
           dict->value=value_destroy(dict->value);
           dict->key=aux->key;
           dict->value=aux->value;
           dict->right=dict_remove(dict->right,aux->key);
        } 
    } 
    else { 
         if (key_less(word,dict->key))
        {
            dict->left=dict_remove(dict->left,word);
        }
        else if(key_less(dict->key,word)){
            dict->right=dict_remove(dict->right,word);
        }
       
    }
       
    return dict;
}

dict_t dict_remove_all(dict_t dict) {
     if (dict != NULL){
         dict->key = key_destroy(dict->key);
        dict->value = value_destroy(dict->value);
        dict->left = dict_remove_all(dict->left);
        dict->right = dict_remove_all(dict->right);
        free (dict);
        dict = NULL;
    }
    return dict;
}

void dict_dump(dict_t dict, FILE *file) {
     if (dict != NULL) {
        dict_dump(dict->left,file);
        key_dump(dict->key,file);
        fprintf(file,":");
        value_dump(dict->value,file);
        fprintf(file,"\n");
        dict_dump(dict->right,file);
    }
}

dict_t dict_destroy(dict_t dict) {
     if (dict != NULL){
        dict_destroy(dict->left);
        dict_destroy (dict->right);
        free(dict);
        dict = NULL;
    }
    return dict;
}

