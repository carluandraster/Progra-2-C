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
void cargarListaEquipos(TLista *L);
void listarA(TLista L, TLista *M, char K, int *cantJugListados, char *maxEquipo);
void listarB(TLista L, TLista *N, int X, float *promedios);
void mostrarListaConPromedios(TLista N,float *PROMEDIOS);
int verifica(TLista L, char *E, int P);
void eliminar(TLista *L);
void mostrarLista(TLista L);

int main()
{
    TLista L, M, N;
    int X, cantJugListados = 0, P;
    char K, *maxEquipo, *E;
    float *PROMEDIOS;

    cargarListaEquipos(&L);
    printf("Ingrese una letra K: ");
    scanf(" %c", &K);
    listarA(L, &M, K, &cantJugListados, maxEquipo);
    printf("Cantidad de jugadores listados: %d\n",cantJugListados);
    printf("Equipo con mas jugadores que empiezan por la letra solicitada: %s\n",maxEquipo);
    mostrarLista(M);
    do
    {
        printf("Ingrese un puntaje X: ");
        scanf("%d", &X);
    } while (X > 0);
    listarB(L, &N, X,PROMEDIOS);
    mostrarListaConPromedios(N,PROMEDIOS);
    printf("Ingrese un equipo: ");
    scanf("%s", E);
    printf("Ingrese puntaje: ");
    scanf("%d", &P);
    printf(verifica(L, E, P) ? "El equipo %s tiene %d puntos\n", E, P : "El equipo %s no tiene %d puntos\n", E, P);
    eliminar(&L);
    mostrarLista(L);

    return 0;
}

// Agrega un nodo a la lista principal
void addnodo(TLista *L, TEquipo e){
    TLista aux = *L,ant,nuevo;
    nuevo = (TLista)malloc(sizeof(TEquipo));
    *nuevo = e;
    if (*L == NULL)
        *L = nuevo;
    else
    {
        while (aux != NULL)
        {
            ant = aux;
            aux = aux->sig;
        }
        ant->sig = nuevo;
    }
}

// Agrega un nodo a una sublista
void addnodito(TLista L, TJugador e){
    TJugador *aux,*nuevo;
    aux = L->jugadores;
    nuevo = (TJugador *)malloc(sizeof(TJugador));
    *nuevo = e;
    if (aux == NULL)
        L->jugadores = aux;
    else
    {
        while (aux->sig != NULL)
            aux = aux->sig;
        aux->sig = nuevo;
    }
}

// Inicializa lista de equipos
void cargarListaEquipos(TLista *L)
{
    TEquipo equipo1 = {"River Plate", 45, NULL, NULL};
    TEquipo equipo2 = {"Boca Juniors", 40, NULL, NULL};
    TEquipo equipo3 = {"Racing Club", 35, NULL, NULL};
    TEquipo equipo4 = {"Independiente", 30, NULL, NULL};
    
    // Agregamos los equipos a la lista principal en orden decreciente por puntaje
    addnodo(L, equipo1);
    addnodo(L, equipo2);
    addnodo(L, equipo3);
    addnodo(L, equipo4);

    // Agregamos jugadores para cada equipo
    // River Plate
    TJugador jugador1 = {"Franco Armani", 34, 'A', NULL};
    TJugador jugador2 = {"Julian Alvarez", 21, 'A', NULL};
    TJugador jugador3 = {"Enzo Perez", 35, 'A', NULL};
    addnodito(*L, jugador1);
    addnodito(*L, jugador2);
    addnodito(*L, jugador3);

    // Boca Juniors
    TLista aux = (*L)->sig;
    TJugador jugador4 = {"Esteban Andrada", 31, 'A', NULL};
    TJugador jugador5 = {"Carlos Tevez", 37, 'S', NULL};
    TJugador jugador6 = {"Edwin Cardona", 28, 'A', NULL};
    addnodito(aux, jugador4);
    addnodito(aux, jugador5);
    addnodito(aux, jugador6);

    // Racing Club
    aux = aux->sig;
    TJugador jugador7 = {"Gabriel Arias", 33, 'A', NULL};
    TJugador jugador8 = {"Lisandro Lopez", 38, 'S', NULL};
    addnodito(aux, jugador7);
    addnodito(aux, jugador8);

    // Independiente
    aux = aux->sig;
    TJugador jugador9 = {"Sebastian Sosa", 34, 'A', NULL};
    TJugador jugador10 = {"Silvio Romero", 33, 'A', NULL};
    addnodito(aux, jugador9);
    addnodito(aux, jugador10);
}

// Lista para todos los clubes los jugadores cuyo nombre comienza con la letra K
void listarA(TLista L, TLista *M, char K, int *cantJugListados, char *maxEquipo){
    TLista aux = L,nuevo,equipo;
    TJugador *jugador;
    int maxJugList = -1,contador;

    while (aux != NULL)
    {
        *equipo = *aux;
        addnodo(M,*equipo);
        jugador = equipo->jugadores;
        contador = 0;
        while (jugador != NULL)
        {
            if (jugador->nombre[0] == K){
                addnodito(aux,*jugador);
                contador++;
            }
            jugador = jugador->sig;
        }
        if (contador > maxJugList)
        {
            maxJugList = contador;
            strcpy(maxEquipo,aux->nombre);
        }
        *cantJugListados += contador;
        aux = aux->sig;
    }
}

// Lista los clubes que tienen un mínimo de X (dato) puntos junto con todos sus jugadores,
// mostrando edad promedio de cada equipo
void listarB(TLista L, TLista *N, int X, float *promedios){
    int i = 0,contador,acumulador;
    TLista aux = L;
    TJugador *jugador;

    while (aux != NULL && aux->puntaje >= X)
    {
        contador = acumulador = 0;
        addnodo(N,*aux);
        jugador = aux->jugadores;
        while (jugador != NULL)
        {
            addnodito(aux,*jugador);
            jugador = jugador->sig;
            acumulador += jugador->edad;
            contador++;
        }
        if (contador)
            promedios[i] = (float)acumulador/contador;
        else
            promedios[i] = -1;
        i++;
        aux = aux->sig;
    }
    
}

void mostrarListaConPromedios(TLista N,float *PROMEDIOS){}