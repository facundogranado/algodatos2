#include <stdio.h>

void absolute(int x, int *y) {
    
    if (x>=*y)
    {
        *y=x;
    }
    else
    {
        *y=-x;
    }
    
}

int main(void) {

    int b=0;
    int a=-98;
    absolute(a,&b);
    printf("%d\n",b);
    return 0;
}

