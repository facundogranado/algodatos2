#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#include "truco.h"

struct _s_truco_card {
    int num;
    char p;
};

#define ESPADA "ESPADA"
#define BASTO  "BASTO"
#define ORO    "ORO"
#define COPA   "COPA"

static const char *suit_str(char p) {
    const char *str;
    if (p == 'e') {
        str = ESPADA;
    } else if (p=='b') {
        str = BASTO;
    } else if (p=='o') {
        str = ORO;
    } else if (p=='c') {
        str = COPA;
    }
    return str;
}

static void dump(int num, char suit) {
    printf(" ----------------\n"
           " : %2d           :\n"
           " :              :\n"
           " :              :\n"
           " :    ""%-7s""   :\n"
           " :              :\n"
           " :              :\n"
           " :              :\n"
           " :           %2d :\n"
           " ----------------\n",
           num, suit_str(suit), num);
}

static int card_rank(int num, char suit) {
    int rank=0;

    if (4 <= num && num <= 12) {
        rank=8; }

    else{    
        rank=11; 
    }
    if (num==1 && suit == 'e') {  
        rank=15;   
    } else if (num==1 && suit=='b') {
        rank=14; 
    } else if (num==7 && suit=='e') {
        rank=13; 
    } else if (num==7 && suit=='o') {
        rank=12; 
    }
    return rank;
}

static bool invrep(truco_card c) {
    bool valid_card=false;
    valid_card =((c->num == 1 ||c->num == 2 ||c->num == 3 || c->num ==4 ||c->num ==5 ||c->num ==6||c->num ==7||
    c->num ==10||c->num ==11||c->num ==12)) && ((c->p==ESPADA || c->p==BASTO || c->p==COPA || c->p==ORO )); 
    return valid_card;
}

truco_card truco_card_new(int num, char p) {
    truco_card card=malloc(sizeof(struct _s_truco_card));
    card->num=num;
    card->p=p;
    return card;
}

bool truco_card_win(truco_card a, truco_card b) {
    bool card_a_win=false;
    if (card_rack(a)>card_rack(b))
   {
       card_a_win=true;
   }
    return card_a_win;
}

bool truco_card_tie(truco_card a, truco_card b) {
    bool is_a_tie=false;
    if (card_rack(a)==card_rack(b))
   {
       is_a_tie=true;
   }
    return is_a_tie;
}

void truco_card_dump(truco_card c) {
    printf("La carta es:%i de %c\n",c->num,c->p);
}

truco_card truco_card_destroy(truco_card c) {
    free(c->num);
    free(c->p);
    return c;
}
