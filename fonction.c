#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <conio.h>
#include <windows.h>
#include "fonction.h"

struct Joueur{
 int numj;
 char nom[30];
 char symb;
};
static int premier,gain1,gain2;
static char grille[LIGNES][COLONNES];
static char symb1,symb2;
static Joueur joueur1, joueur2;



//gotoxy
void gotoxy(int x, int y)
{
    HANDLE hConsoleOutput;
    COORD dwCursorPosition;
    fflush(stdout);
    dwCursorPosition.X = x;
    dwCursorPosition.Y = y;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
}

//grillepuissance4
void grillepuissance4(int x, int y, int l, int h){
    int i,j,t=0 , n=0;


for(i=2;i<l;i=i+4)
    {
        gotoxy(x+i,y-1);
        printf("%d",n);
        n=n+1;
    }
    for(i=1;i<h;i=i+2)
    {
        gotoxy(x-1,y+i);
        printf("%d",t);
        t+=1;
    }
    gotoxy(x,y);
    printf("%c",218);
    gotoxy(x+l,y);
    printf("%c",191);
    gotoxy(x,y+h);
    printf("%c",192);
    gotoxy(x+l,y+h);
    printf("%c",217);
    for(i=4;i<l;i=i+4)//pour tracer les deux grandes lignes horizontales;mod
    {
        gotoxy(x+i,y);
        printf("%c",194);
        gotoxy(x+i,y+h);
        printf("%c",193);
    }
    for(i=0;i<=h;i=i+2)//
    {
        for(j=1;j<l;j=j+2)
        {
            gotoxy(x+j,y+i);
            printf("%c",196);
        }

    }
    for(i=0;i<=h;i=i+2)//new
    {
        for(j=2;j<l;j=j+4)
        {
            gotoxy(x+j,y+i);
            printf("%c",196);
        }

    }
    for(i=2;i<h;i=i+2)//mod
    {
        gotoxy(x,y+i);
        printf("%c",195);
        gotoxy(x+l,y+i);
        printf("%c",180);
    }
    for(i=4;i<l;i=i+4)
    {
        for(j=2;j<h;j=j+2)//
        {
            gotoxy(x+i,y+j);
            printf("%c",197);
        }
    }
    for(i=0;i<=l;i=i+4)
    {
        for(j=1;j<=h;j=j+2)
        {
           gotoxy(x+i,y+j);
           printf("%c",179);

        }
    }


}


// init_jeu
void init_jeu(){
   int cmp, MAX=2, MIN=1, colone;

    do{
       printf("Nom du Joueur 1: ");
       scanf("%s",&joueur1.nom);
       //nom1=joueur1.nom;

       printf("Nom du Joueur 2: ");
       scanf("%s",&joueur2.nom);
       //nom2=joueur2.nom;

       cmp = strcmp(joueur1.nom,joueur2.nom);
       if(cmp==0)
        printf("\n SVP Entrer des noms differents!! \n");
    }
    while(cmp == 0);

   srand(time(NULL));
   premier = (rand() % (MAX - MIN + 1)) + MIN;
    switch(premier){
    case 1:
        printf("Le joueur qui commence est: %s",joueur1.nom);
        do{
            printf("\nQuel est votre symbole joueur1: (O ou X)? : ");
            scanf("%s",&joueur1.symb);

        }while(joueur1.symb!= 'X' && joueur1.symb !='O');


        if(joueur1.symb =='X'){
            joueur2.symb= 'O';

        }
        else
            joueur2.symb= 'X';


        system("cls");
        grillepuissance4(8,2,28,12);
        gotoxy(0,0);
        printf("\n\n\n\n\t\t\t\t\t\t JEU DE PUISSANCE 4");
        printf("\t\t\t\t\t\t \n");
        printf("\n\t\t\t\t\t\t le symbole de %s est: %c",joueur1.nom,joueur1.symb);
        printf("\n\t\t\t\t\t\t le symbole de %s est: %c",joueur2.nom,joueur2.symb);
        printf("\t\t\t\t\t\t \n\n\n\n");
        printf("\n\t\t\t\t\t\t C'est %s qui commence le Jeu",joueur1.nom);

        break;
    default:
        printf("Le joueur qui commence la partie est: %s",joueur2.nom);

        do{
            printf("\nQuel est votre symbole joueur2: (O ou X)? : ");
            scanf("%s",&joueur2.symb);

        }while(joueur2.symb!= 'X' && joueur2.symb !='O');

        if(joueur2.symb =='X'){
                joueur1.symb = 'O';

        }
        else
            joueur1.symb = 'X';


        system("cls");
        grillepuissance4(8,2,28,12);
        gotoxy(0,0);
        printf("\n\n\n\n\t\t\t\t\t\t JEU DE PUISSANCE 4");
        printf("\t\t\t\t\t\t \n");
        printf("\n\t\t\t\t\t\t le symbole de %s est: %c",joueur1.nom,joueur1.symb);
        printf("\n\t\t\t\t\t\t le symbole de %s est: %c",joueur2.nom,joueur2.symb);
        printf("\t\t\t\t\t\t \n\n\n\n");
        printf("\n\t\t\t\t\t\t C'est %s qui commence le Jeu",joueur2.nom);


    }
}
// Jouer_colonne
 int jouer_colonne(int colonne, int joueur_num) {
    int a,b , ok ,i,j,succes;
    char val ;
    int ligne=6;


do{

    if(grille[(ligne-1)][colonne]==0){

        if(joueur_num==1)
            grille[ligne-1][(colonne)]= joueur1.symb;
        else
            grille[ligne-1][(colonne)]= joueur2.symb;

        val = grille[ligne-1][(colonne)] ;
        a =((4*colonne)+10) ;
        b=((2*ligne)+1) ;
        gotoxy(a,b) ;
        printf("%c",val);
        ok = 1;
        succes=1;
    }
    else{
        ok=0;
        ligne--;
                if(ligne==0){
                    succes=0;
                    ok=1;
                }

     }



}while (ok==0);

return succes;
 }

int verif_gain(char matrice[6][7]){
 int i,j,succes=0;

for(j=0;j<7;j++){
	for(i=5;i>2;i--){
    if( (grille[i][j]==grille[i-1][j])&& ( grille[i-1][j]==grille[i-2][j]) && (grille[i-2][j]==grille[i-3][j])
                        &&(grille[i][j]!=0) &&(grille[i-1][j]!=0) &&(grille[i-2][j]!=0) &&(grille[i-3][j]!=0)){

					succes=1;
		}
	}

}
for(i=5;i>=0;i--){
	for(j=0;j<4;j++){
        if( (grille[i][j]==grille[i][j+1])&& (grille[i][j+1]==grille[i][j+2]) && (grille[i][j+2]==grille[i][j+3])
                        &&(grille[i][j]!=0) &&(grille[i][j+1]!=0) &&(grille[i][j+2]!=0) &&(grille[i][j+3]!=0)  ){

					succes=1;
		}
	}

}
for(i=5;i>2;i--){
	for(j=0;j<4;j++){
		if( (grille[i][j]==grille[i-1][j+1])&& (grille[i-1][j+1]==grille[i-2][j+2]) && (grille[i][j]==grille[i-3][j+3])
                        &&(grille[i][j]!=0)  &&(grille[i-1][j+1]!=0) &&(grille[i-2][j+2]!=0) &&(grille[i-3][j+3]!=0)){

					succes=1;
		}
	}

}
for(i=5;i>2;i--){
	for(j=6;j>2;j--){
		if( (grille[i][j]==grille[i-1][j-1])&& (grille[i-1][j-1]==grille[i-2][j-2]) && (grille[i-2][j-2]==grille[i-3][j-3])
                        &&(grille[i][j]!=0)  &&(grille[i-1][j-1]!=0) &&(grille[i-2][j-2]!=0) &&(grille[i-3][j-3]!=0)){

					succes=1;
		}
	}

}

return succes ;

}






void jouer_aujeu(){
    int colonne, i,j ,rx=8 ,ry =2 , num ,a ,b,calcul,jouer=0 ,a_jouer;
    char joueur_actuel[30];
    int recom, jouerpre=0, jouerde=0;


grillepuissance4(POSITION_X,POSITION_Y,28,12);
        gotoxy(0,16);
    init_jeu();

     for(i=0;i<6;i++){
            for(j=0;j<7;j++)
                grille[i][j]=0;
        }

    gotoxy(0,16);
        do{
            if(premier==1){
                        do{
                        gotoxy(0,16);
                        printf("A %s d'entrer une colonne: ",joueur1.nom);
                        scanf("%d",&colonne);
                        if(colonne>7){
                            gotoxy(0,17);
                            printf("%s entrer une colonne valide: ",joueur1.nom);
                            scanf("%d",&colonne);
                        }
                        }while(colonne>6);

                         a_jouer= jouer_colonne(colonne,1) ;

                         if(a_jouer==0){
                             gotoxy(0,17);
                             printf("%s entrer une colonne valide: ",joueur1.nom);
                              scanf("%d",&colonne);
                            jouer_colonne(colonne,1) ;
                         }

                    calcul=verif_gain(grille[6][7]);
                       if(calcul==1)
                          {
                               gotoxy(0,18);
                               printf("\n %s a gagne au %d eme coup\n",joueur1.nom,jouer+1);
                               return 1 ;
                       }
                       do{
                        gotoxy(0,20);
                        printf("A %s d'entrer une colonne: ",joueur2.nom);
                        scanf("%d",&colonne);
                        if(colonne>7){
                            gotoxy(0,21);
                            printf("%s Entrer une colonne valide ",joueur2.nom);
                            scanf("%d",&colonne);
                        }
                        }while(colonne>6);
                         a_jouer= jouer_colonne(colonne,2) ;

                         if(a_jouer==0){
                             gotoxy(0,21);
                             printf("%s Entrer une colonne valide ",joueur2.nom);
                              scanf("%d",&colonne);
                            jouer_colonne(colonne,2) ;
                         }

                    calcul=verif_gain(grille[6][7]);
                       if(calcul==1)
                          {
                               gotoxy(0,22);
                               printf("\n %s  a gagne au %d eme coup\n",joueur2.nom,jouer+1);
                               return 1 ;
                       }
                }
                else{
                        do{
                        gotoxy(0,16);
                        printf("A %s d'entrer une colonne: ",joueur2.nom);
                        scanf("%d",&colonne);
                      if(colonne>7){
                            gotoxy(0,17);
                            printf("%s Entrer une colonne valide ",joueur2.nom);
                            scanf("%d",&colonne);
                        }
                        }while(colonne>6);
                    a_jouer= jouer_colonne(colonne,2) ;

                         if(a_jouer==0){
                             gotoxy(0,17);
                             printf("%s Entrer une colonne valide ",joueur2.nom);
                              scanf("%d",&colonne);
                            jouer_colonne(colonne,2) ;
                         }
                    calcul=verif_gain(grille[6][7]);
                       if(calcul==1)
                          {
                               gotoxy(0,20);
                               printf("\n %s  a gagne au %d eme coup\n",joueur2.nom,jouer+1);
                               return 1 ;
                       }
                       do{
                        gotoxy(0,19);
                        printf("A %s d'entrer une colonne: ",joueur1.nom);
                        scanf("%d",&colonne);
                      if(colonne>7){
                            gotoxy(0,18);
                            printf("%s Entrer une colonne valide ",joueur1.nom);
                            scanf("%d",&colonne);
                        }
                        }while(colonne>6);
                        a_jouer= jouer_colonne(colonne,1) ;

                         if(a_jouer==0){
                             gotoxy(0,18);
                             printf("%s Entrer une colonne valide ",joueur1.nom);
                              scanf("%d",&colonne);
                            jouer_colonne(colonne,1) ;
                         }
                    calcul=verif_gain(grille[6][7]);
                       if(calcul==1)
                          {
                            gotoxy(0,20);
                            printf("\n %s gagne au %d eme coup\n",joueur1.nom,jouer+1);
                               return 1 ;
                       }
                }

                jouer++;

        } while(jouer<42);



return 0 ;
}









