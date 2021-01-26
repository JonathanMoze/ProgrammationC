#include <gtest/gtest.h>
#include "Liste.h"

TEST(Liste, creer_liste)
{
    Liste_t *l = creer_liste();

    //vérifie que la liste est crée
    ASSERT_FALSE(l == NULL);

    //vérifie que la liste n'a pas encore d'éléments
    ASSERT_TRUE(l->premier == NULL);

    liberer_liste(l);
}

TEST(Liste, valeur_element)
{
    int *i = (int *)malloc(sizeof(int));
    *i = 54;
    Liste_t *l = creer_liste();
    inserer_en_tete(l, i);

    //vérifie que la valeur de l'élément est bien 54
    ASSERT_EQ(*((int *)valeur_element(l->premier)), 54);

    liberer_liste(l);
}

TEST(Liste, modifier_valeur)
{
    int *i = (int *)malloc(sizeof(int));
    *i = 54;
    Liste_t *l = creer_liste();
    inserer_en_tete(l, i);

    //vérifie que la valeur de l'élément avant la modif est 54 
    ASSERT_EQ(*((int *)valeur_element(l->premier)), 54);
    int *j = (int *)malloc(sizeof(int));
    *j = 6;
    modifier_valeur(l->premier, j);

    //vérifie que la valeur de l'element après la modif est 6
    ASSERT_EQ(*((int *)valeur_element(l->premier)), 6);


    free(i);
    liberer_liste(l);
}

TEST(Liste, inserer_en_tete)
{
    int *i = (int *)malloc(sizeof(int));
    *i = 54;
    Liste_t *l = creer_liste();
    inserer_en_tete(l, i);

    //vérifie que l'élément en tête est 54
    ASSERT_EQ(*((int *)valeur_element(l->premier)), 54);
    int *j = (int *)malloc(sizeof(int));
    *j = 6;
    inserer_en_tete(l, j);

    //vérifie que l'élément en tête est maintenant 6
    ASSERT_EQ(*((int *)valeur_element(l->premier)), 6);

    //vérifie que 54 est passé en 2e element de la liste
    ASSERT_EQ(*((int *)valeur_element(l->premier->suivant)), 54);

    liberer_liste(l);
}

TEST(Liste, inserer_apres)
{
    int *i = (int *)malloc(sizeof(int));
    *i = 54;
    Liste_t *l = creer_liste();
    inserer_en_tete(l, i);

    int *j = (int *)malloc(sizeof(int));
    *j = 6;
    inserer_apres(l, l->premier, j);

    //vérifie que 54 est toujours premier
    ASSERT_EQ(*((int *)valeur_element(l->premier)), 54);

    //vérifie que 6 est placé après 54
    ASSERT_EQ(*((int *)valeur_element(l->premier->suivant)), 6);

    liberer_liste(l);
}

TEST(Liste, supprimer_en_tete)
{
    int *i = (int *)malloc(sizeof(int));
    *i = 54;
    Liste_t *l = creer_liste();
    inserer_en_tete(l, i);

    int *j = (int *)malloc(sizeof(int));
    *j = 6;
    inserer_apres(l, l->premier, j);

    int *val = (int *)supprimer_en_tete(l);

    //vérifie que l'element supprimé est bien 54 qui etait en tête
    ASSERT_EQ(*val, 54);

    //vérifie que l'élement maintenant en tête est 6
    ASSERT_EQ(*((int *)valeur_element(l->premier)), 6);

    //vérifie que la taille de la liste est 1
    ASSERT_TRUE(l->taille == 1);

    free(val);
    liberer_liste(l);
}

TEST(Liste, supprimer_apres)
{
    int *i = (int *)malloc(sizeof(int));
    *i = 54;
    Liste_t *l = creer_liste();
    inserer_en_tete(l, i);

    int *j = (int *)malloc(sizeof(int));
    *j = 6;
    inserer_apres(l, l->premier, j);

    int *val = (int *)supprimer_apres(l, l->premier);

    //vérifie que l'element supprimé est bien 6 qui etait après le premier element
    ASSERT_EQ(*val, 6);

    //vérifie que l'élement en tête est toujours 54
    ASSERT_EQ(*((int *)valeur_element(l->premier)), 54);

    //vérifie que la taille de la liste est 1
    ASSERT_TRUE(l->taille == 1);

    free(val);
    liberer_liste(l);
}

TEST(Liste, liste_taille)
{
    int *i = (int *)malloc(sizeof(int));
    *i = 54;
    Liste_t *l = creer_liste();
    inserer_en_tete(l, i);

    //vérifie que la taille est 1
    ASSERT_TRUE(l->taille == 1);


    int *j = (int *)malloc(sizeof(int));
    *j = 6;
    inserer_apres(l, l->premier, j);

    //vérifie que la taille est 2
    ASSERT_TRUE(l->taille == 2);

    int *k = (int *)malloc(sizeof(int));
    *k = 1;
    inserer_apres(l, l->premier, k);

    //vérifie que la taille est 3
    ASSERT_TRUE(l->taille == 3);

    int *val = (int *)supprimer_en_tete(l);

    //vérifie que la taille est revenue à 2
    ASSERT_TRUE(l->taille == 2);

    free(val);
    liberer_liste(l);
}