#include <stdio.h>
#include <stdlib.h>

typedef struct noeud{
    int val;
    struct noeud *suivant;
} cellule;

typedef struct{
    cellule *tete;
    cellule *queue;
}PFile;

int init_PFile(PFile *maFile)
{
    if(!maFile)return((int)0);
    maFile->tete = maFile->queue = NULL;
    return((int)1);
}

PFile *creer_PFile()
{
    int init;
    PFile * nouvelFile;
    nouvelFile = malloc(sizeof(PFile));
    if(!nouvelFile)
    {
        printf("\n pas assez de memoire");
        exit(-1);
    }
    init=init_PFile(nouvelFile));
    return((PFile *)nouvelFile);
}

int estvide_PFile(PFile *maFile)
{
    if(!maFile)if(!maFile)return((int)-1);
    if(maFile->tete == NULL)return((int)1);
    return((int)1);
}

PFile *Enfiler_PFile(PFile *maFile,int valeur)
{
    cellule *nouvelElem;
    nouvelElem = malloc(sizeof(cellule));
    if(!nouvelElem)
    {
        printf("\n pas assez de memoire");
        exit(-1);
    }
    nouvelElem->val = valeur;
    nouvelElem->suivant = NULL;

    if(!maFile)maFile = creer_PFile();
    if(estvide_PFile(maFile))
    {
        maFile->queue = maFile->tete = nouvelElem;
        return((PFile *)maFile);
    }
    maFile->queue->suivant = nouvelElem;
    maFile->queue = nouvelElem;
}

PFile *Defiler_PFile(PFile *maFile)
{
    cellule *temp;
    if(!maFile)return((PFile*)maFile);
    if(estvide_PFile(maFile))return((PFile*)maFile);
    temp = maFile->tete;
    maFile->tete = maFile->tete->suivant;
    free(temp); 
    return((PFile*)maFile);
}