#include "array_helpers.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

unsigned int array_from_file(int array[],unsigned int max_size,const char *filepath) {

    FILE *file=NULL;
    file = fopen(filepath,"r");

    if (file==NULL)
    {
        printf("ARCHIVO NULO.\n");
        exit(EXIT_FAILURE);
    }

    unsigned int size=0u;
    unsigned int res=0u;
    res = fscanf(file,"%u",&size);
    
    if (res != 1)
    {
        printf("ARREGLO INVALIDO\n");
        exit(EXIT_FAILURE);
    }
    

    if (res>max_size)
    {
        printf("EL TAMAÑO PERMITIDO ES %d\n",max_size);
        exit(EXIT_FAILURE);
    }

    for (unsigned int i = 0u; i < size; i++)
    {
        fscanf(file,"%i",&array[i]);     
        
    }
    fclose(file);
    return(size);
    
}



void array_dump(int a[], unsigned int length) {
    //your code here!!!!!
    printf("%u\n",length);
    for (unsigned int i = 0; i < length; i++)
    {
        printf("%i ",a[i]);
    }
    printf("\n");
    
}