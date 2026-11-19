/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Davi Callegario Caetano
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1610
Data        : 17/11/2026
Objetivo    : Veririficar se existe ciclos em arquivos
Dificuldade : Média
Uso de IA   : A IA me auxiliou a resolver possíveis erros no funcionamento do código
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

typedef struct no Tno;
struct no {
    int identificador;
    Tno* prox;
};

Tno** montando_vertice(int vertices) {
    Tno** vertice = malloc(vertices * sizeof(Tno*));
    for (int i = 0; i < vertices; i++) {
        vertice[i] = malloc(sizeof(Tno));
        vertice[i]->identificador = i + 1;
        vertice[i]->prox = NULL;
    }
    return vertice;
}

void criando_arestas(int origem, int destino, Tno** vertice) {
    Tno* novo = malloc(sizeof(Tno));
    novo->identificador = destino;
    novo->prox = vertice[origem - 1]->prox;
    vertice[origem - 1]->prox = novo;
}


int dfs(Tno** vertice, int origem, int* visitados, int* pilha_v, Tno** pilha_prox) {
    int topo = 0;

    visitados[origem] = 1; 
    pilha_v[topo] = origem;
    pilha_prox[topo] = vertice[origem]->prox;
    topo++;

    while (topo > 0) {
        int u = pilha_v[topo - 1];
        Tno* aux = pilha_prox[topo - 1];

        if (aux != NULL) {
            
            pilha_prox[topo - 1] = aux->prox;
            int v = aux->identificador - 1;

            if (visitados[v] == 1) {
                return 1; 
            }
            if (visitados[v] == 0) {
                visitados[v] = 1;
                pilha_v[topo] = v;
                pilha_prox[topo] = vertice[v]->prox;
                topo++;
            }
        } else {
            
            visitados[u] = 2; 
            topo--;
        }
    }

    return 0;
}

void liberar_grafo(Tno** vertice, int vertices) {
    for (int i = 0; i < vertices; i++) {
        Tno* atual = vertice[i];
        while (atual != NULL) {
            Tno* prox = atual->prox;
            free(atual);
            atual = prox;
        }
    }
    free(vertice);
}

int main() {
    int T, N, M;
    if (scanf("%d", &T) != 1) return 0;

    while (T--) {
        scanf("%d %d", &N, &M);
        Tno** vertice = montando_vertice(N);

        int doc_A, doc_B;
        for (int l = 0; l < M; l++) {
            scanf("%d %d", &doc_A, &doc_B);
            criando_arestas(doc_A, doc_B, vertice);
        }

        int* visitados = calloc(N, sizeof(int));
        int* pilha_v = malloc(N * sizeof(int));
        Tno** pilha_prox = malloc(N * sizeof(Tno*));

        int tem_ciclo = 0;
        for (int i = 0; i < N; i++) {
            if (visitados[i] == 0) {
                if (dfs(vertice, i, visitados, pilha_v, pilha_prox) == 1) {
                    tem_ciclo = 1;
                    break;
                }
            }
        }

        if (tem_ciclo) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }

        free(visitados);
        free(pilha_v);
        free(pilha_prox);
        liberar_grafo(vertice, N);
    }

    return 0;
}