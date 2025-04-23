/*Todo restaurante, embora por lei não possa obrigar o cliente a pagar, cobra 10% de comissão para o
garçom. Faça um algoritmo que leia o valor gasto com despesas realizadas em um restaurante e
imprima o valor da gorjeta e o valor total com a gorjeta. */

#include <stdio.h>

#define comissao 0.1

int main (){
    float valor_gorjeta, valor_total, valor_gasto;

    printf("Forneça o valor total gasto: R$");
    scanf("%f", &valor_gasto);
    
    valor_gorjeta = valor_gasto*comissao;
    valor_total = valor_gorjeta + valor_gasto;

    printf("O valor da gorjeta: R$%.2f\nO valor total: R$%.2f", valor_gorjeta, valor_total);

    return 0;
}