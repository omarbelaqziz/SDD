#include <stdio.h>
#include <stdlib.h>


void ConverEntier(int* resultat){
    char car;
    while(car = getchar()){
        switch (car){
        case '\n':
        case '\t':
        case ' ': return;
        case '0': *resultat = *resultat * 10;break;
        case '1': *resultat = (*resultat * 10) + 1;break;
        case '2': *resultat = (*resultat * 10) + 2;break;
        case '3': *resultat = (*resultat * 10) + 3;break;
        case '4': *resultat = (*resultat * 10) + 4;break;
        case '5': *resultat = (*resultat * 10) + 5;break;
        case '6': *resultat = (*resultat * 10) + 6;break;
        case '7': *resultat = (*resultat * 10) + 7;break;
        case '8': *resultat = (*resultat * 10) + 8;break;
        case '9': *resultat = (*resultat * 10) + 9;break;
        default:    printf("\n erreur de saisie"); 
                    exit(-1);
        }
    }

}


void main(){
    int op = 0,op1 = 0 ,op2 = 0,entier = 0,aide=0,resultat=0;
    int vrai = 0;
    char car;
    printf("entrer votre equation : ");
    while(car = getchar()){
         switch (car){
        case '\n':
        case '\t':
        case ' ':goto fin;break;
        case '+':   op = 1; 
                    if(aide == 0){
                        aide = 1;
                        op1 = entier;
                        entier = 0;
                    } else if (aide == 1) {
                        aide = 2;
                        op2 = entier;
                        entier = 0;
                    }break;
        case '=': if(aide == 0){
                        aide = 1;
                        op1 = entier;
                        entier = 0;
                    } else if (aide == 1) {
                        aide = 2;
                        op2 = entier;
                        entier = 0;
                    }res(&resultat);goto fin;
        case '0': entier = entier * 10;break;
        case '1': entier = (entier * 10) + 1;break;
        case '2': entier = (entier * 10) + 2;break;
        case '3': entier = (entier * 10) + 3;break;
        case '4': entier = (entier * 10) + 4;break;
        case '5': entier = (entier * 10) + 5;break;
        case '6': entier = (entier * 10) + 6;break;
        case '7': entier = (entier * 10) + 7;break;
        case '8': entier = (entier * 10) + 8;break;
        case '9': entier = (entier * 10) + 9;break;
        default:    printf("\n erreur de saisie"); 
                    exit(-1); 
        }
        
    }
    fin : 
        printf("op = %d\nop1 = %d\nop2 = %d\nresultat = %d",op,op1,op2,resultat);
}