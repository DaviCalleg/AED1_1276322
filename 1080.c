 /* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Davi Callegario Caetano
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1080
Data        : 20/08/2026
Objetivo    : Apresentar o maior elemento de uma matriz e sua posição
Dificuldade : Fácil
Uso de IA   : Tive muitos problemas na hora de enviar o código no Beecrowd. Então para tentar ver o que estava de errado na saída utilizei da IA para corrigir. 
-------------------------------------------------------------------------- */
 
 #include <stdio.h>

int main() {

int v[100], maior, posicao, estado = 0;

for(int i = 0; i < 100; i++){
        scanf("%d", &v[i]); //Leitura dos valores
}

//Maior elemento e posicao
maior = v[0];
posicao = 0;

for(int i = 0; i < 100; i++){
    if(maior < v[i]){
        maior = v[i];
        posicao = i;
    }
}

posicao += 1;

printf("%d\n", maior);
printf("%d\n", posicao);

return 0;

}