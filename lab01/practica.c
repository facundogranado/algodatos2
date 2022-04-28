#include<stdio.h>
void array_dump(int a[], unsigned int length) {

    printf("%u\n",length);
    for (unsigned int i = 0; i < length; i++)
    {
        printf("%i ",a[i]);
    }
    printf("\n");
}
int maxElemento(int a[],int i){
    int x=0;
    for ( int j = 1; j < i; j++)
    {
        if (a[j]>a[x])
        {
            x=j;
        }
        
    }
    
    return x;
}


void swap(int a[],int i,int j){
    int tmp;
    tmp=a[i];
    a[i]=a[j];
    a[j]=tmp;
}


void ordenacion(int a[],int lengh){
    int x;
    for ( int i = lengh; i > 0; i--)
    {   
        x = maxElemento(a,i);
        swap(a,i,x);
    }
    array_dump(a,lengh);    
    
}





int main(void){
    int tam;
    printf("ingrese tamaño del arreglo\n");
    scanf("%i",&tam);
    int a[tam];
    for (int i = 0; i < tam; i++)
    {
        printf("Ingrese el elemnto\n");
        scanf("%i",&a[i]);
    }
    
    ordenacion(a,tam);




    return 0;
}