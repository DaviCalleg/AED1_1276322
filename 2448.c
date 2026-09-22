#include <stdio.h>
#include <stdlib.h>
/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Davi Callegario Caetano
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/2448
Data        : 22/09/2026
Objetivo    : Contabilizar o tempo necessário para um carteiro entregar algumas encomendas dada uma certa ordem
Dificuldade : Média
Uso de IA   : Utilizada para conferir os conceitos de Busca Binária
-------------------------------------------------------------------------- */
int busca_binaria(int vet[], int entrega, int tam_vet){

    int e, d, m;
    e = 0;
    d = (tam_vet - 1);

    while(e <= d){
        m = (e + d)/2;
        if(vet[m] == entrega){
            break;
        }
        else{
            if(vet[m] < entrega){
                e = m + 1;
            }
            else if (vet[m] > entrega){
                d = m - 1;
            }
        }
    }
    return m;
}

int main(){
    int M, N, tempo = 0, destino = 0, posicao_atual = 0;
        scanf("%d %d", &M, &N);

     int vet[M];

     for(int i = 0; i < M; i++){
            scanf("%d", &vet[i]);
     }

     int vet2[N];

     for(int i = 0; i < N; i++){
            scanf("%d", &vet2[i]);
     }

     for(int i = 0; i < N; i++){
        int e;
        e = vet2[i];
           destino = busca_binaria(vet, e, M);
           tempo += abs(destino - posicao_atual); //Para pegar o módulo da distância
           posicao_atual = destino;
     }

     printf("%d\n", tempo);

    return 0;
}