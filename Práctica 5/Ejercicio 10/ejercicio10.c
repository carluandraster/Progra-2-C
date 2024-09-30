#include <stdio.h>
#include "../Ejercicio 09/pilaDinamica.h"
#define MAXELEM 100

void chequearParentesis(char expresion[MAXELEM]);
void chequearCorchetes(char expresion[MAXELEM]);
void chequearLlaves(char expresion[MAXELEM]);

int main()
{
    char expresion[MAXELEM];
    printf("Ingrese una expresion: ");
    scanf("%s", expresion);
    // Inciso a
    chequearParentesis(expresion);
    // Inciso b
    chequearCorchetes(expresion);
    chequearLlaves(expresion);
    return 0;
}

void chequearParentesis(char expresion[MAXELEM])
{
    unsigned short i = 0;
    TPila parentesis;
    TElementoP x;
    IniciaP(&parentesis);
    while (expresion[i] != '\0' && (expresion[i] != ')' || !VaciaP(parentesis)))
    {
        if (expresion[i] == '(')
            poneP(&parentesis, expresion[i]);
        else if (expresion[i] == ')')
            sacaP(&parentesis, &x);
        i++;
    }
    if (expresion[i] != '\0')
        printf("Falta abrir parentesis.\n");
    else if (!VaciaP(parentesis))
        printf("Falta cerrar parentesis.\n");
}

void chequearCorchetes(char expresion[MAXELEM])
{
    unsigned short i = 0;
    TPila corchetes;
    TElementoP x;
    IniciaP(&corchetes);
    while (expresion[i] != '\0' && (expresion[i] != ']' || !VaciaP(corchetes)))
    {
        if (expresion[i] == '[')
            poneP(&corchetes, expresion[i]);
        else if (expresion[i] == ']')
            sacaP(&corchetes, &x);
        i++;
    }
    if (expresion[i] != '\0')
        printf("Falta abrir corchetes.\n");
    else if (!VaciaP(corchetes))
        printf("Falta cerrar corchetes.\n");
}

void chequearLlaves(char expresion[MAXELEM])
{
    unsigned short i = 0;
    TPila llaves;
    TElementoP x;
    IniciaP(&llaves);
    while (expresion[i] != '\0' && (expresion[i] != '}' || !VaciaP(llaves)))
    {
        if (expresion[i] == '{')
            poneP(&llaves, expresion[i]);
        else if (expresion[i] == '}')
            sacaP(&llaves, &x);
        i++;
    }
    if (expresion[i] != '\0')
        printf("Falta abrir llaves.\n");
    else if (!VaciaP(llaves))
        printf("Falta cerrar llaves.\n");
}