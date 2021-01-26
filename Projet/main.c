#include "File.h"
#include "Liste.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>



void remplir_file(File_t *f)
{
    float *i = malloc(sizeof(float));
    float *j = malloc(sizeof(float));
    float *l = malloc(sizeof(float));
    *i = 0, *j = 3, *l = 10;
    enfiler(f, i);
    enfiler(f, j);
    enfiler(f, l);
    afficher_file(f, &affiche_reel);
}

int main(void)
{
/*
    printf("----- TEST DES FILES ----- \n");

    File_t *f = creer_file();
    remplir_file(f);
    afficher_file(f, &affiche_reel);
    liberer_file(f);
    f = NULL;

    printf("----- TEST DE FUSION  ----- \n");

    int *a = malloc(sizeof(int));
    *a = 4;
    int *b = malloc(sizeof(int));
    *b = 7;
    int *c = malloc(sizeof(int));
    *c = 9;
    Liste_t *l = creer_liste();
    inserer_en_tete(l, a);
    inserer_apres(l, adresse_premier(l), b);
    inserer_apres(l, adresse_suivant(adresse_premier(l)), c);

    printf("Liste 1 :");
    afficher_liste(l, &affiche_entier);

    int *x = malloc(sizeof(int));
    *x = 1;
    int *y = malloc(sizeof(int));
    *y = 5;
    int *z = malloc(sizeof(int));
    *z = 10;

    Liste_t *l2 = creer_liste();
    inserer_en_tete(l2, z);
    inserer_en_tete(l2, y);
    inserer_en_tete(l2, x);

    printf("Liste 2 :");
    afficher_liste(l2, &affiche_entier);

    Liste_t *ltest = malloc(sizeof(Liste_t));

    ltest = fusion(l, l2, &compare_entier);

    printf("La liste fusionnée : ");
    afficher_liste(ltest, &affiche_entier);


    printf(" ----- TEST DECOUPE LISTE -----\n");

    Liste_t *les_listes = decoupe_liste(ltest);

    Liste_t *liste_1 = valeur_element(adresse_premier(les_listes));
    Liste_t *liste_2 = valeur_element(adresse_suivant(adresse_premier(les_listes)));

    printf("Liste 1 :");
    afficher_liste(liste_1, &affiche_entier);

    printf("Liste 2 :");
    afficher_liste(liste_2, &affiche_entier);

*/

    printf(" ----- TEST TRIFUSION -----\n");
    /* //Test du tri avec int
    int *x = malloc(sizeof(int));
    *x = 1;
    int *y = malloc(sizeof(int));
    *y = 5;
    int *z = malloc(sizeof(int));
    *z = 10;

    int *a = malloc(sizeof(int));
    *a = 4;
    int *b = malloc(sizeof(int));
    *b = 7;
    int *c = malloc(sizeof(int));
    *c = 9;*/


   //test du tri avec chaines de charactères : fonctionne mais avec une erreur de segmentation à la fin, surement sur les libérer_liste
   // qui tentent de libérer les valeurs de type char*
    char *x = "Test";
    char *y = "Bonjour";
    char *z = "Zorro";

    char *a = "Frelon";
    char *b = "Tomate";
    char *c = "Oiseau";


    Liste_t* test_tri = creer_liste();
    inserer_en_tete(test_tri, y);
    inserer_en_tete(test_tri, a);
    inserer_en_tete(test_tri, z);
    inserer_en_tete(test_tri, x);
    inserer_en_tete(test_tri, c);
    inserer_en_tete(test_tri, b);

    printf("AVANT :\n");
    afficher_liste(test_tri, &affiche_chaine);
    printf("\n");
    printf("APRES : \n");
    test_tri = tri_fusion(test_tri, &compare_chaine);
    afficher_liste(test_tri, &affiche_chaine);


    liberer_liste(test_tri);

    return EXIT_SUCCESS;
}
