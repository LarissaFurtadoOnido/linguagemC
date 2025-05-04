/*Questão 06
Faça um algoritmo que tenha como entrada 3 valores a,b,c e imprima em ordem crescente.*/


#include <stdio.h>

int main(){
    int valorA, valorB, valorC, maior, menor, meio;
    printf("Forneça o primeiro valor inteiro: ");
    scanf("%d", &valorA);
    printf("Forneça o segundo valor inteiro: ");
    scanf("%d", &valorB);
    printf("Forneça o terceiro valor inteiro: ");
    scanf("%d", &valorC);
    
    if(valorA<0 || valorB<0 || valorC<0)
        printf("Valor inválido!");
    else{
        if(valorA > valorB && valorA > valorC){
            maior = valorA;
            if(valorB > valorC){
                meio = valorB;
                menor = valorC;
            }else{
                meio = valorC;
                menor = valorB;
            }
            
        }else if(valorB > valorC){
            maior = valorB;
            
            if(valorA > valorC){
                meio = valorA;
                menor = valorC;
            }else{
                meio = valorC;
                menor = valorA;
            }
            
        }else{
            maior = valorC;
            if(valorA > valorB){
                meio = valorA;
                menor = valorB;
            }else{
                meio = valorB;
                menor = valorA;
            }
        }
        
        printf("\n%d %d %d", menor, meio, maior);
    }

    return 0;
}
