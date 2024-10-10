#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char *TElementoA;
typedef struct nodo
{
    TElementoA dato;
    struct nodo *izq,*der;
} nodo;
typedef nodo *arbol;

void addnodo(arbol *a,TElementoA x);
void cargarArbol(arbol *a);
void nivCadMasLarga(arbol a, unsigned short nivel, unsigned short *maxLongitud, unsigned short *nivelCadLarga);

int main()
{
    arbol a;
    unsigned short maxLongitud = 0, nivelCadLarga = 0;
    
    cargarArbol(&a);
    nivCadMasLarga(a, 1, &maxLongitud, &nivelCadLarga);
    if (nivelCadLarga == 0)
        printf("No se encontro palabra que empiece con A.\n");
    else
        printf("Nivel de la cadena mas larga que empiece con A: %u\n",nivelCadLarga);
    
    return 0;
}

void addnodo(arbol *a,TElementoA x){
    *a = (arbol)malloc(sizeof(nodo));
    (*a)->dato = x;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}

void cargarArbol(arbol *a){
    addnodo(a, "Casa");
    addnodo(&(*a)->izq, "Arbol");
    addnodo(&(*a)->der, "linda");
    addnodo(&(*a)->izq->izq, "gato");
    addnodo(&(*a)->izq->der, "Artilleria");
    addnodo(&(*a)->der->izq, "Mate");
    addnodo(&(*a)->izq->der->der,"La");
}

void nivCadMasLarga(arbol a, unsigned short nivel, unsigned short *maxLongitud, unsigned short *nivelCadLarga)
{
    unsigned short longitud;

    if (a != NULL)
    {
        // Comprobar si la cadena empieza con 'A' o 'a'
        if (a->dato[0] == 'A' || a->dato[0] == 'a')
        {
            longitud = strlen(a->dato);
            // Si la longitud es mayor que la actual máxima, actualizar
            if (longitud > *maxLongitud)
            {
                *maxLongitud = longitud;
                *nivelCadLarga = nivel;
            }
        }
        // Llamar recursivamente a los hijos izquierdo y derecho
        nivCadMasLarga(a->izq, nivel + 1, maxLongitud, nivelCadLarga);
        nivCadMasLarga(a->der, nivel + 1, maxLongitud, nivelCadLarga);
    }
}