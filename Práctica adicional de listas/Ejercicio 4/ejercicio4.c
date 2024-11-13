#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXCAR 15

typedef struct documento
{
    char DNI[9];
    struct documento *sig;
} documento;
typedef documento *TListaDNI;
typedef struct nodito
{
    char codigo[5], fecha[9], hora[5];
    int capacidad;
    TListaDNI pasajeros;
    struct nodito *sig;
} nodito;
typedef nodito *TSubLista;
typedef struct nodo
{
    char destino[MAXCAR];
    TSubLista vuelos;
    struct nodo *sig;
} nodo;
typedef nodo *TLista;

void addDNI(TListaDNI *DNIS, char DNI[9]);
void removeDNI(TListaDNI *DNIS, char DNI[9]);
void addVuelo(TSubLista *Vuelos, char codigo[5], char fecha[9], char hora[5], int capacidad);
void addDestino(TLista *D, char destino[]);
void cargarLista(TLista *D);
void buscarDestino(TLista D, char nombre[], TLista *destino);
void buscarVuelo(TLista D, char codigo[], TSubLista *vuelo);
int cantReservas(TSubLista);
void listarEstados(TLista destino);
void mostrarLista(TLista D);

int main()
{
    TLista D = NULL, dest;
    TSubLista vuelo;
    char respuesta, codigo[5], fecha[9], hora[5], destino[MAXCAR], DNI[9];
    int capacidad, error, res;

    cargarLista(&D);

    // Agregar vuelo o destino
    do
    {
        printf("Desea agregar un nuevo vuelo? (S o N)\n");
        scanf(" %c", &respuesta);
        respuesta = toupper(respuesta);
    } while (respuesta != 'S' && respuesta != 'N');
    while (respuesta == 'S')
    {
        printf("Ingrese el destino: ");
        scanf(" %s", destino);
        buscarDestino(D, destino, &dest);
        if (dest == NULL)
        {
            addDestino(&D, destino);
            dest = D;
        }

        printf("Ingrese un codigo: ");
        scanf(" %s", codigo);
        printf("Ingrese una fecha: ");
        scanf(" %s", fecha);
        printf("Ingrese hora de despegue: ");
        scanf(" %s", hora);
        printf("Ingrese capacidad del avion: ");
        scanf(" %d", &capacidad);
        addVuelo(&dest->vuelos, codigo, fecha, hora, capacidad);

        do
        {
            printf("Desea agregar otro vuelo? (S o N)\n");
            scanf(" %c", &respuesta);
            respuesta = toupper(respuesta);
        } while (respuesta != 'S' && respuesta != 'N');
    }

    // Agregar o quitar documento
    do
    {
        printf("Desea reservar o cancelar un pasaje? (S o N)\n");
        scanf(" %c", &respuesta);
        respuesta = toupper(respuesta);
    } while (respuesta != 'S' && respuesta != 'N');
    while (respuesta == 'S')
    {
        printf("Ingrese el destino: ");
        scanf(" %s", destino);
        buscarDestino(D, destino, &dest);
        if (dest == NULL)
            printf("No se encontro el destino\n");
        else
        {
            printf("Ingrese codigo de vuelo: ");
            scanf(" %s", codigo);
            buscarVuelo(dest, codigo, &vuelo);
            if (vuelo == NULL)
                printf("No se encontro el vuelo\n");
            else
            {
                do
                {
                    printf("Menu\n1 - Reservar\n2 - Cancelar\n");
                    scanf("%d", &res);
                } while (res != 1 && res != 2);
                printf("Ingrese documento: ");
                scanf(" %s", DNI);
                if (respuesta == 1)
                    addDNI(&vuelo->pasajeros, DNI);
                else
                    removeDNI(&vuelo->pasajeros, DNI);
            }
        }
        do
        {
            printf("Desea reservar o cancelar otro pasaje? (S o N)\n");
            scanf(" %c", &respuesta);
            respuesta = toupper(respuesta);
        } while (respuesta != 'S' && respuesta != 'N');
    }
    printf("Ingrese otro destino: ");
    scanf(" %s", destino);
    buscarDestino(D, destino, &dest);
    if (dest == NULL)
        printf("No se encontro destino\n");
    else
        listarEstados(dest);

    return 0;
}

// Agrega un DNI a la subsublista de pasajeros
void addDNI(TListaDNI *DNIS, char DNI[9])
{
    TListaDNI nuevo;
    nuevo = (TListaDNI)malloc(sizeof(documento));
    strcpy(nuevo->DNI, DNI);
    nuevo->sig = *DNIS;
    *DNIS = nuevo;
}

// Quita un DNI de la subsublista de pasajeros
void removeDNI(TListaDNI *DNIS, char DNI[9])
{
    TListaDNI ant = NULL, elim = *DNIS;
    while (elim != NULL && strcmp(elim->DNI, DNI))
    {
        ant = elim;
        elim = elim->sig;
    }
    if (elim != NULL)
    {
        if (ant == NULL)
            *DNIS = elim->sig;
        else
            ant->sig = elim->sig;
        free(elim);
    }
}

// Inserta ordenado un vuelo en la sublista de vuelos
void addVuelo(TSubLista *Vuelos, char codigo[5], char fecha[9], char hora[5], int capacidad)
{
    TSubLista ant = NULL, nuevo, Sig = *Vuelos;
    nuevo = (TSubLista)malloc(sizeof(nodito));
    strcpy(nuevo->codigo, codigo);
    strcpy(nuevo->fecha, fecha);
    strcpy(nuevo->hora, hora);
    nuevo->capacidad = capacidad;
    nuevo->pasajeros = NULL;
    while (Sig != NULL && strcmp(codigo, Sig->codigo) > 0)
    {
        ant = Sig;
        Sig = Sig->sig;
    }
    nuevo->sig = Sig;
    if (ant == NULL)
        *Vuelos = nuevo;
    else
        ant->sig = nuevo;
}

// Agrega un destino
void addDestino(TLista *D, char destino[])
{
    TLista nuevo = (TLista)malloc(sizeof(nodo));
    strcpy(nuevo->destino, destino);
    nuevo->vuelos = NULL;
    nuevo->sig = *D;
    *D = nuevo;
}

void cargarLista(TLista *D)
{
    addDestino(D, "Nueva_York");
    addDestino(D, "Rio_de_Janeiro");
    addDestino(D, "Madrid");
    addDestino(D, "Cancun");
    addDestino(D, "Buenos_Aires");
    addVuelo(&(*D)->vuelos, "AA01", "22112024", "1000", 100);
    addDNI(&(*D)->vuelos->pasajeros, "37196999");
    addDNI(&(*D)->vuelos->pasajeros, "17756569");
    addDNI(&(*D)->vuelos->pasajeros, "22139241");
    addDNI(&(*D)->vuelos->pasajeros, "45993239");
    addVuelo(&(*D)->vuelos, "AA02", "25112024", "1800", 150);
    addDNI(&(*D)->vuelos->sig->pasajeros, "21196547");
    addDNI(&(*D)->vuelos->sig->pasajeros, "30141329");
}

// Busca destino en la lista. De no encontrarse, devuelve NULL
void buscarDestino(TLista D, char nombre[], TLista *destino)
{
    *destino = D;
    while (*destino != NULL && strcmp((*destino)->destino, nombre))
        *destino = (*destino)->sig;
}

// Busca vuelo en la sublista de D. De no encontrarse, devuelve NULL
void buscarVuelo(TLista D, char codigo[], TSubLista *vuelo)
{
    *vuelo = D->vuelos;
    while (*vuelo != NULL && strcmp((*vuelo)->codigo, codigo) < 0)
        *vuelo = (*vuelo)->sig;
    if (*vuelo != NULL && strcmp((*vuelo)->codigo, codigo) > 0) // No se encontro el vuelo
        *vuelo = NULL;
}

// Devuelve la cantidad de reservas que tiene el vuelo V
int cantReservas(TSubLista V)
{
    TListaDNI aux = V->pasajeros;
    int contador = 0;
    while (aux != NULL)
    {
        contador++;
        aux = aux->sig;
    }
    return contador;
}

void listarEstados(TLista destino)
{
    TSubLista aux = destino->vuelos;
    while (aux != NULL)
    {
        /* code */
    }
}