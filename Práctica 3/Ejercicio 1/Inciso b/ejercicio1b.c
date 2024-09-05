#include <stdio.h>

void division (int *, int, int *);

short int main(){
    int a,b,c;

    printf("Ingrese dividendo: ");
    scanf("%d",&a);
    do
    {
        printf("Ingrese divisor: ");
        scanf("%d",&b);
    } while (b == 0);
    
    c = 0;
    division(&a,b,&c);
    printf("Cociente: %d\n",c);
    printf("Resto: %u\n",a);
    return 0;
}

void division (int *a, int b, int *c){
    if (*a < 0){
        *a = -*a;
        division(a,-b,c);
    }
    else
        if (*a >= b){
            if (b>0)
            {
                *a -= b;
                ++ *c;
            }
            else
            {
                *a += b;
                -- *c;
            }
            division(a,b,c);
        }    
}