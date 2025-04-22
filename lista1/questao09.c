/*Faça um programa que leia as três notas de um aluno e mostre a média aritmética desses valores.*/

#include <stdio.h>

#define MAX_NOTA 3

int main(){
    float nota1, nota2, nota3, media;
    
    printf("Forneça a primeira nota do aluno: ");
    scanf("%f", &nota1);
    printf("Forneça a segunda nota do aluno: ");
    scanf("%f", &nota2);
    printf("Forneça a terceira nota do aluno: ");
    scanf("%f", &nota3);

    media = (nota1+nota2+nota3) / MAX_NOTA;
    printf("%.2f", media);

    return 0;
}