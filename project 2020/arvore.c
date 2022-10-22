#include "arvore.h"
void inicializar_arvore(void) {
    raiz =NULL;
    raiz2=NULL;
}
void treeprint(struct tnode *p) {
    if (p != NULL) {
        treeprint(p->left);
        printf("%d %s\n", p->gente.divida, p->gente.nome);
        treeprint(p->right);
    }
}

int colocar1(struct pessoa alguem) {
    struct tnode *p;
    p = (struct tnode *) malloc(sizeof(struct tnode)); // make a new node
    if (p == NULL)
        return 1;
    p->gente = alguem;
    p->left = p->right = NULL;
    raiz = addtree(raiz, p);
    return 0;
}

int colocar2(struct pessoa alguem) {
    struct tnode *p;
    p = (struct tnode *) malloc(sizeof(struct tnode)); // make a new node
    if (p == NULL)
        return 1;
    p->gente = alguem;
    p->left = p->right = NULL;
    raiz2 = addtree(raiz2, p);
    return 0;
}

struct tnode *addtree(struct tnode *pr, struct tnode *p) {
    int cond;
    if (pr == NULL) {
        pr = p;
    } else {
        if ((cond = strcasecmp(p->gente.nome, pr->gente.nome)) > 0) {
            pr->right = addtree(pr->right, p);
        } else if (cond < 0)
            pr->left = addtree(pr->left, p);
    }
    return pr;
}

