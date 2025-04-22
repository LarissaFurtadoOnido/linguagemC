/*Antes do racionamento de energia ser decretado, quase ninguém falava em quilowatts; mas, agora,
todos incorporaram essa palavra em seu vocabulário. Sabendo-se que 100 quilowatts de energia
custa um sétimo do salário mínimo, fazer um programa que calcule e imprima: 
• o valor em reais de cada quilowatt;
• o valor em reais a ser pago; 
• o novo valor a ser pago por essa residência com um desconto de 10%. */

#include <stdio.h>

#define DESCONTO 0.1

int main(){
    float kw, valor_kw, valor_total, salario_minimo, novo_valor;

    printf("Forneça o valor do salário mínimo: R$");
    scanf("%f", &salario_minimo);
    printf("Forneça o quilowatts: ");
    scanf("%f", &kw);

    valor_kw = (salario_minimo/7)/100;
    valor_total = valor_kw * kw;

    novo_valor = valor_total - valor_total * DESCONTO;

    printf("\nValor de cada quilowatt: R$%.2f\nValor a ser pago: R$%.2f\nValor com desconto de %.0f por cento: %.2f", valor_kw, valor_total, DESCONTO*100, novo_valor);

    return 0;
}