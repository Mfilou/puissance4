#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "fonction.h"





int main(){
    char recom;

    do{
            jouer_aujeu();

     do
        { fflush(stdin);
        gotoxy(0,24);
         printf("\t\tVoulez-vous recommencer ? (o/n) : ");
         scanf("%c",&recom);
        }while(recom!='o' && recom!='n');
        if(recom=='o')
            system("cls");

        printf("\n");
 }while (recom=='o');




    // int rejouer ;

   // do {
   //   rejouer = jouer_aujeu();
   // }while(rejouer==1)



    


    return 0;
}
