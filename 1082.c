/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Davi Callegario Caetano
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1082
Data        : 10/11/2026
Objetivo    : Análise de Grafos
Dificuldade : Média alta
Uso de IA   : A IA foi utilizada para reparar defeitos de uma primeira versão feita de forma autônoma
-------------------------------------------------------------------------- */
#include<stdio.h>
#include<stdlib.h>
int ** matriz_adjac(int qtd_vertices){
    
    int ** matriz;
    matriz = malloc(qtd_vertices * sizeof(int*));
    for(int i = 0; i < qtd_vertices; i++){
        matriz[i] = malloc(qtd_vertices * sizeof(int));
    }
    for(int i = 0; i < qtd_vertices; i++){
        for (int j = 0; j < qtd_vertices; j++){
            matriz[i][j] = 0;  
        }
        
    }

    return matriz;
}
void dfs(int** matriz, int x, int visitados[], int qtd_vertices){
    visitados[x] = 1;
    printf("%c,", (x + 97));
    for(int i = 0; i < qtd_vertices; i++){
        if(matriz[x][i] == 1 && !visitados[i]){
            dfs(matriz,i,visitados,qtd_vertices);
        }
    }
}
int analise_componentes(int qtd_vertices, int ** matriz){
    int visitados[qtd_vertices], componentes = 0;
    for(int v = 0; v < qtd_vertices; v++){
        visitados[v] = 0;
    }
    for(int x = 0; x < qtd_vertices;x++){
        if(visitados[x] == 0){
            dfs(matriz, x, visitados, qtd_vertices);
            componentes++;
            printf("\n");    
        }
    }    
    return componentes;
}
void liberar_matriz(int ** matriz, int qtd_vertices){
    for(int i = 0; i < qtd_vertices;i++){
        for(int j = 0; j < qtd_vertices;j++){
            free(matriz[i][j]);
        }
    }
}
int main(){
    int qtd_casos;
    scanf("%d", &qtd_casos);
    if(qtd_casos == 0){
        return 0;
    }
    else{
        int qtd_vertices, qtd_arestas, contagem = 1;
        while(contagem <= qtd_casos){ 
            scanf("%d", &qtd_vertices);
            int** matriz = matriz_adjac(qtd_vertices);
            scanf("%d", &qtd_arestas);
            char termo_um, termo_dois;
            for(int i=0; i < qtd_arestas; i++){
                scanf(" %c %c", &termo_um, &termo_dois);
                termo_um = termo_um - 97;
                termo_dois = termo_dois - 97;
                matriz[termo_um][termo_dois] = 1;
                matriz[termo_dois][termo_um] = 1;
            }
            printf("Case #%d:\n", contagem);
            int componentes = analise_componentes(qtd_vertices, matriz);
            printf("%d connected components", componentes);
            printf("\n\n");
            contagem++;
            liberar_matriz(matriz, qtd_vertices);
        }
    }


    return 0;
}