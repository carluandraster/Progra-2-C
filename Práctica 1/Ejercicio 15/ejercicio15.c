// Librerías
#include <stdio.h>
#include <math.h>

// Prototipos
short int consecutivos(int a, int b, int c);

// Funciones
int main()
{
    int a, b, c;
    printf("Ingrese 3 numeros enteros: ");
    scanf("%d %d %d", &a, &b, &c);
    printf(consecutivos(a, b, c) ? "Son numeros consecutivos" : "No son numeros consecutivos");
}

short int consecutivos(int a, int b, int c)
{
    unsigned int dist1, dist2, dist3;

    // Cálculo de distancias
    dist1 = sqrt(pow(a - b, 2));
    dist2 = sqrt(pow(a - c, 2));
    dist3 = sqrt(pow(b - c, 2));

    return dist1 == 2 && dist2 == 1 && dist3 == 1 || dist1 == 1 && dist2 == 2 && dist3 == 1 || dist1 == 1 && dist2 == 1 && dist3 == 2;
}