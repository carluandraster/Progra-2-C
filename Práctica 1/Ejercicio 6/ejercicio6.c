#include <stdio.h>

int main()
{
    int a = 1, b = 2, c = 3, d = 4;
    printf("a) %d\n", a + b * c / d);
    printf("b) %d\n", (a + b) * c % d);
    printf("c) %d\n", d < 65 && 3 == d);
    printf("d) %d\n", a <= b || (3 > a));
    printf("e) %d\n", (a >= d) && (2 - 14 == c + 1));
}