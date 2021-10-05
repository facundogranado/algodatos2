#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
    

    /* Permutes elements of a[izq..der] and returns pivot such that:
     - izq <= pivot <= der
     - elements in a[izq,pivot) all 'go_before' (according to function goes_before) a[pivot]
     - a[pivot] 'goes_before' all the elements in a(pivot,der]
    */
                        int i,j,pivot;
                        pivot=izq;
                        i=izq+1;
                        j=der;

                        while (i<=j){
                            if (goes_before(a[i],a[pivot])){
                                i++;
                            }
                            else if (goes_before(a[pivot],a[j])){
                                j--;
                            }
                            else{
                                swap(a,i,j);
                                j--;
                                i++;
                            }                           
                            
                        }

                        swap(a,pivot,j);
                        pivot=j;

                    return pivot;                    
                        
}

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
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}

