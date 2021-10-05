#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {

                int pivot;

              
                if (der>izq){  
                    pivot=partition(a,izq,der);
                
                    if (pivot==0)
                    {   quick_sort_rec(a,izq,pivot);
                        
                    }else
                    {
                        quick_sort_rec(a,izq,pivot-1); 
                    }
                    
                    quick_sort_rec(a,pivot+1,der);                    
                    
                }

}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0u, (length == 0u) ? 0u : length - 1u);
}

