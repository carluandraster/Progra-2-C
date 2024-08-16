#include <stdio.h>
int main()
{
    int c = 3, l;
    c = (c * 2 - (l = 4, --l));
    printf(" valor de c %d\t valor de l %d\n", c, l); //  valor de c 3 valor de l 3
    getch();
    return 0;
}