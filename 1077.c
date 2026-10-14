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
//Estruturas Dinâmicas:
typedef struct pilha Tpilha;
typedef struct fila Tfila;

struct pilha{
    char operador;
    Tpilha * prox;
};

struct fila{
    char operando;
    Tfila * prox;
};

int tamanho_expressao(char expressao_infixa[]){
    int tamanho = 0;
    for(int i = 0; expressao_infixa[i] != '\0' && expressao_infixa[i] != '\n'; i++){
        tamanho++;
    };
    return tamanho;
}
void push_fila(Tfila* ponteiro_fila, char operando){
    Tfila * novo;
    novo = malloc(sizeof(Tfila));
    if(novo == NULL){
        printf("A alocacao Falhou!");
    }
    else{
        novo->operando = operando;
        novo->prox = ponteiro_fila->prox;
        ponteiro_fila->prox = novo;
    }
}

void push_pilha(Tpilha * ponteiro_pilha, char operador){
    Tpilha * novo;
    novo = malloc(sizeof(Tpilha));
    if(novo == NULL){
        printf("Alocacao falhou!");
    }
    else{
       novo->operador = operador;
       novo->prox = ponteiro_pilha->prox;
       ponteiro_pilha->prox = novo;
    }
}
void pop_pilha(Tpilha * ponteiro_pilha, int pos, char expressao_posfixa[]){
    
    Tpilha * aux;
    aux = ponteiro_pilha->prox;
    ponteiro_pilha->prox = aux;
    while(aux != NULL){
        expressao_posfixa[pos] = aux->operador;
        aux = aux->prox;
        free(ponteiro_pilha->prox);
        ponteiro_pilha->prox = aux;
        pos++;
    }
    
}
int comparando_operadores(char expressao_infixa[], int posicao, int prox_operador){
    int v_operador, v_prox_operador;
    //Dando valor ao operador;
    if(expressao_infixa[posicao] == '+' || expressao_infixa[posicao] == '-'){
        v_operador = 1;
    }
    else if(expressao_infixa[posicao] == '*' || expressao_infixa[posicao] == '/'){
        v_operador = 2;
    }
    else if(expressao_infixa[posicao] == '^' || expressao_infixa[posicao] == ')'){
        v_operador = 3;
    }
    //Dando valor ao prox_operador;
    if(expressao_infixa[prox_operador] == '+' || expressao_infixa[prox_operador] == '-'){
        v_operador = 1;
    }
    else if(expressao_infixa[prox_operador] == '*' || expressao_infixa[prox_operador] == '/'){
        v_operador = 2;
    }
    else if(expressao_infixa[prox_operador] == '^' || expressao_infixa[prox_operador] == ')'){
        v_operador = 3;
    }

    if(v_operador < v_prox_operador){
        return 1;
    }else{
        return 0;
    }
}
int prioridade_operador(char expressao_infixa[], int posicao){
    int prioridade;
    int prox_operador = posicao;
    while(expressao_infixa[prox_operador] != '+' || expressao_infixa[prox_operador] != '-' || expressao_infixa[prox_operador] != '*' || expressao_infixa[prox_operador] != '/' || expressao_infixa[prox_operador] != '^' || expressao_infixa[prox_operador] != ')' || expressao_infixa[prox_operador] != '\0'){
        prox_operador++;
    }
    if(expressao_infixa[prox_operador] == '\0'){
        prioridade = 1;
        return prioridade;
    }
    else{
        prioridade = comparando_operadores(expressao_infixa, posicao, prox_operador);
        return prioridade; 
    }
}

int main(){
    //Recebendo o número de casos:
    int N;
    do{
        scanf("%d", &N);
        //Limapndo o Buffer:
        int c;
    while ((c = getchar()) != '\n' && c != EOF);
    }while(N < 1 || N > 1000);
    //Criando as estruturas dinâmicas e alocando memória:
    Tpilha * ponteiro_pilha;
    ponteiro_pilha = malloc(sizeof(Tpilha));
    Tfila * ponteiro_fila;
    ponteiro_fila = malloc(sizeof(Tfila));
    if((ponteiro_pilha == NULL) || (ponteiro_fila == NULL)){
        printf("Alocação Falhou");
        return 1;
    }
    ponteiro_fila->prox = NULL;
    ponteiro_pilha->prox = NULL;
    //Analisando as expressoes
    while(N != 0){
        int pos = 0;
        //Criando o vetor de char para ler a expressão com até 300 caracteres;
        char expressao_infixa[300];
        //Vetor que vai guardar a expressao já convertida;
        char expressao_posfixa[300];
        //Fazendo a leitura da expressao infixa:
            fgets(expressao_infixa, 300, stdin);
            //Vendo seu tamanho:
            int tamanho_infixa = tamanho_expressao(expressao_infixa);
            //Começando a "tradução" para posfixa;
            for(int j = 0; j < tamanho_infixa; j++){
                int verificacao = 0;
                //Verificando se é um operador ou um operando;
                if((expressao_infixa[j] < 'A' && expressao_infixa[j] > 'Z') || (expressao_infixa[j] < 'a' && expressao_infixa[j] > 'z') || (expressao_infixa[j] > '0' && expressao_infixa[j] < '9')){
                    //Caso seja, vamos direto na string nova:
                    expressao_posfixa[pos] = expressao_infixa[j];
                    verificacao++;
                    pos++;
                }
                else if(expressao_infixa[j] == '+' || expressao_infixa[j] == '-' || expressao_infixa[j] == '*' || expressao_infixa[j] == '/' || expressao_infixa[j] == '^' || expressao_infixa[j] == ')' || expressao_infixa[j] == '(' ){
                    if(verificacao == 2){
                        int prioridade = prioridade_operador(expressao_infixa, j);
                        if(prioridade == 0){
                            push_pilha(ponteiro_pilha, expressao_infixa[j]);
                        }
                        else if(prioridade == 1){
                            //Coloco tudo que tem na pilha na string:
                            push_pilha(ponteiro_pilha, expressao_infixa[j]);
                            pop_pilha(ponteiro_pilha, pos, expressao_posfixa);
                        }
                    }
                }
                
            }
        //Adicionando o \0 no final da string:
        expressao_posfixa[tamanho_infixa];
        //Imprimindo a expressao posfixa
        printf("%s", expressao_posfixa);
        N--;
    }

    return 0;
}