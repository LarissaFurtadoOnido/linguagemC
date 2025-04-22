/*Faça um programa que leia quanto você ganha por hora e o número de horas trabalhadas no mês.
Na sequência, calcule e mostre o total do seu salário no referido mês.*/

#include <stdio.h>

int main(){
    float valor_h, salario;
    int num_h;

    printf("Forneça as horas trabalhasdas no mês: ");
    scanf("%d", &num_h);
    printf("Forneça o valor da hora: R$");
    scanf("%f", valor_h);

    salario = num_h * valor_h;

    printf("O salário é R$%2.f", salario);

    return 0;
}