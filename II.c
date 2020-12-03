#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void main(){
    char *car;
    int val=0;
    strcpy(car,"0");
    //do {
        val = 10*val + (int)atoi(car);
        printf("\n val = %d\n",val);
        scanf("%s",car);
        printf("\n car = %c et (int)car = %d",*car,atoi(car));
    //}while(*car != '\n');
}