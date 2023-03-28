#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED



#define LIGNES 6
#define COLONNES 7


#define POSITION_X 8
#define POSITION_Y 2




typedef struct Joueur Joueur;

void gotoxy(int x, int y);
void grillepuissance4(int x, int y, int l, int h);
void init_jeu();
int jouer_colonne(int colonne, int joueur_num);

int verif_gain(char matrice[6][7]);
void jouer_aujeu();


#endif // FONCTION_H_INCLUDED




