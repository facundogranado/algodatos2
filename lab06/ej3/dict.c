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
static bool check_greater(key_t key, dict_t d){
    bool value = true;
    if(d != NULL){
        value =string_less(d->key,key) 
        && check_greater(key,d->left)
        && check_greater(key,d->right);
    }
    return value;
}

static bool check_smaller(key_t key,dict_t d){
    bool value = true;
    if(d != NULL){
        value = string_less(key,d->key)
        && check_smaller(key,d->left)
        && check_smaller(key,d->right);
    }
    return value;
}
static bool invrep(dict_t d) {
    bool valid = false;
    if(d == NULL){
        valid = true;
    }else{
        valid = check_greater(d->key,d->left) 
        && check_smaller(d->key,d->right)
        && invrep(d->left)
        && invrep(d->right);
    }
    return valid;
}

dict_t dict_empty(void) {
    dict_t dict = NULL;
    assert(invrep(dict) && dict_length(dict)==0);
    return dict;
}

dict_t dict_add(dict_t dict, key_t word, value_t def) {
    assert(invrep(dict));
    if(dict == NULL){
        dict = malloc(sizeof(struct _node_t));
        dict->key=word;
        dict->value=def;
        dict->left=NULL;
        dict->right=NULL;
    }else if(string_eq(dict->key,word)){
        dict->value=def;
    }else if(string_less(word,dict->key)){
        dict->left=dict_add(dict->left,word,def);
    }else if(string_less(dict->key,word)){
        dict->right=dict_add(dict->right,word,def);
    }
    assert(invrep(dict) && string_eq(def,dict_search(dict,word)));
    return dict;
}

value_t dict_search(dict_t dict, key_t word) {
    assert(invrep(dict));

    key_t def=NULL;
    if(dict !=NULL){
        if(string_eq(dict->key,word)){
            def = dict->value;
        }else if(string_less(word,dict->key)){
            def=dict_search(dict->left,word);
        }else if(string_less(dict->key,word)){
            def=dict_search(dict->right,word);
        }
    }
    assert((def!=NULL) == (dict_exists(dict,word)));
    return def;
}

bool dict_exists(dict_t dict, key_t word) {
    assert(invrep(dict));
    bool exist=false;
    if(dict!=NULL){
        if(string_eq(dict->key,word)){
            exist=true;
        }else if(string_less(word,dict->key)){
            exist = dict_exists(dict->left,word);
        }else if(string_less(dict->key,word)){
            exist=dict_exists(dict->right,word);
        }
    }
    assert(invrep(dict));
    return exist;
}

unsigned int dict_length(dict_t dict) {
    unsigned int length=0;
    assert(invrep(dict));
    if(dict!=NULL){
        length++;
        length += dict_length(dict->left);
        length += dict_length(dict->right);
    }

    return length;
}
key_t dict_max(dict_t d) {
    key_t max_d;
    assert(invrep(d));
    while(d->right!=NULL){
        d = d->right;
    }
    max_d = d->key;
    return max_d;
}

dict_t dict_remove(dict_t dict, key_t word) {
     assert(invrep(dict));
    if(dict != NULL){
        if(string_eq(dict->key,word)){
            if ((dict->left == NULL) && (dict->right == NULL)){
                free(dict);
                dict=NULL;
            }else if(dict->left == NULL && dict->right != NULL){
                dict=dict->right;

            }else if(dict->left != NULL && dict->right == NULL){
                dict = dict->left;
     
            }else{
                dict->key=dict_max(dict->left);
                dict->left=dict_remove(dict->left,dict_max(dict->left));
            }
            
        }else if(string_less(word,dict->key)){
            dict->left=dict_remove(dict->left,word);
        } else if(string_less(dict->key,word)){
            dict->right=dict_remove(dict->right,word);
        }
    }
    assert(invrep(dict) && !dict_exists(dict, word));
    return dict;
}

dict_t dict_remove_all(dict_t dict) {
     if (dict != NULL){
        dict->key = string_destroy(dict->key);
        dict->value = string_destroy(dict->value);
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
        dict_remove_all(dict);
        dict = NULL;
    }
    return dict;
}

