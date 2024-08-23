#include <stdio.h>

int main()
{
    int i;

    // Inciso a
    int v1[4] = {0};
    printf("Inciso a: ");
    for (i = 0; i < 4; i++)
        printf("%d \t", v1[i]); // 0    0   0    0
    printf("\n");

    // Inciso b
    int v2[5] = {6};
    printf("Inciso b: ");
    for (i = 0; i < 5; i++)
        printf("%d \t", v2[i]); // Basura
    printf("\n");

    // Inciso c
    int v3[] = {2, 4, 6};
    printf("Inciso c: ");
    for (i = 0; i < 3; i++)
        printf("%d \t", v3[i]); // 2    4   6
    printf("\n");

    // Inciso d
    char s1[4] = {'h', 'o', 'y'};
    printf("Inciso d: ");
    for (i = 0; i < 4; i++)
        printf("%c \t", s1[i]); // Basura
    printf("\n");

    // Inciso e
    char s2[] = {'h', 'o', 'y'};
    printf("Inciso e: ");
    for (i = 0; i < 3; i++)
        printf("%c \t", s2[i]); // h    o   y
    printf("\n");

    // Inciso f
    char s3[4] = {'h', 'o', 'y', '\0'};
    printf("Inciso f: %s\n", s3); // hoy

    return 0;
}