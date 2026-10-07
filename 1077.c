#include <stdio.h>
#include <stdlib.h>
/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Davi Callegario Caetano
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1077
Data        : 24/09/2026
Objetivo    : Transforma uma expressão infixa em posfixa
Dificuldade : 
Uso de IA   : 
-------------------------------------------------------------------------- */

typedef struct fila_operandos Tfila;

struct fila_operandos{
    char operando;
    Tfila * prox;
};

typedef struct operadores Tpilha;

struct operadores{
    char operador;
    Tpilha * prox;
};

//Expressao final:
char expressao_final[300];
int posicao = 0;

int num_string(char expressao[]){
    int contagem = 0;
    for(int i= 0; expressao != '\n'; i++){
        contagem++;
    }
    return contagem;
}
int verificando_parenteses(char expressao[],int tamanho){
    int verificacao = 0;
    for(int i = 0; i < tamanho; i++){
        if(expressao[i] == '('){
            verificacao = 1;
        }
    }
    return verificacao;
}
void avaliacao_parenteses(char expressao[], int tamanho, Tfila * cabeca_fila, Tfila * cauda_fila, Tpilha * cabeca_pilha){
    char expressao_parenteses[300];
    int tamanho_nova_string = 0;
    for(int i = 0; i < tamanho;i++){
        if(expressao[i] == '('){
            //A nova expressão vai começar uma casa a frente do parênteses;
            for(int j = (i + 1); expressao[j] != ')'; j++){
                expressao_parenteses[j - (i + 1)] = expressao[j];
            }
            tamanho_nova_string = num_string(expressao_parenteses);
            notacao_polonesa(expressao_parenteses,tamanho_nova_string, cabeca_fila, cauda_fila, cabeca_pilha);
        }
    }
}
int verificacao_string_vazia(){
    int verificacao = 0;
    if(expressao_final[0] != NULL){
        verificacao = 1;
    }
    return verificacao;
}
void notacao_polonesa(char expressao[],int tamanho,Tfila * cabeca_fila, Tfila * cauda_fila, Tpilha * cabeca_pilha){
    //Ponto Principal do Problema:
    //Percorrer a expressão e adicionar na pilha ou fila;
    int verificacao_string = 0, qtd_operando = 0; //Verificando se a string esta vazia. Será necessário dois operandos pra sair o operador:
    verificacao_string = verificacao_string_vazia();
    if(verificacao_string == 0){
      for(int k = 0; k < tamanho; k++){

            if(expressao[k] == '+' || expressao[k] == '-' || expressao[k] == '*' || expressao[k] == '/' || expressao[k] == '^'){
                //É um operador e vai para a pilha
                push_pilha(cabeca_pilha, expressao[k]);
            }
            else if(expressao[k] >= '0' && expressao[k] <= '9'|| expressao[k] >= 'a' && expressao[k] <= 'z' || expressao[k] >= 'A' && expressao[k] <= 'Z'){
                //É um operando e vai pra pilha
                push_fila(cabeca_fila, cauda_fila, expressao[k]);
            }
        }  
    }else{

    }     
}
void push_pilha(Tpilha * cabeca_pilha, char operando){
    Tpilha * novo;
    novo = malloc(sizeof(Tpilha)); //Considerando que deu certo
    novo->operador = operando;
    novo->prox = cabeca_pilha->prox;
    cabeca_pilha->prox = novo;
}
void push_fila(Tfila * cabeca_fila, Tfila * cauda_fila, char operando){
    Tfila * novo;
    novo = malloc(sizeof(Tfila)); //Considerando que deu certo
    if(cabeca_fila->prox == NULL){
        novo->operando = operando;
        novo->prox = cabeca_fila->prox;
        cabeca_fila->prox = novo;
        cauda_fila->prox = novo;
    }else{
        novo->operando = operando;
        novo->prox = cabeca_fila->prox;
        cabeca_fila->prox = novo;
    } 
}
void pop_fila(Tfila * cauda_fila, Tfila * cabeca_fila){
    Tfila * sair_elemento;
    Tfila * aux;
    int elemento_addf; 
    sair_elemento = cauda_fila->prox;
    elemento_addf = sair_elemento->operando;
    adicionando_string(elemento_addf);
    free(sair_elemento);
    for(Tfila * p = cabeca_fila->prox; p->prox != NULL; p = p->prox){
        aux = p;
    }
    cauda_fila->prox = aux;
}
pop_pilha(Tpilha * cabeca_pilha){
    char elemento_add;
    Tpilha * sair_elemento;
    sair_elemento = cabeca_pilha->prox;
    cabeca_pilha->prox = sair_elemento->prox;
    elemento_add = sair_elemento->operador;
    adicionando_string(elemento_add);
    free(sair_elemento);
}
void adicionando_string(char adicionar){
    expressao_final[posicao] = adicionar;
    posicao++;
}
int main(){
    //Criando e alocando estruturas dinâmicas;
    //Cabeca para pilha:
    Tpilha * cabeca_pilha;
    cabeca_pilha = malloc(sizeof(Tpilha)); //Considerando que deu certo
    cabeca_pilha->operador = NULL;
    cabeca_pilha->prox = NULL;
    //Criando cabeça e cauda para fila:
    Tfila * cabeca_fila;
    cabeca_fila = mallco(sizeof(Tfila)); //Considerando que deu certo
    cabeca_fila->operando = NULL;
    Tfila * cauda_fila;
    cauda_fila = malloc(sizeof(Tfila)); //Considerando que deu certo
    cauda_fila->operando = NULL;
    cabeca_fila->prox = NULL;
    cauda_fila->prox = NULL;

    //Leitura da quantidade de expressões:
    int casos;
    scanf("%d", &casos);

    //Recepção da expressão;
    while(casos != 0){
        char expressao[300];
        fgets(expressao,300,stdin);
        int tamanho = num_expressao(expressao);

        //Avaliando parenteses e dividindo em casos:
        int verificacao_p;
        verificacao_p = (expressao,tamanho);
        if(verificacao_p == 1){
        avaliacao_parenteses(expressao, tamanho, cabeca_fila, cauda_fila, cabeca_pilha);    
        }
        else{
            //Caso não tenha parenteses seguimos para a transformação
            notacao_polonesa(expressao,tamanho, cabeca_fila, cauda_fila, cabeca_pilha);
        }
    }
    return 0;
}