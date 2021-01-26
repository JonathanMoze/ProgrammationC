#include <gtest/gtest.h>
#include "File.h"

TEST(File, creer_file)
{
    File_t *f = creer_file();
    ASSERT_FALSE(f == NULL);
    ASSERT_TRUE(f->premier == NULL);
    ASSERT_TRUE(f->dernier == NULL);
    liberer_file(f);
}

TEST(File, enfiler)
{
    File_t *f = creer_file();
    ASSERT_EQ(file_taille(f), 0);
    for(int i=0; i<10; i++){
        int* ii = (int *)malloc(sizeof(int));
        *ii = i;
        enfiler(f, ii);
        ASSERT_EQ(*((int *)f->dernier->val), i);
    }

    liberer_file(f);
}

TEST(File, defiler)
{
    File_t *f = creer_file();

    int* i = (int *)malloc(sizeof(int));
    int* i2 = (int *)malloc(sizeof(int));
    int* i3 = (int *)malloc(sizeof(int));
    int* i4 = (int *)malloc(sizeof(int));


    *i=0, *i2=1, *i3=2, *i4=3;
    enfiler(f, i);
    enfiler(f, i2);
    enfiler(f, i3);
    enfiler(f, i4);

    for(int i=0; i<4; ++i){
        int *val = (int*) defiler(f);
        ASSERT_EQ(*val, i);
        free(val);
    }

    liberer_file(f);
}

TEST(File, file_taille)
{
    File_t *f = creer_file();
    
    int* i = (int *)malloc(sizeof(int));
    int* i2 = (int *)malloc(sizeof(int));
    int* i3 = (int *)malloc(sizeof(int));
    int* i4 = (int *)malloc(sizeof(int));


    *i=0, *i2=1, *i3=2, *i4=3;
    enfiler(f, i);
    enfiler(f, i2);
    enfiler(f, i3);
    enfiler(f, i4);

    ASSERT_EQ(file_taille(f), 4);


    liberer_file(f);
}

TEST(File, file_vide)
{
    File_t * f = creer_file();
    ASSERT_TRUE(file_vide(f));

    int* i = (int *)malloc(sizeof(int));
    *i=1;
    enfiler(f,i);
    ASSERT_FALSE(file_vide(f));
    defiler(f);
    ASSERT_TRUE(file_vide(f));
    free(i);
    liberer_file(f);
}