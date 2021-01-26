#ifndef FILE_H
#define FILE_H
#include "Element.h"



struct File_s {
    Element_t* premier;
    Element_t* dernier;
    int taille;
};

typedef struct File_s File_t;


File_t* creer_file();
void enfiler(File_t* f, void * v);
void* defiler(File_t* f);
int file_taille(const File_t* f);
int file_vide(const File_t* f);
void liberer_file(File_t* f);

void afficher_file(File_t *f, func_ptr affiche);

#endif