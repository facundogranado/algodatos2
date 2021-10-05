#include<stdio.h>
#include <stdbool.h>
#include "odd.h"





int main(){

    int a[]={6,1,4};
    bool r;
    r =is_odd_sorted(a,3);
    printf("%i",r);



    return 0;
}