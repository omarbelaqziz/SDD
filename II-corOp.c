#include <stdio.h>
#include <stdlib.h>


void partie_fractionnaire(int* entier, float* reel){
    float dix=0.1;
    char car;
    
    *reel = *reel + (float)*entier;
    while(car = getchar()){
        switch (car){
        case '\n':
        case '\t':
        case ' ': return;
        case '0': *reel = *reel;break;
        case '1': *reel = *reel + (1.0 * dix);break;
        case '2': *reel = *reel + (2.0 * dix);break;
        case '3': *reel = *reel + (3.0 * dix);break;
        case '4': *reel = *reel + (4.0 * dix);break;
        case '5': *reel = *reel + (5.0 * dix);break;
        case '6': *reel = *reel + (6.0 * dix);break;
        case '7': *reel = *reel + (7.0 * dix);break;
        case '8': *reel = *reel + (8.0 * dix);break;
        case '9': *reel = *reel + (9.0 * dix);break;
        default:    printf("\n erreur de saisie"); 
                    exit(-1);
        }
        dix = dix/10.;
    }
}


void partie_naturel(int* entier, float* reel, int *estReel,int *estNegative){
    char car;
    while((car=getchar())==' '){
        
    }
    if((car=getchar())=='-') *estNegative = -1;
    while(car = getchar()){
        switch (car){
        case '\n':
        case '\t':
        case ' ': return;
        case '.': *estReel = 1;partie_fractionnaire(entier,reel);return;
        case '0': *entier = *entier * 10;break;
        case '1': *entier = (*entier * 10) + 1;break;
        case '2': *entier = (*entier * 10) + 2;break;
        case '3': *entier = (*entier * 10) + 3;break;
        case '4': *entier = (*entier * 10) + 4;break;
        case '5': *entier = (*entier * 10) + 5;break;
        case '6': *entier = (*entier * 10) + 6;break;
        case '7': *entier = (*entier * 10) + 7;break;
        case '8': *entier = (*entier * 10) + 8;break;
        case '9': *entier = (*entier * 10) + 9;break;
        default:    printf("\n erreur de saisie"); 
                    exit(-1); 
        }
    }
}

void main(){
    int valeur = 0;
    int estneg = 1;
    float reel;
    char car;
    int estReel = 0;
    printf("entrer une valeur : ");
    partie_naturel(&valeur,&reel,&estReel,&estneg);
    if(estReel) printf("la valeur que vous avez entré est %f", reel*estneg);
    else printf("la valeur que vous avez entré est %d", valeur*estneg);
}