 /* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Davi Callegario Caetano
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1080
Data        : 27/08/2026
Objetivo    : Apresentar o maior elemento e sua posição dentro de um vetor de 100 !!Utilizando alocação dinâmica
Dificuldade : Fácil
Uso de IA   :  Não foi utilizada neste código.
-------------------------------------------------------------------------- */
 
 #include <stdio.h>
 #include <stdlib.h>

int main() {

int *vetor, maior, posicao; //Declarando um poteiro do tipo inteiro 

//Alocação dinâmica

vetor = (int*) malloc(100 * sizeof(int)); //Entregando o endereço da alocação para vetor

if(vetor == NULL){ //Caso a alocação falhe o código irá encerrar retornando 1 (que significa que algo na executação falhou)
    printf("A alocação falhou!");
    return 1;
}

//Preenchendo os vetores e manipulação normal do vetor:

for(int i = 0; i < 100; i++){
        scanf("%d", &vetor[i]); //Leitura dos valores
}

//Maior elemento e posicao
maior = vetor[0];
posicao = 0;

for(int i = 0; i < 100; i++){
    if(maior < vetor[i]){
        maior = vetor[i];
        posicao = i;
    }
}

posicao += 1;

printf("%d\n", maior);
printf("%d\n", posicao);

free(vetor); //Liberando o espaço utilizado

return 0;

}