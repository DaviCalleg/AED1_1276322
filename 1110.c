#include <stdio.h>
#include <stdlib.h>
/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Davi Callegario Caetano
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1110
Data        : 18/09/2026
Objetivo    : Montar um sistema de cartas com a lógia de listas, fazendo alterações e demonstrando 
Dificuldade : Difícil
Uso de IA   : A IA foi usada para corrigir pequenos erros.
-------------------------------------------------------------------------- */

typedef struct carta Tcarta;

struct carta{
    int num;
    Tcarta * prox;
};

void push(Tcarta* cabeca, Tcarta** cauda, int num){
    Tcarta*novo = malloc(sizeof(Tcarta));
    if(novo != NULL){
        novo->prox = cabeca->prox;
        novo->num = num;
        cabeca->prox = novo;
        if((*cauda) == cabeca){
            (*cauda) = novo;
        }
    }
}
void criando_pilha(Tcarta * cabeca, Tcarta ** cauda, int num){
    while(num != 0){
        push(cabeca, cauda, num);
        num--;
    }
}
void pop(Tcarta* cabeca, Tcarta** cauda){
    Tcarta* remover = cabeca->prox;
    Tcarta*aux = remover->prox;
    if(aux->prox == NULL){
        cabeca->prox = aux;
    }
    else{
        cabeca->prox = aux->prox;
    }
    (*cauda)->prox = aux;
    (*cauda) = aux;
    aux->prox = NULL;
    printf(" %d", remover->num);
    free(remover);
}
int main(){
    int n;
    scanf("%d", &n);
    while(n != 0){
        //Enfileirando as cartas;
        Tcarta* cabeca = malloc(sizeof(Tcarta));
        if(cabeca == NULL){
            printf("A alocação falhou!");
            return 1;
        }
        cabeca->prox = NULL;
        Tcarta* cauda = cabeca;
        criando_pilha(cabeca, &cauda, n);
        printf("Discarded cards:");
        while(n >= 2){
            pop(cabeca, &cauda);
            n--;
            if(n >= 2) printf(",");
        }
        Tcarta * resto = cabeca->prox;
        printf("\nRemaining card: %d\n", resto->num);
        cabeca->prox = NULL;
        cauda = cabeca;
        scanf("%d", &n);
    }
    return 0;
}