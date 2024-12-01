#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct nodo
{
    char clave;
    struct nodo *izq, *der;
} nodo;
typedef nodo *arbol;

void addnodo(arbol *a, char e);
void cargarArbol(arbol *a);
int esVocal(char c);
int nodoCumple(arbol a);
int cantNodoCumple(arbol a);
int cantArbolCumple(arbol a);

int main()
{
    arbol a;
    cargarArbol(&a);
    printf("Cantidad de arboles que cumplen la condicion: %d\n", cantArbolCumple(a));
    return 0;
}

void addnodo(arbol *a, char e)
{
    *a = (arbol)malloc(sizeof(nodo));
    (*a)->clave = e;
    (*a)->izq = (*a)->der = NULL;
}

void cargarArbol(arbol *a)
{
    addnodo(a, 'A');
    addnodo(&(*a)->izq, 'B');
    addnodo(&(*a)->der, 'C');
    addnodo(&(*a)->izq->izq, 'E');
    addnodo(&(*a)->izq->der, 'D');
    addnodo(&(*a)->der->izq, 'F');
    addnodo(&(*a)->der->der, 'I');
    addnodo(&(*a)->der->der->izq, 'T');
    addnodo(&(*a)->der->der->izq->der, 'Z');
}

// Verifica que el caracter sea una letra vocal
int esVocal(char c)
{
    c = toupper(c);
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

// Verifica si el nodo tiene clave vocal y todos sus hijos no
int nodoCumple(arbol a)
{
    if (a == NULL || !esVocal(a->clave))
        return 0;
    else
    {
        a = a->izq;
        while (a != NULL && !esVocal(a->clave))
            a = a->der;
        return a == NULL;
    }
}

// Cuenta la cantidad de nodos que verifican si tienen clave vocal y todos sus hijos no
int cantNodoCumple(arbol a)
{
    if (a == NULL)
        return 0;
    else
        return nodoCumple(a) + cantNodoCumple(a->izq) + cantNodoCumple(a->der);
}

// Cuenta los arboles con al menos 2 nodos que verifican si tienen clave vocal y todos sus hijos no
int cantArbolCumple(arbol a)
{
    int contador = 0;

    while (a != NULL)
    {
        contador += nodoCumple(a) + cantNodoCumple(a->izq) >= 2;
        a = a->der;
    }
    return contador;
}