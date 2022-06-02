#include "pair.h"
#include <stdlib.h>
#include <stdio.h>

pair_t pair_new(int x, int y){
    pair_t new_pair={x,y};
    return new_pair;
}


int first(pair_t p){
    return p.fst;
}

int second(pair_t p){
    return p.snd;
}

pair_t pair_swapped(pair_t p){
    return pair_new(p.snd,p.fst);
}

pair_t pair_destroy(pair_t p){
    return p;
}



