#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
int main(void){

    stack p = stack_empty();
    
    p = stack_push(p,1);
    p = stack_push(p,4);
    p = stack_push(p,5);

    printf("%u,%d",stack_size(p),stack_top(p));

    return (EXIT_SUCCESS);
}