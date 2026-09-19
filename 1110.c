#include <stdio.h>
#include <stdlib.h>
/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Davi Callegario Caetano
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1110
Data        : 18/09/2026
Objetivo    : 
Dificuldade : 
Uso de IA   : 
-------------------------------------------------------------------------- */

//Definindo a struct da lista
typedef struct lista Tlista;

struct lista{
    int conteudo;
    Tlista* prox;
};
//Definindo struct para carta do topo
typedef struct topo Ttopo;

struct topo{
    Tlista * topo;
};

//Definindo struct para carta da base
typedef struct base Tbase;

struct base{
    Tlista * base;
};

void inserir(Ttopo* ptopo, Tbase* pbase, int conteudo, int qtd_cartas){
    Tlista * new;
    new = malloc(sizeof(Tlista));
    if(new == NULL) return;
    new->conteudo = conteudo;
    if(conteudo == qtd_cartas){
        pbase->base = new;
        ptopo->topo = new;
        new->prox = NULL;
    }
    else{
        new->prox = ptopo->topo;
        ptopo->topo = new;
    }
}
int contando(Ttopo * ptopo){
    Tlista * aux;
    aux = ptopo->topo;
    int cartas = 0;

    while(aux != NULL){
        aux = aux->prox;
        cartas++;
    }
    return cartas;
}
int jogar_fora(Ttopo * ptopo){
    Tlista * carta_eliminada;
    int conteudo_carta_eliminada;
    carta_eliminada = ptopo->topo;
    conteudo_carta_eliminada = carta_eliminada->conteudo;
    ptopo->topo = carta_eliminada->prox;
    free(carta_eliminada);

    return conteudo_carta_eliminada;
}
void mudanca_base(Ttopo * ptopo, Tbase * pbase){
    Tlista * nova_base;
    Tlista * antiga_base;
    antiga_base = pbase->base;
    nova_base = ptopo->topo;
    ptopo->topo = nova_base->prox;
    nova_base->prox = NULL;
    pbase->base = nova_base;
    antiga_base->prox = nova_base;
}
void limpeza(Ttopo* ptopo){
    Tlista * elim_carta;
    elim_carta = ptopo->topo;
    free(elim_carta);
}
int main(){

    Ttopo * carta_topo;
    carta_topo = malloc(sizeof(Ttopo));
    if(carta_topo == NULL) return 1;
    Tbase * carta_base;
    carta_base = malloc(sizeof(Tbase));
    if(carta_base == NULL) return 1;

    int qtd_cartas;
    
    scanf("%d", &qtd_cartas);
    
    while(qtd_cartas > 0){
        int cartas_eliminadas[qtd_cartas];
        for(int i = qtd_cartas; i >= 1; i--){
            inserir(carta_topo,carta_base,i, qtd_cartas);
        }
        int verif_cartas = contando(carta_topo);
        int posicao = 0;
        while (verif_cartas >= 2){
            cartas_eliminadas[posicao] = jogar_fora(carta_topo);
            verif_cartas = contando(carta_topo);
            if(verif_cartas >= 2){
            mudanca_base(carta_topo, carta_base);
            }
            posicao++;
        }

        printf("Discarded cards:");
        for(int i = 0; i < (qtd_cartas-1);i++){
            if(i == (qtd_cartas - 2)){
                printf(" %d", cartas_eliminadas[i]);
            }
            else{
                printf(" %d,", cartas_eliminadas[i]);
            }
        } 
        int ultima_carta;
        Tlista * p_ultima_carta;
        p_ultima_carta = carta_topo->topo;
        ultima_carta = p_ultima_carta->conteudo;
        printf("\nRemaining card: %d\n", ultima_carta);
        scanf("%d", &qtd_cartas);
        limpeza(carta_topo);

    }
    
    return 0;
}

