#include <stdio.h>
#include <stdlib.h>

typedef struct noeud{
    int valeur;
    struct noeud *suivant;
} cellule;

int estVide_listeP(cellule *liste){
    if(!liste) return((int)1);
    return((int)0);
}

int Taille_listeP(cellule* liste){
    cellule *pointeur;
    int taille = 0;
    pointeur = liste;
    while(pointeur){
        taille++;
        pointeur = pointeur->suivant;
    }
    return((int)taille);
}

cellule *insererElement_listeP(cellule* liste,int pos,int val){
    cellule* nouvelElem;
    nouvelElem = (cellule*)malloc(sizeof(cellule));
    if(!nouvelElem){
        printf("\n memoire insuffisante \n");
        exit(-1);
    }
    nouvelElem->valeur = val;
    if(pos == 1){
        nouvelElem->suivant = liste;
        return((cellule *)nouvelElem);
    }
    cellule *pointeur;
    pointeur = liste; 
    int compteur = 1;
    while(pointeur){
        if (compteur == pos-1){
            nouvelElem->suivant = pointeur->suivant;
            pointeur->suivant = nouvelElem;
            return ((cellule *)liste);
        }
        compteur++;
        pointeur = pointeur->suivant; 
    }
    free(nouvelElem);
    return ((cellule *)liste);
}

void afficher_listeP(cellule *liste){
    cellule *pointeur;
    pointeur = liste;
    printf("\n");
    while(pointeur){
        printf("\t%d",pointeur->valeur);
        pointeur = pointeur->suivant;
    }
    printf("\n");
}

int positionDElement(cellule *liste,int elem){
    if(!liste) return ((int)-1);
    cellule *pointeur;
    int position = 1;
    pointeur = liste;
    while (pointeur){
        if(pointeur->valeur == elem)return ((int)position);
        position++;
        pointeur = pointeur->suivant;
    }
    return((int)0);
}

cellule *suppPos_listeP(cellule* liste,int pos){
    cellule *pointeur,*tmp;
    if(pos == 1){
        tmp = liste;
        liste = liste->suivant;
        free(tmp);
        return((cellule *)liste);
    }
    pointeur = liste; 
    int compteur = 1;
    while(pointeur->suivant){
        if (compteur == pos-1){
            tmp = pointeur->suivant;
            pointeur->suivant = tmp->suivant;
            free(tmp);
            return ((cellule *)liste);
        }
        compteur++;
        pointeur = pointeur->suivant; 
    }
    return ((cellule *)liste);
}
cellule *supprimerElement_listeP(cellule* liste,int val){
    int position;
    if((position=positionDElement(liste,val))>0)
    liste=suppPos_listeP(liste,position);
    return((cellule*)liste);
}

cellule *suppTtOccElem_listeP(cellule* liste,int val){
    int position;
    while((position=positionDElement(liste,val))>0)
    liste=suppPos_listeP(liste,position);
    return((cellule*)liste);
}


cellule *vider_listeP(cellule* liste){
    cellule *pointeur,*tmp;
    pointeur = liste;
    liste = NULL;
    while(pointeur){
        tmp = pointeur;
        pointeur = pointeur->suivant;
        free(tmp);
    }
    return ((cellule*)liste);
}

void main(){
    cellule *liste;
    liste = NULL;
    if(estVide_listeP(liste))printf("\nla liste est vide\n");
    for (int i = -1; i < 10; i++)
    {
        liste = insererElement_listeP(liste,i,i);
    }
    if(estVide_listeP(liste))printf("\nla liste est vide\n");
    afficher_listeP(liste);
    liste = supprimerElement_listeP(liste,5);
    afficher_listeP(liste);
    for (int i = 1; i < 10; i++)
    {
        liste = insererElement_listeP(liste,2*i,6);
    }
    afficher_listeP(liste);
    liste = suppTtOccElem_listeP(liste,6);
    printf("\n la taille de la liste est : %d\n",Taille_listeP(liste));
    afficher_listeP(liste);
}