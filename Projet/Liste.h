#ifndef LISTE_H
#define LISTE_H

#include "Element.h"
#include <stdio.h>
#include <stdlib.h>

struct Liste_s{
    Element_t* premier;
    int taille;
};

typedef struct Liste_s Liste_t;

Liste_t *creer_liste();

void* adresse_premier(Liste_t *l);
void* adresse_suivant(void* adr);

void* valeur_element(void* adr);
void modifier_valeur(void* adr, void* val);

void inserer_en_tete(Liste_t *l, void* val);
void inserer_apres(Liste_t *l, void* adr, void* val);

void* supprimer_en_tete(Liste_t *l);
void* supprimer_apres(Liste_t *l, void* adr);

int liste_taille(const Liste_t *l);

void afficher_liste(const Liste_t *l, func_ptr affiche);
void liberer_liste(Liste_t *l);


Liste_t *fusion(Liste_t *l1, Liste_t *l2, func_comp compare);
void* inserer_et_avancer(Liste_t *l_in, Liste_t *l_out, void* adr);
Liste_t* decoupe_liste(Liste_t *l);
Liste_t* tri_fusion(Liste_t *l, func_comp compare);



#endif