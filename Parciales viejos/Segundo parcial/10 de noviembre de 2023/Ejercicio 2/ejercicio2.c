#include <stdio.h>
#include "TDA N-ario/N-ario.h"
#define INFINITO 9999

Nodo *crearNodo(TElementoA valor);
void cargarArbol(Arbol *a, Posicion *p);
int grado(Arbol a, Posicion p);
int minGrado(Arbol a, Posicion p, int K, int nivel);
int maxGrado(Arbol a, Posicion p, int K, int nivel);

int main()
{
    Arbol a;
    Posicion p;
    int K, MaxGrado;

    cargarArbol(&a, &p);
    do
    {
        printf("Ingrese un nivel K: ");
        scanf("%d", &K);
    } while (K < 1);
    MaxGrado = maxGrado(a, p, K, 1);
    if (MaxGrado == -1)
        printf("No existe el nivel K en el grafo.\n");
    else
    {
        printf("Maximo grado del nivel K: %d\n", MaxGrado);
        printf("Minimo grado del nivel K: %d\n", minGrado(a, p, K, 1));
    }

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
    *a = crearNodo('C'); // Raíz del árbol

    (*a)->hijoIzq = crearNodo('B');                         // Hijo más izquierdo de la raíz
    (*a)->hijoIzq->hermanoDer = crearNodo('A');             // Hermano derecho del primer hijo
    (*a)->hijoIzq->hermanoDer->hermanoDer = crearNodo('D'); // Otro hermano

    // Agregamos hijos al nodo B
    (*a)->hijoIzq->hijoIzq = crearNodo('E');
    (*a)->hijoIzq->hijoIzq->hermanoDer = crearNodo('F');
    (*a)->hijoIzq->hijoIzq->hermanoDer->hermanoDer = crearNodo('u');

    // Agregamos un hijo al nodo A
    (*a)->hijoIzq->hermanoDer->hijoIzq = crearNodo('O');

    // Agregamos hijos al nodo D
    (*a)->hijoIzq->hermanoDer->hermanoDer->hijoIzq = crearNodo('I');
    (*a)->hijoIzq->hermanoDer->hermanoDer->hijoIzq->hermanoDer = crearNodo('J');

    *p = *a;
}

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

int minGrado(Arbol a, Posicion p, int K, int nivel)
{
    int minAux = INFINITO, minGra;
    Posicion c;
    if (!Nulo(p))
        if (nivel == K)
            return grado(a, p);
        else
        {
            c = HijoMasIzq(p, a);
            while (!Nulo(c))
            {
                minGra = minGrado(a, c, K, nivel + 1);
                if (minGra < minAux)
                    minAux = minGra;
                c = HermanoDer(c, a);
            }
            return minAux;
        }
    else
        return INFINITO;
}

int maxGrado(Arbol a, Posicion p, int K, int nivel)
{
    int maxAux = -1, maxGra;
    Posicion c;
    if (!Nulo(p))
        if (nivel == K)
            return grado(a, p);
        else
        {
            c = HijoMasIzq(p, a);
            while (!Nulo(c))
            {
                maxGra = maxGrado(a, c, K, nivel + 1);
                if (maxGra > maxAux)
                    maxAux = maxGra;
                c = HermanoDer(c, a);
            }
            return maxAux;
        }
    else
        return -1;
}