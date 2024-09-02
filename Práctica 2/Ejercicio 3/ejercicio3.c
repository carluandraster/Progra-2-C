#include <stdio.h>
#include <stdlib.h>

void reservarMemoriayCargar(int **);

short main()
{
    int *var1, *var2, *var3;
    reservarMemoriayCargar(&var1);
    reservarMemoriayCargar(&var2);
    reservarMemoriayCargar(&var3);

    printf("Sumatoria de los enteros: %d\n", *var1 + *var2 + *var3);
    printf("Productoria de los enteros: %d", *var1 * *var2 * *var3);

    free(var1);
    free(var2);
    free(var3);

    return 0;
}

void reservarMemoriayCargar(int **var)
{
    *var = (int *)malloc(sizeof(int));
    printf("Ingrese un entero: ");
    scanf("%d", *var);
}