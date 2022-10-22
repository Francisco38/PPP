#include "arvore.h"
//Francisco Faria 2019227649
//o ficheiro de dados esta codificado para primeiro estar o nome do pessoa e depois o valor pago pelo mesmo, estando estes valores separados por um \t.
//neste projecto decidi utilizar duas arvores sendo uma para as pessoas em divida (raiz) e outra para as pessoas que pagaram o valor necessario (raiz2).
//estando ambas organizadas por ordem alfabética.No final temos dois ficheiros criados, um para cada caso referido anteriormente (pago ou em divida).
//caso ocorra algum erro na execução do programa ,o mesmo acaba imediatamente e imprime na consola a parte em que i problema ocorreu.

int main(void) {
    inicializar_arvore();
    if(open_ficheiros()!=0){
        printf("Erro-ao abrir os ficheiros");
        return 1;
    }

    if(ficheiro_arvore()!=0){
        printf("Erro ao passar os dados do ficheiro para as arvores");
        return 1;
    }

    if(arvore_ficheiro(raiz,fich2)==1){
        printf("Erro ao transferir os valores de arvore(raiz) para o ficheiro");
        return 1;
    }

    if(arvore_ficheiro(raiz2,fich3)==1){
        printf("Erro ao transferir os valores de arvore(raiz2) para o ficheiro");
        return 1;
    }

    if(close_fich()==1){
        printf("Erro ao fechar os ficheiros");
        return 1;
    }
    return 0;
}