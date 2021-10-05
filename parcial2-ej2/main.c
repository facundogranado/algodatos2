#include <stdlib.h>
#include <stdio.h>
#include "truco.h"


int main(void){
    truco_card a=NULL;
    truco_card b=NULL;
    int c,e;
    char z,f;
    prinf("Carta A:\n");
    prinf("ingrese el numero de la carta:\n");
    scanf("%i",&c);
    prinf("ingrese el palo de la carta:\n");
    scanf("%c",&z);
    a=truco_card_new(c,z);
    prinf("Carta B:\n");
    prinf("ingrese el numero de la carta:\n");
    scanf("%i",&e);
    prinf("ingrese el palo de la carta:\n");
    scanf("%c",&f);
    b=truco_card_new(e,f);
    
    if (truco_card_win(a,b))
    {
        prinf("La carta ganadora es la A:\n");
        truco_card_dump(a);
    }else if(truco_card_tie(a,b))
    {
       prinf("La mano esta parda!:\n");
    }
    else{
        prinf("La carta ganadora es la B:\n");
        truco_card_dump(b);
    }

    truco_card_destroy(a);
    truco_card_destroy(b);

return EXIT_SUCCESS;
}