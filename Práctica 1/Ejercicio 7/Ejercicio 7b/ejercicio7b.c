#include <stdio.h>

int main(){
    char x;
    /* leer x = 3 */
    scanf("%d", &x);
    printf("%c\n",x);
    scanf("%f", &x);
    printf("%c\n",x);
    scanf(" %c", &x);
    printf("%c",x);
    return 0;
}