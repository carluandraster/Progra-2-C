#include <stdio.h>

int main (){
    int *p, a = 4, b = 5;
    p = &b; // A p se le asigna donde esta b. *p pasa a valer 5
    *p *= 2; // Duplicar a *p (pasa a valer 10)
    printf("b=%d *p=%d\n", b, *p); // b=10 *p=10 
    printf("&b=%p p=%p &p=%p\n", &b, p, &p); // &b=AA01 p=AA01 &p=B3F0 
    b = *p *3; 
    printf("b=%d *p=%d\n", b, *p); // b=30 *p=30 
    printf("&b=%p p=%p\n", &b, p); // &b=AA01 p=AA01
    a = b; 
    p = &a; 
    (*p)++; 
    printf("b=%d a=%d *p=%d\n", b, a, *p); // b=30 a=31 *p=31 
    printf("&b=%p &a=%p p=%p &p=%p\n", &b, &a, p, &p); 
    return 0;
}