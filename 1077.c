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

typedef struct operador Toperador;

struct operador{
    int operador;
    Toperador * prox;
};

typedef struct operando Toperando;

struct operando{
    int operando;
    Toperando * prox;
};

struct cabeca_operador{
    Toperador * primeiro_no;
};

struct cabeca_operadorando{
    Toperando * primeiro_no;
};

int man_string(char expressao[]){
    int contagem = 0;
    for(int i = 0; expressao[i] != '\n';i++){
        contagem++;
    }
    expressao[contagem] = '\0';
    return contagem;
}
int main(){

    Toperando * cabeca_op;
    Toperador * cabeca_opd;

    int casos, tam_expressao;
    char expressao[300];
    scanf("%d", &casos);

    while(casos != 0){
        casos--;
        fgets(expressao, 300, stdin);
        tam_expressao = man_string(expressao);
        
    }



    return 0;
}