#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
int main(void){

    stack p = stack_empty();

    printf("%u\n",stack_size(p));

    return (EXIT_SUCCESS);
}