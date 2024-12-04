#include <stdio.h>
#include "TDA N-ario/N-ario.h"

Nodo *crearNodo(TElementoA valor);
void cargarArbol(Arbol *a, Posicion *p);
int contarSi(Arbol a, Posicion p, unsigned int K, unsigned int nivel);

int main()
{
    Arbol a;
    Posicion p;
    unsigned int K;
    cargarArbol(&a, &p);
    printf("Ingrese un nivel K: ");
    scanf("%u", &K);
    printf("Cantidad de nodos en el nivel K con clave 0: %d\n", contarSi(a, p, K, 1));
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
    (*a)->hijoIzq->hermanoDer = crearNodo(0);             // Hermano derecho del primer hijo
    (*a)->hijoIzq->hermanoDer->hermanoDer = crearNodo(2); // Otro hermano

    // Agregamos hijos al nodo 2
    (*a)->hijoIzq->hijoIzq = crearNodo(0);
    (*a)->hijoIzq->hijoIzq->hermanoDer = crearNodo(0);

    // Agregamos un hijo al nodo 3
    (*a)->hijoIzq->hermanoDer->hijoIzq = crearNodo(-7);

    // Agregamos hijos al nodo 4
    (*a)->hijoIzq->hermanoDer->hermanoDer->hijoIzq = crearNodo(1);
    (*a)->hijoIzq->hermanoDer->hermanoDer->hijoIzq->hermanoDer = crearNodo(0);

    *p = *a;
}

int contarSi(Arbol a, Posicion p, unsigned int K, unsigned int nivel)
{
    Posicion c;
    int contador = 0;
    if (Nulo(p))
        return 0;
    else if (nivel == K)
        return Info(p, a) == 0;
    else
    {
        c = HijoMasIzq(p, a);
        while (!Nulo(c))
        {
            contador += contarSi(a, c, K, nivel + 1);
            c = HermanoDer(c, a);
        }
        return contador;
    }
}