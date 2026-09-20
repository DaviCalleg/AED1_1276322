#include <stdio.h>
#include <stdlib.h>
/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Davi Callegario Caetano
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1068
Data        : 20/09/2026
Objetivo    : Verificar se os parênteses estão corretos
Dificuldade : Média
Uso de IA   : Foi utilizado para tirar pequenas dúvidas
-------------------------------------------------------------------------- */

typedef struct no Tnode;

struct no{
    Tnode * prox;
};
int manipulacoes_string(char expressao[]){
    int contagem = 0;
    
    if(fgets(expressao, 1000, stdin) == NULL){
        return 0;
    }
    else{
        for(int i = 0; expressao[i] != '\n' && expressao[i] != '\0'; i++){
            contagem++;
        }
        expressao[contagem] = '\0';
        return contagem;
    }
    
}
void empilhar(Tnode * cabeca){
    Tnode * new;
    new = malloc(sizeof(Tnode));
    if(new == NULL) return;
    new->prox = cabeca->prox;
    cabeca->prox = new;
}
int desempilhar(Tnode * cabeca){
    
     if(cabeca->prox == NULL){
        return 1;
    }
    else{
        Tnode * desempilhar;
        desempilhar = cabeca->prox;
        cabeca->prox = desempilhar->prox;
        free(desempilhar);
        return 0;
    } 
}
int verificacao_resto(Tnode * cabeca){
    if(cabeca->prox == NULL){
        return 0;
    }
    else if (cabeca->prox != NULL){
      return 1;  
    }
}
int main(){
    int qtd_elementos = 0;
    char expressao[1000];
    while((qtd_elementos = manipulacoes_string(expressao)) != 0 ){
    
        Tnode * cabeca;
        cabeca = malloc(sizeof(Tnode));
        if(cabeca == NULL) return 1;
        cabeca->prox = NULL;

        int verificacao = 0;
        for(int i = 0; i < qtd_elementos; i++){
            
            if(expressao[i] == '('){
                empilhar(cabeca);
            }
            else if (expressao[i] == ')'){
            verificacao = desempilhar(cabeca);
            if(verificacao == 1){
                    printf("incorrect\n");
                    break;
                }
            }
        }
        if(verificacao != 1){
            verificacao = verificacao_resto(cabeca);
                if(verificacao == 0){
                    printf("correct\n");
                    
                }else if(verificacao == 1){
                    printf("incorrect\n");
                    
                }
        }        

        
    } 
    return 0;
}