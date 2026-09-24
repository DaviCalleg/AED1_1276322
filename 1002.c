#include <stdio.h>
#include <stdlib.h>
/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Davi Callegario Caetano
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1002
Data        : 24/09/2026
Objetivo    : Área do Círculo
Dificuldade : Fácil
Uso de IA   : Não
-------------------------------------------------------------------------- */
 
int main() {
 double raio, area;
 scanf("%lf", &raio);

 double pi = 3.14159;
 
 area = (pi * (raio * raio));
 
 printf("A=%.4f\n", area);
    return 0;
}