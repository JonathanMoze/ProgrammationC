#ifndef ELEMENT_H
#define ELEMENT_H

typedef void* data_ptr;

typedef void (*func_ptr) (data_ptr data);

typedef int (*func_comp) (data_ptr data, data_ptr data2);

struct Element_s{
    data_ptr val;
    struct Element_s * suivant;
};

typedef struct Element_s Element_t;

Element_t * creer_element(void * val);
void liberer_element(Element_t *e);



int compare_chaine(data_ptr data1, data_ptr data2);
int compare_entier(data_ptr data1, data_ptr data2);
int compare_reel(data_ptr data1, data_ptr data2);
void affiche_entier(data_ptr data);
void affiche_reel(data_ptr data);
void affiche_chaine(data_ptr data);


#endif