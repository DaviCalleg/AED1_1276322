/* Implemente um programa em C que leia 5 números inteiros distintos e insira esses números,
na ordem de leitura, em uma árvore binária de busca. Depois, imprima os valores utilizando
o percurso em ordem (in-order traversal). */
#include<stdlib.h>
#include<stdio.h>

typedef struct no Tno;

struct no{
    int conteudo;  
    Tno* esq;
    Tno* dir;
};
void inserir(Tno** raiz, int conteudo){
        if((*raiz) == NULL){
            Tno* novo =  malloc(sizeof(Tno));
            if(novo == NULL){
                printf("A Alocação Falhou");
            }
            else{
                (*raiz) = novo;
                novo->conteudo = conteudo;
                novo->dir = NULL;
                novo->esq = NULL; 
            }
        }
        else{
            if(conteudo > (*raiz)->conteudo){
                inserir(&((*raiz)->dir),conteudo);
            }
            else if(conteudo <= (*raiz)->conteudo){
                inserir(&((*raiz)->esq), conteudo);
            }
        }
}
void impressao(Tno** raiz){
    if((*raiz)->esq == NULL){
        printf("%d ",(*raiz)->conteudo);
    }
    else{
        impressao(&((*raiz)->esq));
        printf("%d ",(*raiz)->conteudo);
    }
    if((*raiz)->dir != NULL){
        impressao(&((*raiz)->dir)); 
    }
}
int main(){
    Tno* raiz = NULL;
    int conteudo, contador = 0;
    printf("Escreva o numero %d: ", contador); 
        scanf("%d", &conteudo);
    while(conteudo > 0){
        inserir(&raiz, conteudo);
        contador++;
        printf("Escreva o numero %d: ", contador); 
        scanf("%d", &conteudo);
    }
    if(contador > 0 ){
         printf("Os numeros presentes na arvore sao: ");
        impressao(&raiz);
    }
    else{
        printf("Não ha folhas na arvore!");
    }
    return 0;
}