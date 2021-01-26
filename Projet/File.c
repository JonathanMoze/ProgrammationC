#include <stdlib.h>
#include <stdio.h>

#include "File.h"

File_t* creer_file(){
    File_t *f = (File_t * ) malloc(sizeof(File_t));
    f->premier = NULL;
    f->dernier = NULL;
    f->taille = 0;

    return f;
}

void enfiler(File_t* f, void * v){
    Element_t *e = creer_element(v);
    if(f->taille == 0){
        f->premier = e;
    }
    else{
        f->dernier->suivant = e;
    }
    f->dernier = e;
    f->taille++;
}

void* defiler(File_t* f){
    Element_t *e = f->premier;
    f->premier = e->suivant;
    f->taille--;
    void * val = e->val;
    free(e);
    return val;
}

int file_taille(const File_t *f){
    return f->taille;
}

int file_vide(const File_t *f){
    return f->taille == 0;
}

void liberer_file(File_t *f){
    Element_t * e = f->premier;
    while(e != NULL){
        Element_t * suivant = e->suivant;
        liberer_element(e);
        e = suivant;
    }

    free(f);
}

void afficher_file(File_t *f, func_ptr affiche){
    Element_t *e = f->premier;
    while(e != NULL){
        (*affiche)(e->val);
        e = e->suivant;
    }
    printf("\n");
}