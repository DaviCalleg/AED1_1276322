#include <stdio.h>
 
int main(){
 
 //Número de matrizes
 int n;
 
 //Leitura de n sempre maior que zero
 do{
    scanf("%d", &n);
 }while(n < 0);
 
 
 //Declarando um vetor de matrizes
 int v_matrizes[n][9][9];
 
 //Recebendo as instancias de todas as matrizes de uma vez
for(int i = 0; i < n; i++){  
    for(int l = 0; l < 9; l++){
        for(int c = 0; c < 9; c++){
            scanf("%d", &v_matrizes[i][l][c]);
        }
    }
}  

//Conferência
for(int i = 0; i < n; i++){    
    //Linhas
    int rev_linha, j_numl, sol_linha = 0, sol_coluna = 0, sol_matrizes = 0;
    for(int l = 0; l < 9; l++){
        if(sol_linha == 1){ //Se ele já reconheceu um erro, já sai do laço
                break;
            }
        for(int c = 0; c < 9; c++){
            if(sol_linha == 1){
                break;
            }
            rev_linha = v_matrizes[i][l][c];
            for(int r = 0; r < 9; r++){ //Fixando um número e avaliando os outros
                j_numl = 0; //Pulando a casa do próprio número que está sendo analisado, se há outro na mesma linha (nesse caso)
                if(c == r){
                    j_numl = 1;
                }
                if(j_numl == 0){
                    if(rev_linha == v_matrizes[i][l][r] ||(v_matrizes[i][l][r] < 1 || v_matrizes[i][l][r] > 9)){ //Além da revisão da repetição vê se o numero 1 < n < 9
                    sol_linha = 1;
                    break;
                    }
                }
            }
        }
    }
    
    //Coluna. Semelhante a linha
    if(sol_linha == 0){ //Só vai entrar se a revisao da linha estiver certa
        int rev_coluna, j_numc;
        for(int c = 0; c < 9; c++){
            if(sol_coluna == 1){
                    break;
                }
            for(int l = 0; l < 9; l++){
                if(sol_coluna == 1){
                    break;
                }
                rev_coluna = v_matrizes[i][l][c];
                for(int r = 0; r < 9; r++){
                    j_numc = 0;
                    if(l == r){
                        j_numc = 1;
                    }
                    if(j_numc == 0){
                        if(rev_coluna == v_matrizes[i][r][c] || (v_matrizes[i][r][c] < 1 || v_matrizes[i][r][c] > 9)){
                        sol_coluna = 1;
                        break;
                        }
                    }
                }
            }
        }        
    }
    
    //Matrizes 3x3
    if(sol_linha == 0 && sol_coluna == 0){
        int rev_matrizes, j_numm, aj_lm = -3, aj_cm = -3; // Ajuste para dividir a matriz de 9x9 em 9 partes de 3x3
        for(int lm = 1; lm <= 3; lm++){
            if(sol_matrizes == 1){
                    break;
            }
            aj_lm += 3; //Ajuste na linha
            for(int cm = 1; cm <= 3; cm++){
                if(sol_matrizes == 1){
                    break;
                }
                aj_cm += 3; //Ajuste na coluna
                for(int l = (0 + aj_lm); l <= (2 + aj_lm); l++){ //Aplicando o ajuste
                    if(sol_matrizes == 1){
                        break;
                    }
                    for(int c = (0 + aj_cm); c <= (2 + aj_cm); c++){ //Aplicando o ajuste
                        if(sol_matrizes == 1){
                            break;
                        }
                            rev_matrizes = v_matrizes[i][l][c];
                            for(int rl = (0 + aj_lm); rl <= (2 + aj_lm); rl++){
                                if(sol_matrizes == 1){
                                    break;
                                }
                                for(int rc = (0 + aj_cm); rc <= (2 + aj_cm); rc++){
                                    j_numm = 0; //Pulando o próprio número
                                    if(l == rl && c == rc){
                                        j_numm = 1;
                                    }
                                        if(j_numm == 0){
                                            if(rev_matrizes == v_matrizes[i][rl][rc] || (v_matrizes[i][rl][rc] < 1 || v_matrizes[i][rl][rc] > 9)){
                                                sol_matrizes = 1;
                                                    break;
                                            }
                                        }
                                }
                            }
                    }
                    
                }
                if(cm == 3) aj_cm = -3; //Quando chega na coluna 3 para zerar e voltar na primeira
            }
            if(lm == 3) aj_cm = -3; //Quando chega na linha 3 para zerar e voltar na primeira
        }
    }
    
    
    printf("Instancia %d\n", (i + 1)); //Impressão final
    if(sol_linha == 1 || sol_coluna == 1 || sol_matrizes == 1){ //Se existir algum erro irá imprimir que "NAO"
        printf("NAO\n\n"); 
    }
    else{
        printf("SIM\n\n"); 
    }
    
}
    
    return 0;
}

