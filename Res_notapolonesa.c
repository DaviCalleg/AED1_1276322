#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct pilha Tpilha;

struct pilha{
    int conteudo;
    Tpilha * prox;
};


typedef struct cabeca_pilha{
    Tpilha * primeiro_no;
}Tcabeca_pilha;

int man_expressao(char expressao[]){
    int contador = 0;
    for(int i = 0; expressao[i] != '\0'; i++){
        contador++;
    }
    return (contador-1);
}
void push(Tcabeca_pilha * primeiro_no, int novo_conteudo){
    Tpilha * novo;
    novo = malloc(sizeof(Tpilha));
    if(novo == NULL){
        printf("Falha na alocação!");
    }
    novo->conteudo = novo_conteudo;
    novo->prox = primeiro_no->primeiro_no;
    primeiro_no->primeiro_no = novo;
}
int pop(Tcabeca_pilha * primeiro_no){
    int conteudo;
    Tpilha * no_excluido;
    no_excluido = primeiro_no->primeiro_no;
    primeiro_no->primeiro_no = no_excluido->prox;
    conteudo = no_excluido->conteudo;
    free(no_excluido);
    return conteudo;
}
int main(){
    Tcabeca_pilha * primeiro_no;
    primeiro_no = malloc(sizeof(Tcabeca_pilha));
    if(primeiro_no == NULL) return 1;
    primeiro_no->primeiro_no = NULL;
    //Lendo a Expressão:
    int tamanho, resultado, num1, num2;
    char expressao[300];
    printf("Insira a expressão em notacao polonesa:\n");
    fgets(expressao, 300, stdin);
    tamanho = man_expressao(expressao);
    //Operações:
    for(int i = 0; i < tamanho; i++){
        if(expressao[i] != ' '){
            if(expressao[i] == '+' || expressao[i] == '-' || expressao[i] == '*' || expressao[i] == '/' || expressao[i] == '^'){
                num1 = pop(primeiro_no);
                num2 = pop(primeiro_no);
                if(expressao[i] == '+'){
                    resultado = num2 + num1;
                }
                if(expressao[i] == '-'){
                    resultado = num2 - num1;
                }
                if(expressao[i] == '*'){
                    resultado = num2 * num1;
                }
                if(expressao[i] == '/'){
                    resultado = num2 / num1;
                }
                if(expressao[i] == '^'){
                    resultado = pow(num2, num1);
                }
                push(primeiro_no, resultado);
            }
            else{
                int novo_conteudo = (expressao[i]) - '0';
                push(primeiro_no, novo_conteudo);
            }
        }
    }
    Tpilha * presultado;
    int resultado_final;
    presultado = malloc(sizeof(Tpilha));
    if(presultado == NULL){
        printf("A alocação falhou!");
    }
    presultado = primeiro_no->primeiro_no;
    resultado_final = presultado->conteudo;
    free(presultado);
    printf("O resultado final eh: %d", resultado_final);
    return 0;
}

///Resolver problema de numero com mais de uma casa.
