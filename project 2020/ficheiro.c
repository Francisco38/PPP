#include "arvore.h"

int open_ficheiros(){
    char nome_fich[LINHA-5];
    fich1=NULL;
    fich2=NULL;
    fich3=NULL;
    while(fich1 == NULL) {
        printf("Nome do ficheiro de dados? ");
        if (get_one_line(stdin,nome_fich, LINHA-5) == EOF){
            printf("o programa não esta bem codificado");
            return 1;
        }
        fich1=fopen(nome_fich, "r");
        if (fich1 == NULL)
            fprintf(stderr,"Ficheiro não existe\n");

    }
    while(fich2 == NULL) {
        printf("Nome do ficheiro para as dividas? ");
        if (get_one_line(stdin,nome_fich, LINHA-5) == EOF){
            printf("o programa não esta bem codificado");
            return 1;
        }
        fich2=fopen(nome_fich, "w");
        if (fich2 == NULL)
            fprintf(stderr,"problema ao abrir fichiero\n");

    }
    while(fich3 == NULL) {
        printf("Nome do ficheiro para as contas em dia? ");
        if (get_one_line(stdin,nome_fich, LINHA-5) == EOF){
            printf("o programa não esta bem codificado");
            return 1;
        }
        fich3=fopen(nome_fich, "w");
        if (fich3 == NULL)
            fprintf(stderr,"problema ao abrir fichiero\n");

    }
    return 0;
}

int get_one_line(FILE * fich, char *linha, int lim) {
    int c, i;
    i = 0;
    while (isspace(c = fgetc(fich)));
    if (c != EOF) {
        if (!iscntrl(c)) linha[i++] = c;
    } else
        return c;

    for (; i < lim - 1;) {
        c = fgetc(fich);
        if (c == EOF)
            return c;
        if (c == '\n')
            break;
        linha[i++] = c;
    }
    linha[i] = 0;
    while ((c != EOF) && (c != '\n'))
        c = fgetc(fich);
    return c;
}
int arvore_ficheiro (struct tnode *p,FILE *f){
    char d[4];
    if (p != NULL) {
        if(arvore_ficheiro(p->left,f)==1){
            return 1;
        }
        fwrite(p->gente.nome,1,LINHA-5,f);
        if (ferror (f)){
            printf ("erro a escrever no ficheiro\n");
            return 1;
        }
        fputc('\t',f);
        if (ferror (f)){
            printf ("erro a escrever no ficheiro\n");
            return 1;
        }
        sprintf(d, "%d", p->gente.divida);
        fwrite(&d,1,3,f);
        if (ferror (f)){
            printf ("erro a escrever no ficheiro\n");
            return 1;
        }
        fputc('\n',f);
        if (ferror (f)){
            printf ("erro a escrever no ficheiro\n");
            return 1;
        }
        if(arvore_ficheiro(p->right,f)==1){
            return 1;
        }
    }
    return 0;
}

int ficheiro_arvore(){
    char b[LINHA]="                    ";
    char *token;
    char linha[LINHA]="";
    long int numl;
    while (get_one_line(fich1,linha, LINHA) != EOF) {
        token = strtok(linha,"\t");
        strcpy(alguem.nome, token);
        int i=0;
        while(i<LINHA-5){
            if(alguem.nome[i]=='\0'){
                alguem.nome[i]=' ';
            }
            i++;
        }
        token = strtok(NULL, "\n");
        errno = 0;
        numl = strtol(token, NULL, 0);
        if (errno) {
            printf("Transbordo em long\n");
            return 1;
        }
        if (numl <= INT_MAX && numl >= INT_MIN) {
            alguem.divida = (int) numl;
        }
        else{
            printf("Transbordo em int\n");
            return 1;
        }
        alguem.divida=alguem.divida-50;
        if (alguem.divida < 0) {
            if (colocar1(alguem) != 0) {
                fprintf(stderr, "Não há espaço para inserir\n");
                return 1;
            }
        }
        else {
            if (colocar2(alguem) != 0) {
                fprintf(stderr, "Não há espaço para inserir\n");
                return 1;
            }
        }
        strcpy(alguem.nome,b);
    }
    return 0;
}

int close_fich(){
    if (fclose(fich1)!=0){
      return 1;
    }
    if (fclose(fich2)!=0){
        return 1;
    }
    if (fclose(fich3)!=0){
        return 1;
    }
    return 0;
}