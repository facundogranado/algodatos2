/*
  @file sort.c
  @brief sort functions implementation
*/

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "helpers.h"
#include "sort.h"
#include "player.h"

bool goes_before(player_t x, player_t y){
    return(x->rank<=y->rank);;
}

bool array_is_sorted(player_t atp[], unsigned int length) {
    unsigned int i = 1u;
    while (i < length && goes_before(atp[i - 1u], atp[i])) {
        i++;
    }
    return (i == length);
}
void swap(player_t *i, player_t *j){
    player_t temp;
    
    temp = *i;
    *i = *j;
    *j = temp; 
}
static void insert(player_t a[],int i) {
    
    for (int j = i; j>0 && goes_before(a[j],a[j-1]); j--){
        swap(&a[j],&a[j-1]);
    }
    
}

void insertion_sort(player_t a[], unsigned int length){
    for (unsigned int i = 1u; i < length; ++i){
         insert(a, i);
        assert(array_is_sorted(a,i));
    }
}

void sort(player_t a[], unsigned int length) {
    insertion_sort(a,length);
}

