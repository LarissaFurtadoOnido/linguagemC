/*Três amigos jogaram na loteria. Caso eles ganhem, o prêmio deve ser repartido proporcionalmente
ao valor que cada deu para a realização da aposta. Faça um programa que leia quanto cada
apostador investiu, o valor do prêmio, e imprima quanto cada um ganharia do prêmio com base no
valor investido.*/

#include <stdio.h>

int main(){
    float aposta1, aposta2, aposta3, apostaTotal, porc1, porc2, porc3, premio;

    printf("Forneça o primeiro valor: R$");
    scanf("%f", &aposta1);
    printf("Forneça o segundo valor: R$");
    scanf("%f", &aposta2);
    printf("Forneça o terceiro valor: R$");
    scanf("%f", &aposta3);
    printf("Forneça o valor do prêmio: R$");
    scanf("%f", &premio);

    apostaTotal = aposta1+aposta2+aposta3;
    porc1 = aposta1/apostaTotal;
    porc2= aposta2/apostaTotal;
    porc3 = aposta3/apostaTotal;

    printf("\nO valor da aposta R$%.2f recebe R$%.2f\n", aposta1, premio * porc1);
    printf("\nO valor da aposta R$%.2f recebe R$%.2f\n", aposta2, premio * porc2);
    printf("\nO valor da aposta R$%.2f recebe R$%.2f\n", aposta3, premio * porc3);

    return 0;
}