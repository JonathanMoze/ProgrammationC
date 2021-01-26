#include "Element.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Element_t *creer_element(void * val){
    Element_t *e = (Element_t *) malloc(sizeof(Element_t));
    e->val = val;
    e->suivant = NULL;
    return e;
}

void liberer_element(Element_t *e){
    free(e->val);
    free(e);
}



void affiche_reel(data_ptr data)
{
    float *val = (float *)data;
    printf("%f ", *val);
}


void affiche_entier(data_ptr data)
{
    int *val = (int *)data;
    printf("%d ", *val);
}

void affiche_chaine(data_ptr data)
{
    char *val = (char *) data;
    printf("%s - ", val);
}


int compare_entier(data_ptr data1, data_ptr data2)
{
    int *val1 = (int *)data1;
    int *val2 = (int *)data2;

    return *val1 - *val2;
}

int compare_reel(data_ptr data1, data_ptr data2)
{
    float *val1 = (float *)data1;
    float *val2 = (float *)data2;

    return *val1 - *val2;
}

int compare_chaine(data_ptr data1, data_ptr data2)
{
    char *val1 = (char *) data1;
    char *val2 = (char *) data2;

    return strcmp(val1, val2);
}


