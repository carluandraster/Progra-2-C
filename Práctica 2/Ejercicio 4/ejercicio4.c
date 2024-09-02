#include <stdio.h>
#include <stdlib.h>

short main()
{
    float *arreglo;
    unsigned short i, N;
    printf("Ingrese la cantidad de numeros que va a ingresar: ");
    scanf("%hu", &N);
    arreglo = (float *)malloc(N * sizeof(float));
    for (i = 0; i < N; i++)
    {
        printf("Ingrese elemento %hu: ", i + 1);
        scanf("%f", &arreglo[i]);
    }
    printf("Numeros positivos: ");
    for (i = 0; i < N; i++)
        if (arreglo[i] > 0)
            printf("\t%2.2f", arreglo[i]);

    free(arreglo);
    return 0;
}