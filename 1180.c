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
printf("%d", posicao);

return 0;

}