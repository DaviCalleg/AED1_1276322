 /* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Davi Callegario Caetano
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1180
Data        : 20/08/2026
Objetivo    : Apresentar o menor elemento de uma matriz e sua posição
Dificuldade : Fácil
Uso de IA   : Não foi utilizada IA. 
-------------------------------------------------------------------------- */

#include <stdio.h>
 
int main() {
 
 int n, menor, posicao;
 
 scanf("%d", &n); //Leitura de n

 int X[n]; //Declaração do vetor
 
 //Leitura dos elementos
 for(int i = 0; i < n; i++){
     scanf("%d", &X[i]);
 }
 
 //Menor elemento e posicao
 menor = X[0];
 posicao = 0;
 
  for(int i = 1; i < n; i++){
     if(menor > X[i]){
         menor = X[i];
         posicao = i;
     }
 }
 
 printf("Menor valor: %d\n", menor);
 printf("Posicao: %d\n", posicao);
 
    return 0;
}