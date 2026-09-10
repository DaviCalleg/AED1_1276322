#include<stdio.h>
#include<stdlib.h>

    //Definindo a estrutura do nodes de uma lista;
    typedef struct nodes{
        int content; //Primeira parte da célula - Conteúdo dos nó;
        struct nodes *p; //Segunda parte da célula - Ponteiro para outro tipo "struct nodes";
    }No;
    //Note que a definição do nó está sendo de forma global para poder utiliza-la em functions;

//Funções:
void inserir(No **lista, int new_valor){
    No *novo = malloc(sizeof(No));
    if(novo == NULL){
        printf("Erro ao alocar memória, não fo possível inserir um novo elemento!"); //Se der erro em alocar a nova struct;
        return;
    }
    else{
        novo->content = new_valor;
        novo->p = *lista;
        *lista = novo;
    }
};

int main(){

    //Criando a estrutura do tipo No chamada cabeça;
    No *cabeca;
   
    cabeca = NULL; //Indicando que a lista vai comceçar sem elementos.

    // # Operações em Listas #
    int escolha;
    do{
        printf("Opções:\n[1]-> Inserir nodes\n[2]-> Apagar nodes\n[3]-> Buscar elementos\n[0]->Finalizar");
        scanf("%d", &escolha);
        if(escolha == 1){
            //Inserindo um elemento;
            int num;
            printf("Qual numero deseja inserir");
            scanf("%d", &num);
            inserir(&cabeca, num);
        }
    }while(escolha != 0);

  return 0;
}