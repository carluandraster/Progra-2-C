#include <stdio.h>
int main(){
 int c=3, d=2;
 c -= d++ * 3;
 printf(" valor de c %d\tvalor de d %d\n", c, d); // valor de c -3 valor de d 3
 return 0;
}