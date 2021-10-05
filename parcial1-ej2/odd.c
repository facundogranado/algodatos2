#include <stdbool.h>
#include <stdio.h>

#include "odd.h"

bool is_odd_sorted(int array[], unsigned int length) {
    
    bool res=true;
    
            for (unsigned int i = 1u; i < length-1 && res; i=i+2)
            {
               if (array[i]<=array[i+2])
               {
                
               }
               else
               {
                   res=false;
               }
               
            }
        


    return res;
}

