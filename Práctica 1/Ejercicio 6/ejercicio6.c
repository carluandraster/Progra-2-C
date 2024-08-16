#include <stdio.h>

int main()
{
    int a = 1, b = 2, c = 3, d = 4;
    printf("a) %d", a + b * c / d);
    printf("b) %d", (a + b) * c % d);
    printf("c) %d", d < 65 && 3 == d);
    printf("d) %d", a <= b || (3 > a));
    printf("e) %d", (a >= d) && (2 - 14 == c + 1));
    printf("f) %d", a > b || a < c &&a = c || a >= b);
}