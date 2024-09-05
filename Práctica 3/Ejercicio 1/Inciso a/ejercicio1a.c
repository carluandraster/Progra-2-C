#include <stdio.h>

int producto (int, int);

short int main(){
    int a,b;
    printf("Ingrese un par de numeros enteros: ");
    scanf("%d %d",&a,&b);
    printf("%d x %d = %d",a,b,producto(a,b));
    return 0;
}

int producto (int a, int b){
    if (a== 0 || b == 0)
        return 0;
    else
        if (b<0)
            return -producto(a,-b);
        else
            return a+producto(a,b-1);
}