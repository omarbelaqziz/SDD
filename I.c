#include <stdio.h>

void main(){
    int a, b, pgcd, i;
    printf("entrer a et b : ");
    scanf("%d %d",&a,&b);
    i = 1;
    
    while(i<a && i<b){
        if (!(a%i) && !(b%i)) pgcd = i;
        i++;
    }
    printf("le pgcd est %d",pgcd);
}