#include <stdio.h>
#include <stdbool.h>
#include "pivot.h"

int main(){
    int a[4]={1,1,6,5};
    bool r;
    r = is_pivot(a,4,1);
    printf("%i",r);
    return 0;
}