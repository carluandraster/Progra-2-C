#include <stdio.h>
#include <string.h>
#include "TDA N-ario/N-ario.h"

Nodo *crearNodo(TElementoA valor);
void cargarArbol(Arbol *a, Posicion *p);
int cumple(Arbol a, Posicion p, int K, int nivel);

int main()
{
    Arbol a;
    Posicion p;
    int K;

    cargarArbol(&a, &p);
    do
    {
        printf("Ingrese un nivel K: ");
        scanf("%d", &K);
    } while (K < 1);
    printf(cumple(a, p, K, 1) ? "El arbol cumple la condicion.\n" : "El arbol no cumple la condicion.\n");

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

// Carga el arbol
void cargarArbol(Arbol *a, Posicion *p)
{
    *a = crearNodo("Casa"); // Raíz del árbol

    (*a)->hijoIzq = crearNodo("Bala");                         // Hijo más izquierdo de la raíz
    (*a)->hijoIzq->hermanoDer = crearNodo("Arte");             // Hermano derecho del primer hijo
    (*a)->hijoIzq->hermanoDer->hermanoDer = crearNodo("Dedo"); // Otro hermano

    // Agregamos hijos al nodo Bala
    (*a)->hijoIzq->hijoIzq = crearNodo("Escalera");
    (*a)->hijoIzq->hijoIzq->hermanoDer = crearNodo("Foca");
    (*a)->hijoIzq->hijoIzq->hermanoDer->hermanoDer = crearNodo("Usar");

    // Agregamos un hijo al nodo Arte
    (*a)->hijoIzq->hermanoDer->hijoIzq = crearNodo("Oso");

    // Agregamos hijos al nodo Dedo
    (*a)->hijoIzq->hermanoDer->hermanoDer->hijoIzq = crearNodo("Isla");
    (*a)->hijoIzq->hermanoDer->hermanoDer->hijoIzq->hermanoDer = crearNodo("Jabon");

    *p = *a;
}

int cumple(Arbol a, Posicion p, int K, int nivel)
{
    Posicion c;
    int hayMayor = 0, hayMenor = 0, comparacion, grado = 0;
    if (Nulo(p))
        return 1;
    else if (nivel == K)
    {
        c = HijoMasIzq(p, a);
        while (!Nulo(c) && (!hayMayor || !hayMenor))
        {
            grado++;
            comparacion = strcmp(Info(p, a), Info(c, a));
            if (comparacion > 0)
                hayMayor = 1;
            else if (comparacion < 0)
                hayMenor = 1;
            c = HermanoDer(c, a);
        }
        return grado <= 1 || hayMayor && hayMenor;
    }
    else
    {
        c = HijoMasIzq(p, a);
        while (!Nulo(c) && cumple(a, c, K, nivel + 1))
            c = HermanoDer(c, a);
        return Nulo(c);
    }
}