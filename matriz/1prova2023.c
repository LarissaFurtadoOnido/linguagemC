/*implemente uma função que calcule a maior e a menor diferença entre dois elementos
consecutivos de um vetor de inteiros. A função deve retornar 1 de a maior diferença for diferente da
menor diferença e 0 em caso contrário. Um programa para testar tal função também deve ser
implementado.*/

#include <stdio.h>

#define N 5

int MaiorMenorDiferenca(int vetorA[], int tamanho){
    int i, menor, maior, subtracao;
    for(i=0;i<tamanho-1;i++){
        subtracao=vetorA[i]-vetorA[i+1];
        if(i==0){
            maior=subtracao;
            menor=subtracao;
        }else if(subtracao>maior)
            maior=subtracao;
        else if(subtracao<menor)
            menor=subtracao;
    }

    if(maior!=menor)
        return 1;
    return 0;
}

int main(){        
    int vetor[N]={5,5,5,5,5}, retorno;

    retorno = MaiorMenorDiferenca(vetor, N);

    if(retorno == 1)
        printf("Diferentes!\n");
    else
        printf("Iguais!\n");

    return 0;
}