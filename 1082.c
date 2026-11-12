/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Davi Callegario Caetano
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1082
Data        : 10/11/2026
Objetivo    : Análise de Grafos
Dificuldade : 
Uso de IA   : 
-------------------------------------------------------------------------- */
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
void dfs(int** matriz[][], int visitados[]){

}
void analise_componentes(int qtd_vertices, int ** matriz[][]){
    int visitados[qtd_vertices], origem = 0;
    dfs(matriz, visitados);

}
int main(){
    int qtd_casos;
    scanf("%d", &qtd_casos);
    if(qtd_casos == 0){
        return 0;
    }
    else{
        int qtd_vertices, qtd_arestas, contagem = qtd_casos;
        while(contagem <= qtd_casos){ 
            scanf("%d", &qtd_vertices);
            int** matriz = matriz_adjac(qtd_vertices);
            scanf("%d", &qtd_arestas);
            int termo_um, termo_dois;
            for(int i=0; i <= qtd_arestas; i++){
                scanf("%d", &termo_um);
                termo_um = termo_um - 97;
                scanf("%d", &termo_dois);
                termo_dois = termo_dois - 97;
                matriz[termo_um][termo_dois] = 1;
                matriz[termo_dois][termo_um] = 1;
            }
            printf("Caso #%d:", contagem);
            analise_componentes(qtd_vertices, matriz);
            contagem++;
        }
    }


    return 0;
}