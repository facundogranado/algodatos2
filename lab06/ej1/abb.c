#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "abb.h"

struct _s_abb {
    abb_elem elem;
    struct _s_abb *left;
    struct _s_abb *right;
};

static bool elem_eq(abb_elem a, abb_elem b) {

    return a == b;
}


static bool elem_less(abb_elem a, abb_elem b) {

    return a < b;
}

static bool check_greater(abb_elem e, abb tree){
    bool greater=true;
    if (tree!=NULL)
    {
        greater=elem_less(tree->elem,e) && check_greater(e,tree->left) 
                                        && check_greater (e,tree->right);
    }
    return greater;
}

static bool check_smaller(abb_elem e, abb tree){
    bool smaller=true;
    if (tree!=NULL)
    {
        smaller=elem_less(e,tree->elem) && check_smaller(e,tree->left) 
                                        && check_smaller(e,tree->right);
    }
    return smaller;
}


static bool invrep(abb tree) {
    bool valid=false;
    if (tree==NULL)
    {
        valid=true;
    } else{
        valid=check_greater(tree->elem,tree->left)  && check_smaller(tree->elem,tree->right) 
                                                    && invrep(tree->left) 
                                                    && invrep(tree->right);
    }
    
    return valid;
}

abb abb_empty(void) {

    return NULL;
}
abb abb_add(abb tree, abb_elem e) {
    assert(invrep(tree));
    if (tree==NULL)
    {
        tree=malloc(sizeof(struct _s_abb));
        tree->elem=e;
        tree->left=NULL;
        tree->right=NULL;
    }
    else if(e>tree->elem){
        tree->right=abb_add(tree->right,e);
    }
    else if(e<tree->elem){
        tree->left=abb_add(tree->left,e);
    }
    
    assert(invrep(tree) && abb_exists(tree, e));
    return tree;
}

bool abb_is_empty(abb tree) {

    return tree==NULL;
}

bool abb_exists(abb tree, abb_elem e) {
    bool exists=false;
    assert(invrep(tree));
    exists= ((tree!=NULL) && (elem_eq(e,tree->elem))) ||
    (elem_less(tree->elem,e) && abb_exists(tree->right,e)) ||  
    (elem_less(e,tree->elem) && abb_exists(tree->left,e));
    return exists;
}

unsigned int abb_length(abb tree) {
    unsigned int length=0;
    assert(invrep(tree));
    if (tree !=NULL)
    {
        length++;
        length+=abb_length(tree->left);
        length+=abb_length(tree->right);
    }
    assert(invrep(tree) && (abb_is_empty(tree) || length > 0));
    return length;
}

abb del_max(abb tree){
    if (tree->right==NULL)
    {
        tree=tree->left;
    }
    else{
        tree=del_max(tree->right);
    } 
return tree;

}

abb abb_remove(abb tree, abb_elem e) {
    assert(invrep(tree));
    if (tree == NULL) {
        return tree;
    }
    if(tree->elem==e){
        if ((tree->left==NULL) && (tree->right==NULL))
        {
        
        }
        

    }else if(e<tree->elem){
        tree->left=abb_remove(tree->left,e);
    }else if (e>tree->elem){
        tree->right=abb_remove(tree->right,e);
    }
    
            
    assert(invrep(tree) && !abb_exists(tree, e));
    
return tree;
}
abb_elem abb_root(abb tree) {
    abb_elem root;
    assert(invrep(tree) && !abb_is_empty(tree));
    root=tree->elem;
    assert(abb_exists(tree, root));
    return root;
}

abb_elem abb_max(abb tree) {
    abb_elem max_e;
    assert(invrep(tree) && !abb_is_empty(tree));
    while (tree->right !=NULL)
    {
        tree=tree->right;
    }
    max_e=tree->elem;
    
    assert(invrep(tree) && abb_exists(tree, max_e));
    return max_e;
}

abb_elem abb_min(abb tree) {
    abb_elem min_e;
    assert(invrep(tree) && !abb_is_empty(tree));
   while (tree->left !=NULL)
    {
        tree=tree->left;
    }
    min_e=tree->elem;
    assert(invrep(tree) && abb_exists(tree, min_e));
    return min_e;
}

void abb_dump(abb tree) {
    assert(invrep(tree));
    if (tree != NULL) {
        abb_dump(tree->left);
        printf("%d ", tree->elem);
        abb_dump(tree->right);
    }
}

abb abb_destroy(abb tree) {
    assert(invrep(tree));
    if (tree != NULL){
        abb_destroy(tree->left);
        abb_destroy (tree->right);
        free (tree);
        tree = NULL;
    }
    assert(tree == NULL);
    return tree;
}

