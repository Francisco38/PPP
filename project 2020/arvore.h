#ifndef PROJECT_2020_ARVORE_H
#define PROJECT_2020_ARVORE_H
#define LINHA 26
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

struct pessoa {
    char nome[LINHA-5];
    int divida;
};

struct tnode{
    struct pessoa gente;
    struct tnode *left;
    struct tnode *right;
}*raiz,*raiz2;

//variaveis
FILE * fich1 ;
FILE * fich2 ;
FILE * fich3 ;
struct pessoa alguem;

//funções arvore
void treeprint(struct tnode *p);        //imprime todos os elementos de uma arvore por ordem
void inicializar_arvore(void);      //coloca raiz e raiz2 a NULL
int colocar1(struct pessoa alguem);     //coloca um elementa na arvore
int colocar2(struct pessoa alguem);     //coloca um elemento na arvore
struct tnode *addtree(struct tnode *, struct tnode *);

//funções fich
int get_one_line(FILE * fich, char *linha, int lim);        //para ter uma linha do fich
int open_ficheiros();       //pede os nomes e abre ficheiros para leitura e escrita
int close_fich();       //fechar od ficheiros
int ficheiro_arvore();     //ficheiro para arvore
int arvore_ficheiro (struct tnode *p,FILE *fich1);     //arvore para ficheiro


#endif //PROJECT_2020_ARVORE_H
