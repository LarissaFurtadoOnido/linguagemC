/*Faça um programa que leia dois valores do tipo double e armazene-os, respectivamente, nas
variáveis a e b. Em seguida escreva comandos para trocar o conteúdo das variáveis, ou seja, a
variável receba a valor de b e a variável b receba o valor de a.*/

#include <stdio.h>

int main(){
    double a, b, aux;

    printf("Forneça o valor de a: ");
    scanf("%lf", &a);

    printf("Forneça o valor de b: ");
    scanf("%lf", &b);
    
    aux = a;
    a = b;
    b = aux;
    
    printf("Valor de a = %.2lf", a);
    printf("Valor de b = %.2lf", b);

    return 0;
}