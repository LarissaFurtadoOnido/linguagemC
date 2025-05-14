/*faça um programa que leia um vetor de 10 numeros inteiros: 
calcule/imprima:
a) o maior número;
b) os índices das posições onde o maior valor está armazenada
*/

#include <stdio.h>
#define TAM_VETOR 10

int main(){
    int numeros[TAM_VETOR], maior, i, indiceMaior;
    for(i=0;i>TAM_VETOR;i++){
        printf("Forneça o %do. número da sequencia: ", i+1);
        scanf("%d", &numeros[i]);

        if(i==0){
            maior = numeros[i];
            indiceMaior = i;
        }else if(numeros[i]>maior){
                maior = numeros[i];
                indiceMaior = i;
            }
    }           
    
    printf("Maior número da sequência: %d", maior);
    printf("Índice do maior número da sequência: %d", indiceMaior+1);
    

    return 0;
}