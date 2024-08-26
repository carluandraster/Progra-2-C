// Librerías
#include <stdio.h>
#include <stdlib.h>

// Constantes
#define MAXELEM 100

// Prototipos
void leerVector(int[], unsigned short int *);
void mostrarImpares(unsigned short int, int[]);
void generarVector(int, unsigned short int, int[], int[MAXELEM], unsigned short int *);
void mostrarVector(unsigned short int, int[]);
unsigned short int buscar(int, int, int[]);

int main()
{
    // Declaración y asignación de variables
    int *V, W[MAXELEM], x, k;
    unsigned short int N, M, pos, respuesta;
    char continuar;

    V = (int *)malloc(sizeof(int) * MAXELEM);
    leerVector(V, &N);

    // Menu
    do
    {
        do
        {
            printf("MENU\n1. Mostrar posiciones impares\n2. Mostrar elementos divisibles por un numero\n3. Buscar en el vector\n");
            scanf("%hu", &respuesta);
        } while (respuesta != 1 && respuesta != 2 && respuesta != 3);

        switch (respuesta)
        {
        case 1:
            // Inciso a
            printf("Posiciones impares: ");
            mostrarImpares(N, V);
            break;
        case 2:
            // Inciso b
            printf("Ingrese un numero k: ");
            scanf("%d", &k);
            generarVector(k, N, V, W, &M);
            printf("Numeros divisibles por %d: ", k);
            mostrarVector(M, W);
            break;
        case 3:
            // Inciso c
            printf("Ingrese un numero x: ");
            scanf("%d", &x);
            pos = buscar(x, N, V);
            if (pos > N)
                printf("No se encontro %d en el vector\n", x);
            else
                printf("Se encuentra en la posicion %hu\n", pos);
            break;
        }

        do
        {
            printf("Desea continuar? (S o N)\n");
            scanf(" %c", &continuar);
        } while (continuar != 'S' && continuar != 's' && continuar != 'N' && continuar != 'n');

    } while (continuar == 'S' || continuar == 's');
    free(V);
}

void leerVector(int V[], unsigned short int *N)
{
    unsigned short int i;

    printf("Cuantos numeros desea ingresar? ");
    scanf("%hu", N);

    for (i = 0; i < *N; i++)
    {
        printf("Ingrese la posicion %d: ", i);
        scanf("%d", &V[i]);
    }
}

void mostrarImpares(unsigned short int N, int V[])
{
    unsigned short int i;
    for (i = 1; i < N; i += 2)
        printf("%d\t", V[i]);
    printf("\n");
}

void generarVector(int k, unsigned short int N, int V[], int W[MAXELEM], unsigned short int *M)
{
    unsigned short int i;
    *M = 0;

    for (i = 0; i < N; i++)
        if (V[i] % k == 0)
        {
            W[*M] = V[i];
            ++*M;
        }
}

void mostrarVector(unsigned short int M, int W[])
{
    unsigned short int i;
    for (i = 0; i < M; i++)
        printf("%d\t", W[i]);
    printf("\n");
}

unsigned short int buscar(int x, int N, int V[])
{
    unsigned short int i = 0;
    while (i <= N && V[i] != x)
        i++;
    return i;
}