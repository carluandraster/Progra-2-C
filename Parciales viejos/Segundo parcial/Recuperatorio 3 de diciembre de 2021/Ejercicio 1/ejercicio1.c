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
int verifica(arbol a, int K, int nivel);

int main()
{
    arbol a;
    int K;

    cargarArbol(&a);
    do
    {
        printf("Ingrese un nivel K: ");
        scanf("%d", &K);
    } while (K < 1);
    printf(verifica(a, K, 1) ? "En el bosque hay al menos un arbol que cumple la condicion.\n" : "Ningun arbol en el bosque cumple con la condicion.\n");

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
    addnodo(a, 'A');
    addnodo(&(*a)->izq, 'D');
    addnodo(&(*a)->der, 'C');
    addnodo(&(*a)->izq->izq, 'E');
    addnodo(&(*a)->izq->der, 'B');
    addnodo(&(*a)->der->izq, 'F');
    addnodo(&(*a)->der->der, 'G');
    addnodo(&(*a)->der->izq->der, 'A');
}

int verifica(arbol a, int K, int nivel)
{
    TElementoA vc = '\0';
    if (a == NULL)
        return 0;
    else if (nivel == K)
    {
        a = a->izq;
        while (a != NULL && a->dato > vc)
        {
            vc = a->dato;
            a = a->der;
        }
        return a == NULL;
    }
    else
        return verifica(a->izq, K, nivel + 1) || verifica(a->der, K, nivel);
}