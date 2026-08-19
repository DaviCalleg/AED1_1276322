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

printf("Menor valor: %d", menor);
printf("\nPosicao: %d", posicao);

return 0;

}