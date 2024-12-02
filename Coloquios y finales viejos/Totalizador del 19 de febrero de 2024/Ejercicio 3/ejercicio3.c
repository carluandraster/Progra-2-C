#include <stdio.h>
#include "TDA N-ario/N-ario.h"

Nodo *crearNodo(TElementoA valor);
void cargarArbol(Arbol *a, Posicion *p);
unsigned int grado(Arbol a, Posicion p);
unsigned int contarNodos(Arbol a, Posicion p, unsigned int K, unsigned int nivel);

int main()
{
    Arbol a;
    Posicion p;
    unsigned int K;

    cargarArbol(&a, &p);
    printf("Ingrese un numero K: ");
    scanf("%u", &K);
    printf(contarNodos(a, p, K, 1) == K ? "Hay exactamente K nodos no hoja que tienen grado igual al nivel en el que se encuentran\n" : "No hay exactamente K nodos no hoja que tengan grado igual al nivel en el que se encuentran\n");
    return 0;
}

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

void cargarArbol(Arbol *a, Posicion *p)
{
    *a = crearNodo(3); // Raíz del árbol

    (*a)->hijoIzq = crearNodo(2);                         // Hijo más izquierdo de la raíz
    (*a)->hijoIzq->hermanoDer = crearNodo(1);             // Hermano derecho del primer hijo
    (*a)->hijoIzq->hermanoDer->hermanoDer = crearNodo(2); // Otro hermano

    // Agregamos hijos al nodo 2
    (*a)->hijoIzq->hijoIzq = crearNodo(1);
    (*a)->hijoIzq->hijoIzq->hermanoDer = crearNodo(1);

    // Agregamos un hijo al nodo 3
    (*a)->hijoIzq->hermanoDer->hijoIzq = crearNodo(-7);

    // Agregamos hijos al nodo 4
    (*a)->hijoIzq->hermanoDer->hermanoDer->hijoIzq = crearNodo(1);
    (*a)->hijoIzq->hermanoDer->hermanoDer->hijoIzq->hermanoDer = crearNodo(0);

    *p = *a;
}

// Devuelve el grado del nodo que esta en la posicion p
unsigned int grado(Arbol a, Posicion p)
{
    unsigned int contador = 0;
    Posicion c;
    if (!Nulo(p))
    {
        c = HijoMasIzq(p, a);
        while (!Nulo(c))
        {
            contador++;
            c = HermanoDer(c, a);
        }
    }
    return contador;
}

unsigned int contarNodos(Arbol a, Posicion p, unsigned int K, unsigned int nivel)
{
    Posicion c;
    unsigned int acumulador;

    acumulador = grado(a, p) == nivel;
    c = HijoMasIzq(p, a);
    while (!Nulo(c))
    {
        acumulador += contarNodos(a, c, K, nivel + 1);
        c = HermanoDer(c, a);
    }
    return acumulador;
}