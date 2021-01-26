#include <stdlib.h>
#include <stdio.h>

#include "Liste.h"



Liste_t *creer_liste()
{
    Liste_t *l = (Liste_t *)malloc(sizeof(Liste_t));
    l->premier = NULL;
    l->taille = 0;

    return l;
}

void *adresse_premier(Liste_t *l)
{
    return l->premier;
}

void *adresse_suivant(void *adr)
{
    return ((Element_t *)adr)->suivant;
}

void *valeur_element(void *adr)
{
    return ((Element_t *)adr)->val;
}

void modifier_valeur(void *adr, void *val)
{
    Element_t *e = (Element_t *)adr;
    e->val = val;
}

void inserer_en_tete(Liste_t *l, void *val)
{
    Element_t *nouv = creer_element(val);
    if (l->taille != 0)
    {
        nouv->suivant = l->premier;
    }
    l->premier = nouv;
    l->taille++;
}

void inserer_apres(Liste_t *l, void *adr, void *val)
{
    Element_t *e = creer_element(val);
    e->suivant = ((Element_t *)adr)->suivant;
    ((Element_t *)adr)->suivant = e;
    l->taille++;
}

void *supprimer_en_tete(Liste_t *l)
{
    void *val = l->premier->val;
    Element_t *e = l->premier->suivant;
    free(l->premier);
    l->premier = e;
    l->taille--;
    return val;
}

void *supprimer_apres(Liste_t *l, void *adr)
{
    Element_t *e = ((Element_t *)adr);
    Element_t *suivant = e->suivant;
    void *val = suivant->val;
    e->suivant = suivant->suivant;
    free(suivant);
    l->taille--;
    return val;
}

int liste_taille(const Liste_t *l)
{
    return l->taille;
}

void afficher_liste(const Liste_t *l, func_ptr affiche)
{
    printf("La liste : \n");
    if (l->taille != 0)
    {
        Element_t *e = l->premier;
        while (e != NULL)
        {
            (*affiche)(e->val);
            e = e->suivant;
        }
        printf("\n");
    }
    else
    {
        printf("La liste est vide. \n");
    }
}

void liberer_liste(Liste_t *l)
{
    Element_t *e = l->premier;
    while (e != NULL)
    {
        Element_t *suivant = e->suivant;
        liberer_element(e);
        e = suivant;
    }
    free(l);
}

Liste_t *fusion(Liste_t *l1, Liste_t *l2, func_comp compare)
{
    Liste_t *l = creer_liste();
    void *adr = NULL;
    if (l1 != NULL && l2 != NULL)
    {
        while ((l1->premier != NULL && l2->premier != NULL))
        {
            if ((*compare)(valeur_element(l1->premier), valeur_element(l2->premier)) < 0)
            {
                adr = inserer_et_avancer(l1, l, adr);
            }
            else
            {
                adr = inserer_et_avancer(l2, l, adr);
            }
        }
        while (l1->premier != NULL && l1 != NULL)
        {
            adr = inserer_et_avancer(l1, l, adr);
        }
        while (l2->premier != NULL && l2 != NULL)
        {
            adr = inserer_et_avancer(l2, l, adr);
        }
    }
    else
    {
        if (l1 == NULL)
        {
            l = l2;
        }
        else
        {
            l = l1;
        }
    }

    liberer_liste(l1);
    liberer_liste(l2);

    return l;
}

void *inserer_et_avancer(Liste_t *l_in, Liste_t *l_out, void *adr)
{
    void *val = valeur_element(l_in->premier);
    supprimer_en_tete(l_in);
    if (adr == NULL)
    {
        inserer_en_tete(l_out, val);
        adr = l_out->premier;
    }
    else
    {
        inserer_apres(l_out, adr, val);
        adr = adresse_suivant(adr);
    }
    return adr;
}

Liste_t *decoupe_liste(Liste_t *l1)
{
    Liste_t *liste_de_liste = creer_liste();
    if (l1->taille > 1)
    {
        Liste_t *l2 = creer_liste();
        int milieu = liste_taille(l1) / 2;
        Element_t *e_milieu = l1->premier;

        for (int i = 0; i < milieu - 1; ++i)
        {
            e_milieu = e_milieu->suivant;
        }

        l2->premier = e_milieu->suivant;
        e_milieu->suivant = NULL;

        l1->taille = milieu;
        Element_t *tmp = l2->premier;
        while (tmp != NULL)
        {
            l2->taille++;
            tmp = tmp->suivant;
        }
        inserer_en_tete(liste_de_liste, l2);
        inserer_en_tete(liste_de_liste, l1);
    }
    else if (l1->taille == 1)
    {
        inserer_en_tete(liste_de_liste, l1);
        inserer_apres(liste_de_liste, adresse_premier(liste_de_liste), NULL);
    }
    else
    {
        inserer_en_tete(liste_de_liste, NULL);
        inserer_en_tete(liste_de_liste, NULL);
    }

    return liste_de_liste;
}

Liste_t *tri_fusion(Liste_t *l, func_comp compare)
{
    if (l->taille > 1)
    {
        Liste_t *liste_de_liste = decoupe_liste(l);


        Liste_t *liste_1 = (Liste_t *)valeur_element(adresse_premier(liste_de_liste));
        Liste_t *liste_2 = (Liste_t *)valeur_element(adresse_suivant(adresse_premier(liste_de_liste)));

        free(liste_de_liste);

        liste_1 = tri_fusion(liste_1, compare);
        liste_2 = tri_fusion(liste_2, compare);

        Liste_t *fusionne = fusion(liste_1, liste_2, compare);


        return fusionne;
    }
    else{
        return l;
    }
}

