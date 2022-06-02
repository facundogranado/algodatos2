#include <stdio.h>
#include <stdlib.h>
#include "string.h"

int main(void){

    char *cadena,*cadena2;
    cadena="holae";
    cadena2= "holaa";
    string s1= string_create(cadena);
    string s2= string_create(cadena2);
    
    printf ("%i:  \n",string_eq(s1,s2));
    printf ("%i:  \n",string_less(s1,s2));



    return EXIT_SUCCESS;
}