#include <stdio.h>

int main(){
    int x,y;
    x=20;
    switch (x)
    {
    case 4:
        y=7;
        break;
    
    case 5:
        y=9;
        break;
    
    case 9:
        y = 14;
        break;
    
    default:
        y = 22;
        break;
    }

    printf("%d",y);
}