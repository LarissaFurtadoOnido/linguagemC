/*Uma companhia de carros paga a seu vendedor um salario de R$ 2.000,00 por m^es mais uma
comissão de R$ 500,00 para cada carro vendido e mais 5% do valor da venda. Todo mês a
companhia prepara os seguintes dados para um determinado vendedor: matrícula (somente
números), número de carros vendidos e o valor total das vendas. Elabore um algoritmo para calcular
e imprimir o salario do vendedor num dado mês.*/

#include <stdio.h>

#define SALARIO 2000.00
#define COMISSAO 500.00
#define PERCENTUAL 0.05

int main(){
    int matricula, num_carros;
    float valorTotalVendas, salarioTotal;

    printf("Forneça a matrícula do funcionário: ");
    scanf("%d", &matricula);
    printf("Forneça o número de carros vendidos pelo funcionário: ");
    scanf("%d", &num_carros);
    printf("Forneça o valor total de vendas R$: ");
    scanf("%f", &valorTotalVendas);

    salarioTotal = SALARIO + COMISSAO*num_carros + valorTotalVendas*PERCENTUAL;

    printf("\nMatrícula: %d\nSalário total: R$%.2f\n", matricula, salarioTotal);
    

    return 0;
}