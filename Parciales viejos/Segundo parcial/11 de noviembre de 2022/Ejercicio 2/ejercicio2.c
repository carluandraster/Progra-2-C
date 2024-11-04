#include <stdio.h>
#include "TDA N-ario/N-ario.h"
#define N 20

Nodo *crearNodo(TElementoA valor);
void cargarArbol(Arbol *a, Posicion *p);
int grado(Arbol a, Posicion p);
int maxClave(Arbol a, Posicion p, int G);

int main()
{
    Arbol a;
    Posicion p;
    int G, MaxClave;

    cargarArbol(&a, &p);
    do
    {
        printf("Ingrese un grado G: ");
        scanf("%d", &G);
    } while (G <= 0);
    MaxClave = maxClave(a, p, G);
    if (MaxClave == -1)
        printf("No se encontro nodos de grado G ni de grado 2G.\n");
    else
        printf("Maxima clave de grado G o 2G: %d", MaxClave);

    return 0;
}

// Crea un nodo en el arbol
Nodo *crearNodo(TElementoA valor)
{
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    if (nuevo != NULL)
    {
        nuevo->dato = valor;
        nuevo->hijoIzq = NULL;
        nuevo->hermanoDer = NULL;
    }
    return nuevo;
}

// Inicializa el arbol
void cargarArbol(Arbol *a, Posicion *p)
{
    *a = crearNodo(1); // Raíz del árbol

    (*a)->hijoIzq = crearNodo(2);                         // Hijo más izquierdo de la raíz
    (*a)->hijoIzq->hermanoDer = crearNodo(3);             // Hermano derecho del primer hijo
    (*a)->hijoIzq->hermanoDer->hermanoDer = crearNodo(4); // Otro hermano

    // Agregamos hijos al nodo 2
    (*a)->hijoIzq->hijoIzq = crearNodo(5);
    (*a)->hijoIzq->hijoIzq->hermanoDer = crearNodo(6);

    // Agregamos un hijo al nodo 3
    (*a)->hijoIzq->hermanoDer->hijoIzq = crearNodo(7);

    // Agregamos hijos al nodo 4
    (*a)->hijoIzq->hermanoDer->hermanoDer->hijoIzq = crearNodo(8);
    (*a)->hijoIzq->hermanoDer->hermanoDer->hijoIzq->hermanoDer = crearNodo(9);

    *p = *a;
}

// Devuelve el grado del nodo en la posicion p
int grado(Arbol a, Posicion p)
{
    Posicion c;
    int contador = 0;
    if (Nulo(p))
        return -1;
    else
    {
        c = HijoMasIzq(p, a);
        while (!Nulo(c))
        {
            contador++;
            c = HermanoDer(c, a);
        }
        return contador;
    }
}

// Retorna la mayor clave entre los nodos de grado G o 2G (si no hay, devuelve -1)
int maxClave(Arbol a, Posicion p, int G)
{
    int i, Grado, maxAux = -1, aux;
    Posicion c;
    if (Nulo(p))
        return -1;
    else
    {
        Grado = grado(a, p);
        if (Grado == G || Grado == 2 * G)
            maxAux = Info(p, a);
        c = HijoMasIzq(p, a);
        while (!Nulo(c))
        {
            aux = maxClave(a, c, G);
            if (aux > maxAux)
                maxAux = aux;
            c = HermanoDer(c, a);
        }
        return maxAux;
    }
}