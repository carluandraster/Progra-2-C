#include <stdio.h>
#include <string.h>
#define MAXELEM 20

int main()
{
    char cad1[MAXELEM], cad2[MAXELEM], cad3[MAXELEM];
    gets(cad1);
    gets(cad2);
    if (strcmp(cad1, cad2))
        strcpy(cad3, cad1);
    return 0;
}