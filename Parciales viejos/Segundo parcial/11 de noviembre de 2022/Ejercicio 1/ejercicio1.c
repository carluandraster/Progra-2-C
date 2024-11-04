#include <stdio.h>
#include <stdlib.h>

typedef char TElementoA;
typedef struct nodo
{
    TElementoA dato;
    struct nodo *izq, *der;
} nodo;
typedef nodo *arbol;

void addnodo(arbol *a, TElementoA e);
void cargarArbol(arbol *a);
int cumple(arbol a, int K, int nivel);

int main()
{
    arbol a;
    int K;
    cargarArbol(&a);
    do
    {
        printf("Ingrese un nivel K: ");
        scanf("%d", &K);
    } while (K <= 1);
    printf(cumple(a, K, 1) ? "Cumple con la condicion pedida\n" : "No cumple condicion pedida\n");
    return 0;
}

void addnodo(arbol *a, TElementoA e)
{
    *a = (arbol)malloc(sizeof(nodo));
    (*a)->dato = e;
    (*a)->izq = (*a)->der = NULL;
}

void cargarArbol(arbol *a)
{
    // Raiz
    addnodo(a, 'A');

    // Hijos de A
    addnodo(&(*a)->izq, 'B');
    addnodo(&(*a)->der, 'C');

    // Hijos de B
    addnodo(&(*a)->izq->izq, 'E');
    addnodo(&(*a)->izq->der, 'D');

    // Hijos de C
    addnodo(&(*a)->der->izq, 'F');
    addnodo(&(*a)->der->der, 'G');
}

int cumple(arbol a, int K, int nivel)
{
    if (a == NULL)
        return 1;
    else if (nivel == K - 1)                  // El nivel siguiente es K
        if (a->izq == NULL && a->der == NULL) // No tiene hijos
            return 1;
        else if (a->izq == NULL) // Solo tiene hijo derecho
            return a->dato < a->der->dato;
        else if (a->der == NULL) // Solo tiene hijos izquierdo
            return a->dato < a->izq->dato;
        else
            return a->dato < a->izq->dato && a->izq->dato < a->der->dato;
    else
        return cumple(a->izq, K, nivel + 1) && cumple(a->der, K, nivel + 1);
}