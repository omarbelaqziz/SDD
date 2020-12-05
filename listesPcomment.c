// Manipulation des listes à l'aide des pointeurs

#include <stdio.h>
#include <stdlib.h>

/*
chaque cellule dans la liste contient deux champs:
    -un champ où on va stocker la valeur de la cellule.
    -un pointeur qui pointe vers la cellule suivante.*/
typedef struct noeud{
    int valeur;
    struct noeud *suivant;
} cellule;


/*************************************************************************
Fonction : estVide_listeP
Entrées : (cellule *liste) : la tete d'une liste 
Sorties : la focntion retourne une valeur entière:
    - 1 si la liste est vide.
    - 0 si la liste est non vide 
Description : on fait un test sur le pointeur de la liste
passé en paramètres , (c'est la tete de la liste),
si c'est un pointeur NULL cela veut dire que la tete ne 
pointe vers aucun élement ceci demontre bien que la liste 
vide.
*************************************************************************/
int estVide_listeP(cellule *liste)
{
    // on teste la valeur du pointeur 
    /* le test  if(!liste) est vrai seulement 
       si liste == NULL et on casse la fonction 
       en retournant 1 */
    if(!liste) return((int)1);
    /*  si la programme arrive a cette partie c'est que le
        test n'est pas vrai. En d'autres termes liste pointe 
        bien vers une cellule, cela veut dire qu'elle n'est pas 
        vide
    */
    return((int)0);
}


/*************************************************************************
Fonction : Taille_listeP
Entrées : (cellule *liste) : la tete d'une liste 
Sorties : la focntion retourne une la taille de si la liste.
Description : la  fonction calcule la taille de la liste  
en utilisant un pointeur qui traverse la liste jusqu'à sa fin 
en incrémentant la valeur d'un compteur 
*************************************************************************/
int Taille_listeP(cellule* liste)
{
    cellule *pointeur;// pointeur courant 
    int taille = 0;// taille de la liste initialisée par 0
    pointeur = liste;
    /*
    tant que la pointeur courant n'est pas NUll cela veut dire
    qu'on n'a pas encore atteint la fin de liste on incremente
    la taille et le pointeur courant pointe vers l'élement 
    suivant
    */
    while(pointeur)//debut
    {//debut de la boucle
        taille++;
        pointeur = pointeur->suivant;
    }//fin while(pointeur)
    return((int)taille);
}


/*************************************************************************
Fonction : insererElement_listeP
Entrées :   - (cellule* liste) : la tete d'une liste, lele
            - (int val) : la valeur qu'on veut inserer.
            - (int pos) : la position où on veut l'inserer
Sorties : la focntion retourne une pointeur vers la nouvelle 
liste contenant l'element inseré.
Description : la  fonction nous permet d'inserer un element
(une valeur) dans une position determinée (au debut, au milieux
ou à la fin). si la position n'est pas valide on ne va rien 
changer dans la liste
*************************************************************************/
cellule *insererElement_listeP(cellule* liste,int pos,int val)
    {
        cellule* nouvelElem;
        // creation d'une nouvelle cellule
        nouvelElem = (cellule*)malloc(sizeof(cellule));
        // tester si la création est bien passée
        if(!nouvelElem)
            {
                printf("\n memoire insuffisante \n");
                exit(-1);
            // si on n'a pas d'espace suffisant on quitlle le programme
            }
    // si tous se passe bien on continue

    //on affecte la veleur au nouvel élemeny
    nouvelElem->valeur = val;

    // insertion au début de la liste
    if(pos == 1){
        nouvelElem->suivant = liste;
        return((cellule *)nouvelElem);
        // on casse la fonction après l'insertion
    }

    // insertion à une position autre que le début
    cellule *pointeur;
    pointeur = liste; 
    int compteur = 1;

    /*pour inserer un element dans une position on doit
    se déplacer à l'élement qui précède cette position
    mais si la liste a une fin avant pos-1 cela veut dire que 
    la position est invalide*/
    while(pointeur)
        {
            if (compteur == pos-1){
                nouvelElem->suivant = pointeur->suivant;
                pointeur->suivant = nouvelElem;
                return ((cellule *)liste);
            }
            compteur++;
            pointeur = pointeur->suivant; 
        }
    /*si le programme arrive ici cela veut dire que la position
    est invalide, on libère donc l'éspace qu'on vient d'allouer
    avec malloc*/
    free(nouvelElem);
    return ((cellule *)liste);
}




/*************************************************************************
Fonction : afficher_listeP
Entrées : (cellule* liste) : la tete d'une liste, lele
Sorties : la focntion n'admet aucune sortie, elle ne fait 
qu'afficher
Description : la  fonction permet d'afficher les élements 
de la liste dans l'ordre en mettant des tabulation entre
es valeurs. Pour ce, un pointeur percours la liste jusqu'à 
sa fin en affichant le contenu de chaque cellule.
*************************************************************************/
void afficher_listeP(cellule *liste)
{
    cellule *pointeur;// pointeur courant
    pointeur = liste; // initialement on point vers le premier element
    printf("\n");
    while(pointeur)// tant que on n'a pas atteind la fin de la liste
        {
            printf("\t%d",pointeur->valeur);
            // afficher la valeur de la cellule courante
            pointeur = pointeur->suivant;
            // le pointeur pointe vers lelement suivant
        }// fin de while(pointeur)
    printf("\n");
}// fin fonction afficher_listeP



/*************************************************************************
Fonction : positionDElement
Entrées :   - (cellule* liste) : la tete d'une liste.
            - (int elem) : l'élement qu'on cherche la position

Sorties :  (int) :  - la position dans le cas normal.
                    - (-1) si la liste est vide.
                    - (0) si l'élement n'existe pas dans la liste
Description : la  fonction permet de trouver et retourner
la postion de la  première occurence d'un élement dans 
une liste s'il éxiste. 
*************************************************************************/
int positionDElement(cellule *liste,int elem)
{
    if(!liste) return ((int)-1);
    // si la liste est vide on casse la fonction
    cellule *pointeur;
    int position = 1; // la position initialisée par 1
    pointeur = liste; 
    // le pointeur courant pointe au début vers la première cellule
    while (pointeur) // tant que on n'a pas atteind la fin de la liste
        {
            if(pointeur->valeur == elem)return ((int)position);
            /* si la celluel courante contient l'element cherchée
            on retourne sa position*/
            position++;
            pointeur = pointeur->suivant;
        } // fin while (pointeur)
    return((int)0);
}// fin fonction positionDElement



/*************************************************************************
Fonction : suppPos_listeP
Entrées :   - (cellule* liste) : la tete d'une liste.
            - (int position) : la position qu'on veut supprimer
Sorties :  (cellule*) : pointeur vers la liste modifiée.
Description : la  fonction permet de supprimer un élement qui se trouve 
dans une position donnée.
*************************************************************************/
cellule* suppPos_listeP(cellule* liste,int pos){
    cellule *pointeur; // pointeur Courant
    cellule *tmp; // pointeur temporaire

    // suppression du premier élement
    if(pos == 1){
        tmp = liste;
        liste = liste->suivant;
        free(tmp);
        return((cellule *)liste);
    }

    // suppression position autre que la première
    
    //on se déplace dans la première cellule au début 
    pointeur = liste;
    // initialiser un compteur à 1
    int compteur = 1;
    /*pour supprimer une cellule il faut se déplacer dans la cellule
    qui la précède*/  
    while(pointeur->suivant)
    /*on arrête le déplacement dans les cellule dés qu'on arrive à 
    la dernière cellule sans atteindre la cellule pos-1, cela 
    signifie que la position est invlide*/ 
        {
            if (compteur == pos-1)
            /* si on est dans la cellule qui precéde celle qu'on 
            veur supprimer on commence la supression*/
                {
                    tmp = pointeur->suivant;
                    pointeur->suivant = tmp->suivant;
                    free(tmp);
                    return ((cellule *)liste);
                    /* supression faite, et on casse la fonction 
                     on retournant la nouvelle liste */
                }
            /* on n'a pas encore arrivée à pos-1 alors on se déplace 
            vers la cellule suivante*/
            compteur++;
            pointeur = pointeur->suivant; 
        
        }// fin while(pointeur->suivant)
    return ((cellule *)liste);
}

/*************************************************************************
Fonction : supprimerElement_listeP
Entrées :   - (cellule* liste) : la tete d'une liste.
            - (int val) : l'élement qu'on veut supprimer.
Sorties : la focntion retourne la liste après la suppression de l'element.
Description : la  fonction utilise la fonction positionDElement pour 
déterminer la position de l'élement qui va servir de le supprimer 
en utilisant suppPos_listeP 
*************************************************************************/
cellule *supprimerElement_listeP(cellule* liste,int val){
    int position;// la position
        // on teste si la position est valide sans aucune erreur
        if((position=positionDElement(liste,val))>0)
        // on supprime l'élement
        liste=suppPos_listeP(liste,position);
    // on retourne la nouvelle liste
    return((cellule*)liste);
}

/*************************************************************************
Fonction : suppTtOccElem_listeP
Entrées :   - (cellule* liste) : la tete d'une liste.
            - (int val) : l'élement qu'on veut supprimer.
Sorties : la focntion retourne la liste après la suppression de l'element.
Description : la  fonction utilise la fonction positionDElement pour 
déterminer la position de tous les occurences de l'élement 
et pour chaque position on utilise suppPos_listeP pour supprimer
*************************************************************************/
cellule *suppTtOccElem_listeP(cellule* liste,int val){
    int position;
    while((position=positionDElement(liste,val))>0)
        liste=suppPos_listeP(liste,position);
        // la boucle se termine dés qu'il n'y a plus d'occurences
    return((cellule*)liste);
}

/*************************************************************************
Fonction : vider_listeP
Entrées :  (cellule* liste) : la tete d'une liste.
Sorties : la focntion retourne la liste après la suppression de tous 
les élements. Pour cela on utilise un pointeur qui parcours toute la 
liste et libère l'espace alloué pour chaque cellule
*************************************************************************/
cellule *vider_listeP(cellule* liste){
    cellule *pointeur; // pointeur de parcours 
    cellule *tmp; // pointeur temporaire
    pointeur = liste;
    liste = NULL; // la liste sera vide donc sa tête aura la valeur NULL
    while(pointeur)// tant qu'il y a des cellules à libèrer
        {
            tmp = pointeur;// tmp pointera vers la cellule courante
            pointeur = pointeur->suivant;
            free(tmp);// on libère la cellule 
        }
    return ((cellule*)liste);// on retourne la nouvelle liste vide
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