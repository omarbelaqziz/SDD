#include <stdio.h>
#include <stdlib.h>
#define MaxElem 100

/* La structure qu'on va adopter pour implementater des files 
en utilisant les tableaux est la suivante :
    - un tableau d'éléments 
    - deuc entier qui vont stocker les indices de la tête 
    et de la queue.*/
typedef struct {
    int TabElem[MaxElem];   // Tableau d'élements
    int Queue;              // indice de la queue  
    int Tete;               // indice de la tête
} File;

/*  Fonction    : init_File
    Descriotion : La fonction permet d'initialiser un nouvelle
                  pile oubien de vider une pile. Ceci se fait 
                  en mettant les valuers des deux indices 
                  tete et queue à la valeur -1
    Entrée      : (File *MaFile) un pointeur sur une file 
    Sortie      : (int) un entier qui déterminera l'état 
                  de déroulement de la fonction : 
                    1 en cas normal 
                    0 si le pointeur n'éxiste pas*/

int init_file(File *MaFile)
{
    // si le pointeur n'existe pas
    if(!MaFile)return((int)0);
    // cas normale :
    MaFile->Queue = MaFile->Tete = -1;
    return((int)1);
}

/*  Fonction    : estSature
    Descriotion : La fonction permet de savoir si une file 
                  est saturée ou non 
    Entrée      : (File *MaFile) un pointeur sur une file 
    Sortie      : (int) un entier qui joue le role d'un 
                  boolien  : 
                    1 si la file est saturée  
                    0 sinon*/
int estSature_file(File MaFile)
{
    if(MaFile.Tete == ((MaFile.Queue+1)%MaxElem))return((int)1);
    return((int)0);
}



int estVide_file(File maFile)
{
    if((maFile.Queue == -1)&&(maFile.Tete == -1)) return((int)1);
    return((int)0);
}



int enfiler_file(File *maFile,int elem)
{
    // si la pile est saturée on ne peut pas enfiler
    if(estSature_file(*maFile)) return((int)0);
    // si elem est le premier élement que la file va recevoir
    if(estVide_file(*maFile))
    {
        //le premier element du tab recevera elem
        maFile->TabElem[0] = elem;  
        /* dans ce cas la queue et la tête auront 
         le même indice 0 (le premier élement est 
         lui même le dernier élement de la file) */
        maFile->Queue = maFile->Tete = 0;
        return((int)1);
    }
    // cas normal :
    maFile->TabElem[++maFile->Queue%MaxElem] = elem;
    return((int)1);
    
}

int defiler_file(File *maFile)
{
    int init;
    if(!maFile) return((int)-1);
    if(estVide_file(*maFile)) return((int)0);
    if(maFile->Queue == maFile->Tete) 
        {
            init = init_file(maFile);
            return((int)1);
        }
    maFile->Tete=(((maFile->Tete)+1)%MaxElem);
    return((int)1);
}

int consulter_teteFile(File maFile)
{
    if(estVide_file(maFile))
    {
        printf("\n Attention, la File est vide.");
        return((int)-99999);
    }
    return((int)maFile.TabElem[maFile.Tete]);
}

File * afficher_file(File *maFile)
{
    int init,tmp;
    File *NF;
    NF = malloc(sizeof(File));
    init = init_file(NF);
    printf("\n");
    while(!estVide_file(*maFile))
    {
        
        tmp = consulter_teteFile(*maFile);
        printf("%d\t",tmp);
        init = enfiler_file(NF,tmp);
        init = defiler_file(maFile);
    }
    free(maFile);
    return((File *)NF);
  
}

void main()
{
    int test;
    File Of;
    File *NF;
    NF = malloc(sizeof(File));
    test = init_file(NF);
    printf("\n\t Queue = %d \t Tete = %d",NF->Queue,NF->Tete);
    for(int i = 0 ; i < 10 ; i++){
        test = enfiler_file(NF,i);
    }
    printf("\n\t Queue = %d \t Tete = %d",NF->Queue,NF->Tete);
    //if(estSature_file(Of)) printf("\n la file est saturee");
    NF=afficher_file(NF);
    printf("\n\t Queue = %d \t Tete = %d",NF->Queue,NF->Tete);
    NF=afficher_file(NF);
    printf("\n\t Queue = %d \t Tete = %d",NF->Queue,NF->Tete);



    /*test=enfiler_file(Of,56);
    if(test)printf("\n  \t Queue = %d \t Tete = %d"
                    "\n la tete est = %d",Of->Queue,Of->Tete,consulter_teteFile(Of));
    test=enfiler_file(Of,5897);
    test=enfiler_file(Of,111117);
    test=enfiler_file(Of,12);
    test=enfiler_file(Of,12);
    test=enfiler_file(Of,167);
    if(test)printf("\n  \t Queue = %d \t Tete = %d"
                    "\n la tete est = %d",Of->Queue,Of->Tete,consulter_teteFile(Of));
     afficher_file(Of);
    test = defiler_file(Of);
    if(test)printf("\n  \t Queue = %d \t Tete = %d"
                    "\n la tete est = %d",Of->Queue,Of->Tete,consulter_teteFile(Of));
    afficher_file(Of);
    if(test)printf("\n  \t Queue = %d \t Tete = %d"
                    "\n la tete est = %d",Of->Queue,Of->Tete,consulter_teteFile(Of));*/



}