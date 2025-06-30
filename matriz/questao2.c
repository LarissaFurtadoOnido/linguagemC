/*Implemente uma função que some os elementos de uma matriz bidimensional de inteiros. Um
programa para testar tal função também deve ser implementado.*/

#include <stdio.h>

#define N 2

void somaMatrizes(int matrizA[][N], int matrizB[][N], int tamanho,int soma[][N]){
    int i, j;
    for(i=0;i<tamanho;i++){
        for(j=0;j<tamanho;j++)
            soma[i][j]= matrizA[i][j]+matrizB[i][j];
    }
}

int main(){
    int matrizA[N][N] = {1,2,3,4}, matrizB[N][N] = {1,2,3,4}, result[N][N], i, j;

    somaMatrizes(matrizA, matrizB, N, result);

    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            printf(" %d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}