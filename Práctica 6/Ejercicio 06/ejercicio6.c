#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXCAR 20

typedef struct TJugador
{
    char nombre[MAXCAR];
    short int edad;
    char estado;
    struct TJugador *sig;
} TJugador;
typedef struct TEquipo
{
    char nombre[MAXCAR];
    int puntaje;
    struct TEquipo *sig;
    TJugador *jugadores;
} TEquipo;
typedef TEquipo *TLista;

void addnodo(TLista *L, TEquipo e, TLista *ult);
void addnodito(TLista L, TJugador e, TJugador **ult);
void cargarListaEquipos(TLista *L);
void listarA(TLista L, char K, int *cantJugListados, char *maxEquipo);
void listarB(TLista L, int X);
int verifica(TLista L, char *E, int P);
void eliminar(TLista *L);
void mostrarLista(TLista L);

int main()
{
    TLista L = NULL;
    int X, cantJugListados = 0, P;
    char K, *maxEquipo, *E;

    cargarListaEquipos(&L);
    printf("Ingrese una letra K: ");
    scanf(" %c", &K);
    listarA(L, K, &cantJugListados, maxEquipo);
    printf("Cantidad de jugadores listados: %d\n", cantJugListados);
    printf("Equipo con mas jugadores que empiezan por la letra solicitada: %s\n", maxEquipo);
    do
    {
        printf("Ingrese un puntaje X: ");
        scanf("%d", &X);
    } while (X > 0);
    listarB(L, X);
    printf("Ingrese un equipo: ");
    scanf("%s", E);
    printf("Ingrese puntaje: ");
    scanf("%d", &P);
    if (verifica(L, E, P))
        printf("El equipo %s tiene %d puntos\n", E, P);
    else
        printf("El equipo %s no tiene %d puntos\n", E, P);
    eliminar(&L);
    mostrarLista(L);

    return 0;
}

// Agrega un nodo a la lista principal
void addnodo(TLista *L, TEquipo e, TLista *ult)
{
    TLista aux = *ult, ant, nuevo;
    nuevo = (TLista)malloc(sizeof(TEquipo));
    *nuevo = e;
    nuevo->sig = NULL;
    if (*L == NULL)
        *L = *ult = nuevo;
    else
    {
        (*ult)->sig = nuevo;
        *ult = (*ult)->sig;
    }
}

// Agrega un nodo a una sublista
void addnodito(TLista L, TJugador e, TJugador **ult)
{
    TJugador *aux, *nuevo;
    aux = L->jugadores;
    nuevo = (TJugador *)malloc(sizeof(TJugador));
    *nuevo = e;
    nuevo->sig = NULL;
    if (aux == NULL)
        L->jugadores = *ult = nuevo;
    else
    {
        (*ult)->sig = nuevo;
        *ult = (*ult)->sig;
    }
}

// Inicializa lista de equipos
void cargarListaEquipos(TLista *L)
{
    TLista ult;
    TEquipo equipo;
    TJugador jugador, *Ult;
    FILE *archivo;
    int i, N;

    archivo = fopen("equipos.txt", "rt");
    if (archivo == NULL)
        printf("No se pudo abrir el archivo.\n");
    else
    {
        while (fscanf(archivo, "%19s %d %d\n", equipo.nombre, &equipo.puntaje, &N) == 3)
        {
            equipo.jugadores = NULL;  // Inicializar la sublista de jugadores como vacía
            addnodo(L, equipo, &ult); // Agregar el equipo a la lista y obtener el último nodo

            for (i = 0; i < N; i++)
            {
                fscanf(archivo, "%19s %d %c\n", jugador.nombre, &jugador.edad, &jugador.estado);
                addnodito(ult, jugador, &Ult); // Agregar el jugador a la sublista del equipo
            }
        }
        fclose(archivo);
    }
}

// Lista para todos los clubes los jugadores cuyo nombre comienza con la letra K
void listarA(TLista L, char K, int *cantJugListados, char *maxEquipo)
{
    TLista aux = L;
    TJugador *jugador;
    int maxJugList = -1, contador;

    while (aux != NULL)
    {
        contador = 0;
        printf("%s\n", aux->nombre);
        jugador = aux->jugadores;
        while (jugador != NULL)
        {
            if (jugador->nombre[0] == K)
            {
                contador++;
                printf("%s\n", jugador->nombre);
            }
            jugador = jugador->sig;
        }
        printf("\n");
        *cantJugListados += contador;
        if (contador > maxJugList)
        {
            maxJugList = contador;
            strcpy(maxEquipo, aux->nombre);
        }
        aux = aux->sig;
    }
}

// Lista los clubes que tienen un mínimo de X (dato) puntos junto con todos sus jugadores,
// mostrando edad promedio de cada equipo
void listarB(TLista L, int X)
{
    int contador, acumulador;
    TLista aux = L;
    TJugador *jugador;

    while (aux != NULL && aux->puntaje >= X)
    {
        contador = acumulador = 0;
        printf("%s\n", aux->nombre);
        jugador = aux->jugadores;
        while (jugador != NULL)
        {
            printf("%s\n", jugador->nombre);
            contador++;
            acumulador += jugador->edad;
        }
        if (contador)
            printf("Edad promedio: %5.2f\n\n", (float)acumulador / contador);
        else
            printf("El equipo no registro jugadores\n\n");
    }
}

// Verifica si el equipo E tiene P puntos
int verifica(TLista L, char *E, int P)
{
    TLista aux = L;
    /*Casos de corte:
    1. aux es NULL
    2. Se encontro el equipo
    3. El puntaje de aux es menor a P
    4. El puntaje de aux es P pero su nombre es mayor al de E*/
    while (aux != NULL && aux->puntaje >= P && strcmp(aux->nombre, E) && (aux->puntaje != P || strcmp(aux->nombre, E) < 0))
        aux = aux->sig;
    return !strcmp(aux->nombre, E) && aux->puntaje == P;
}

// Elimina a los jugadores suspendidos
void eliminar(TLista *L)
{
    TLista aux = *L;
    TJugador *ant, *elim, *siguiente;
    while (aux != NULL)
    {
        elim = aux->jugadores;
        // Eliminar los primeros jugadores inactivos
        while (elim != NULL && elim->estado == 'S')
        {
            siguiente = elim == NULL ? NULL : elim->sig;
            aux->jugadores = siguiente;
            free(elim);
            elim = siguiente;
        }
        siguiente = elim == NULL ? NULL : elim->sig;
        // Resto de los jugadores
        while (elim != NULL)
        {
            if (elim->estado == 'S')
            {
                ant->sig = siguiente;
                free(elim);
            }
            ant = elim;
            elim = siguiente;
            siguiente = elim == NULL ? NULL : elim->sig;
        }
        aux = aux->sig;
    }
}

void mostrarLista(TLista L)
{
    TLista aux = L;
    TJugador *jugador;
    while (aux != NULL)
    {
        printf("%s %d\n", aux->nombre, aux->puntaje);
        jugador = aux->jugadores;
        while (jugador != NULL)
        {
            printf("%s %d %c\n", jugador->nombre, jugador->edad, jugador->estado);
            jugador = jugador->sig;
        }
        printf("\n");
        aux = aux->sig;
    }
}