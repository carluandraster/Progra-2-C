#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TJugador
{
    char *nombre;
    short int edad;
    char estado;
    struct TJugador *sig;
} TJugador;
typedef struct TEquipo
{
    char *nombre;
    int puntaje;
    struct TEquipo *sig;
    TJugador *jugadores;
} TEquipo;
typedef TEquipo *TLista;

void addnodo(TLista *L, TEquipo e);
void addnodito(TLista L, TJugador e);
void cargarLista(TLista *L);
void listarA(TLista L, TLista *M, char K, int *cantJugListados, char *maxEquipo);
void listarB(TLista L, TLista *N, int X);
int verifica(TLista L, char *E, int P);
void eliminar(TLista *L);
void mostrarLista(TLista L);

int main()
{
    TLista L, M, N;
    int X, cantJugListados, P;
    char K, *maxEquipo, *E;

    cargarLista(&L);
    printf("Ingrese una letra K: ");
    scanf(" %c", &K);
    listarA(L, &M, K, &cantJugListados, maxEquipo);
    mostrarLista(M);
    do
    {
        printf("Ingrese un puntaje X: ");
        scanf("%d", &X);
    } while (X > 0);
    listarB(L, &N, X);
    mostrarLista(N);
    printf("Ingrese un equipo: ");
    scanf("%s", E);
    printf("Ingrese puntaje: ");
    scanf("%d", &P);
    printf(verifica(L, E, P) ? "El equipo %s tiene %d puntos\n", E, P : "El equipo %s no tiene %d puntos\n", E, P);
    eliminar(&L);
    mostrarLista(L);

    return 0;
}
