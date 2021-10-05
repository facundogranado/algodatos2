#include <stdbool.h>
#include "pivot.h"

bool is_pivot(int array[], unsigned int length, unsigned int piv) {
    
    bool res=true;
    
    for (unsigned int  j = 0; j <= piv && res; j++)
    {
        for (unsigned int k = length; k > piv; k--)
        {
             if (array[j]<= array[piv] && array [piv]< array[k])
            {
            res=true;      
            }
            else
            {
            res=false;
            }
      }
    }
    

    return res;
}
