#include "array_helpers.h"
#include "boolean.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


unsigned int array_from_file(int array[],unsigned int max_size,const char *filepath) {

    FILE *file=NULL;
    file = fopen(filepath,"r");

    if (file==NULL)
    {
        printf("ARCHIVO NULO.\n");
        exit(EXIT_FAILURE);
    }

    unsigned int size=0u;
    int res=0;
    res = fscanf(file,"%u",&size);
    
    if (res != 1)
    {
        printf("ARREGLO INVALIDO\n");
        exit(EXIT_FAILURE);
    }
    

    if (size>max_size)
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
    printf("%u\n",length);
    for (unsigned int i = 0; i < length; i++)
    {
        fprintf(stdout,"%i ",a[i]);
    }
    printf("\n");

}

boolean array_is_sorted(int a[], unsigned int max_size){

    boolean res=true;

    for (unsigned int i = 0; i < max_size-1 && res==true; i++)
    {
       
        if (a[i]<= a[i+1])
        {
            res=true;
        }
        else
        {
            res=false;
        }
        
    }
   


return res;

}
