#include <stdio.h>
int main(){
    int a, b, c = 3, d = 2;
    a = 8 - 5 * 3 + 2;
    b = 7 % 3 + 4 * 2;
    printf(" valor de a %d\tvalor de b %d\n", a ,b); //  valor de a -5 valor de b 9
    b %= a;
    printf(" valor de b %d\t\n", b); // valor de b 4
    b =(-4) % 3;
    printf(" valor de b %d\t\n", b); // valor de b 2
    if(d = a)
        printf(" d y a son iguales ");
    else 
        printf(" d y a son distintos ");
    return 0; //  d y a son iguales 
} 