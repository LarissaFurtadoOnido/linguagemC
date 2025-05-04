/*Questão 08
Escreva um programa que leia as três notas de uma aluno. Calcular a média ponderada do aluno,
considerando que o peso para a maior nota seja 5 e para a segunda maior o peso é 3 e para a menor
o peso é 2. Mostrar a média calculada e uma mensagem "APROVADO" se a média for maior ou
igual a 6 e "REPROVADO" se a média for menor que 6..*/


#include <stdio.h>
#define MEDIA 3
#define PESO1 5
#define PESO2 3
#define PESO3 2

int main(){
    float nota1, nota2, nota3, soma=0, mediaTotal;
    
    printf("Forneça a primeira nota: ");
    scanf("%f", &nota1);
    printf("Forneça a segunda nota: ");
    scanf("%f", &nota2);
    printf("Forneça a terceira nota: ");
    scanf("%f", &nota3);
    
    if(nota1 > nota2 && nota1 > nota3){
        soma += nota1*PESO1;
        if(nota2 > nota3)
            soma += nota2*PESO2 + nota3*PESO3;
    }else if(nota2 > nota3){
        soma += nota2*PESO1;
        if(nota1 > nota3)
            soma += nota1*PESO2 + nota3*PESO3;
        else
            soma += nota3*PESO2 + nota1*PESO3;
    }else{
        soma += nota3*PESO1;
        if(nota1 > nota2)
            soma += nota1*PESO2 + nota2*PESO3;
        else
            soma += nota2*PESO2 + nota1*PESO3;
    }
    
    mediaTotal = soma/MEDIA;
    printf("\nMédia = %.2f\n", mediaTotal);
    if(mediaTotal >= 6)
        printf("\nAprovado!\n");
    else
        printf("\nReprovado!\n");
    
    return 0;
}
